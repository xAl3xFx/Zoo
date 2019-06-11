#include "Animals/Models/Bird.h"

Bird::Bird(const char* species, Food* food, const double amountOfFood) : Animal(species, food, amountOfFood)
{
    //ctor
}

Bird::~Bird()
{
    //dtor
}
