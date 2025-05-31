#include <stdio.h>

#define MAX_TEXTO 200

int contarVogais(char texto[]) {
    int i, total = 0;
    char letra;

    for (i = 0; texto[i] != '\0'; i++) {
        letra = texto[i];
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
            letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
            total++;
        }
    }
    return total;
}


void inicialMaiuscula(char texto[]) {
    int i = 0;
    int novaPalavra = 1;

    while (texto[i] != '\0') {
        if (texto[i] >= 'a' && texto[i] <= 'z' && novaPalavra) {
            texto[i] = texto[i] - 32;
            novaPalavra = 0;
        } else if (texto[i] == ' ') {
            novaPalavra = 1;
        } else {
            novaPalavra = 0;
        }
        i++;
    }
}

int main() {
    char entrada[MAX_TEXTO];

    printf("Informe uma frase: ");
    fgets(entrada, MAX_TEXTO, stdin);

    printf("\nFrase digitada: %s", entrada);

    int qtdVogais = contarVogais(entrada);
    printf("Quantidade de vogais: %d\n", qtdVogais);

    inicialMaiuscula(entrada);
    printf("Frase com início maiúsculo em cada palavra: %s", entrada);

    return 0;
}


