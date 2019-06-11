#ifndef COMMANDDISPATCHER_H
#define COMMANDDISPATCHER_H
#include "Zoo.h"
#include "fstream"
#include "AnimalFactory.h"
#include "CageFactory.h"
#include "Cage.h"

/**
 * Declaration of the class Zoo so that the CommandDispatcher class knows that the Zoo class exists.
 */
class Zoo;
/**
 * Class performing all of the zoo's functionality.
 * This class implements the Command Dispatcher pattern.
 * This class implements the Singleton pattern.
 */
class CommandDispatcher{
    /**
    * Variable giving access to the console.
    */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    /**
    * Static reference to the only instance of this class (Singleton).
    */
    static CommandDispatcher* instance;
    /**
    * Private constructor so that it's not possible to create second instance of this class (Singleton).
    */
    CommandDispatcher();
    /**
    * Function that prints to the console all possible animals that can be accommodated to the zoo.
    */
    void printAnimalsList();
    /**
    * Function that prints to the console all possible cages that can be build.
    */
    void printCagesList();
    /**
    * Function that prints to the console the species of the animals that are in the zoo.
    */
    void printAnimalsFromTheZoo(Zoo&);
    /**
    * Function that prints to the console the types of the cages that are already built in the zoo.
    */
    void printCagesFromTheZoo(Zoo&);

    /**
    * Constant variable which holds all of the species that can be accommodated in the zoo.
    */
    static const char* animals[22];
public:
    /**
    * Function that returns pointer to the only instance of this class (Singleton).
    */
    static CommandDispatcher* getInstance();
    /**
    * Function that adds an animal to the zoo.
    */
    void addAnimal(Zoo&);
    /**
    * Function that builds a cage in the zoo.
    */
    void buildCage(Zoo&);
    /**
    * Function that calculates the food needed for all of the animals from the zoo and fills the warehouse with this amount of food.
    */
    void loadFood(Zoo&);
    /**
    * Function that feeds all of the animals from the zoo (if there is enough food in the warehouse).
    */
    void feedTheAnimals(Zoo&);
    /**
    * Function that shows information for an animal from the zoo.
    */
    void showAnimalInfo(Zoo&);
    /**
    * Function that shows information for a cage from the zoo.
    */
    void showCageInfo(Zoo&);
    ~CommandDispatcher();
};

#endif // COMMANDDISPATCHER_H
