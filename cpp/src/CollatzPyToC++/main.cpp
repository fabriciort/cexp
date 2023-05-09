#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "collatz_sequence.h"

void draw_collatz_tree(sf::RenderTarget &target, int n, float x, float y, float angle, float length, const sf::Color &color) {
    if (n > 1) {
        float new_x = x + length * cos(angle * M_PI / 180.0f);
        float new_y = y - length * sin(angle * M_PI / 180.0f);

        sf::Vertex line[] = {sf::Vertex(sf::Vector2f(x, y), color), sf::Vertex(sf::Vector2f(new_x, new_y), color)};
        target.draw(line, 2, sf::Lines);

        std::vector<int> seq = collatz_sequence(n);
        for (int i = 1; i < seq.size(); ++i) {
            float new_angle = angle + seq[i] * 15.0f;
            draw_collatz_tree(target, seq[i], new_x, new_y, new_angle, length * 0.75, color);
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    sf::RenderWindow window(sf::VideoMode(800, 800), "Collatz Conjecture Tree Animation");
    window.setFramerateLimit(30);

    sf::Clock clock;
    float delay = 3.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (clock.getElapsedTime().asSeconds() > delay) {
            window.clear(sf::Color::White);

            int n = 2 + rand() % 1000;
            sf::Color color(rand() % 256, rand() % 256, rand() % 256, 255);

            draw_collatz_tree(window, n, 400.0f, 600.0f, -90.0f, 100.0f, color);

            window.display();
            clock.restart();
        }
    }

    return 0;
}
