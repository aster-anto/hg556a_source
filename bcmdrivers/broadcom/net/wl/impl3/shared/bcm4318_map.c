#include <typedefs.h>

#ifdef BCMSDIO

uint16 wl_srom_map_4318[256] = {
/* 000 */ 0x8001, 0x28ff, 0x1010, 0x0000, 0x0420, 0x02d0, 0x044b, 0x0221,
/* 008 */ 0x000c, 0x0422, 0x0100, 0x3200, 0x0280, 0x0200, 0x0580, 0xe401,
/* 016 */ 0x1814, 0x8043, 0x0202, 0x8022, 0x0805, 0x8808, 0x0000, 0x00ff,
/* 024 */ 0x0221, 0x000c, 0x2222, 0x0001, 0x0011, 0x0000, 0x0000, 0x0000,
/* 032 */ 0x0000, 0x0040, 0x0000, 0x00e0, 0x9664, 0x00c8, 0x0000, 0x0000,
/* 040 */ 0x0000, 0x0000, 0x0000, 0x0000, 0x2015, 0x0008, 0x7242, 0x616f,
/* 048 */ 0x6364, 0x6d6f, 0x3800, 0x3230, 0x312e, 0x6731, 0x5320, 0x2043,
/* 056 */ 0x4453, 0x4f49, 0x3200, 0x322e, 0xff00, 0x0822, 0x0604, 0x9000,
/* 064 */ 0x6f4c, 0x860a, 0x0a80, 0x3b03, 0x8015, 0x77fa, 0x3efe, 0x1048,
/* 072 */ 0x0280, 0x0306, 0x0280, 0x0207, 0x0580, 0xff09, 0xffff, 0x80ff,
/* 080 */ 0x0a04, 0x0000, 0xff00, 0xff00, 0xffff, 0xffff, 0xffff, 0xffff,
/* 088 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 096 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 104 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 112 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 120 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 128 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 136 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 144 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 152 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 160 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 168 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 176 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 184 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 192 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 200 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 208 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 216 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 224 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 232 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 240 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 248 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xbfff
};

#else

uint16 wl_srom_map_4318[64] = {
/* 000 */ 0x2001, 0x0000, 0x0449, 0x14e4, 0x4318, 0x8000, 0x0002, 0x0000,
/* 008 */ 0x1000, 0x1800, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff,
/* 016 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/* 024 */ 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0xffff, 0xffff, 0xffff,
/* 032 */ 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0xffff,
/* 040 */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x3046, 0x15a7,
/* 048 */ 0xfab0, 0xfe97, 0xffff, 0xffff, 0x0048, 0xffff, 0xffff, 0xffff,
/* 056 */ 0x003e, 0xea49, 0xff02, 0x0000, 0xff08, 0xffff, 0xffff, 0x0002
};

#endif
