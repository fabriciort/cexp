#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const int WIDTH = 800;
const int HEIGHT = 600;

class Flower {
public:
    Flower(unsigned long n, unsigned long petals, float radius) :
        m_n(n),
        m_petals(petals),
        m_radius(radius)
    {
        m_lines.resize(petals);
        for (int i = 0; i < petals; ++i) {
            float angle = i * 2 * M_PI / petals;
            float x = m_radius * std::cos(angle);
            float y = m_radius * std::sin(angle);
            m_points.push_back(sf::Vector2f(WIDTH / 2 + x, HEIGHT / 2 + y));
        }
    }

    void draw(sf::RenderWindow& window)
    {
        if (m_n == 1) {
            return;
        }

        unsigned long n = m_n;
        int petal = 0;
        while (n != 1) {
            if (petal >= m_petals) {
                petal = 0;
            }

            unsigned long next_n = n % 2 == 0 ? n / 2 : 3 * n + 1;

            m_lines[petal].append(sf::Vertex(m_points[petal], sf::Color::White));
            m_lines[petal].append(sf::Vertex(m_points[next_petal(petal)], sf::Color::White)));

            n = next_n;
            petal = next_petal(petal);
        }

        for (int i = 0; i < m_petals; ++i) {
            window.draw(m_lines[i]);
        }
    }

private:
    unsigned long m_n;
    unsigned long m_petals;
    float m_radius;
    std::vector<sf::VertexArray> m_lines;
    std::vector<sf::Vector2f> m_points;

    int next_petal(int petal)
    {
        return (petal + 1) % m_petals;
    }
};

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Collatz Flower");

    unsigned long n = 3;
    unsigned long max_n = 10000;
    unsigned long petals = 8;
    float radius = 200.0;
    unsigned long iterations = 0;
    unsigned long max_iterations = 1000;
    unsigned long start_time = sf::Clock().getElapsedTime().asMilliseconds();

    Flower flower(n, petals, radius);

    while (sf::Clock().getElapsedTime().asMilliseconds() - start_time < 30000) {
        window.clear(sf::Color::Black);

        flower.draw(window);

        window.display();

        n++;
        iterations++;
        if (n > max_n || iterations > max_iterations) {
            n = 3;
            iterations = 0;
            flower = Flower(n, petals, radius);
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

