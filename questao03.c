#include <stdio.h>
#include <stdlib.h>

struct ponto{
	int numero;
	struct ponto *prox;
};

typedef struct ponto TipoLista;
TipoLista *primeiro;

void inserir() {
	TipoLista *lista = malloc(sizeof(TipoLista));
	
	printf("Digite o valor:\n");
	scanf("%d", &lista->numero);
	
	lista->prox = NULL;
	
	if(primeiro == NULL) {
		primeiro = lista;
	} else{
		TipoLista *aux = primeiro;

		while(aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = lista;
	}
}

void inverter(TipoLista *lista) {
	if(lista != NULL) {
		inverter(lista->prox);
    printf("\n");
		printf("%2d ", lista->numero);
	}
}

void imprimir(TipoLista *lista) {
	if(lista != NULL) {
    printf("\n");
		printf("%2d ", lista->numero);
		imprimir(lista->prox);
	}
}



int main() {
	int auxiliar = 0, escolha, quan;
	
	do{
		printf("==========M E N U==========\n");
		printf("[1] - Inserir números\n");
		printf("[2] - Listar números\n");
		printf("[3] - Listar números na ordem inversa\n");
		printf("[4] - Sair\n");
    printf("===========================\n");
		printf("Digite sua opção: ");
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
				imprimir(primeiro);
				printf("\n");
				break;
			case 3:
				inverter(primeiro);
				printf("\n");
				break;
			case 4:
				printf("Encerando o programa...\n");
        printf("PROGRAMA ENCERRADO!\n");
				auxiliar = 1;
				break;
			default:
				printf("<ERR0R!!> Opção Inválida x(\n");
		}
	} while(auxiliar != 1);
	
	return 0;
}