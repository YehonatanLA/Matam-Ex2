#ifndef EXAMDETAILS_CPP_SNIPER_H
#define EXAMDETAILS_CPP_SNIPER_H

#include "Character.h"

namespace mtm {
    class Sniper : public Character {
    public:

        Sniper(units_t health, units_t ammo, units_t range, units_t power, Team team);
        ~Sniper() = default;
        Sniper(const Sniper& other) =default;
        Sniper& operator=(const Sniper& other) =default;

        /// has critical hit once in three successful hits. has a ring of range (instead from a circle)
        void attack(const Point &src_coordinates, const Point &dst_coordinates,
                    std::map<Point, std::shared_ptr<Character>>& board) override;
        void reload() override;
        std::shared_ptr<Character> clone() const override;
        char getCharCharacterType() const override;
        void checkAttackExceptions(const Point &src, const Point &dest,
                       const std::map<Point, std::shared_ptr<Character>> &board) override;

        bool isInMovementRange(const Point &src_point, const Point &dst_point) const override;

    private:
        int critical;
        int min_range;
        static const int MAX_MOVEMENT = 4;
        static const int RELOAD_AMOUNT = 2;
        static const int AMMO_PER_ATTACK = 1;
        static const int CRITICAL_MODULE = 3;
    };
}

#endif //EXAMDETAILS_CPP_SNIPER_H
