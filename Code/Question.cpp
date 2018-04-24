#include"util.h"
#ifndef QUES
#define QUES
class Questions
{
    int id;
    int type;
    char ques[100];
    char opt1[100];
    char opt2[100];
    char opt3[100];
    char opt4[100];
    int ans;
public:
    void set_id(int i)
    {
        id=i;
    }
    void set_type(int t)
    {
        type=t;
    }
    void set_ques(char q[])
    {
        strcpy(ques,q);
    }
    void set_opt1(char o1[])
    {
        strcpy(opt1,o1);
    }
    void set_opt2(char o2[])
    {
        strcpy(opt2,o2);
    }
    void set_opt3(char o3[])
    {
        strcpy(opt3,o3);
    }
    void set_opt4(char o4[])
    {
        strcpy(opt4,o4);
    }
    void set_ans(int a)
    {
        ans=a;
    }
    int get_id()
    {
        return id;
    }
    int get_type()
    {
        return type;
    }
    void get_ques()
    {
        cout<<ques;
    }
    void get_opt1()
    {
        cout<<opt1;
    }
    void get_opt2()
    {
        cout<<opt2;
    }
    void get_opt3()
    {
        cout<<opt3;
    }
    void get_opt4()
    {
        cout<<opt4;
    }
    int get_ans()
    {
        return ans;
    }
    void get_short_ques()
    {
        if(strlen(ques)<15)
        {
            cout.width(15);
            cout.fill(' ');
            cout<<ques;
        }
        else
            cout.write(ques,15);
    }
    void get_short_opt1()
    {
        if(strlen(opt1)<10)
        {
            cout.width(10);
            cout.fill(' ');
            cout<<opt1;
        }
        else
            cout.write(opt1,10);
    }
    void get_short_opt2()
    {
        if(strlen(opt2)<10)
        {
            cout.width(10);
            cout.fill(' ');
            cout<<opt2;
        }
        else
            cout.write(opt2,10);
    }
    void get_short_opt3()
    {
        if(strlen(opt3)<10)
        {
            cout.width(10);
            cout.fill(' ');
            cout<<opt3;
        }
        else
            cout.write(opt3,10);
    }
    void get_short_opt4()
    {
        if(strlen(opt4)<10)
        {
            cout.width(10);
            cout.fill(' ');
            cout<<opt4;
        }
        else
            cout.write(opt4,10);
    }
    int max_marks;
    int negative_mark;
    int positive_mark;
    int no_of_ques_to_ask;
    char password[30];
    char app_file_name[30];
    char ques_file_name[30];
    int get_negative_mark()
    {
        return negative_mark;
    }
    int get_positive_mark()
    {
        return positive_mark;
    }
    int get_no_of_ques_to_ask()
    {
        return no_of_ques_to_ask;
    }
    char* get_password()
    {
        return password;
    }
    char* get_app_file_name()
    {
        return app_file_name;
    }
    char* get_ques_file_name()
    {
        return ques_file_name;
    }
    void set_negative_mark(int nm)
    {
        negative_mark=nm;
    }
    void set_positive_mark(int pm)
    {
        positive_mark=pm;
    }
    void set_no_of_ques_to_ask(int nq)
    {
        no_of_ques_to_ask=nq;
    }
    void set_password(char pw[])
    {
        strcpy(password, pw);
    }
    void set_app_file_name(char af[])
    {
        strcpy(app_file_name, af);
    }
    void set_ques_file_name(char qf[])
    {
        strcpy(ques_file_name, qf);                 //to be checked again
    }
};
#endif
