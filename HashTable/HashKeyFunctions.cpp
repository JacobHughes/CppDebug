#pragma once

#include "HashKeyFunctions.h"

unsigned rotatingHash(void *key, int len)
{
	unsigned char *p = (unsigned char *)key;
	unsigned h = 0;
	int i;
	
	for (i = 0; i < len; ++i)
	{
		h = (h << 4) ^ (h >> 28) ^ p[i];
	}
	return h;
}

unsigned bernsteinHash(void *key, int len)
{
	unsigned char *p = (unsigned char *)key;
	unsigned h = 0;
	int i;

	for (i = 0; i < len; ++i)
	{
		h = 33 * h + p[i];
	}
	return h;
}

unsigned modifiedBernsteinHash(void *key, int len)
{
	unsigned char *p = (unsigned char *)key;
	unsigned h = 0;
	int i;

	for (i = 0; i < len; ++i)
	{
		h = 33 * h ^ p[i];
	}
	return h;
}

unsigned shiftAddXorHash(void *key, int len){}

unsigned FNVHash(void *key, int len){}

unsigned OneAtATimeHash(void *key, int len){}

unsigned JSWHash(void *key, int len){}

unsigned ELFHash(void *key, int len){}