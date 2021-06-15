//
// Created by alonb on 14/06/2021.
//

#ifndef EXAMDETAILS_CPP_GAME_H
#define EXAMDETAILS_CPP_GAME_H

#include "Character.h"
#include <vector>
#include <ostream>

namespace mtm {
    class Game {

    public:
        Game(int height, int width);
        ~Game() = default;
        Game(const Game& other);
        Game& operator=(const Game& other);
        void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);
        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                                                        units_t health, units_t ammo, units_t range, units_t power);
        void move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
        void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
        void reload(const GridPoint & coordinates);

        friend std::ostream &operator<<(std::ostream &os, const Game &game);

        bool isOver(Team* winningTeam=NULL) const;

        private:
        std::vector<std::vector<std::shared_ptr<Character>>> board;
        unsigned int height, width;
        bool isEmpty(const GridPoint& coordinates) const;
        std::shared_ptr<Caracter> get(const GridPoint &coordinates);


        bool outOfBoard(const GridPoint &point) const;
    };
}

#endif //EXAMDETAILS_CPP_GAME_H
