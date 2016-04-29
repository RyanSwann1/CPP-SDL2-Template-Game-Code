#include "IconManager.h"



IconManager::IconManager()
{
}


IconManager::~IconManager()
{
}

void IconManager::draw()
{
	for (auto &icon : m_icons)
	{
		icon->draw();
	}
}

void IconManager::update()
{
	for (auto &icon : m_icons)
	{
		icon->update();
	}
}

void IconManager::addIcon(std::unique_ptr<Icon>& icon)
{
	m_icons.push_back(std::unique_ptr<Icon>(std::move(icon)));
}
