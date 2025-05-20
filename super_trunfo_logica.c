#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura da carta
struct Carta {
    int forca;
    int inteligencia;
    int velocidade;
};

// Função para imprimir os atributos da carta
void mostrarCarta(struct Carta carta) {
    printf("Força: %d\n", carta.forca);
    printf("Inteligência: %d\n", carta.inteligencia);
    printf("Velocidade: %d\n", carta.velocidade);
}

// Função para gerar cartas aleatórias
struct Carta gerarCarta() {
    struct Carta nova;
    nova.forca = rand() % 101;
    nova.inteligencia = rand() % 101;
    nova.velocidade = rand() % 101;
    return nova;
}

int main() {
    srand(time(NULL));
    int opcao;

    struct Carta jogador = gerarCarta();
    struct Carta computador = gerarCarta();

    printf("Bem-vindo ao Super Trunfo - Desafio da Lógica!\n");
    printf("Sua carta:\n");
    mostrarCarta(jogador);

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Força\n");
    printf("2 - Inteligência\n");
    printf("3 - Velocidade\n");
    printf("4 - Dois Atributos (Força + Velocidade)\n");
    scanf("%d", &opcao);

    printf("\nCarta do computador:\n");
    mostrarCarta(computador);

    // Comparações
    if (opcao == 1) {
        if (jogador.forca > computador.forca)
            printf("\nVocê venceu!\n");
        else if (jogador.forca < computador.forca)
            printf("\nVocê perdeu!\n");
        else
            printf("\nEmpate!\n");
    } else if (opcao == 2) {
        if (jogador.inteligencia > computador.inteligencia)
            printf("\nVocê venceu!\n");
        else if (jogador.inteligencia < computador.inteligencia)
            printf("\nVocê perdeu!\n");
        else
            printf("\nEmpate!\n");
    } else if (opcao == 3) {
        if (jogador.velocidade > computador.velocidade)
            printf("\nVocê venceu!\n");
        else if (jogador.velocidade < computador.velocidade)
            printf("\nVocê perdeu!\n");
        else
            printf("\nEmpate!\n");
    } else if (opcao == 4) {
        int somaJogador = jogador.forca + jogador.velocidade;
        int somaComputador = computador.forca + computador.velocidade;

        // Operador ternário
        (somaJogador > somaComputador) ? printf("\nVocê venceu!\n") :
        (somaJogador < somaComputador) ? printf("\nVocê perdeu!\n") :
        printf("\nEmpate!\n");
    } else {
        printf("Opção inválida.\n");
    }

    return 0;
}
