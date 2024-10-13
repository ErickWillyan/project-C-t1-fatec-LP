#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int matricula;
    int historico[5];
    char periodo[10];
    int semestre;
    char unidade[100];
} historico_notas;

int main(void)
{
    char run[2];
    int regCount = 0;
    historico_notas registros[100];

    FILE *file = fopen("teste.txt", "a");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("🄷🄸🅂🅃🄾🅁🄸🄲🄾\n");

    while (1)
    {
        printf("Deseja inserir um histórico de notas? (s/n): ");
        scanf("%1s", run);
        if (strcmp(run, "n") == 0)
        {
            break;
        }

        printf("\nInsira o nome do aluno: ");
        scanf("%49s", registros[regCount].nome);

        printf("Insira a matrícula do aluno: ");
        scanf("%d", &registros[regCount].matricula);

        printf("Insira o semestre no qual o aluno está ingressado: ");
        scanf("%d", &registros[regCount].semestre);

        printf("Informe a nota de matemática: ");
        scanf("%d", &registros[regCount].historico[0]);

        printf("Informe a nota de ciências: ");
        scanf("%d", &registros[regCount].historico[1]);

        printf("Informe a nota de geografia: ");
        scanf("%d", &registros[regCount].historico[2]);

        printf("Informe a nota de português: ");
        scanf("%d", &registros[regCount].historico[3]);

        printf("Informe a nota de história: ");
        scanf("%d", &registros[regCount].historico[4]);

        printf("Insira o período que o aluno estuda: ");
        scanf("%9s", registros[regCount].periodo);

        printf("Insira a unidade no qual o aluno está ingressado: ");
        scanf("%99s", registros[regCount].unidade);

        fprintf(file, "%s, %d, %d, %d, %d, %d, %d, %s, %s\n",
                registros[regCount].nome,
                registros[regCount].matricula,
                registros[regCount].historico[0],
                registros[regCount].historico[1],
                registros[regCount].historico[2],
                registros[regCount].historico[3],
                registros[regCount].historico[4],
                registros[regCount].periodo,
                registros[regCount].unidade);

        fflush(file);

        regCount++;
    }

    fclose(file);
    return 0;
}
