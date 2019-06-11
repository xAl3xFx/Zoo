#include "Aquarium.h"
Aquarium::Aquarium(const int humidity, const int vegetation, const char* terrainType) : Cage(humidity,vegetation, terrainType, 0)
{
}

Aquarium::~Aquarium(){

}

void Aquarium::addAnimal(Animal& _animal){
    animal = &_animal;
    isEmpty = false;
}
