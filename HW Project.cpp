#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include<cstring>

class Planet {
private:
    char* name;
    char* planetSystem;
    char* republic;

public:
    Planet();
    Planet(const char* _name, const char* _planetSystem, const char* _republic);
    Planet(const Planet& other);
    ~Planet();
    Planet& operator=(const Planet& other);
    bool operator==(const Planet& other) const;
    bool operator!=(const Planet& other) const;
    void print_planet()const;

    char* get_name()const {
        return name;
    }
    void set_name(const char* _name) {
        if (name != nullptr)
            delete[]name;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }
    char* get_planetSystem()const {
        return planetSystem;
    }
    void set_planetSystem(const char* _planetSystem) {
        if (planetSystem != nullptr)
            delete[]planetSystem;
        planetSystem = new char[strlen(_planetSystem) + 1];
        strcpy(planetSystem, _planetSystem);
    }
    char* get_republic() const {
        return republic;
    }
    void set_republic(const char* _republic) {
        if (republic != nullptr)
            delete[]republic;
        republic = new char[strlen(_republic) + 1];
        strcpy(republic, _republic);
    }
};

Planet::Planet() {
    name = nullptr;
    planetSystem = nullptr;
    republic = nullptr;
}

Planet::Planet(const char* _name, const char* _planetSystem, const  char* _republic) {
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);

    this->planetSystem = new char[strlen(_planetSystem) + 1];
    strcpy(this->planetSystem, _planetSystem);

    this->republic = new char[strlen(_republic) + 1];
    strcpy(this->republic, _republic);
}

Planet::Planet(const Planet& other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->planetSystem = new char[strlen(other.planetSystem) + 1];
    strcpy(this->planetSystem, other.planetSystem);

    this->republic = new char[strlen(other.republic) + 1];
    strcpy(this->republic, other.republic);
}

void Planet::print_planet()const {
    std::cout << "Name of the Planet: " << name << std::endl;
    std::cout << "Planet system: " << planetSystem << std::endl;
    std::cout << "Republic: " << republic << std::endl;
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
    return strcmp(this->name, other.name) && (this->planetSystem == other.planetSystem) && (this->republic == other.republic);
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
    }
    return *this;
}



enum class rankOfStormtrooper { Cadet, Private, Lance_Corporal, Corporal, Sergeant, Staff_Sergeant, Master_Sergeant };
class Stormtrooper {
private:
    char* id;
    rankOfStormtrooper rank;
    char* type;
    Planet planet;

public:
    Stormtrooper();
    Stormtrooper(const char* _id, const rankOfStormtrooper _rank, const char* _type, const Planet _planet);
    Stormtrooper(const Stormtrooper& other);
    ~Stormtrooper();
    bool operator==(const Stormtrooper& other) const;
    bool operator!=(const Stormtrooper& other) const;
    Stormtrooper& operator=(const Stormtrooper& other);
    void print_stormtrooper()const;

    char* get_id()const {
        return id;
    }
    void set_id(const char* _id) {
        if (id != nullptr)
            delete[]id;
        id = new char[strlen(_id) + 1];
        strcpy(id, _id);
    }
    rankOfStormtrooper get_rank()const {
        return rank;
    }
    void set_rank(const rankOfStormtrooper _rank) {
        rank = _rank;
    }
    char* get_type()const {
        return type;
    }
    void set_type(const char* _type) {
        if (type != nullptr)
            delete[]type;
        type = new char[strlen(_type) + 1];
        strcpy(type, _type);
    }
    Planet get_planet()const {
        return planet;
    }
    void set_planet(const Planet _planet) {
        planet = _planet;
    }
};
Stormtrooper::Stormtrooper() {
    id = nullptr;
    type = nullptr;
    set_rank(rankOfStormtrooper::Cadet);
}
Stormtrooper::Stormtrooper(const char* _id, const rankOfStormtrooper _rank, const char* _type, const Planet _planet) {
    this->id = new char[strlen(_id) + 1];
    strcpy(this->id, _id);
    this->type = new char[strlen(_type) + 1];
    strcpy(this->type, _type);
    this->rank = _rank;
    this->planet = _planet;
}
Stormtrooper::Stormtrooper(const Stormtrooper& other) {
    this->id = new char[strlen(other.id) + 1];
    strcpy(this->id, other.id);

    this->type = new char[strlen(other.type) + 1];
    strcpy(this->type, other.type);

    this->rank = other.rank;
    this->planet = other.planet;
}
Stormtrooper::~Stormtrooper() {
    delete[]id;
    id = nullptr;
    delete[]type;
    type = nullptr;
}
void Stormtrooper::print_stormtrooper()const {
    std::cout << "Stormtrooper's id: " << id << std::endl;
    std::cout << "Rank: ";

    switch (rank)
    {
    case rankOfStormtrooper::Cadet: std::cout << "Cadet" << std::endl;   break;
    case rankOfStormtrooper::Lance_Corporal: std::cout << "Lance_Corporal" << std::endl;   break;
    case rankOfStormtrooper::Corporal: std::cout << "Corporal" << std::endl;   break;
    case rankOfStormtrooper::Sergeant: std::cout << "Sergeant" << std::endl;   break;
    case rankOfStormtrooper::Staff_Sergeant: std::cout << "Staff_Sergeant" << std::endl;   break;
    case rankOfStormtrooper::Master_Sergeant: std::cout << "Master_Sergeant" << std::endl;   break;
    }
    std::cout << "Type: " << type << std::endl;
    planet.print_planet();
}

