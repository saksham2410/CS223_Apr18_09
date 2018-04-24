#include"util.h"
#include<conio.h>
using namespace std;
#ifndef DBM
#define DBM

class databaseManager
{
public:
    void show_questions_database();
    void enter_questions();
    void show_student_database();
    void register_now();
    void edit_student();
    void give_test();
    void get_result();
    void settings();
    void configure();
};
void databaseManager:: settings()
{
    system("cls");

    cout<<"********************************************************************************"<<endl;
    cout<<"                                  ::SETTINGS::                                  "<<endl<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"CURRENT SETTINGS : "<<endl<<endl;
    cout<<"1. ADMIN PASSWORD : "<<password<<endl;
    cout<<"2. STUDENT DATABASE FILENAME : "<<app_file_name<<endl;
    cout<<"3. QUESTIONS DATABASE FILENAME : "<<endl;
    for(int i=0; i<4; i++)
        cout<<"\t"<<ques_file_name[i]<<endl;
    cout<<"4. MARKS AWARDED FOR RIGHT ANSWER : "<<positive_mark<<endl;
    cout<<"5. MARKS DEDUCTED FOR WRONG ANSWER : "<<negative_mark<<endl;
    cout<<"6. NUMBER OF QUESTIONS TO BE ASKED IN THE TEST : "<<no_of_ques_to_ask<<endl<<endl;
    cout<<"DO YOU WANT TO CHANGE THE SETTINGS? (y/n) : ";
    char ch[100];
    cin.ignore();
    cin.getline(ch,100);
    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
    {
        cout<<"\nNOTE : If invalid inputs are entered, the settings remain unchanged\n\n";
        Questions config_obj;
        ofstream config_file;
        config_file.open("config.dat",ios::out|ios::trunc|ios::binary);
        cout<<"\nENTER NEW ADMIN PASSWORD OR ENTER X TO DO NOT CHANGE : ";
        //cin.ignore();
        cin.getline(new_password,30);
        if((strcmp(new_password,"x")!=0)&&(strcmp(new_password,"X")!=0))
        {
            config_obj.set_password(new_password);
        }
        else
        {
            config_obj.set_password(password);
        }
        cout<<"\nENTER NEW FILENAME FOR STUDENT DATABASE OR ENTER X TO DO NOT CHANGE : ";
        cin.getline(new_app_file_name,100);
        if((strcmp(new_app_file_name,"x")!=0)&&(strcmp(new_app_file_name,"X")!=0))
        {
            config_obj.set_app_file_name(new_app_file_name);
        }
        else
        {
            config_obj.set_app_file_name(app_file_name);
        }
        cout<<"\nENTER NEW FILENAME FOR QUESTION DATABASE OR ENTER X FOR NO CHANGE : ";
        cin.getline(new_ques_file_name,100);
        if((strcmp(new_ques_file_name,"x")!=0)&&(strcmp(new_ques_file_name,"X")!=0))
        {
            /*
               int n;
            valid1:
               cout<<"\nEnter the courseID for the FILENAME (1.English, 2.Physics, 3.Chemistry, 4.Maths) : ";
               cin>>n;
               if(cin.fail())
               {
                   cin.clear();
                   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                   cout<<"\nINVALID COURSEID";
                   goto valid1;
               }
               if(add_type<1 || add_type>4)
               {
                   system("cls");
                   cout<<"\nPLEASE ENTER VALID COURSEID"<<endl;
                   goto valid1;
               }*/
            config_obj.set_ques_file_name(new_ques_file_name);
        }
        else
        {
            config_obj.set_ques_file_name(ques_file_name[0]);               //to be checked again
        }
        cout<<"\nENTER MARKS TO BE AWARDED FOR RIGHT ANSWER OR ENTER -1(MINUS ONE) TO DO NOT CHANGE:";
        cin>>new_positive_mark;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            config_obj.set_positive_mark(positive_mark);
        }
        else if(new_positive_mark>=0 && new_positive_mark<=100)
        {
            config_obj.set_positive_mark(new_positive_mark);
        }
        else
        {
            config_obj.set_positive_mark(positive_mark);
        }
        cout<<"\nENTER MARKS TO BE DEDUCTED FOR WRONG ANSWER OR ENTER -1(MINUS ONE) TO DO NOT CHANGE:";
        cin>>new_negative_mark;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            config_obj.set_negative_mark(negative_mark);
        }
        else if(new_negative_mark>=0 && new_negative_mark<=100)
        {
            config_obj.set_negative_mark(new_negative_mark);
        }
        else
        {
            config_obj.set_negative_mark(negative_mark);
        }
        cout<<"\nENTER NUMBER OF QUESTIONS TO BE ASKED IN TEST OR ENTER -1(MINUS ONE) TO DO NOT CHANGE:";
        cin>>new_no_of_ques_to_ask;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            config_obj.set_no_of_ques_to_ask(no_of_ques_to_ask);
        }
        else if(new_no_of_ques_to_ask>=1 && new_no_of_ques_to_ask<=10)
        {
            config_obj.set_no_of_ques_to_ask(new_no_of_ques_to_ask);
            cin.ignore();
        }
        else
        {
            config_obj.set_no_of_ques_to_ask(no_of_ques_to_ask);
            cin.ignore();
        }

        config_file.write((char*)&config_obj,sizeof(config_obj));
        cout<<"\n\nCHANGES UPDATED SUCCESSFULLY\n\n";

        cout<<"PRESS ANY KEY TO GO BACK TO ADMIN PANEL";
        _getch();

        config_file.close();
        configure();
    }
    system("cls");
    professor_login();;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void databaseManager:: configure()
{
    Questions config_obj;
    fstream config_file;
    config_file.open("config.dat",ios::in|ios::binary);
    cout<<config_file;
    if(config_file)
    {
        config_file.read((char*)&config_obj,sizeof(config_obj));
        strcpy(password, config_obj.get_password());
        positive_mark=config_obj.get_positive_mark();
        negative_mark=config_obj.get_negative_mark();
        no_of_ques_to_ask=config_obj.get_no_of_ques_to_ask();

        //strcpy(app_file_name,config_obj.get_app_file_name());
        //strcpy(ques_file_name,config_obj.get_ques_file_name());
    }
    config_file.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void databaseManager:: show_questions_database()
{
    system("cls");
    Questions t3_question;
    //int t;
    ifstream fin;
    cout.setf(ios::left);
    cout<<"ID"<<setw(3)<<"COURSE"<<setw(11)<<"QUES"<<setw(11)<<"OPT1"<<setw(11)<<"OPT2"<<setw(11)<<"OPT3"<<setw(11)<<"OPT4"<<setw(2)<<"ANS"<<endl;
    for(int i=0; i<4; i++)
    {
        fin.open(ques_file_name[i], ios::binary|ios::in);

        while(fin.read((char*)&t3_question,sizeof(t3_question)))
        {
            cout.setf(ios::left);
            cout<<setw(3)<<t3_question.get_id();
            cout<<setw(3)<<t3_question.get_type();
            cout<<setw(16);
            t3_question.get_short_ques();
            cout<<' ';
            cout<<setw(11);
            t3_question.get_short_opt1();
            cout<<' ';
            cout<<setw(11);
            t3_question.get_short_opt2();
            cout<<' ';
            cout<<setw(11);
            t3_question.get_short_opt3();
            cout<<' ';
            cout<<setw(11);
            t3_question.get_short_opt4();
            cout<<' ';
            cout<<setw(2);
            cout<<t3_question.get_ans()<<endl;
        }
        fin.close();
        cout<<endl;
    }
    cin.ignore();
    cout<<"PRESS ANY KEY TO RETURN TO THE ADMIN PANEL";
    _getch();
    cout<<endl<<endl;

    system("cls"); professor_login();;
}
//////////////////////////////////////////////////////////////////////////////////////
void databaseManager:: enter_questions()
{
    Questions t_question;
    ofstream fout;
    char ask='y';

    cout<<"********************************************************************************"<<endl;
    cout<<"                              ::ENTER QUESTIONS::                               "<<endl<<endl;
    cout<<"********************************************************************************"<<endl;
    while(ask!='n')
    {
        cout<<"ENTER x TO STOP ELSE ANYTHING TO PROCEED TO ADD QUESTION: ";
        cin.ignore();
        cin.getline(add_q,100);
        if(strcmp(add_q,"X")==0 || strcmp(add_q,"x")==0)
        {
            ask='n';
            system("cls");
            professor_login();
        }
valid:
        cout<<"\nEnter the courseID (1.English, 2.Physics, 3.Chemistry, 4.Maths) : ";
        cin>>add_type;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"\nINVALID COURSEID";
            goto valid;
        }
        else if(add_type<1 || add_type>4)
        {
            system("cls");
            cout<<"\n\nPLEASE ENTER VALID COURSEID"<<endl;
            goto valid;
        }
        calc_no_of_questions(add_type);
        fout.open(ques_file_name[add_type-1], ios::app|ios::binary);

        t_question.set_type(add_type);

        cout<<"ENTER QUESTION : ";
        cin.ignore();
        cin.getline(add_q,100);
        t_question.set_ques(add_q);


        cout<<"OPTION 1 : ";
        cin.getline(add_o1,100);
        t_question.set_opt1(add_o1);
        cout<<"OPTION 2 : ";
        cin.getline(add_o2,100);
        t_question.set_opt2(add_o2);
        cout<<"OPTION 3 : ";
        cin.getline(add_o3,100);
        t_question.set_opt3(add_o3);
        cout<<"OPTION 4 : ";
        cin.getline(add_o4,100);
        t_question.set_opt4(add_o4);
input0:
        cout<<"ANSWER : ";
        cin>>add_a;
        if( cin.fail() )
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"\nEnter valid choice\n";
            goto input0;
        }
        else if(add_a<1 || add_a>4)
        {
            cout<<"\nIncorrect Choice\n";
            goto input0;
        }

        t_question.set_ans(add_a);
        t_question.set_id(++no_of_questions[add_type-1]);
        fout.write((char*)&t_question, sizeof(t_question));
        fout.close();
        calc_no_of_questions(add_type);
    }
    cin.ignore();
    cout<<"PRESS ANY KEY TO RETURN TO THE ADMIN PANEL";
    _getch();
    system("cls");

    professor_login();;
}
////////////?????????////////////////////////////////////////////////////////////////////////////////
void databaseManager:: edit_student()                 //exception handling
{
    Students ed_obj;
    fstream ed_file;
    ed_file.open(app_file_name,ios::in|ios::out|ios::binary);
    cout<<"\nNOTE : If any wrong credentials are entered, the data will remain unaltered\n\n";
    cout<<"ENTER VALID STUDENT NUMBER :"<<endl;
    cin>>ed_apno;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"********************************************************************************"<<endl;
        cout<<"STUDENT NOT FOUND!"<<endl;
        cout<<"********************************************************************************"<<endl;
        ed_file.close();
        cout<<"PRESS ANY KEY TO RETURN TO THE ADMIN PANEL";
        _getch();
        system("cls");
        professor_login();
    }
    int flag_ed=0;
    while(!ed_file.eof())
    {
        pos=ed_file.tellg();
        ed_file.read((char*)&ed_obj,sizeof(ed_obj));
        if(ed_obj.get_UserId()==ed_apno)
        {
            cout<<"ENTER NEW FIRST NAME OR ENTER X TO DO NOT CHANGE:";
            cin.ignore();
            cin.getline(ed_new_faname,50);
            //cin>>ed_new_faname;
            if((strcmp(ed_new_faname,"x")!=0)&&(strcmp(ed_new_faname,"X")!=0))
            {
                ed_obj.set_faname(ed_new_faname);
            }
            cout<<"ENTER NEW LAST NAME OR ENTER X TO DO NOT CHANGE:";
            cin.getline(ed_new_maname,50);
            //cin>>ed_new_maname;
            if((strcmp(ed_new_maname,"x")!=0)&&(strcmp(ed_new_maname,"X")!=0))
            {
                ed_obj.set_maname(ed_new_maname);
            }

            cout<<"ENTER NEW DATE OF BIRTH OR 0 TO DO NOT CHANGE"<<endl;
            cout<<"DATE:";
            cin>>ed_new_dob_d;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if(ed_new_dob_d>0 && ed_new_dob_d<32)
            {
                ed_obj.set_dob_d(ed_new_dob_d);
            }
            cout<<"MONTH:";
            cin>>ed_new_dob_m;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if(ed_new_dob_m>0 || ed_new_dob_m<13)
            {
                ed_obj.set_dob_m(ed_new_dob_m);
            }
            cout<<"YEAR:";
            cin>>ed_new_dob_y;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if(ed_new_dob_y>1900 || ed_new_dob_y<2017)
            {
                ed_obj.set_dob_y(ed_new_dob_y);
            }
            ed_file.seekg(pos);
            ed_file.write((char*)&ed_obj, sizeof(ed_obj));
            flag_ed=1;
            cout<<"STUDENT DETAILS SUCCESSFULLY CHANGED!"<<endl;

            break;
        }
    }
    if(!flag_ed)
    {

        cout<<"********************************************************************************"<<endl;
        cout<<"STUDENT NOT FOUND!"<<endl;
        cout<<"********************************************************************************"<<endl;
    }
    ed_file.close();

    cout<<"PRESS ANY KEY TO RETURN TO THE ADMIN PANEL";
    _getch();
    cin.ignore();
    system("cls");
    professor_login();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////

