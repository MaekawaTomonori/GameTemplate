#ifndef MyGame_HPP_
#define MyGame_HPP_
#include "include/IGame.hpp"

class MyGame final : public IGame{
public:
	MyGame();
	~MyGame() override;
	void Initialize() override;
	void Update() override;
	void Shutdown() override;

private:

}; // class MyGame

#endif // MyGame_HPP_
