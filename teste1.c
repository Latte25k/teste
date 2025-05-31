#include <stdio.h>

#define MAX_LEN 250

// Conta o número de vogais (maiúsculas e minúsculas) em uma string
int totalVogais(char *str) {
    int i = 0, contador = 0;
    char ch;
    while (str[i] != '\0') {
        ch = str[i];
        // Verifica vogais minúsculas e maiúsculas
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            contador++;
        }
        i++;
    }
    return contador;
}

// Coloca a primeira letra de cada palavra em maiúsculo
void converterParaTitulo(char *str) {
    int i = 0;
    int deveMaiuscula = 1; // Indica se deve converter o caractere atual

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            deveMaiuscula = 1;  // Próximo caractere pode ser início de palavra
        } else if (deveMaiuscula && (str[i] >= 'a' && str[i] <= 'z')) {
            str[i] = str[i] - 32;  // Converte para maiúsculo
            deveMaiuscula = 0;
        } else {
            deveMaiuscula = 0;
        }
        i++;
    }
}

int main() {
    char fraseUsuario[MAX_LEN];

    printf("Por favor, digite uma frase:\n");
    fgets(fraseUsuario, MAX_LEN, stdin);

    printf("\nFrase original: %s", fraseUsuario);

    int quantidadeVogais = totalVogais(fraseUsuario);
    printf("Total de vogais na frase: %d\n", quantidadeVogais);

    converterParaTitulo(fraseUsuario);
    printf("Frase formatada (Título): %s", fraseUsuario);

    return 0;
}
