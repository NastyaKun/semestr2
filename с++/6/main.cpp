#include <SFML/Graphics.hpp>
#include <Circle.hpp>
#include <Game.hpp>

int main()
{
    mt::Game game(1100, 1000, "Game");

    if (!game.Setup(10))
        return -1;

    game.LifeCycle();

    return 0;
}