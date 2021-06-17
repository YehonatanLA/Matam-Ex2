#include "Sniper.h"
using namespace std;
namespace mtm {


    Sniper::Sniper(units_t health, units_t ammo, units_t range, units_t power, Team team) : Character(
            health, ammo, range, power, team), critical(0) {}

    std::shared_ptr<Character> Sniper::clone() const {
//        return  shared_ptr<Sniper>(new Sniper(*this));
    }

    void Sniper::attack(const Point &src_coordinates, const Point &dst_coordinates,
                        std::map<Point, std::shared_ptr<Character>> board){

        if (canAttack(src_coordinates, dst_coordinates, board)) {
            return;
        }
        shared_ptr<Character> attacked_ptr = board.at(dst_coordinates);
        critical = (critical + 1) % critical_module;
        if (critical == 0) {
            attacked_ptr->hit(2 * power);
        } else {
            attacked_ptr->hit(power);
        }
        ammo -= ammo_per_attack;
        if (attacked_ptr->isDead()) {
            board.erase(dst_coordinates);
        }

    }

    void Sniper::reload() {
        ammo += reload_amount;
    }

    char Sniper::getCharCharacterType() const {
        switch (team) {
            case POWERLIFTERS:
                return 'N';
            case CROSSFITTERS:
                return 'n';
        }
    }

    bool Sniper::canAttack(const Point& src, const Point& dest,const std::map<Point, std::shared_ptr<Character>>& board) {

        if(Point::distance(src, dest) > range || Point::distance(src, dest) < range / 2){
            throw OutOfRange();
        }
        if(ammo - ammo_per_attack < 0){
            throw OutOfAmmo();
        }
        try{

            const shared_ptr<Character>& dest_player = board.at(dest);
            const shared_ptr<Character>& src_player = board.at(src);
            if(dest_player->getTeam() == src_player->getTeam()){
                throw IllegalTarget();
            }
        }

        catch(out_of_range&){
            throw IllegalTarget();
        }

        if(Point::distance(src, dest) == 0){
            throw IllegalTarget();
        }
        return true;
    }




}
