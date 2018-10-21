#include <iostream>
#include <stdio.h>

int main() {
    int numEstados;
    scanf("%d", &numEstados);

    char alfabeto[1024];
    scanf("%s", &alfabeto);

    int estadoInicial;
    scanf("%d", &estadoInicial);

    int quantidadeEstadosFinais;
    scanf("%d", &quantidadeEstadosFinais);

    int estadosFinais[quantidadeEstadosFinais];

    for (int i = 0; i < quantidadeEstadosFinais; i++) {
        scanf("%d", &estadosFinais[i]);
    }

    int quantidadeDeTransicoes = strlen(alfabeto) * numEstados;
    char transicoes[quantidadeDeTransicoes][3];

    for (int i = 0; i < quantidadeDeTransicoes; ++i) {
        char symbol;
        int start, end;
        scanf("%d\t%c\t%d", &start, &symbol, &end);
        transicoes[i][0] = start;
        transicoes[i][1] = symbol;
        transicoes[i][2] = end;
    }


    char entrada[102400];
    scanf("%s", &entrada);

    int estadoAtual = estadoInicial;

    for (int i = 0; i < strlen(entrada); ++i) {
        char entradaAtual = entrada[i];

        for (int j = 0; j < quantidadeDeTransicoes; ++j) {
            if (transicoes[j][0] == estadoAtual && transicoes[j][1] == entradaAtual) {
                estadoAtual = transicoes[j][2];
                break;
            }
        }
    }

    bool encontrado = false;

    for (int k = 0; k < quantidadeEstadosFinais; ++k) {
        if (estadosFinais[k] == estadoAtual) {
            encontrado = true;
        }
    }

    if (encontrado) {
        printf("Aceita\n");
    } else {
        printf("Rejeitada\n");
    }


    return 0;
}