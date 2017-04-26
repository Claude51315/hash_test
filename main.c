#include"hash.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int (*hash)(char* , int , char *, int);

#ifndef N
#define N 10000
#endif

#ifdef ADLER
#include "zlib.h"
#endif
#ifdef SHA1
#include "sha1.h"
#endif

int main(int argc, char *argv[]){

#ifdef CRC32 
    hash = crc32_hash;
#elif MD5
    hash = md5_hash;
#elif ADLER
    hash = adler_hash;
#elif SHA1
    hash = sha1_hash;
#endif


    char *input = argv[1];
    int fd = open(input, O_RDONLY);
    char in_buf[4097];
    int in_len = 4096;
    unsigned char output[30];
    for(int n = 0 ; n < N ; n ++)
    {
        read(fd, in_buf, sizeof(in_buf)-1);
        memset(output, '\0', sizeof(output));
        
        hash(in_buf, in_len, output, sizeof(output));
    
        int *qq;
        unsigned long *qq2;
#ifdef CRC32 
        qq = (int*)output;
        printf("%x\n",  *qq);
#elif ADLER
        qq2 = (unsigned long*)output;
        printf("%lu\n",  *qq2);
#elif MD5
        qq = (int*)output;
        printf("%x%x%x%x\n", *qq, *(qq+1), *(qq+2), *(qq+3));
#elif SHA1
        for(int i = 0 ; i < SHA1HashSize ; i++) {
            printf("%x", output[i]);
        }
        printf("\n");
#endif
    }
    close(fd);
    return 0;
}
