struct RSH
{
    unsigned int operator()(char* str, unsigned int len)
    {
       unsigned int b    = 378551;
       unsigned int a    = 63689;
       unsigned int hash = 0;
       unsigned int i    = 0;
    
       for(i = 0; i < len; str++, i++)
       {
          hash = hash * a + (*str);
          a    = a * b;
       }
    
       return hash;
    }
};
 
struct JSHash{
    unsigned int operator()(char* str, unsigned int len)
    {
    unsigned int hash = 1315423911;
    unsigned int i    = 0;
 
    for(i = 0; i < len; str++, i++)
    {
        hash ^= ((hash << 5) + (*str) + (hash >> 2));
    }
 
    return hash;
    }

}; 
/* End Of JS Hash Function */
 
struct PJWHash{
    unsigned int operator()(char* str, unsigned int len)
    {
    const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
    const unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
    const unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
    const unsigned int HighBits          = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
    unsigned int hash              = 0;
    unsigned int test              = 0;
    unsigned int i                 = 0;
 
    for(i = 0; i < len; str++, i++)
    {
        hash = (hash << OneEighth) + (*str);
 
        if((test = hash & HighBits)  != 0)
        {
            hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
        }
    }
 
    return hash;
    }

};
/* End Of  P. J. Weinberger Hash Function */
 
struct ELFHash{
    unsigned int operator()(char* str, unsigned int len)
    {
    unsigned int hash = 0;
    unsigned int x    = 0;
    unsigned int i    = 0;
 
    for(i = 0; i < len; str++, i++)
    {
        hash = (hash << 4) + (*str);
        if((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
        }
        hash &= ~x;
    }
 
    return hash;
    }

} ;
/* End Of ELF Hash Function */
 
/*This hash function comes from Brian Kernighan and Dennis Ritchie's book "The C Programming Language". 
* It is a simple hash function using a strange set of possible seeds which all constitute a pattern 
* of 31....31...31 etc, it seems to be very similar to the DJB hash function.
*/

struct BKDRHash{
    unsigned int operator()(char* str, unsigned int len)
    {
    unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
    unsigned int hash = 0;
    unsigned int i    = 0;
 
    for(i = 0; i < len; str++, i++)
    {
        hash = (hash * seed) + (*str);
    }
 
    return hash;
    }
};
/* End Of BKDR Hash Function */
 
/*This is the algorithm of choice which is used in the open source SDBM project. 
* The hash function seems to have a good over-all distribution for many different 
* data sets. It seems to work well in situations where there is a high variance 
* in the MSBs of the elements in a data set.
*/
struct SDBMHash{
    unsigned int operator()(char* str, unsigned int len)
    {
    unsigned int hash = 0;
    unsigned int i    = 0;
 
    for(i = 0; i < len; str++, i++)
    {
        hash = (*str) + (hash << 6) + (hash << 16) - hash;
    }
 
    return hash;
    }

};
/* End Of SDBM Hash Function */
 
/*An algorithm produced by Professor Daniel J. Bernstein and shown first 
* to the world on the usenet newsgroup comp.lang.c. It is one of the most 
* efficient hash functions ever published.
*/
struct DJBHash{
    unsigned int operator()(char* str, unsigned int len)
    {
    unsigned int hash = 5381;
    unsigned int i    = 0;
 
    for(i = 0; i < len; str++, i++)
    {
        hash = ((hash << 5) + hash) + (*str);
    }
 
    return hash;
    }

};
/* End Of DJB Hash Function */
 
struct DEKHash{
    unsigned int operator()(char* str, unsigned int len)
    {
    unsigned int hash = len;
    unsigned int i    = 0;
 
    for(i = 0; i < len; str++, i++)
    {
        hash = ((hash << 5) ^ (hash >> 27)) ^ (*str);
    }
    return hash;
    }

}; 
/* End Of DEK Hash Function */
 
struct BPHash{
    unsigned int operator()(char* str, unsigned int len)
    {
    unsigned int hash = 0;
    unsigned int i    = 0;
    for(i = 0; i < len; str++, i++)
    {
        hash = hash << 7 ^ (*str);
    }
 
    return hash;
    }

} ;
/* End Of BP Hash Function */
 
struct FNVHash{
    unsigned int operator()(char* str, unsigned int len)
    {
    const unsigned int fnv_prime = 0x811C9DC5;
    unsigned int hash      = 0;
    unsigned int i         = 0;
 
    for(i = 0; i < len; str++, i++)
    {
        hash *= fnv_prime;
        hash ^= (*str);
    }
 
    return hash;
    }
}; 
/* End Of FNV Hash Function */
 
struct APHash{
    unsigned int operator()(char* str, unsigned int len)
    {
       unsigned int hash = 0xAAAAAAAA;
       unsigned int i    = 0;
    
       for(i = 0; i < len; str++, i++)
       {
          hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ (*str) * (hash >> 3)) :
                                   (~((hash << 11) + (*str) ^ (hash >> 5)));
       }
    
       return hash;
    }

}; 
/* End Of AP Hash Function */