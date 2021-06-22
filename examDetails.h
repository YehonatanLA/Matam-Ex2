
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

        static const int STATIC_COURSE =  234124;
        static const int STATIC_EXAM_MONTH = 7;
        static const int STATIC_EXAM_DAY = 28;
        constexpr static const double STATIC_EXAM_HOUR = 13;
        static const int STATIC_EXAM_LENGTH = 3;
        static const int FIRST_MONTH = 1;
        static const int LAST_MONTH = 12;
        static const int LAST_DAY = 30;
        static const int FIRST_DAY = 1;
        constexpr static const double HALF = 0.5;
        constexpr static const double EPSILON = 0.000001;
        constexpr static const double MIDNIGHT = 24;

        static double fraction(double num);


    public:
        /**
         * Constructor for ExamDetails.
         * @param course  - the coursre number.
         * @param exam_month - the exam month of the exam. Must be between 1 and 12.
         * @param exam_day - the day of the exam. Must be between 1 and 30.
         * @param exam_hour - the hour of the exam. Must be either a round hour or a half hour
         * between 0 to 23:30.
         * @param exam_length - the length of the exam. Must be a non-negative round number.
         * @param exam_link  - the link to the exam. The default value is " ".
         * @throw - InvalidDateException - if one of the date parameters is invalid.
         * @throw - InvalidTimeException - if one of the time parameters is invalid.
         * @throw - InvalidArgsException - if one of the other arguments is invalid.
         */
        ExamDetails(int course, int exam_month, int exam_day, double exam_hour,
                    int exam_length, const std::string &exam_link = " ");
        /**
         * Destructor for ExamDetails. default.
         */
        ~ExamDetails() = default;

        /**
         * Copy constructor for ExamDetails.
         * @param other_exam_details - the ExamDetails to copy from.
         */
        ExamDetails(const ExamDetails &other_exam_details);

        /**
         * Assignment operator  for ExamDetails.
         * @param exam_details  - the ExamDetails to assign from.
         * @return - the ExamDetails after assign with exam_details.
         */
        ExamDetails &operator=(const ExamDetails &exam_details);

        /**
         * Operator< for ExamDetails. The operator compares two ExamDetails by the date
         * (month precedes, then day then hour)
         * @param exam1 - the first exam to compare.
         * @param exam2 - the second exam to compare.
         * @return - true if exam1 comes before exam2, otherwise return false.
         */
        friend bool operator<(const ExamDetails &exam1, const ExamDetails &exam2);

        /**
         * Operator- for ExamDetails. The operator returns the
         * difference of days between exam2 and this ExamDetails. Can return a negative number.
         * @param other- an ExamDetails to compare with this ExamDetails.
         * @return - The difference of days between exam2 and this ExamDetails.
         */
        int operator-(const ExamDetails &other) const;

        /**
         * Makes a static ExamDetails.
         * @return - the created ExamDetails.
         */
        static ExamDetails makeMatamExam();

        /**
         * Returns the link to the exam.
         */
        const std::string &getLink() const;

        /**
         * Sets the link to the exam.
         * @param examLink - the new link to set to.
         */
        void setLink(const std::string &examLink);

        /**
         * Operator<< for ExamDetails.
         * @param os - the output variable to store the output.
         * @param details - the ExamDetails to print.
         * @return - the variable os.
         */
        friend std::ostream &operator<<(std::ostream &os, const ExamDetails &details);

        /**
         * The class for invalid date exceptions.
         */
        class InvalidDateException {
        };

        /**
         * The class for invalid time exceptions.
         */
        class InvalidTimeException {
        };

        /**
         *  The class for non date/time related invalid exceptions.
         */
        class InvalidArgsException {
        };


    //private:


    };

}
#endif //UNTITLED2_EXAMDETAILS_H
