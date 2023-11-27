#include <stdio.h>
#include <string.h>

int main() {

    int n = 0;

    printf("Esse codigo tem como intuito fazer a aplicacao do lema de bombeamento\n");
    printf("A linguagem verificada sera: \n\n");
    printf("L = {0^n 1^n | n >= 0}\n\n");
    printf("Para a linguagem ser regular tem que respeitar 3 regras, sao elas: \n");
    printf("1) |uv| <= p\n");
    printf("2) |v| >= 1\n");
    printf("3) Para todo i>= 0, uv^iz deve pertencer a L\n\n");

    printf("Agora forneca o valor de n para fazermos o bombeamento: ");
    scanf("%i", &n);

    int tamanho = 2 * n;

    // Construindo a palavra
    char palavra[100] = "";
    int aux = 0;
    for (int i = 0; i < tamanho; i++) {
        if (i < tamanho / 2) {
            palavra[aux++] = '0';
        } else {
            palavra[aux++] = '1';
        }
    }
    // Dividindo a palavra em u, v, e z
    char u[2] = "", v[100] = "", z[100] = "";
    strncpy(u, palavra, 1);
    strncpy(v, palavra + 1, n - 1);
    strncpy(z, palavra + n, n);

    printf("\nBombeando :\n");

    printf("Palavra gerada: %s\n", palavra);
    printf("Ela e dividida em 3 SubStrings, u, v e z\n");
    printf("u = %s\nv = %s\nz = %s\n\n", u, v, z);

    int armazena_pertencimento[3] = {0};

    // Executa o lema do bombeamento
    for (int i = 0; i < 3; i++) {
        char palavranova[100] = "";
        strcat(palavranova, u);
        if (i == 0) {
            strcat(palavranova, z);
        } else if (i == 1) {
            strcat(palavranova, v);
            strcat(palavranova, z);
        } else if (i == 2) {
            strcat(palavranova, v);
            strcat(palavranova, v);
            strcat(palavranova, z);
        }
        printf("\nIteracao %i\n", i);
        printf("w = %s\n", palavranova);

        // Verifica se uv^iz pertence a L
        int qtd_0 = 0, qtd_1 = 0;
        int tamanho_palavranova = strlen(palavranova);

        //percorre a palavra e soma os valores de 0 e 1
        for (int j = 0; j < tamanho_palavranova; j++) {
            if (palavranova[j] == '0') {
                qtd_0++;
            } else if (palavranova[j] == '1') {
                qtd_1++;
            } else {
                printf("%s nao pertence a L\n", palavranova);
                return 0;
            }
        }
        if (qtd_0 == qtd_1) {
            printf("%s pertence a L\n", palavranova);
            armazena_pertencimento[i] = 1;
        } else {
            printf("%s nao pertence a L\n", palavranova);
        }
    }
    // Verifica se a linguagem é regular ou não
    int soma = armazena_pertencimento[0] + armazena_pertencimento[1] + armazena_pertencimento[2];
    if (soma == 3) {
        printf("\n\nA linguagem e regular\n");
    } else {
        printf("\n\nA linguagem nao e regular\n");
    }
    return 0;
}
