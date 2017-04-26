#include "zlib.h"
#include <stdio.h>
#include<string.h>
int adler_hash(char *in_buf, int in_len, char *out_buf, int out_len){
    uLong adler =adler32(0L, Z_NULL, 0);
    adler = adler32(adler,in_buf, in_len );
    memcpy(out_buf, &adler, sizeof(adler));
    return 0;
}
