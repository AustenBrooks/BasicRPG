#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class character{
    private:
    string name;
    int maxHealth, health, attack, defense, speed;
    int level, xp;
    int gold;
    int numPotions;
    int statPoints;
    
    public:

    character();

    character(string name, int health, int attack, int defense, int speed);

    void set(string name, int health, int attack, int defense, int speed);

    bool isAlive();

    int getAttack();

    void defend(int damage);

    void increaseAttribute(int attribute);

    void decreaseAttribute(int attribute);

    void heal(int numHeals);

    void levelUp();

    void increaseStats();

    void killedMonster();

    bool goShopping();

    void rest(int days);

    void usePotion();

    void printStatus(void);

    void displayStats(void);

    int getHealth();

    int getSpeed();

    int getGold();
    
    int getPotion();
    
    int getXp();
    
    int getLevel();
};
#endif