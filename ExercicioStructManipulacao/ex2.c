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