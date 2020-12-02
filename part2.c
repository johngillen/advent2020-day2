#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE * file;
    file = fopen("input", "r");

    int passvalid = 0;
    
    for (;;)
    {
        int i1, i2;
        char passchar;
        char pass[20];

        int line = fscanf(file, "%d-%d %c: %s\n", &i1, &i2, &passchar, pass);
        if (line == EOF) break;
        
        i1--; i2--;

        if ((pass[i1] == passchar || pass[i2] == passchar) && (pass[i1] != pass[i2])) { passvalid++; }
    }
    printf("valid passwords: %d\n", passvalid);

    return 0;
}
