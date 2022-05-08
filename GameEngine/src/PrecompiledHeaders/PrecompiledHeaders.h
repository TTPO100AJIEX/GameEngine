#pragma once

#include <fstream>
#include <sstream>

#include <cstdint>
#include <chrono>

#include <memory>
#include <optional>
#include <functional>
#include <utility>
#include <new>
#include <algorithm>

#include <tuple>
#include <string>
#include <array>
#include <vector>
#include <initializer_list>
#include <unordered_map>


#include <GLM/glm.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtc/matrix_transform.hpp>

#include <GLAD/glad.h>
#ifdef PLATFORM_WINDOWS
	#include <GLFW/glfw3.h>
#endif


#include <Log/Log.h>

#include <Engine/Core/KeyCodes/KeyCodes.h>
#ifdef PLATFORM_WINDOWS
	#include <Engine/Core/KeyCodes/GLFW/GLFW.h>
#endif
#include <Engine/Core/ShaderDataType/ShaderDataType.h>
#include <Engine/Core/ShaderType/ShaderType.h>
#ifdef RENDER_USE_OPENGL
	#include <Engine/Core/ShaderType/OpenGL/OpenGL.h>
	#include <Engine/Core/ShaderDataType/OpenGL/OpenGL.h>
#endif
#include <Engine/Core/Time/Time.h>