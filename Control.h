/**
 * Project Untitled
 */
#include <string>
#ifndef _CONTROL_H
#define _CONTROL_H
using namespace std;

class Control {
public: 
    string username = "";
    string password = "";
    
void MakePhonebook();
    
void ChoosePhonebook();
    
void DeletePhonebook();
    
void CommandLoop();
    
void PhonebookLoop(string file_n);

bool Search_Verif(string username, string password);

};

#endif //_CONTROL_H
