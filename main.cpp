#include <unistd.h>
#include "art.h"
#include "stringTools.h"
#include "character.h"

using namespace std;

int main(){
    string name = "Default Man";
    int hp=10, atk=5, def=5, spd=5;
    
    srand(time(0));
    
    cout << "Enter your name"<<endl;
    cin >> name;
    
    character player(name,hp,atk,def,spd);
    character monster("monster",1,1,1,1);
    while (player.isAlive()){
        
        while (player.getXp() >= 100){
            player.levelUp();
            
            usleep(1500000);
        }
        
        bool isStopped= true;
        string path;
        while(isStopped){
            player.displayStats();
            
            cout<<"You are currently at a town, would you like to:"<< endl <<"Continue on the road, Visit the Shop, Rest at the Inn, or Retire from Adventuring?"<<endl;
            cin>>path;
            lowercaseString(path);
            removeSpaces(path);
            
            if (path=="retire"||path=="retire_from_adventuring"){
                cout <<endl << name << " retired at level: "<< player.getLevel() <<" with "<< player.getGold() <<" gold" << endl;
                player.displayStats();
                return 0;
                
            }
            else if (path == "continue"||path == "continue_on_the_road"||path == "road"){
                isStopped = false;
            }
            else if(path =="visit"||path=="shop"||path=="visit_the_shop"){
                shop();
                
                bool isShopping= true;
                while (isShopping){
                    isShopping = player.goShopping();
                }
            }
            else if(path =="rest_t_the_inn"||path =="rest"||path =="inn"){
                int daysRest=0;
                cout<< "Staying in the inn will cost 10 gold per day, and restore 20 life."<<endl<<"How many days would you life to stay?"<<endl;
                cin>>daysRest;
                player.rest(daysRest);
            }
        }
        
        string playerMove;
        usleep(1000000);
        cout<<"You encounter a monster on the road"<<endl;
        
        monster.set("Monster",(rand()%(player.getLevel()*2))+5,(rand()%(player.getLevel()*3))+3,(rand()%(player.getLevel()))+1,(rand()%(player.getLevel()*2))+3);
        
        int turnCount=0;
        while(monster.isAlive() && player.isAlive()){
            usleep(500000);
            ++turnCount;
            cout<< "Turn "<<turnCount<<endl;
            
            bool isChoosing = true;
            bool isAttacking = true;
            bool isSuccessful= false;
            while(isChoosing){
                cout<<"Attack, Defend, Item, or Flee"<<endl;
                cin >> playerMove;
                lowercaseString(playerMove);
                
                if(playerMove=="attack")
                    isChoosing=false;
                
                else if(playerMove=="defend"){
                    player.increaseAttribute(3);
                    isChoosing=false;
                    isAttacking=false;
                }
                else if(playerMove=="item"){
                    if (player.getPotion()==0){
                        cout << "You have no potions available"<<endl;
                        break;
                    }
                    
                    else while(1){
                        cout<<"You have "<<player.getPotion()<<" potions, would you like to use one?"<<endl;
                        string potionUse;
                        cin>>potionUse;
                        lowercaseString(potionUse);
                        if(potionUse=="yes"||potionUse=="y"){
                            player.usePotion();
                            isChoosing=false;
                            break;
                        }
                        else{
                            cout<<"No potions were used"<<endl;
                            break;
                        }
                    }
                }
                
                else if(playerMove=="flee"){
                    isChoosing=false;
                    isAttacking=false;
                    
                    if (monster.getSpeed()>player.getSpeed()){
                        int flee = rand()%(monster.getSpeed()+1-player.getSpeed());
                        if(flee==0){
                            cout<<"The monster is faster than you, but you successfully outmaneuvered it"<<endl;
                            isSuccessful=true;
                        }
                        else
                            cout<<"The monster is faster than you, and caught up to you"<<endl;
                    }
                    else if (monster.getSpeed()==player.getSpeed()){
                        int flee = rand()%2;
                        if(flee){
                            cout<<"You and the monster are of equal speed, but you managed to escape"<<endl;
                            isSuccessful=true;
                        }
                        else
                            cout<<"You and the monster are of equal speed, but the monster managed to cut you off"<<endl;
                    }
                    else{
                        cout<<"You are faster than the monster, and outran it"<<endl;
                        isSuccessful=true;
                    }
                }
            }
            
            if(playerMove=="flee" && isSuccessful)
                break;
            
            else if(!isAttacking||playerMove=="item"){
                player.defend(monster.getAttack());
                art("player");
                player.printStatus();
                
                if(player.getHealth()<= 0)
                    break;
            }
            
            else if(monster.getSpeed() > player.getSpeed()){
                player.defend(monster.getAttack());
                art("player");
                player.printStatus();
                
                if(player.getHealth()<= 0)
                    break;
                
                usleep(500000);
                
                monster.defend(player.getAttack());
                art("monster");
                monster.printStatus();
            }   
            
            else {
                monster.defend(player.getAttack());
                art("monster");
                monster.printStatus();
                
                if(monster.getHealth()<=0)
                    break;
                
                usleep(500000);
                
                player.defend(monster.getAttack());
                art("player");
                player.printStatus();
            }
            
            if(playerMove=="defend")
                player.decreaseAttribute(3);
        }   
        if(playerMove=="flee")
            cout<< "You successfully ran away"<<endl<<endl;
        
        else if(player.isAlive()){
        cout<< "Player wins!"<<endl;
        player.killedMonster();
        }
        
        else if(monster.isAlive())
            cout << "Monster wins!" << endl;
    }
    cout << "Game Over"<<endl;
    return 0;
}
