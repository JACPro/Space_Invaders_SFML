#include "DevelopState.h"
#include "GameObject.h"
#include <iostream>
#include "UpdateComponent.h"
#include "RectColliderComponent.h"

void GameObject::update(float fps)
{
	if (m_Active && m_HasUpdateComponent)
	{
		int lastUpdateComponent = m_FirstUpdateComponentLocation + m_NumberUpdateComponents;
		for (int i = m_FirstUpdateComponentLocation; i < lastUpdateComponent; i++)
		{
			std::shared_ptr<UpdateComponent> tempUpdate = std::static_pointer_cast<UpdateComponent>(m_Components[i]);
			if (tempUpdate->enabled())
			{
				tempUpdate->update(fps);
			}
		}
	}
}

void GameObject::draw(sf::RenderWindow& window)
{
	if (m_Active && m_HasGraphicsComponent)
	{
		if (m_Components[m_GraphicsComponentLocation]->enabled())
		{
			getGraphicsComponent()->draw(window, getTransformComponent());
		}
	}
}

std::shared_ptr<GraphicsComponent> GameObject::getGraphicsComponent()
{
	return std::static_pointer_cast<GraphicsComponent>(m_Components[m_GraphicsComponentLocation]);
}

std::shared_ptr<TransformComponent> GameObject::getTransformComponent()
{
	return std::static_pointer_cast<TransformComponent>(m_Components[m_TransformComponentLocation]);
}

void GameObject::addComponent(std::shared_ptr<Component> component)
{
	m_Components.push_back(component);
	component->enableComponent();
	if (component->getType() == "update")
	{
		m_HasUpdateComponent = true;
		m_NumberUpdateComponents++;
		if (m_NumberUpdateComponents == 1)
		{
			m_FirstUpdateComponentLocation = m_Components.size() - 1;
		}
	}
	else if (component->getType() == "graphics")
	{
		// No iteration in the draw method required
		m_HasGraphicsComponent = true;
		m_GraphicsComponentLocation = m_Components.size() - 1;
	}
	else if (component->getType() == "transform")
	{
		m_TransformComponentLocation = m_Components.size() - 1;
	}
	else if (component->getType() == "collider" && component->getSpecificType() == "rect")
	{
		m_HasCollider = true;
		m_NumberRectColliderComponents++;
		if (m_NumberRectColliderComponents == 1)
		{
			m_FirstRectColliderComponentLocation = m_Components.size() - 1;
		}
	}
}

void GameObject::setActive()
{
	m_Active = true;
}

void GameObject::setInactive()
{
	m_Active = false;
}

bool GameObject::isActive() const
{
	return m_Active;
}

void GameObject::setTag(std::string tag)
{
	m_Tag = "" + tag;
}

std::string GameObject::getTag() const
{
	return m_Tag;
}

void GameObject::start(GameObjectSharer* gos)
{
	auto it = m_Components.begin();
	auto end = m_Components.end();
	for (it; it != end; ++it)
	{
		(*it)->start(gos, this);
	}
}

// Slow - only use in start function
std::shared_ptr<Component> GameObject::getComponentByTypeAndSpecificType(std::string type, std::string specificType)
{
	auto it = m_Components.begin();
	auto end = m_Components.end();
	for (it; it != end; ++it)
	{
		if ((*it)->getType() == type)
		{
			if ((*it)->getSpecificType() == specificType)
			{
				return (*it);
			}
		}
	}
#ifdef debuggingErrors
	cout << "GameObject.cpp::getComponentByTypeAndSpecificType-" << "COMPONENT NOT FOUND ERROR!" << endl;
#endif
	return m_Components[0];
}

sf::FloatRect& GameObject::getEncompassingRectCollider()
{
	if (m_HasCollider)
	{
		return (std::static_pointer_cast<RectColliderComponent>(m_Components[m_FirstRectColliderComponentLocation]))->getColliderRectF();
	}
}

std::string GameObject::getEncompassingRectColliderTag()
{
	return std::static_pointer_cast<RectColliderComponent>(m_Components[m_FirstRectColliderComponentLocation])->getColliderTag();
}

std::shared_ptr<UpdateComponent> GameObject::getFirstUpdateComponent()
{
	return std::static_pointer_cast<UpdateComponent>(
		m_Components[m_FirstUpdateComponentLocation]);
}

bool GameObject::hasCollider() const
{
	return m_HasCollider;
}

bool GameObject::hasUpdateComponent() const
{
	return m_HasUpdateComponent;
}
