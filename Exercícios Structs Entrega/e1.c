#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define IMPRIMIR_RESUMIDO 0
#define IMPRIMIR_TUDO 1
#define N 100

typedef struct
{
    char ddd[3];
    char numero[10];
} Telefone;

typedef struct
{
    char rua[32];
    char numero[10];
    char complemento[16];
    char bairro[16];
    char cep[10];
    char cidade[32];
    char estado[4];
    char pais[32];
} Endereco;

typedef struct
{
    int dia;
    int mes;
    int ano;
} DataAniversario;

typedef struct
{
    char nome[32];
    char email[32];
    Endereco endereco;
    Telefone telefone;
    DataAniversario dataAniversario;
    char observacoes[64];
} Agenda;

Agenda pessoas[N];
int global_counter = 0;

void sgets(char *s, size_t size, FILE *stream)
{
    setbuf(stdin, NULL);
    fgets(s, size, stream);
    s[strcspn(s, "\n")] = '\0';
}

void printPessoa(Agenda *pessoa)
{
    printf("\nNome: %s", pessoa->nome);
    printf("\nEmail: %s", pessoa->email);
    printf("\nTelefone: (%s) %s", pessoa->telefone.ddd, pessoa->telefone.numero);
    printf("\nEndereço: %s, %s, %s, %s, CEP: %s, %s, %s, %s",
           pessoa->endereco.rua, pessoa->endereco.numero,
           pessoa->endereco.complemento, pessoa->endereco.bairro,
           pessoa->endereco.cep, pessoa->endereco.cidade,
           pessoa->endereco.estado, pessoa->endereco.pais);
    printf("\nData de aniversário: %02d/%02d/%04d",
           pessoa->dataAniversario.dia,
           pessoa->dataAniversario.mes,
           pessoa->dataAniversario.ano);
    printf("\nObservações: %s\n", pessoa->observacoes);
}

void printPessoaResumida(Agenda *pessoa)
{
    printf("\nNome: %s", pessoa->nome);
    printf("\nTelefone: (%s) %s", pessoa->telefone.ddd, pessoa->telefone.numero);
    printf("\nEmail: %s\n", pessoa->email);
}

void ordenarVetorAlfabetico()
{
    for (int i = 0; i < global_counter - 1; i++)
    {
        for (int j = i + 1; j < global_counter; j++)
        {
            if (strcmp(pessoas[i].nome, pessoas[j].nome) > 0)
            {
                Agenda temp = pessoas[i];
                pessoas[i] = pessoas[j];
                pessoas[j] = temp;
            }
        }
    }
}

void inserePessoa()
{
    if (global_counter >= N)
    {
        puts("Agenda cheia!");
        return;
    }

    Agenda nova;

    puts("Nome:");
    sgets(nova.nome, sizeof(nova.nome), stdin);

    puts("Email:");
    sgets(nova.email, sizeof(nova.email), stdin);

    puts("Telefone - DDD:");
    sgets(nova.telefone.ddd, sizeof(nova.telefone.ddd), stdin);

    puts("Telefone - Número:");
    sgets(nova.telefone.numero, sizeof(nova.telefone.numero), stdin);

    puts("Rua:");
    sgets(nova.endereco.rua, sizeof(nova.endereco.rua), stdin);

    puts("Número:");
    sgets(nova.endereco.numero, sizeof(nova.endereco.numero), stdin);

    puts("Complemento:");
    sgets(nova.endereco.complemento, sizeof(nova.endereco.complemento), stdin);

    puts("Bairro:");
    sgets(nova.endereco.bairro, sizeof(nova.endereco.bairro), stdin);

    puts("CEP:");
    sgets(nova.endereco.cep, sizeof(nova.endereco.cep), stdin);

    puts("Cidade:");
    sgets(nova.endereco.cidade, sizeof(nova.endereco.cidade), stdin);

    puts("Estado:");
    sgets(nova.endereco.estado, sizeof(nova.endereco.estado), stdin);

    puts("País:");
    sgets(nova.endereco.pais, sizeof(nova.endereco.pais), stdin);

    printf("Data de aniversário (dia mes ano): ");
    setbuf(stdin, NULL);
    scanf("%d %d %d", &nova.dataAniversario.dia, &nova.dataAniversario.mes, &nova.dataAniversario.ano);
    getchar();

    puts("Observações:");
    sgets(nova.observacoes, sizeof(nova.observacoes), stdin);

    pessoas[global_counter++] = nova;
    ordenarVetorAlfabetico();
}
void removePessoa(int index)
{
    if (index < 0 || index >= global_counter)
    {
        puts("Índice inválido.");
        return;
    }
    for (int i = index; i < global_counter - 1; i++)
    {
        pessoas[i] = pessoas[i + 1];
    }
    global_counter--;
    puts("A pessoa foi removida");
}

