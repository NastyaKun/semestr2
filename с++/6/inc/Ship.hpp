#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


namespace mt 
{
	class Ship 
	{
		float m_x, m_y, m_v;
		float m_alpha;
		sf::Texture m_TextureShip;
		sf::Sprite m_SpriteShip;

	public:
		Ship() = default;

		Ship(float x, float y) 
		{
			m_x = x;
			m_y = y;
		}

		bool Setup(float x, float y) 
		{
			m_x = x;
			m_y = y;
			m_alpha = 0;
			m_v = 0;

			//Загрузка текстуры
			if (!m_TextureShip.loadFromFile("assets\\textureShip1.jpg")) 
			{
				std::cout << "Error while loading textureShip1.jpg";
				return false;
			}

			m_SpriteShip.setTexture(m_TextureShip);

			m_SpriteShip.setScale(0.2f, 0.2f);
			m_SpriteShip.setOrigin(m_TextureShip.getSize().x / 2, m_TextureShip.getSize().y / 2);
			m_SpriteShip.setPosition(m_x, m_y);
			m_SpriteShip.setRotation(m_alpha);
		}

		void SetVelocity(float dv) 
		{
			m_v += dv;
		}

		void Move() 
		{

			float AlphaRad = acos(-1) * m_alpha / 180;
			m_x += m_v * cos(AlphaRad);
			m_y += m_v * sin(AlphaRad);
			m_SpriteShip.setPosition(m_x, m_y);
		}

		void Rotate(float dalpha) {
			m_alpha += dalpha;
			m_SpriteShip.setRotation(m_alpha);
		}

		sf::Sprite Get() 
		{
			return m_SpriteShip;
		}
	};
}