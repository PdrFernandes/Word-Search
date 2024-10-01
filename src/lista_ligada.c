#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "lista_ligada.h"

//LISTA LIGADA PALAVRAS LINHAS
char* lista_ligada_linha(ListaLigada * lista, int index) {
	No * p = lista->primeiro;
	int i = 0;
	while (i < index) {
		p=p->proximo;
		i++;
	}

	return p->valor;
}

ListaLigadaPalavraLinhas * cria_lista_palavra_linhas(){
	ListaLigadaPalavraLinhas * lista =  (ListaLigadaPalavraLinhas *) malloc (sizeof(ListaLigadaPalavraLinhas));
	lista->primeiro = NULL;
	
	return lista;
}

void destroi_lista_palavra_linhas(ListaLigadaPalavraLinhas * lista){

	NoPalavraLinhas * p = lista->primeiro;
	NoPalavraLinhas * tmp;

	while(p){
		
		tmp = p;
		p = p->proximo;
		free(tmp);
	}

	free(lista);
}
int tamanho_lista_ligada_palavra_linhas(ListaLigadaPalavraLinhas * lista){

	int tamanho = 0;

	NoPalavraLinhas * p = lista->primeiro;

	while(p){
		tamanho++;
		p = p->proximo;
	}

	return tamanho;
}
Boolean insere_lista_ligada_palavra_linhas(ListaLigadaPalavraLinhas * lista, int n_linha, int indice){

	int i;

	NoPalavraLinhas * p;
	NoPalavraLinhas * novo = (NoPalavraLinhas *) malloc(sizeof(NoPalavraLinhas));
	
	novo->linha = n_linha;
	if(indice == 0){
		novo->proximo = lista->primeiro;
		lista->primeiro = novo;
	}
	else {
		i = 0;
		p = lista->primeiro;

		while(p){

			if(i == indice - 1) break;

			i++;
			p = p->proximo;
		}
		
		novo->proximo = p->proximo;
		p->proximo = novo;
	}
	return TRUE;
}

void imprime_lista_ligada_palavra_linhas(ListaLigadaPalavraLinhas * lista, ListaLigada * lista_linhas){
	NoPalavraLinhas * p;
	int num;
	for(p = lista->primeiro; p; p = p->proximo){
		
		if (p->linha != num) {
			printf(" %05d: %s\n", p->linha, lista_ligada_linha(lista_linhas, p->linha-1));
			num = p->linha;
		}
	}
	//printf("\n");
}
//FIM LISTA LIGADA PALAVRA LINHAS

//LISTA LIGADA PALAVRAS
ListaLigadaPalavra * cria_lista_palavra(){
	ListaLigadaPalavra * lista =  (ListaLigadaPalavra *) malloc (sizeof(ListaLigadaPalavra));
	lista->primeiro = NULL;
	
	return lista;
}

void destroi_lista_palavra(ListaLigadaPalavra * lista){

	NoPalavra * p = lista->primeiro;
	NoPalavra * tmp;

	while(p){
		
		tmp = p;
		p = p->proximo;
		free(tmp);
	}

	free(lista);
}
int tamanho_lista_ligada_palavra(ListaLigadaPalavra * lista){

	int tamanho = 0;

	NoPalavra * p = lista->primeiro;

	while(p){
		tamanho++;
		p = p->proximo;
	}

	return tamanho;
}
Boolean insere_lista_ligada_palavra_ordenada(ListaLigadaPalavra * lista, int n_linha, Elemento e){

	NoPalavra * p;
	NoPalavra * anterior;
	NoPalavra * novo = (NoPalavra *) malloc(sizeof(NoPalavra));
	
	novo->str_palavra = (char *) malloc(strlen(e));
	strcpy(novo->str_palavra, e);
	novo->ocorrencias = 1;

	anterior = NULL;
	p = lista->primeiro;

	while(p){
		if(strcmp(e, p->str_palavra) == 0) { //Caso elemento for igual ao n�, aumenta a ocorr�ncia e adiciona na lista de linhas
			insere_lista_ligada_palavra_linhas(p->lista_linhas, n_linha, p->ocorrencias);
			p->ocorrencias++;
			return TRUE;
		}
		if(strcmp(e, p->str_palavra) < 0) break;
 			
		anterior = p;
		p = p->proximo;
	}
	
	novo->proximo = p;
	novo->lista_linhas = cria_lista_palavra_linhas();
	insere_lista_ligada_palavra_linhas(novo->lista_linhas, n_linha, 0);

	if(anterior) anterior->proximo = novo;
	else {
		lista->primeiro = novo;	
	}

	return TRUE;
}

NoPalavra * elemento_lista_palavra(ListaLigadaPalavra * lista, int index) {
	NoPalavra * p = lista->primeiro;
	int i = 0;
	while (i < index) {
		p=p->proximo;
		i++;
	}

	return p;
}

NoPalavra * busca_bin_lista (ListaLigadaPalavra * lista, char * palavra, int inf, int sup) {
	if (inf > sup) return NULL;
	
	int meio = (sup+inf)/2;
	NoPalavra * elemento_meio = elemento_lista_palavra(lista, meio);

	if (strcmp(elemento_meio->str_palavra, palavra) == 0) return elemento_meio;
	if (strcmp(elemento_meio->str_palavra, palavra) < 0) return busca_bin_lista(lista, palavra, meio+1, sup);
	else return busca_bin_lista(lista, palavra, inf, meio-1);
}
//FIM LISTA LIGADA PALAVRA

//LISTA LIGADA
ListaLigada * cria_lista(){
	ListaLigada * lista =  (ListaLigada *) malloc (sizeof(ListaLigada));
	lista->primeiro = NULL;
	
	return lista;
}

void destroi_lista(ListaLigada * lista){

	No * p = lista->primeiro;
	No * tmp;

	while(p){
		
		tmp = p;
		p = p->proximo;
		free(tmp);
	}

	free(lista);
}

int tamanho_lista_ligada(ListaLigada * lista){

	int tamanho = 0;

	No * p = lista->primeiro;

	while(p){
		tamanho++;
		p = p->proximo;
	}

	return tamanho;
}

void imprime_lista_ligada(ListaLigada * lista){

	No * p;

	printf("Lista: \n");

	for(p = lista->primeiro; p; p = p->proximo){

		printf("%04d: ", p->numero_linha);
		printf("%s\n", p->valor);
	}

	printf("\n");
}

Boolean insere_lista_ligada(ListaLigada * lista, Elemento e, int indice){

	int i;

	No * p;
	No * novo = (No *) malloc(sizeof(No));

	//novo->valor = (char *) malloc(strlen(e));
	novo->valor = (char *) malloc((strlen(e))+ 1);
	strcpy(novo->valor, e);
	
	novo->numero_linha = indice + 1;
	
	if(indice == 0){

		novo->proximo = lista->primeiro;
		lista->primeiro = novo;
	}
	else {
		i = 0;
		p = lista->primeiro;

		while(p){

			if(i == indice - 1) break;

			i++;
			p = p->proximo;
		}
		
		novo->proximo = p->proximo;
		p->proximo = novo;
	}
	return TRUE;
}
//FIM LISTA LIGADA
