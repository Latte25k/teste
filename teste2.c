#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100
#define MAX_STR 100

typedef struct {
    char titulo[MAX_STR];
    char autor[MAX_STR];
    char editora[MAX_STR];
    int anoPublicacao;
    int qtdPaginas;
} Livro;

void preencherVetor(Livro livros[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Livro %d ---\n", i + 1);
        printf("Título: ");
        fgets(livros[i].titulo, MAX_STR, stdin);
        livros[i].titulo[strcspn(livros[i].titulo, "\n")] = '\0'; // remove '\n'

        printf("Autor: ");
        fgets(livros[i].autor, MAX_STR, stdin);
        livros[i].autor[strcspn(livros[i].autor, "\n")] = '\0';

        printf("Editora: ");
        fgets(livros[i].editora, MAX_STR, stdin);
        livros[i].editora[strcspn(livros[i].editora, "\n")] = '\0';

        printf("Ano de publicação: ");
        scanf("%d", &livros[i].anoPublicacao);

        printf("Quantidade de páginas: ");
        scanf("%d", &livros[i].qtdPaginas);
        getchar(); 
    }
}

void imprimirVetor(Livro livros[], int n) { 
    printf("\n--- Lista de Livros ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d - \"%s\" | Autor: %s | Editora: %s | Ano: %d | Páginas: %d\n",
               i, livros[i].titulo, livros[i].autor, livros[i].editora,
               livros[i].anoPublicacao, livros[i].qtdPaginas);
    }
}

int buscarPorTitulo(Livro livros[], int n, const char tituloBusca[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(livros[i].titulo, tituloBusca) == 0) {
            return i;
        }
    }
    return -1;
}

void ordenarPorTitulo(Livro livros[], int n) {
    Livro temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(livros[j].titulo, livros[j + 1].titulo) > 0) {
                temp = livros[j];
                livros[j] = livros[j + 1];
                livros[j + 1] = temp;
            }
        }
    }
}


int buscaBinariaPorTitulo(Livro livros[], int n, const char tituloBusca[]) {
    int inicio = 0, fim = n - 1, meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        int cmp = strcmp(livros[meio].titulo, tituloBusca);

        if (cmp == 0)
            return meio;
        else if (cmp < 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

int main() {
    Livro biblioteca[MAX_LIVROS];
    int qtdLivros;

    printf("Quantos livros deseja cadastrar? ");
    scanf("%d", &qtdLivros);
    getchar();

    preencherVetor(biblioteca, qtdLivros);

    imprimirVetor(biblioteca, qtdLivros);

    char tituloBusca[MAX_STR];

    printf("\nDigite o título do livro para buscar (linear): ");
    fgets(tituloBusca, MAX_STR, stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = '\0';

    int pos = buscarPorTitulo(biblioteca, qtdLivros, tituloBusca);
    if (pos != -1)
        printf("Livro encontrado na posição %d (busca linear).\n", pos);
    else
        printf("Livro não encontrado (busca linear).\n");

    ordenarPorTitulo(biblioteca, qtdLivros);

    printf("\nVetor ordenado por título:\n");
    imprimirVetor(biblioteca, qtdLivros);

    printf("\nDigite o título do livro para buscar (binária): ");
    fgets(tituloBusca, MAX_STR, stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = '\0';

    int posBinaria = buscaBinariaPorTitulo(biblioteca, qtdLivros, tituloBusca);
    if (posBinaria != -1)
        printf("Livro encontrado na posição %d (busca binária).\n", posBinaria);
    else
        printf("Livro não encontrado (busca binária).\n");

    return 0;
}
