#include <stdio.h>
#include <string.h>
#include <unistd.h>

void Jindutiao()
{
    char arr[130] = "Nice to meet you , would you like to drink some hot tea ? Welcome to my home ! My Friend! ";
    char result[130];
    memset(result, ' ', 130);
    int n = 0;
    while (1)
    {
        n += 2;
        if (result[0] != ' ') break;
        memcpy(result + (130 - n), arr, n);
        printf("%-130s\r", result);
        fflush(stdout);
        usleep(100000);
        //sleep(1);
    }
    n = 0;
    char disapper[130];
    memset(disapper, ' ', 130);
    fflush(stdout);
    while (1)
    {
        n += 2;
        if (n == 130) break;
        memcpy(disapper, arr + n, 130 - n);
        printf("%-130s\r", disapper);
        fflush(stdout);
        usleep(100000);
    }

}



int main()
{
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    while (1)
    {
        Jindutiao();
    }
}