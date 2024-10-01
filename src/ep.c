
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>

#include "lista_ligada.h"
#include "arvore_binaria.h"

#include "lista_ligada.c"
#include "arvore.c"

#define TAMANHO 1000

//Remove os h�ｽfens das linhas
// Isso �ｽ feito separado da pontua�ｽ�ｽo pois �ｽ preciso substituir o h�ｽfem por um
// espa�ｽo (' '), e assim considerar a palavra que possui o h�ｽfem como duas.
char * substituirHifen(char* linha) {
	int tamanho_Linha = strlen(linha);
    int i;

    for (i = 0; i < tamanho_Linha; i++) {
        if (linha[i] == '-') {
            linha[i] = ' ';
        }
    }

    return linha;
}

//Remove as pontua�ｽ�ｽes das palavras
char * removerPontuacao(char *str) {
    int i, j;
    int len = strlen(str);

    for (i = 0, j = 0; i < len; i++) {
        if (!ispunct((unsigned char)str[i]) && !isspace((unsigned char)str[i])) {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';
    return str;
}

//Transforma palavra em min�ｽscula
void para_minuscula(char* str) {
	int i;
    for(i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

//Fun�ｽao strsep da biblioteca string.h
// Est�ｽ aqui, porque, para executa-la no windows, ela n�ｽo �ｽ identificada
char * strsep(char **stringp, const char *delim) {
    char *start = *stringp;
    if (start) {
        /* skip all characters in the token (not delimiters) */
        char *p = start + strcspn(start, delim);
        if (*p) {
            *p++ = '\0';
            *stringp = p;
        } else {
            *stringp = NULL;
        }
    }
    return start;
}
//FIM DAS FUN�ｽ�ｽES AUXILIARES

int main(int argc, char ** argv){
	setlocale(LC_ALL, "Portuguese_Brazil");
	
    //variaveis p/ controle de tempo
	clock_t ticks[2]; //vetor para marcar o in�ｽcio e fim do contador de clocks
	double tempo;

	FILE * in;
	char * linha;
    char * copia_linha;
	char * copia_ponteiro_linha;
	char * quebra_de_linha;
	char * palavra;	
    char * copia_palavra;	
	int contador_linha;
    ListaLigada * lista_linhas;
	ListaLigadaPalavra * lista_palavras;
	Arvore * arvore;

	if(argc == 3 && ((0 == strcmp(argv[2], "lista"))||(0 == strcmp(argv[2], "arvore")))) {
        ticks[0] = clock();//inicio da contagem: arquivo e contru�ｽ�ｽo de ind�ｽce
		in = fopen(argv[1], "r");

        lista_linhas = cria_lista();

		//CASO INDEXAﾃ�グ FOR LISTA
		if ((0 == strcmp(argv[2], "lista"))) lista_palavras = cria_lista_palavra();
		//CASO INDEXAﾃ�グ FOR ARVORE
		else {
			arvore = cria_arvore();
		}
		
		
		contador_linha = 0;
 		linha = (char *) malloc((TAMANHO + 1) * sizeof(char));
		
		while(in && fgets(linha, TAMANHO, in)){
			if( (quebra_de_linha = strrchr(linha, '\n')) ) *quebra_de_linha = 0;
            
            //Insere a linha em uma lista ligada pois o nﾃｺmero de linhas em um arquivo nﾃ｣o ﾃｩ fixo.
            copia_linha = (char *) malloc((TAMANHO + 1) * sizeof(char));
            
            strcpy(copia_linha, linha);
            insere_lista_ligada(lista_linhas, copia_linha, contador_linha);
            //copia_linha[strcspn(copia_linha, "\n")] = '\0';
            
            copia_linha = substituirHifen(copia_linha);

			// fazemos uma copia do endereﾃｧo que corresponde ao array de chars 
			// usado para armazenar cada linha lida do arquivo pois a funﾃｧﾃ｣o 'strsep' 
			// modifica o endereﾃｧo do ponteiro a cada chamada feita a esta funﾃｧﾃ｣o (e 
			// nﾃ｣o queremos que 'linha' deixe de apontar para o inicio do array).

			copia_ponteiro_linha = copia_linha;

            //CASO INDEXAﾃ�グ FOR LISTA
            if ((0 == strcmp(argv[2], "lista"))) {
                while( (palavra = strsep(&copia_ponteiro_linha, " ")) ){
                    para_minuscula(palavra);
                    copia_palavra = (char *) malloc(strlen(palavra) * sizeof(char));
                    strcpy(copia_palavra, palavra);
                    
                    //Ao inserir o valor na struct do nﾃｳ da lista, usar copia_palavra invﾃｩs de palavra
                    //Se usar palavra, todos nﾃｳs terﾃ｣o o mesmo valor
                    
                    //No while, o copia_palavra sempre gera um endereﾃｧo diferente que aloca uma string entﾃ｣o nﾃ｣o causa esse erro
                    copia_palavra = removerPontuacao(copia_palavra);
					insere_lista_ligada_palavra_ordenada(lista_palavras, contador_linha+1, copia_palavra);
			    }
            }
            
            //CASO INDEXAﾃ�グ FOR ﾃヽVORE
            else {
                while( (palavra = strsep(&copia_ponteiro_linha, " ")) ){
                    para_minuscula(palavra);
                    copia_palavra = (char *) malloc(strlen(palavra) * sizeof(char));
                    strcpy(copia_palavra, palavra);
                    
                    //Ao inserir o valor na struct do nﾃｳ da ﾃ｡rvore, usar copia_palavra invﾃｩs de palavra
                    //Se usar palavra, todos nﾃｳs terﾃ｣o o mesmo valor
                    
					//No while, o copia_palavra sempre gera um endereﾃｧo diferente que aloca uma string entﾃ｣o nﾃ｣o causa esse erro
                    copia_palavra = removerPontuacao(copia_palavra);
                    insere_ord(arvore, copia_palavra, contador_linha+1);
			    }
            }

			contador_linha++;
		}

        ticks[1] = clock();//fim da contagem: arquivo e contru�ｽ�ｽo de ind�ｽce
		tempo =1000 * ((double)(ticks[1] - ticks[0])/CLOCKS_PER_SEC);//calculo do tempo em ms

        printf("Tipo de indice: '%s'\n", argv[2]);
		printf("Arquivo texto: '%s'\n", argv[1]);
		printf("Numero de linhas no arquivo: %d\n", contador_linha++);
		printf("Tempo para carregar o arquivo e construir o indice: %g ms\n", tempo);

        //variaveis para controle de entrada do teclado
		int fim;
		char * entrada_user;
		char * palavra_buscada;
		char * acao;
		
		//alocando memoria para cada string
		entrada_user = (char *) malloc((TAMANHO) * sizeof(char));
		acao = (char *) malloc((100) * sizeof(char));
		palavra_buscada = (char *) malloc((100) * sizeof(char));
		
		while (fim == 0){
			printf("> ");
			fgets(entrada_user,TAMANHO, stdin);
			entrada_user[strcspn(entrada_user, "\n")] = '\0';//remove a quebra de linha que o fgets gera
			
			if (0 == strcmp(entrada_user, "fim")) {
			fim = 1;
			break;
			}
			
			acao = strtok(entrada_user, " ");
			palavra_buscada = strtok(NULL, "\0");
			
			if (0 == strcmp(acao, "busca") && (palavra_buscada != NULL)){
				ticks[0] = clock();//inicio da contagem: busca
				para_minuscula(palavra_buscada);//transforma para minuscula a entrada para padronizar a busca
				if ((0 == strcmp(argv[2], "lista"))) {
				
					NoPalavra * no_p = busca_bin_lista(lista_palavras, palavra_buscada, 0, tamanho_lista_ligada_palavra(lista_palavras));//busca
					
					//verificar se a palavra foi encontrada ou nao
					if (no_p) {
						printf("Existem %d ocorrﾃｪncias da palavra '%s' na(s) seguinte(s) linha(s): \n", no_p->ocorrencias, palavra_buscada);
						imprime_lista_ligada_palavra_linhas(no_p->lista_linhas, lista_linhas);
					}
					else printf("Palavra '%s' nao encontrada.\n", palavra_buscada);
				}
				
				//CASO INDEXAﾃ�グ FOR ARVORE
				else {
				
					No_arv * no_a = busca_bin(arvore, palavra_buscada);//busca
					
					//verificar se a palavra foi encontrada ou nao
					if (no_a) {
						printf("Existem %d ocorrﾃｪncias da palavra '%s' na(s) seguinte(s) linha(s): \n", no_a->repeticoes, palavra_buscada);
						imprime_lista_ligada_palavra_linhas(no_a->lista_linhas, lista_linhas);
					}
					else printf("Palavra '%s' nao encontrada.\n", palavra_buscada);
				}
				
				ticks[1] = clock();//fim da contagem: busca
				tempo = 1000 * ((double)(ticks[1] - ticks[0])/CLOCKS_PER_SEC);//calculo do tempo em ms
				
				printf("Tempo de busca: %g ms\n", tempo);
			}
			
			else {
				printf("Opﾃｧﾃ｣o invﾃ｡lida!\n");
			}
			
		}
	
		return 0;
	}

	return 1;
}
