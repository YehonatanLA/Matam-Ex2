#ifndef EXAMDETAILS_CPP_MEDIC_H
#define EXAMDETAILS_CPP_MEDIC_H

#include "Character.h"

namespace mtm {
    class Medic : public Character {
    public:
        void attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                    std::vector<std::vector<std::shared_ptr<Character>>> board) const override;
        std::shared_ptr<Character> clone() const override;
        char getCharCharacterType() override;
        void reload() const override;


    private:
        static const int max_movement = 5;
        static const int reload_amount = 5;
        static const int ammo_per_attack = 1;
    };

}

#endif //EXAMDETAILS_CPP_MEDIC_H
