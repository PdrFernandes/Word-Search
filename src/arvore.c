#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "lista_ligada.h"
#include "arvore_binaria.h"

//ARVORE

Arvore * cria_arvore(){

	Arvore * arvore = (Arvore *) malloc (sizeof(Arvore));
	arvore->raiz = NULL;
	return arvore;
}

No_arv * busca_bin_rec(No_arv * no, char * e){

	if(no){
		
		if (0 == strcmp(no->palavra_no,e)) return no;
		if (0 < strcmp(no->palavra_no,e)) return busca_bin_rec(no->esq, e);
		//if(no->valor == e) return no;
		//if(e < no->valor) return busca_bin_rec(no->esq, e);
		return busca_bin_rec(no->dir, e);
	}

	return NULL;
}

No_arv * busca_bin(Arvore * arvore, char * e){
	
	return busca_bin_rec(arvore->raiz, e);	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Boolean insere_ord_rec(No_arv * raiz, No_arv * novo, int n_linha){
	if(0 != strcmp(raiz->palavra_no,novo->palavra_no)){//maior q 0 o da direita vem antes
		
		if(strcmp(raiz->palavra_no,novo->palavra_no) > 0){

			if(raiz->esq) return insere_ord_rec(raiz->esq, novo, n_linha);
			else {
				novo->lista_linhas = cria_lista_palavra_linhas();
				insere_lista_ligada_palavra_linhas(novo->lista_linhas, n_linha, 0);	
				raiz->esq = novo;
			}
		}
		else{
			if(raiz->dir) return insere_ord_rec(raiz->dir, novo, n_linha);
			else {
				novo->lista_linhas = cria_lista_palavra_linhas();
				insere_lista_ligada_palavra_linhas(novo->lista_linhas, n_linha, 0);	
				raiz->dir = novo;
			}
		}
		return TRUE;
	}
	
	insere_lista_ligada_palavra_linhas(raiz->lista_linhas, n_linha, raiz->repeticoes);
	raiz->repeticoes++;//se a palavra for a mesma, incrementa suas repeticoes
	return FALSE;
}

Boolean insere_ord(Arvore * arvore, char * e, int n_linha){

	No_arv * novo = (No_arv *) malloc(sizeof(No_arv));
	novo->repeticoes = 1;
	
	novo->palavra_no = (char *) malloc((strlen(e)));
	strcpy(novo->palavra_no, e);
	novo->esq = novo->dir = NULL;

	if(arvore->raiz) return insere_ord_rec(arvore->raiz, novo, n_linha);
	
	novo->lista_linhas = cria_lista_palavra_linhas();
	insere_lista_ligada_palavra_linhas(novo->lista_linhas, n_linha, 0);	
	arvore->raiz = novo;
	
	return TRUE;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

No_arv * encontra_menor(No_arv * raiz){

	if(raiz->esq) return encontra_menor(raiz->esq);
	
	return raiz;
}

No_arv * encontra_maior(No_arv * raiz){

	if(raiz->dir) return encontra_maior(raiz->dir);
	
	return raiz;
}

No_arv * encontra_pai_ord(No_arv * raiz, No_arv * no){

	if(raiz){

		if(raiz->esq == no) return raiz;
		if(raiz->dir == no) return raiz;
		if(no->valor < raiz->valor) return encontra_pai_ord(raiz->esq, no);
		if(no->valor > raiz->valor) return encontra_pai_ord(raiz->dir, no);
	}
		
	return NULL;
}
//FIM ARVORE
