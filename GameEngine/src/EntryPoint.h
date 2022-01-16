#pragma once

#ifdef PLATFORM_WINDOWS

	extern Engine::Engine* Engine::CreateGame();

	int main(int argc, char** argv)
	{
		#ifdef DEBUG
			Engine::Log::Init();
			ENGINE_INFO("Initialized log!");
		#endif

		Engine::Engine* game = Engine::CreateGame();
		game->Run();
		delete game;
	}

#endif