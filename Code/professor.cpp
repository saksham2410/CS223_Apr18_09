#include"util.h"
#include"databaseManager.cpp"
#ifndef PROFESSOR
#define PROFESSOR

class professor : public User
{
    char PASSWORD[50];
public:
    void setPass(char P[])
    {
        strcpy(PASSWORD,P);
    }
    char* getPassword()
    {
        return PASSWORD;
    }

    void viewQuestions()
    {
        databaseManager db;
        db.show_questions_database();
    }

    void viewStudents()
    {
        databaseManager db;
        db.show_student_database();
    }
};



#endif