void databaseManager:: show_student_database()
{
    Students t3_student;
    ifstream fin;
    fin.open(app_file_name, ios::binary|ios::in);
    calc_no_of_Students();

    cout<<"TOTAL:"<<no_of_Students<<endl;
    cout.setf(ios::left);
    cout<<setw(3)<<"NO."<<setw(16)<<"F_NAME"<<setw(16)<<"L_NAME"<<setw(11)<<" DOB"<<setw(5)<<"RANK"<<setw(5)<<"NO. OF TEST APPEARED"<<endl;
    while(fin.read((char*)&t3_student,sizeof(t3_student)))
    {
        cout.setf(ios::left);
        cout<<setw(3)<<t3_student.get_UserId();
        cout<<setw(16);
        t3_student.get_short_faname();
        cout<<setw(10);
        cout<<' ';
        t3_student.get_short_maname();
        cout<<' ';
        cout.setf(ios::right);
        cout<<' '<<setw(2)<<setfill('0')<<t3_student.get_dob_d()<<"-"<<setw(2)<<setfill('0')<<t3_student.get_dob_m()<<"-"<<setw(4)<<setfill('0')<<t3_student.get_dob_y()<<' '<<setfill(' ');
        cout.setf(ios::left);
        if(t3_student.get_rank()>0)
        {
            cout<<setw(5)<<t3_student.get_rank();
        }
        else
        {
            cout<<setw(5)<<"N/A";
        }
        cout<<setw(4)<<t3_student.no_of_appeared_tests<<endl;
        /*
        if(t3_student.get_marks()!=-500)
        {
            cout<<setw(4)<<t3_student.get_marks()<<endl;
        }
        else
        {
            cout<<setw(4)<<"N/A"<<endl;
        }
        */
    }
    fin.close();
    cout<<endl;
    cout<<"PRESS ANY KEY TO RETURN TO THE ADMIN PANEL";
    _getch();
    system("cls");
    cin.ignore();

    professor_login();;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void databaseManager:: get_result()
{
    system("cls");
    Students t2_student;
    ifstream fin;
    fin.open(app_file_name,ios::in|ios::binary);

Sno2:
    cout<<"ENTER VALID STUDENT NUMBER :"<<endl;
    cin>>apno;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto Sno2;
    }
    cout<<"ENTER DATE OF BIRTH : \n";
day3:
    cout<<"ENTER VALID DAY (e.g., 1, 2, 3, 4, ....30, 31 ) : ";
    cin>>get_d;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto day3;
    }

    cout<<"ENTER VALID MONTH (e.g., 1, 2, 3, 4, ....11, 12 ) : ";
    cin>>get_m;
    if(cin.fail())
    {
month3:
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto month3;
    }

