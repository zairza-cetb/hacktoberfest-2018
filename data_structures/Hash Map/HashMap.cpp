#include "HashMap.h"



HashMap::HashMap()
{
	table = new HashEntry *[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		table[i] = NULL;
	}
}

int HashMap::HashFunc(int key)
{
	return key % TABLE_SIZE;
}
void HashMap::Insert(int key, int value)
{
	int hash = HashFunc(key);
	while (table[hash] != NULL && table[hash]->key != key)
	{
		hash = HashFunc(hash + 1);
	}
	if (table[hash] != NULL)
		delete table[hash];
	table[hash] = new HashEntry(key, value);
}

int HashMap::Search(int key)
{
	int  hash = HashFunc(key);
	while (table[hash] != NULL && table[hash]->key != key)
	{
		hash = HashFunc(hash + 1);
	}
	if (table[hash] == NULL)
		return -1;
	else
		return table[hash]->value;
}

void HashMap::Remove(int key)
{
	int hash = HashFunc(key);
	while (table[hash] != NULL)
	{
		if (table[hash]->key == key)
			break;
		hash = HashFunc(hash + 1);
	}
	if (table[hash] == NULL)
	{
		cout << "No Element found at key " << key << endl;
		return;
	}
	else
	{
		delete table[hash];
	}
	cout << "Element Deleted" << endl;
}

HashMap::~HashMap()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i] != NULL)
			delete table[i];
		delete[] table;
	}
}
