#include <SFML/Graphics.hpp>
#include <complex>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;
const int MAX_ITER = 1000;

int mandelbrot(const std::complex<double>& c)
{
    std::complex<double> z(0, 0);
    int i;
    for (i = 0; i < MAX_ITER && std::norm(z) < 4.0; ++i) {
        z = z * z + c;
    }
    return i;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Mandelbrot Zoom");

    double zoom = 1.0;
    double centerX = -0.5;
    double centerY = 0.0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    centerX = (WIDTH / 2.0) * zoom / WIDTH + centerX;
                    centerY = (HEIGHT / 2.0) * zoom / WIDTH + centerY;
                    zoom *= 0.5;
                }
                else if (event.key.code == sf::Keyboard::Num0) {
                    centerX = (WIDTH / 2.0) * zoom / WIDTH + centerX;
                    centerY = (HEIGHT / 2.0) * zoom / WIDTH + centerY;
                    zoom *= 2.0;
                }
            }
        }

        sf::Image image;
        image.create(WIDTH, HEIGHT, sf::Color::Black);

        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                double real = (x - WIDTH / 2.0) * zoom / WIDTH + centerX;
                double imag = (y - HEIGHT / 2.0) * zoom / WIDTH + centerY;
                std::complex<double> c(real, imag);
                int iter = mandelbrot(c);
                sf::Color color(iter % 256, iter % 256, iter % 256);
                image.setPixel(x, y, color);
            }
        }

        sf::Texture texture;
        texture.loadFromImage(image);
        sf::Sprite sprite(texture);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
