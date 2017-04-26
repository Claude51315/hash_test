#include "sha1.h"
#include <stdio.h>
#include <string.h>
int sha1_hash(char *in_buf, int in_len, char *out_buf, int out_len)
{
    int ret;
    unsigned char fingerprint[SHA1HashSize];
    SHA1Context sha;
    ret = SHA1Reset(&sha);
    ret = SHA1Input(&sha, in_buf, in_len);    
    ret = SHA1Result(&sha, fingerprint);
    memcpy(out_buf, fingerprint, sizeof(fingerprint));
    return 0;
}

