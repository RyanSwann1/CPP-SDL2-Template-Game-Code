#include "Vector2.h"



Vector2::Vector2()
{
}

Vector2::Vector2(const float x, const float y) : m_x(x), m_y(y)
{

}


Vector2::~Vector2()
{
}


void operator+=(Vector2& v1, const Vector2& v2)
{
	v1.m_x += v2.m_x;
	v1.m_y += v2.m_y;
}
