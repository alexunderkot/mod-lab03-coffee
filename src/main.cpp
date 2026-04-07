#include <iostream>
#include "../include/Automata.h"
int main(){
    Automata automata = Automata();
    automata.on();
    automata.getState();
    automata.off();
    automata.getState();
    automata.getMenu();
    automata.on();
    automata.coin(10);
    automata.getMenu();
    automata.getState();
    std::string drink = automata.choice(2);
    automata.check(drink);
    automata.coin(200);
    automata.check(drink);
    automata.cook(drink);
    automata.finish();
    return 0;
}
