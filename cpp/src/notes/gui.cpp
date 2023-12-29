// gui.cpp
#include "gui.h"
#include <iostream>

GUI::GUI() : window(sf::VideoMode(800, 600), "Notes App"), textArea(), notes() {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font." << std::endl;
    }

    textArea.setFont(font);
    textArea.setCharacterSize(16);
    textArea.setPosition(10, 10);
    textArea.setFillColor(sf::Color::White);
}

void GUI::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void GUI::update() {
    // Atualize a lógica do aplicativo conforme necessário
}

void GUI::render() {
    window.clear();

    // Renderize as anotações na área de texto
    const auto& notesVector = notes.getNotes();
    for (size_t i = 0; i < notesVector.size(); ++i) {
        textArea.setString(notesVector[i]);
        textArea.setPosition(10, 10 + i * 20);
        window.draw(textArea);
    }

    window.display();
}

void GUI::run() {
    while (window.isOpen()) {
        handleInput();
        update();
        render();
    }
}

