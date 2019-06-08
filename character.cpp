#include "character.h"
#include "stringTools.h"

character::character(){
    name = "default";
    maxHealth = 0;
    health = 0;
    attack = 0;
    defense = 0;
    speed = 0;
    gold = 0;
    level = 0;
    xp = 0;
    numPotions = 0;
    statPoints = 0;
}
character::character(string name, int health, int attack, int defense, int speed){
    this->name = name;
    maxHealth = health;
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    this->speed = speed;
    level = 1;
    xp = 0;
    gold = 25;
    numPotions = 0;
    statPoints = 0;
}
void character::set(string name, int health, int attack, int defense, int speed){
    this->name = name;
    maxHealth = health;
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    this->speed = speed;
}
bool character::isAlive(){
    return health > 0;
}
int character::getAttack(){
    return attack;    
}
void character::defend(int damage){
    srand(time(0));
    int damageDealt = rand()%damage+1 - rand()%defense;
    if (damageDealt<0)
        damageDealt = 0;
    
    health = health - (damageDealt);
    
    if(health<0)
        health=0;
}
void character::increaseAttribute(int attribute){
    if (attribute==1){
        ++maxHealth;
        ++health;
    }
    if (attribute==2)
        ++attack;
    if (attribute==3)
        ++defense;
    if (attribute==4)
        ++speed;
}
void character::decreaseAttribute(int attribute){
    if (attribute==1)
        --health;
    if (attribute==2)
        --attack;
    if (attribute==3)
        --defense;
    if (attribute==4)
        --speed;
}
void character::heal(int numHeals){
    for(int i=0; i<numHeals;++i)
        ++health;
    if(health>maxHealth)
        health=maxHealth;
}
void character::levelUp(){
    ++level;
    xp -= 100;
    statPoints += 3;
    cout<< "You leveled up! You gain 5 HP and 3 stat points"<<endl;
    for(int i = 0; i<5; ++i)
        increaseAttribute(1);
    increaseStats();
}
void character::increaseStats(){
    while (statPoints>0){
        cout<< endl << name << "'s Level: "<< getLevel() <<endl;
        displayStats();
        cout << "You currently have "<< statPoints <<" available stat points, "<<endl;
        cout << "Choose which attribute you want to increase by one" <<endl;
        
        string plusStat;
        int statChoice=0;
        while(statChoice<1||statChoice>4){
            statChoice=0;
            cout << "HP, ATK, DEF, or Spd"<<endl;
            cin >> plusStat;
            lowercaseString(plusStat);
            if(plusStat=="hp"||plusStat=="health")
                statChoice=1;
            else if(plusStat=="atk"||plusStat=="attack")
                statChoice=2;
            else if(plusStat=="def"||plusStat=="defense")
                statChoice=3;
            else if(plusStat=="spd"||plusStat=="speed")
                statChoice=4;
        }
        --statPoints;
        increaseAttribute(statChoice);
    }
}
void character::killedMonster(){
    int xpGained = rand()%50+25;
    int goldGained = rand()%5+10;
    xp += xpGained;
    gold += goldGained;
    cout<<"You gain " << xpGained << " XP and "<< goldGained <<" Gold" << endl <<endl;
}
bool character::goShopping(){
    string shopItem;
    while(1){
        cout<< "You have " << gold << " gold" << endl << "Would you like to buy some armour, a sword, a potion, or leave"<<endl;
        cin >> shopItem;
        lowercaseString(shopItem);
        removeSpaces(shopItem);
        
        if((shopItem=="armour"||shopItem=="armor"||shopItem=="some_armour"||shopItem=="some_armor") && gold>=50){
            for(int i = 0; i<5; ++i)
                increaseAttribute(3);
            gold -= 50;
        }
        else if((shopItem=="sword"||shopItem=="a_sword") && gold>=50){
            for(int i = 0; i<5; ++i)
                increaseAttribute(2);
            gold -= 50;
        }
        else if((shopItem=="a potion"||shopItem=="potion"||shopItem=="red_potion"||shopItem=="a_red_potion") && gold>=50){
            ++numPotions;
            gold-=50;
        }
        else if(shopItem=="leave")
            return false;
    }
}
void character::rest(int days){
    if(gold>=days*10){
        heal(20*days);
        gold-=10*days;
    }
    else
        cout<<"You lack the required gold"<<endl;
}
void character::usePotion(){
    --numPotions;
    heal(50);
}
void character::printStatus(void){
    cout <<name<<"'s HP: "<< health <<" / "<< maxHealth << endl;    
}
void character::displayStats(void){
    cout <<"HP: "<< health <<" / "<< maxHealth << " Attack: " << attack <<" Defense: " << defense<<" Speed: "<<speed<< " Gold: "<< gold<< " XP: "<< xp <<endl<<endl;
}
int character::getHealth(){
    return health;
}
int character::getSpeed(){
    return speed;
}
int character::getGold(){
    return gold;
}
int character::getPotion(){
    return numPotions;
}
int character::getXp(){
    return xp;
}
int character::getLevel(){
    return level;
}