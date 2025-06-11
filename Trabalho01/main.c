#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define QTDLIVROS 50
#define LOOP 1
#if __linux__
#define clear() system("clear")
#elif WIN32
#define clear() system("cls")
#endif

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
    int codigoLivro;
    char titulo[50];
    float valorLocacao;
} Locacao;

Livro livros[QTDLIVROS];

void printLivro(Livro l)
{
    puts("==========PRINT LIVRO==========");
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

    while (fgets(buffer, sizeof(buffer), f) != NULL && i < QTDLIVROS)
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
        // printLivro(livros[i]);
        i++;
    }
}
void storeLocacao(Locacao l, FILE *f2)
{
    fprintf(f2, "%s;%s;%d;%s;%f\n", l.cliente, l.data, l.codigoLivro, l.titulo, l.valorLocacao);
}

Livro buscarLivroPorId(int id)
{
    for (int i = 0; i < QTDLIVROS; i++)
    {
        if (livros[i].codigo == id)
        {
            return livros[i];
        }
    }

    Livro livroInválido;
    livroInválido.codigo = -1;
    return livroInválido;
}

void verTodosOsLivros()
{
    puts("======VER O CATÁLOGO=======");
    for (int i = 0; i < QTDLIVROS; i++)
    {
        printLivro(livros[i]);
    }
}

void getDataAtual(char data[])
{
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    // Formata a data como dd/mm/aaaa
    strftime(data, 11, "%d/%m/%Y", tm_info);
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
    // verTodosOsLivros();
    int op = -1;
    while (LOOP)
    {
        printf("=========LOCADORA DIGITAL==========");
        printf("\n1.Buscar Livro\n");
        printf("\n2.Alugar Livro\n");
        printf("\n3-Ver Livros no catálogo\n");
        printf("\n0.Sair\n");
        scanf("%d", &op);

        if (op == 0)
        {
            break;
        }
        else if (op == 1)
        {

            int buscar_id = 0;

            printf("\n========== BUSCAR LIVRO==========\n");
            printf("\nDigite o id do livro (1-50):");
            scanf("%d", &buscar_id);

            printf("\n==========BUSCAR LIVRO=========\n");
            Livro acharLivro = buscarLivroPorId(buscar_id);
            if (acharLivro.codigo == -1)
            {
                puts("O livro que você pediu, não existe!");
                continue;
            }

            printLivro(acharLivro);
        }
        else if (op == 2)
        {
            Locacao l;
            puts("==========ALUGAR LIVRO==========");
            printf("\nDigite o id do livro:\n");
            scanf("%d", &l.codigoLivro);

            Livro getLivro = buscarLivroPorId(l.codigoLivro);
            if (getLivro.codigo == -1)
            {
                puts("O livro que você digitou, não existe!");
                continue;
            }

            getDataAtual(l.data);
            puts("\nDigite o seu nome, por favor:");
            setbuf(stdin, NULL);
            fgets(l.cliente, sizeof(l.cliente) - 1, stdin);
            l.cliente[strcspn(l.cliente, "\n")] = '\0';
            l.valorLocacao = getLivro.valorAluguel;
            strcpy(l.titulo, getLivro.titulo);
            l.codigoLivro = getLivro.codigo;
            fprintf(f2, "%s;%s;%d;%s;%.2f\n", l.cliente, l.data, l.codigoLivro, l.titulo, l.valorLocacao);
        }
        else if (op == 3)
        {
            verTodosOsLivros();
        }
    }

    fclose(f);
    fclose(f2);
    return 0;
}