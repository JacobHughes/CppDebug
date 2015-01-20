#pragma once

#include "HashBucket.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

template <typename K, typename V>
class HashTable
{
public:
	HashTable(int tableSize)
	{
		this->table.resize(tableSize);
	}

	~HashTable(){};

	HashBucket<K, V>* find(K &key)
	{
		HashBucket<K, V> tempBucket;
		tempBucket.setKey(key);
		int index = tempBucket.getHash(table.size());
		for (int i = 0; i < table[index].size(); ++i)
		{
			if (table[index][i].getKey() == key)
			{
				return &table[index][i];
			}
		}

		return NULL;
	}

	void erase(HashBucket<K, V> * pos)
	{}

	void insert(K &key, V &value)
	{
		HashBucket<K, V> bucket(key, value);

		int index = bucket.getHash(this->table.size());
		table[index].push_back(bucket);
	}

private:
	std::vector<std::vector<HashBucket<K, V>>>table;
};

