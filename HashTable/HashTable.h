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
public:
	HashTable(int tableSize)
	{
		this->tableSize = tableSize;
		this->table.resize(this->tableSize);
	}

	~HashTable(){}

	HashBucket<K, V>* find(K key)
	{
		HashBucket<K, V> tempBucket;
		tempBucket.setKey(key);
		
		int index = tempBucket.getHash(this->tableSize);

		for (int i = 0; i < table[index].size(); ++i)
		{
			if (this->table[index][i].getKey() == key)
			{
				return &this->table[index][i];
			}
		}

		return NULL;
	}

	HashBucket<K, V>* find(K key, V value)
	{
		HashBucket<K, V> tempBucket;
		tempBucket.setKey(key);

		int index = tempBucket.getHash(this->tableSize);

		for (int i = 0; i < this->table[index].size(); ++i)
		{
			if (this->table[index][i].getKey() == key && this->table[index][i].getValue() == value)
			{
				return &this->table[index][i];
			}
		}

		return NULL;
	}

	void erase(HashBucket<K, V> * pos)
	{
		if (pos == NULL) { return; }

		int index = pos->getHash(this->tableSize);

		int i = 0;

		while (&this->table[index][i] != pos && i < this->table[index].size())
		{
			++i;
		}

		for (int j = i; j < this->table[index].size() - 1; ++j)
		{
			this->table[index][j] = this->table[index][j + 1];
		}

		this->table[index].pop_back();
	}

	void insert(K key, V value)
	{
		HashBucket<K, V> bucket(key, value);
		
		int index = bucket.getHash(this->tableSize);

		if (this->table[index].size() > 0)
		{
			++collisionCounter;
		}

		++entryCounter;
		this->table[index].push_back(bucket);

	}

	int getCollisions(){ return this->collisionCounter; };

	friend ostream & operator<< (ostream& out, const HashTable<K, V>& right)
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

	double getLoadFactor()
	{
		return static_cast<double>(entryCounter) / tableSize;
	}

protected:
	std::vector<std::vector<HashBucket<K, V>>> table;
	int tableSize;
	int collisionCounter = 0;
	int entryCounter = 0;
};

