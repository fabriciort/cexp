// notes.cpp
#include "notes.h"

void Notes::addNote(const std::string& note) {
    notes.push_back(note);
}

const std::vector<std::string>& Notes::getNotes() const {
    return notes;
}

