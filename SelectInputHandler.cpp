#include "SelectInputHandler.h"
#include "SoundEngine.h"
#include "WorldState.h"
#include <iostream>

int WorldState::WAVE_NUMBER; // Resolves linker error



void SelectInputHandler::handleKeyPressed(sf::Event& event, sf::RenderWindow& window)
{
	// Quit the game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
}
void SelectInputHandler::handleLeftClick(std::string& buttonInteractedWith, sf::RenderWindow& window)
{
	if (buttonInteractedWith == "Play") 
	{
		SoundEngine::playClick();
		WorldState::WAVE_NUMBER = 0;
		getPointerToScreenManagerRemoteControl()->loadLevelInPlayMode("level1");
	}
	else if (buttonInteractedWith == "Quit") 
	{
		SoundEngine::playClick();
		window.close();
	}
}
