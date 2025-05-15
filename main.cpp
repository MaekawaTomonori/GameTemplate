#include <memory>
#include <Windows.h>
#include "Framework.hpp"
#include "MyGame.hpp"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	Framework project(std::make_unique<MyGame>());

	project.Run();

	return 0;
}

