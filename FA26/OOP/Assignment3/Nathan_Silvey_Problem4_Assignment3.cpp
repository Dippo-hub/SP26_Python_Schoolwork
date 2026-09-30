#include <iostream>
#include <string>
using std::string;

class Attendance {
    public:
        Attendance(const string &attendance) {
            this -> attendance = attendance;
        }

        bool checkAttendance() {
            if (!isLate() and !isAbsent())
                return true;
            return false;
        }

    private:
        string attendance; // ex ("PALLLAPAAP")

        bool isAbsent() { //returns true if absent for 2 or more times in record
            short absentCount = 0;
            for(short i=0; i<attendance.size(); i++) {
                if (attendance.at(i) == 'A')
                absentCount++;
            }
            if (absentCount > 2)
                return true;
            return false;
        }

        bool isLate() { //returns true if late for 3 consecutive days
            if (attendance.size() < 3)
                return false;
            for(short j=2; j<attendance.size(); j++) {
                if (attendance.at(j-2) == 'L' && attendance.at(j-1) == 'L' && attendance.at(j) == 'L')
                    return true;
            }
            return false;
        }
};

int main(void) {
Attendance atd1("PPALLP");
Attendance atd2("PPALLL");
(atd1.checkAttendance()) ? std::cout << "PASSED" : std::cout << "FAILED";
std::cout << std::endl;
(atd2.checkAttendance()) ? std::cout << "PASSED" : std::cout << "FAILED";
std::cout << std::endl;
return 0;
}