void buscarPessoaPorNome(char *nome)
{
    int encontrou = 0;
    for (int i = 0; i < global_counter; i++)
    {
        if (strstr(pessoas[i].nome, nome))
        {
            printPessoa(&pessoas[i]);
            encontrou = 1;
        }
    }
    if (!encontrou)
    {
        puts("Pessoa não encontrada.");
    }
}

void buscarPorMes(int mes)
{
    for (int i = 0; i < global_counter; i++)
    {
        if (pessoas[i].dataAniversario.mes == mes)
        {
            printPessoa(&pessoas[i]);
        }
    }
}

void buscarPorDiaEMes(int dia, int mes)
{
    for (int i = 0; i < global_counter; i++)
    {
        if (pessoas[i].dataAniversario.dia == dia && pessoas[i].dataAniversario.mes == mes)
        {
            printPessoa(&pessoas[i]);
        }
    }
}

void printPessoas(int code)
{
    for (int i = 0; i < global_counter; i++)
    {
        if (code == IMPRIMIR_RESUMIDO)
        {
            printPessoaResumida(&pessoas[i]);
        }
        else if (code == IMPRIMIR_TUDO)
        {
            printPessoa(&pessoas[i]);
        }
    }
}

int main(void)
{
    setlocale(LC_ALL, "");
    int opc = -1;

    while (opc != 0)
    {
        printf("\nMenu:\n");
        printf("1 - Inserir Pessoa\n");
        printf("2 - Remover Pessoa (por índice)\n");
        printf("3 - Mostrar agenda (resumido)\n");
        printf("4 - Mostrar agenda (completo)\n");
        printf("5 - Buscar por nome\n");
        printf("6 - Buscar por mês de aniversário\n");
        printf("7 - Buscar por dia e mês de aniversário\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc);
        getchar();

        if (opc == 1)
        {
            inserePessoa();
        }
        else if (opc == 2)
        {
            int index;
            printf("Índice para remover (0 a %d): ", global_counter - 1);
            scanf("%d", &index);
            getchar();
            removePessoa(index);
        }
        else if (opc == 3)
        {
            printPessoas(IMPRIMIR_RESUMIDO);
        }
        else if (opc == 4)
        {
            printPessoas(IMPRIMIR_TUDO);
        }
        else if (opc == 5)
        {
            char nome[32];
            puts("Digite o nome para buscar:");
            sgets(nome, sizeof(nome), stdin);
            buscarPessoaPorNome(nome);
        }
        else if (opc == 6)
        {
            int mes;
            printf("Digite o mês (1-12): ");
            scanf("%d", &mes);
            getchar();
            buscarPorMes(mes);
        }
        else if (opc == 7)
        {
            int dia, mes;
            printf("Digite dia e mês: ");
            setbuf(stdin, NULL);
            scanf("%d %d", &dia, &mes);
            getchar();
            buscarPorDiaEMes(dia, mes);
        }
    }

    return 0;
}
