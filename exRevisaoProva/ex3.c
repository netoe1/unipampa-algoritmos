/*
3: Agenda Telefônica com Busca
Crie uma struct Contato com os campos nome, telefone e email.
Permita ao usuário:
1. Cadastrar até 100 contatos
2. Buscar um contato pelo nome e exibir os dados, se encontrado
3. Exibir todos os contatos cadastrados
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 100
typedef struct
{
    char nome[30];
    char telefone[30];
    char email[30];
} Contato;

int ix = 0;
Contato todos[MAX];

void cadastrarContato()
{
    if (ix != MAX)
    {
        Contato novo;
        puts("\nDigite o nome do contato:");
        setbuf(stdin, NULL);
        fgets(novo.nome, sizeof(novo.nome) - 1, stdin);
        novo.nome[strcspn(novo.nome, "\n")] = '\0';

        puts("\nDigite o telefone:");
        setbuf(stdin, NULL);
        fgets(novo.telefone, sizeof(novo.telefone) - 1, stdin);
        novo.telefone[strcspn(novo.telefone, "\n")] = '\0';

        puts("\nDigite o email:");
        setbuf(stdin, NULL);
        fgets(novo.email, sizeof(novo.email) - 1, stdin);
        novo.email[strcspn(novo.email, "\n")] = '\0';
        todos[ix] = novo;
        ix++;
        return;
    }

    puts("Os cadastros chegaram ao limite!");
}

void buscarContato(char nome[30])
{
    for (int i = 0; i != ix; i++)
    {
        if (strcmp(nome, todos[i].nome) == 0)
        {
            printf("\nNome:%s\nTelefone:%s\nEmail:%s\n", todos[i].nome, todos[i].telefone, todos[i].email);
        }
    }

    puts("Não foi encontrado o contato.");
}

void mostrarTodos()
{
    for (int i = 0; i != ix; i++)
    {
        printf("\nNome:%s\nTelefone:%s\nEmail:%s\n", todos[i].nome, todos[i].telefone, todos[i].email);
    }
}

int main(void)
{
    int op;

    do
    {
        printf("\n=====Agenda=====\n1-Cadastrar contato\n2-Mostrar contato pelo nome\n3-Mostrar Todos\n0-Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            cadastrarContato();
            break;

        case 2:
            char nome[30];
            puts("\nDigite o nome do contato:");
            setbuf(stdin, NULL);
            fgets(nome, sizeof(nome) - 1, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            buscarContato(nome);
            break;

        case 3:
            mostrarTodos();
            break;

        default:
            break;
        }
    } while (op != 0);
    return 0;
}
