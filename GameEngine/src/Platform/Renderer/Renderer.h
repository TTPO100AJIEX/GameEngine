#pragma once

#ifdef RENDERER_USE_OPENGL
	#include "OpenGL/Renderer.h"
#else
	#error "One of [RENDERER_USE_OPENGL] must be defined"
#endif

#include "Common/Camera/Camera.h"
#include "Common/Camera/ControlledCamera/ControlledCamera.h"
#include "Common/TextureLibrary/TextureLibrary.h"
#include "Common/ShaderLibrary/ShaderLibrary.h"