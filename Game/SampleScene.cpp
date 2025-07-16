#include "SampleScene.hpp"

void SampleScene::Initialize() {
    sprite_ = std::make_unique<Sprite>();
    sprite_->Initialize("circle.png");
    sprite_->SetPosition({100, 100});

    model_ = std::make_unique<Model>();
    model_->Initialize("simpleSkin");
}

void SampleScene::Update() {
    if (!sprite_) return;
    sprite_->Update();

    if (!model_)return;
    model_->Update();
}

void SampleScene::Draw() {
    if (!model_) return;
    model_->Draw();

    if (!sprite_) return;
    sprite_->Draw();
}

void SampleScene::Finalize() {
    IScene::Finalize();
}
