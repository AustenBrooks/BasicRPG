#include "art.h"

void art(string defender){
    if(defender== "player"){
    cout<<"  O ~~}O  "<<endl;
    cout<<" \\|/   \\______"<<endl;
    cout<<" / \\   / \\  / \\ "<<endl;
    }
    if(defender == "monster"){
        cout<<"  O      O"<<endl;
        cout<<" \\|--+==> \\______ "<<endl;
        cout<<" / \\      / \\  / \\ "<<endl;
    }
}

void shop(){
    cout<<"               YE OLDE SHOPPE"<<endl;
    cout<<endl;
    cout<<"                                  ____"<<endl;
    cout<<"     _____      |\\               (____)   "<<endl;
    cout<<"    / ___ \\     \\ \\              |    |           "<<endl; 
    cout<<"    |(___)|      \\ \\            /      \\           "<<endl;
    cout<<"    |_____|       \\ \\          /________\\                  "<<endl;                      
    cout<<"    _     _        \\ \\  /     /          \\      "<<endl;
    cout<<"   | |___| |        \\ \\/      |          |    "<<endl;
    cout<<"   |       |         \\/\\      |          | "<<endl;
    cout<<"   |       |         /\\ \\     \\          /  "<<endl;
    cout<<"    \\_____/         /  \\/      \\________/"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"  Armour 50 G  Sword 50 G   Red Potion 50 G "<<endl;
    cout<<"     +5 DEF       +5 ATK         +50 HP "<<endl;
}