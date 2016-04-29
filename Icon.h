#ifndef ICON_H
#define ICON_H

#include "Vector2.h"
#include <string>
class Icon
{


public:
	Icon();
	~Icon();

	virtual void draw() = 0;
	virtual void update() = 0;
	std::string getID() const { return m_ID; }

protected:
	int m_currentAction;
	Vector2 m_position;
	int m_sizeWidth;
	int m_sizeHeight;
	std::string m_ID;
	bool m_clicked;

	enum IconState
	{
		MOUSE_OUT,
		MOUSE_OVER,
		CLICKED
	};
private:

	
};
#endif // !ICON_H
