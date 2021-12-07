#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodalista {
char titulo[51];
char autor[51];
int ano;
int quantidade;
struct nodalista *prox;
};
typedef struct nodalista NoDaLista;
NoDaLista *primeiro;
int tamanho=0;

void inserir_dados(){
  NoDaLista *nodalista = malloc(sizeof(NoDaLista));
  printf("\n");
  printf("Título: \n");
  scanf("%s", nodalista->titulo);
  printf("Autor: \n");
  scanf("%s", nodalista->autor);
  printf("Ano: \n");
  scanf("%d", &nodalista->ano);
  printf("Quantidade: \n");
  scanf("%d", &nodalista->quantidade);
  nodalista->prox = primeiro;
  primeiro = nodalista;
  tamanho++;
}

void mostrar_dados(NoDaLista *nodalista){
  if (nodalista != NULL) {
    printf("\n");
    printf("===========D A D O S===========\n");
    printf("%s - %s - %d - %d\n", nodalista->titulo, nodalista->autor,nodalista->ano,nodalista->quantidade);
    mostrar_dados(nodalista->prox);
    }
}

int quantidade_livros(NoDaLista *livros) {
	if(livros != NULL) {
		tamanho += livros->quantidade;
		quantidade_livros(livros->prox);
	}
	return tamanho;
}

void livro_ano(NoDaLista *livros, int ano) {
	if(livros != NULL) {
		if(livros->ano == ano) {
      printf("\n");
      printf("============================\n");
			printf("Livro: %s\n", livros->titulo);
			printf("Autor: %s\n", livros->autor);
			printf("Ano: %d\n", livros->ano);
			printf("Quantidade: %d\n", livros->quantidade);
		}
		livro_ano(livros->prox, ano);
	}
}

int main() {
	int aux = 0, escolha, q_livros, ano_pub, quan;
	
	do{
    printf("\n");
		printf("=========== M E N U ===========\n");
		printf("[1] - Sistema de livros\n");
		printf("[2] - Sair\n");
		printf("Selecione sua opção: ");
		scanf("%d", &escolha);
		
		switch(escolha) {
		  case 1:
				do{
          printf("\n");
					printf("[1] - Inserir livros\n");
					printf("[2] - Listar livros\n");
					printf("[3] - Quantidade de livos\n");
					printf("[4] - Procurar por ano\n");
					printf("[5] - Voltar\n");
					printf("Opcao: ");
					scanf("%d", &escolha);
					
					switch(escolha) {
						case 1:	
							printf("Quantos cadastros você quer realizar?\n");
              scanf("%d",&quan);
              for(int i=0;i<quan;i++){
              inserir_dados();
           }			
					break;
							
						case 2:	
							mostrar_dados(primeiro);
							break;
						
						case 3:
							q_livros = quantidade_livros(primeiro);
              printf("\n");
							printf("Estoque: %d\n", q_livros);
							break;
							
						case 4:
              printf("\n");
							printf("Ano de publicação: ");
							scanf("%d", &ano_pub);
							livro_ano(primeiro, ano_pub);
							break;
							
						case 5:
							aux = 2;
							break;
							
						default:
              printf("\n");
							printf("<ERR0R!!> Opção Inválida!\n");
					}
				} while(aux != 2);
				break;
			case 2:
				aux = 1;
				break;
			default:
        printf("\n");
				printf("<ERR0R!!> Opção Inválida!\n");
		}
	} while(aux != 1);
	
	return 0;
}