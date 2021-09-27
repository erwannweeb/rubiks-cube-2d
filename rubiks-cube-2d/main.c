#include <stdlib.h>
#include<stdio.h>
#include<conio.h>
#include"rubiks.h"

int main(){
    int op;
    int side, sens;

    // Création du rubik's cube + remplissage de base
    struct Rubiks obj;
    create_rubiks(&obj);
    Reset_Cube(&obj);

    struct Rubiks tab2;
    create_rubiks(&tab2);


    // Menu/ boucle de base
    while (1){

        // On demande a la personne ce qu'elle veut faire
        printf("1. Initialisation/Reinitialiser Cube\n2. Vider Cube\n3. Cube Aleatoire\n4. Ajouter manuellement une couleur\n5. Tourner un cote\n6. Resolution Automatique\n7. Quitter\nChoisir une option : ");
        scanf("%d",&op);

        // Le programme réagit en fonction du nb donnée
        switch (op)
        {
            // On reset le cube
            case 1:Reset_Cube(&obj); break;

                // On vide le cube
            case 2:blank_rubiks(&obj); display_rubiks(&obj); break;

                // On assigne une couleur a une case
            case 4:manualAssignement(&obj); break;

            case 5: tourner_cube(&obj, &tab2);display_rubiks(&obj); break;

                // On sort du programme
            case 7:return 0;

            default:
                break;
        }
    }

}


