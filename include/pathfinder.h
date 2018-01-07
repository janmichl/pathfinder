/**
    @file
    @author Jan Michalczyk 

    @brief
*/

#pragma once

#include <stdexcept>
#include <exception>
#include <vector>
#include <queue>
#include <map>
#include <memory>

#ifdef DNDEBUG
#define PATHFINDER_ASSERT(condition, message)
#else
#define PATHFINDER_ASSERT(condition, message) if (!(condition)) {throw(std::runtime_error(message));}
#endif

#include "pathfinder/pathfinder_config.h"
#include "pathfinder/utilities.h"
#include "pathfinder/node.h"
#include "pathfinder/bfs.h"