#ifndef EXAMDETAILS_CPP_GAME_H
#define EXAMDETAILS_CPP_GAME_H

#include "Character.h"
#include <map>
#include <ostream>
#include "Point.h"
#include "Soldier.h"
#include "Medic.h"
#include "Sniper.h"

//TODO @throw
namespace mtm {
    class Game {
        //parameters:
        std::map<Point,std::shared_ptr<Character>> board;
        unsigned int height, width;

        //functions:
    public:
        /**
         * Constructor for a Game object.
         * @param: height - the height of the board.
         * @param: width - the width of the board.
         * @throws: IllegalArgument in case of one of the arguments is non positive.
         * */
        Game(int height, int width);

        /**
         * Destructor for a Game object.
         * */
        ~Game() = default;

        /**
         * Copy Constructor for a Game object.
         * @param: other (reference) - another game that will be copied.
         * */
        Game(const Game &other);

        /**
         * Assignment Operator for a Game object.
         * @param: other (reference) - another game that will be assigned.
         * @return: a Game object reference of the assigned game.
         * */
        Game &operator=(const Game &other);

        /**
         * adds a character to the Game object.
         * @param coordinates (reference) - the coordinates of the added character.
         * @param character (reference) - a shared pointer to a constructed character.
         * @throw OutOfBound if the given coordinates are out of the bounds of the board.
         * @throw CellOccupied if the given coordinates are occupied in the board.
         * */
        void addCharacter(const GridPoint &coordinates, const std::shared_ptr<Character>& character);

        /**
         * Creates a specific character based on the given characteristics.
         * @param type - the type of the character that will be created.
         * @param team - the type of the character that will be created.
         * @param health - the type of the character that will be created.
         * @param ammo - the type of the character that will be created.
         * @param range - the type of the character that will be created.
         * @param power - the type of the character that will be created.
         * @return a shared pointer created Character.
         * @throw IllegalArgument if health <= 0 or ammo < 0 or range < 0 or power < 0.
         * */
        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                                                        units_t health, units_t ammo, units_t range, units_t power);

        /**
         * Moves a character in the board
         * @param src_coordinates (reference) - the coordinates of the source of the moving character.
         * @param dst_coordinates (reference) - the coordinates of the destination of the moving character.
         * @throw IllegalCell if src_coordinates is out of range or dst_coordinates is out of range.
         * @throw CellEmpty if there is no character in src_point.
         * @throw MoveTooFar if the destination is not in the movement range of the Character.
         * @throw CellOccupied if the destination point is occupied.
         * */
        void move(const GridPoint &src_coordinates, const GridPoint &dst_coordinates);

        /**
         * The character in the source GridPoint attacks the character in the destination GridPoint.
         * @param src_coordinates - the coordinates of the attacking character.
         * @param dst_coordinates - the coordinates of the attacked character.
         * @throw IllegalCell if src_coordinates or dst_coordinates are out of board.
         * @throw CellEmpty if src_point is not occupied.
         */
        void attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates);

        /**
         * the character in the given coordinates does a reload action.
         * @param coordinates - the coordinates of the character about to reload.
         * @throw IllegalCell if coordinates are out of the board.
         * @throw CellEmpty if src_point is not occupied.
         */
        void reload(const GridPoint &coordinates);

        /**
         * operator for printing the given Game.
         * @param os - The Output Stream that the game will be printed in.
         * @param game -
         * @return
         */
        friend std::ostream &operator<<(std::ostream &os, const Game &game);

        /**
         * Checks if in the current state of the board, any of the group wins.
         * @param winningTeam
         * @return:
         *      if there are only characters from one team, the function will return true.
         *      if there are no characters on the game or characters from both of the teams, the function will
         *              return false.
         *      if winningTeam != NULL/nullptr and there is a winning team, the team of the winners will be written
         *              at the address of the pointer winningTeam.
         *      if there are no characters on the game or characters from both of the teams and winningTeam != NULL/nullptr,
         *              the value of winning team will not change.
         *
         */
        bool isOver(Team *winningTeam = NULL) const;

    private:
        /**
         * Checks if the GridPoint is out of the board.
         * @param point - the given GridPoint.
         * @return true if the GridPoint is in the Range of the board. else, return false.
         */
        bool outOfBoard(const GridPoint &point) const;

        /**
         * Checks if the Point is Occupied.
         * @param point - the given Point.
         * @return true if the Point is occupied. else, return false.
         */
        bool isOccupied(const Point& point);
    };
}

#endif //EXAMDETAILS_CPP_GAME_H
