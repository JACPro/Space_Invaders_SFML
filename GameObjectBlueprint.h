#pragma once

#include<vector>
#include<string>
#include<map>

class GameObjectBlueprint 
{
private:
	std::string m_Name = "";
	std::vector<std::string> m_ComponentList;
	std::string m_BitmapName = "";
	float m_Width;
	float m_Height;
	float m_LocationX;
	float m_LocationY;
	float m_Speed;
	bool m_EncompassingRectCollider = false;
	std::string m_EncompassingRectColliderLabel = "";

public:
	float getWidth() const;
	void setWidth(float width);
	float getHeight() const;
	void setHeight(float height);
	float getLocationX() const;
	void setLocationX(float locationX);
	float getLocationY() const;
	void setLocationY(float locationY);
	std::string getName() const;
	void setName(std::string name);
	std::vector<std::string>& getComponentList();
	void addToComponentList(std::string newComponent);
	std::string getBitmapName() const;
	void setBitmapName(std::string bitmapName);
	std::string getEncompassingRectColliderLabel() const;
	bool getEncompassingRectCollider() const;
	void setEncompassingRectCollider(std::string label);
};
