#include<iostream>
#include<string>
#include <fstream>


#include "hash.h"

using namespace std;

int fileInput(HashTable&);
int showMenu();
void get(HashTable&);

int main() {

	int choice;
	HashTable studentID;
	fileInput(studentID);


	do
	{

		choice = showMenu();
		switch (choice)
		{
		case 1: get(studentID);
			break;
		}
	} while (choice != 2);
	cout << "Good Bye!";
	return 0;



}


int fileInput(HashTable &studentID) {
	int count = 0, tmpkey = 0;
	string tmpstring;

	ifstream input;
	input.open("students.txt");

	if (input.fail()) {
		cerr << "Could not open file!" << endl;
		exit(1);
	}
	while (input >> tmpkey) {
		getline(input, tmpstring);
		tmpstring.erase(tmpstring.begin());
		studentID.insert(tmpkey, tmpstring);
		count++;
	}
	
	return count;
	input.close();
}


int showMenu()
{
	int select;

	cout << "\nMenu\n";
	cout << "========\n";
	cout << "1. Search for a student\n";
	cout << "2. Exit\n";
	cout << "Enter choice: ";
	cin >> select;
	cin.ignore();
	return select;
}

void get(HashTable& studentID) {
	int tmpID, tmpvalue;
	cout << "Enter student ID" << endl;
	cin >> tmpID;
	cout << studentID.retrieve(tmpID) << endl;

}