bool Stormtrooper:: operator==(const Stormtrooper& other) const {
    return strcmp(this->id, other.id) && (this->planet == other.planet) && (this->rank == other.rank) && (this->type == other.type);
}
bool Stormtrooper:: operator!=(const Stormtrooper& other) const {
    return !(*this == other);
}
Stormtrooper& Stormtrooper::operator=(const Stormtrooper& other) {
    if (this != &other) {
        delete[] id;
        this->id = new char[strlen(other.id) + 1];
        strcpy(this->id, other.id);
        delete[] type;
        this->type = new char[strlen(other.type) + 1];
        strcpy(this->type, other.type);
        this->planet = other.planet;
        this->rank = other.rank;
    }
    return *this;
}



enum class rankOfJedi { Youngling, Padawan, Service, Corps, Knight, Consular, Guardian, Sentinel, Master, Council_Member, Master_of_the_Order };
class Jedi {
private:
    char* name;
    rankOfJedi rank;
    double midi_chlorian;
    Planet planet;
    char* spicies;
    char* militaryRank;
public:
    Jedi();
    Jedi(const char* _name, const rankOfJedi _rank, const double _midi_chlorian, const Planet _planet, const char* _spicies, const char* _militaryRank);
    Jedi(Jedi& other);
    ~Jedi();
    bool operator==(const Jedi& other) const;
    bool operator!=(const Jedi& other) const;
    Jedi& operator=(const Jedi& other);
    void print_Jedi();

    char* get_name()const {
        return name;
    }
    void set_name(const char* _name) {
        if (name != nullptr)
            delete[]name;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }
    rankOfJedi get_rank()const {
        return rank;
    }
    void set_rank(const rankOfJedi _rank) {
        rank = _rank;
    }

    double get_midi_chlorian()const {
        return midi_chlorian;
    }
    void set_midi_chlorian(const double _midi_chlorian) {
        midi_chlorian = _midi_chlorian;
    }

