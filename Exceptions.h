#ifndef EXAMDETAILS_CPP_EXCEPTIONS_H
#define EXAMDETAILS_CPP_EXCEPTIONS_H


#include <exception>
namespace mtm {
    class Exception : std::exception {
    protected:
        const char* what() const noexcept override = 0;
    };



    class IllegalArgument : mtm::Exception{
        const char* what() const noexcept override;
    };


    class IllegalCell : mtm::Exception{
        const char* what() const noexcept override;

    };
    class CellEmpty : mtm::Exception{
        const char* what() const noexcept override;

    };
    class MoveTooFar : mtm::Exception{
        const char* what() const noexcept override;

    };
    class CellOccupied : mtm::Exception{
        const char* what() const noexcept override;

    };
    class OutOfRange : mtm::Exception{
        const char* what() const noexcept override;

    };
    class OutOfAmmo : mtm::Exception{
        const char* what() const noexcept override;

    };
    class IllegalTarget : mtm::Exception{
        const char* what() const noexcept override;

    };
}
#endif //EXAMDETAILS_CPP_EXCEPTIONS_H
