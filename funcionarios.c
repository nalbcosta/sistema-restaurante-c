#include "funcionarios.h"
#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 100

static Funcionario funcionarios[MAX_FUNCIONARIOS];
static int totalFuncionarios = 0;

void carregarFuncionarios() {
    FILE *f = fopen("funcionarios.dat", "rb");
    if (f) {
        fread(&totalFuncionarios, sizeof(int), 1, f);
        fread(funcionarios, sizeof(Funcionario), totalFuncionarios, f);
        fclose(f);
    }
}

void salvarFuncionarios() {
    FILE *f = fopen("funcionarios.dat", "wb");
    if (f) {
        fwrite(&totalFuncionarios, sizeof(int), 1, f);
        fwrite(funcionarios, sizeof(Funcionario), totalFuncionarios, f);
        fclose(f);
    }
}

void cadastrarFuncionario() {
    if (totalFuncionarios >= MAX_FUNCIONARIOS) {
        printf("Limite de funcionarios atingido.\n");
        return;
    }
    Funcionario novoFuncionario;
    novoFuncionario.id = totalFuncionarios + 1;
    printf("=== Cadastro de Funcionario ===\n");
    printf("ID: %d\n", novoFuncionario.id);
    printf("Digite o nome do funcionario: ");
    scanf("%s", novoFuncionario.nome);
    // Seleção de cargo
    printf("Selecione o cargo:\n");
    printf("1. Garcom\n2. Gerente\n3. Cozinheiro\n4. Atendente\n5. Caixa\n");
    int opcaoCargo;
    scanf("%d", &opcaoCargo);
    switch(opcaoCargo) {
        case 1: strcpy(novoFuncionario.cargo, "Garcom"); break;
        case 2: strcpy(novoFuncionario.cargo, "Gerente"); break;
        case 3: strcpy(novoFuncionario.cargo, "Cozinheiro"); break;
        case 4: strcpy(novoFuncionario.cargo, "Atendente"); break;
        case 5: strcpy(novoFuncionario.cargo, "Caixa"); break;
        default: strcpy(novoFuncionario.cargo, "Outro"); break;
    }
    printf("Digite o salario do funcionario: ");
    scanf("%f", &novoFuncionario.salario);
    // Seleção de turno
    printf("Selecione o turno:\n");
    printf("1. Manha\n2. Tarde\n3. Noite\n");
    int opcaoTurno;
    scanf("%d", &opcaoTurno);
    switch(opcaoTurno) {
        case 1: strcpy(novoFuncionario.turno, "Manha"); break;
        case 2: strcpy(novoFuncionario.turno, "Tarde"); break;
        case 3: strcpy(novoFuncionario.turno, "Noite"); break;
        default: strcpy(novoFuncionario.turno, "Outro"); break;
    }
    printf("Digite o telefone do funcionario: ");
    scanf("%s", novoFuncionario.telefone);
    funcionarios[totalFuncionarios] = novoFuncionario;
    totalFuncionarios++;
    salvarFuncionarios();
    printf("Funcionario cadastrado com sucesso!\n");
}

void listarFuncionarios() {
    printf("=== Lista de Funcionarios ===\n");
    if (totalFuncionarios == 0) {
        printf("Nenhum funcionario cadastrado.\n");
        return;
    }
    for (int i = 0; i < totalFuncionarios; i++) {
        printf("ID: %d\n", funcionarios[i].id);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Salario: %.2f\n", funcionarios[i].salario);
        printf("Turno: %s\n", funcionarios[i].turno);
        printf("Telefone: %s\n", funcionarios[i].telefone);
        printf("-------------------------\n");
    }
}

Funcionario* buscarFuncionarioPorId(int id) {
    for (int i = 0; i < totalFuncionarios; i++) {
        if (funcionarios[i].id == id) {
            return &funcionarios[i];
        }
    }
    return NULL;
}

void editarFuncionario(int id) {
    Funcionario *func = buscarFuncionarioPorId(id);
    if (func == NULL) {
        printf("Funcionario com ID %d nao encontrado.\n", id);
        return;
    }
    printf("=== Editar Funcionario ===\n");
    printf("ID: %d\n", func->id);
    printf("Nome atual: %s\n", func->nome);
    printf("Digite o novo nome: ");
    scanf("%s", func->nome);
    // Seleção de cargo
    printf("Cargo atual: %s\n", func->cargo);
    printf("Selecione o novo cargo:\n");
    printf("1. Garcom\n2. Gerente\n3. Cozinheiro\n4. Atendente\n5. Caixa\n");
    int opcaoCargo;
    scanf("%d", &opcaoCargo);
    switch(opcaoCargo) {
        case 1: strcpy(func->cargo, "Garcom"); break;
        case 2: strcpy(func->cargo, "Gerente"); break;
        case 3: strcpy(func->cargo, "Cozinheiro"); break;
        case 4: strcpy(func->cargo, "Atendente"); break;
        case 5: strcpy(func->cargo, "Caixa"); break;
        default: strcpy(func->cargo, "Outro"); break;
    }
    printf("Salario atual: %.2f\n", func->salario);
    printf("Digite o novo salario: ");
    scanf("%f", &func->salario);
    // Seleção de turno
    printf("Turno atual: %s\n", func->turno);
    printf("Selecione o novo turno:\n");
    printf("1. Manha\n2. Tarde\n3. Noite\n");
    int opcaoTurno;
    scanf("%d", &opcaoTurno);
    switch(opcaoTurno) {
        case 1: strcpy(func->turno, "Manha"); break;
        case 2: strcpy(func->turno, "Tarde"); break;
        case 3: strcpy(func->turno, "Noite"); break;
        default: strcpy(func->turno, "Outro"); break;
    }
    printf("Telefone atual: %s\n", func->telefone);
    printf("Digite o novo telefone: ");
    scanf("%s", func->telefone);
    salvarFuncionarios();
    printf("Funcionario editado com sucesso!\n");
}

void removerFuncionario(int id) {
    int found = 0;
    for (int i = 0; i < totalFuncionarios; i++) {
        if (funcionarios[i].id == id) {
            found = 1;
        }
        if (found && i < totalFuncionarios - 1) {
            funcionarios[i] = funcionarios[i + 1];
        }
    }
    if (found) {
        totalFuncionarios--;
        salvarFuncionarios();
        printf("Funcionario removido com sucesso!\n");
    } else {
        printf("Funcionario com ID %d nao encontrado.\n", id);
    }
}