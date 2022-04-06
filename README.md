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
3) Merkle tree
4) Inline
5) hpp
6) chrono
7) Hello! How does project linking work in msvs? 
I have two projects (Game and GameEngine) in a solution. I have links { "GameEngine" } in the Game project (I am using premake5 to generate the projects but I guess it is not a big issue). The only thing I use in Game from GameEngine is #include <EntryPoint.cpp> which is set up to include everything the GameEngine implements. Now I have to actually copy all includedirs from GameEngine to Game like "%{wks.location}/GameEngine/src",. But is it really necessary?
As I am thinking of how it should be: the GameEngine is compiled as StaticLib so it should contain everything it needs. The Game just links that .lib file, and does not have all GameEngine's includedirs copied.
8) https://www.floofyhosting.com/billing/index.php?rp=/store/kvm-vps
9) https://developer.mozilla.org/en-US/docs/Web/API/Service_Worker_API/Using_Service_Workers
   https://developer.mozilla.org/en-US/docs/Web/API/Web_Workers_API/Using_web_workers
10) https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/get
11) https://www.twilio.com/blog/working-with-environment-variables-in-node-js-html
12) cef
13) glm
14) https://en.cppreference.com/w/cpp/language/value_category