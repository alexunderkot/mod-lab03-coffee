// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Automata.h"

TEST(task1, test1_part1) {
    Automata automata;
    EXPECT_EQ(automata.getCash(), 0);
    automata.on();
    EXPECT_EQ(static_cast<int>(automata.getState()),
            static_cast<int>(state::wait));
    automata.off();
    EXPECT_EQ(static_cast<int>(automata.getState()),
            static_cast<int>(state::off));
    automata.on();
    automata.coin(10);
    EXPECT_EQ(static_cast<int>(automata.getState()),
              static_cast<int>(state::accept));
    automata.getMenu();
    EXPECT_EQ(static_cast<int>(automata.getState()),
              static_cast<int>(state::accept));
}

TEST(task1, test1_part2) {
    Automata automata;
    automata.on();
    automata.coin(10);
    std::string drink = automata.choice(2);
    EXPECT_EQ(static_cast<int>(automata.getState()),
              static_cast<int>(state::check));
    automata.check(drink);
    EXPECT_EQ(static_cast<int>(automata.getState()),
              static_cast<int>(state::wait));
}

TEST(task1, test1_part3) {
    Automata automata;
    automata.on();
    automata.coin(10);
    std::string drink = automata.choice(2);
    automata.check(drink);
    automata.coin(90);
    EXPECT_EQ(automata.getCash(), 100);
    EXPECT_EQ(static_cast<int>(automata.getState()),
              static_cast<int>(state::accept));
    drink = automata.choice(2);
    automata.check(drink);
    EXPECT_EQ(static_cast<int>(automata.getState()),
              static_cast<int>(state::cook));
}

TEST(task1, test1_part4) {
    Automata automata;
    automata.on();
    automata.coin(100);
    std::string drink = automata.choice(2);
    automata.check(drink);
    automata.cook(drink);
    EXPECT_EQ(automata.getCash(), 0);
    automata.finish();
    EXPECT_EQ(automata.getState(), state::wait);
}

TEST(task1, test1_part5) {
    Automata automata;
    automata.on();
    automata.coin(100);
    std::string drink = automata.choice(2);
    automata.check(drink);
    automata.cook(drink);
    automata.finish();
    automata.off();
    EXPECT_EQ(automata.choice(2), "");
}

TEST(task1, test1_part6) {
    Automata automata;
    automata.on();
    automata.coin(99);
    std::string drink = automata.choice(2);
    automata.check(drink);
    EXPECT_EQ(automata.getCash(), 99);
}

TEST(task1, test1_part7) {
    Automata automata;
    automata.on();
    automata.coin(100);
    EXPECT_EQ(automata.choice(0), "incorrect choice");
    automata.coin(1);
    EXPECT_EQ(automata.choice(6), "incorrect choice");
}

TEST(task1, test1_part8) {
    Automata automata;
    automata.on();
    automata.coin(100);
    EXPECT_EQ(automata.choice(6), "incorrect choice");
}

TEST(task1, test1_part10) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.coin(20);
    automata.coin(30);
    EXPECT_EQ(automata.getCash(), 60);
    EXPECT_EQ(static_cast<int>(automata.getState()),
              static_cast<int>(state::accept));
}

TEST(task1, test1_part11) {
    Automata automata;
    automata.on();
    automata.coin(550);

    std::string drink1 = automata.choice(1);
    EXPECT_EQ(drink1, "Tea");
    EXPECT_EQ(static_cast<int>(automata.getState()),
              static_cast<int>(state::check));
    automata.check(drink1);
    EXPECT_EQ(static_cast<int>(automata.getState()),
              static_cast<int>(state::cook));
    automata.cook(drink1);
    automata.finish();
    EXPECT_EQ(automata.getCash(), 500);
    EXPECT_EQ(automata.getState(), state::wait);

    automata.coin(100);
    std::string drink2 = automata.choice(2);
    EXPECT_EQ(drink2, "Coffee");
    automata.check(drink2);
    automata.cook(drink2);
    automata.finish();
    EXPECT_EQ(automata.getCash(), 500);

    automata.coin(150);
    std::string drink3 = automata.choice(3);
    EXPECT_EQ(drink3, "Milk");
    automata.check(drink3);
    automata.cook(drink3);
    automata.finish();
    EXPECT_EQ(automata.getCash(), 500);

    automata.coin(200);
    std::string drink4 = automata.choice(4);
    EXPECT_EQ(drink4, "Latte");
    automata.check(drink4);
    automata.cook(drink4);
    automata.finish();
    EXPECT_EQ(automata.getCash(), 500);

    automata.coin(300);
    std::string drink5 = automata.choice(5);
    EXPECT_EQ(drink5, "Latte with almond milk and marshmello");
    automata.check(drink5);
    automata.cook(drink5);
    automata.finish();
    EXPECT_EQ(automata.getCash(), 500);
    EXPECT_EQ(automata.getState(), state::wait);
}

TEST(task1, test1_part12) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(2);
    automata.cancel();
    EXPECT_EQ(automata.getState(), state::wait);
    EXPECT_EQ(automata.getCash(), 100);
    automata.coin(100);
    automata.choice(2);
    EXPECT_EQ(automata.getState(), state::check);
    EXPECT_EQ(automata.getCash(), 200);
}
