// Mid Exam OOP Katuuk Christian Everhard

#include <iostream>
#include <conio.h>

using namespace std;

using namespace std;

class Student
{
public:
    int attendance[100], quiz[100], assignment[100], mid_exam[100], final_exam[100], grade[100];
    void enterGrade(int st_num)
    {
        cout << "Enter Grade for Student " << st_num + 1 << endl;
        cout << "Attendance : ";
        cin >> attendance[st_num];
        cout << "Quiz       : ";
        cin >> quiz[st_num];
        cout << "Assignment : ";
        cin >> assignment[st_num];
        cout << "Mid Exam   : ";
        cin >> mid_exam[st_num];
        cout << "Final Exam : ";
        cin >> final_exam[st_num];
        cout << endl;
        grade[st_num] = ((10 * attendance[st_num]) / 100) + ((10 * quiz[st_num]) / 100) + ((20 * assignment[st_num]) / 100) + ((30 * mid_exam[st_num]) / 100) + ((30 * final_exam[st_num]) / 100);
    }

    void printGrade(int num_st)
    {
        cout << "---------------------------" << endl;
        cout << "STUDENS GRADE" << endl;
        cout << "---------------------------" << endl;
        cout << "Student\t\tGrade" << endl;
        cout << "---------------------------" << endl;
        for (int i = 0; i < num_st; i++)
        {
            cout << i + 1 << "\t\t" << grade[i];
            if (grade[i] <= 100 && grade[i] >= 91)
            {
                cout << " (A)" << endl;
            }
            else if (grade[i] <= 90 && grade[i] >= 85)
            {
                cout << " (A-)" << endl;
            }
            else if (grade[i] <= 84 && grade[i] >= 82)
            {
                cout << " (B+)" << endl;
            }
            else if (grade[i] <= 81 && grade[i] >= 78)
            {
                cout << " (B)" << endl;
            }
            else if (grade[i] <= 77 && grade[i] >= 75)
            {
                cout << " (B-)" << endl;
            }
            else if (grade[i] <= 74 && grade[i] >= 70)
            {
                cout << " (C+)" << endl;
            }
            else if (grade[i] <= 69 && grade[i] >= 67)
            {
                cout << " (C)" << endl;
            }
            else if (grade[i] <= 66 && grade[i] >= 60)
            {
                cout << " (C-)" << endl;
            }
            else if (grade[i] <= 59 && grade[i] >= 40)
            {
                cout << " (D)" << endl;
            }
            else if (grade[i] <= 39 && grade[i] >= 0)
            {
                cout << " (F)" << endl;
            }
        }
        cout << "---------------------------" << endl;
    }
};

//main function
int main()
{
    Student st;
    int num_st;
    cout << "Grading System v1.0" << endl;
    cout << "===================" << endl;
    cout << "Enter number of Students: ";
    cin >> num_st;
    cout << endl;
    for (int i = 0; i < num_st; i++)
    {
        st.enterGrade(i);
    }
    st.printGrade(num_st);
    cout<<"Thankyou!"<<endl;

    return 0;
}
