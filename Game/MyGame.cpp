#include "MyGame.hpp"

MyGame::MyGame(): IGame() {
} 

MyGame::~MyGame() = default;

void MyGame::Initialize() {
	GetCurrentConfig()
		.SetTitle("Engine")
		.SetFPS(60);
}

void MyGame::Update() {
}

void MyGame::Shutdown() {
}

void MyGame::Draw() {
}
