#ifndef TYPES_H
#define TYPES_H


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define moveSpeed 8

#define posInBounds(x, y) (x >= 0 && x < SCREEN_WIDTH && y >= 16 && y < SCREEN_HEIGHT)

typedef enum { true, false } bool;
typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;

#endif
