#include <iostream>
#include <ncurses.h> // clear limpar a tela no terminal, pritw exibir o texto na tela, refresh atualiza a tela, getch captura as teclas sem enter
#include <vector> 

const int ROWS = 25; // numero dee linhas da matriz
const int COLS = 19; // numero de colunas da matriz

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
int playerX = 1;
int playerY = 1;

// função para verificar colisão
bool colisao(int x, int y){
    if(x < 0 || x >= COLS || y < 0 || y >= ROWS) {
        return true; // Fora dos limites, é tratado como colisão mesmo assim
    }
    return grid[y][x] == 1; // Há uma parede
}

// para exibir a grade
void displayGrid() {
    clear(); // Limpa a tela, cada vez que o item é exibido a tela anterior é limpa, para que apareça apenas a nova posição do personagem

    for (int i = 0; i < ROWS; ++i) { // linhas
        for (int j = 0; j < COLS; ++j) { // coluna
            if (i == playerY && j == playerX) { // verifica se as coord correspondem as posições do personagens
                printw("P "); // Desenha o personagem na posição atual
            } else  if (collisionGrid[i][j]) {
                printw("x "); // Exibe "x" se houve colisão
            } else { //
                printw(grid[i][j] == 1 ? "1 " : "0 ");
            }
        }
        printw("\n"); // nova linha da matriz
    }
    refresh(); // atualiza a tela para mostrar as mudanças feitas
}

// Função para mover o personagem
void mover(int dx, int dy) {
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
    initscr(); // Inicializa o ncurses
    noecho(); // Não exibe a entrada do usuário
    cbreak(); // Desabilita o buffer de linha
    nodelay(stdscr, TRUE); // Não bloqueia a entrada de teclado

    int input; // Declara a variável input

    while (true) { // loop infinito para pernitir movimentos continuos
        displayGrid(); // desenha a grade atualizada

        input = getch(); // espera por uma tecla sem precisar de enter

        switch (input) { // switch para verirficar a tecla acionada
            case 'w': mover(0, -1); break; // cima
            case 's': mover(0, 1); break;  // baixo
            case 'a': mover(-1, 0); break; // esquerda
            case 'd': mover(1, 0); break;  // direita
            case 'q': endwin(); return 0; // sai do programa
        }
    }

    endwin(); // Finaliza o ncurses, liberando recursos alocados
    return 0;
}
