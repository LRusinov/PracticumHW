#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include"Stormtrooper.h"
enum class rankOfJedi { Youngling, Padawan, Service, Corps, Knight, Consular, Guardian, Sentinel, Master, Council_Member, Grand_Master };
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
    char* get_name()const;
    void set_name(const char* _name);
    rankOfJedi get_rank()const;
    void set_rank(const rankOfJedi _rank);
    double get_midi_chlorian()const;
    void set_midi_chlorian(const double _midi_chlorian);
    Planet get_planet()const;
    void set_planet(const Planet _planet);
    char* get_spicies()const;
    void set_spicies(const char* _spicies);
    char* get_militaryRank()const;
    void set_militaryRank(const char* _militaryRank);

    bool operator==(const Jedi& other) const;
    bool operator!=(const Jedi& other) const;
    Jedi& operator=(const Jedi& other);
    void print_Jedi();
    void Write_file(const Jedi& J);
    void Read_file_J(Jedi& jedi_fromfile);
    friend std::ostream& operator<<(std::ostream& os, const Jedi& jedi_out);
    rankOfJedi char_to_enum(const char* str, rankOfJedi& rank_out);
    double char_to_double(const char* str, double midi_chlorian_out);
};
