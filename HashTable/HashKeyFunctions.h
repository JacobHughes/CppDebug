#pragma once

unsigned rotatingHash(void *key, int len);

unsigned bernsteinHash(void *key, int len);

unsigned modifiedBernsteinHash(void *key, int len);

unsigned shiftAddXorHash(void *key, int len);

unsigned FNVHash(void *key, int len);

unsigned OneAtATimeHash(void *key, int len);

unsigned JSWHash(void *key, int len);

unsigned ELFHash(void *key, int len);