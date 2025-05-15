#include <memory>
#include <Windows.h>
#include "MyGame.hpp"
#include "include/Framework.hpp"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
    CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	Framework project;
	project.Execute(std::make_unique<MyGame>());
    /*std::unique_ptr<Window> window = std::make_unique<Window>();
    window->Create();
   
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)){
        if (msg.message != WM_QUIT){
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }else {
	        
        }
    }*/

	return 0;
}

