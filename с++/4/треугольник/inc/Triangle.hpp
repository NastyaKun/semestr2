#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{

	class Triangle
	{
		float m_x1, m_y1;
		float m_x2, m_y2;
		float m_x3, m_y3;
		sf::ConvexShape m_shape;

	public:
		Triangle() = default;

		Triangle(float x1, float y1, float x2, float y2, float x3, float y3)
		{
			Setup(x1, y1, x2, y2, x3, y3);
		}

		void Setup(float x1, float y1, float x2, float y2, float x3, float y3)
		{
			m_x1 = x1;
			m_y1 = y1;
			m_x2 = x2;
			m_y2 = y2;
			m_x3 = x3;
			m_y3 = y3;
			//m_shape.setRadius(m_r);
			m_shape.setPointCount(3);
			m_shape.setPoint(0, sf::Vector2f(m_x1, m_y1));
			m_shape.setPoint(1, sf::Vector2f(m_x2, m_y2));
			m_shape.setPoint(2, sf::Vector2f(m_x3, m_y3));
			m_shape.setFillColor(sf::Color::Color(255, 0, 0, 255));
		}

		sf::ConvexShape Get()
		{
			return m_shape;
		}
	};

}