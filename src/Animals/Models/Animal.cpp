#include "Animals/Models/Animal.h"
#include <algorithm>
#include <windows.h>

Animal::Animal(const char* _species, Food* _food, const double _amountOfFood)
{
    species = new char[strlen(_species) +1];
    strcpy(species, _species);
    food = _food;
    amountOfFood = _amountOfFood;
}

Animal::~Animal()
{
    delete[] species;
    delete[] food;
}

void Animal::copyAnimal(const Animal& other){
    species = new char[strlen(other.species) +1];
    strcpy(species, other.species);
    food = other.food;
    amountOfFood = other.amountOfFood;
}

Animal::Animal(const Animal& other){
    copyAnimal(other);
}

Animal& Animal::operator=(const Animal& other){
    if(this!=&other){
        delete[] species;
        delete[] food;
        copyAnimal(other);
    }
    return *this;
}

char* Animal::parseTypeName(){
    const char* type = typeid(*this).name();
    char* result = new char[32];
    int counter = 0;
    for(int i=0; i<strlen(type); i++){
        char ch = type[i];
        if(((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A') || (ch == ' '))){
            result[counter] = ch;
            counter++;
        }
    }
    result[counter] = '\0';
    return result;
}

char* Animal::parseFoodTypeName(){
    const char* type = typeid(*food).name();
    char* result = new char[32];
    int counter = 0;
    for(int i=0; i<strlen(type); i++){
        char ch = type[i];
        if(((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A') || (ch == ' '))){
            result[counter] = ch;
            counter++;
        }
    }
    result[counter] = '\0';
    return result;
}

void Animal::showInfo(){
    char* type = parseTypeName();
    char* food = parseFoodTypeName();
    SetConsoleTextAttribute(hConsole, 176);
    std::cout << "Showing information for: " << species << "." << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Diet: " << amountOfFood << " kilos of " << food << "." << std::endl;
    SetConsoleTextAttribute(hConsole, 6);
    char picturePath[100] = "D:\\Uni\\Zoo\\assets\\pictures\\animals\\";
    strcat(picturePath, species);
    strcat(picturePath, ".jpg");
    char soundPath[100] = "D:\\Uni\\Zoo\\assets\\sounds\\";
    strcat(soundPath, species);
    strcat(soundPath, ".wav");

    // read an image
    ShellExecute(NULL,
             "open",
             picturePath,
             NULL,
             NULL,
             SW_SHOW);
    ShellExecute(NULL,
             "open",
             soundPath,
             NULL,
             NULL,
             SW_HIDE);
    delete food;
    delete type;
}
