#include "Soldier.h"

using namespace std;

namespace mtm {
    using std::shared_ptr;

    Soldier::Soldier(int health, int ammo, int range, int power, Team team) :
            Character(health, ammo, range, power, team),
            splash_range(ceil(((double)range) / 3)), splash_power(ceil(((double) power) / 2)) {}


    void Soldier::attack(const Point &src_coordinates, const Point &dst_coordinates,
                         std::map<Point, std::shared_ptr<Character>>& board) {
        checkAttackExceptions(src_coordinates, dst_coordinates, board);
        for (auto it = board.begin(); it != board.end(); /*no need for increment*/) {
            int attack_distance = Point::distance(it->first, dst_coordinates);
            shared_ptr<Character> attacked_ptr = it->second;
            if (attack_distance > splash_range || attacked_ptr->getTeam() == team) {
                it++;
                continue;
            }
            attacked_ptr->hit(attack_distance > 0 ? splash_power : power);
            if (attacked_ptr->isDead()) {
                board.erase(it++);
            }
            else{
                ++it;
            }
        }
        ammo -= AMMO_PER_ATTACK;
    }


    void Soldier::reload() {
        ammo += RELOAD_AMOUNT;
    }

    std::shared_ptr<Character> Soldier::clone() const {
        return std::make_shared<Soldier>(*this);
    }


    char Soldier::getCharCharacterType() const {
        switch (team) {
            case POWERLIFTERS:
                return 'S';
            case CROSSFITTERS:
                return 's';
        }
        return 0;
    }

    void
    Soldier::checkAttackExceptions(const Point &src, const Point &dest, const std::map<Point, std::shared_ptr<Character>> &board) {

        if (Point::distance(src, dest) > range || Point::distance(src, dest) < 0) {
            throw OutOfRange();
        }
        if (ammo < AMMO_PER_ATTACK) {
            throw OutOfAmmo();
        }
        if(src.getGridPoint().row != dest.getGridPoint().row && src.getGridPoint().col != dest.getGridPoint().col){
            throw IllegalTarget();
        }
    }

    bool Soldier::isInMovementRange(const Point &src_point, const Point &dst_point) const {
        return Point::distance(dst_point, src_point) <= MAX_MOVEMENT;
    }


}