year3:
    cout<<"ENTER VALID YEAR (e.g., 1901, ...2015, 2016 ) : ";
    cin>>get_y;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto year3;
    }

    int flag=0;
    while(fin.read((char *)&t2_student,sizeof(t2_student)))
    {
        if(t2_student.get_UserId()==apno&&t2_student.get_dob_d()==get_d&&t2_student.get_dob_m()==get_m&&t2_student.get_dob_y()==get_y)
        {
            system("cls");
            cout<<"********************************************************************************"<<endl;
            cout<<"                                   ::RESULT::                                   "<<endl<<endl;
            cout<<"********************************************************************************"<<endl;
            cout<<"STUDENT NUMBER : "<<t2_student.get_UserId()<<endl;
            cout<<endl;
            cout<<"FIRST NAME : ";
            t2_student.get_faname();
            cout<<endl;
            cout<<"LAST NAME : ";
            t2_student.get_maname();
            cout<<endl;
            cout<<"DATE OF BIRTH : "<<t2_student.get_dob_d()<<"-"<<t2_student.get_dob_m()<<"-"<<t2_student.get_dob_y()<<endl;
            if(t2_student.get_rank()!=-1)
            {
                calc_no_of_Students();
                cout<<"RANK : "<<t2_student.get_rank()<<" OUT OF "<<no_of_Students<<endl;
            }
            else
            {
                cout<<"RANK NOT ASSIGNED"<<endl;
            }
            cout<<endl;
            t2_student.show_result();
            cout<<endl;
            /*if(t2_student.get_marks()!=-500)
            {
                cout<<"MARKS : "<<t2_student.get_marks()<<" OUT OF "<<no_of_ques_to_ask*positive_mark<<endl;
                cout<<"********************************************************************************"<<endl;
            }
            else
            {
                cout<<"MARKS NOT ASSIGNED"<<endl;
                cout<<"********************************************************************************"<<endl;
            }*/
            flag=1;
            break;
        }
    }
    if(!flag)
    {

        cout<<"********************************************************************************"<<endl;
        cout<<"                             STUDENT NOT FOUND!                                 "<<endl;
        cout<<"********************************************************************************"<<endl;
    }
    fin.close();
    cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
    _getch();
    system("cls");
    main();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void databaseManager:: give_test()
{
    system("cls");
    Students test_student;
    fstream fin;
    fin.open(app_file_name,ios::in|ios::out|ios::binary);

    int n;
    cout<<"SELECT THE COURSE :\n\n";
    cout<<"1.ENGLISH\n";
    cout<<"2.PHYSICS\n";
    cout<<"3.CHEMISTRY\n";
    cout<<"4.MATHS\n";
    cout<<"\nEnter the course number : ";
retry3:
    cin>>n;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"\nPlease enter a valid course number (between 1-4) : ";
        goto retry3;
    }
    else if(n<1 || n>4)
    {
        cout<<"Please enter a valid course number (between 1-4) :";
        goto retry3;
    }

    calc_no_of_questions(n);
    if(no_of_questions[n-1]<no_of_ques_to_ask)
    {
        cout<<"********************************************************************************"<<endl;
        cout<<"INSUFFICIENT QUESTION IN DATABASE. CONTACT ADMINISTRATOR"<<endl;
        cout<<"********************************************************************************"<<endl;
        cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
        _getch();
        cout<<endl;
        main();
    }
