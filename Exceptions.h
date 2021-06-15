

#ifndef EXAMDETAILS_CPP_EXCEPTIONS_H
#define EXAMDETAILS_CPP_EXCEPTIONS_H


#include <exception>
namespace mtm {
    class Exception : std::exception {
    protected:
        //TODO: fix the override
        const char * what() const override  = 0 noexcept;
    };



    class IllegalArgument : mtm::Exception{
        const char * what() const override;
    };


    class IllegalCell : mtm::Exception{
        const char * what() const override;

    };
    class CellEmpty : mtm::Exception{
        const char * what() const override;

    };
    class MoveTooFar : mtm::Exception{
        const char * what() const override;

    };
    class CellOccupied : mtm::Exception{
        const char * what() const override;

    };
    class OutOfRange : mtm::Exception{
        const char * what() const override;

    };
    class OutOfAmmo : mtm::Exception{
        const char * what() const override;

    };
    class IllegalTarget : mtm::Exception{
        const char * what() const override;

    };
}
#endif //EXAMDETAILS_CPP_EXCEPTIONS_H
