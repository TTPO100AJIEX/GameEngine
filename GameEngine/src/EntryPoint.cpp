#include <PrecompiledHeaders.h>

#include "Engine/Engine.h"


#include "Engine/Events/App.h"
#include "Engine/Events/Keyboard.h"
#include "Engine/Events/Mouse.h"
#include "Engine/Events/Window.h"

#include "Engine/Render/RenderAPI.h"


#ifdef PLATFORM_WINDOWS

	int main(int argc, char** argv)
	{
		#ifdef DEBUG
			GameEngine::Log::set_pattern("[%d-%m-%Y %T.%e] [%n]-[%L:%l] %^%v%$");
			ENGINE_WARN("Initialized log!");
		#endif

		std::shared_ptr<GameEngine::Engine> game = GameEngine::CreateGame();
		game->Run();

		return 0;
	}

#endif