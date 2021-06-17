//
// Created by alonb on 16/06/2021.
//

#include "Point.h"
namespace mtm {
    bool Point::operator==(const mtm::Point &other) const {
        return gridPoint == other.gridPoint;
    }

    bool Point::operator!=(const mtm::Point &other) const {
        return !(other == *this);
    }

    bool Point::operator<(const Point &other) const {
        if(gridPoint.row < other.gridPoint.row){
            return true;
        }
        return gridPoint.col < other.gridPoint.col;
    }

    bool Point::operator>(const Point &other) const {
        return other < *this;
    }

    bool Point::operator<=(const Point &other) const {
        return !(other < *this);
    }

    bool Point::operator>=(const Point &other) const {
        return !(*this < other);
    }

    Point::Point(const GridPoint &input) : gridPoint(input) {

    }

    int Point::distance(const Point &point1, const Point &point2) {
        return GridPoint::distance(point1.gridPoint, point2.gridPoint);
    }

    const GridPoint &Point::getGridPoint() const {
        return gridPoint;
    }

}