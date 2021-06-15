#include "Soldier.h"

namespace mtm {
    using std::shared_ptr;

    Soldier::Soldier(int health, int ammo, int range, int power, Team team) :
            Character(health, ammo, range, power, team),
            splash_range(ceil(range / 3)), splash_power(ceil(power / 2)) {}

    void Soldier::attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                         std::vector<std::vector<std::shared_ptr<Character>>> board) const {

    }

    void Soldier::reload() const {
        ammo += reload_amount;
    }

    std::shared_ptr<Character> Soldier::clone() const {
        //TODO
    }

    char Soldier::getCharCharacterType() {
        switch(team){
            case POWERLIFTERS:
                return 'S';
            case CROSSFITTERS:
                return 's';
        }
        return 0;
    }

}