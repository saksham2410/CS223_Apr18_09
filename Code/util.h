#ifndef UTIL_H
#define UTIL_H
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include<cstdio>
#include<limits.h>
#include<bits/stdc++.h>
#include<sstream>
#include<unistd.h>
#include<cstdlib>
#include<ctime>
using namespace std;
/*
// as getch was not working in linux beacuse it does not support conio.h

char _getch(){

  struct termios oldt, newt;
  int ch;
  tcgetattr (STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr (STDIN_FILENO, TCSANOW, &newt);
  ch = getchar ();
  tcsetattr (STDIN_FILENO, TCSANOW, &oldt);
  return ch;
};
*/

int main_menu_choice;
int dd,dm,dy;
char na[50], fa[50], ma[50];
int no_of_Students=0;
int apno, get_d, get_m, get_y;
char pass[30];
int admin_menu_choice;
int ed_apno, ed_new_dob_d, ed_new_dob_m, ed_new_dob_y;
char ed_new_name[50], ed_new_faname[50], ed_new_maname[50];
int pos;
int no_of_questions[4]= {0};

char add_q[100], add_o1[100], add_o2[100], add_o3[100], add_o4[100];
int add_a,add_type;
int t_apno, t_dob_d, t_dob_m, t_dob_y;
int pos2;
int marks[500];
int pos3;
int negative_mark=1;
int positive_mark = 5;
int no_of_ques_to_ask=5;
char password[30]="password";
char app_file_name[30]="STUDENT.DAT";
char ques_file_name[4][30]= {"ENGLISH_QUES.DAT","PHYSICS_QUES.DAT","CHEM_QUES.DAT","MATHS_QUES.DAT"};
int new_negative_mark;
int new_positive_mark;
int new_no_of_ques_to_ask;
char new_password[30];
char new_app_file_name[30];
char new_ques_file_name[30];
int test_count=0;

int main();
void assign_rank();
void calc_no_of_questions(int);
void calc_no_of_Students();
void professor_login();

#include"user.cpp"
#include"Students.cpp"
#include"Question.cpp"
#include"professor.cpp"
#include"Functions.cpp"

#endif
