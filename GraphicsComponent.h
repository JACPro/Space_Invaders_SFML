#pragma once

#include "Component.h"
#include "TransformComponent.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObjectSharer.h"
#include <iostream>

class GraphicsComponent : public Component 
{
private:
	std::string m_Type = "graphics";
	bool m_Enabled = false;

public:
	virtual void draw(sf::RenderWindow& window, std::shared_ptr<TransformComponent> t) = 0;
	virtual void initializeGraphics(std::string bitmapName, sf::Vector2f objectSize) = 0;

	std::string Component::getType() const override { return m_Type; }
	void Component::disableComponent() override { m_Enabled = false; }
	void Component::enableComponent() override { m_Enabled = true; }
	bool Component::enabled() const override { return m_Enabled; }
	void Component::start(GameObjectSharer* gos, GameObject* self) override {}
};
