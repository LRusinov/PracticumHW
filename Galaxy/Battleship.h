#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <typeinfo>
#include <iostream>
#include"Jedi.h"
enum class Category_ammunition { Heavy, Medium,Light };
template<class C>
class BattleShip {
private:
    double speed;
    unsigned int cannons;
    bool hyperjump;
    unsigned int size;
    C pilot;
    unsigned int amount_of_fuel;
    Category_ammunition ammo;
    unsigned int hull;
public:
    
    BattleShip() {
        speed = 0.0;
        cannons = 0;
        size = 0;
        hyperjump = false;
        amount_of_fuel = 100;
        ammo = Category_ammunition::Light;
        hull = 100;
    }
    BattleShip(const double _speed, const unsigned int _cannons, const unsigned int _size, const bool _hyperjump, C _pilot,const unsigned int _amount_of_fuel,const Category_ammunition _ammo,const unsigned int _hull) {
        this->speed = _speed;
        this->cannons = _cannons;
        this->size = _size;
        this->hyperjump = _hyperjump;
        this->pilot = _pilot;
        this->amount_of_fuel = _amount_of_fuel;
        this->ammo = _ammo;
        this->hull = _hull;
    }
    BattleShip(BattleShip& other) {
        this->speed = other.speed;
        this->cannons = other.cannons;
        this->size = other.size;
        this->hyperjump = other.hyperjump;
        this->pilot = other.pilot;
        this->amount_of_fuel = other.amount_of_fuel;
        this->ammo = other.ammo;
        this->hull = other.hull;
    }
    unsigned int get_hull()const {
        return hull;
    }
    void set_hull(const unsigned int _hull) {
        hull = _hull;
    }
    Category_ammunition get_ammo()const {
        return ammo;
    }
    void set_ammo(const Category_ammunition _ammo) {
        ammo = _ammo;
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
    
    unsigned int get_amount_of_fuel()const {
        return amount_of_fuel;
    }
    void set_amount_of_fuel(const unsigned int _amount_of_fuel){
        amount_of_fuel = _amount_of_fuel;
    }
    bool get_hyperjump()const {
        return hyperjump;
    }
    
    void set_hyperjump(const bool _hyperjump) {
        hyperjump = _hyperjump;
    }
    
    char* get_pilot()const {
        if (typeid(C) == typeid(Jedi)) {
            return pilot.get_name();
        }

    }
    
    void set_pilot(const Jedi _pilot) {
        const type_info& t1 = typeid(_pilot);
        const type_info& t2= typeid(Jedi);
        if (t1 != t2 ) {
            std::cout << "Invalid";
        }
        else {
            this->pilot = _pilot;
        }
    }
    
    unsigned int get_size()const {
        return size;
    }
    void set_size(const unsigned int _size) {
        size = _size;
    }

    bool operator==(const BattleShip& other) const {
        return speed == other.speed && cannons == other.cannons && size == other.size && hyperjump == other.hyperjump && pilot == other.pilot && amount_of_fuel==other.amount_of_fuel && hull==other.hull && ammo==other.ammo ;
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
            this->amount_of_fuel = other.amount_of_fuel;
            this->hull = other.hull;
            this->ammo = other.ammo;
        }
    }
    void print_BattleShip() {
        std::cout << "Speed: " << speed << std::endl;
        std::cout << "Cannons: " << cannons << std::endl;
        std::cout << "Size: " << size << std::endl;
        std::cout << "Hyperjump: " << hyperjump << std::endl;
        std::cout << "Hull: " << hull << "%" << std::endl;
        std::cout << "Fuel: " << amount_of_fuel << "%" << std::endl;
        std::cout << "Ammo: ";
        switch (ammo)
        {
        case Category_ammunition::Heavy: std::cout << "Heavy" << std::endl;   break;
        case Category_ammunition::Light: std::cout << "Light" << std::endl;   break;
        case Category_ammunition::Medium: std::cout << "Medium" << std::endl;   break;
        }
        std::cout << "Pilot: " << pilot << std::endl;

    }
    void Write_file( BattleShip& B) {
        std::ofstream myfile;
        myfile.open("Battleship.txt", std::ios::out);
        myfile << B.get_speed() << std::endl;
        myfile << B.get_cannons() << std::endl;
        myfile << B.get_size() << std::endl;
        myfile << B.get_hyperjump() << std::endl;
        myfile << B.get_hull() << std::endl;
        myfile << B.get_amount_of_fuel() << std::endl;
        myfile << B.get_ammo() << std::endl;
        myfile << B.pilot.Read_file_J << std::endl;//??????????
        myfile.close();
    }
 inline   void Read_file_J(BattleShip& battleship_fromfile) {
        unsigned int counter = 0;
        std::string text;
        std::ifstream  myfile("Battleship.txt");
        Jedi jed;
        while (getline(myfile, text) && text != "") {
            char* buff = new char[text.size() + 1];
            strcpy(buff, text.c_str());
            switch (counter) {
            case 0: battleship_fromfile.set_speed(jed.char_to_double(buff)); counter++; break;
            case 1: battleship_fromfile.set_cannons(char_to_int(buff)); counter++; break;
            case 2: battleship_fromfile.set_size(char_to_int(buff)); counter++; break;
            case 3: battleship_fromfile.set_hyperjump(buff); counter++; break;
            case 4: battleship_fromfile.set_hull(char_to_int(buff)); counter++; break;
            case 5: battleship_fromfile.set_amount_of_fuel(char_to_int(buff)); counter++; break;
            case 6: battleship_fromfile.set_ammo(char_to_enum(buff)); counter++; break;
            }

        }

        myfile.close();

    }
    friend std::ostream& operator<<(std::ostream& os,const  BattleShip& battleShip_out) {
        os << "Speed: " << battleShip_out.get_speed() << std::endl;
        os << "Cannons: " << battleShip_out.get_cannons() << std::endl;
        os << "Size: " << battleShip_out.get_size() << std::endl;
        os << "Hyperjump: " << battleShip_out.get_hyperjump() << std::endl;
        os << "Hull: " << battleShip_out.get_hull() << "%" << std::endl;
        os << "Fuel: " << battleShip_out.get_amount_of_fuel() << "%" << std::endl;
        os << "Ammo: ";
        switch (battleShip_out.get_ammo())
        {
        case Category_ammunition::Heavy: os << "Heavy" << std::endl;   break;
        case Category_ammunition::Light: os << "Light" << std::endl;   break;
        case Category_ammunition::Medium: os << "Medium" << std::endl;   break;
        }
        return os;
    }
    int char_to_int(const char* str) {
        unsigned int result = 0;
        unsigned int size = strlen(str);
        unsigned int s = size;
        for (unsigned int i = 0; i < size; i++) {
            s--;
            result += (int(str[i]) - 48) * pow(10, s);
            
        }
        return result;
    }
    Category_ammunition char_to_enum(const char* str, Category_ammunition ammo_out= Category_ammunition::Light) {

        if (str == "Medium") ammo_out = Category_ammunition::Medium;
        if (str == "Heavy") ammo_out = Category_ammunition::Heavy;
        if (str == "Light") ammo_out = Category_ammunition::Light;
        return ammo_out;
    }
    std::vector <BattleShip<Jedi>> fuel_refill(const std::vector <BattleShip<Jedi>> battlesips, const size_t index) {
            if (battlesips[index].get_amount_of_fuel() != 100) {
                battlesips[index].set_amount_of_fuel(100);
            }
    }
    std::vector <BattleShip<Jedi>> ammo_change(const std::vector <BattleShip<Jedi>> battlesips, const size_t index,const Category_ammunition _ammo) {
        if (battlesips[index].get_ammo() == Category_ammunition::Heavy) {
            if (_ammo == Category_ammunition::Medium) {
                battlesips[index].set_speed(battlesips[index].get_speed() * 2);
            }
            else if (_ammo == Category_ammunition::Light) {
                battlesips[index].set_speed(battlesips[index].get_speed() * 4);
            }
        }
        if (battlesips[index].get_ammo() == Category_ammunition::Medium) {
            if (_ammo == Category_ammunition::Heavy) {
                battlesips[index].set_speed(battlesips[index].get_speed() / 2);
            }
            else if (_ammo == Category_ammunition::Light) {
                battlesips[index].set_speed(battlesips[index].get_speed() * 2);
            }
        }
        if (battlesips[index].get_ammo() == Category_ammunition::Light) {
            if (_ammo == Category_ammunition::Medium) {
                battlesips[index].set_speed(battlesips[index].get_speed() / 2);
            }
            else if (_ammo == Category_ammunition::Heavy) {
                battlesips[index].set_speed(battlesips[index].get_speed() / 4);
            }
        }
        battlesips[index].set_ammo(_ammo);
    }
    std::vector <BattleShip<Jedi>> remove_broken(const std::vector <BattleShip<Jedi>> battlesips) {
        for (size_t i= 0; i < battlesips.size(); i++) {
            if (battlesips[i].get_hull() < 50) {
                battlesips.clear(battlesips.begin() + i);
            }
        }
        return battleships;
    }
};
