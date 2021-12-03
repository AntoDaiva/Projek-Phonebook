
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "Control.h"
#include "phonebook.h"

phonebook pb;
using namespace std;
/**
 * Control implementation
 */


void Control::MakePhonebook() {
	bool found = false;
	string Line;
	cout << "masukkan username: ";//set username
	cin >> username;

	ifstream check_F;//cek ketersediaan username
	check_F.open("list phonebook.txt");
	while (getline(check_F, Line)) {
		if (Line == username) {
			found = true;
		}
	}
	if (found == true) {
		cout << "----username sudah terpakai----" << endl<<endl;
		return;
	}

	cout << "masukkan password: ";//set password
	cin >> password;

	fstream F;//masukkan ke list phonebook
	F.open("list phonebook.txt", ios::app);
		F << username << endl <<password << endl<<endl;
		cout << "phonebook terbuat"<< endl;
	F.close();

	string nama_file = "pb " + username + ".txt";//buat phonebook baru
	F.open(nama_file, ios::out);

}

void Control::ChoosePhonebook() {
	bool verif;

	cout << "masukkan username: ";
	cin >> username;
	cout << "masukkan password: ";
	cin >> password;

	verif = Search_Verif(username, password);//cari dan verifikasi phonebook yang dipilih
	string nama_file = "pb " + username + ".txt";
	if (verif == true) {
		PhonebookLoop(nama_file);
	}
}

void Control::DeletePhonebook() {

	cout << "masukkan username: ";
	cin >> username;
	cout << "masukkan password: ";
	cin >> password;
	
	bool verif = Search_Verif(username, password);//cari dan verifikasi
	
	string file_list = "list phonebook.txt";
	string file_temp = "temp.txt";
	string Line;
	const char* arr_file_list = file_list.c_str();
	const char* arr_file_temp = file_temp.c_str();
	int i=0;

	if (verif == true) {
		remove(arr_file_temp);//buat data yang sudah diedit ke temp
		ifstream F;
		fstream temp;
		F.open(file_list);
		temp.open(file_temp, ios::app);
		while (getline(F, Line)) {
			if (Line != username && i==0)
				temp << Line<< endl;
			else if(Line == username)
				i += 3;
			if (i > 0)
				i -= 1;
		}
		F.close(); temp.close();

		remove(arr_file_list);//hapus file list lama
		rename(arr_file_temp, arr_file_list);//rename file temp menjadi list phonebook
	
		string nama_file = "pb " + username + ".txt";//hapus file phonebook dengan nama tersebut
		const char* file_n = nama_file.c_str();
		remove(file_n);
		cout << "phonebook terhapus" << endl<<endl;

	}
}

void Control::CommandLoop() {
	int user_input;
	do {
		cout << "-----------------------------------------------------" << endl;
		cout << "||1. Buat Phonebook\t\t\t\t   ||" << endl;
		cout << "||2. Buka Phonebook\t\t\t\t   ||" << endl;
		cout << "||3. Hapus PHonebook\t\t\t\t   ||" << endl;
		cout << "||(tekan tombol lainnya untuk menghentikan program)||" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "input: ";
		cin >> user_input;
		switch (user_input) {
		case 1:
			MakePhonebook();
			break;
		case 2:
			ChoosePhonebook();
			break;
		case 3:
			DeletePhonebook();
			break;
		}

	} while ((user_input == 1) || (user_input == 2) || (user_input == 3)); {
	}
}

void Control::PhonebookLoop(string file_n) {
	int user_input;
	do {
		cout << "----------------------------------------------------" << endl;
		cout << "|1. Tambah Kontak\t\t\t\t   |" << endl;
		cout << "|2. Hapus Kontak\t\t\t\t   |" << endl;
		cout << "|3. Edit Kontak\t\t\t\t\t   |" << endl;
		cout << "|4. List Kontak\t\t\t\t\t   |" << endl;
		cout << "|5. Cari Kontak\t\t\t\t\t   |" << endl;
		cout << "|((tekan tombol lainnya untuk menghentikan program)|" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "input: ";
		cin >> user_input;
		switch (user_input) {
		case 1:
			pb.AddContact(file_n);
			break;
		case 2:
			pb.DeleteContact(file_n);
			break;
		case 3:
			pb.EditContact(file_n);
			break;
		case 4:
			pb.Contactlist(file_n);
			break;
		case 5:
			pb.SearchContact(file_n);
			break;
		}

	} while ((user_input == 1) || (user_input == 2) || (user_input == 3) || (user_input == 4) || (user_input == 5)); {
	}
	exit(0);
	return;
}

bool Control::Search_Verif(string un, string pw) {
	string Line;
	bool found = false;
	bool status = false;

	ifstream F;
	F.open("list phonebook.txt");
	while (getline(F, Line)) {
		if (found == true) {
			if (Line == pw)
				status = true;
		}
		if (Line == un) {
			found = true;
		}
	}
	F.close();

	if (found == true) {
		if (status == true) {
			cout << "password benar" << endl;
			return true;
		}
		else{
			cout << "password salah" << endl;
			return false;
		}
	}
	else {
		cout << "username tidak ditemukan";
		return false;
	}
}
	
