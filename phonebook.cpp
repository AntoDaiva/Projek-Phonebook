/**
 * Project Untitled
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "phonebook.h"


using namespace std;
/**
 * phonebook implementation
 */


void phonebook::AddContact(string file_n) {
	cout<< "--------------------------------" << endl; 
	cout << "Membuat Kontak Baru..."<< endl;
	InputData();

	bool found = false;//cek duplicate kontak
	found = Search(Nama, file_n);
	if (found == true) {
		cout << "--------------------------------" << endl;
		cout << "kontak dengan nama tersebut sudah ada" << endl;
		return;
	}

	fstream F;//masukkan ke file pb
	F.open(file_n, ios::app);
	F << Nama << endl << Nomor << endl << Alamat << endl << Email << endl << endl;
	F.close();

	cout << "--------------------------------" << endl;
	cout << "kontak telah ditambah" << endl;
}

void phonebook::DeleteContact(string file_n) {
	cout << endl << "Nama kontak yang ingin dihapus: ";//prompt nama kontak
	cin >> Nama;

	bool found = false;//cek keadaan kontak
	found = Search(Nama, file_n);
	if (found == false) {
		cout << "--------------------------------" << endl;
		cout << "kontak dengan nama tersebut tidak ada" << endl;
		return;
	}

	//logic yang sama dengan delete phonebook namun diubah sedikit
	string file_pb = file_n; 
	string file_temp = "temp.txt";
	string Line;
	const char* arr_file_pb = file_pb.c_str();
	const char* arr_file_temp = file_temp.c_str();
	int i = 0;

	remove(arr_file_temp);//buat data yang sudah diedit ke temp
	ifstream F;
	fstream temp;
	F.open(file_pb);
	temp.open(file_temp, ios::app);
	while (getline(F, Line)) {
		if (Line != Nama && i == 0)
			temp << Line << endl;
		else if (Line == Nama)
			i += 5;
		if (i > 0)
			i -= 1;
	}
	F.close(); temp.close();

	remove(arr_file_pb);//hapus file list lama
	rename(arr_file_temp, arr_file_pb);//rename file temp menjadi list phonebook

	cout << "kontak telah dihapus"<< endl;
}

void phonebook::EditContact(string file_n) {
	string kontak;
	cout << "nama kontak yang akan diedit: ";//prompt nama kontak
	cin >> kontak;
	bool found = false;
	found = Search(kontak, file_n);

	cout << "--------------------------------" << endl;
	if (found == false) {
		cout << "kontak tidak ditemukan\n";
		return;
	}
	else {
		cout << "kontak diedit menjadi..." << endl;
		InputData();

		string file_pb = file_n;
		string file_temp = "temp.txt";
		string Line;
		const char* arr_file_pb = file_pb.c_str();
		const char* arr_file_temp = file_temp.c_str();
		int i = 0;
		int count = 0;

		remove(arr_file_temp);//buat data yang sudah diedit ke temp
		ifstream F;
		fstream temp;
		F.open(file_pb);
		temp.open(file_temp, ios::app);
		while (getline(F, Line)) {//logic campuran dari delete phonebook dan search phonebook
			if (Line != kontak && i == 0)
				temp << Line << endl;

			switch (count) {
			case 1:
				temp << Nomor<< endl;
				count++;
				break;
			case 2:
				temp << Alamat<< endl;
				count++;
				break;
			case 3:
				temp << Email<< endl;
				count = 0;
				break;
			}
			if (Line == kontak) {
				temp << Nama<< endl;
				count = 1;
				i += 4;
			}
			if (i > 0)
				i -= 1;
		}
		F.close(); temp.close();

		remove(arr_file_pb);//hapus file list lama
		rename(arr_file_temp, arr_file_pb);//rename file temp menjadi list phonebook


	}

	cout << "contact edited"<<endl;
}

void phonebook::Contactlist(string file_n) {
	
	string Line;
	int count = 1;
	int contact_count = 1;

	cout << "--------------------------------" << endl;
	ifstream F;
	F.open(file_n);
	while (getline(F, Line)) {
		
		switch (count){
		case 1:
			Nama = Line;
			break;
		case 2:
			Nomor = Line;
			break;
		case 3:
			Alamat = Line;
			break;
		case 4:
			Email = Line;
			cout << contact_count << ".\n";
			cout << "Nama\t: " << Nama << "\nAlamat\t: " << Alamat <<
				"\nNomor\t: " << Nomor << "\nEmail\t: " << Email<< endl<< endl;
			contact_count++;
			break;
		}
		if (count > 4)
			count = 0;
		count++;
	}


	cout << "contact listed"<< endl;
}

void phonebook::SearchContact(string file_n) {
	bool found = false;
	cout << "masukkan nama yang dicari: ";//prompt nama kontak
	cin >> Nama;
	found = Search(Nama, file_n);//cari nama

	cout << "--------------------------------" << endl;
	if (found == true) {//display kontak
		string Line;
		int count = 0;
		ifstream F;
		F.open(file_n);
		while (getline(F, Line)) {
			switch (count) {
			case 1:
				Nomor = Line;
				count++;
				break;
			case 2:
				Alamat = Line;
				count++;
				break;
			case 3:
				Email = Line;
				cout << "Nama\t: " << Nama << "\nAlamat\t: " << Alamat <<
					"\nNomor\t: " << Nomor << "\nEmail\t: " << Email << endl << endl;
				count = 0;
				break;
			}
			if (Line == Nama) {
				count = 1;
			}
		}
		F.close();
	}
	else
		cout << "kontak tidak ditemukan\n";
}

void phonebook::InputData() {
	cout << "Nama: ";
	cin >> Nama;
	cout << "Nomor: ";
	cin >> Nomor;
	cout << "Alamat: ";
	cin >> Alamat;
	cout << "Email: ";
	cin >> Email;
}

bool phonebook::Search(string nama, string file_n) {
	string Line;

	ifstream check_F;//cek ketersediaan username
	check_F.open(file_n);
	while (getline(check_F, Line)) {
		if (Line == nama) {
			return true;
		}
	}
	return false;
}

