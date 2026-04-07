#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>

enum class state{
    off = 1,
    wait,
    accept,
    check,
    cook
};

std::ostream& operator<<(std::ostream& os, state s);

class Automata{
private:
    int _cash;
    std::vector<std::string> _menu;
    std::map<std::string, int> _products;
    state _state;

public:
    Automata();
    void on();
    void off();
    void coin(int deposit);
    void getMenu();
    state getState();
    std::string choice(int choice);
    void check(std::string product);
    void cancel();
    void cook(std::string product);
    void finish();
    int getCash();
};

#endif  // INCLUDE_AUTOMATA_H_