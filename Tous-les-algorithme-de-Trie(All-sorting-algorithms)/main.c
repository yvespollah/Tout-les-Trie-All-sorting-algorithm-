
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"
void afficherTableau(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choix,i;
    int arr[] = {5, 2, 7, 1, 9, 6}; // Exemple de tableau
    int tailles[] = {1000, 5000, 10000, 20000, 40000, 50000};

    int n = sizeof(arr) / sizeof(arr[0]);

    do {
        printf("\nMenu:\n");
        printf("1. Tri par insertion\n");
        printf("2. Tri par selection\n");
        printf("3. Tri a bulles\n");
        printf("4. Tri bitonique\n");
        printf("5. Tri fusion\n");
        printf("0. Quitter\n");

        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Example:\n");
                printf("Tableau non trié : ");
                afficherTableau(arr, n);
                printf("\n\n"); 
                triInsertion(arr, n);
                printf("Tableau trié par insertion : ");
                afficherTableau(arr, n);
                printf("\n\n");        
                printf("Mesure des temps d'execution pour différentes tailles de tableau :\n");

    for ( i = 0; i < sizeof(tailles) / sizeof(tailles[0]); i++) {
        printf("\nTaille du tableau : %d\n", tailles[i]);
      
        printf("Tri par insertion : ");
        mesurerTempsExecution(triInsertion, tailles[i]);
    }
                break;
            case 2:
            printf("Example:\n");
                printf("Tableau non trié : ");
                afficherTableau(arr, n);
                triSelection(arr, n);
                printf("Tableau trié par sélection : ");
                afficherTableau(arr, n);
                 printf("\n\n");        
                printf("Mesure des temps d'execution pour différentes tailles de tableau :\n");

    for ( i = 0; i < sizeof(tailles) / sizeof(tailles[0]); i++) {
        printf("\nTaille du tableau : %d\n", tailles[i]);
         printf("Tri par sélection : ");
        mesurerTempsExecution(triSelection, tailles[i]);
    }
                break;
            case 3:
            printf("Example:\n");
                printf("Tableau non trié : ");
                afficherTableau(arr, n);
                triBulles(arr, n);
                printf("Tableau trié par bulles : ");
                afficherTableau(arr, n);
                  printf("\n\n");        
                printf("Mesure des temps d'execution pour différentes tailles de tableau :\n");

    for ( i = 0; i < sizeof(tailles) / sizeof(tailles[0]); i++) {
        printf("\nTaille du tableau : %d\n", tailles[i]);
        printf("Tri à bulles : ");
        mesurerTempsExecution(triBulles, tailles[i]);
    }
                break;
            case 4:
            printf("Example:\n");
                printf("Tableau non trié : ");
                afficherTableau(arr, n);
                triBitonique(arr, n);
                printf("Tableau trié par tri bitonique : ");
                afficherTableau(arr, n);
                  printf("\n\n");        
                printf("Mesure des temps d'execution pour différentes tailles de tableau :\n");

    for ( i = 0; i < sizeof(tailles) / sizeof(tailles[0]); i++) {
        printf("\nTaille du tableau : %d\n", tailles[i]);
        printf("Tri bitonique : ");
        mesurerTempsExecution(triBitonique, tailles[i]);
    }
                break;
            case 5:
            printf("Example:\n");
                printf("Tableau non trié : ");
                afficherTableau(arr, n);
                triFusion(arr, 0, n - 1);
                printf("Tableau trié par tri fusion : ");
                afficherTableau(arr, n);
                   printf("\n\n");        
                printf("Mesure des temps d'execution pour différentes tailles de tableau :\n");

    for ( i = 0; i < sizeof(tailles) / sizeof(tailles[0]); i++) {
        printf("\nTaille du tableau : %d\n", tailles[i]);
       printf("Tri fusion : ");
        mesurerTempsExecution(triFusion, tailles[i]);
    }
                break;
            case 0:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un choix valide.\n");
        }
    } while (choix != 0);

    return 0;
}
