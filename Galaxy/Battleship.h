#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <typeinfo>
#include <iostream>
#include"Jedi.h"


template<class C>
class BattleShip {
private:
    double speed;
    unsigned int cannons;
    bool hyperjump;
    unsigned int size;
    C pilot;
    
public:
    
    BattleShip() {
        speed = 0.0;
        cannons = 0;
        size = 0;
        hyperjump = false;
    }
    BattleShip(const double _speed, const unsigned int _cannons, const unsigned int _size, const bool _hyperjump, C _pilot) {
        this->speed = _speed;
        this->cannons = _cannons;
        this->size = _size;
        this->hyperjump = _hyperjump;
        this->pilot = _pilot;
    }
    BattleShip(BattleShip& other) {
        this->speed = other.speed;
        this->cannons = other.cannons;
        this->size = other.size;
        this->hyperjump = other.hyperjump;
        this->pilot = other.pilot;
    }
    
    double get_speed()const {
        return speed;
    }
    
    void set_speed(const double _speed) {
        speed = _speed;
    }
    
    unsigned int get_cannons()const {
        return cannons;
    }
    
    void set_cannons(const unsigned int _cannons) {
        cannons = _cannons;
    }
    
    bool get_hyperjump()const {
        return hyperjump;
    }
    
    void set_hyperjump(const bool _hyperjump) {
        hyperjump = _hyperjump;
    }
    
    C get_pilot() {
        return pilot;
    }
    
    void set_pilot(const Jedi _pilot) {
        const type_info& t1 = typeid(_pilot);
        const type_info& t2= typeid(Jedi);
        if (t1 != t2 ) {
            std::cout << "Invalid";
        }
    }
    
    unsigned int get_size()const {
        return size;
    }
    void set_size(const unsigned int _size) {
        size = _size;
    }

    bool operator==(const BattleShip& other) const {
        return speed == other.speed && cannons == other.cannons && size == other.size && hyperjump == other.hyperjump && pilot == other.pilot;
    }
    bool operator!=(const BattleShip& other) const {
        return !(*this == other);
    }
    BattleShip& operator=(const BattleShip& other) {
        if (*this != other) {
            this->speed = other.speed;
            this->cannons = other.cannons;
            this->size = other.size;
            this->hyperjump = other.hyperjump;
            this->pilot = other.pilot;
        }
    }
    void print_BattleShip() {
        std::cout << "Speed: " << speed << std::endl;
        std::cout << "Cannons: " << cannons << std::endl;
        std::cout << "Size: " << size << std::endl;
        std::cout << "Hyperjump: " << hyperjump << std::endl;
        std::cout << "Pilot: " << pilot << std::endl;
    }
    void Write_file( BattleShip& B) {
        std::ofstream myfile;
        myfile.open("Battleship.txt", std::ios::out);
        myfile << B.get_speed() << std::endl;
        myfile << B.get_cannons() << std::endl;
        myfile << B.get_size() << std::endl;
        myfile << B.get_hyperjump() << std::endl;
        myfile << B.get_pilot() << std::endl;
        myfile.close();
    }
    void Read_file_J(BattleShip& battleship_fromfile) {
        unsigned int counter = 0;
        std::string text;
        std::ifstream  myfile("Battleship.txt");
        while (getline(myfile, text) && text != "") {
            char* buff = new char[text.size() + 1];
            strcpy(buff, text.c_str());
            switch (counter) {
            case 0: battleship_fromfile.set_speed(buff); counter++; break;
            case 1: battleship_fromfile.set_cannons(buff); counter++; break;
            case 2: battleship_fromfile.set_size(buff); counter++; break;
            case 3: battleship_fromfile.set_hyperjump(buff); counter++; break;
            case 4: battleship_fromfile.set_pilot(buff); counter++; break;
            }
        }

        myfile.close();

    }
    friend std::ostream& operator<<(std::ostream& os, const BattleShip& battleShip_out);
    void pilot_validation(const C& _pilot);
};