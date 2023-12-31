#include "Button.h"

Button::Button(sf::Vector2f position, float width, float height,
	int red, int green, int blue, std::string text)
{
	// Shape
	m_Button.setPosition(position);
	m_Button.setFillColor(sf::Color(red, green, blue));
	m_Button.setSize(sf::Vector2f(width, height));
	// Text
	m_Text = "" + text;
	float textPaddingX = width / 10;
	float textPaddingY = height / 10;
	m_ButtonText.setCharacterSize(height * .5f);
	m_ButtonText.setString(text);
	m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
	m_ButtonText.setFont(m_Font);
	m_ButtonText.setPosition(sf::Vector2f((position.x + textPaddingX), (position.y + textPaddingY)));
	// Collision
	m_Collider = sf::FloatRect(position, sf::Vector2f(width, height));
}
void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_Button);
	window.draw(m_ButtonText);
}
