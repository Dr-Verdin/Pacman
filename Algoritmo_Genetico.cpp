#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

const int POPULATION_SIZE = 100;
const int GENERATIONS = 100;
const int GENERATION_CURRENT = 1;

int ind[POPULATION_SIZE + 1]; // individuos


typedef struct individuo_{
    int gene; // Solução (estratégia)
    int fitness; // Avaliação da população
} INDIVIDUO;

void inicia(int tamPop, int ind[]){ 
    // implementar
}

void avalia(int tamPop){
    printf("Geração: %d\n", GENERATION_CURRENT);
    GENERATION_CURRENT++;
}

void elitismo(int tamPop){

}

int main(int argc, char **argv){
    inicia(POPULATION_SIZE, ind); // inicializa a população

    return 0;
}