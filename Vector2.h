#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
	friend void operator +=(Vector2& v1, const Vector2& v2);
public:
	Vector2();
	Vector2(const float x, const float y);
	~Vector2();

	void setX(const float x) { m_x = x; }
	void setY(const float y) { m_y = y; }
	
	float getX() const { return m_x; }
	float getY() const { return m_y; }
private:
	float m_x;
	float m_y;
};
#endif // !VECTOR2_H