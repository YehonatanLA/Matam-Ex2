#ifndef EXAMDETAILS_CPP_SOLDIER_H
#define EXAMDETAILS_CPP_SOLDIER_H


#include "Character.h"
namespace mtm {
    class Soldier : public Character {
    public:
        //Constructor
        Soldier(units_t health, units_t ammo, units_t range, units_t power, Team team);


        void attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                    std::vector<std::vector<std::shared_ptr<Character>>> board) const override;
        void reload() const override;
        std::shared_ptr<Character> clone() const override;
        char getCharCharacterType() override;



    private:
        static const int max_movement = 3;
        static const int reload_amount = 3;
        static const int ammo_per_attack = 1;
        units_t splash_range;
        units_t splash_power;
    };
}

#endif //EXAMDETAILS_CPP_SOLDIER_H

