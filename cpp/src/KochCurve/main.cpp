#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "koch_curve.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    sf::RenderWindow window(sf::VideoMode(800, 800), "Koch Curve Animation");
    window.setFramerateLimit(30);

    sf::Clock clock;
    float delay = 30.0f;
    int max_depth = 10;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (clock.getElapsedTime().asSeconds() > delay) {
            clock.restart();
        }

        int depth = static_cast<int>((clock.getElapsedTime().asSeconds() / delay) * max_depth);

        window.clear(sf::Color::White);

        // Coordenadas ajustadas para centralizar a Curva de Koch
        float x1 = 100.0f;
        float y1 = 400.0f;
        float x2 = 700.0f;
        float y2 = 400.0f;
        sf::Color color = sf::Color::Black;

        draw_koch_curve(window, x1, y1, x2, y2, depth, color);

        window.display();
    }

    return 0;
}

