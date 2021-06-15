#ifndef EXAMDETAILS_CPP_SNIPER_H
#define EXAMDETAILS_CPP_SNIPER_H

#include "Character.h"
namespace mtm {
    class Sniper : public Character {
    public:
        void attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                    std::vector<std::vector<std::shared_ptr<Character>>> board) const override;
        void reload() const override;
        std::shared_ptr<Character> clone() const override;
        char getCharCharacterType() override;

    private:
        static const int max_movement = 4;
        static const int reload_amount = 2;
        static const int ammo_per_attack = 1;
    };
}

#endif //EXAMDETAILS_CPP_SNIPER_H
