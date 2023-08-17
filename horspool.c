// horspool algorithm
#include <stdio.h>
#include <string.h>

#define max 500
int table[max];

void shiftTable(char pattern[])
{
    int i;
    int size = strlen(pattern);

    for(i=0; i<max; i++)
        table[i] = size;

    for(int i=0; i<size-1; i++)
        table[pattern[i]] = size - 1 - i;
}

int horspool(char src[] , char pattern[])
{
    int i,j,k;
    int size_src = strlen(src); // n
    int size_pattern = strlen(pattern); // m

    printf("Size of source string is %d\n",size_src);
    printf("Size of pattern string is %d\n" , size_pattern);

    i = size_pattern - 1;
    while(i < size_src) {
        k = 0;
        while((k < size_pattern) && (pattern[size_pattern - 1 - k] == src[i-k])) {
            k++;
        }
        if(k == size_pattern)
            return i - size_pattern + 1;
        else
            i += table[src[i]];
    }
    return -1;
}

int main()
{
    int size = 1000;
    char src[size] , pattern[size];

    printf("Enter main string\n");
    gets(src); // input
    
    printf("Enter pattern to match\n");
    gets(pattern); // input

    shiftTable(pattern);
    int ans = horspool(src , pattern);

    if(ans == -1) {
        printf("Pattern doesn't exist in source string.\n");
    }
    else {
        printf("Pattern exist in source string at %d.\n", ans);
    }
}
