#include"util.h"
#ifndef USER
#define USER
class User
{

public:
    int UserId;
    char first_name[50];
    char last_name[50];
    int get_UserId()
    {
        return UserId;
    }
    void get_faname()
    {
        cout<<first_name;
    }
    void get_maname()
    {
        cout<<last_name;
    }
    void set_maname(char ma[])
    {
        strcpy(last_name,ma);
    }
    void set_faname(char fa[])
    {
        strcpy(first_name,fa);
    }

};
#endif
