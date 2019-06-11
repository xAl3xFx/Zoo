#include "Validator.h"

Validator* Validator::instance = 0;

Validator::Validator(){}

Validator* Validator::getInstance(){
    if (instance == 0){
        instance = new Validator();
    }
    return instance;
}

int Validator::validateIntInBetween(const int starts, const int ends) const{
    int result;
    cin >> result;
    while(!cin || (result>ends || result<starts)){
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Please enter number between " << starts << " and " << ends << " ." << endl;
        SetConsoleTextAttribute(hConsole, 6);
        cin.clear();
        cin.ignore();
        cin >> result;
    }
    return result;
}
