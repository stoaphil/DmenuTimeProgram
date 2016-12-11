#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t          t;
    struct tm       *tmp;
    char            buf[64];

    time(&t);
    tmp = localtime(&t);

    if(strftime(buf, 64, "%X %Z, %a %D", tmp) == 0){ //  See APUE fig. 6.11
        printf("buffer length 64 too small\n");
        exit(12);
    }
    else
        printf("%s\n", buf);

    exit(0);
}
