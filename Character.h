#ifndef EXAMDETAILS_CPP_CHARACTER_H
#define EXAMDETAILS_CPP_CHARACTER_H

#include "Point.h"
//#include "Game.h"
#include <map>
#include <memory>
#include "Exceptions.h"

namespace mtm {
    class Character {

    protected:
        //Fields:
        units_t health;
        units_t ammo;
        units_t range;
        units_t power;
        Team team;

    public:
        //Constructor & Destructor:
        Character(units_t health, units_t ammo, units_t range, units_t power, Team team);
        Character(const Character& other) = default;
        ~Character() = default;
        Character& operator=(const Character& other) = default;

        //Virtual Functions:
        ///FILL ME!
        virtual void attack(const Point &src_coordinates, const Point &dst_coordinates, std::map<Point, std::shared_ptr<Character>>& board) = 0;

        ///FILL ME!
        virtual void reload() = 0;

        ///FILL ME!
        virtual std::shared_ptr<Character> clone() const = 0;

        ///FILL ME!
        virtual char getCharCharacterType() const = 0;

        ///FILL ME!
        virtual bool isInMovementRange(const Point &src_point, const Point &dst_point) const  = 0;

        ///FILL ME!
        virtual void checkAttackExceptions(const Point& src, const Point& dest, const std::map<Point, std::shared_ptr<Character>>& board) = 0;

        //general functions:
        ///FILL ME!
        bool isDead() const;

        ///FILL ME!
        Team getTeam() const;

        ///FILL ME!
        void hit(int damage);

        ///FILL ME!
        void heal(int add_health);
    };
}

#endif //EXAMDETAILS_CPP_CHARACTER_H
