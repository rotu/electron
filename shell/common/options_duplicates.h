#ifndef ELECTRON_SHELL_COMMON_OPTIONS_DUPLICATES_H_
#define ELECTRON_SHELL_COMMON_OPTIONS_DUPLICATES_H_

#include <memory>
#include "base/command_line.h"

std::unique_ptr<base::DuplicateSwitchHandler> GetDuplicateSwitchHandler();

#endif  // ELECTRON_SHELL_COMMON_OPTIONS_DUPLICATES_H_
