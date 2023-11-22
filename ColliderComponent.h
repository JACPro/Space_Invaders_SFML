#pragma once

#include "Component.h"
#include <iostream>

class ColliderComponent : public Component
{
private:
	std::string m_Type = "collider";
	bool m_Enabled = false;

public:
	std::string Component::getType() const override
	{
		return m_Type;
	}

	void Component::disableComponent() override 
	{
		m_Enabled = false;
	}

	void Component::enableComponent() override
	{
		m_Enabled = true;
	}

	bool Component::enabled() const override
	{
		return m_Enabled;
	}

	void Component::start(GameObjectSharer* gos, GameObject* self) override
	{
	}
};
