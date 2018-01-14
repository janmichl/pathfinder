/**
    @file
    @author  Jan Michalczyk
    @copyright 2017-2018 Jan Michalczyk. Licensed under the Apache License, Version 2.0.
    (see @ref LICENSE or http://www.apache.org/licenses/LICENSE-2.0)
    
    @brief Core headers and definitions
*/

#pragma once

#include <iostream>
#include <stdexcept>
#include <exception>
#include <vector>
#include <queue>
#include <map>
#include <memory>
#include <algorithm>
#include <sstream>
#include <string>

#include "config-yaml/config_reader.h"

#include <Eigen/Core>

#ifdef DNDEBUG
#define PATHFINDER_ASSERT(condition, message)
#else
#define PATHFINDER_ASSERT(condition, message) if (!(condition)) {throw(std::runtime_error(message));}
#endif

#include "core/pathfinder_config.h"
#include "core/node.h"
#include "core/utilities.h"
