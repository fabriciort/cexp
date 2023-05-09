#include "koch_curve.h"
#include <cmath>

void draw_koch_curve(sf::RenderTarget &target, float x1, float y1, float x2, float y2, int depth, const sf::Color &color) {
    if (depth == 0) {
        sf::Vertex line[] = {sf::Vertex(sf::Vector2f(x1, y1), color), sf::Vertex(sf::Vector2f(x2, y2), color)};
        target.draw(line, 2, sf::Lines);
    } else {
        float dx = x2 - x1;
        float dy = y2 - y1;

        float x3 = x1 + dx / 3.0;
        float y3 = y1 + dy / 3.0;

        float x5 = x1 + dx * 2.0 / 3.0;
        float y5 = y1 + dy * 2.0 / 3.0;

        float x4 = x3 + (dx / 3.0) * cos(M_PI / 3.0) - (dy / 3.0) * sin(M_PI / 3.0);
        float y4 = y3 + (dx / 3.0) * sin(M_PI / 3.0) + (dy / 3.0) * cos(M_PI / 3.0);

        draw_koch_curve(target, x1, y1, x3, y3, depth - 1, color);
        draw_koch_curve(target, x3, y3, x4, y4, depth - 1, color);
        draw_koch_curve(target, x4, y4, x5, y5, depth - 1, color);
        draw_koch_curve(target, x5, y5, x2, y2, depth - 1, color);
    }
}

