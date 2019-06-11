#ifndef ANIMALFACTORY_H
#define ANIMALFACTORY_H
#include "Animals/Models/Animal.h"
#include "Animals/Herbivores/HerbivoreBird.h"
#include "Animals/Herbivores/HerbivoreFish.h"
#include "Animals/Herbivores/HerbivoreMammal.h"
#include "Animals/Herbivores/HerbivoreReptile.h"
#include "Animals/Predators/PredatorBird.h"
#include "Animals/Predators/PredatorFish.h"
#include "Animals/Predators/PredatorMammal.h"
#include "Animals/Predators/PredatorReptile.h"
#include "Food/Food.h"
#include "Food/FishFood.h"
#include "Food/Meat.h"
#include "Food/PlantFood.h"

/**
 * Factory for animals.
 */
class AnimalFactory{
    public:
        /**
        * Static function which creates a pointer to an animal by taking it's species and returning this pointer;
        */
        static Animal* createAnimal(const char*);
};

#endif // ANIMALFACTORY_H
