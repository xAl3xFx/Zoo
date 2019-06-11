#include "Animals/Models/Reptile.h"

Reptile::Reptile(const char* species, Food* food, const double amountOfFood) : Animal(species, food, amountOfFood)
{
    //ctor
}

Reptile::~Reptile()
{
    //dtor
}
