//parses a save file and sets global variables accordingly

#include <stdio.h>

#include "display.h"
#include "parse.h"

void parse(char** file)
{
    FILE* data = fopen(file, "r");

    char readBuffer[100];

    while (fgets(readBuffer, sizeof(readBuffer), data) != NULL)
    {
        printf("%s", readBuffer);
    }
}