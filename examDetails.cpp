#include "examDetails.h"
#include <cmath>

#define STATIC_LINK "https://tinyurl.com/59hzps6m"
using std::string;


namespace mtm {

    using std::endl;

    ExamDetails::ExamDetails(int course, int exam_month, int exam_day, double exam_hour,
                             int exam_length, const string &exam_link) : course(course), exam_link(exam_link) {

        if (FIRST_MONTH > exam_month || exam_month > LAST_MONTH) {
            throw ExamDetails::InvalidDateException();
        }
        this->exam_month = exam_month;
        if (FIRST_DAY > exam_day || exam_day > LAST_DAY) {
            throw ExamDetails::InvalidDateException();
        }
        this->exam_day = exam_day;
        this->exam_day = exam_day;
        if ((fabs(fraction(exam_hour) - HALF) >= EPSILON && fraction(exam_hour) >= EPSILON) ||
            floor(exam_hour) >= MIDNIGHT || exam_hour < 0.0) {
            throw ExamDetails::InvalidTimeException();
        }
        this->exam_hour = exam_hour;
        if (exam_length <= 0) {
            throw ExamDetails::InvalidArgsException();
        }
        this->exam_length = exam_length;
    }

    ExamDetails::ExamDetails(const ExamDetails &other_exam_details) :
            course(other_exam_details.course), exam_month(other_exam_details.exam_month),
            exam_day(other_exam_details.exam_day), exam_hour(other_exam_details.exam_hour),
            exam_length(other_exam_details.exam_length), exam_link(other_exam_details.exam_link) {
    }

    bool operator<(const ExamDetails &exam1, const ExamDetails &exam2) {
        if (exam1.exam_month < exam2.exam_month)
            return true;
        if (exam2.exam_month < exam1.exam_month)
            return false;
        if (exam1.exam_day < exam2.exam_day)
            return true;
        if (exam2.exam_day < exam1.exam_day)
            return false;
        return exam1.exam_hour < exam2.exam_hour;
    }

    int ExamDetails::operator-(const ExamDetails &other) const {
        return (MONTH_LENGTH * exam_month + exam_day) - (MONTH_LENGTH * other.exam_month + other.exam_day);
    }


    ExamDetails &ExamDetails::operator=(const ExamDetails &exam_details) {
        if (this == &exam_details) {
            return *this;
        }
        this->course = exam_details.course;
        this->exam_day = exam_details.exam_day;
        this->course = exam_details.course;
        this->course = exam_details.course;
        this->course = exam_details.course;
        this->exam_link = exam_details.exam_link;
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const ExamDetails &details) {
        os << "Course Number: " << details.course << endl
           << "Time: " << details.exam_day << "." << details.exam_month << " at " << (int) floor(details.exam_hour)
           << ":" << (fabs(floor(details.exam_hour) - details.exam_hour) < mtm::ExamDetails::EPSILON ? "00" : "30")
           << endl
           << "Duration: " << details.exam_length << ":00" << endl
           << "Zoom Link: " << details.exam_link << endl;

        return os;
    }


    ExamDetails ExamDetails::makeMatamExam() {
        return ExamDetails(STATIC_COURSE, STATIC_EXAM_MONTH, STATIC_EXAM_DAY, STATIC_EXAM_HOUR, STATIC_EXAM_LENGTH,
                           STATIC_LINK);
    }

    double ExamDetails::fraction(double num) {
        return num - floor(num);
    }

    const string &ExamDetails::getLink() const {
        return exam_link;
    }

    void ExamDetails::setLink(const string &examLink) {
        exam_link = examLink;
    }

}
