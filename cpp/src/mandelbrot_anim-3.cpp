#include <SFML/Graphics.hpp>
#include <complex>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;
const int MAX_ITER = 200;

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
    int samples = 2;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    centerX = (event.mouseButton.x - WIDTH / 2.0) * zoom / WIDTH + centerX;
                    centerY = (event.mouseButton.y - HEIGHT / 2.0) * zoom / WIDTH + centerY;
                    zoom *= 0.5;
                    samples *= 2;
                }
                else if (event.mouseButton.button == sf::Mouse::Right) {
                    centerX = (event.mouseButton.x - WIDTH / 2.0) * zoom / WIDTH + centerX;
                    centerY = (event.mouseButton.y - HEIGHT / 2.0) * zoom / WIDTH + centerY;
                    zoom *= 2.0;
                    samples /= 2;
                    if (samples < 1) {
                        samples = 1;
                    }
                }
            }
        }

        sf::Image image;
        image.create(WIDTH / samples, HEIGHT / samples, sf::Color::Black);

        for (int y = 0; y < HEIGHT / samples; ++y) {
            for (int x = 0; x < WIDTH / samples; ++x) {
                double real = (x - WIDTH / 2.0 / samples) * zoom / WIDTH + centerX;
                double imag = (y - HEIGHT / 2.0 / samples) * zoom / WIDTH + centerY;
                std::complex<double> c(real, imag);
                int iter = mandelbrot(c);
                sf::Color color(iter % 256, iter % 256, iter % 256);
                image.setPixel(x, y, color);
            }
        }

        sf::Texture texture;
        texture.loadFromImage(image);
        sf::Sprite sprite(texture);
        sprite.setScale(samples, samples);
        window.draw(sprite);
        window.display();
    }

    return 0;
}

