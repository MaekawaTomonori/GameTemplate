#include "MyGame.hpp"

#include "SceneFactory.hpp"

MyGame::MyGame(): IGame(std::make_unique<SceneFactory>(), "sample") {
    GetCurrentConfig()
        .SetTitle("Engine")
        .SetFPS(60);
}

MyGame::~MyGame() = default;

