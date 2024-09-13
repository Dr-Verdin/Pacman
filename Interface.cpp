#include <GL/glut.h>
#include <cmath>

#define windowWidth 665
#define windowHeight 875

void draw();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Pacman");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Define a cor de fundo da janela como branca
    glutDisplayFunc(draw); // Registra a função de desenhar
    glutMainLoop(); // Entra no loop principal do GLUT

    return 0;
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor
    glLoadIdentity(); // Reseta a matriz de transformação

    // A tela padrão do OpenGL tem suas coordenadas X e Y de -1 até 1
    // Coordenada (-1, -1) é o canto inferior esquerdo
    // Coordenada (-1, 1) é o canto superior esquerdo
    // Coordenada (0, 0) é o centro da tela
    
    // Desenha várias formas com diferentes parâmetros


    glutSwapBuffers(); // Troca os buffers para exibir o frame desenhado
}