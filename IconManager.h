#ifndef ICON_MANAGER_H
#define ICON_MANAGER_H

#include "Icon.h"
#include <vector>
#include <memory>
class IconManager
{
public:
	IconManager();
	~IconManager();

	void draw();
	void update();
	void addIcon(std::unique_ptr<Icon>& icon);
	void clearIcons() { m_icons.clear(); }

private:
	std::vector<std::unique_ptr<Icon>> m_icons;

};
#endif // !ICON_MANAGER_H
