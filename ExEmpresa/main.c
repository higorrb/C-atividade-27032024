#include <stdio.h>
#include <string.h>

typedef struct 
{
    int id;
    char nome[100];
    float salario;
    int quantidade_filhos;
}Empresa;

void adicionarFuncio(Empresa *funcionarios, int *indice)
{
    funcionarios[*indice].id = *indice;

    printf("\nDigite o nome: ");
    fgets(funcionarios[*indice].nome, 100, stdin);
    funcionarios[*indice].nome[strcspn(funcionarios[*indice].nome, "\n")] = '\0';

    printf("Digite o salario: ");
    scanf("%f", &funcionarios[*indice].salario);

    printf("Digite a quantidade de filhos: ");
    scanf("%d", &funcionarios[*indice].quantidade_filhos);

    (*indice)++;
}

void imprimirFuncio(Empresa *funcionarios, int *indice)
{
    int i;
    for (i = 0; i < *indice; i++)
    {
        printf("ID---------------%d\n", funcionarios[i].id);
        printf("Nome-------------%s\n", funcionarios[i].nome);
        printf("Salario----------R$%.2f\n", funcionarios[i].salario);
        printf("Filhos-----------%d\n\n", funcionarios[i].quantidade_filhos);
        
    }
    
}

void RemoveFuncio(Empresa *funcionarios, int *indice)
{
    int i, ind;

    printf("\nDigite o ID do funcionario que deseja EXCLUIR: ");
    scanf("%d", &ind);
    fflush(stdin);

    if (ind>=0 && ind<=*indice)
    {
        for (i = ind; i < *indice; i++)
        {
            funcionarios[i] = funcionarios[i+1];
            funcionarios[i].id = i;
        }
        printf("Funcionario Excluido!");
    }
    else{
        printf("ID invalido!\n");
    }
    
}

void alterarFuncio(Empresa *funcionarios, int *indice)
{
    int ind;
    printf("\nDigite o ID do funcionario que deseja Alterar: ");
    scanf("%d", &ind);
    fflush(stdin);
    if (ind>=0 && ind<=*indice)
    {
    printf("\nDigite o nome: ");
    fgets(funcionarios[ind].nome, 100, stdin);
    funcionarios[ind].nome[strcspn(funcionarios[ind].nome, "\n")] = '\0';

    printf("Digite o salario: ");
    scanf("%f", &funcionarios[ind].salario);

    printf("Digite a quantidade de filhos: ");
    scanf("%d", &funcionarios[ind].quantidade_filhos);
    }
    else{
        printf("ID invalido!\n");
    }

}

void qntFilhosFuncio(Empresa *funcionarios, int *indice)
{
    int i;
    for (i = 0; i < *indice; i++)
    {
        if (funcionarios[i].quantidade_filhos > 2)
        {
        printf("ID---------------%d\n", funcionarios[i].id);
        printf("Nome-------------%s\n", funcionarios[i].nome);
        printf("Salario----------R$%.2f\n", funcionarios[i].salario);
        printf("Filhos-----------%d\n\n", funcionarios[i].quantidade_filhos);
        }
    }
}

float somaSalarioFuncio(Empresa *funcionarios, int *indice){
    int i, somaTotal = 0;

    for (i = 0; i < *indice; i++)
    {
        somaTotal += funcionarios[i].salario;
    }
    return somaTotal;
}

float maiorSalarioFuncio(Empresa *funcionarios, int *indice){
    int i, maiorSalario = 0;

    for (i = 0; i < *indice; i++)
    {
        if (funcionarios[i].salario > maiorSalario)
        {
            maiorSalario = funcionarios[i].salario;
        }
        
    }
    return maiorSalario;
}

float menorSalarioFuncio(Empresa *funcionarios, int *indice){
    int i = 0, menorSalario = 0;

    menorSalario = funcionarios[i].salario;

    for (i = 0; i < *indice; i++)
    {
        if (funcionarios[i].salario < menorSalario)
        {
            menorSalario = funcionarios[i].salario;
        }
        
    }
    return menorSalario;
}

void aumentarSalarioFuncio(Empresa *funcionarios, int *indice){
    int i = 0;

    for (i = 0; i < *indice; i++)
    {
        if (funcionarios[i].salario < 1000)
        {
            funcionarios[i].salario = funcionarios[i].salario * 1.10;
        }
    }
    printf("Aumento de Salario realizado com sucesso!");
}

int main(){
    Empresa funcionarios[100];
    int op, indice = 0;


    do
    {
        printf("\n\n~~~~~~~~~~MENU~~~~~~~~~~\n[1]-ELIMINAR REGISTRO\n[2]-ALTERAR REGISTRO\n[3]-INCLUIR REGISTRO\n[4]-LISTAR REGISTROS\n[5]-FUNCIONARIO +2 FILHOS\n[6]-SOMA DE SALARIO\n[7]-MAIOR SALARIO\n[8]-MENOR SALARIO\n[9]-AUMENTAR SALARIO\n[0]-ENCERRAR\n");
        printf("Digite uma opcao: ");
        scanf("%d", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            printf("\n========EXCLUIR REGISTRO========\n");
            RemoveFuncio(funcionarios, &indice);
            indice--;
            break;
        
        case 2:
            printf("\n=========ALTERAR REGISTRO=========\n");
            alterarFuncio(funcionarios, &indice);
            break;

        case 3:
            adicionarFuncio(funcionarios, &indice);
            break;

        case 4:
            printf("\n=========FUNCIONARIOS=========\n");
            imprimirFuncio(funcionarios, &indice);
            break;
        case 5:
            printf("\n=========FUNCIONARIOS +2 FILHOS=========\n");
            qntFilhosFuncio(funcionarios, &indice);
            break;
        case 6:
            printf("\n=========SOMA DE SALARIOS=========\n");
            printf("A soma de todos os salarios da empresa: R$%.2f", somaSalarioFuncio(funcionarios, &indice));
            break;
        case 7:
            printf("\n=========MAIOR SALARIO=========\n");
            printf("O maior salario da empresa: R$%.2f", maiorSalarioFuncio(funcionarios, &indice));
            break;
        case 8:
            printf("\n=========MENOR SALARIO=========\n");
            printf("O menor salario da empresa: R$%.2f", menorSalarioFuncio(funcionarios, &indice));
            break;
        case 9:
            printf("\n=========AUMENTAR SALARIO=========\n");
            aumentarSalarioFuncio(funcionarios, &indice);
            break;
        case 0:
            printf("\nPrograma Encerrado!");
            break;
        default:
            printf("Opcao INVALIDA!\n");
            break;
        }
    }while (op != 0);
    return 0;
}