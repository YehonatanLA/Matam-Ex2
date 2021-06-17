#ifndef EXAMDETAILS_CPP_EXCEPTIONS_H
#define EXAMDETAILS_CPP_EXCEPTIONS_H


#include <exception>
namespace mtm {
    class Exception : std::exception {
    protected:
        public:const char* what() const noexcept override = 0;
    };



    class IllegalArgument : mtm::Exception{
        public:
        const char* what() const noexcept override;
    };


    class IllegalCell : mtm::Exception{
        public:
        const char* what() const noexcept override;

    };
    class CellEmpty : mtm::Exception{
        public:
        const char* what() const noexcept override;

    };
    class MoveTooFar : mtm::Exception{
        public:
        const char* what() const noexcept override;

    };
    class CellOccupied : mtm::Exception{
        public:
        const char* what() const noexcept override;

    };
    class OutOfRange : mtm::Exception{

    public:
        const char* what() const noexcept override;
    };
    class OutOfAmmo : mtm::Exception{
        public:
        const char* what() const noexcept override;

    };
    class IllegalTarget : mtm::Exception{
        public:
        const char* what() const noexcept override;

    };
}
#endif //EXAMDETAILS_CPP_EXCEPTIONS_H
