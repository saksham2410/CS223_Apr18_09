#include"util.h"
#ifndef STUDENTS
#define STUDENTS

class Students : public User
{
    int dob_day;
    int dob_mon;
    int dob_year;
    int rank;
    int testId[20]= {0};
    int marks_obtained[20]= {0};

public:
    int no_of_appeared_tests=0;

    int get_dob_d()
    {
        return dob_day;
    }
    int get_dob_m()
    {
        return dob_mon;
    }
    int get_dob_y()
    {
        return dob_year;
    }

    int get_totalMarks()
    {
        int marks =0;
        for(int i=0; i<no_of_appeared_tests; i++)
        {
            marks=marks+marks_obtained[i];
        }
        return marks;
    }
    int get_rank()
    {
        return rank;
    }
    void set_rank(int rn)
    {
        rank=rn;
    }
    void set_UserId(int ap)
    {
        UserId=ap;
    }
    void set_dob_d(int dd)
    {
        dob_day=dd;
    }
    void set_dob_m(int dm)
    {
        dob_mon=dm;
    }
    void set_dob_y(int dy)
    {
        dob_year=dy;
    }

    void set_result(int testNumber, int marksObtained)
    {
        testId[no_of_appeared_tests]=testNumber;
        marks_obtained[no_of_appeared_tests]=marksObtained;
    }
    void show_result()
    {
        cout<<"NO. OF TEST ATTEMPTED : "<<no_of_appeared_tests<<endl<<endl;
        cout.setf(ios::left);
        cout<<setfill(' ')<<"S.no"<<setw(30)<<"TestID"<<setw(15)<<"Marks Obtained";
        cout<<endl;
        for(int i=0; i<no_of_appeared_tests; i++)
        {
            //cout.setf(ios::left);
            cout<<i+1<<setw(30)<<testId[i]<<setw(15)<<marks_obtained[i]<<endl;
        }
    }

    void get_short_faname()
    {
        if(strlen(first_name)<15)
        {
            cout.width(15);
            cout.fill(' ');
            cout<<first_name;
        }
        else
            cout.write(first_name,15);
    }
    void get_short_maname()
    {
        if(strlen(last_name)<15)
        {
            cout.width(15);
            cout.fill(' ');
            cout<<last_name;
        }
        else
            cout.write(last_name,15);
    }
};
#endif
