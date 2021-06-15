//
// Created by alonb on 14/06/2021.
//

#include "Medic.h"

namespace mtm {
    using std::vector;
    using std::shared_ptr;

    void Medic::attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                       vector<vector<shared_ptr<Character>>> board) const {
        shared_ptr<Character> attacked_ptr = board[dst_coordinates.col][dst_coordinates.row];
        if(attacked_ptr == nullptr){
            throw IllegalArgument();
        }
        if (team != attacked_ptr->getTeam()) {
            attacked_ptr->hit(power);
            ammo -= ammo_per_attack;
        }
        else{
            attacked_ptr->heal(power);
        }
    }

    void Medic::reload() const {

    }

    shared_ptr<Character> Medic::clone() const {
        return std::shared_ptr<Character>();
    }

    char Medic::getCharCharacterType() {
        switch (team) {
            case(POWERLIFTERS):
                return 'M';
            case CROSSFITTERS:
                return 'm';
        }
        return 0;
    }
}