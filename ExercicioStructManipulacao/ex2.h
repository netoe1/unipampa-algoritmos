#ifndef EX2_H
#define EX2_H

#pragma region CONSTS
#define ARQUIVO_BIN "funcionarios.bin"
#define MAX_FUNCIONARIOS 200
#define FUNCIONARIO_INVALIDO -1
#pragma endregion CONSTS

#pragma region STRUCT_DEFINITION
typedef struct
{
    int id;         // Código único do funcionário
    char nome[100]; // Nome completo
    char cargo[50]; // Cargo ocupado
    float salario;  // Salário mensal
} Funcionario;

#pragma endregion STRUCT_DEFINITION

#pragma region HEADER
Funcionario
funcionarioInvalido();
Funcionario cadastrarFuncionario();
void listarTodosOsFuncionarios();
Funcionario buscarFuncionarioPorId(int id);
Funcionario editarDadosDoFuncionaro(int id, char cargoNovo[50], float salarioNovo);
Funcionario removerFuncionario(int id);
int getFuncionarioIndex(int id);
void resetarMemoria();
void printFuncionario(Funcionario f);
void lerArquivo();
void salvarArquivo();
void saltarArquivo_caseDeletar();

#pragma endregion HEADER

#endif