    Planet get_planet()const {
        return planet;
    }
    void set_planet(const Planet _planet) {
        planet = _planet;
    }
    char* get_spicies()const {
        return spicies;
    }
    void set_spicies(const char* _spicies) {
        if (spicies != nullptr)
            delete[]spicies;
        spicies = new char[strlen(_spicies) + 1];
        strcpy(spicies, _spicies);
    }
    char* get_militaryRank()const {
        return militaryRank;
    }
    void set_militaryRank(const char* _militaryRank) {
        if (name != nullptr)
            delete[]militaryRank;
        militaryRank = new char[strlen(_militaryRank) + 1];
        strcpy(militaryRank, _militaryRank);
    }
};
Jedi::Jedi() {
    name = nullptr;
    spicies = nullptr;
    militaryRank = nullptr;
    midi_chlorian = 0;
    set_rank(rankOfJedi::Youngling);
}
Jedi::Jedi(const char* _name, const rankOfJedi _rank, const double _midi_chlorian, const Planet _planet, const char* _spicies, const char* _militaryRank) {
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);

    this->spicies = new char[strlen(_spicies) + 1];
    strcpy(this->spicies, _spicies);

    this->militaryRank = new char[strlen(_militaryRank) + 1];
    strcpy(this->militaryRank, _militaryRank);

    this->rank = _rank;
    this->midi_chlorian = _midi_chlorian;
    this->planet = _planet;

}
Jedi::Jedi(Jedi& other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->spicies = new char[strlen(other.spicies) + 1];
    strcpy(this->spicies, other.spicies);

    this->militaryRank = new char[strlen(other.militaryRank) + 1];
    strcpy(this->militaryRank, other.militaryRank);

    this->midi_chlorian = other.midi_chlorian;
    this->rank = other.rank;
    this->planet = other.planet;
}
Jedi::~Jedi() {
    delete[]name;
    name = nullptr;
    delete[]spicies;
    spicies = nullptr;
    delete[]militaryRank;
    militaryRank = nullptr;
}
void Jedi::print_Jedi() {
    std::cout << "Jedi's name: " << name << std::endl;
    std::cout << "Rank: ";
    switch (rank)
    {
    case rankOfJedi::Youngling: std::cout << "Youngling" << std::endl;   break;
    case rankOfJedi::Padawan: std::cout << "Padawan" << std::endl;   break;
    case rankOfJedi::Service: std::cout << "Service" << std::endl;   break;
    case rankOfJedi::Corps: std::cout << "Corps" << std::endl;   break;
    case rankOfJedi::Knight: std::cout << "Knight" << std::endl;   break;
    case rankOfJedi::Consular: std::cout << "Consular" << std::endl;   break;
    case rankOfJedi::Guardian: std::cout << "Guardian" << std::endl;   break;
    case rankOfJedi::Sentinel: std::cout << "Sentinel" << std::endl;   break;
    case rankOfJedi::Council_Member: std::cout << "Council_Member" << std::endl;   break;
    case rankOfJedi::Master_of_the_Order: std::cout << "Master_of_the_Order" << std::endl;   break;
    }
    std::cout << "Midi-chlorian: " << midi_chlorian << std::endl;
    planet.print_planet();
    std::cout << "Spicies: " << spicies << std::endl;
    std::cout << "MilitaryRank: " << militaryRank << std::endl << std::endl;
}

bool Jedi:: operator==(const Jedi& other) const {
    return strcmp(this->name, other.name) && (this->planet == other.planet) && (this->rank == other.rank) && (this->spicies == other.spicies) && (this->militaryRank == other.militaryRank) && (this->midi_chlorian == other.midi_chlorian);
}
bool Jedi:: operator!=(const Jedi& other) const {
    return !(*this == other);
}
Jedi& Jedi::operator=(const Jedi& other) {
    if (this != &other) {
        delete[] name;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        delete[] spicies;
        this->spicies = new char[strlen(other.spicies) + 1];
        strcpy(this->spicies, other.spicies);
        delete[] militaryRank;
        this->militaryRank = new char[strlen(other.militaryRank) + 1];
        strcpy(this->militaryRank, other.militaryRank);
        planet = other.planet;
        rank = other.rank;
        midi_chlorian = other.midi_chlorian;
    }
    return *this;
}
int main() {

    Jedi j;
    Planet planetOfYoda;
    planetOfYoda.set_name("Dagobah");
    planetOfYoda.set_planetSystem(" Dagobah system");
    planetOfYoda.set_republic("The Galactic");
    j.set_name("Yoda");
    j.set_midi_chlorian(18000);
    j.set_militaryRank("Jedi General");
    j.set_spicies("Yoda's species");
    j.set_planet(planetOfYoda);
    j.set_rank(rankOfJedi::Master_of_the_Order);
    j.print_Jedi();

    Stormtrooper s;
    Planet planetOfStormtrooper;
    planetOfStormtrooper.set_name("The Empire");
    planetOfStormtrooper.set_planetSystem(" Empire");
    planetOfStormtrooper.set_republic("The Galactic");
    s.set_id("TK-421");
    s.set_planet(planetOfStormtrooper);
    s.set_rank(rankOfStormtrooper::Corporal);
    s.set_type("Death trooper");
    s.print_stormtrooper();

    return 0;
}
