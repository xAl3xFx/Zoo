#include "Utils/CommandDispatcher.h"

CommandDispatcher* CommandDispatcher::instance = 0;

CommandDispatcher::CommandDispatcher(){}

const char* CommandDispatcher::animals[22] = {
    "Brown Bear",
    "Wolf",
    "Wild Goat",
    "Owl",
    "Eagle",
    "Lion",
    "Tiger",
    "Lynx",
    "Lemur",
    "Parrot",
    "Giraffe",
    "Elephant",
    "Zebra",
    "Polar Bear",
    "Penguin",
    "Seal",
    "Dolphin",
    "Shark",
    "Clown Fish",
    "Python",
    "Monitor Lizard",
    "Chameleon"
};

CommandDispatcher* CommandDispatcher::getInstance(){

    if (instance == 0){
        instance = new CommandDispatcher();
    }
    return instance;
}

CommandDispatcher::~CommandDispatcher(){
    for(int i=0;i<22;i++){
        delete animals[i];
    }
    delete[] animals;
}

void CommandDispatcher::printAnimalsList(){
    ifstream iFile("animals.txt");
    if(!iFile){
        SetConsoleTextAttribute(hConsole, 4);
        cerr << "Animals list could not be loaded." << endl;
        SetConsoleTextAttribute(hConsole, 6);
        return;
    }
    char ch;
    SetConsoleTextAttribute(hConsole, 7);
    while (iFile.get(ch))
    cout << ch;
    SetConsoleTextAttribute(hConsole, 6);
    iFile.close();
}

void CommandDispatcher::printCagesList(){
    ifstream iFile("cages.txt");
    if(!iFile){
        SetConsoleTextAttribute(hConsole, 4);
        cerr << "Cages list could not be loaded." << endl;
        SetConsoleTextAttribute(hConsole, 6);
        return;
    }
    char ch;
    SetConsoleTextAttribute(hConsole, 7);
    while (iFile.get(ch))
    cout << ch;
    SetConsoleTextAttribute(hConsole, 6);
    iFile.close();
}

void CommandDispatcher::printAnimalsFromTheZoo(Zoo& zoo){
    for(int i=0; i<zoo.cur; i++){
        if(!zoo.cages[i]->getIsEmpty()){
            SetConsoleTextAttribute(hConsole, 7);
            cout << (i+1) << ". " << zoo.cages[i]->getAnimal()->getSpecies() << endl;
            SetConsoleTextAttribute(hConsole, 6);
        }
    }
}

void CommandDispatcher::printCagesFromTheZoo(Zoo& zoo){
    for(int i=0; i<zoo.cur; i++){
        char* typeName = zoo.cages[i]->getTypeName();
        SetConsoleTextAttribute(hConsole, 7);
        cout << (i+1) << ". " << typeName << endl;
        SetConsoleTextAttribute(hConsole, 6);
        delete[] typeName;
    }
}

void CommandDispatcher::addAnimal(Zoo& zoo){
    cout << "Please choose the animal you want to accommodate" << endl;
    printAnimalsList();
    cout << endl;
    int option = Validator::getInstance()->validateIntInBetween(1,26);
    Animal* animal = AnimalFactory::createAnimal(CommandDispatcher::animals[option-1]);
    bool isAdd = false;
    for(int i=0; i<zoo.cur; i++){
            if(zoo.cages[i]->getIsEmpty()){
                if(option>=1 && option<=5){
                    if(typeid(*zoo.cages[i])==typeid(Forest)){
                        zoo.cages[i]->addAnimal(*animal);
                        isAdd = true;
                    }
                }
                else if((option>=6 && option<=8)||(option>=11 && option <=13)){
                    if(typeid(*zoo.cages[i])==typeid(Savanna)){
                        zoo.cages[i]->addAnimal(*animal);
                        isAdd = true;
                    }
                }
                else if((option>=9 && option<=10)){
                    if(typeid(*zoo.cages[i])==typeid(Jungle)){
                        zoo.cages[i]->addAnimal(*animal);
                        isAdd = true;
                    }
                }
                else if((option>=14 && option<=16)){
                    if(typeid(*zoo.cages[i])==typeid(PolarZone)){
                        zoo.cages[i]->addAnimal(*animal);
                        isAdd = true;
                    }
                }
                else if((option>=17 && option<=19)){
                    if(typeid(*zoo.cages[i])==typeid(Aquarium)){
                        zoo.cages[i]->addAnimal(*animal);
                        isAdd = true;
                    }
                }
                else if((option>=20 && option<=22)){
                    if(typeid(*zoo.cages[i])==typeid(Terrarium)){
                        zoo.cages[i]->addAnimal(*animal);
                        isAdd = true;
                    }
                }
            }
        }
    if(isAdd){
        SetConsoleTextAttribute(hConsole, 10);
        cout << "The animal was successfully accommodated." << endl;
        SetConsoleTextAttribute(hConsole, 6);
    }else{
        SetConsoleTextAttribute(hConsole, 4);
        cerr << "No suitable cage found. The animal was not accommodated." << endl;
        SetConsoleTextAttribute(hConsole, 6);
    }
}

