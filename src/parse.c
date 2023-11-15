//parses a save file and sets global variables accordingly

#include <stdio.h>
#include <string.h>

#include "parse.h"
#include "display.h"

void parse(char* file)
{
    FILE* data = fopen(file, "r");

    char readBuffer[100];

    char currentChar;
    while (fgets(readBuffer, sizeof(readBuffer), data) != NULL)
    {
        if (!isdigit(readBuffer[0]))
        {
            char *count = (char*)malloc(10 * sizeof(char));
            memcpy(count, &readBuffer[2], strlen(readBuffer) - 2);
            switch (readBuffer[0])
            {
                case 'q':
                    quads = (quad*)malloc(atoi(count) * sizeof(quad)); //assign quad# from float in count
                    break;
                case 't':
                    
                    break;
            }
            free(count);
            continue;
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