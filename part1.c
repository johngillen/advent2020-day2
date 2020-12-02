#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE * file;
    file = fopen("input", "r");

    int passvalid = 0;
    
    for (;;)
    {
        int passmin, passmax, passcount = 0;
        char passchar;
        char pass[20];

        int line = fscanf(file, "%d-%d %c: %s\n", &passmin, &passmax, &passchar, pass);
        if (line == EOF) break;

        for (size_t i = 0; i < strlen(pass); i++) { if (pass[i] == passchar) { passcount++; } }

        if (passcount >= passmin && passcount <= passmax) { passvalid++; }
        
    }
    printf("valid passwords: %d\n", passvalid);

    return 0;
}
