#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#ifndef N
#define N 10000
#endif
int main(){
    unsigned char data[4096+1];
    memset(data, '\0', sizeof(char));
    srand(time(NULL));
    int fd;
    fd = open("data.out",O_CREAT | O_RDWR, 0666);
    data[4096] = '\n';
    for(int n = 0 ; n < N ; n++)
    {
    for(int i = 0; i< 4096; i++){
        if(i%2 == 0)
        
            data[i] = '0'+rand()%10;
        else
            data[i] = 'A'+rand()%6;
    }
    write(fd, data, sizeof(data));
    }
    close(fd);


    return 0;
}
