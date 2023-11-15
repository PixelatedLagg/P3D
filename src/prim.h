#ifndef PRIM_H
#define PRIM_H

#include <GL/gl.h>

typedef struct
{
    GLfloat v1_x, v1_y, v1_z, v2_x, v2_y, v2_z, v3_x, v3_y, v3_z, v4_x, v4_y, v4_z;
} quad;

typedef struct
{
    GLfloat v1_x, v1_y, v1_z, v2_x, v2_y, v2_z, v3_x, v3_y, v3_z; 
} tri;

#endif