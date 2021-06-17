#include "Game.h"
#include "Soldier.h"
#include "Medic.h"
#include "Sniper.h"

using namespace std;

namespace mtm
{
    Game::Game(int height, int width)
    {
        if (height <= 0 || width <= 0) {
            throw IllegalArgument();
        }
        this->height = height;
        this->width = width;
        board = map<Point,shared_ptr<Character>>();
    }

    Game::Game(const Game& other)
    {
        height = other.height;
        width = other.width;
        for (const auto& iterator : other.board) {
            Point point(iterator.first);
            shared_ptr<Character> shared_ptr = iterator.second->clone();
            board.insert({point, shared_ptr});
        }
    }

    Game& Game::operator=(const Game &other) = default;

    void Game::addCharacter(const GridPoint &coordinates, const std::shared_ptr<Character>& character)
    {
        if (outOfBoard(coordinates)){
            throw IllegalCell();
        }
        Point point_coordinates(coordinates);
        if(isOccupied(point_coordinates)){
            throw CellOccupied();
        }
        board.insert({point_coordinates,character});
    }

    std::shared_ptr<Character>
    Game::makeCharacter(CharacterType type, Team team, units_t health, units_t ammo, units_t range, units_t power)
    {
        switch (type) {
            case SOLDIER:
                return Soldier(health, ammo, range, power, team).clone();
            case MEDIC:
                return Medic(health, ammo, range, power, team).clone();
            case SNIPER:
                return Sniper(health, ammo, range, power, team).clone();
        }
        return nullptr;
    }

    void Game::move(const GridPoint &src_coordinates, const GridPoint &dst_coordinates) {
        if(outOfBoard(src_coordinates) || outOfBoard(dst_coordinates)){
            throw IllegalCell();
        }
        Point src_point(src_coordinates), dst_point(dst_coordinates);
        if(!isOccupied(src_point)){
            throw CellEmpty();
        }
        shared_ptr<Character> ptr_character = board.at(src_point);
        if (!ptr_character->isInMovementRange(src_point, dst_point)){
            throw MoveTooFar();
        }
        if(isOccupied(dst_point)){
            throw CellOccupied();
        }
        board.erase(src_point);
        board.insert({dst_point, ptr_character});
    }

    void Game::attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates) {
        if(outOfBoard(src_coordinates) || outOfBoard(dst_coordinates)){
            throw IllegalCell();
        }
        Point src_point(src_coordinates), dst_point(dst_coordinates);
        if(!isOccupied(src_point)){
            throw CellEmpty();
        }
        shared_ptr<Character> attacker = board.at(src_point);
        attacker->attack(src_point , dst_point, board);

    }

    void Game::reload(const GridPoint &coordinates) {
        if(outOfBoard(coordinates)){
            throw IllegalCell();
        }
        Point point(coordinates);
        if(!isOccupied(point)){
            throw CellEmpty();
        }
        shared_ptr<Character> ptr_character = board.at(point);
        ptr_character->reload();
    }

    std::ostream &operator<<(std::ostream &os, const Game &game) {
        char* begin = new char [game.height * game.width]; //!out fo memory?
        char* end = begin + game.height * game.width;
        for (char* ptr = begin; ptr < end; ++ptr) {
            *ptr = ' '; ///Define? static const?
        }
        for(const auto& it : game.board){
            int row = it.first.getGridPoint().row;
            int col = it.first.getGridPoint().col;
            shared_ptr<Character> ptr_character = it.second;
            begin[ (game.width * row) + col] = ptr_character->getCharCharacterType(); ///math? transpose?
        }
        printGameBoard(os, begin, end, game.width);
        delete[] begin;
        return os;
    }

    bool Game::isOver(Team *winningTeam) const {
        if(board.empty()){
            return false;
        }
       bool powerlifters_in_game = false, crossfitters_in_game = false;
        for (const auto& it : board) {
            switch (it.second->getTeam()) {
                case POWERLIFTERS:
                    powerlifters_in_game = true;
                    break;
                case CROSSFITTERS:
                    crossfitters_in_game = true;
                    break;
            }
            if(powerlifters_in_game && crossfitters_in_game){
                return false;
            }
        }
        if(winningTeam != nullptr){
            *winningTeam = powerlifters_in_game ? POWERLIFTERS : CROSSFITTERS;
        }
        return true;
    }

    bool Game::outOfBoard(const GridPoint &coordinates) const {
        return coordinates.row < 0 ||coordinates.col < 0 ||coordinates.row >= height ||coordinates.col >= width;
    }

    bool Game::isOccupied(const Point &point) {
        for (const auto& it : board) {
            if (it.first == point){
                return true;
            }
        }
        return false;
    }


}

