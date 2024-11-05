#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100
#define MAX_ATIVIDADES 100

typedef struct {
    char nome[100];
    char matricula[20];
    int cargaHorariaTotal;
    int atividadesComplementaresAproveitadas;
} Aluno;

typedef struct {
    int numeroRegistro;
    char matriculaAluno[20];
    char descricao[100];
    int cargaHoraria;
    char statusAproveitamento; 
} AtividadeComplementar;

Aluno alunos[MAX_ALUNOS];
AtividadeComplementar atividades[MAX_ATIVIDADES];
int totalAlunos = 0;
int totalAtividades = 0;

void cadastrarAluno() {
    if (totalAlunos >= MAX_ALUNOS) {
        printf("Numero maximo de alunos atingido.\n");
        return;
    }
    Aluno novoAluno;
    printf("a nome do aluno é: ");
        fgets(novoAluno.nome, sizeof(novoAluno.nome), stdin);
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0'; 
    printf("a matricula do aluno é: ");
        fgets(novoAluno.matricula, sizeof(novoAluno.matricula), stdin);
            novoAluno.matricula[strcspn(novoAluno.matricula, "\n")] = '\0'; 
            novoAluno.cargaHorariaTotal = 0;
            novoAluno.atividadesComplementaresAproveitadas = 0;
            alunos[totalAlunos++] = novoAluno;
    printf("aluno cadastrado com sucesso\n");
}

void cadastrarAtividade() {
    if (totalAtividades >= MAX_ATIVIDADES) {
        printf("numero maximo de atividades atingido.\n");
        return;
    }
    AtividadeComplementar novaAtividade;
    novaAtividade.numeroRegistro = totalAtividades + 1; 
    printf("matricula do aluno: ");
        fgets(novaAtividade.matriculaAluno, sizeof(novaAtividade.matriculaAluno), stdin);
        novaAtividade.matriculaAluno[strcspn(novaAtividade.matriculaAluno, "\n")] = '\0'; 
    printf("descricao da atividade: ");
        fgets(novaAtividade.descricao, sizeof(novaAtividade.descricao), stdin);
            novaAtividade.descricao[strcspn(novaAtividade.descricao, "\n")] = '\0'; 
    printf("carga horaria: ");
        scanf("%d", &novaAtividade.cargaHoraria);
            getchar(); 
        novaAtividade.statusAproveitamento = 'N'; 
        atividades[totalAtividades++] = novaAtividade;
    printf("atividade cadastrada.\n");
}

void pesquisarAtividadesAluno() {
    char matricula[20];
    printf("Digite a matricula do aluno: ");
        fgets(matricula, sizeof(matricula), stdin);
            matricula[strcspn(matricula, "\n")] = '\0'; 

    printf("Atividades do aluno %s:\n", matricula);
    for (int i = 0; i < totalAtividades; i++) {
        if (strcmp(atividades[i].matriculaAluno, matricula) == 0) {
            printf("Numero: %d\nDescricao: %s\nCarga Horaria: %d\nStatus: %c\n\n",
                   atividades[i].numeroRegistro, atividades[i].descricao,
                   atividades[i].cargaHoraria, atividades[i].statusAproveitamento);
        }
    }
}
void mostrarCargaHorariaTotal() {
    printf("Carga Horaria Total:\n");
    for (int i = 0; i < totalAlunos; i++) {
        printf("nome: %s\nmatricula: %s\ncarga horaria total: %d\n\n",
               alunos[i].nome, alunos[i].matricula, alunos[i].cargaHorariaTotal);
    }
}
int main() {
    int opcao;
    do {
        printf("menu:\n");
        printf("1. cadastrar um aluno\n");
        printf("2. cadastrar uma atividade\n");
        printf("3. oesquisar atividades do aluno\n");
        printf("4. mostrar carga horaria total\n");
        printf("5. sair\n");
        printf("escolha uma opcas: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1: cadastrarAluno(); break;
            case 2: cadastrarAtividade(); break;
            case 3: pesquisarAtividadesAluno(); break;
            case 4: mostrarCargaHorariaTotal(); break;
            case 5: printf("voce saiu\n"); break;
            default: printf("digite uma opcao valida\n"); break;
        }
    } while (opcao != 5);

    return 0;
}