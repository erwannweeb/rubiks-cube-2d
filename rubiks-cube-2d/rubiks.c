#include "rubiks.h"

// Cette fonction permet a Clion de supporter la couleur
void Color(int color)
{
    if (color!=3)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
    }
}

// Cette fonction transforme les valeurs du tableau en lettre (pour l'affichage)
char getColor(int val){
    switch (val)
    {
        case 4:return 'R';
        case 1: return 'B';
        case 2: return 'G';
        case 15:return 'W';
        case 14: return 'Y';
        case 3:return 'O';
        case 8:return 'X';
        default:
            break;
    }
}

// Cette fonction permet d'obtenir la face opposé à celle que l'on utilise
int getBackSide(int side){
    switch (side)
    {
        case 0:return 5;
        case 1:return 3;
        case 2:return 4;
        case 3:return 1;
        case 4:return 2;
        case 5:return 0;
        default:
            break;
    }
}

// Cette fonction permet d'obtenir la couleur de la face choisi
int getcolorFace(char color){
    switch (color)
    {
        case 'R':return O;
        case 'B':return G;
        case 'W':return Y;
        case 'O':return R;
        case 'G':return B;
        case 'Y':return W;
        default:
            break;
    }
}

// Cette fonction permet de verifier si la combinaison de couleur actuel est techniquement possible
int checkValidty(int side, int color, struct Rubiks *r, int i, int j){
    if (j == 2){
        j = 0;
    }
    if (j == 0){
        j = 2;
    }
    int backSide = getBackSide(side);
    char actualColor = getColor(color);
    int supposedColor = getcolorFace(actualColor);
    if (r->cube[backSide][i][j] == X){
        return 1;
    }
    if (r->cube[backSide][i][j] != supposedColor){
        return 0;
    }
    else{
        return 1;
    }
}

// Cette fonction permet de créer un cube vide
void create_rubiks(struct Rubiks *r){
    r->cube = (int***)malloc(6 * sizeof(int**));
    for (int i = 0; i < 6; i++)
    {
        r->cube[i] = (int**)malloc(3 * sizeof(int*));

        for (int j = 0; j < 3; j++)
        {
            r->cube[i][j] = (int*)malloc(3 * sizeof(int));
        }
    }
    blank_rubiks(r);

}

// Cette fonction permet de créer un cube blanc
void blank_rubiks(struct Rubiks *r){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                r->cube[i][j][k] = X;
            }
        }
    }
}

// Cette fonction permet de donner une couleur à une face
void init_rubiks(struct Rubiks *r, enum T_COLOR color, enum T_SIDE side){
    if (checkValidty(side, color, r, 0, 0)){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                r->cube[side][i][j] = color;
            }
        }
    }
    else{
        printf("Combinaisons de couleurs impossible\n");
    }
}

// Cette fonction permet d'afficher le cube
void display_rubiks(struct Rubiks *r){

    // Affichage de la première ligne
    for (int j = 0; j < 3; j++)
    {
        printf("   ");
        for (int i = 0; i < 3; i++){
            printf(" ");
        }
        for (int k = 0; k < 3; k++) {
            Color(r->cube[0][j][k]);
            printf("%c ", getColor(r->cube[0][j][k]));
        }
        printf("\n");
    }
    printf("\n");

    // Affichage de la seconde ligne
    for (int i = 0; i < 3; i++){


        for (int j = 0; j < 3; j++){
            Color(r->cube[1][i][j]);
            printf("%c ", getColor(r->cube[1][i][j]));
        }
        for (int j = 0; j < 3; j++){
            Color(r->cube[2][i][j]);
            printf("%c ", getColor(r->cube[2][i][j]));
        }
        for (int j = 0; j < 3; j++){
            Color(r->cube[3][i][j]);
            printf("%c ", getColor(r->cube[3][i][j]));
        }
        for (int j = 0; j < 3; j++){
            Color(r->cube[4][i][j]);
            printf("%c ", getColor(r->cube[4][i][j]));
        }
        printf("\n");
    }
    printf("\n");

    // Affichage de la troisième
    for (int j = 0; j < 3; j++)
    {
        printf("   ");
        for (int i = 0; i < 3; i++){
            printf(" ");
        }
        for (int k = 0; k < 3; k++) {
            Color(r -> cube[5][j][k]);
            printf("%c ", getColor(r->cube[5][j][k]));
        }
        printf("\n");
    }
    Color(15);

}

