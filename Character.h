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
        /**
         * attacks the character in dst_coordinates.
         * @param src_coordinates - the coordinates of the attacking character.
         * @param dst_coordinates - the coordinates of the attacked character.
         * @param board - the board of the game.
         * @throw OutOfRange if dst_coordinates are out the Character's range.
         * @throw OutOfAmmo if the character's ammo is less then AMMO_PER_ATTACK.
         * @throw IllegalTarget if the attack could not happen.
         */
        virtual void attack(const Point &src_coordinates, const Point &dst_coordinates, std::map<Point, std::shared_ptr<Character>>& board) = 0;

        /**
         * reloads the Character's ammo.
         */
        virtual void reload() = 0;

        /**
         * clones the character
         * @return a shared pointer to a clone of the Character.
         */
        virtual std::shared_ptr<Character> clone() const = 0;

        /**
         * @return the type of the Character.
         */
        virtual char getCharCharacterType() const = 0;

        /**
         * checks if if the character can move to the destination from the source in consideration of distance.
         * @param src_point
         * @param dst_point
         * @return true if the character can move to the destination from the source in consideration of distance.
         *          else, return false.
         */
        virtual bool isInMovementRange(const Point &src_point, const Point &dst_point) const  = 0;

        /**
         * checks the exceptions for the Character::attack function.
         * @param src
         * @param dest
         * @param board
         * @throw OutOfRange if dst_coordinates are out the Character's range.
         * @throw OutOfAmmo if the character's ammo is less then AMMO_PER_ATTACK.
         * @throw IllegalTarget if the attack could not happen.
         */
        virtual void checkAttackExceptions(const Point& src, const Point& dest, const std::map<Point, std::shared_ptr<Character>>& board) = 0;

        //general functions:
        /**
         * @return true if character.health <= 0. else, return false.
         */
        bool isDead() const;

        /**
         * @return the team of the Character.
         */
        Team getTeam() const;

        /**
         * decrease the character's health by damage.
         * @param damage - the amount of health that will decrease.
         */
        void hit(int damage);

        /**
         * increase the character's health by add_health.
         * @param add_health - the amount of health that will increase.
         */
        void heal(int add_health);
    };
}

#endif //EXAMDETAILS_CPP_CHARACTER_H
