# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## プロジェクト概要

これはC++20 DirectX12ベースのゲームエンジンテンプレートプロジェクトで、以下の構造になっています：
- **Engine/**: すべてのエンジンシステムを含むコアエンジンライブラリ（.lib）
- **Game/**: Engineライブラリに依存するゲーム実行ファイル
- **Assets/**: 共有リソース（モデル、テクスチャ、シェーダー、フォント）

エンジンは異なるシステム（Camera、Light、Model、Sprite、Texture、Scene）のマネージャーを持つコンポーネントベースのアーキテクチャに従っています。

## ビルドコマンド

これはMSBuildを使用するVisual Studio 2022 C++プロジェクトです：

### ソリューションのビルド
```bash
msbuild GameTemplate.sln /p:Configuration=Debug /p:Platform=x64
msbuild GameTemplate.sln /p:Configuration=Release /p:Platform=x64
```

### 個別プロジェクトのビルド
```bash
# 最初にEngineライブラリをビルド
msbuild Engine/Engine.vcxproj /p:Configuration=Debug /p:Platform=x64

# Game実行ファイルをビルド（Engineに依存）
msbuild Game/Game.vcxproj /p:Configuration=Debug /p:Platform=x64
```

### ゲームの実行
```bash
# デバッグビルド
.\out\x64\Debug\Game\Game.exe

# リリースビルド  
.\out\x64\Release\Game\Game.exe
```

## アーキテクチャ概要

### コアフレームワーク
- **Framework**: メインアプリケーションループマネージャー（Framework.hpp:20）
- **IGame**: ゲーム実装のベースクラス（MyGameがこれを継承）
- **IScene**: ゲームシーンのベースクラス（SampleSceneがこれを継承）
- **SceneSwitcher**: シーン遷移の管理

### エンジンシステム
- **DirectXAdapter**: DirectX12の初期化と管理
- **ResourceRepository**: アセットローディングと管理システム
- **CameraManager**: 3Dカメラシステム管理
- **LightManager**: ライティングシステム（指向性、点光源、スポットライト）
- **TextureManager**: テクスチャローディングとGPUリソース管理
- **ModelCommon/SpriteCommon**: 3Dモデルと2Dスプライトのレンダリングパイプライン

### モデルローディング
エンジンは複数の3D形式をサポートします：
- **GltfLoader**: アニメーション付きglTF 2.0形式サポート
- **ObjLoader**: Wavefront OBJ形式サポート
- モデルデータは**ModelRepository**と**MeshRepository**にキャッシュされます

### アセットパイプライン
- モデル: `Assets/Resources/`内の`.gltf`、`.obj`、`.blend`ファイル
- テクスチャ: `.png`ファイル 
- シェーダー: `Assets/Shaders/`内の`.hlsl`ファイル
- フォント: `Assets/Fonts/`内の`.ttf`ファイル

### 依存関係管理
ソリューションには以下のベンダーライブラリが含まれています：
- **imgui**: デバッグUIシステム
- **DirectXTex**: テクスチャ処理
- **lwlog**: ログシステム（現在のコードではあまり使用されていません）

## ゲーム開発ワークフロー

1. `Game/MyGame.cpp`でゲームロジックを実装（IGameを継承）
2. ISceneを継承してシーンを作成（`Game/SampleScene.cpp`を参照）
3. `Game/SceneFactory.cpp`でシーンを登録
4. レンダリング、入力、アセットローディングにはFrameworkのマネージャーを使用

### エントリーポイント
アプリケーションは`Game/main.cpp:5`で開始され、FrameworkインスタンスをCreateしてMyGameインスタンスを渡します。

## 開発ノート

- C++20標準を使用
- コードスタイル: インデントは4スペース、ソースファイルはUTF-8エンコーディング
- Engineプロジェクトは静的ライブラリ（.lib）にコンパイルされます
- GameプロジェクトはEngine.libとリンクして最終実行ファイルを作成します
- ビルド出力は`out/x64/{Configuration}/`に出力されます