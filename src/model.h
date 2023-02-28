#ifndef MODEL_H
#define MODEL_H

#include "TYPES.H"

#define MAX_NAME_LEN 20

#define a_KEY 0x0061
#define d_KEY 0x0064
#define w_KEY 0x0077 
#define f_KEY 0x0066
#define space_KEY 0x0020


enum playerStates 
{ Idle, Running, Jumping, Crouching, Attacking, Super };

typedef struct
{
    enum playerStates state;
    unsigned int x, y;      /*position coordinates*/
    int delta_x, delta_y;   /*horiz. & vert. displacement per clock tick*/

} Player;

/*The health and info bar for both players*/
typedef struct 
{
    unsigned int health;
    char name[MAX_NAME_LEN];
    UINT8 *pfpBitmap;
} Bar;

/*applies to both the floor and side boundaries*/
typedef struct
{
    unsigned int x, y;
    unsigned int height;
    unsigned int width;
} Border;

/*contains all game objects*/
typedef struct
{
    Player players[2];
    Bar bars[2];
    Border floor;
    Border walls[2];
} Model;

#endif