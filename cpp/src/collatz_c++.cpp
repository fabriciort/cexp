#include <SFML/Graphics.hpp>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

void draw_sequence(sf::RenderWindow& window, unsigned long n)
{
    sf::VertexArray lines(sf::LinesStrip, 0);
    lines.append(sf::Vertex(sf::Vector2f(0, HEIGHT - n / 2), sf::Color::Red));
    while (n != 1) {
        if (lines.getVertexCount() >= WIDTH) {
            break;
        }
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        lines.append(sf::Vertex(sf::Vector2f(lines.getVertexCount(), HEIGHT - n / 2), sf::Color::Red));
    }
    window.draw(lines);
}

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Collatz Conjecture");

    unsigned long n = 10000;
    unsigned long max_n = 10000000;
    unsigned long iterations = 100;
    unsigned long max_iterations = 1000;
    unsigned long start_time = sf::Clock().getElapsedTime().asMilliseconds();

    while (sf::Clock().getElapsedTime().asMilliseconds() - start_time < 30000) {
        window.clear(sf::Color::Black);

        draw_sequence(window, n);

        window.display();

        n++;
        iterations++;
        if (n > max_n || iterations > max_iterations) {
            n = 1;
            iterations = 0;
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(0);
            }
        }
    }

    return 0;
}

