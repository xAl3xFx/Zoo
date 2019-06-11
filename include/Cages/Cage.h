#ifndef CAGE_H
#define CAGE_H
#include "Animals/Models/Animal.h"
#include <typeinfo>
#include <cstring>

/**
 * Class holding information about the abstract (base) class Cage.
 */
class Cage{
protected:
    /**
    * Variable giving access to the console.
    */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    /**
    * Variables holding information about the humidity and vegetation percentages in the cage.
    */
    int humidity, vegetation;
    /**
    * Variable holding information about the latitude of the cage.
    */
    double latitude;
    /**
    * Variable indicating whether the cage has an animal in it or not.
    */
    bool isEmpty;
    /**
    * Variable holding information about the terrain type of the cage.
    */
    char* terrainType;
    /**
    * Reference to the animal in the cage.
    */
    Animal* animal;
    /**
    * Function that parses the typeid(*this) correctly as char*.
    */
    char* parseTypeName();
    /**
    * Copy function (used in copy constructor and operator=.
    */
    void copyCage(const Cage&);
public:
    /**
    * Constructor taking 4 parameters.
    * param1: The humidity% in the cage.
    * param2: The vegetation% in the cage.
    * param3: The terrain type of the cage.
    * param4: The latitude of the cage.
    */
    Cage(const int, const int, const char*, const double);
    /**
    * Copy constructor.
    */
    Cage(const Cage&);
    /**
    * Operator =.
    */
    Cage& operator=(const Cage&);
    /**
    * Virtual destructor because this is an abstract class.
    */
    virtual ~Cage();
    /**
    * Virtual function which adds an animal to the cage.
    */
    virtual void addAnimal(Animal&) = 0;
    /**
    * Function that returns the animal in the cage.
    */
    Animal* getAnimal(){return animal;}
    /**
    * Function that returns the correctly parsed typeid(*this) as char*.
    */
    char* getTypeName(){return parseTypeName();}
    /**
    * Function that returns whether there is an animal in the cage or not.
    */
    bool getIsEmpty() const {return isEmpty;}
    /**
    * Function that returns the amount of food that the animal in the cage eats.
    */
    double getAmountOfFood() {return animal->getAmountOfFood();}
    /**
    * Function that returns the specific type of food that the animal in the cage eats.
    */
    const std::type_info& getFoodType(){return typeid(*(animal->getFood()));}
    /**
    * Function that shows information about the cage.
    */
    void showInfo();
};


#endif // CAGE_H
