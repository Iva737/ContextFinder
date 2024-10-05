#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
std::string path = "/home/iva737/Рабочий стол/Context Finder/test";
const int mx = 300; //Width  Window
const int my = 200; //Height Window

int main()
{
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode(mx, my), "Context Finder");

    // Создаем круг
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(100, 50); // расположим круг в центре окна

    // Основной цикл
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Очищаем окно
        window.clear();

        // Рисуем круг
        window.draw(circle);

        // Отображаем изменения на экране
        window.display();
    }

    return 0;
}


/*

std::cout << "Hello world!";



*/
