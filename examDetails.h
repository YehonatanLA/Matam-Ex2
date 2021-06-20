
#ifndef UNTITLED2_EXAMDETAILS_H
#define UNTITLED2_EXAMDETAILS_H

#define MONTH_LENGTH 30

#include <iostream>
#include <string>

namespace mtm {

    class ExamDetails {

        int course;
        int exam_month;///Enum?
        int exam_day;
        double exam_hour; ///Should it be double? something else?
        int exam_length;
        std::string exam_link;

        static const int static_course =  234124;
        static const int static_exam_month = 7;
        static const int static_exam_day = 28;
        constexpr static const double static_exam_hour = 13;
        static const int static_exam_length = 3;
        static const int first_month = 1;
        static const int last_month = 12;
        static const int last_day = 30;
        static const int first_day = 1;
        constexpr static const double half = 0.5;
        constexpr static const double epsilon = 0.000001;

        static double fraction(double num); //??? private


    public:


        ExamDetails(int course, int exam_month, int exam_day, double exam_hour,
                    int exam_length, const std::string &exam_link = "");

        ExamDetails(const ExamDetails &other_exam_details);

        ExamDetails &operator=(const ExamDetails &exam_details);

        friend bool operator<(const ExamDetails &exam1, const ExamDetails &exam2);

        //friend bool operator==(const ExamDetails &exam_details) const;

        friend bool operator>(const ExamDetails& exam1, const ExamDetails& exam2);

        bool operator<=(const ExamDetails &other) const;

        bool operator>=(const ExamDetails &other) const;

        int operator-(const ExamDetails &other) const;

        static ExamDetails makeMatamExam();

        const std::string &getLink() const;

        void setLink(const std::string &examLink);

        friend std::ostream &operator<<(std::ostream &os, const ExamDetails &details);

        class InvalidDateException {
        };

        class InvalidTimeException {
        };

        class InvalidArgsException {
        };

        //TODO check for static consts
        ~ExamDetails() = default;

    //private:


    };

}
#endif //UNTITLED2_EXAMDETAILS_H
