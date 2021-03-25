#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include<cstring>
#include<fstream>
#include<string>
enum class typeOfPlanet{Chthonian_planet, Carbon_planet, Coreless_planet, Desert, Gas_dwarf, Helium_planet, Ice_giant, Ice_planet, Iron_planet, Lava_planet, Ocean_planet, Protoplanet, Puffy_planet, Silicate_planet, Terrestrial_planet};
class Planet {
private:
    char* name;
    char* planetSystem;
    char* republic;
    typeOfPlanet typeofplanet;

public:
    Planet();
    Planet(const char* _name, const char* _planetSystem, const char* _republic, const typeOfPlanet _type);
    Planet(const Planet& other);
    ~Planet();
    char* get_name()const;
    void set_name(const char* _name);
    char* get_planetSystem()const;
    void set_planetSystem(const char* _planetSystem);
    char* get_republic() const;
    void set_republic(const char* _republic);
    void set_typeofplanet(const typeOfPlanet _typeofplanet);
    typeOfPlanet get_typeofplanet()const;

    Planet& operator=(const Planet& other);
    bool operator==(const Planet& other) const;
    bool operator!=(const Planet& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Planet& planet_out);
    template<typename T1, class T2>
    void print_planet(const T1 n, const T1 planetSys, const T1 repub, const T2 type)const {
        Planet pl;
        pl.set_name(n);
        pl.set_planetSystem(planetSys);
        pl.set_republic(repub);
        pl.set_typeofplanet(type);
        std::cout << pl;
    }
    void Write_file(const Planet& P);
    void Read_file_P(Planet& planet_fromfile);
};
