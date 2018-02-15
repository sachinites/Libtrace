/* Assuming least significant bit starts from 0th bit and go upto 63rd bit*/

#ifndef __BITS__
#define __BITS__

#define IS_BIT_SET(n, pos)	((n & (1 << (pos))) != 0)
#define TOGGLE_BIT(n, pos)	(n = n ^ (1 << (pos)))
#define COMPLEMENT(num)	   	(num = num ^ 0xFFFFFFFFFFFFFFFF)
#define UNSET_BIT(n, pos)  	(n = n & ((1 << pos) ^ 0xFFFFFFFFFFFFFFFF))
#define SET_BIT(n, pos)     (n = n | 1 << pos)

#endif

