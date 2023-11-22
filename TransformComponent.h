#pragma once
#include "Component.h"
#include<SFML/Graphics.hpp>
using namespace sf;
class Component;
class TransformComponent : public Component {
private:
	const std::string m_Type = "transform";
	Vector2f m_Location;
	float m_Height;
	float m_Width;
public:
	TransformComponent(float width, float height, Vector2f location);
	Vector2f& getLocation();
	Vector2f getSize() const;

	std::string Component::getType() const override { return m_Type; }
	// Only one type of Transform so just return m_Type
	std::string Component::getSpecificType() const override { return m_Type; }
	void Component::disableComponent() override {}
	void Component::enableComponent() override {}
	bool Component::enabled() const override { return false; }
	void Component::start(GameObjectSharer* gos, GameObject* self) override {}
};
