#ifndef MODEL_H
#define MODEL_H

#include "TYPES.H"
#include "string.h"

#define MAX_NAME_LEN 20

#define a_KEY       0x0061  /*move right*/
#define d_KEY       0x0064  /*move left*/
#define w_KEY       0x0077  /*light attack*/
#define f_KEY       0x0066  /*super attack*/
#define j_KEY       0x006A  /*heavy attack*/
#define k_KEY       0x006B  /*slide*/
#define q_KEY       0x0071  /*quit*/
#define space_KEY   0x0020  /*jump*/


enum avatarStates 
{ Idle, Running, Jumping, Crouching, Attacking, Super };

typedef struct {
    unsigned int top_left_x;
    unsigned int top_left_y;
    unsigned int width;
    unsigned int height;
    /*bool active;            for invincibility frames if feature is added */
} Hitbox;

typedef struct {
    enum avatarStates state;
    Hitbox hitbox;
    unsigned int x, y;      /*position coordinates*/
    int delta_x, delta_y;   /*horiz. & vert. displacement per clock tick*/
} Avatar;

/*The health and info bar for both players*/
typedef struct  {
    unsigned int health;
    char name[MAX_NAME_LEN];
    UINT8 *pfpBitmap;                   /*includes avatar image and decorative borders*/
    UINT8 *superStars[2];
    /*UINT8 *rounds[4]; (will keep track of rounds if feature is added; make type for round)*/
    unsigned int x, y;
    unsigned int barWidth, barHeight;   /*width and height of the healthbar part*/
} Bar;

/*contains all game objects*/
typedef struct {
    Avatar player;
    Avatar opponent;
    Bar bars[2];
} Model;

/*function prototypes*/
void initPlayer(Avatar *, int, int);
void initBar(Bar *, int, char *, UINT8 *, int, int);
void move_player(Avatar *, char);

#endif