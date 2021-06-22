#ifndef EXAMDETAILS_CPP_SOLDIER_H
#define EXAMDETAILS_CPP_SOLDIER_H


#include "Character.h"
namespace mtm {
    class Soldier : public Character {
        //additional parameters:
        units_t splash_range;
        units_t splash_power;
    public:
        Soldier(units_t health, units_t ammo, units_t range, units_t power, Team team);
        ~Soldier() =default;
        Soldier(const Soldier& other) =default;
        Soldier& operator=(const Soldier& other) =default;

        /// has splash damage.
        void attack(const Point &src_coordinates, const Point &dst_coordinates,
                    std::map<Point, std::shared_ptr<Character>>& board) override;
        void reload()  override;
        std::shared_ptr<Character> clone() const override;
        char getCharCharacterType() const override;
        void checkAttackExceptions(const Point &src, const Point &dest,
                       const std::map<Point, std::shared_ptr<Character>> &board) override;
        bool isInMovementRange(const Point &src_point, const Point &dst_point) const override;

    private:
        static const int MAX_MOVEMENT = 3;
        static const int RELOAD_AMOUNT = 3;
        static const int AMMO_PER_ATTACK = 1;
    };
}

#endif //EXAMDETAILS_CPP_SOLDIER_H

