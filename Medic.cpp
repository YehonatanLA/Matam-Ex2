#include "Medic.h"

using namespace std;

namespace mtm {
    using std::shared_ptr;

    Medic::Medic(units_t health, units_t ammo, units_t range, units_t power, Team team) : Character(health, ammo, range,
                                                                                                    power, team) {}

    void Medic::attack(const Point &src_coordinates, const Point &dst_coordinates,
                       std::map<Point, std::shared_ptr<Character>>& board) {

        checkAttackExceptions(src_coordinates, dst_coordinates, board);
        shared_ptr<Character> attacked_ptr = board.at(dst_coordinates);

        if (team != attacked_ptr->getTeam()) {
            if (ammo < AMMO_PER_ATTACK) {
                throw OutOfAmmo();
            }
            attacked_ptr->hit(power);
            ammo -= AMMO_PER_ATTACK;
            if (attacked_ptr->isDead()) {
                board.erase(dst_coordinates);
            }
        } else {
            attacked_ptr->heal(power);
        }

    }

    void Medic::reload() {
        ammo += RELOAD_AMOUNT;
    }

    shared_ptr<Character> Medic::clone() const {
        return std::make_shared<Medic>(*this);
    }


    char Medic::getCharCharacterType() const {
        switch (team) {
            case (POWERLIFTERS):
                return 'M';
            case CROSSFITTERS:
                return 'm';
        }
        return 'X';
    }


    void
    Medic::checkAttackExceptions(const Point &src, const Point &dest, const std::map<Point, std::shared_ptr<Character>> &board) {
        if (Point::distance(src, dest) > range || Point::distance(src, dest) < 0) {
            throw OutOfRange();
        }
        if(board.find(dest) == board.end()){
            if (ammo < AMMO_PER_ATTACK) {
                throw OutOfAmmo();
            }
            throw IllegalTarget();
        }
        if (Point::distance(src, dest) == 0) {
            throw IllegalTarget();
        }
    }

    bool Medic::isInMovementRange(const Point &src_point, const Point &dst_point) const {
        return Point::distance(dst_point, src_point) <= MAX_MOVEMENT;
    }

}