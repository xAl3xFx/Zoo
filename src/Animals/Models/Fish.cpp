#include "Animals/Models/Fish.h"

Fish::Fish(const char* species, Food* food, const double amountOfFood) : Animal(species, food, amountOfFood)
{
    //ctor
}

Fish::~Fish()
{
    //dtor
}
