//parses a save file and sets global variables accordingly

#include <stdio.h>
#include <string.h>

#include "parse.h"
#include "display.h"

void parse(char* file)
{
    const char c[] = " ";
    const char o[] = ",";
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
                char* qc1 = strtok(readBuffer, o);
                char* qc2 = strtok(NULL, o);
                char* qc3 = strtok(NULL, o);
                char* qc4 = strtok(NULL, o);

                q.v1_x = strtof(strtok(qc1, c), NULL);
                q.v1_y = strtof(strtok(NULL, c), NULL);
                q.v1_z = strtof(strtok(NULL, c), NULL);

                q.v2_x = strtof(strtok(qc2, c), NULL);
                q.v2_y = strtof(strtok(NULL, c), NULL);
                q.v2_z = strtof(strtok(NULL, c), NULL);

                q.v3_x = strtof(strtok(qc3, c), NULL);
                q.v3_y = strtof(strtok(NULL, c), NULL);
                q.v3_z = strtof(strtok(NULL, c), NULL);

                q.v4_x = strtof(strtok(qc4, c), NULL);
                q.v4_y = strtof(strtok(NULL, c), NULL);
                q.v4_z = strtof(strtok(NULL, c), NULL);
                
                quads[primI] = q;
                break;
            case 't': //parsing for 3 values, repeat parse by comma x3, and inside repeat parse by space x3
                tri t;
                char* tc1 = strtok(readBuffer, o);
                char* tc2 = strtok(NULL, o);
                char* tc3 = strtok(NULL, o);
                
                t.v1_x = strtof(strtok(tc1, c), NULL);
                t.v1_y = strtof(strtok(NULL, c), NULL);
                t.v1_z = strtof(strtok(NULL, c), NULL);

                t.v2_x = strtof(strtok(tc2, c), NULL);
                t.v2_y = strtof(strtok(NULL, c), NULL);
                t.v2_z = strtof(strtok(NULL, c), NULL);

                t.v3_x = strtof(strtok(tc3, c), NULL);
                t.v3_y = strtof(strtok(NULL, c), NULL);
                t.v3_z = strtof(strtok(NULL, c), NULL);

                tris[primI] = t;
                break;
        }
        primI++;
    }
}