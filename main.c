#include <stdio.h>
#include <stdlib.h>

#include <malloc.h>

typedef int telem;
typedef struct no{
	telem dado;
	struct no* prox;
} tno;

typedef tno* tpilha;

//1) Criar uma pilha vazia
void criar (tpilha *p);

//2) Testar se a pilha está vazia
int vazia (tpilha p);

//3) Obter o elemento do topo da pilha (sem eliminar)
int elemtopo (tpilha p, telem *elem);

//4) Inserir um novo elemento no topo da pilha (empilhar)
int push (tpilha *p, telem valor);

//5) Remove o elemento do topo da pilha (desempilhar), retornando o elemento removido
int pop (tpilha *p, telem *valor);

//6 - Imprime uma pilha recursiva
void imprime(tpilha Pilha);

//Funcao principal
int main()
{
	tpilha p;
	telem valor;
	criar(&p);
	//imprime(&p);

	int opcao;

   do{

		printf("\n\n\n\tEDITOR DE PILHAS ENC ");
		printf("\n\t1 - EXIBIR PILHA   ");
		printf("\n\t2 - INSERIR TOPO   ");
		printf("\n\t3 - REMOVER TOPO   ");
		printf("\n\t4 - EXIBIR TOPO    ");
		printf("\n\t5 - SAIR           ");

		printf("\n\n\t  DIGITE SUA OPÇÃO: ");
		scanf("%d",&opcao);
		system("CLS");
		switch(opcao){

			case 1: {
				imprime(p);
			}break;

			case 2: {

				printf("\n Indique o valor a colocar no topo:");
				scanf("%d",&valor);
				if(push(&p, valor)>0){
					printf("\n\tOK - push (&p, %d)",valor);
				}
			}break;

			case 3:{
				telem valor;
				if(pop(&p, &valor)>0)
					printf("\n\t OK pop(&p, %d)", valor);

			}break;
			case 4:{
				//telem valor;
				if(elemtopo (p, &valor)>0){
					printf("\n\t OK elemtopo(p, [%d])", valor);
				}
			}break;
		}

	}while(opcao!=5);

    return 0;
}

//1) Criar uma pilha vazia
void criar (tpilha *p)
{
	*p = NULL;
}

//2) Testar se a pilha está vazia
int vazia (tpilha p)
{
	return (p == NULL);
}

//3) Obter o elemento do topo da pilha (sem eliminar)
int elemtopo (tpilha p, telem *elem)
{
	if (vazia(p)) return 0; /* erro: pilha vazia */
	*elem = p->dado;
	return 1;
}

//4) Inserir um novo elemento no topo da pilha (empilhar)
int push (tpilha *p, telem valor)
{
	tpilha novo;
	novo = (tno *) malloc(sizeof(tno));
	if (novo == NULL){
		printf("\n\tERRO: Memoria insuficiente! ");
		return -1; /* erro: mem¢ria insuficiente */
	}
	novo->dado = valor;
	novo->prox = *p;
	*p = novo;
	return 1;
}

//5) Remove o elemento do topo da pilha (desempilhar), retornando o elemento removido
int pop (tpilha *p, telem *valor)
{
	tpilha aux;
	if (vazia(*p)) return 0; /* erro: lista vazia */
	aux = *p;
	*valor = (*p)->dado;
	*p = aux->prox;
	free(aux);
	return 1;
}

//6 - Imprime uma pilha recursiva
void imprime(tpilha Pilha) {

	tpilha aux;
	if(vazia(Pilha)){//Não existem elementos

		printf("\n\tLista Vazia");
		return ;
	}
	else{
		printf("\t <- %d",(Pilha)->dado);
		imprime(((Pilha)->prox)); //lista os restantes elementos
	}

}