// Remplissage d'une case du cube
void fill_rubiks(struct Rubiks *r, enum T_COLOR color, enum T_SIDE side,int row, int col){
    if (checkValidty(side, color, r, row, col)){
        r->cube[side][row][col] = color;
    }
}

// On modifie une face du cube
void InitCube(struct Rubiks *r){
    int face,color;

    enum T_SIDE side; enum T_COLOR c;
    printf("Choisir une face \n1.UP\n2.LEFT\n3.FRONT\n4.RIGHT\n5.BACK\n6.DOWN\n");
    scanf("%d",&face);
    while (face > 6){
        printf("Veuillez choisir une valeur entre 1 et 6\n");
        scanf("%d", &face);
    }
    printf("Choisir une couleur \n1.Blanc\n2.Orange\n3.Vert\n4.Rouge\n5.Bleu\n6.Jaune\n");
    scanf("%d", &color);
    while (color > 6){
        printf("Veuillez choisir une valeur entre 1 et 6\n");
        scanf("%d", &color);
    }
    switch (face)
    {
        case 1:side = UP; break;
        case 2:side = LEFT; break;
        case 3:side = FRONT; break;
        case 4:side = RIGHT; break;
        case 5:side = BACK; break;
        case 6:side = DOWN; break;
        default:
            break;
    }

    switch (color)
    {
        case 1:c = W; break;
        case 2:c = O; break;
        case 3:c = G; break;
        case 4:c = R; break;
        case 5:c = B; break;
        case 6:c = Y; break;
        default:
            break;
    }
    init_rubiks(r, c, side);
    display_rubiks(r);
}

// On modifie une case du cube
void manualAssignement(struct Rubiks *r) {
    int face, color, row, col;
    enum T_SIDE side;
    enum T_COLOR c;


    printf("Choisir une face \n1.UP\n2.LEFT\n3.FRONT\n4.RIGHT\n5.BACK\n6.DOWN\n");
    scanf("%d", &face);
    while (face > 6) {
        printf("Veuillez choisir une valeur entre 1 et 6\n");
        scanf("%d", &face);
    }

    printf("Choisir ligne: \n");
    scanf("%d", &row);
    while (row > 3) {
        printf("Veuillez choisir une valeur entre 1 et 3\n");
        scanf("%d", &row);
    }

    printf("Choisir colonne: \n");
    scanf("%d", &col);
    while (col > 3) {
        printf("Veuillez choisir une valeur entre 1 et 3\n");
        scanf("%d", &col);
    }

    printf("Choisir une couleur \n1.Blanc\n2.Orange\n3.Vert\n4.Rouge\n5.Bleu\n6.Jaune\n");
    scanf("%d", &color);
    while (color > 6) {
        printf("Veuillez choisir une valeur entre 1 et 6\n");
        scanf("%d", &color);
    }

    switch (face) {
        case 1:
            side = UP;
            break;
        case 2:
            side = LEFT;
            break;
        case 3:
            side = FRONT;
            break;
        case 4:
            side = RIGHT;
            break;
        case 5:
            side = BACK;
            break;
        case 6:
            side = DOWN;
            break;
        default:
            break;
    }

    switch (color)
    {
        case 1:c = W; break;
        case 2:c = O; break;
        case 3:c = G; break;
        case 4:c = R; break;
        case 5:c = B; break;
        case 6:c = Y; break;
        default:
            break;
    }

    fill_rubiks(r, c, side,row-1,col-1);
    display_rubiks(r);
}

void tourner_cube(struct Rubiks *r, struct Rubiks *t){
    int choix, side, sens;

    do{
        printf("Quart de tour ou demi-tour ? 1/ Quart 2/ Demi : ");
        scanf("%d", &choix);
    }while((1>choix) || (choix > 2));
    do{
        printf("Choisir une face \n1.UP\n2.LEFT\n3.FRONT\n4.RIGHT\n5.BACK\n6.DOWN\n");
        scanf("%d", &side);
    }while((1>side) || (side > 6));
    do{
        printf("Dans quel sens ? 1/ Horaire 2/ Anti-horaire :  ");
        scanf("%d", &sens);
    }while((1>sens) || (sens > 2));

    if(choix == 1){
        quart_de_tour(side-1, sens, r, t);
    }
    if(choix == 2){
        demi_tour(side-1, sens, r, t);
    }
}

