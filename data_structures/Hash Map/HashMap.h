#pragma once
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int TABLE_SIZE = 128;

class HashEntry
{
public:
	int key;
	int value;
	HashEntry(int key, int value)
	{
		this->key = key;
		this->value = value;
	}
};

class HashMap
{
	HashEntry **table;
public:
	HashMap();
	int HashFunc(int key);
	void Insert(int key, int value);
	int Search(int key);
	void Remove(int key);
	~HashMap();
};
