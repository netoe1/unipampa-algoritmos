#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "ex2.h"
#include "sgets.c"
/*
Exercício 2: Sistema de Gerenciamento de Funcionários com Arquivo Binário
Você foi contratado para criar um sistema simples de gerenciamento de funcionários para uma
empresa. Este sistema deve utilizar uma estrutura (`struct`) para representar os funcionários, e
todos os dados devem ser armazenados permanentemente em um **arquivo binário** chamado
"funcionarios.bin".
Requisitos
1. Defina uma estrutura Funcionario com os seguintes campos:
 typedef struct {
 int id; // Código único do funcionário
 char nome[100]; // Nome completo
 char cargo[50]; // Cargo ocupado
 float salario; // Salário mensal
 } Funcionario;

2. O sistema deve apresentar um menu com as seguintes opções:
 1. Cadastrar novo funcionário
 2. Listar todos os funcionários
 3. Buscar funcionário por ID
 4. Alterar dados de um funcionário
 5. Remover funcionário
 6. Sair
 ```
Detalhamento das funcionalidades
1. Cadastrar novo funcionário
* O usuário informa os dados do funcionário.
* O sistema salva os dados no arquivo binário "funcionarios.bin" sem apagar os existentes.
* O ID deve ser único. Verifique se já existe no arquivo antes de cadastrar.
2. Listar todos os funcionários
* O programa lê o arquivo binário e exibe todos os funcionários em uma tabela com cabeçalho.
* Exemplo de saída:
 ID Nome Cargo Salário
 1 João Silva Analista 3500.00
 2 Maria Souza Gerente 5800.00
3. Buscar funcionário por ID
* O usuário digita um ID e o sistema procura no arquivo.
* Se encontrado, exibe os dados do funcionário; senão, exibe mensagem de erro.
4. Alterar dados de um funcionário
* O usuário fornece um ID.
* O programa busca o funcionário, permite editar cargo e salário, e atualiza os dados diretamente
no arquivo.
5. Remover funcionário
* O sistema cria um novo arquivo temporário copiando todos os funcionários exceto o que tem o
ID informado.
* Depois, substitui o arquivo original por este novo.
* Essa operação remove de fato o registro.
6. Sair
* Finaliza o programa.
Regras e observações
* Use funções específicas para cada operação.
* Trate erros como: não conseguir abrir arquivos, digitação inválida, ID duplicado, etc.
* Organize bem o código e use comentários para facilitar a leitura.
*/
// #pragma region CONSTS
// #define ARQUIVO_BIN "funcionarios.bin"
// #define MAX_FUNCIONARIOS 200
// #define FUNCIONARIO_INVALIDO -1
// #pragma endregion CONSTS

// #pragma region STRUCT_DEFINITION
// typedef struct
// {
//     int id;         // Código único do funcionário
//     char nome[100]; // Nome completo
//     char cargo[50]; // Cargo ocupado
//     float salario;  // Salário mensal
// } Funcionario;

// #pragma endregion STRUCT_DEFINITION
Funcionario todosOsFuncionarios[MAX_FUNCIONARIOS];
int funcionariosIndex = 0;

// #pragma region HEADER
// Funcionario
// funcionarioInvalido();
// Funcionario cadastrarFuncionario();
// void listarTodosOsFuncionarios();
// Funcionario buscarFuncionarioPorId(int id);
// Funcionario editarDadosDoFuncionaro(int id, char cargoNovo[50], float salarioNovo);
// Funcionario removerFuncionario(int id);
// int getFuncionarioIndex(int id);
// void resetarMemoria();
// void printFuncionario(Funcionario f);
// void lerArquivo();
// void salvarArquivo();
// void saltarArquivo_caseDeletar();

// #pragma endregion HEADER

int main(void)
{
    setlocale(LC_ALL, "");
    resetarMemoria();

    return EXIT_SUCCESS;
}

