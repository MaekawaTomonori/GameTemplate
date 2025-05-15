#include "MyGame.hpp"

MyGame::MyGame(): IGame() {
} 

MyGame::~MyGame() = default;

void MyGame::Initialize() {
	SetConfig({"Engine", 60});
}

void MyGame::Update() {
}

void MyGame::Shutdown() {
}
