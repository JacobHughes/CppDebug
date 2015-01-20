#pragma once

inline unsigned rotatingHash(void *key, int len);

inline unsigned bernsteinHash(void *key, int len);

inline unsigned modifiedBernsteinHash(void *key, int len);

inline unsigned shiftAddXorHash(void *key, int len);

inline unsigned FNVHash(void *key, int len);

inline unsigned OneAtATimeHash(void *key, int len);

inline unsigned ELFHash(void *key, int len);