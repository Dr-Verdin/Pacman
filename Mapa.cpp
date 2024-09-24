#include <iostream>
#include <vector> 
#include <termios.h>

#define ROWS 25 // numero dee linhas da matriz
#define COLS 19 // numero de colunas da matriz

// matriz que representa o mapa do pacman
int grid[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
    {1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
    {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// matriz para rastreas colisões
bool collisionGrid[ROWS][COLS] = { false };

// Posição inicial do personagem
int playerX = 9;
int playerY = 14;

// função para verificar colisão
bool colisao(int x, int y){ // OKK
    if(x < 0 || x >= COLS || y < 0 || y >= ROWS) {
        return true; // Fora dos limites, é tratado como colisão mesmo assim
    }
    return grid[y][x] == 1; // Há uma parede
}

// para exibir a grade
void displayGrid() { // OKKK
    for (int i = 0; i < ROWS; i++) { // linhas
        for (int j = 0; j < COLS; j++) { // coluna
            if (i == playerY && j == playerX){ // verifica se as coord correspondem as posições do personagens
                std::cout << "P "; // Desenha o personagem na posição atual
            } else if (collisionGrid[i][j]){
                std::cout << "X "; // Exibe "X" se houve colisão
                collisionGrid[i][j] = false;
            } else { //
                std::cout << (grid[i][j] == 1 ? "1 " : "0 ");
            }
        }
        std::cout << std::endl; // nova linha da matriz
    }
}

// Função para mover o personagem
void mover(int dx, int dy) { // okk
    int newX = playerX + dx;
    int newY = playerY + dy;

    if (colisao(newX, newY)) { // verifica se a nova posição tem colisão
        collisionGrid[newY][newX] = true; // Marca a colisão na matriz
    } else {
        playerX = newX; // atualiza a posição x do player
        playerY = newY; // atualiza a posição y do player
        collisionGrid[playerY][playerX] = false; // Reseta a colisão na nova posição
    }
}

int main() {
    char input; // Declara a variável input

    while (true) { // loop infinito para pernitir movimentos continuos
        displayGrid(); // desenha a grade atualizada

        std::cin >> input;

        switch (input) { // switch para verirficar a tecla acionada
            case 'w': mover(0, -1); break; // cima
            case 's': mover(0, 1); break;  // baixo
            case 'a': mover(-1, 0); break; // esquerda
            case 'd': mover(1, 0); break;  // direita
            case 'q': return 0; // sai do programa
        }
    }

    return 0;
}


// belm..., classes, grafo