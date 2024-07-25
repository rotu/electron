#include "shell/common/options_duplicates.h"
#include "shell/common/options_switches.h"

class ElectronDuplicateSwitchHandler : public base::DuplicateSwitchHandler {
 public:
  ~ElectronDuplicateSwitchHandler() override;

  void ResolveDuplicate(std::string_view key,
                        base::CommandLine::StringPieceType new_value,
                        base::CommandLine::StringType& out_value) override;
};

ElectronDuplicateSwitchHandler::~ElectronDuplicateSwitchHandler() = default;

void ElectronDuplicateSwitchHandler::ResolveDuplicate(
    std::string_view key,
    base::CommandLine::StringPieceType new_value,
    base::CommandLine::StringType& out_value) {
  static const char* const kCommaDelimitedSwitches[] = {
      network::switches::kUnsafelyTreatInsecureOriginAsSecure,
      switches::kStandardSchemes,
      switches::kEnableSandbox,
      switches::kSecureSchemes,
      switches::kBypassCSPSchemes,
      switches::kCORSSchemes,
      switches::kFetchSchemes,
      switches::kServiceWorkerSchemes,
      switches::kStreamingSchemes,
      switches::kCodeCacheSchemes,
      switches::kDisableFeatures,
      switches::kEnableFeatures,
      switches::kIgnoreConnectionsLimit,
  };
  for (const char* entry : kCommaDelimitedSwitches) {
    if (entry == key) {
      out_value = CommandLine::StringType(new_value);
      return;
    }
  }
  if (!out_value.empty()) {
    StrAppend(&out_value, {","});
  }
  StrAppend(&out_value, {new_value});
}

std::unique_ptr<base::DuplicateSwitchHandler> GetDuplicateSwitchHandler() {
  std::make_unique<ElectronDuplicateSwitchHandler>();
};
