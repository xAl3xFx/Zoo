#ifndef ANIMAL_H
#define ANIMAL_H
#include <cstring>
#include <iostream>
#include <windows.h>
#include <typeinfo>
#include "Food/Food.h"

/**
 * Class holding information about the abstract (base) class Animal.
 */
class Animal{
protected:
    /**
    * Variable giving access to the console.
    */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    /**
    * Variable holding information about the species of the animal.
    */
    char* species;
    /**
    * Pointer to a variable of type Food holding information about the food that the animal eats.
    */
    Food* food;
    /**
    * Variable holding information about the amount of food that the animal eats.
    */
    double amountOfFood;
    /**
    * Function which parses the actual type of the animal.
    */
    char* parseTypeName();
    /**
    * Function which parses the actual type of the Food which the animal eats.
    */
    char* parseFoodTypeName();
    /**
    * Copy function (used in copy constructor and operator=.
    */
    void copyAnimal(const Animal&);
public:
    /**
    * Constructor with 3 parameters.
    * param1: species of the animal.
    * param2: Type of food that the animal eats.
    * param3: amount of food that the animal eats.
    */
    Animal(const char*, Food*, const double);
    /**
    * Copy constructor.
    */
    Animal(const Animal&);
    /**
    * Operator =.
    */
    Animal& operator=(const Animal&);

    /**
    * Virtual destructor because this is an abstract class.
    */
    virtual ~Animal();
    /**
    * Getter for amountOfFood.
    */
    double getAmountOfFood() const {return amountOfFood;}
    /**
    * Getter for Food.
    */
    Food* getFood() const {return food;}
    /**
    * Getter for species.
    */
    char* getSpecies() const {return species;}
    /**
    * Function which shows information for the animal.
    */
    void showInfo();
};

#endif // ANIMAL_H
