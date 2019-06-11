#include "Animals/Models/Mammal.h"

Mammal::Mammal(const char* species, Food* food, const double amountOfFood) : Animal(species, food, amountOfFood)
{
    //ctor
}

Mammal::~Mammal()
{
    //dtor
}
