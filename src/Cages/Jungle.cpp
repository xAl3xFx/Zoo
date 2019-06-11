#include "Jungle.h"

Jungle::Jungle(const int humidity, const int vegetation, const char* terrainType, const double latitude) : Cage(humidity,vegetation, terrainType, latitude)
{
}

Jungle::~Jungle()
{
    //dtor
}

void Jungle::addAnimal(Animal& _animal){
    animal = &_animal;
    isEmpty = false;
}