Sno:
    cout<<"ENTER YOUR VALID STUDENT NUMBER :"<<endl;
    cin>>t_apno;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto Sno;
    }
    cout<<"ENTER DATE OF BIRTH : \n";
    do
    {
day2:
        cout<<"ENTER VALID DAY (e.g., 1, 2, 3, 4, ....30, 31 ) : ";
        cin>>t_dob_d;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto day2;
        }
    }
    while(!((t_dob_d>0)&&(t_dob_d<32)));
    do
    {
        cout<<"ENTER VALID MONTH (e.g., 1, 2, 3, 4, ....11, 12 ) : ";
        cin>>t_dob_m;
        if(cin.fail())
        {
month2:
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto month2;
        }
    }
    while(!((t_dob_m>0)&&(t_dob_m<13)));
    do
    {
year2:
        cout<<"ENTER VALID YEAR (e.g., 1901, ...2015, 2016 ) : ";
        cin>>t_dob_y;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto year2;
        }
    }
    while(!((t_dob_y>1900)&&(t_dob_y<3000)));
    int flag=0;
    while (!fin.eof())
    {
        pos2=fin.tellg();
        fin.read((char*)&test_student,sizeof(test_student));
        if(test_student.get_UserId()==t_apno&&test_student.get_dob_d()==t_dob_d&&test_student.get_dob_m()==t_dob_m&&test_student.get_dob_y()==t_dob_y)
        {
            flag=1;
            cout<<endl;
            break;
        }
    }
    if(flag==1)
    {
        int corrAns_count=0;
        int incorrAns_count=0;
        system("cls");
        test_count++;
        cout<<"TESTID : "<<test_count;
        cout<<"\n\nINSTRUCTIONS : \n1. EACH QUESTION HAS SINGLE CORRECT ANSWER \n2. TEST CONSISTS OF "<<no_of_ques_to_ask<<" QUESTIONS \n3. EACH QUESTION CARRIES +"<<positive_mark<<" MARKS AND -"<<negative_mark<<" MARKS \n4. OPTION ENTERED OTHER THAN 1,2,3,4 WILL BE TAKEN AS WRONG ANSWER UNLESS SPECIFIED";
        cout<<"\n\nALL THE BEST !\n\n";
        Questions t_obj;
        ifstream t_ques;
        t_ques.open(ques_file_name[n-1],ios::in|ios::binary);
        time_t t;
        int seedval= (unsigned) time (&t);
        srand(seedval);
        int marks = 0;
        test_student.set_result(test_count,0);
        int qno;
        int ans;
        for(int i=0; i<5; i++)
        {
nextQues:
            qno=rand()%no_of_questions[n-1]+1;
            while(t_ques.read((char*)&t_obj, sizeof(t_obj)))
            {

                if(t_obj.get_id()==qno && t_obj.get_type()==n)
                {
                    cout<<"********************************************************************************"<<endl;
                    cout<<"Q"<<i+1<<". ";
                    t_obj.get_ques();
                    cout<<endl;
                    //cout<<"********************************************************************************"<<endl;
                    cout<<endl;
                    cout<<"OPTIONS"<<endl<<"1. ";
                    t_obj.get_opt1();
                    cout<<endl;
                    cout<<"2. ";
                    t_obj.get_opt2();
                    cout<<endl;
                    cout<<"3. ";
                    t_obj.get_opt3();
                    cout<<endl;
                    cout<<"4. ";
                    t_obj.get_opt4();
                    cout<<endl;
retry4:
                    cout<<"ENTER VALID ANSWER: ( 1, 2, 3, 4 ) OR 0(ZERO TO SKIP THIS QUESTION) : ";
                    cin>>ans;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        goto retry4;
                    }

                    if (ans==0)
                    {
                        cout<<"Do you want to end the test? Press y or n : ";
                        char end_test[50];
                        cin>>end_test;
                        if(strcmp(end_test,"y")==0||strcmp(end_test,"Y")==0)
                        {
                            goto finish;
                        }
                        else if(strcmp(end_test,"n")==0||strcmp(end_test,"N")==0)
                        {
                            i++;
                            cout<<endl;
                            goto nextQues;
                        }
                        else
                        {
                            cout<<"TEST ABORTED DUE TO INVALID INPUT\n";
                            goto finish;
                        }
                    }
                    else if(t_obj.get_ans()==ans)
                    {
                        marks = marks + positive_mark;
                        corrAns_count++;
                    }
                    else
                    {
                        marks = marks - negative_mark;
                        incorrAns_count++;
                    }
                    break;
                }
            }
            t_ques.seekg(0);
        }
