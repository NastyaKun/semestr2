#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{

	class Triangle
	{
		float m_r;
		float m_x;
		float m_y;
		
		sf::CircleShape triangle;

	public:
		Triangle() = default;

		Triangle(float x, float y, float r)
		{
			Setup(x, y, r);
		}

		void Setup(float x, float y, float r)
		{
			m_x = x;
			m_y = y;
			triangle.setRadius(m_r);
			triangle.setPosition(m_x, m_y);
			triangle.setPointCount(3);
			triangle.setFillColor(sf::Color::Color(255, 0, 0, 255));
		}

		sf::CircleShape Get()
		{
			return triangle;
		}
	};

}

//m_shape.setPoint(0, sf::Vector2f(m_x, m_y));
			//m_shape.setPoint(1, sf::Vector2f(m_y, m_z));
			//m_shape.setPoint(2, sf::Vector2f(m_z, m_x));