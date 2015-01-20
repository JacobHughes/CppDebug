#pragma once
#include "HashKeyFunctions.h"

#include <vector>
#include <string>

template <typename K, typename V>
class HashBucket
{
public:
	HashBucket(){};
	HashBucket(K &key_, V &value_)
	{
		this->key = key_;
		this->value = value_;
	}
	~HashBucket(){};
	
	int getHash(int M)
	{
		V val = getKey();

		return modifiedBernsteinHash(val, M);
	};

	void setKey(K &key){ this->key = key; };
	void setValue(V &value){ this->value = value; };
	
	const K getKey(){ return this->key; };
	const V getValue(){ return this->value; };

protected:
	K key;
	V value;
};