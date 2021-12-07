#include <stdio.h>
#include <stdlib.h>
	
struct numeros{
	int valor;
	struct numeros *prox;
};

typedef struct numeros Lista;
Lista *primeiro;

void inserir() {
	Lista *valores = malloc(sizeof(Lista));

	printf("Digite o valor: ");
	scanf("%d", &valores->valor);
  printf("\n");
	
	valores->prox = NULL;
	
	if(primeiro == NULL) {
		primeiro = valores;
	} else {
		Lista *aux = primeiro;
		
		while(aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = valores;
	}
}

void mostrar(Lista *valores) {
	if(valores != NULL) {
		printf("%2d ", valores->valor);
		mostrar(valores->prox);
	}
}

Lista *remover_negativo(Lista *valores){
	Lista *copia = valores;
	
	if(copia != NULL) {
		
		if(copia->valor < 0) {
			printf("N=%2d ", copia->valor);	
			copia = valores->prox;	
		}
		
		printf("P=%2d", copia->valor);
		remover_negativo(copia->prox);
	}
	return copia;
}

int main() {
	int auxiliar = 0, escolha, quan;
  Lista *nova_lista;
	
	do{
		printf("==========M E N U=========\n");
		printf("[1] - Inserir valores\n");
		printf("[2] - Listar valores\n");
		printf("[3] - Listar valores sem número negativo\n");;
		printf("[4] - Sair\n");
		printf("Qual operação você deseja realizar?\n");
		scanf("%d", &escolha);
		
		switch(escolha) {
			case 1:
				printf("Quantos números você quer inserir?\n");
        scanf("%d",&quan);
        for(int i=0;i<quan;i++){
          inserir();
        }
				break;
			case 2:
				mostrar(primeiro);
				printf("\n");
				break;
			case 3:
				nova_lista = remover_negativo(primeiro);
				
				printf("\n");
				break;
			case 4:
				printf("Encerrando programa...\n");
				auxiliar = 1;
				break;
			default:
				printf("<ERR0R!!> Opção inválida!\n");
		}
	} while(auxiliar != 1);
	
	return 0;
}