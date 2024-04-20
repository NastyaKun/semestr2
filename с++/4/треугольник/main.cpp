#include <SFML/Graphics.hpp>
#include <Triangle.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");
    
    srand(time(0));
    
    const int n = 10;
    
    mt::Triangle c[n];
    for (int i = 0; i < n; i++)
    {
        int x1 = rand() % 100;
        int y1 = rand() % 100;
        int x2 = rand() % 100;
        int y2 = rand() % 100;
        int x3 = rand() % 100;
        int y3 = rand() % 100;
        c[i].Setup(x1, y1, x2, y2, x3, y3);
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