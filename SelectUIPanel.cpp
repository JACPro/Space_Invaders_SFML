#include "SelectUIPanel.h"
#include <iostream>

// Create a new UIPanel by calling the super-class constructor
SelectUIPanel::SelectUIPanel(sf::Vector2i res) : UIPanel(
		res,
		(res.x / 10) * 2, // 2/10 width from left
		res.y / 3, // 1/3 height from top
		(res.x / 10) * 6, // Cover 6/10 of width
		res.y / 3, // Cover 1/3 of height
		50, 255, 255, 255) // a, r, g, b
{
	m_ButtonWidth = res.x / 20;
	m_ButtonHeight = res.y / 20;
	m_ButtonPadding = res.x / 100;

	m_Text.setFillColor(sf::Color::Green);
	m_Text.setString("SPACE INVADERS ++");
	m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
	m_Text.setFont(m_Font);
	m_Text.setPosition(sf::Vector2f(m_ButtonPadding, m_ButtonHeight + (m_ButtonPadding * 2)));
	m_Text.setCharacterSize(100);

	initialiseButtons();
}

void SelectUIPanel::initialiseButtons()
{
	// Buttons positioned relative to top-left corner of UI panel (m_View in UIPanel)
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
		"Quit");
}

void SelectUIPanel::draw(sf::RenderWindow& window)
{
	show();
	UIPanel::draw(window);
	window.draw(m_Text);
}
