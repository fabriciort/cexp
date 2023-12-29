// notes.h
#ifndef NOTES_H
#define NOTES_H

#include <string>
#include <vector>

class Notes {
public:
    void addNote(const std::string& note);
    const std::vector<std::string>& getNotes() const;

private:
    std::vector<std::string> notes;
};

#endif

