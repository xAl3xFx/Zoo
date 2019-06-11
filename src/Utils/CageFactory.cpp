#include "CageFactory.h"

Cage* CageFactory::createCage(const int cageType){
    switch(cageType){
    case 1:
        return new Forest(40,70, "forest", 50);
        break;
    case 2:
        return new Savanna(20, 60, "desert",  15);
        break;
    case 3:
        return new Jungle(90,90, "jungle", 23);
        break;
    case 4:
        return new PolarZone(20, 0, "water", 66);
        break;
    case 5:
        return new Aquarium(100, 10, "water");
        break;
    case 6:
        return new Terrarium(50, 70, "rocky");
        break;
    }
}
