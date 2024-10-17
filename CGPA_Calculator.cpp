/*The user’s input is used to compute the CGPA, which
includes information like the number of courses taken and
the grades earned in each one. The program also shows each
student’s overall course grade. CGPA Calculator calculates a
student’s Cumulative Grade Point Average (CGPA) from the
given exam results. The program can show the individual
grades of each course, calculate total credits and total grade
points achieved, determine the GPA for the semester, and
based on all the data, it can generate and present the CGPA
of the student.*/
#include <iostream>
using namespace std;
class CGPA_Calculator
{
    private:
    int totalCourses;
    float gradePoints;
    float courseGrade;
    double totalCreditHours;
    double totalGradePoints;
    double semesterGPA;
    double CGPA;

    public:
    void GPA(){
        cout<<"Enter the total number of courses: ";
        cin>>totalCourses;
        for(int i=0;i<totalCourses;i++){
            double creditHours;
            cout<<"Enter the credit hours of course "<<i+1<<":";
            cin>>creditHours;
            cout<<"Enter grade of course "<<i+1<<":";

            cin>>gradePoints;
            totalGradePoints+=(gradePoints*creditHours);
            totalCreditHours+=creditHours;
        }

    }
    void  setCGPA(){
        CGPA=totalGradePoints/totalCreditHours;
    }
    int  getCGPA(){
        return CGPA;
    }


};
int main()
{
    CGPA_Calculator student1;
    student1.GPA();
    student1.setCGPA();
    cout<<"Your CGPA is "<<student1.getCGPA()<<endl;
    return 0;
}