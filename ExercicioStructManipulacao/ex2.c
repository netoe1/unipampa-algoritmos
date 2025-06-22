#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_FUNCIONARIOS 100
#define FUNCIONARIO_INVALIDO -1

typedef struct
{
    int id;
    char nome[100];
    char cargo[50];
    float salario;
} Funcionario;

Funcionario todosOsFuncionarios[MAX_FUNCIONARIOS];
int funcionariosIndex = 0;

Funcionario funcionarioInvalido();
Funcionario cadastrarFuncionario();
void listarTodosOsFuncionarios();
Funcionario buscarFuncionarioPorId(int id);
Funcionario editarDadosDoFuncionario(int id, char cargoNovo[50], float salarioNovo);
Funcionario removerFuncionario(int id);
void printFuncionario(Funcionario f);
void lerArquivo();
void salvarArquivo();
int getFuncionarioIndex(int id);
void resetarMemoria();
void wait();

int main(void)
{
    setlocale(LC_ALL, "");
    resetarMemoria();
    lerArquivo();
    int op = -1;
    int id = 0;
    while (op != 0)
    {
        printf("=====SISTEMA DE CADASTRO=====\n1. Cadastrar novo funcionário\n2. Listar todos os funcionários\n3. Buscar funcionário por ID\n4. Alterar dados de um funcionário\n5. Remover funcionário\n6. Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        {
            Funcionario novo = cadastrarFuncionario();
            printFuncionario(novo);
            wait();
            break;
        }
        case 2:
            listarTodosOsFuncionarios();
            wait();
            break;
        case 3:
            puts("\nDigite o id do funcionário:");
            scanf("%d", &id);
            {
                Funcionario buscar = buscarFuncionarioPorId(id);
                if (buscar.id == FUNCIONARIO_INVALIDO)
                {
                    puts("O funcionário não foi encontrado...");
                    wait();
                }
                else
                {
                    printFuncionario(buscar);
                    wait();
                }
            }
            break;
        case 4:
            puts("\nDigite o id do funcionario que você quer editar:");
            scanf("%d", &id);
            if (buscarFuncionarioPorId(id).id != FUNCIONARIO_INVALIDO)
            {
                Funcionario ret;
                char aux[50];
                float salario;
                printf("\nDigite o novo cargo:");
                setbuf(stdin, NULL);
                fgets(aux, sizeof(aux) - 1, stdin);
                aux[strcspn(aux, "\n")] = '\0';
                printf("\nDigite o novo salário:");
                scanf("%f", &salario);
                ret = editarDadosDoFuncionario(id, aux, salario);
                if (ret.id == FUNCIONARIO_INVALIDO)
                {
                    puts("Não foi possível editar o usuário!");
                    wait();
                }
                else
                {
                    puts("O usuário foi editado!");
                    printFuncionario(ret);
                    wait();
                }
            }
            else
            {
                puts("O funcionário não foi encontrado...");
                wait();
            }
            break;
        case 5:
            puts("\nDigite o id do funcionário");
            scanf("%d", &id);
            if (removerFuncionario(id).id != FUNCIONARIO_INVALIDO)
            {
                puts("O usuário foi removido com sucesso!");
                wait();
            }
            else
            {
                puts("Funcionário não encontrado.");
                wait();
            }
            break;
        case 6:
            op = 0;
            break;
        default:
            break;
        }
    }
    salvarArquivo();
    return EXIT_SUCCESS;
}

Funcionario funcionarioInvalido()
{
    Funcionario erro;
    erro.id = FUNCIONARIO_INVALIDO;
    erro.salario = -1;
    return erro;
}

Funcionario cadastrarFuncionario()
{
    Funcionario novoFuncionario;
    if (funcionariosIndex == MAX_FUNCIONARIOS)
    {
        puts("[ERRO]: Você chegou ao limite máximo de cadastro do sistema!");
        wait();
        return funcionarioInvalido();
    }
    while (1)
    {
        printf("\nID:");
        scanf("%d", &novoFuncionario.id);
        if (novoFuncionario.id < 0)
        {
            puts("[ERRO]: O id do funcionário não pode ser negativo!");
            wait();
            continue;
        }
        if (buscarFuncionarioPorId(novoFuncionario.id).id != FUNCIONARIO_INVALIDO)
        {
            puts("[ERRO]: Esse funcionário já existe, digite outro id!");
            wait();
            continue;
        }
        break;
    }
    printf("\nNome:");
    setbuf(stdin, NULL);
    fgets(novoFuncionario.nome, sizeof(novoFuncionario.nome) - 1, stdin);
    novoFuncionario.nome[strcspn(novoFuncionario.nome, "\n")] = '\0';
    printf("\nCargo:");
    setbuf(stdin, NULL);
    fgets(novoFuncionario.cargo, sizeof(novoFuncionario.cargo) - 1, stdin);
    novoFuncionario.cargo[strcspn(novoFuncionario.cargo, "\n")] = '\0';
    while (1)
    {
        printf("\nSalário:");
        scanf("%f", &novoFuncionario.salario);
        if (novoFuncionario.salario <= 0)
        {
            puts("O salário do funcionário deve ser > 0!");
            wait();
            continue;
        }
        break;
    }
    todosOsFuncionarios[funcionariosIndex++] = novoFuncionario;
    salvarArquivo();
    return novoFuncionario;
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
        wait();
        return funcionarioInvalido();
    }
    strcpy(todosOsFuncionarios[func_id].cargo, cargoNovo);
    todosOsFuncionarios[func_id].salario = salarioNovo;
    salvarArquivo();
    return todosOsFuncionarios[func_id];
}

Funcionario removerFuncionario(int id)
{
    int index = getFuncionarioIndex(id);
    if (index == -1)
    {
        puts("[ERRO]: O funcionário não existe!");
        wait();
        return funcionarioInvalido();
    }
    Funcionario removido = todosOsFuncionarios[index];
    todosOsFuncionarios[index] = funcionarioInvalido();
    funcionariosIndex--;
    salvarArquivo();
    return removido;
}

void printFuncionario(Funcionario f)
{
    printf("=====Funcionário %s=====\nID:%d\nCargo:%s\nSalário:R$ %.2f\n", f.nome, f.id, f.cargo, f.salario);
}

void lerArquivo()
{
    FILE *file = fopen("funcionarios.bin", "rb");
    if (!file)
    {
        return;
    }
    int i = 0;
    while (i < MAX_FUNCIONARIOS && fread(&todosOsFuncionarios[i], sizeof(Funcionario), 1, file) == 1)
        i++;
    funcionariosIndex = i;
    fclose(file);
}

void salvarArquivo()
{
    FILE *file = fopen("funcionarios.bin", "wb");
    if (!file)
    {
        puts("[ERRO]: Erro ao abrir o arquivo para escrita!");
        return;
    }
    for (int i = 0; i < MAX_FUNCIONARIOS; i++)
    {
        if (todosOsFuncionarios[i].id != FUNCIONARIO_INVALIDO)
        {
            fwrite(&todosOsFuncionarios[i], sizeof(Funcionario), 1, file);
        }
    }
    fclose(file);
}

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
    funcionariosIndex = 0;
    for (int i = 0; i < MAX_FUNCIONARIOS; i++)
    {
        todosOsFuncionarios[i] = funcionarioInvalido();
    }
}

void wait()
{
    puts("Aperte ENTER para continuar...");
    setbuf(stdin, NULL);
    getchar();
}
