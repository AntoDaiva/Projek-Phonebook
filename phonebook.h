

#include <string>
using namespace std;
#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

class phonebook {
public: 
    string Nama;
    string Nomor;
    string Alamat;
    string Email;
    
void AddContact(string file_n);
    
void DeleteContact(string file_n);
    
void EditContact(string file_n);
    
void Contactlist(string file_n);
    
void SearchContact(string file_n);

//fungsi tambahan

void InputData();

bool Search(string nama, string file_n);

};

#endif //_PHONEBOOK_H
