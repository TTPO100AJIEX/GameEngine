To run the game on windows:
1) Change msvs version in GenerateProjects.bat
2) Execute GenerateProjects.bat
3) Open GameEngine.sln
4) Compile the solution
---------------------------------
To run on platforms other than windows, look into premake5.lua files and define PLATFORM_WINDOWS for your platform (may or may not work:))
---------------------------------
To learn:
1) C++20 modules
2) copy elision