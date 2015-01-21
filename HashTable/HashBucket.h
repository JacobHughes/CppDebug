#pragma once

#include <vector>
#include <string>
#include <typeinfo>

template <typename K, typename V>
class HashBucket
{
public:
	HashBucket(){};
	HashBucket(K key, V value)
	{
		this->key = key;
		this->value = value;
	}
	~HashBucket(){}
	
	int getHash(int M)
	{
		K key = getKey();

		int hashedIndex = modifiedBernsteinHash((void*)&key);

		return hashedIndex % M;
	}

	inline unsigned modifiedBernsteinHash( void* v_key)
	{
		unsigned h = 0;
		if (typeid(K) == typeid(string))
		{
			string * key_ = static_cast<string *>(v_key);
			unsigned char *p = (unsigned char *)key_->c_str();
			int len = sizeof(p) / sizeof(p[0]);
			for (int i = 0; i < len; ++i)
			{
				h = 33 * h ^ p[i];
			}
		}
		else
		{
			unsigned char *p = static_cast<unsigned char *>(v_key);
			int len = sizeof(p) / sizeof(p[0]);
			for (int i = 0; i < len; ++i)
			{
				h = 33 * h ^ p[i];
			}
		}

		return h;
	}

	void setKey(K key){ this->key = key; }
	void setValue(V value){ this->value = value; }
	
	K getKey(){ return this->key; };
	V getValue(){ return this->value; };

protected:
	K key;
	V value;
};