#pragma region IMPLEMENTATION
Funcionario cadastrarFuncionario()
{
    Funcionario novoFuncionario;
    int op = 0;
    if (funcionariosIndex == MAX_FUNCIONARIOS)
    {
        puts("[ERRO]: Você chegou ao limite máximo de cadastro do sistema!");
        return funcionarioInvalido();
    }

    while (1)
    {
        printf("\nID:");
        scanf("%d", &novoFuncionario.id);

        if (novoFuncionario.id < 0)
        {
            puts("[ERRO]: O id do funcionário não pode ser negativo!");
            continue;
        }

        if (buscarFuncionarioPorId(novoFuncionario.id).id != -1)
        {
            puts("[ERRO]: Esse funcionário já existe, digite outro id!");
            continue;
        }
        break;
    }

    printf("\nNome:");
    sgets(novoFuncionario.nome, sizeof(novoFuncionario.nome) - 1);
    printf("\nCargo:");
    sgets(novoFuncionario.cargo, sizeof(novoFuncionario.cargo) - 1);
    while (1)
    {
        printf("\nSalário:");
        scanf("%f", &novoFuncionario.salario);
        if (novoFuncionario.salario <= 0)
        {
            puts("O salário do funcionário deve ser > 0!");
            continue;
        }
        break;
    }
    funcionariosIndex++;

    return novoFuncionario;
}

Funcionario funcionarioInvalido()
{
    Funcionario erro;
    erro.id = -1;
    erro.salario = -1;
    return erro;
}

void listarTodosOsFuncionarios()
{
    for (int i = 0; i < MAX_FUNCIONARIOS; i++)
    {
        if (todosOsFuncionarios[i].id != FUNCIONARIO_INVALIDO)
        {
            printFuncionario(todosOsFuncionarios[i]);
        }
    }
}

Funcionario buscarFuncionarioPorId(int id)
{
    for (int i = 0; i < MAX_FUNCIONARIOS; i++)
    {
        if (todosOsFuncionarios[i].id == id)
        {
            return todosOsFuncionarios[i];
        }
    }
    return funcionarioInvalido();
}

Funcionario editarDadosDoFuncionario(int id, char cargoNovo[50], float salarioNovo)
{
    int func_id = getFuncionarioIndex(id);
    if (func_id == -1)
    {
        puts("[ERRO]:O funcionário não existe!");
        return funcionarioInvalido();
    }

    strcpy(todosOsFuncionarios[func_id].cargo, cargoNovo);
    todosOsFuncionarios[func_id].salario = salarioNovo;

    return todosOsFuncionarios[func_id];
}

Funcionario removerFuncionario(int id)
{
    int index = getFuncionarioIndex(id);
    if (index == -1)
    {
        puts("[ERRO]:O funcionário não existe!");
        return funcionarioInvalido();
    }

    todosOsFuncionarios[index] = funcionarioInvalido();
    funcionariosIndex--;
    return todosOsFuncionarios[index];
}

void printFuncionario(Funcionario f)
{
    printf("=====Funcionário %100s=====\nID:%d\nCargo:%49s\nSalário:R$ %.2f\n", f.nome, f.id, f.cargo, f.salario);
}

void lerArquivo()
{
    FILE *file = fopen("funcionarios.bin", "rb");
    if (!file)
    {
        puts("[ERRO]: Erro ao abrir o arquivo, ele não existe, ou você não tem permissão!");
        fclose(file);
    }
    fclose(file);
}
void salvarArquivo()
{
    FILE *file = fopen("funcionarios.bin", "wb");
    if (!file)
    {
        puts("[ERRO]: Erro ao abrir o arquivo, ele não existe, ou você não tem permissão!");
        fclose(file);
    }
    fclose(file);
}
void saltarArquivo_caseDeletar();

int getFuncionarioIndex(int id)
{
    for (int i = 0; i < MAX_FUNCIONARIOS; i++)
    {
        if (todosOsFuncionarios[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void resetarMemoria()
{
    int i = 0;
    funcionariosIndex = 0;
    while (i++ < MAX_FUNCIONARIOS)
    {
        todosOsFuncionarios[i] = funcionarioInvalido();
    }
}

#pragma endregion IMPLEMENTATION