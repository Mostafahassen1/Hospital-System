#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <string>

using namespace std;

 const int MAX_specification = 20 ;
 const int MAX_queue = 5 ;

extern string nmaes[MAX_specification+1][MAX_queue+1];
extern int status[MAX_specification+1][MAX_queue+1];
extern int Lingth_queu[MAX_specification+1];

void shift_right(int spe, string names[], int status[]);
void shift_left(int check, string names[], int status[]);
void Get_next_patient();
void print_all_patients();
bool Add_new_patient();
int menu();
int System_hospital();

#endif
