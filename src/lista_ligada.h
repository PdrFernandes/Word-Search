#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#define FALSE 0
#define TRUE 1

//#define LISTA_ORDENADA

typedef int Boolean;
typedef char * Elemento;

//LISTA LIGADA PALAVRA LINHA
typedef struct _no_palavra_linhas {
	int linha;
	struct _no_palavra_linhas * proximo;
} NoPalavraLinhas;

typedef struct {
	NoPalavraLinhas * primeiro;
} ListaLigadaPalavraLinhas;
//

//LISTA LIGADA PALAVRA	
typedef struct _no_palavra_ {
	char * str_palavra;
	int ocorrencias;
	ListaLigadaPalavraLinhas * lista_linhas;
	struct _no_palavra_ * proximo;
} NoPalavra;

typedef struct {
	NoPalavra * primeiro;
} ListaLigadaPalavra;
//

//LISTA LIGADA
typedef struct _no_ {
	Elemento valor;
	int numero_linha;
	struct _no_ * proximo;
} No;

typedef struct {
	
	No * primeiro;

} ListaLigada;
//


//FUNCOES LISTAS LIGADAS


//LISTA LIGADA PALAVRAS LINHAS
char* lista_ligada_linha(ListaLigada * lista, int index);

ListaLigadaPalavraLinhas * cria_lista_palavra_linhas();

void destroi_lista_palavra_linhas(ListaLigadaPalavraLinhas * lista);

int tamanho_lista_ligada_palavra_linhas(ListaLigadaPalavraLinhas * lista);

Boolean insere_lista_ligada_palavra_linhas(ListaLigadaPalavraLinhas * lista, int n_linha, int indice);

void imprime_lista_ligada_palavra_linhas(ListaLigadaPalavraLinhas * lista, ListaLigada * lista_linhas);
//FIM LISTA LIGADA PALAVRA LINHAS


//LISTA LIGADA PALAVRAS
ListaLigadaPalavra * cria_lista_palavra();

void destroi_lista_palavra(ListaLigadaPalavra * lista);

int tamanho_lista_ligada_palavra(ListaLigadaPalavra * lista);

Boolean insere_lista_ligada_palavra_ordenada(ListaLigadaPalavra * lista, int n_linha, Elemento e);

NoPalavra * elemento_lista_palavra(ListaLigadaPalavra * lista, int index);

NoPalavra * busca_bin_lista (ListaLigadaPalavra * lista, char * palavra, int inf, int sup);
//FIM LISTA LIGADA PALAVRA


//LISTA LIGADA
ListaLigada * cria_lista();

void destroi_lista(ListaLigada * lista);

int tamanho_lista_ligada(ListaLigada * lista);

void imprime_lista_ligada(ListaLigada * lista);

Boolean insere_lista_ligada(ListaLigada * lista, Elemento e, int indice);
//FIM LISTA LIGADA

#endif //LISTA_LIGADA_H
