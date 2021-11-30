/**
 * Project Untitled
 */

#include <iostream>
#include "Control.h"
#include "phonebook.h"

using namespace std;
/**
 * Control implementation
 */


void Control::MakePhonebook() {
	cout << "phonebook terbuat"<< endl;
}

void Control::ChoosePhonebook() {
	cout << "phonebook terpilih" << endl;
}

void Control::DeletePhonebook() {
	cout << "phonebook terhapus" << endl;
}

void Control::CommandLoop() {
	int u_input;
	do {
		cout << "--------------------------------" << endl;
		cout << "1. Make Phonebook" << endl;
		cout << "2. Choose Phonebook" << endl;
		cout << "3. Delete PHonebook" << endl;
		cout << "--------------------------------" << endl;
		cout << "input: ";
		cin >> u_input;
		switch (u_input) {
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

	} while ((u_input == 1) || (u_input == 2) || (u_input == 3)); {
	}
}

void Control::PhonebookLoop() {

}