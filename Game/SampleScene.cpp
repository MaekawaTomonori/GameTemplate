#include "SampleScene.hpp"

void SampleScene::Initialize() {
    sprite_ = std::make_unique<Sprite>();
    sprite_->Initialize("circle.png");
    sprite_->SetPosition({100, 100});
}

void SampleScene::Update() {
    if (!sprite_) return;
    sprite_->Update();
}

void SampleScene::Draw() {
    if (!sprite_) return;
    sprite_->Draw();
}

void SampleScene::Finalize() {
    IScene::Finalize();
}