// On tourne une face d'un quart
void quart_de_tour(enum T_SIDE side, int sens, struct Rubiks *r, struct Rubiks *t) {

    int i, j, k, l;
    int gauche, droite, haut = 2, bas = 4;
    int tab[5]={1,2,3,4,4};

    if(sens == 2){
        sens = 1;
        demi_tour(side, 1, r, t);
    }
    for (l = 0; l < 3; l++) {
        k = 2;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                t->cube[side][j][i + k] = r->cube[side][i][j];
            }
            k -= 2;
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            r->cube[side][i][j] = t->cube[side][i][j];
        }
    }

    if ((tab[side-2] > 3) || tab[side-2] < 0){
        gauche = 4;
    }
    else{
        gauche = tab[side-2];
    }
    if (tab[side] == tab[side-1]){
        droite = 1;
    }
    else
        {
        droite = tab[side];
    }

    if ((side == 2) || (side == 3) || (side == 4) || (side == 1)) {
        for (l = 0; l < 3; l++) {
            for (i = 0; i < 3; i++) {
                t->cube[gauche][i][2] = r->cube[5][0][i];
                t->cube[0][2][2 - i] = r->cube[gauche][i][2];
                t->cube[droite][2 - i][0] = r->cube[0][2][2 - i];
                t->cube[5][0][i] = r->cube[droite][2 - i][0];
            }
            if (sens == 0) {
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        r->cube[gauche][i][2] = t->cube[gauche][i][2];
                        r->cube[droite][2 - i][0] = t->cube[droite][2 - i][0];
                        r->cube[5][0][i] = t->cube[5][0][i];
                        r->cube[0][2][2 - i] = t->cube[0][2][2 - i];
                    }
                }
            }
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                r->cube[gauche][i][2] = t->cube[gauche][i][2];
                r->cube[droite][2 - i][0] = t->cube[droite][2 - i][0];
                r->cube[5][0][i] = t->cube[5][0][i];
                r->cube[0][2][2 - i] = t->cube[0][2][2 - i];
            }
        }
    }

    if(side == 0){
        haut = 4;
        bas = 2;
    }

    if ((side == 0) || (side == 5)) {
        for (l = 0; l < 3; l++) {
            for (i = 0; i < 3; i++) {
                t->cube[1][i][2] = r->cube[bas][0][i];
                t->cube[haut][2][2 - i] = r->cube[1][i][2];
                t->cube[3][2 - i][0] = r->cube[haut][2][2 - i];
                t->cube[bas][0][i] = r->cube[3][2 - i][0];
            }
            if (sens == 0) {
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        r->cube[1][i][2] = t->cube[1][i][2];
                        r->cube[3][2 - i][0] = t->cube[3][2 - i][0];
                        r->cube[bas][0][i] = t->cube[bas][0][i];
                        r->cube[haut][2][2 - i] = t->cube[haut][2][2 - i];
                    }
                }
            }
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                r->cube[1][i][2] = t->cube[1][i][2];
                r->cube[3][2 - i][0] = t->cube[3][2 - i][0];
                r->cube[bas][0][i] = t->cube[bas][0][i];
                r->cube[haut][2][2 - i] = t->cube[haut][2][2 - i];
            }
        }
    }
}

 void demi_tour(enum T_SIDE side, int sens, struct Rubiks *r, struct Rubiks *t){

    quart_de_tour(side, sens, r, t);
    quart_de_tour(side, sens, r, t);

}

// Remet le rubik's cube a sa forme initiale
void Reset_Cube(struct Rubiks *r) {

    init_rubiks(&*r, G, FRONT);
    init_rubiks(&*r, Y, DOWN);

    init_rubiks(&*r, R, RIGHT);
    init_rubiks(&*r, O, LEFT);

    init_rubiks(&*r, W, UP);
    init_rubiks(&*r, B, BACK);

    display_rubiks(&*r);
}
