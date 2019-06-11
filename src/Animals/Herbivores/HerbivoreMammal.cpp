#include "Animals/Herbivores/HerbivoreMammal.h"

HerbivoreMammal::HerbivoreMammal(const char* species, Food* food, const double amountOfFood) : Mammal(species, food, amountOfFood)
{
    //ctor
}

HerbivoreMammal::~HerbivoreMammal()
{
    //dtor
}
