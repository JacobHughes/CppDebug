/*=======================================================
	Code written by Jacob Hughes

	Copyright (C) Jacob Hughes 2015

	Contact for use:

	yacolt@gmail.com
	https://github.com/JacobHughes/
=======================================================*/


#pragma once

#include "HashBucket.h"

#include <vector>
#include <string>
#include <memory>
#include <ostream>
#include <iostream>
#include <typeinfo>

using namespace std;

template <typename K, typename V>
class HashTable
{
	/*
		This is my implementation of a generic template class for
		a hash table. Type K is the key-type, and V is the data.
		This allows any object as the Key or Value.

		This implemenation uses a 2D-array for the hash table, 
		implented with vectors of HashBucket objects.

		The HashBucket objects hold and generate hash keys, as well
		as holding the data.

		This implementation will count the number of collisions, 
		and report the load factor of the HashTable.
	
	*/
public:
	//Constructor - set the size of the table
	HashTable(int tableSize)
	{
		this->tableSize = tableSize;
		this->table.resize(this->tableSize);
	}
	
	//Destructor - default
	~HashTable(){}

	//Function to find data based on the key
	HashBucket<K, V>* find(K key)
	{
		//Get a temporary bucket to generate a key
		HashBucket<K, V> tempBucket;
		tempBucket.setKey(key);
		
		//Find the index of this key
		int index = tempBucket.getHash(this->tableSize);

		//Loop through all the data stored in the index
		for (int i = 0; i < table[index].size(); ++i)
		{
			//If the key matches..
			if (this->table[index][i].getKey() == key)
			{
				//...return the HashBucket object
				return &this->table[index][i];
			}
		}

		//Return NULL since nothing matched our search
		return NULL;
	}


	//Function to find data with the key and value known
	HashBucket<K, V>* find(K key, V value)
	{
		//Get a temporary bucket to generate a key
		HashBucket<K, V> tempBucket;
		tempBucket.setKey(key);

		//Find the index of this key
		int index = tempBucket.getHash(this->tableSize);

		//Loop through all the data stored in the index
		for (int i = 0; i < this->table[index].size(); ++i)
		{
			//if the key AND value matches...
			if (this->table[index][i].getKey() == key && this->table[index][i].getValue() == value)
			{
				//...return the HashBucket object
				return &this->table[index][i];
			}
		}

		//Return NULL since nothing matched our search
		return NULL;
	}

	//Function to erase a bucket
	void erase(HashBucket<K, V> * pos)
	{
		//If we are handed a NULL pointer, invalid
		if (pos == NULL) { return; }

		//Find the index of the bucket
		int index = pos->getHash(this->tableSize);

		//Loop variable
		int i = 0;

		//Loop around to find the index of our bucket
		while (&this->table[index][i] != pos && i < this->table[index].size())
		{
			++i;
		}

		//Move any other objects with the same index forwards
		for (int j = i; j < this->table[index].size() - 1; ++j)
		{
			this->table[index][j] = this->table[index][j + 1];
		}

		//Then pop-back to delete our specific bucket
		this->table[index].pop_back();

		//Decrement the number of entries
		--entryCounter;
	}

	//Function to insert to the table
	void insert(K key, V value)
	{
		//Create a new bucket to hold the value
		HashBucket<K, V> bucket(key, value);
		
		//Find the insertion index
		int index = bucket.getHash(this->tableSize);

		//If this index results in a collision...
		if (this->table[index].size() > 0)
		{
			//...increment the collision counter
			++collisionCounter;
		}

		//Add the bucket to the table
		this->table[index].push_back(bucket);

		//Increment the number of objects in the table
		++entryCounter;

	}

	//Function to return the number of collision from insertion
	int getCollisions(){ return this->collisionCounter; };

	//Operator to output the Hash Table to a representation in text
	//Each line has the bucket number, and an 'x' to represent the number of
	//objects in each bucket.
	friend ostream & operator<< (ostream & out, const HashTable<K, V> & right)
	{
		for (int i = 0; i < right.table.size(); ++i)
		{
			out << i << ": ";
			for (int j = 0; j < right.table[i].size(); ++j)
			{
				out << "x ";
			}
			out << "\n";
		}
		return out;
	}

	//Function to return the load factor	
	double getLoadFactor()
	{
		//Return the load factor (defined as number of objects
		//in the table / number of buckets
		return static_cast<double>(entryCounter) / tableSize;
	}

protected:
	//The hash table, in vectors
	std::vector<std::vector<HashBucket<K, V>>> table;
	//Size of the table
	int tableSize;
	//Number of collisions
	int collisionCounter = 0;
	//Number of objects in the table
	int entryCounter = 0;
};

