#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

// Estrutura para representar um dado
typedef struct {
    int valor;
    bool estado;
} DADOS;

// Função para somar os pontos da ronda
int somarpontos_ronda(int v[]) {
    int presente[5] = { 0 };
    int i, soma = 0;

    // Percorre o vetor de valores e marca os números presentes
    for (i = 0; i < 5; i++) {
        if (v[i] >= 1 && v[i] <= 5) {
            presente[v[i] - 1] = 1; // Marca como presente
        }
    }

    // Soma os valores ausentes
    for (i = 0; i < 5; i++) {
        if (presente[i] == 0) { // Se não está marcado, está ausente
            soma += (i + 1); // Soma o valor correspondente
        }
    }

    return soma;
}

// Função para jogar uma ronda
int jogar(int x, char j1[], char j2[], DADOS dados[]) {
    int i, op1 = 1, re_roll = 0, op2 = 0, soma, valores[5];

    // Inicializa os dados
    srand(time(NULL));
    for (i = 0; i < 5; i++) {
        dados[i].estado = false;
        dados[i].valor = 0;
    }

    // Turno do jogador 1
    if (x == 1) {
        system("color 20");
        system("cls");
        do {
            printf("Vez do jogador %s\n", j1);
            for (i = 0; i < 5; i++) {
                if (!dados[i].estado) {
                    dados[i].valor = (rand() % 5 + 1);
                    printf("Dado %d: %d\n", i + 1, dados[i].valor);
                }
                else {
                    printf("Dado %d: %d (Guardado)\n", i + 1, dados[i].valor);
                }
            }

            // Re-roll logic
            if (re_roll <= 2) {
                printf("\nEscolher dados para guardar/desmarcar (1-5)\n(0 - para nao guardar mais):\n");
                do {
                    printf("--> ");
                    scanf("%d", &op2);
                    getchar();
                    if (op2 > 0 && op2 <= 5 && !dados[op2 - 1].estado) {
                        dados[op2 - 1].estado = true;
                    }
                    else if (op2 > 0 && op2 <= 5 && dados[op2 - 1].estado) {
                        dados[op2 - 1].estado = false;
                    }
                } while (op2 != 0);
                printf("\nDeseja lancar de novo os dados? (0- Nao, 1- Sim)\n--> ");
                scanf("%d", &op1);
                getchar();
                re_roll++;
                system("cls");
            }
            else if (re_roll > 2) {
                op1 = 0;
            }
        } while (op1 != 0);
    }

    // Turno do jogador 2
    else {
        system("color 30");
        system("cls");
        do {
            printf("Vez do jogador %s\n", j2);
            for (i = 0; i < 5; i++) {
                if (!dados[i].estado) {
                    dados[i].valor = (rand() % 5 + 1);
                    printf("Dado %d: %d\n", i + 1, dados[i].valor);
                }
                else {
                    printf("Dado %d: %d (Guardado)\n", i + 1, dados[i].valor);
                }
            }

            // Re-roll logic
            if (re_roll <= 2) {
                printf("\nEscolher dados para guardar/desmarcar (1-5)\n(0 - para nao guardar mais):\n");
                do {
                    printf("--> ");
                    scanf("%d", &op2);
                    getchar();
                    if (op2 > 0 && op2 <= 5 && !dados[op2 - 1].estado) {
                        dados[op2 - 1].estado = true;
                    }
                    else if (op2 > 0 && op2 <= 5 && dados[op2 - 1].estado) {
                        dados[op2 - 1].estado = false;
                    }
                } while (op2 != 0);
                printf("\nDeseja lancar de novo os dados? (0- Nao, 1- Sim)\n--> ");
                scanf("%d", &op1);
                getchar();
                re_roll++;
                system("cls");
            }
            else if (re_roll > 2) {
                op1 = 0;
            }
        } while (op1 != 0);
    }

    // Calcula os valores finais
    for (i = 0; i < 5; i++) {
        valores[i] = dados[i].valor;
    }

    return soma = somarpontos_ronda(valores);
}

// Função principal
int main() {
    int turno = 1, i, pontos = 0, ronda = 1;
    char p1[30], p2[30];
    DADOS dados[5];

    // Mensagem inicial
    printf("-------------------\nTrabalho de LIC\nJogo de dados\nFeito por: Goncalo Melo\n-------------------");
    Sleep(3000);
    system("cls");

    // Leitura dos nomes dos jogadores
    printf("Introduzir nome do jogador 1: ");
    scanf("%s", p1);
    printf("Introduzir nome do jogador 2: ");
    scanf("%s", p2);
    getchar();

    // Ciclo principal do jogo
    for (i = 0; i < 40; i++) {
        pontos = jogar(turno, p1, p2, dados);
        printf("Ronda:%d = %d pontos", ronda, pontos);
        ronda++;
        getchar();
        turno *= -1;
    }

    return 0;
}
