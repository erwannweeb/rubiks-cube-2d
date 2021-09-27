#include<stdio.h>
#include<conio.h>
#include<Windows.h>

// Création du dictionnaire T_side (associe les côtés à des chiffres)
enum T_SIDE { UP = 0, LEFT = 1, FRONT = 2, RIGHT = 3, BACK = 4, DOWN = 5 };

// Création du dictionnaire T_color (associe les lettres à des chiffres provenant de conio.h)
enum T_COLOR { R = 4, B = 1, G = 2, W = 15, Y = 14, O = 3, X =8 };


// On crée le Rubiks Cube
struct Rubiks
{
    int ***cube;
};

// On initialise toute les fonctions de Rubiks.c

//Création du cube et fonctions de base
void create_rubiks(struct Rubiks *r);
void init_rubiks(struct Rubiks *r, enum T_COLOR color, enum T_SIDE side);
void Reset_Cube(struct Rubiks *r);

//Affichage du cube
void blank_rubiks(struct Rubiks *r);
void display_rubiks(struct Rubiks *r);
void fill_rubiks(struct Rubiks *r, enum T_COLOR color, enum T_SIDE side, int row, int col);

//Contrôler le cube
void manualAssignement(struct Rubiks *r);
void InitCube(struct Rubiks *r);
void tourner_cube(struct Rubiks *r, struct Rubiks *t);
void quart_de_tour(enum T_SIDE side, int sens, struct Rubiks *r, struct Rubiks *t);
void demi_tour(enum T_SIDE side, int sens, struct Rubiks *r, struct Rubiks *t);

//Fonctions permettant le bon fonctionnement
void Color(int color);
char getColor(int val);
int getBackSide(int side);
int getcolorFace(char color);
int checkValidty(int side, int color, struct Rubiks *r, int i, int j);
