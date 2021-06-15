#ifndef EXAMDETAILS_CPP_CHARACTER_H
#define EXAMDETAILS_CPP_CHARACTER_H

#include "Auxiliaries.h"
#include "Game.h"
#include <memory>
#include "Exceptions.h"

namespace mtm {
    class Character {

    public:
        //Constructor & Destructor:
        Character(units_t health, units_t ammo, units_t range, units_t power, Team team);
        ~Character() = default;

        //virtual functions:
        virtual void attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                            std::vector<std::vector<std::shared_ptr<Character>>> board) const = 0;
        virtual void reload() const = 0;
        virtual std::shared_ptr<Character> clone() const = 0;
        virtual char getCharCharacterType() = 0;
        virtual bool isInMovementRange() = 0;
        virtual bool isInAttackRange() = 0;

        //general functions:
        bool isDead() const;
        Team getTeam() const;
        void hit(int damage);
        void heal(int add_health);

    };

    protected:
        //Parameters:
        units_t health;
        units_t ammo;
        units_t range;
        units_t power;
        Team team;

        //Static parameters:
        virtual const static int max_movement;
        virtual const static int reload_amount;
        virtual const static int ammo_per_attack;
}

#endif //EXAMDETAILS_CPP_CHARACTER_H
