#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define QTDLIVROS 50
#define LOOP 1
/*NOME DOS ARQUIVOS PARA FOPEN*/
#define LIVROSLOCADORA_CSV "fonte.csv"
#define LOCACOES_CSV "locacoes.csv"
#define RELATORIO_ACERVO_CSV "relatorio_acervo.csv"
#define RELATORIO_LOCACOES_CSV "relatorio_locacoes.csv"

// Declaração struct
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

// Váriaveis globais( vetores em memória)
Livro livros[QTDLIVROS];
Locacao locacoes[QTDLIVROS];

// Print do livro para visualização no console.
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

Livro buscarLivroPorId(int id)
{
    // Busca sequencial no vetor carregado em memória, caso não encontre, retorna -1
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
// Dá o print de todos os livros no console.
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
    // Utiliza a estrutura struct_tm, nativa do C, para pegar o tempo em segundos, utilizando a função time(NULL)
    // com base na quantidade de segundos desde a criação da linguagem;

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t); // Formata os dados em um ponteiro para a struct.

    // Formata a data como dd/mm/aaaa
    strftime(data, 11, "%d/%m/%Y", tm_info); // Formata a data para string.
}

int ordenarAcervoPorAutor(const void *a, const void *b)
{
    Livro *cast_a = (Livro *)a; // Dá o cast nos ponteiros a e b;
    Livro *cast_b = (Livro *)b;
    return strcmp(cast_a->autor, cast_b->autor); // Realiza a comparação e retorna. qsort deve ordenar em ordem alfabética
}

int ordenarAcervoPorTitulo(const void *a, const void *b)
{
    // Mesmo caso da função acima.
    Livro *cast_a = (Livro *)a;
    Livro *cast_b = (Livro *)b;
    return strcmp(cast_a->titulo, cast_b->titulo); // Realiza a comparação e retorna. qsort deve ordenar em ordem alfabética
}

int ordenarAcervoPorId(const void *a, const void *b)
{
    // Dá o cast diretamente, em uma linha e retorna para a função qsort.
    return *(int *)a - *(int *)b;
}

int ordenarLocacaoPorData(const void *a, const void *b)
{
    Locacao *cast_a = (Locacao *)a;
    Locacao *cast_b = (Locacao *)b;

    return strcmp(cast_a->data, cast_b->data);
}

void printLocacao()
{
    puts("==========PRINT LOCACAO==========");
    for (int i = 0; i < QTDLIVROS; i++)
    {
        printf("\nNome:%s", locacoes[i].cliente);
        printf("\nData:%s", locacoes[i].data);
        printf("\nId:%d", locacoes[i].codigoLivro);
        printf("\nValor:R$%.2f", locacoes[i].valorLocacao);
    }
    printf("\n");
}

void buscarLivroCódigo(int id)
{
    // Realiza a busca sequencial no vetor carregado em memória dos livros.
    puts("==========BUSCAR LIVRO:Código ==========");
    int i;
    for (i = 0; i < QTDLIVROS; i++)
    {
        if (livros[i].codigo == id)
        {
            printLivro(livros[i]);
        }
    }
}

void buscarPeloGenero(const char genero[])
{
    // Busca sequencialmente pelo gênero, comparando o vetor de entrada, com o vetor carregado com os dados do .csv
    puts("==========Buscar Livro: Gênero==========");
    int i;
    for (i = 0; i < QTDLIVROS; i++)
    {
        if (strcmp(livros[i].genero, genero) == 0)
        {
            printLivro(livros[i]);
        }
    }
}

void buscarPeloTitulo(const char nomeLivro[])
{
    // Busca sequencialmente pelo gênero, comparando o vetor de entrada, com o vetor carregado com os dados do .csv
    puts("==========Buscar Livro:Título ==========");
    int i;
    for (i = 0; i < QTDLIVROS; i++)
    {
        if (strcmp(livros[i].titulo, nomeLivro) == 0)
        {
            printLivro(livros[i]);
        }
    }
}

