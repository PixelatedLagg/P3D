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
    int primI = 0;
    while (fgets(readBuffer, sizeof(readBuffer), data) != NULL)
    {
        if (!isdigit(readBuffer[0]))
        {
            char *count = (char*)malloc(10 * sizeof(char));
            memcpy(count, &readBuffer[2], strlen(readBuffer) - 2);
            currentChar = readBuffer[0];
            switch (currentChar)
            {
                case 'q':
                    quads = (quad*)malloc(atoi(count) * sizeof(quad)); //assign quad# from float in count
                    break;
                case 't':
                    tris = (quad*)malloc(atoi(count) * sizeof(quad)); //assign tri# from float in count
                    break;
            }
            free(count);
            primI = 0;
            continue;
        }
        switch (currentChar)
        {
            case 'q': //parsing for 4 values, repeat parse by comma x4, and inside repeat parse by space x4
                quad q;
                char* comma;
                comma = strtok(readBuffer,",");
                char* space;

                space = strtok(comma," ");
                q.v1_x = strtof(space, NULL);
                space = strtok(NULL, " ");
                q.v1_y = strtof(space, NULL);
                space = strtok(NULL, " ");
                q.v1_z = strtof(space, NULL);
                comma = strtok(NULL, ",");
                space = strtok(comma," ");

                q.v2_x = strtof(space, NULL);
                space = strtok(NULL, " ");
                q.v2_y = strtof(space, NULL);
                space = strtok(NULL, " ");
                q.v2_z = strtof(space, NULL);
                comma = strtok(NULL, ",");
                space = strtok(comma," ");

                q.v3_x = strtof(space, NULL);
                space = strtok(NULL, " ");
                q.v3_y = strtof(space, NULL);
                space = strtok(NULL, " ");
                q.v3_z = strtof(space, NULL);
                comma = strtok(NULL, ",");
                space = strtok(comma," ");
                
                q.v4_x = strtof(space, NULL);
                space = strtok(NULL, " ");
                q.v4_y = strtof(space, NULL);
                space = strtok(NULL, " ");
                q.v4_z = strtof(space, NULL);
                break;
            case 't': //parsing for 3 values
                break;
        }
        primI++;
    }
}

/*
string->float

float f;
f = strtof(buff, NULL);
*/