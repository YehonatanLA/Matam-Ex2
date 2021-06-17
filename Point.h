#ifndef EXAMDETAILS_CPP_POINT_H
#define EXAMDETAILS_CPP_POINT_H
#include "Auxiliaries.h"
namespace mtm {
    class Point {
        GridPoint gridPoint;

    public:
        explicit Point(const GridPoint &input) ;
        Point(const Point &input) = default;
        ~Point() = default;
        Point& operator=(const Point& other) = default;

        static int distance(const Point &point1, const Point &point2);

        bool operator==(const Point &rhs) const;
        bool operator!=(const Point &rhs) const;
        bool operator<(const Point &rhs) const;
        bool operator>(const Point &rhs) const;
        bool operator<=(const Point &rhs) const;
        bool operator>=(const Point &rhs) const;

        const GridPoint &getGridPoint() const;
    };


}

#endif //EXAMDETAILS_CPP_POINT_H
