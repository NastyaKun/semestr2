#include <SFML/Graphics.hpp>
#include <Circle.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");
    
    srand(time(0));
    
    const int n = 10;
    
    mt::Circle c[n];
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 1000;
        int y = rand() % 600;
        int r = rand() % 100 + 1;
        c[i].Setup(x, y, r);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < n; i++)
            window.draw(c[i].Get());
        window.display();
    }

    return 0;
}