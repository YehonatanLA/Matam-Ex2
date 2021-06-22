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
        static const int max_movement = 4;
        static const int reload_amount = 2;
        static const int ammo_per_attack = 1;
        static const int critical_module = 3;
    };
}

#endif //EXAMDETAILS_CPP_SNIPER_H
