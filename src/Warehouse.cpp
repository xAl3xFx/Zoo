#include "Warehouse.h"
Warehouse::Warehouse()
{
    fish = 0;
    meat = 0;
    plants = 0;
}

Warehouse::~Warehouse()
{
    //dtor
}

void Warehouse::loadFood(const double _meat, const double _fish, const double _plants){
    meat += _meat;
    fish += _fish;
    plants += _plants;
}

bool Warehouse::takeMeat(const double _meat){
    if((meat-_meat)>=0){
        meat-=_meat;
        return true;
    }
    return false;
}

bool Warehouse::takeFish(const double _fish){
    if((fish-_fish)>=0){
        fish-=_fish;
        return true;
    }
    return false;
}


bool Warehouse::takePlants(const double _plants){
    if((plants-_plants)>=0){
        plants-=_plants;
        return true;
    }
    return false;
}

