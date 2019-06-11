#include "Savanna.h"

Savanna::Savanna(const int humidity, const int vegetation, const char* terrainType, const double latitude) : Cage(humidity,vegetation, terrainType, latitude)
{
}

Savanna::~Savanna()
{
    //dtor
}

void Savanna::addAnimal(Animal& _animal){
    animal = &_animal;
    isEmpty = false;
}