void loadLivros()
{
    char buffer[256];                                                 // Define o tamanho de leitura da linha;
    int i = 0;                                                        // Inicializa contador
    FILE *f = fopen(LIVROSLOCADORA_CSV, "r");                         // Abre arquivo para leitura
    while (fgets(buffer, sizeof(buffer), f) != NULL && i < QTDLIVROS) // Cria Loop sequencial para ler o arquivo, até que se esgote as linhas
    {                                                                 // e o contador chegue ao limite; guarda a linha na str buffer, com o limite de 256 linhas.
        // puts(buffer);
        char *token = strtok(&buffer[0], ";"); // Quebra em tokens a partir do ;, característico do .csv, posteriormente carregado na string buffer
        livros[i].codigo = atoi(token);        // Converte a string em int, com o uso da função atoi()
        // puts(token);

        token = strtok(NULL, ";"); // Continua quebrando a string em tokens e realiza a cópia do token para a estrutura
        strcpy(livros[i].titulo, token);
        // puts(token);

        token = strtok(NULL, ";"); // Continua quebrando a string em tokens realiza a cópia do token para a estrutura
        strcpy(livros[i].autor, token);
        // puts(token);

        token = strtok(NULL, ";");
        livros[i].ano = atoi(token);
        // puts(token);

        token = strtok(NULL, ";"); // Continua quebrando a string em tokens ee realiza a cópia do token para a estrutura
        strcpy(livros[i].editora, token);

        token = strtok(NULL, ";"); // // Continua quebrando a string em tokens e utiliza asci to float para converter string em um número com vírgula.
        livros[i].valorAluguel = atof(token);
        // printLivro(livros[i]);

        token = strtok(NULL, ";"); // Quebra o ultimo pedaço em tokens e copia o token para a estrutura.
        strcpy(livros[i].genero, token);
        // puts(token);
        i++;
    }
    fclose(f);
}
void storeLocacao(Locacao l)
{
    if (sizeof(Locacao) / sizeof(locacoes) >= 50)
    {
        puts("Não é possível realizar mais locações.");
        return;
    }
    FILE *f = fopen(LOCACOES_CSV, "w"); // Abre o arquivo e dá um fprintf formatado nele, depois o fecha.
    fprintf(f, "%s;%s;%d;%s;%f\n", l.cliente, l.data, l.codigoLivro, l.titulo, l.valorLocacao);
    fclose(f);
}
void loadLocacoes()
{
    FILE *file = fopen(LOCACOES_CSV, "r");
    char buffer[256];                                                    // Define o tamanho de leitura da linha;
    int i = 0;                                                           // Inicializa contador                      // Abre arquivo para leitura
    while (fgets(buffer, sizeof(buffer), file) != NULL && i < QTDLIVROS) // Cria Loop sequencial para ler o arquivo, até que se esgote as linhas
    {                                                                    // e o contador chegue ao limite; guarda a linha na str buffer, com o limite de 256 linhas.
        // puts(buffer);
        char *token = strtok(&buffer[0], ";"); // Quebra em tokens a partir do ;, característico do .csv, posteriormente carregado na string buffer
        strcpy(locacoes[i].cliente, token);    // Converte a string em int, com o uso da função atoi()
        // puts(token);

        token = strtok(NULL, ";"); // Continua quebrando a string em tokens e realiza a cópia do token para a estrutura
        strcpy(locacoes[i].data, token);
        // puts(token);

        token = strtok(NULL, ";"); // Continua quebrando a string em tokens realiza a cópia do token para a estrutura
        locacoes[i].codigoLivro = atoi(token);
        // puts(token);

        token = strtok(NULL, ";");
        strcpy(locacoes[i].titulo, token);
        // puts(token);

        token = strtok(NULL, ";"); // Continua quebrando a string em tokens ee realiza a cópia do token para a estrutura
        locacoes[i].valorLocacao = atof(token);
        i++;
    }
    fclose(file);
}
int main(void)
{
    setlocale(LC_ALL, ""); // Suporte para acentos

    loadLivros();

    int op = -1;
    while (LOOP) // Cria um loop infinito
    {
        printf("\n=========LOCADORA DIGITAL==========\n");
        printf("1.Buscar Livro\n");
        printf("2.Alugar Livro\n");
        printf("3-Ver Acervo de Livros\n");
        printf("4-Ver Todas as Locações\n");
        printf("0.Sair\n");
        scanf("%d", &op); // Entrada da opção

        if (op == 0) // Se a opção for igual a zero, força a quebrar.
        {
            break;
        }
        else if (op == 1)
        {
            // Filtro das buscas
            int submenu = 0;
            printf("\n1 - Buscar Livro por título:");
            printf("\n2 - Buscar Livro por código:");
            printf("\n3 - Buscar Livro por gênero:");
            printf("\n0 - Voltar");
            scanf("%d", &submenu);

            switch (submenu)
            {
            case 1:

                // Recebe o título e procura.
                char titulo[30];
                printf("\nDigite o título do livro:");
                setbuf(stdin, NULL);
                fgets(titulo, sizeof(titulo) - 1, stdin);
                titulo[strcspn(titulo, "\n")] = '\0';
                buscarPeloTitulo(titulo);
                break;
            case 2:
                // Recebe o id do livro e procura
                int buscar_id = 0;
                printf("\n==========BUSCAR LIVRO POR ID==========\n");
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
                break;

            case 3:
                char genero[30];
                printf("\nDigite o gênero do livro:");
                setbuf(stdin, NULL);
                fgets(genero, sizeof(genero) - 1, stdin);
                genero[strcspn(genero, "\n")] = '\0';
                buscarPeloGenero(genero);
                break;
            case 0:
                puts("Você escolheu voltar!");
                break;

            default:
                puts("Opção inválida!");
                break;
            }
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
            storeLocacao(l);
        }
        else if (op == 3)
        {
            int submenu = 0;
            puts("==========VER ACERVO DE LIVROS ==========");
            printf("1 - Ordernar por Autor\n");
            printf("2 - Ordernar por Título\n");
            printf("3 - Ordernar por Id\n");
            printf("3 - Voltar\n");
            scanf("%d", &submenu);

            switch (submenu)
            {
            case 1:
                qsort(livros, QTDLIVROS, sizeof(Livro), ordenarAcervoPorAutor);
                break;

            case 2:
                qsort(livros, QTDLIVROS, sizeof(Livro), ordenarAcervoPorTitulo);
                break;
            case 3:
                qsort(livros, QTDLIVROS, sizeof(Livro), ordenarAcervoPorId);
                break;

            case 4:
                puts("Você escolheu voltar!");
                break;

            default:
                puts("Opção Inválida!");
                break;
            }
            verTodosOsLivros();

            if (submenu >= 1 && submenu <= 3)
            {
                qsort(livros, QTDLIVROS, sizeof(Livro), ordenarAcervoPorId);
            }
        }
        else if (op == 4)
        {
            int submenu = 0;
            loadLocacoes();
            qsort(locacoes, QTDLIVROS, sizeof(Locacao), ordenarLocacaoPorData);
            printLocacao();
        }
    }
    return 0;
}