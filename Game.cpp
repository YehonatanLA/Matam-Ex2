#include "Game.h"
#include <utility>
#include "Soldier.h"
#include "Medic.h"
#include "Sniper.h"
#include "Auxiliaries.h"

using namespace std;

namespace mtm
{
    Game::Game(int height, int width)
    {
        if (height <= 0 || width <= 0) {
            //ToDo illegalArgument
        }
        board = vector<vector<shared_ptr<Character>>>(height, vector<shared_ptr<Character>>(width,
                                                                                            shared_ptr<Character>(
                                                                                                    nullptr)));
        this->height = height;
        this->width = width;

    }

    mtm::Game::Game(const Game& other)
    {
        this->height = other.height;
        this->width = other.width;
        Game new_game((int) height, (int) width);
        for(int i = 0; i < height; i++){
            for (int j = 0; j < width; j++) {
                new_game.board[i][j] = other.board[i][j]->clone();
            }
        }
    }

    Game& mtm::Game::operator=(const Game &other)
    {
        if(this == &other){
            return *this;
        }
        board = other.board;
        height = other.height;
        width = other.width;
        return *this;
    }

    void Game::addCharacter(const GridPoint &coordinates, std::shared_ptr<Character> character) {
        if (coordinates.row < 0 ||coordinates.col < 0 ||coordinates.row >= height ||coordinates.col >= width){
            //ToDo IllegalCell Exception
            return;
        }
        if(!isEmpty(coordinates)){
            //ToDo CellOccupied Exception
            return;
        }
        board[coordinates.row][coordinates.col] = character; ///why yell??
    }

    std::shared_ptr<Character>
    Game::makeCharacter(CharacterType type, Team team, units_t health, units_t ammo, units_t range, units_t power) {
        switch (type) {
            case SOLDIER:
                Soldier soldier(health, ammo, range, power, team);  ///wtf
                break;
            case MEDIC:
                break;
            case SNIPER:
                break;
        }
    }

    std::ostream &operator<<(std::ostream &os, const Game &game) {
        char* begin = new char [game.height * game.width];
        char* end = begin;
        int arr_position = 0;
        for(const vector<shared_ptr<Character>>& vector_row : game.board){
            for(const shared_ptr<Character>& position: vector_row){
                begin[arr_position] = position->getCharCharacterType();
                arr_position++;
            }
        }
        printGameBoard(os, begin, end, game.width);
        delete[] begin;

    }

    bool Game::isOver(Team *winningTeam) const {
        bool powerlifters_in_game = false, crossfitters_in_game = false;
        int row = 0, col = 0;
        for(const vector<shared_ptr<Character>>& vector_row: board){
            for(const shared_ptr<Character>& position : vector_row){

                GridPoint point(row,col);
                if(isEmpty(point)){
                    col++;
                    continue;
                }

                else{

                    Team group_name = position->getTeam();
                    switch (group_name) {

                        case POWERLIFTERS:
                            powerlifters_in_game = true;
                            break;
                        case CROSSFITTERS:
                            crossfitters_in_game = true;
                            break;
                    }
                    col++;
                }
            }
            row++;

        }
        if(winningTeam == nullptr){
        return crossfitters_in_game == powerlifters_in_game;

        }
        else{
            if(crossfitters_in_game == powerlifters_in_game){
                return false;
            }
            else if(crossfitters_in_game > powerlifters_in_game){
                *winningTeam = CROSSFITTERS;
            }
            else{
                *winningTeam = POWERLIFTERS;
            }
        }
        return true;
    }

    void Game::reload(const GridPoint &coordinates) {
        if(outOfBoard(coordinates)){
            throw IllegalCell();
        }
        if(isEmpty(coordinates)){
            throw CellEmpty();
        }
        shared_ptr<Character> character = board[coordinates.row][coordinates.col];
        character->reload();
    }

    bool Game::outOfBoard(const GridPoint &point) const {
        if(point.row >= width || point.col >= height){
            return true;
        }
        return false;
    }

    void Game::move(const GridPoint &src_coordinates, const GridPoint &dst_coordinates) {
        if(outOfBoard(src_coordinates) || outOfBoard(dst_coordinates)){
            throw
        }
    }


}

