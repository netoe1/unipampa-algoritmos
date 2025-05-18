/*

Fazer um programa para simular uma agenda de telefones. Para cada pessoa devem-se ter os seguintes dados:

• Nome

• E-mail

• Endereço (contendo campos para Rua, número, complemento, bairro, cep, cidade,

estado, país).

• Telefone (contendo campo para DDD e número)

• Data de aniversário (contendo campo para dia, mês, ano).

• Observações: Uma linha (string) para alguma observação especial.

(a) Definir a estrutura acima.

(b) Declarar a variável agenda (vetor) com capacidade de agendar até 100 nomes.

(c) Definir um bloco de instruções busca por primeiro nome: Imprime os dados da pessoa com esse nome (se tiver mais de uma pessoa, imprime para todas).

(d) Definir um bloco de instruções busca por mês de aniversário: Imprime os dados de todas as pessoas que fazem aniversário nesse mês.

(e) Definir um bloco de instruções busca por dia e mês de aniversário: Imprime os dados de todas as pessoas que fazem aniversário nesse dia e mês.

(f) Definir um bloco de instruções insere pessoa: Insere por ordem alfabética de nome.

(g) Definir um bloco de instruções retira pessoa: Retira todos os dados dessa pessoa e desloca todos os elementos seguintes do vetor para a posição anterior.

(h) Definir um bloco de instruções imprime agenda com as opções:

• Imprime nome, telefone e e-mail.

• Imprime todos os dados.

(i) O programa deve ter um menu principal oferecendo as opções acima.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define N 100

typedef struct
{
    char ddd[2];
    char numero[9];
} Telefone;

typedef struct
{
    char rua[32];
    char numero[4];
    char complemento[16];
    char bairro[16];

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
    char observacoes[32];
} Agenda;

Agenda pessoas[100];
int global_counter = 0;

void sgets(char *s, size_t size, FILE *stream)
{
    setbuf(stdin, NULL);
    fgets(s, size, stream);
    s[strcspn(s, "\n")] = '\0';
}
void printPessoa(Agenda *pessoa);
void buscarPessoaPorNome(char *nome);
void buscarPorDiaEMes(int dia, int mes);
void ordenarVetorAlfabetico()
{
    int i = 0;
    for (i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            char backup[32];
            strcpy(backup, pessoas[i].nome);

            if (strcmp(pessoas[j].nome, pessoas[i].nome) > 0)
            {
                char backup[32];
                strcpy(backup, pessoas[j].nome);
                strcpy(pessoas[j].nome, pessoas[i].nome);
                strcpy(pessoas[j].nome, backup);
            }
        }
    }
}
void inserePessoa()
{
    if (global_counter < 100)
    {
        // printf("\nNome:%s", pessoas[global_counter].nome);
        // printf("\nEmail:%s", pessoas[global_counter].email);
        // printf("\nRua:%s", pessoas[global_counter].rua);
        // printf("\nNúmero:%s", pessoas[global_counter].numero);
        // printf("\nComplemento:%s", pessoas[global_counter].complemento);
        // printf("\nBairro%s", pessoas[global_counter].bairro);
        // printf("\nData de aniversário: %d/%d/%d", pessoa->dataAniversario.dia, pessoa->dataAniversario.mes, pessoa->dataAniversario.ano);
        // printf("\nObservações:%s", pessoa->observacoes);

        puts("Nome:");
        sgets(pessoas[global_counter].nome, sizeof(pessoas[global_counter].nome) - 1, stdin);
        puts("Email:");
        sgets(pessoas[global_counter].email, sizeof(pessoas[global_counter].email) - 1, stdin);
        puts("Rua:");
        sgets(pessoas[global_counter].endereco.rua, sizeof(pessoas[global_counter].endereco.rua) - 1, stdin);
        puts("Número:");
        sgets(pessoas[global_counter].endereco.numero, sizeof(pessoas[global_counter].endereco.numero) - 1, stdin);
        puts("Complemento:");
        sgets(pessoas[global_counter].endereco.complemento, sizeof(pessoas[global_counter].endereco.complemento) - 1, stdin);
        puts("Bairro:");
        sgets(pessoas[global_counter].endereco.bairro, sizeof(pessoas[global_counter].endereco.bairro) - 1, stdin);
        puts("\nData de aniversário: Dia-Mês-Ano");
        scanf("%d %d %d", &pessoas[global_counter].dataAniversario.dia, pessoas[global_counter].dataAniversario.mes, pessoas[global_counter].dataAniversario.ano);
        puts("\nObservações:");
        sgets(pessoas[global_counter].observacoes, sizeof(pessoas[global_counter].observacoes) - 1, stdin);
        ordenarVetorAlfabetico();
    }
}

void removePessoa(int index)
{
    int i = 0;
    for (int i = 0; i < N; i++)
    {
        if (index == i)
        {
            strcpy(pessoas[i].email, "");
            strcpy(pessoas[i].nome, "");
            strcpy(pessoas[i].observacoes, "");
            strcpy(pessoas[i].telefone.ddd, "");
            strcpy(pessoas[i].telefone.numero, "");
            strcpy(pessoas[i].endereco.bairro, "");
            strcpy(pessoas[i].endereco.rua, "");
            strcpy(pessoas[i].endereco.complemento, "");
            strcpy(pessoas[i].endereco.numero, "");
            pessoas[i].dataAniversario.dia = 0;
            pessoas[i].dataAniversario.mes = 0;
            pessoas[i].dataAniversario.ano = 0;
            global_counter--;
            break;
        }
    }
    Agenda pessoaFrente;
    for (int x = i + 1; x < N - 1; x++)
    {
    }
}
int main(void)
{
}

void printPessoa(Agenda *pessoa)
{
    printf("\n----------DADOS PESSOA----------\n");
    printf("\nNome:%s", pessoa->nome);
    printf("\nEmail:%s", pessoa->email);
    printf("\nRua:%s", pessoa->endereco.rua);
    printf("\nNúmero:%s", pessoa->endereco.numero);
    printf("\nComplemento:%s", pessoa->endereco.complemento);
    printf("\nBairro%s", pessoa->endereco.bairro);
    printf("\nData de aniversário: %d/%d/%d", pessoa->dataAniversario.dia, pessoa->dataAniversario.mes, pessoa->dataAniversario.ano);
    printf("\nObservações:%s", pessoa->observacoes);
}

void buscarPessoaPorNome(char *nome)
{
    int i = 0;
    for (i = 0; i < N; i++)
    {
        if (strcmp(nome, pessoas[i].nome) == 0)
        {
            printPessoa(&pessoas[i]);
        }
    }
}

void buscarPorDiaEMes(int dia, int mes)
{
    int i = 0;
    for (i = 0; i < N; i++)
    {
        if (pessoas[i].dataAniversario.dia == dia && pessoas[i].dataAniversario.mes == mes)
        {
            printPessoa(&pessoas[i]);
        }
    }
}