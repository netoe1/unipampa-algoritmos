/*

    Exercício 1: Controle de Estoque com Struct e Arquivo Texto
Você está desenvolvendo um sistema básico de controle de estoque para uma pequena loja. O
sistema deve utilizar `struct` em C para armazenar os dados dos produtos e permitir o salvamento
e a leitura desses dados a partir de um arquivo texto.
Requisitos:
1. Defina uma estrutura `Produto` com os seguintes campos:
 * int codigo; – código do produto
 * char nome[50]; – nome do produto
 * int quantidade; – quantidade disponível em estoque
 * float preco; – preço unitário do produto
2. O programa deve permitir ao usuário:
 * Cadastrar produtos (um ou mais).
 * Gravar os dados dos produtos em um arquivo texto chamado "estoque.txt" no seguinte
formato:
 Codigo Nome Quantidade Preco
 ```
3. Após o cadastro, o programa deve:
 * Ler os dados do arquivo "estoque.txt" e exibir todos os produtos cadastrados.
 * Permitir a busca de um produto pelo código e mostrar suas informações.
 * Calcular e exibir o valor total em estoque de todos os produtos (quantidade × preço).
Regras:
* Use funções separadas para:
 * Cadastrar produtos
 * Salvar em arquivo
 * Ler do arquivo
 * Buscar por código
 * Calcular valor total em estoque
 * Utilize boas práticas de programação e tratamento de erros (como falha ao abrir arquivos).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Retornos
#define MAX_PRODUTOS 100
#define PRODUTO_NAO_EXISTE -1
#define SEM_VALOR -1

// Nome do arquivo
#define ESTOQUE_TXT "estoque.txt"

typedef struct
{
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

Produto cadastrarProduto();
Produto procurarProdutoPorId(int id);
Produto resetProduto();
void salvarArquivo();
void lerArquivo();
float calcularValorEstoque();
void printProduto(Produto p);
void printTodosOsProdutos();
Produto todosOsProdutos[MAX_PRODUTOS];
int nAtual = 0;

int main(void)
{
    setlocale(LC_ALL, "");
    int op = 0;
    lerArquivo();
    do
    {
        while (1)
        {
            puts("Selecione uma das opções:\n1-Cadastrar novo produto\n2-Buscar produto por id\n3-Buscar todos os produtos\n4-Calcular Valor do Estoque\n0-Sair");
            scanf("%d", &op);

            if (op < 0)
            {
                puts("Opção inválida!");
                continue;
            }
            break;
        }

        switch (op)
        {
        case 1:
            printProduto(cadastrarProduto());
            salvarArquivo();
            break;
        case 2:

            int id = 0;
            while (1)
            {
                puts("Digite o id do produto:");
                scanf("%d", &id);

                if (id < 0)
                {
                    puts("Valor inválido para produto.");
                    continue;
                }
                break;
            }

            Produto buscar = procurarProdutoPorId(id);
            printProduto(buscar);
            if (buscar.codigo == -1)
            {
                puts("Não foi possível encontrar o produto!");
            }

            break;
        case 3:
            printTodosOsProdutos();
            break;
        case 4:
            printf("\nValor Total do estoque:R$%.2f", calcularValorEstoque());
        case 0:
            puts("Saindo....");
            break;
        default:
            puts("Opção inválida!");
            break;
        }

    } while (op != 0);

    return 0;
}

Produto resetProduto()
{
    Produto reset = {PRODUTO_NAO_EXISTE, "0", SEM_VALOR, 0.0};
    return reset;
}

Produto procurarProdutoPorId(int id)
{

    for (int i = 0; i < MAX_PRODUTOS; i++)
    {
        if (todosOsProdutos[i].codigo == id)
        {
            return todosOsProdutos[i];
        }
    }

    return resetProduto();
}

Produto cadastrarProduto()
{
    if (nAtual == MAX_PRODUTOS)
    {
        puts("Você já chegou ao limite do sistema!");
        return resetProduto();
    }

    Produto novoProduto;

    while (1)
    {

        printf("\n======CADASTRAR-PRODUTO======\n");
        puts("Digite o código do produto");
        scanf("%d", &novoProduto.codigo);
        if (novoProduto.codigo < 0)
        {
            printf("\nId Inválido, por favor, digite um válido.");
            continue;
        }

        if (procurarProdutoPorId(novoProduto.codigo).codigo != PRODUTO_NAO_EXISTE)
        {
            puts("Esse código que você tentou informar já existe, por favor, digite outro.");
            novoProduto = resetProduto();
            continue;
        }
        break;
    }

    puts("Digite o nome do produto:");
    setbuf(stdin, NULL);
    fgets(novoProduto.nome, sizeof(novoProduto.nome) - 1, stdin);
    novoProduto.nome[strcspn(novoProduto.nome, "\n")] = '\0';

    while (1)
    {
        puts("Digite a quantidade do produto");
        scanf("%d", &novoProduto.quantidade);
        if (novoProduto.quantidade < 0.0)
        {
            puts("O produto não pode ter quantidade negativa, digite novamente!");
            continue;
        }
        break;
    }

    while (1)
    {
        puts("Digite o valor do produto");
        scanf("%f", &novoProduto.preco);
        if (novoProduto.preco < 0.0)
        {
            puts("O preco não pode ser negativo, digite novamente!");
            continue;
        }
        break;
    }

    nAtual++;
    return novoProduto;
}

float calcularValorEstoque()
{
    float sum = 0.0;
    for (int i = 0; i < MAX_PRODUTOS; i++)
    {
        sum += todosOsProdutos[i].preco * todosOsProdutos[i].quantidade;
    }

    return sum;
}

void lerArquivo()
{
    FILE *file = fopen(ESTOQUE_TXT, "r");
    if (!file)
    {
        puts("Não foi possível achar o arquivo .txt ou você não tem permissão!");
        exit(EXIT_FAILURE);
    }
    int i = 0;

    while (fscanf(file, "%d %49s %d %f",
                  &todosOsProdutos[i].codigo,
                  todosOsProdutos[i].nome,
                  &todosOsProdutos[i].quantidade,
                  &todosOsProdutos[i].preco) == 4 &&
           i == MAX_PRODUTOS)
    {

        printProduto(todosOsProdutos[i]);

        i++;
    }

    fclose(file);
}

void printProduto(Produto p)
{
    if (!((p.codigo == 0 || p.codigo == 1) && p.quantidade == 0 && p.preco == 0.0))
        printf("\nCódigo:%d\nNome:%s\nQuantidade:%d\nPreço:%.2f\n", p.codigo, p.nome, p.quantidade, p.preco);
}

void printTodosOsProdutos()
{
    for (int i = 0; i < MAX_PRODUTOS; i++)
    {
        printProduto(todosOsProdutos[i]);
    }
}

void salvarArquivo()
{
    FILE *file = fopen(ESTOQUE_TXT, "w");
    if (!file)
    {
        puts("Erro ao salvar arquivo!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nAtual; i++)
    {
        fprintf(file, "%d %s %d %.2f\n", todosOsProdutos[i].codigo, todosOsProdutos[i].nome, todosOsProdutos[i].quantidade, todosOsProdutos[i].preco);
    }

    fclose(file);
}