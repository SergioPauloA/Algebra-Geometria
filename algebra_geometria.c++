#include <iostream>
#include <vector>

// Definindo o tamanho da grade
const int largura = 41;
const int altura = 11;

// Função para desenhar um círculo na grade
void desenhaCirculo(int cx, int cy, int raio,
                    std::vector<std::vector<char>> &grade) {
    // Itera sobre cada ponto na área que pode conter o círculo
    for (int y = cy - raio; y <= cy + raio; ++y) {
        // Verifica se o ponto está dentro dos limites da grade
        if (y < 0 || y >= altura)
            continue;
        for (int x = cx - raio; x <= cx + raio; ++x) {
            // Verifica se o ponto está dentro dos limites da grade
            if (x < 0 || x >= largura)
                continue;
            // Calcula a distância do ponto (x, y) ao centro (cx, cy)
            int dx = x - cx;
            int dy = y - cy;
            // Verifica se o ponto está dentro do círculo
            if ((dx * dx + dy * dy) <= (raio * raio)) {
                grade[y][x] = '*'; // Marca o ponto na grade
            }
        }
    }
}

// Função para desenhar um quadrado na grade
void desenhaQuadrado(int x0, int y0, int lado,
                     std::vector<std::vector<char>> &grade) {
    // Itera sobre cada linha do quadrado
    for (int y = y0; y < y0 + lado; ++y) {
        // Verifica se a linha está dentro dos limites da grade
        if (y < 0 || y >= altura)
            continue;
        // Itera sobre cada coluna do quadrado
        for (int x = x0; x < x0 + lado; ++x) {
            // Verifica se a coluna está dentro dos limites da grade
            if (x < 0 || x >= largura)
                continue;
            grade[y][x] = '*';
        }
    }
}

// Função para desenhar um triângulo na grade
void desenhaTriangulo(int x0, int y0, int alturaTriangulo,
                      std::vector<std::vector<char>> &grade) {
    // Itera sobre cada linha do triângulo
    for (int y = 0; y < alturaTriangulo; ++y) {
        // Verifica se a linha está dentro dos limites da grade
        if (y0 + y < 0 || y0 + y >= altura)
            continue;
        // Itera sobre as colunas para formar a base do triângulo
        for (int x = -y; x <= y; ++x) {
            // Verifica se a coluna está dentro dos limites da grade
            if (x0 + x < 0 || x0 + x >= largura)
                continue;
            grade[y0 + y][x0 + x] = '*';
        }
    }
}

int main() {
    const int raio = 4;            // Define o raio do círculo
    const int ladoQuadrado = 7;    // Define o lado do quadrado
    const int alturaTriangulo = 7; // Define a altura do triângulo

    // Inicializa a grade com espaços em branco usando vetor de vetores
    std::vector<std::vector<char>> grade(altura,
                                         std::vector<char>(largura, ' '));

    // Calcula a coordenada X do centro da grade
    const int centroX = largura / 2;
    // Calcula a coordenada Y do centro da grade
    const int centroY = altura / 2;

    // Desenha o quadrado à esquerda
    desenhaQuadrado(5, centroY - ladoQuadrado / 2, ladoQuadrado, grade);

    // Desenha o círculo no centro
    desenhaCirculo(centroX, centroY, raio, grade);

    // Desenha o triângulo à direita
    desenhaTriangulo(largura - 8, centroY - alturaTriangulo / 2,
                     alturaTriangulo, grade);

    // Imprime a grade com as formas geometricas
    for (int y = 0; y < altura; ++y) {
        for (int x = 0; x < largura; ++x) {
            std::cout << grade[y][x];
        }
        std::cout << '\n';
    }

    return 0;
}