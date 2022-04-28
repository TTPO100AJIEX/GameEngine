#include <PrecompiledHeaders.h>

#include "Engine/Engine.h"

/*
#include "Render/RenderAPI.h"

#include "Window/Window.h"
#include "Render/General/Renderer.h"

#include "Events/App.h"
#include "Events/Keyboard.h"
#include "Events/Mouse.h"
#include "Events/Window.h"*/


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