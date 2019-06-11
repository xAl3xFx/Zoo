#include "Cages/Forest.h"

Forest::Forest(const int humidity, const int vegetation, const char* terrainType, const double latitude) : Cage(humidity,vegetation, terrainType, latitude)
{
}

Forest::~Forest()
{
    //dtor
}

void Forest::addAnimal(Animal& _animal){
    animal = &_animal;
    isEmpty = false;
}
