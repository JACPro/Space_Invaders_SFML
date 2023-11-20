#include "GameOverUIPanel.h"
#include "GameScreen.h"

bool GameScreen::m_GameOver; // Resolves linker error

GameOverUIPanel::GameOverUIPanel(sf::Vector2i res) : UIPanel(
		res,
		(res.x / 10) * 3.333f, // 3/10 width from left
		res.y / 2, // 1/2 height from top
		(res.x / 10) * 3, // Cover 1/3 of width
		res.y / 6, // Cover 1/6 height
		50, 255, 255, 255) // a, r, g, b
{
	m_ButtonWidth = res.x / 20;
	m_ButtonHeight = res.y / 20;
	m_ButtonPadding = res.x / 100;

	m_Text.setFillColor(sf::Color::Green);
	m_Text.setString("GAME OVER!");
	m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
	m_Text.setFont(m_Font);
	m_Text.setPosition(sf::Vector2f(m_ButtonPadding, (m_ButtonPadding * 2) + m_ButtonHeight));
	m_Text.setCharacterSize(60);

	initialiseButtons();
}
void GameOverUIPanel::initialiseButtons()
{
	addButton(
		m_ButtonPadding,
		m_ButtonPadding,
		m_ButtonWidth,
		m_ButtonHeight,
		0, 255, 0,
		"Play");

	addButton(
		m_ButtonWidth + (m_ButtonPadding * 2),
		m_ButtonPadding,
		m_ButtonWidth,
		m_ButtonHeight,
		255, 0, 0,
		"Home");
}

void GameOverUIPanel::draw(sf::RenderWindow& window)
{
	if (GameScreen::m_GameOver)
	{
		show();
		UIPanel::draw(window);
		window.draw(m_Text);
	}
	else
	{
		hide();
	}
}
