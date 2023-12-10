#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"lautres alle
// 1 
void triInsertion(int arr[], int n) {
    int i, cle, j;
    for (i = 1; i < n; i++) {
        cle = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > cle) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = cle;
    }
}


// 2
void triSelection(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


// 3
void triBulles(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// 4

void fusionBitonique(int arr[], int low, int count, int direction) {
    if (count > 1) {
        int k = count / 2;
        for (int i = low; i < low + k; ++i) {
            if ((arr[i] > arr[i + k]) == direction) {
                int temp = arr[i];
                arr[i] = arr[i + k];
                arr[i + k] = temp;
            }
        }
        fusionBitonique(arr, low, k, direction);
        fusionBitonique(arr, low + k, k, direction);
    }
}

void triBitoniqueRecursif(int arr[], int low, int count, int direction) {
    if (count > 1) {
        int k = count / 2;
        triBitoniqueRecursif(arr, low, k, 1);
        triBitoniqueRecursif(arr, low + k, k, 0);
        fusionBitonique(arr, low, count, direction);
    }
}

void triBitonique(int arr[], int n) {
    triBitoniqueRecursif(arr, 0, n, 1);
}


// 5
void fusion(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void triFusion(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        triFusion(arr, left, mid);
        triFusion(arr, mid + 1, right);

        fusion(arr, left, mid, right);
    }
}


void mesurerTempsExecution(void (*tri)(int arr[], int n), int n) {
    clock_t debut, fin;
    double tempsExecution;

    int *arr = (int *)malloc(sizeof(int) * n);

    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Remplir le tableau avec des valeurs aléatoires (modifier 1000 pour la plage des valeurs aléatoires)
    }

    debut = clock();

    tri(arr, n); // Appel de la fonction de tri

    fin = clock();
    tempsExecution = ((double)(fin - debut)) / CLOCKS_PER_SEC;

    printf("Temps d'execution pour %d elements : %.6f secondes\n", n, tempsExecution);

    free(arr); // Libérer la mémoire allouée pour le tableau
}
