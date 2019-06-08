#include "stringTools.h"

void lowercaseString(string &original){
    for(int i=0;i<original.size();++i)
        original.at(i)=tolower(original[i]);
}

void removeSpaces(string &original){
    for(int i=0;i<original.size();++i){
        if(original.at(i)==' ')
            original.at(i)='_';
    }
}