#pragma once

#ifdef PLATFORM_WINDOWS
	#include "GLFW/Window.h"
#else
	#error "One of [PLATFORM_WINDOWS] must be defined"
#endif