finish:
        cout << "\n\n MARKS OBTAINED : " << marks << endl;
        cout<<"OUT OF "<<no_of_ques_to_ask<<" QUESTIONS, NO. OF CORRECT ANSWERS = "<<corrAns_count<<" AND NO.OF INCORRECT ANSWERS = "<<incorrAns_count<<endl<<endl;
        test_student.set_result(test_count,marks);
        test_student.no_of_appeared_tests++;
        fin.seekg(pos2);
        fin.write((char*)&test_student,sizeof(test_student));
        t_ques.close();
        fin.close();
    }
    if(flag==0)
    {
        cout<<endl;
        cout<<"********************************************************************************"<<endl;
        cout<<"STUDENT NOT FOUND!"<<endl;
        cout<<"********************************************************************************"<<endl<<endl;
    }
    //assign_rank();

    cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
    _getch();
    system("cls");
    main();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void databaseManager:: register_now()
{
    system("cls");

    Students t_student;
    ofstream fout;
    //t_student.set_result(0,0);
    t_student.set_rank(-1);

    fout.open(app_file_name, ios::app|ios::binary);
    cout<<"********************************************************************************"<<endl;
    cout<<"                              ::APPLICATION FORM::                              "<<endl;
    cout<<"********************************************************************************"<<endl;


    cout<<"\nFirst Name and Last Name can be of max 50 characters\n\n";
    cout<<"First Name : ";
    cin.ignore();
    cin.getline(fa,50);
    t_student.set_faname(fa);
    cout<<"Last Name : ";
    cin.getline(ma,50);
    t_student.set_maname(ma);
    cout<<"DATE OF BIRTH : \n";
    do
    {
day:
        cout<<"ENTER VALID DAY (e.g., 1, 2, 3, 4, ....30, 31 ) : ";
        cin>>dd;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto day;
        }
    }
    while(!((dd>0)&&(dd<32)));
    t_student.set_dob_d(dd);
    do
    {
        cout<<"ENTER VALID MONTH (e.g., 1, 2, 3, 4, ....11, 12 ) : ";
        cin>>dm;
        if(cin.fail())
        {
month:
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto month;
        }
    }
    while(!((dm>0)&&(dm<13)));
    t_student.set_dob_m(dm);
    do
    {
year:
        cout<<"ENTER VALID YEAR (e.g., 1901, ...2015, 2016 ) : ";
        cin>>dy;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto year;
        }
    }
    while(!((dy>1900)&&(dy<3000)));
    t_student.set_dob_y(dy);
    calc_no_of_Students();
    t_student.set_UserId(no_of_Students+1);
    fout.write((char*)&t_student, sizeof(t_student));
    fout.close();
    calc_no_of_Students();
    system("cls");
    cout<<"********************************************************************************"<<endl;
    cout<<"                                ::YOUR DETAILS::                                "<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"FORM SUCCESSFULLY SUBMITTED!"<<endl;
    cout<<"STUDENT NUMBER : "<<t_student.get_UserId()<<endl;
    cout<<"FIRST NAME : ";
    t_student.get_faname();
    cout<<endl;
    cout<<"LAST NAME : ";
    t_student.get_maname();
    cout<<endl;
    cout<<"DATE OF BIRTH:"<<t_student.get_dob_d()<<"-"<<t_student.get_dob_m()<<"-"<<t_student.get_dob_y()<<endl;
    cout<<endl<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
    _getch();
    cout<<endl<<endl;
    main();
}
///////////////////////////////////////////////////////////////////////////////////////////////////
#endif
