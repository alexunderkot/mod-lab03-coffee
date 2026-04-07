#include "../include/Automata.h"

std::ostream &operator<<(std::ostream &os, state s)
{
    switch (s)
    {
    case state::off:
        return os << "off";
        break;
    case state::wait:
        return os << "wait";
        break;
    case state::accept:
        return os << "accept";
        break;
    case state::check:
        return os << "check";
        break;
    case state::cook:
        return os << "cook";
        break;
    default:
        return os << "error";
    }
    return os;
}

Automata::Automata()
{
    _cash = 0;
    _menu = {"Tea", "Coffee", "Milk", "Latte", "Latte with almond milk and marshmello"};
    _products = {
        {"Tea", 50},
        {"Coffee", 100},
        {"Milk", 150},
        {"Latte", 200},
        {"Latte with almond milk and marshmello", 300}};
    _state = state::off;
}

void Automata::on()
{
    if (this->_state != state::off)
        return;
    this->_state = state::wait;
    std::cout << "Turning on...\n";
}
void Automata::off()
{
    if (this->_state != state::wait)
        return;
    this->_state = state::off;
    std::cout << "Turning off...\n";
}
void Automata::coin(int deposit)
{
    if (this->_state != state::wait || this->_state != state::accept)
        return;
    std::cout << "Accepting deposit...\n";
    this->_state = state::accept;
    this->_cash += deposit;
}
void Automata::getMenu()
{
    if (this->_state == state::off)
        return;
    std::cout << "Printing menu...\n";
    for (size_t i = 0; i < this->_menu.size(); i++)
        std::cout << this->_menu[i] << '\t' << this->_products[_menu[i]] << std::endl;
}
state Automata::getState()
{
    std::cout << "Printing state...\n";
    std::cout << this->_state << std::endl;
    return this->_state;
}
std::string Automata::choice(int choice)
{
    if (this->_state != state::accept)
        return "";
    std::cout << "Operating your choice...\n";
    this->_state = state::check;
    return (choice <= _menu.size() && choice > 0) ? this->_menu[choice - 1] : "incorrect choice";
}
void Automata::check(std::string product)
{
    if (this->_state != state::check)
        return;
    std::cout << "Trying to charge you for the product...\n";
    if (_cash >= _products[product])
    {
        this->_state = state::cook;
        return;
    }
    std::cout << "Not enough money!\n";
    this->_state = state::wait;
}
void Automata::cancel()
{
    if (this->_state != state::check || this->_state != state::accept)
        return;
    std::cout << "Canceling...\n";
    this->_state = state::wait;
}
void Automata::cook(std::string product)
{
    if (this->_state != state::check)
        return;
    std::cout << "Cooking...\n";
    this->_state = state::cook;
    this->_cash -= this->_products[product];
}
void Automata::finish()
{
    if (this->_state != state::cook)
        return;
    std::cout << "Take your purchase, please!\n";
    this->_state = state::wait;
}
int Automata::getCash()
{
    return this->_cash;
}