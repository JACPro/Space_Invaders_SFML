#pragma once

#include "Screen.h"
#include "GameInputHandler.h"
#include "GameOverInputHandler.h"

class GameScreen : public Screen
{
private:
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
	shared_ptr<GameInputHandler> m_GIH;
	sf::Texture m_BackgroundTexture;
	sf::Sprite m_BackgroundSprite;

public:
	static bool m_GameOver;

	GameScreen(ScreenManagerRemoteControl* smrc, sf::Vector2i res);
	void initialise() override;
	void virtual update(float fps) override;
	void virtual draw(sf::RenderWindow& window);
};
