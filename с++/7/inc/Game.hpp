#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <thread>
#include <Ship.hpp>
#include <Circle.hpp>
#include <Bullet.hpp>

namespace mt 
{
	const float pi = acos(-1);

	class Game 
	{
		const int m_bulletR = 10;
		int m_width;
		int m_height;
		std::string m_capture;
		mt::Circle* m_c;
		mt::Bullet m_b;
		std::vector<Bullet> bullets;
		int m_n;
		sf::RenderWindow m_window;
		sf::Texture m_TextureBackground;
		sf::Sprite m_SpriteBackground;
		sf::Font m_font;
		sf::Text m_fpsText;
		Ship m_ship;
		bool isVisible = true;
		bool isTouchBorder = true;

	public:
		Game(int width, int height, const std::string& capture) 
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		bool Setup(int n) 
		{
			m_n = n;
			
			//Создание окна
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			//Загрузка текстуры фона
			if (!m_TextureBackground.loadFromFile("assets\\Background.jpg")) 
			{
				std::cout << "Error while loading background.jpg";
				return false;
			}
			m_SpriteBackground.setTexture(m_TextureBackground);

			//Загрузка коробля игрока
			if (!m_ship.Setup(100, 100)) 
				return false;
			
			srand(time(0));

			m_c = new mt::Circle[m_n];
			for (int i = 0; i < m_n; i++) 
			{
				int r = rand() % 100 + 10;
				int x = rand() % (1000 - 2 * r) + r;
				int y = rand() % (600 - 2 * r) + r;
				int v = rand() % 50 + 100;
				float alfa = rand() % 7;
				m_c[i].Setup(x, y, r, v, alfa);
			}
		}

		
		void delete_Circle(Circle& obj, Bullet& obj2) 
		{
			float x = obj.X();
			float y = obj.Y();
			float r = obj.R();
			float x1 = obj2.X();
			float y1 = obj2.Y();
			float r1 = obj2.R();
			float Dx = x - x1;
			float Dy = y - y1;
			float dist = sqrt(pow(Dx, 2) + pow(Dy, 2));
			if (dist < r + r1) {
				obj.~Circle();
				obj2.BulletReset();
			}
		}

		void LifeCycle()
		{
			sf::Clock clock;

			while (m_window.isOpen())
			{
				//Обработка событий
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed) 
						m_window.close();
				}

				//Обработка клавиатуры
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					m_ship.setVelocity(1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					m_ship.setVelocity(-1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					m_ship.Rotate(-0.5);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					m_ship.Rotate(0.5);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if (!m_ship.BulletAvailable())
						m_ship.Attack();
					float m_v = m_ship.V();
					float m_x = m_ship.X();
					float m_y = m_ship.Y();
					float m_alpha = m_ship.Alpha();
					float m_v_bullet = 200;
					float alphaRad = acos(-1) * m_alpha / 180;
					m_b.Setup(m_x, m_y, m_bulletR, (m_v + m_v_bullet) * cos(alphaRad), (m_v + m_v_bullet) * sin(alphaRad));
					bullets.push_back(m_b);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					m_ship.BulletReset();
				}


				
				//Логика
				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				for (int i = 0; i < m_n; i++) 
				{
					for (int j = 0; j < bullets.size(); j++)
						delete_Circle(m_c[i], bullets[j]);
				}

				for (int i = 0; i < m_n; i++)
				{
					float x = m_c[i].X();
					float y = m_c[i].Y();
					float r = m_c[i].R();
					float v = m_c[i].V();
					float alfa = m_c[i].Alfa();

					float x_s = x + v * cos(alfa) * dt;
					float y_s = y + v * sin(alfa) * dt;


					bool collision = false;
					if (x_s + r >= m_width)
					{
						m_c[i].Alfa(pi - m_c[i].Alfa());
						m_c[i].X(m_width - r);
						collision = true;
					}

					if (x_s - r <= 0)
					{
						m_c[i].Alfa(pi - m_c[i].Alfa());
						m_c[i].X(r);
						collision = true;
					}

					if (y_s + r >= m_height)
					{
						m_c[i].Alfa(2 * pi - m_c[i].Alfa());
						m_c[i].Y(m_height - r);
						collision = true;
					}

					if (y_s - r <= 0)
					{
						m_c[i].Alfa(2 * pi - m_c[i].Alfa());
						m_c[i].Y(r);
						collision = true;
					}

					if (!collision)
					{
						m_c[i].X(x_s);
						m_c[i].Y(y_s);
					}
				}

				m_b.Move(dt);
				for (int i = 0; i < bullets.size(); i++)
					bullets[i].Move(dt);

				//Перемещение шарика
				m_ship.Move(dt);
				m_fpsText.setString(std::to_string(1 / dt));

				//Отборажение
				m_window.clear();
				m_window.draw(m_SpriteBackground);
				m_window.draw(m_ship.Get());
				for (int i = 0; i < m_n; i++) 
				{
					m_window.draw(m_c[i].Get());
				}

				if (m_ship.BulletAvailable())
					for (int i = 0; i < bullets.size(); i++)
						m_window.draw(m_ship.GetBullet());
					
				if (isVisible)
					m_window.draw(m_ship.Get());

				m_window.display();
			}
		}

		~Game()
		{
			delete[] m_c;
		}
	};
}