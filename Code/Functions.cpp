#include"util.h"
#include"databaseManager.cpp"
#include<conio.h>
using namespace std;
#ifndef FUNC
#define FUNC
databaseManager db;
void cover()
{
    system("cls");
    cout<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"                   ::WELCOME TO THE OBJECTIVE EXAM APPLICATION::                   "<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<endl;
    cout<<"1. Register New Student"<<endl;
    cout<<"2. Give Test"<<endl;
    cout<<"3. Get Student Result"<<endl;
    cout<<"4. Professor Login"<<endl;
    cout<<"5. EXIT"<<endl<<endl;
    cout<<"********************************************************************************"<<endl;
again:
    cout<<"\nENTER YOUR CHOICE (1, 2, 3, 4):"<<endl;
    cin>>main_menu_choice;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"\nPLEASE ENTER VALID CHOICE"<<endl;
        goto again;
    }
    switch(main_menu_choice)
    {
    case 1 :
        db.register_now();
        break;
    case 2 :
        db.give_test();
        break;
    case 3 :
        db.get_result();
        break;
    case 4 :
        cout<<endl;
        cin.ignore();
        professor_login();
        break;
    case 5 :
        exit(0);
    default:
        cout<<"\nPLEASE ENTER VALID CHOICE"<<endl;
        goto again;
    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void calc_no_of_questions(int n)
{
    ifstream fin4calc_q;
    fin4calc_q.open(ques_file_name[n-1],ios::in|ios::binary|ios::ate);
    no_of_questions[n-1]= fin4calc_q.tellg()/sizeof(Questions);
    fin4calc_q.close();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void calc_no_of_Students()
{
    ifstream fin4calc;
    fin4calc.open(app_file_name,ios::in|ios::binary);
    fin4calc.seekg(0,ios::end);
    no_of_Students= fin4calc.tellg()/sizeof(Students);
    fin4calc.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void professor_login()
{

    cout<<"********************************************************************************"<<endl;
    cout<<"                                ::ADMIN LOGIN::                                 "<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"ENTER PROFESSOR PASSWORD:";
    //cin.ignore();
    cin.getline(pass,20);
    if(strcmp(pass,password)==0)
    {

        system("cls");
        cout<<"********************************************************************************"<<endl;
        cout<<"                         ::WELCOME TO THE ADMIN PANEL::                         "<<endl;
        cout<<"********************************************************************************"<<endl;
        cout<<"1. SHOW STUDENT DATABASE"<<endl;
        cout<<"2. GET STUDENT RESULT"<<endl;
        cout<<"3. EDIT STUDENT DETAILS"<<endl;
        cout<<"4. ENTER QUESTIONS"<<endl;
        cout<<"5. SHOW QUESTIONS DATABASE"<<endl;
        cout<<"6. SETTINGS"<<endl;
        cout<<"7. GO BACK TO MAIN MENU"<<endl<<endl;
        cout<<"********************************************************************************"<<endl;
        valid_choice: cout<<"ENTER YOUR VALID CHOICE (1 - 7):";
        cin>>admin_menu_choice;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"WRONG CHOICE!\n";
            goto valid_choice;
        }
        switch(admin_menu_choice)
        {
        case 1 :
            db.show_student_database();
            break;
        case 2 :
            db.get_result();
            break;
        case 3:
            db.edit_student();
            break;
        case 4:
            db.enter_questions();
            break;
        case 5 :
            db.show_questions_database();
            break;
        case 6 :
            db.settings();
            break;
        case 7 :
            main();
            break;
        default:
            cout<<"WRONG CHOICE!\n";
            goto valid_choice;
        }
    }
    else
    {
        cout<<endl;
        cout<<"********************************************************************************"<<endl;
        cout<<"ACCESS DENIED!"<<endl;
        cout<<"********************************************************************************"<<endl;
        cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
        _getch();
        cout<<endl;
        main();
    }
    _getch();
    main();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void assign_rank()
{
    int big, pos, temp;
    Students t_app_obj;
    fstream t_app_file;
    t_app_file.open(app_file_name, ios::in|ios::out|ios::binary);
    int i=0;
    int marks_array[100];
    while(t_app_file.read((char*)&t_app_obj, sizeof(t_app_obj)))
    {
        marks_array[i]=t_app_obj.get_totalMarks();
        i++;
    }
    calc_no_of_Students();
    for(i=0; i<no_of_Students; i++)
    {
        big = marks_array[i];
        pos=i;
        for(int j=i+1; j<no_of_Students; j++)
        {
            if(marks_array[j]>big)
            {
                big = marks_array[j];
                pos=j;
            }
        }
        if(i!=pos)
        {
            temp = marks_array[i];
            marks_array[i] = marks_array[pos];
            marks_array[pos] = temp;
        }
    }
    t_app_file.clear();
    t_app_file.seekg(0);
    while (!t_app_file.eof())
    {
        pos3=t_app_file.tellg();
        t_app_file.read((char*)&t_app_obj, sizeof(t_app_obj));
        for(i = no_of_Students; i>-1; i--)
        {
            if(t_app_obj.get_totalMarks()==-500)
            {
                t_app_obj.set_rank(-1);
                break;
            }
            else if(t_app_obj.get_totalMarks()==marks_array[i])
            {
                t_app_obj.set_rank(i+1);
                break;
            }
        }
        t_app_file.seekg(pos3);
        t_app_file.write((char*)&t_app_obj, sizeof(t_app_obj));
    }
    t_app_file.close();
}

#endif
