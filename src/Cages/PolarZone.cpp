#include "PolarZone.h"

PolarZone::PolarZone(const int humidity, const int vegetation, const char* terrainType, const double latitude) : Cage(humidity,vegetation, terrainType, latitude)
{
}

PolarZone::~PolarZone()
{
    //dtor
}

void PolarZone::addAnimal(Animal& _animal){
    animal = &_animal;
    isEmpty = false;
}
