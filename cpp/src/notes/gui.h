// gui.h
#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include "notes.h"

class GUI {
public:
    GUI();

    void run();

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text textArea;
    Notes notes;

    void handleInput();
    void update();
    void render();
};

#endif

