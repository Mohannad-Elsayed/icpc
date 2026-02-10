#define clz32(a) ((a) ? __builtin_clz((a)) : (32))
#define clz64(a) ((a) ? __builtin_clzll((a)) : (64))
#define ctz32(a) ((a) ? __builtin_ctz((a)) : (32))
#define ctz64(a) ((a) ? __builtin_ctzll((a)) : (64))
#define pct32(a) __builtin_popcount((a))
#define pct64(a) __builtin_popcountll((a))
#define msb32(a) ((a) ? ((31) - __builtin_clz((a))) : (32))
#define msb64(a) ((a) ? ((63) - __builtin_clzll((a))) : (64))
#define bit_width32(a) ((a) ? ((32) - __builtin_clz((a))) : (0))
#define bit_width64(a) ((a) ? ((64) - __builtin_clzll((a))) : (0))
#define bit_ceil32(a) ((!(a)) ? (1) : ((pct32(a)) == (1) ? ((1u) << ((31) - clz32((a)))) : ((1u) << ((32) - clz32(a)))))
#define bit_ceil64(a) ((!(a)) ? (1) : ((pct64(a)) == (1) ? ((1ull) << ((63) - clz64((a)))) : ((1ull) << ((64) - clz64(a)))))
#define bit_floor32(a) ((!(a)) ? (0) : ((1u) << ((31) - clz32((a)))))
#define bit_floor64(a) ((!(a)) ? (0) : ((1ull) << ((63) - clz64((a)))))
#define flip_Nbit(a, n) ((a) ^ ((1) << (n)))
#define only_lsb(a) ((a) & (-(a)))
u32 bit_reverse32(u32 v) { v = (v & 0x55555555) << 1 | (v >> 1 & 0x55555555); v = (v & 0x33333333) << 2 | (v >> 2 & 0x33333333); v = (v & 0x0f0f0f0f) << 4 | (v >> 4 & 0x0f0f0f0f); v = (v & 0x00ff00ff) << 8 | (v >> 8 & 0x00ff00ff); v = (v & 0x0000ffff) << 16 | (v >> 16 & 0x0000ffff); return v; }
u64 bit_reverse64(u64 v) { v = (v & 0x5555555555555555) <<  1 | (v >>  1 & 0x5555555555555555); v = (v & 0x3333333333333333) <<  2 | (v >>  2 & 0x3333333333333333); v = (v & 0x0f0f0f0f0f0f0f0f) <<  4 | (v >>  4 & 0x0f0f0f0f0f0f0f0f); v = (v & 0x00ff00ff00ff00ff) <<  8 | (v >>  8 & 0x00ff00ff00ff00ff); v = (v & 0x0000ffff0000ffff) << 16 | (v >> 16 & 0x0000ffff0000ffff); v = (v & 0x00000000ffffffff) << 32 | (v >> 32 & 0x00000000ffffffff); return v; }
u32 rotr32(u32 x, i64 r) { if (r < 0) { u32 l = (u32)(((u64)(-r)) % 32); return x << l | x >> (-l & 31); } r %= 32; return x >> r | x << (-r & 31); }
u64 rotr64(u64 x, i64 r) { if (r < 0) { u64 l = ((u64)(-r)) % 64; return x << l | x >> (-l & 63); } r %= 64; return x >> r | x << (-r & 63); }
u32 rotl32(u32 x, i64 r) { return rotr32(x, -r); }
u64 rotl64(u64 x, i64 r) { return rotr64(x, -r); }