//
// Created by alonb on 16/06/2021.
//

#include "Exceptions.h"


const char *mtm::IllegalArgument::what() const {
    return "A game related error has occurred: IllegalArgument";
}


const char *mtm::IllegalCell::what() const {
    return "A game related error has occurred: IllegalCell";
}

const char *mtm::CellEmpty::what() const {
    return "A game related error has occurred: CellEmpty";
}

const char *mtm::MoveTooFar::what() const {
    return "A game related error has occurred: MoveTooFar";
}

const char *mtm::CellOccupied::what() const {
    return "A game related error has occurred: CellOccupied";
}

const char *mtm::OutOfRange::what() const {
    return "A game related error has occurred: OutOfRange";
}

const char *mtm::OutOfAmmo::what() const {
    return "A game related error has occurred: OutOfAmmo";
}

const char *mtm::IllegalTarget::what() const {
    return "A game related error has occurred: IllegalTarget";
}

