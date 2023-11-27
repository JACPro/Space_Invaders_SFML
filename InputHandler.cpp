#include <sstream>
#include "InputHandler.h"

void InputHandler::initialiseInputHandler(
	ScreenManagerRemoteControl* sw,
	std::vector<shared_ptr<Button>> buttons,
	sf::View* pointerToUIView,
	Screen* parentScreen)
{
	m_ScreenManagerRemoteControl = sw;
	m_Buttons = buttons;
	m_PointerToUIPanelView = pointerToUIView;
	m_ParentScreen = parentScreen;
}

void InputHandler::handleInput(sf::RenderWindow& window, sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		handleKeyPressed(event, window);
	}
	if (event.type == sf::Event::KeyReleased)
	{
		handleKeyReleased(event, window);
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		auto end = m_Buttons.end();
		for (auto i = m_Buttons.begin(); i != end; ++i) 
		{
			//check if mouse is inside bounds of each button
			if ((*i)->m_Collider.contains(window.mapPixelToCoords(sf::Mouse::getPosition(), (*getPointerToUIView()))))
			{
				// If any button pressed, pass associated text to handleLeftClick if overridden in child class
				handleLeftClick((*i)->m_Text, window);
				break;
			}
		}
	}
	handleGamepad();
}

void InputHandler::handleGamepad() {}// Do nothing unless handled by a derived class
void InputHandler::handleKeyPressed(sf::Event & event, sf::RenderWindow & window) {}// Do nothing unless handled by a derived class
void InputHandler::handleKeyReleased(sf::Event& event, sf::RenderWindow& window) {}// Do nothing unless handled by a derived class
void InputHandler::handleLeftClick(std::string& buttonInteractedWith, sf::RenderWindow& window) {}// Do nothing unless handled by a derived class

sf::View* InputHandler::getPointerToUIView()
{
	return m_PointerToUIPanelView;
}

ScreenManagerRemoteControl* InputHandler::getPointerToScreenManagerRemoteControl()
{
	return m_ScreenManagerRemoteControl;
}

Screen* InputHandler::getmParentScreen() {
	return m_ParentScreen;
}
