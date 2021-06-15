#include "Sniper.h"
namespace mtm {
    void Sniper::attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                             std::vector<std::vector<std::shared_ptr<Character>>> board) const {

    }

    void Sniper::reload() const {

    }

    std::shared_ptr<Character> Sniper::clone() const {
        return std::shared_ptr<Character>();
    }

    char Sniper::getCharCharacterType() {
        return 0;
    }
}
