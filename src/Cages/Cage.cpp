#include "Cage.h"

Cage::Cage(const int _humidity, const int _vegetation, const char* _terrainType, const double _latitude)
{
    isEmpty = true;
    humidity = _humidity;
    vegetation = _vegetation;
    terrainType = new char[strlen(_terrainType) + 1];
    strcpy(terrainType, _terrainType);
    latitude = _latitude;
}

void Cage::copyCage(const Cage& other){
    isEmpty = other.isEmpty;
    humidity = other.humidity;
    vegetation = other.vegetation;
    terrainType = new char[strlen(other.terrainType) + 1];
    strcpy(terrainType, other.terrainType);
    latitude = other.latitude;
}

Cage::Cage(const Cage& other){
    copyCage(other);
}

Cage& Cage::operator=(const Cage& other){
    if(this != &other){
        delete[] animal;
        delete[] terrainType;
        copyCage(other);
    }
    return *this;
}

Cage::~Cage()
{
    delete[] animal;
    delete[] terrainType;
}

char* Cage::parseTypeName(){
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

void Cage::showInfo(){
    char* type = parseTypeName();
    SetConsoleTextAttribute(hConsole, 176);
    std::cout << "Showing information for: " << type << "." << std::endl;
    std::cout << (isEmpty ? "This cage is empty." : "This cage is not empty.") << std::endl;
    std::cout << "Terrain type: " << terrainType << std::endl;
    if(strcmp(type, "Aquarium")!=0 && strcmp(type, "Terrarium")!=0)
    std::cout << "Latitude: " << latitude << " N." << std::endl;
    std::cout << "Humidity: " << humidity << "%." << std::endl;
    std::cout << "Vegetation: " << vegetation << "%." << std::endl;
    SetConsoleTextAttribute(hConsole, 6);
    char picturePath[100] = "D:\\Uni\\Zoo\\assets\\pictures\\cages\\";
    strcat(picturePath, type);
    strcat(picturePath, ".jpg");

    // read an image
    ShellExecute(NULL,
             "open",
             picturePath,
             NULL,
             NULL,
             SW_SHOW);

    delete type;
}

