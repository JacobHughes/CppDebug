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

unsigned shiftAddXorHash(void *key, int len)
{
	unsigned char *p = (unsigned char *)key;
	unsigned h = 0;
	int i;

	for (i = 0; i < len; ++i)
	{
		h ^= (h << 5) + (h >> 2) + p[i];
	}
	return h;
}

unsigned FNVHash(void *key, int len)
{
	unsigned char *p = (unsigned char *)key;
	unsigned h = 0;
	int i;

	for (i = 0; i < len; ++i)
	{
		h = (h * 16777619) ^ p[i];
	}
	return h;
}

unsigned OneAtATimeHash(void *key, int len)
{
	unsigned char *p = (unsigned char *)key;
	unsigned h = 0;
	int i;

	for (i = 0; i < len; ++i)
	{
		h += p[i];
		h += (h << 10);
		h ^= (h >> 6);
	}

	h += (h << 3);
	h ^= (h >> 11);
	h += (h << 15);

	return h;
}

unsigned JSWHash(void *key, int len)
{
	unsigned char *p = (unsigned char *)key;
	unsigned h = 0;
	int i;

	for (i = 0; i < len; ++i)
	{
		h = (h << 1 | h >> 31) ^ tab[p[i]];
	}
	return h;
}

unsigned ELFHash(void *key, int len)
{
	unsigned char *p = (unsigned char *)key;
	unsigned h = 0;
	int i;

	for (i = 0; i < len; ++i)
	{
		h = (h << 4) + p[i];
		g = h & 0xf0000000L;
		
		if (g != 0)
		{
			h ^= g >> 24;
		}
		
		h &= ~g;
	}
	return h;
}