#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "Screen.h"
#include "ScreenManagerRemoteControl.h"

class Screen; //TODO - can we remove this forward declaration as we are including Screen.h ??? I guess not bc circular include???

class InputHandler
{
private:
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
	vector<shared_ptr<Button>> m_Buttons;
	sf::View* m_PointerToUIPanelView;
	Screen* m_ParentScreen;

public:
	void initialiseInputHandler(
		ScreenManagerRemoteControl* sw,
		std::vector<shared_ptr<Button>>,
		sf::View* pointerToUIView,
		Screen* parentScreen);
	void handleInput(sf::RenderWindow& window, sf::Event& event);
	virtual void handleGamepad();
	virtual void handleKeyPressed(sf::Event& event, sf::RenderWindow& window);
	virtual void handleKeyReleased(sf::Event& event, sf::RenderWindow& window);
	virtual void handleLeftClick(std::string& buttonInteractedWith, sf::RenderWindow& window);
	sf::View* getPointerToUIView();
	ScreenManagerRemoteControl* getPointerToScreenManagerRemoteControl();
	Screen* getmParentScreen();
};
