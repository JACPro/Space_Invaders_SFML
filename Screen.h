#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "InputHandler.h"
#include "UIPanel.h"
#include "ScreenManagerRemoteControl.h"

class InputHandler; //TODO - can we remove this forward declaration as we are including InputHandler.h ??? I guess not bc circular include???

class Screen {
private:
	vector<shared_ptr<InputHandler>> m_InputHandlers;
	vector<unique_ptr<UIPanel>> m_Panels;

protected:
	void addPanel(unique_ptr<UIPanel> p, ScreenManagerRemoteControl* smrc, shared_ptr<InputHandler> ih);

public:
	sf::View m_View;

	virtual void initialise();
	void virtual update(float fps);
	void virtual draw(sf::RenderWindow& window);
	void handleInput(sf::RenderWindow& window);
};