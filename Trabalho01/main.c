#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define QTDLIVROS 50

typedef struct
{
    int codigo;
    char titulo[100];
    char autor[50];
    int ano;
    char editora[50];
    int paginas;
    char genero[50];
    float valorAluguel;
} Livro;

typedef struct
{
    char cliente[50];
    char data[11];
    char titulo[50];
    float valorLocacao;
} Locacao;

Livro livros[QTDLIVROS];

void printLivro(Livro l)
{
    printf("Código:%d\t", l.codigo);
    printf("Título: %s\t", l.titulo);
    printf("Autor:%s\t", l.autor);
    printf("Ano:%d\t", l.ano);
    printf("Editora:%s\t", l.editora);
    printf("Gênero:%s\t", l.genero);
    printf("Valor Aluguel:R$%.2f\n", l.valorAluguel);
}

void loadLivros(FILE *f)
{
    char buffer[256];
    int i = 0;

    while (fgets(buffer, sizeof(buffer), f) != NULL)
    {
        // puts(buffer);
        char *token = strtok(&buffer[0], ";");
        livros[i].codigo = atoi(token);
        // puts(token);
        token = strtok(NULL, ";");
        strcpy(livros[i].titulo, token);
        // puts(token);
        token = strtok(NULL, ";");
        strcpy(livros[i].autor, token);
        // puts(token);
        token = strtok(NULL, ";");
        livros[i].ano = atoi(token);
        // puts(token);
        token = strtok(NULL, ";");
        strcpy(livros[i].genero, token);
        // puts(token);
        token = strtok(NULL, ";");
        livros[i].valorAluguel = atof(token);
        printLivro(livros[i]);
    }
}
void storeLocacao(Locacao *l, FILE *f2)
{
    fprintf(f2, "%s;%s;%s;%s;%s\n", l->cliente, l->data, l->titulo, l->valorLocacao);
}

void buscarLivroPorId(int id)
{
}

void verTodosOsLivros();
void alugarLivro()
{
}

int main(void)
{
    setlocale(LC_ALL, "");
    FILE *f = fopen("fonte.csv", "r");
    FILE *f2 = fopen("locacoes.csv", "w");

    if (!f)
    {
        puts("Não foi possível abrir o arquivo");
        fclose(f);
        return -1;
    }

    loadLivros(f);

    int op = 0;
    while (1)
    {
        printf("=========LOCADORA DIGITAL==========");
        printf("\n1.Buscar Livro\n");
        printf("\n2.Alugar Livro\n");
        printf("\n0.Sair\n");

        if (op == 0)
        {
            break;
        }

        if (op == 1)
        {
        }
    }

    fclose(f);
    fclose(f2);

    return 0;
}