void CommandDispatcher::buildCage(Zoo& zoo){
    cout << "Please choose the type of cage you want to build" << endl;
    printCagesList();
    cout << endl;
    int option = Validator::getInstance()->validateIntInBetween(1,6);
    Cage* cage = CageFactory::createCage(option);
    //zoo.buildCage(*cage);
    if(zoo.cur < zoo.cap){
        zoo.cages[zoo.cur] = cage;
    }
    else if(zoo.cur==zoo.cap){
        zoo.resizeCages();
        zoo.cages[zoo.cur] = cage;
    }
    zoo.cur++;
    SetConsoleTextAttribute(hConsole, 10);
    cout << "The cage was build successfully." << endl;
    SetConsoleTextAttribute(hConsole, 6);
}

void CommandDispatcher::loadFood(Zoo& zoo){
    bool areAllCagesEmpty = true;
    for(int i=0; i<zoo.cur; i++){
        if(!zoo.cages[i]->getIsEmpty())
        areAllCagesEmpty = false;
    }
    if(areAllCagesEmpty){
        SetConsoleTextAttribute(hConsole, 4);
        cerr << "The warehouse was not filled because there are no animals in the zoo." << endl;
        SetConsoleTextAttribute(hConsole, 6);
        return;
    }
    double meat = 0, fish = 0, plants = 0;
    for(int i=0;i<zoo.cur;i++){
        if(zoo.cages[i]->getFoodType()==typeid(Meat)){
            meat += zoo.cages[i]->getAmountOfFood();
        }
        else if(zoo.cages[i]->getFoodType()==typeid(FishFood)){
            fish += zoo.cages[i]->getAmountOfFood();
        }
        else if(zoo.cages[i]->getFoodType()==typeid(PlantFood)){
            plants += zoo.cages[i]->getAmountOfFood();
        }
    }
    zoo.warehouse.loadFood(meat, fish, plants);
    SetConsoleTextAttribute(hConsole, 10);
    cout << "The warehouse has been filled successfully." << endl;
    SetConsoleTextAttribute(hConsole, 6);
}

void CommandDispatcher::feedTheAnimals(Zoo& zoo){
    bool areFed = true;
    bool areAllCagesEmpty = true;
    for(int i=0; i<zoo.cur; i++){
        if(!zoo.cages[i]->getIsEmpty())
        areAllCagesEmpty = false;
    }
    if(areAllCagesEmpty){
        SetConsoleTextAttribute(hConsole, 4);
        cerr << "There are no animals in the zoo." << endl;
        SetConsoleTextAttribute(hConsole, 6);
        return;
    }
    for(int i=0; i<zoo.cur; i++){
        if(zoo.cages[i]->getFoodType()==typeid(Meat)){
            if(zoo.warehouse.takeMeat(zoo.cages[i]->getAmountOfFood()))
                continue;
            areFed = false;
        }
        else if(zoo.cages[i]->getFoodType()==typeid(FishFood)){
            if(zoo.warehouse.takeFish(zoo.cages[i]->getAmountOfFood()))
                continue;
            areFed = false;
        }
        else if(zoo.cages[i]->getFoodType()==typeid(PlantFood)){
            if(zoo.warehouse.takePlants(zoo.cages[i]->getAmountOfFood()))
                continue;
            areFed = false;
        }
    }
    if(areFed){
        SetConsoleTextAttribute(hConsole, 10);
        cout << "The animals were fed successfully." << endl;
        SetConsoleTextAttribute(hConsole, 6);
    }else{
        SetConsoleTextAttribute(hConsole, 4);
        cerr << "The animals were not fed. There is not enough food in the warehouse." << endl;
        SetConsoleTextAttribute(hConsole, 6);
    }
}

void CommandDispatcher::showAnimalInfo(Zoo& zoo){
    if(zoo.cur==0){
        SetConsoleTextAttribute(hConsole, 4);
        cerr << "There are no animals in the zoo." << endl;
        SetConsoleTextAttribute(hConsole, 6);
        return;
    }
    bool areAllCagesEmpty = true;
    for(int i=0; i<zoo.cur; i++){
        if(!zoo.cages[i]->getIsEmpty())
        areAllCagesEmpty = false;
    }
    if(areAllCagesEmpty){
        SetConsoleTextAttribute(hConsole, 4);
        cerr << "There are no animals in the zoo." << endl;
        SetConsoleTextAttribute(hConsole, 6);
        return;
    }
    printAnimalsFromTheZoo(zoo);
    int option = Validator::getInstance()->validateIntInBetween(1, zoo.cur);
    if(zoo.cages[option-1]->getIsEmpty()){
        SetConsoleTextAttribute(hConsole, 4);
        cerr << "This cage is empty." << endl;
        SetConsoleTextAttribute(hConsole, 6);
        return;
    }
    zoo.cages[option-1]->getAnimal()->showInfo();

}

void CommandDispatcher::showCageInfo(Zoo& zoo){
    if(zoo.cur==0){
        SetConsoleTextAttribute(hConsole, 4);
        cerr << "There are no cages in the zoo." << endl;
        SetConsoleTextAttribute(hConsole, 6);
        return;
    }
    printCagesFromTheZoo(zoo);
    int option = Validator::getInstance()->validateIntInBetween(1, zoo.cur);
    zoo.cages[option-1]->showInfo();

}
