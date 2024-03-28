#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[50];
	float preco;
	int quantidade;
}Produtos;

void adicionarProd(Produtos *estoque, int *indice){
	
	printf("\nDigite o nome do produto: ");
	fgets(estoque[*indice].nome, sizeof(estoque[*indice].nome), stdin);
	estoque[*indice].nome[strcspn(estoque[*indice].nome, "\n")] = '\0';

	printf("Digite o valor do produto: ");
	scanf("%f", &estoque[*indice].preco);
	
	printf("Digite a quantidade do produto: ");
	scanf("%d", &estoque[*indice].quantidade);
	
	(*indice)++;
}

void exibirProd(Produtos *estoque, int *indice){
	int i;
	printf("Estoque:\n");
	for(i = 0; i < *indice; i++){
		printf("\nNome: %s\nPreco: %.2f\nQuantidade: %d\n", estoque[i].nome, estoque[i].preco, estoque[i].quantidade);
	}
}

void attPreco(Produtos *estoque){
    int id;
    printf("Digite o ID do produto que deseja atualizar o preco: ");
    scanf("%d", &id);
    printf("Digite o novo preco: ");
    scanf("%f", &estoque[id].preco);
    printf("Valor alterado com SUCESSO.\n");
}

int main() {
	Produtos estoque[50];
	int indice;
	int op;
	
	do
	{
		printf("\n[1]-ADICIONAR PRODUTO\n[2]-ATUALIZAR PRECO\n[3]-MOSTRAR PRODUTO\n[0]-Encerrar\n");
		printf("Digite uma opcao: ");
		scanf("%d", &op);
		fflush(stdin);
		
		switch(op){
			case 1:
				printf("\n-----Adionar Produto-----\n");
				adicionarProd(estoque, &indice);
				break;
			case 2:
				printf("\n-----Atualizar Preco-----\n");
				attPreco(estoque);
				break;
			case 3:
				printf("\n-----Mostrar Produto-----\n");
				exibirProd(estoque, &indice);
				break;
			case 0:
				printf("Programa encerrado.");
				break;
			default:
				printf("Opcao invalida.\n");
				break;
		}
	}while(op != 0);
	
	return 0;
}

