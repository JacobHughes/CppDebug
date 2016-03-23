/*=======================================================
	Code written by Jacob Hughes

	jacob.solomon.hughes@gmail.com
	https://github.com/JacobHughes/
=======================================================*/

#pragma once

#include <vector>
#include <string>
#include <typeinfo>

template <typename K, typename V>
class HashBucket
{
	/*
		This class works with a HashTable.

		Each HashBucket object holds an object of type V 
		(determined with HashTable<K,V> and generates a
		hash key for it, to determine where to insert in 
		the HashTable.

		The key generator implementation is currently the
		modified Bernstein Hash function.
	*/
public:
	//Default constructor
	HashBucket(){}

	//Specific constructor
	HashBucket(K key, V value)
	{
		this->key = key;
		this->value = value;
	}

	//Destructor
	~HashBucket(){}
	
	//Get the hashed index for table insertion
	int getHash(int tableSize)
	{
		//Get the key
		K key = getKey();

		//Get the general index
		int hashedIndex = modifiedBernsteinHash((void*)&key);

		//Mod by table size and return
		return hashedIndex % tableSize;
	}

	//Function to generate a hash
	inline unsigned modifiedBernsteinHash( void* v_key)
	{
		//return variable for the hash index
		unsigned h = 0;

		//If statement to determine the typeid of the key K
		//if it is a string, we need to generate the key
		//slightly differently
		if (typeid(K) == typeid(string))
		{
			//If K is a string:
			//Cast into a string
			string * key_ = static_cast<string *>(v_key);
			//cast to an unsigned char *
			unsigned char *p = (unsigned char *)key_->c_str();
			//get the length (number of characters in p)
			int len = sizeof(p) / sizeof(p[0]);
			//For each character, do the hash function
			for (int i = 0; i < len; ++i)
			{
				//Hash function
				h = 33 * h ^ p[i];
			}
		}
		else
		{
			//If K is anything else:
			//Cast into an unsigned char *
			unsigned char *p = static_cast<unsigned char *>(v_key);
			//Get length (number of characters in p)
			int len = sizeof(p) / sizeof(p[0]);
			//For each character, do the hash function
			for (int i = 0; i < len; ++i)
			{
				//Hash function
				h = 33 * h ^ p[i];
			}
		}

		//return the result of the hash function
		return h;
	}

	//Set the key
	void setKey(K key){ this->key = key; }
	//Set the data held by the bucket
	void setValue(V value){ this->value = value; }
	
	//Get the key
	K getKey(){ return this->key; };
	//Get the data held by the bucket
	V getValue(){ return this->value; };

protected:
	//Key
	K key;
	//Data held by bucket
	V value;
};