#ifndef CAGEFACTORY_H
#define CAGEFACTORY_H
#include<cstring>
#include "Cage.h"
#include "Aquarium.h"
#include "Forest.h"
#include "Jungle.h"
#include "PolarZone.h"
#include "Savanna.h"
#include "Terrarium.h"

/**
 * Factory for cages.
 */
class CageFactory{
     public:
        /**
        * Static function which creates a pointer to a cage by taking a corresponding integer as argument and returning this pointer;
        */
        static Cage* createCage(const int);
};

#endif // CAGEFACTORY_H
