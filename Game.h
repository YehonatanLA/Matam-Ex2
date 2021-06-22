#ifndef EXAMDETAILS_CPP_GAME_H
#define EXAMDETAILS_CPP_GAME_H

#include "Character.h"
#include <map>
#include <ostream>
#include "Point.h"
#include "Soldier.h"
#include "Medic.h"
#include "Sniper.h"


namespace mtm {
    class Game {
        //parameters:
        std::map<Point,std::shared_ptr<Character>> board;
        unsigned int height, width;

        //functions:
    public:
        ///FILL ME!
        Game(int height, int width);

        ///FILL ME!
        ~Game() = default;

        ///FILL ME!
        Game(const Game &other);

        ///FILL ME!
        Game &operator=(const Game &other);

        ///FILL ME!
        void addCharacter(const GridPoint &coordinates, const std::shared_ptr<Character>& character);

        ///FILL ME!
        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                                                        units_t health, units_t ammo, units_t range, units_t power);

        ///FILL ME!
        void move(const GridPoint &src_coordinates, const GridPoint &dst_coordinates);

        ///FILL ME!
        void attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates);

        ///FILL ME!
        void reload(const GridPoint &coordinates);

        ///FILL ME!
        friend std::ostream &operator<<(std::ostream &os, const Game &game);

        ///FILL ME!
        bool isOver(Team *winningTeam = NULL) const;

    private:
        ///FILL ME!
        bool outOfBoard(const GridPoint &point) const;

        ///FILL ME!
        bool isOccupied(const Point& point);
    };
}

#endif //EXAMDETAILS_CPP_GAME_H
