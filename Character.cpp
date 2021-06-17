#include "Character.h"

namespace mtm {
    bool Character::isDead() const {
        return this->health <= 0;
    }

    Character::Character(units_t health, units_t ammo, units_t range, units_t power, Team team)
            :  health(health), ammo(ammo), range(range), power(power), team(team) {}

    Team mtm::Character::getTeam() const {
        return team;
    }

    void Character::hit(int damage) {
        health -= damage;
    }

    void Character::heal(int add_health) {
        hit(-add_health);
    }

}

