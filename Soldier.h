#ifndef EXAMDETAILS_CPP_SOLDIER_H
#define EXAMDETAILS_CPP_SOLDIER_H


#include "Character.h"
namespace mtm {
    class Soldier : public Character {
    public:

        Soldier(units_t health, units_t ammo, units_t range, units_t power, Team team);
        ~Soldier() =default;
        Soldier(const Soldier& other) =default;
        Soldier& operator=(const Soldier& other) =default;

        ///FILL ME!
        void attack(const Point &src_coordinates, const Point &dst_coordinates,
                    std::shared_ptr<std::map<Point, std::shared_ptr<Character>>>  board) override;

        ///FILL ME!
        void reload()  override;

        ///FILL ME!
        std::shared_ptr<Character> clone() const override;

        ///FILL ME!
        char getCharCharacterType() const override;

        bool canAttack(const Point &src, const Point &dest,
                       const std::map<Point, std::shared_ptr<Character>> &board) override;

        bool isInMovementRange(const Point &src_point, const Point &dst_point) const override;


    private:
        static const int max_movement = 3;
        static const int reload_amount = 3;
        static const int ammo_per_attack = 1;
        units_t splash_range;
        units_t splash_power;
    };
}

#endif //EXAMDETAILS_CPP_SOLDIER_H

