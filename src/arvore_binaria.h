#ifndef ARVORE_H
#define ARVORE_H

#define FALSE 0
#define TRUE 1

#define INDEFINIDO -1
#define ESQUERDO 0
#define DIREITO 1

typedef int Elemento_arv;
typedef int Boolean;

typedef struct _no_arvore_ {

	Elemento_arv valor;//remover dps, nn removi pq da conflito com outro arqv meu
	
	char * palavra_no;
	
	int repeticoes;
	ListaLigadaPalavraLinhas * lista_linhas;
		
	struct _no_arvore_ * esq;
	struct _no_arvore_ * dir;

} No_arv;

typedef struct {

	No_arv * raiz;

} Arvore;

//FUNCOES DA ARVORE

Arvore * cria_arvore();

No_arv * busca_bin_rec(No_arv * no, char * e);

No_arv * busca_bin(Arvore * arvore, char * e);

Boolean insere_ord_rec(No_arv * raiz, No_arv * novo, int n_linha);

Boolean insere_ord(Arvore * arvore, char * e, int n_linha);

No_arv * encontra_menor(No_arv * raiz);

No_arv * encontra_maior(No_arv * raiz);

No_arv * encontra_pai_ord(No_arv * raiz, No_arv * no);

#endif //#ARVORE_H
