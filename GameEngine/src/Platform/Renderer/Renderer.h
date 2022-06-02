#pragma once

#ifdef RENDERER_USE_OPENGL
	#include "OpenGL/Renderer.h"
	#include "OpenGL/RenderAPI.h"
#else
	#error "One of [RENDERER_USE_OPENGL] must be defined"
#endif