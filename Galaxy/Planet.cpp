#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Planet.h"

char* Planet::get_name()const {
    return name;
}
void Planet::set_name(const char* _name) {
    if (name != nullptr)
        delete[]name;
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}
char* Planet::get_planetSystem()const {
    return planetSystem;
}
void Planet::set_planetSystem(const char* _planetSystem) {
    if (planetSystem != nullptr)
        delete[]planetSystem;
    planetSystem = new char[strlen(_planetSystem) + 1];
    strcpy(planetSystem, _planetSystem);
}
char* Planet:: get_republic() const {
    return republic;
}
void Planet::set_republic(const char* _republic) {
    if (republic != nullptr)
        delete[]republic;
    republic = new char[strlen(_republic) + 1];
    strcpy(republic, _republic);
}
typeOfPlanet Planet::get_typeofplanet()const {
    return typeofplanet;
}
 void Planet::set_typeofplanet(const typeOfPlanet _typeofplanet) {
    typeofplanet = _typeofplanet;
}



Planet::Planet() {
    name = nullptr;
    planetSystem = nullptr;
    republic = nullptr;
    set_typeofplanet(typeOfPlanet::Chthonian_planet);
}

Planet::Planet(const char* _name, const char* _planetSystem, const  char* _republic, const typeOfPlanet _typeofplanet) {
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);

    this->planetSystem = new char[strlen(_planetSystem) + 1];
    strcpy(this->planetSystem, _planetSystem);

    this->republic = new char[strlen(_republic) + 1];
    strcpy(this->republic, _republic);

    this->typeofplanet = _typeofplanet;
}

Planet::Planet(const Planet& other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->planetSystem = new char[strlen(other.planetSystem) + 1];
    strcpy(this->planetSystem, other.planetSystem);

    this->republic = new char[strlen(other.republic) + 1];
    strcpy(this->republic, other.republic);

    this->typeofplanet = other.typeofplanet;
}

Planet:: ~Planet() {
    delete[] name;
    name = nullptr;
    delete[] planetSystem;
    planetSystem = nullptr;
    delete[] republic;
    republic = nullptr;
}
bool Planet:: operator==(const Planet& other) const {
    return !strcmp(this->name, other.name) && !strcmp(this->planetSystem, other.planetSystem) && !strcmp(this->republic, other.republic) && typeofplanet==other.typeofplanet;
}
bool Planet:: operator!=(const Planet& other) const {
    return !(*this == other);
}
Planet& Planet:: operator=(const Planet& other) {
    if (this != &other) {
        delete[] name;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        delete[] planetSystem;
        this->planetSystem = new char[strlen(other.planetSystem) + 1];
        strcpy(this->planetSystem, other.planetSystem);
        delete[] republic;
        this->republic = new char[strlen(other.republic) + 1];
        strcpy(this->republic, other.republic);
        typeofplanet = other.typeofplanet;
    }
    return *this;
}
    std::ostream& operator<<(std::ostream& os, const Planet& planet_out) {
    os << planet_out.get_name() << std::endl;
    os << planet_out.get_planetSystem() << std::endl;
    os << planet_out.get_republic() << std::endl;
    /*switch (planet_out.typeofplanet)
    {
    case typeOfPlanet::Chthonian_planet: os << "Chthonian_planet" << std::endl;   break;
    case typeOfPlanet::Carbon_planet: os << "Carbon_planet" << std::endl;   break;
    case typeOfPlanet::Coreless_planet: os << "Coreless_planet" << std::endl;   break;
    case typeOfPlanet::Desert: os << "Desert" << std::endl;   break;
    case typeOfPlanet::Gas_dwarf: os << "Gas_dwarf" << std::endl;   break;
    case typeOfPlanet::Helium_planet: os << "Helium_planet" << std::endl;   break;
    case typeOfPlanet::Ice_giant: os << "Ice_giant" << std::endl;   break;
    case typeOfPlanet::Ice_planet: os << "Ice_planet" << std::endl;   break;
    case typeOfPlanet::Iron_planet: os << "Iron_planet" << std::endl;   break;
    case typeOfPlanet::Lava_planet: os << "Lava_planet" << std::endl;   break;
    case typeOfPlanet::Ocean_planet: os << "Ocean_planet" << std::endl;   break;
    case typeOfPlanet::Protoplanet: os << "Protoplanet" << std::endl;   break;
    case typeOfPlanet::Puffy_planet: os << "Puffy_planet" << std::endl;   break;
    case typeOfPlanet::Silicate_planet: os << "Silicate_planet" << std::endl;   break;
    case typeOfPlanet::Terrestrial_planet: os << "Terrestrial_planet" << std::endl;   break;
    }*/
    return os;
}
    void Planet::Read_file_P(Planet& planet_fromfile) {
        unsigned int counter = 0;
        std::string text;
        std::ifstream myfile("Planet.txt");
        while (getline(myfile, text) && text != "") {
            char* buff = new char[text.size() + 1];
            strcpy(buff, text.c_str());
            switch (counter) {
            case 0: planet_fromfile.set_name(buff); counter++; break;
            case 1: planet_fromfile.set_planetSystem(buff); counter++; break;
            case 2: planet_fromfile.set_republic(buff); counter = 0; break;
            }
        }
        myfile.close();

    }
    void Planet::Write_file(const Planet& P) {
        std::ofstream myfile;
        myfile.open("Planets.txt", std::ios::out);
        myfile << P.get_name() << std::endl;
        myfile << P.get_planetSystem() << std::endl;
        myfile << P.get_republic() << std::endl;
        myfile.close();
    }
