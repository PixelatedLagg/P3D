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
                    quads = (quad*)malloc(atoi(count) * sizeof(quad)); //assign quad# from int in count
                    break;
                case 't':
                    tris = (tri*)malloc(atoi(count) * sizeof(tri)); //assign tri# from int in count
                    break;
            }
            free(count);
            primI = 0;
            continue;
        }
        switch (currentChar)
        {
            case 'q': //parsing for 4 values, repeat parse by comma x4, and inside repeat parse by space x3
                quad q;
                char* qcomma;
                qcomma = strtok(readBuffer,",");
                char* qspace;

                qspace = strtok(qcomma," ");
                q.v1_x = strtof(qspace, NULL);
                qspace = strtok(NULL, " ");
                q.v1_y = strtof(qspace, NULL);
                qspace = strtok(NULL, " ");
                q.v1_z = strtof(qspace, NULL);
                qcomma = strtok(NULL, ",");
                qspace = strtok(qcomma," ");

                q.v2_x = strtof(qspace, NULL);
                qspace = strtok(NULL, " ");
                q.v2_y = strtof(qspace, NULL);
                qspace = strtok(NULL, " ");
                q.v2_z = strtof(qspace, NULL);
                qcomma = strtok(NULL, ",");
                qspace = strtok(qcomma," ");

                q.v3_x = strtof(qspace, NULL);
                qspace = strtok(NULL, " ");
                q.v3_y = strtof(qspace, NULL);
                qspace = strtok(NULL, " ");
                q.v3_z = strtof(qspace, NULL);
                qcomma = strtok(NULL, ",");
                qspace = strtok(qcomma," ");
                
                q.v4_x = strtof(qspace, NULL);
                qspace = strtok(NULL, " ");
                q.v4_y = strtof(qspace, NULL);
                qspace = strtok(NULL, " ");
                q.v4_z = strtof(qspace, NULL);
                break;
            case 't': //parsing for 3 values, repeat parse by comma x3, and inside repeat parse by space x3
                tri t;
                char* tcomma;
                tcomma = strtok(readBuffer,",");
                char* tspace;

                tspace = strtok(tcomma," ");
                t.v1_x = strtof(tspace, NULL);
                tspace = strtok(NULL, " ");
                t.v1_y = strtof(tspace, NULL);
                tspace = strtok(NULL, " ");
                t.v1_z = strtof(tspace, NULL);
                tcomma = strtok(NULL, ",");
                tspace = strtok(tcomma," ");

                t.v2_x = strtof(tspace, NULL);
                tspace = strtok(NULL, " ");
                t.v2_y = strtof(tspace, NULL);
                tspace = strtok(NULL, " ");
                t.v2_z = strtof(tspace, NULL);
                tcomma = strtok(NULL, ",");
                tspace = strtok(tcomma," ");

                t.v3_x = strtof(tspace, NULL);
                tspace = strtok(NULL, " ");
                t.v3_y = strtof(tspace, NULL);
                tspace = strtok(NULL, " ");
                t.v3_z = strtof(tspace, NULL);
                tcomma = strtok(NULL, ",");
                tspace = strtok(tcomma," ");
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