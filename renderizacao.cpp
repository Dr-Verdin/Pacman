#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

int matrix_to_coords(int x,int y){
    return 0;
}

class Textura{
    public:
    int x, y; // Coordenadas do textura
    int type; // Tipo do textura (para selecionar a imagem)
    int rotation; // Rotação do textura
    cv::Mat image; // Imagem do textura

    // Construtor
    Textura(int x, int y, int type) : x(x), y(y), type(type), rotation(0){
        std::string src = "";
        switch(type){
            case 0:
                src = "/home/dr-verdin/Evolutivos/Pacman/texturas/vazio_zero.png";
                break;
            case 1:
                src = "/home/dr-verdin/Evolutivos/Pacman/texturas/parede_peq_um.png";
                break;
            case 11:
                src = "/home/dr-verdin/Evolutivos/Pacman/texturas/curva_peq_onze.png";
                break;
            case 12:
                src = "/home/dr-verdin/Evolutivos/Pacman/texturas/curva_peq_doze.png";
                break;
            case 13:
                src = "/home/dr-verdin/Evolutivos/Pacman/texturas/interseccao_peq_normal_treze.png";
                break;
            case 14:
                src = "/home/dr-verdin/Evolutivos/Pacman/texturas/quina_peq_catorze.png";
                break;
            case 2:
                src = "/home/dr-verdin/Evolutivos/Pacman/texturas/parede_normal_dois.png";
                break;
            case 21:
                src = "/home/dr-verdin/Evolutivos/Pacman/texturas/curva_normal_vinteum.png";
                break;
            case 22:
                src = "/home/dr-verdin/Evolutivos/Pacman/texturas/interseccao_normal_vintedois.png";
                break;
            case 23:
                src = "/home/dr-verdin/Evolutivos/Pacman/texturas/quina_normal_vintetres.png";
                break;
            case 3:
                src = "/home/dr-verdin/Evolutivos/Pacman/texturas/parede_grande_tres.png";
                break;
            case 31:
                src = "/home/dr-verdin/Evolutivos/Pacman/texturas/quina_grande_trintaum.png";
                break;
            default:
                std::cout << "erro ao tentar colocar imagem da textura" << std::endl;
                exit(1);
        }
        // Carregar a imagem
        this->image = cv::imread(src, cv::IMREAD_COLOR);
        if (this->image.empty()) { // this->image (ver o pq)
            std::cerr << "Erro ao ler a imagem: " << src << std::endl;
            exit(1);
        }
    }

    /*void setRotation(int x, int y, int type){ // implementar
        rotation();
    }*/

    // Função para desenhar uma imagem
    void draw(cv::Mat& background){ // parametro: é um parametro de referenia para uma matriz de imagem do OpenCV
        // Verficação do tamanho da imagem do fundo
        if(background.cols < x + image.cols || background.rows < y + image.rows){
            std::cerr << "A imagem do fundo é menor do que a posição e tamanho da textura." << std::endl;
            exit(1);
        }

        // COpiar a imagem do textura para a posição (x, y) na imagem de fundo
        cv::Mat roi = background(cv::Rect(x, y, image.cols, image.rows)); // Criação da região de interesse (ROI); cv...: cria uum retangulo (subimagem) na posição x, y e de tamanho image.cols e image.rows
        image.copyTo(roi);
    }

    private:
    /*void rotation(int angle){ // implementar
        
    }*/
};

int main() {
    // Matriz de tipos de textura
    std::vector<std::vector<int>> matrix = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {12, 1, 1, 1, 1, 1, 1, 1, 1, 13, 1, 1, 1, 1, 1, 1, 1, 1, 12},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 31, 31, 0, 31, 3, 31, 0, 2, 0, 31, 3, 31, 0, 31, 31, 0, 1},
        {1, 0, 31, 31, 0, 31, 3, 31, 0, 23, 0, 31, 3, 31, 0, 31, 31, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 23, 23, 0, 23, 0, 23, 2, 22, 2, 23, 0, 23, 0, 23, 23, 0, 1},
        {1, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 1},
        {12,1, 1, 11, 0, 22, 2, 23, 0, 23, 0, 23, 2, 22, 0, 11, 1, 1, 12},
        {0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0},
        {1, 1, 1, 11, 0, 23, 0, 11, 14, 0, 14, 11, 0, 23, 0, 11, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 11, 0, 23, 0, 11, 1, 1, 1, 11, 0, 23, 0, 11, 1, 1, 1},
        {0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0},
        {12, 1, 1, 11, 0, 23, 0, 23, 2, 22, 2, 23, 0, 23, 0, 11, 1, 1, 12},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 23, 21, 0, 23, 2, 23, 0, 23, 0, 23, 2, 23, 0, 21, 23, 0, 1},
        {1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1},
        {13, 23, 0, 23, 0, 23, 0, 23, 2, 22, 2, 23, 0, 23, 0, 23, 0, 23, 13},
        {1, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 1},
        {1, 0, 23, 2, 2, 22, 2, 23, 0, 23, 0, 23, 2, 22, 2, 2, 23, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {12, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 12},
        {25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Criar uma tela branca
    cv::Mat whiteCanvas(750, 570, CV_8UC3, cv::Scalar(255, 255, 255));

    for(std::vector<std::vector<int>>::size_type y = 0; y < matrix.size(); y++){
        for(std::vector<std::vector<int>>::size_type x = 0; x < matrix[y].size(); x++){
            Textura textura(x * 30, y * 30, matrix[y][x]);
            // textura.setRotation(x, y, matrix[y][x]);
            textura.draw(whiteCanvas);
        }
    }

    // Exibir a tela
    cv::imshow("Pacman", whiteCanvas);

    // Esperar até que o usuário pressione uma tecla
    cv::waitKey(0);

    return 0;
}
