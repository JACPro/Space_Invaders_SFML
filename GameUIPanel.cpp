#include "GameUIPanel.h"
#include <sstream>
#include "WorldState.h"

// Resolves linker errors
int WorldState::SCORE;
int WorldState::LIVES;

GameUIPanel::GameUIPanel(sf::Vector2i res) : UIPanel(
		res,
		1, // Left screen edge
		1, // Top screen edge
		res.x / 3, // Cover 1/3 of width 
		res.y / 12, // Cover 1/12 of height
		50, 255, 255, 255) // a, r, g, b
{
	m_Text.setFillColor(sf::Color::Green);
	m_Text.setString("Score: 0 Lives: 3 Wave: 1");
	m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
	m_Text.setFont(m_Font);
	m_Text.setPosition(sf::Vector2f(15, 15));
	m_Text.setCharacterSize(40);
}

void GameUIPanel::draw(sf::RenderWindow& window)
{
	UIPanel::draw(window);
	std::stringstream ss;
	ss << "Score: " << WorldState::SCORE << " Lives: " << WorldState::LIVES << " Wave: " << WorldState::WAVE_NUMBER;
	m_Text.setString(ss.str());
	window.draw(m_Text);
}
