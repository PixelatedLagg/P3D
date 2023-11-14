//parses a save file and sets global variables accordingly

#include <stdio.h>
#include <string.h>

#include "parse.h"
#include "display.h"

void parse(char* file)
{
    FILE* data = fopen(file, "r");

    char readBuffer[100];

    while (fgets(readBuffer, sizeof(readBuffer), data) != NULL)
    {
        if (!isdigit(readBuffer[0]))
        {
            char *buff = (char*)malloc(10 * sizeof(char));
            memcpy(buff, &readBuffer[2], strlen(readBuffer) - 2);
            quads = (quad*)malloc(atoi(buff) * sizeof(quad)); //assign quad# from float in buff
            free(buff);
        }
        int i = 0;
        while (readBuffer[i] != '\n')
        {

        }
    }
}

/*
string->float

float f;
f = strtof(buff, NULL);
*/