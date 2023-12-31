#include "Screen.h"

void Screen::initialise() {}

void Screen::addPanel(unique_ptr<UIPanel> uip, ScreenManagerRemoteControl* smrc, shared_ptr<InputHandler> ih)
{
	ih->initialiseInputHandler(smrc, uip->getButtons(), &uip->m_View, this);
	m_Panels.push_back(move(uip));
	m_InputHandlers.push_back(ih);
}

void Screen::handleInput(sf::RenderWindow& window)
{
	sf:: Event event;
	auto itr = m_InputHandlers.begin();
	auto end = m_InputHandlers.end();

	while (window.pollEvent(event))
	{
		for (itr; itr != end; ++itr)
		{
			(*itr)->handleInput(window, event);
		}
	}
}

void Screen::update(float fps) {}

void Screen::draw(sf::RenderWindow& window)
{
	auto itr = m_Panels.begin();
	auto end = m_Panels.end();
	for (itr; itr != end; ++itr)
	{
		(*itr)->draw(window);
	}
}
