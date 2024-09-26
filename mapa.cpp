#include <iostream>
#include <vector> 

#define ROWS 25 // numero dee linhas da matriz
#define COLS 19 // numero de colunas da matriz

class Grid{
    public:
    // matriz que representa o mapa do pacman
    int matrix[ROWS][COLS] = {
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

    // função para verificar colisão
    bool checkCollision(int x, int y){
        if(x < 0 || x >= COLS || y < 0 || y >= ROWS) {
            return true; // Fora dos limites, é tratado como colisão mesmo assim
        }
        return matrix[y][x] == 1; // Há uma parede
    }

    // para exibir a grade
    void display(int playerY, int playerX) { 
        for (int i = 0; i < ROWS; i++) { // linhas
            for (int j = 0; j < COLS; j++) { // coluna
                if (i == playerY && j == playerX){ // verifica se as coord correspondem as posições do personagens
                    std::cout << "P "; // Desenha o player na posição atual
                } else if (collisionGrid[i][j]){
                    std::cout << "X "; // Exibe "X" se houve colisão
                    collisionGrid[i][j] = false;
                } else { //
                    std::cout << (matrix[i][j] == 1 ? "1 " : "0 ");
                }
            }
            std::cout << std::endl; // nova linha da matriz
        }
    }
};

class Player {
    public:
    int x;
    int y;

    Player(int startX, int startY) : x(startX), y(startY) {} // construtor

    // Função para mover o player
    void move(int dx, int dy, Grid& grid) { // debugar****
        int newX = x + dx;
        int newY = y + dy;

        if (grid.checkCollision(newX, newY)) { // verifica se a nova posição tem colisão
            grid.collisionGrid[newY][newX] = true; // Marca a colisão na matriz
        } else {
            x = newX; // atualiza a posição x do player
            y = newY; // atualiza a posição y do player
            grid.collisionGrid[y][x] = false; // Reseta a colisão na nova posição
        }
    }
};

int main() {
    Grid grid;
    Player player(9, 14); // Posição inicial do player
    char input; // Declara a variável input

    while (true) { // loop infinito para pernitir movimentos continuos
        grid.display(player.y, player.x); // desenha a grade atualizada

        std::cin >> input;
        // debugar ****
        switch (input) { // switch para verirficar a tecla acionada
            case 'w': player.move(0, -1, grid); break; // cima
            case 's': player.move(0, 1, grid); break;  // baixo
            case 'a': player.move(-1, 0, grid); break; // esquerda
            case 'd': player.move(1, 0, grid); break;  // direita
            case 'q': return 0; // sai do programa
        }
    }

    return 0;
}

// belm..., classes, grafo