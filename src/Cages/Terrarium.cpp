#include "Terrarium.h"

Terrarium::Terrarium(const int humidity, const int vegetation, const char* terrainType) : Cage(humidity,vegetation, terrainType, 0)
{
}

Terrarium::~Terrarium()
{
    //dtor
}

void Terrarium::addAnimal(Animal& _animal){
    animal = &_animal;
    isEmpty = false;
}
