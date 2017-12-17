#ifndef HASH_H
#define	HASH_H

#include <cstddef>

using namespace std;

struct Student {
	int ID;
	string name;
};

class HashEntry {
private:
	Student student;
public:
	HashEntry(int key, string value) {
		this->student.ID = key;
		this->student.name = value;
		
	}

	int getID() {
		return student.ID;
	}

	string getName() {
		return student.name;
	}
};

const int TABLE_SIZE = 128;

class HashTable {
private:
	HashEntry **table;
public:
	HashTable() {
		table = new HashEntry*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}

	string retrieve(int ID) {
		int hash = (ID % 100);
		while (table[hash] != NULL && table[hash]->getID() != ID)
			hash = (hash + 1);
		if (table[hash] == NULL)
			return "No ID found";
		else
			return table[hash]->getName();
	}
	
	void insert(int ID, string name) {
		int hash = (ID % 100);
		while (table[hash] != NULL && table[hash]->getID() != ID)
			hash = (hash + 1);
		if (table[hash] != NULL)
			delete table[hash];
		table[hash] = new HashEntry(ID, name);
	}

	~HashTable() {
		for (int i = 0; i < TABLE_SIZE; i++)
			if (table[i] != NULL)
				delete table[i];
		delete[] table;
	}
};

#endif