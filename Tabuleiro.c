#include <stdio.h>
#include <stdlib.h>
#include "Tabuleiro.h"


void p1Choices(int acao, int i, int j, tabuleiroDraw draw, tPosicao *T, tPlayer player1, tPlayer player2){
	int peca;

	peca = draw[i-1][j-1];
	/*
		4 - Andar Direita
		5 - Andar Esquerda
		6 - Capturar Direita
		7 - Capturar Esquerda
	*/
	int statusPosicao;

	switch(acao){
		case 4:
			if(verifAndarDirP1(T, peca) != 0 ){
				printf("Operacao Invalida, casa ocupada\n");
			}
			else{
				movePecaDirP1(T, peca);
				desenhaTabDraw(draw, T);
			}
			break;

		case 5:
			if(verifAndarEsqP1(T, peca) != 0 ){
				printf("Operacao Invalida, casa ocupada\n");
			}
			else{
				movePecaEsqP1(T, peca);
				desenhaTabDraw(draw, T);
			}
			break;

		case 6:
			if(verifCaptuDirP1(T, peca)){
				captuEsqP2(T, peca, player2);
				desenhaTabDraw(draw, T);
			}
			else{
				printf("Operacao Invalida, nao pode capturar!\n");	
			}
			break;

		case 7:
			if(verifCaptuEsqP1(T, peca)){
				captuEsqP2(T, peca, player2);
				desenhaTabDraw(draw, T);
			}
			else{
				printf("Operacao Invalida, nao pode capturar!\n");	
			}
			break;			

		default:
			printf("Oooops\n");
			break;
	}
}

void movePecaDirP1(tPosicao *T, int posAtual){
	tPosicao *aux1, *aux2;

	aux1 = buscaPosicao(T, posAtual);
	aux1->ocupante = 0;

	int numPosDir = posAtual + (TAMANHOLINHA + 1);
	aux2 = buscaPosicao(T, numPosDir);
	aux2->ocupante = 1;
}

void movePecaEsqP1(tPosicao *T, int posAtual){
	tPosicao *aux1, *aux2;

	aux1 = buscaPosicao(T, posAtual);
	aux1->ocupante = 0;

	int numPosDir = posAtual + (TAMANHOLINHA - 1);
	aux2 = buscaPosicao(T, numPosDir);
	aux2->ocupante = 1;
}

void captuEsqP1(tPosicao *T, int posAtual, tPlayer player2){
	tPosicao *aux1, *aux2, *aux3;

	aux1 = buscaPosicao(T, posAtual);
	aux1->ocupante = 0;

	int numPosDir = posAtual + (TAMANHOLINHA + 1);
	aux2 = buscaPosicao(T, numPosDir);
	aux2->ocupante = 0;

	int numPosDirDir = numPosDir + (TAMANHOLINHA + 1);
	aux3 = buscaPosicao(T, numPosDirDir);
	aux3->ocupante = 1;	

	player2.contaPecas--;
}

void captuDirP1(tPosicao *T, int posAtual, tPlayer player2){
	tPosicao *aux1, *aux2, *aux3;

	aux1 = buscaPosicao(T, posAtual);
	aux1->ocupante = 0;

	int numPosDir = posAtual + (TAMANHOLINHA - 1);
	aux2 = buscaPosicao(T, numPosDir);
	aux2->ocupante = 0;

	int numPosDirDir = numPosDir + (TAMANHOLINHA - 1);
	aux3 = buscaPosicao(T, numPosDirDir);
	aux3->ocupante = 1;	

	player2.contaPecas--;
}

int verifCaptuDirP1(tPosicao *T, int posAtual){//Deve-se passar a arvore!

	tPosicao *aux;
	int numPosDir = posAtual + (TAMANHOLINHA + 1);
	aux = buscaPosicao(T, numPosDir);

	if(verifAndarDirP1(T, posAtual) == 2){//sei que tem inimigo
		if(verifAndarDirP1(T, numPosDir) == 0){//atras do inimigo esta vazio
			return 1; //pode comer
		}
	}
	return 0; //nao pode comer
}

int verifCaptuEsqP1(tPosicao *T, int posAtual){//Deve-se passar a arvore!

	tPosicao *aux;
	int numPosDir = posAtual + (TAMANHOLINHA - 1);
	aux = buscaPosicao(T, numPosDir);

	if(verifAndarEsqP1(T, posAtual) == 2){//sei que tem inimigo
		if(verifAndarEsqP1(T, numPosDir) == 0){//atras do inimigo esta vazio
			return 1; //pode comer
		}
	}
	return 0; //nao pode comer
}

void p2Choices(int acao, int i, int j, tabuleiroDraw draw, tPosicao *T, tPlayer player1, tPlayer player2){
	int peca;

	peca = draw[i-1][j-1];
	/*
		4 - Andar Direita
		5 - Andar Esquerda
		6 - Capturar Direita
		7 - Capturar Esquerda
	*/
	int statusPosicao;

	switch(acao){
		case 4:
			if(verifAndarDirP2(T, peca) != 0 ){
				printf("Operacao Invalida, casa ocupada\n");
			}
			else{
				movePecaDirP2(T, peca);
				desenhaTabDraw(draw, T);
			}
			break;

		case 5:
			if(verifAndarEsqP2(T, peca) != 0 ){
				printf("Operacao Invalida, casa ocupada\n");
			}
			else{
				movePecaEsqP2(T, peca);
				desenhaTabDraw(draw, T);
			}
			break;

		case 6:
			if(verifCaptuDirP2(T, peca)){
				captuEsqP2(T, peca, player1);
				desenhaTabDraw(draw, T);
			}
			else{
				printf("Operacao Invalida, nao pode capturar!\n");	
			}
			break;

		case 7:
			if(verifCaptuEsqP2(T, peca)){
				captuEsqP2(T, peca, player1);
				desenhaTabDraw(draw, T);
			}
			else{
				printf("Operacao Invalida, nao pode capturar!\n");	
			}
			break;			
			
		default:
			printf("Oooops\n");
			break;
	}
}

void movePecaDirP2(tPosicao *T, int posAtual){
	tPosicao *aux1, *aux2;

	aux1 = buscaPosicao(T, posAtual);
	aux1->ocupante = 0;

	int numPosDir = posAtual - (TAMANHOLINHA - 1);
	aux2 = buscaPosicao(T, numPosDir);
	aux2->ocupante = 2;
}

void movePecaEsqP2(tPosicao *T, int posAtual){
	tPosicao *aux1, *aux2;

	aux1 = buscaPosicao(T, posAtual);
	aux1->ocupante = 0;

	int numPosDir = posAtual - (TAMANHOLINHA + 1);
	aux2 = buscaPosicao(T, numPosDir);
	aux2->ocupante = 2;
}

int verifCaptuDirP2(tPosicao *T, int posAtual){//Deve-se passar a arvore!

	tPosicao *aux;
	int numPosDir = posAtual - (TAMANHOLINHA - 1);
	aux = buscaPosicao(T, numPosDir);

	if(verifAndarDirP2(T, posAtual) == 1){//sei que tem inimigo
		if(verifAndarDirP2(T, numPosDir) == 0){//atras do inimigo esta vazio
			return 1; //pode comer
		}
	}
	return 0; //nao pode comer
}

int verifCaptuEsqP2(tPosicao *T, int posAtual){//Deve-se passar a arvore!

	tPosicao *aux;
	int numPosDir = posAtual - (TAMANHOLINHA + 1);
	aux = buscaPosicao(T, numPosDir);

	if(verifAndarEsqP2(T, posAtual) == 1){//sei que tem inimigo
		if(verifAndarEsqP2(T, numPosDir) == 0){//atras do inimigo esta vazio
			return 1; //pode comer
		}
	}
	return 0; //nao pode comer
}

void captuDirP2(tPosicao *T, int posAtual, tPlayer player1){
	tPosicao *aux1, *aux2, *aux3;

	aux1 = buscaPosicao(T, posAtual);
	aux1->ocupante = 0;

	int numPosDir = posAtual - (TAMANHOLINHA - 1);
	aux2 = buscaPosicao(T, numPosDir);
	aux2->ocupante = 0;

	int numPosDirDir = numPosDir - (TAMANHOLINHA - 1);
	aux3 = buscaPosicao(T, numPosDirDir);
	aux3->ocupante = 2;	

	player1.contaPecas--;
}

void captuEsqP2(tPosicao *T, int posAtual, tPlayer player1){
	tPosicao *aux1, *aux2, *aux3;

	aux1 = buscaPosicao(T, posAtual);
	aux1->ocupante = 0;

	int numPosDir = posAtual - (TAMANHOLINHA + 1);
	aux2 = buscaPosicao(T, numPosDir);
	aux2->ocupante = 0;

	int numPosDirDir = numPosDir - (TAMANHOLINHA + 1);
	aux3 = buscaPosicao(T, numPosDirDir);
	aux3->ocupante = 2;	

	player1.contaPecas--;
}

/*Tambem verifica direita "atras" de P2*/
int verifAndarDirP1(tPosicao *T, int posAtual){//Deve-se passar a arvore!

	tPosicao *aux;

	int numPosDir = posAtual + (TAMANHOLINHA + 1);
	aux = buscaPosicao(T, numPosDir);

	return aux->ocupante;
}

/*Tambem verifica esquerda "atras" de P2*/
int verifAndarEsqP1(tPosicao *T, int posAtual){//Deve-se passar a arvore!

	tPosicao *aux;

	int numPosDir = posAtual + (TAMANHOLINHA - 1);
	aux = buscaPosicao(T, numPosDir);

	return aux->ocupante;
}

/*Tambem verifica esquerda "atras" de P1*/
int verifAndarEsqP2(tPosicao *T, int posAtual){//Deve-se passar a arvore!

	tPosicao *aux;

	int numPosDir = posAtual - (TAMANHOLINHA + 1);
	aux = buscaPosicao(T, numPosDir);

	return aux->ocupante;
}

/*Tambem verifica direita "atras" de P1*/
int verifAndarDirP2(tPosicao *T, int posAtual){//Deve-se passar a arvore!

	tPosicao *aux;

	int numPosDir = posAtual - (TAMANHOLINHA - 1);
	aux = buscaPosicao(T, numPosDir);

	return aux->ocupante;
}

void criaPlayers(tPlayer *player1, tPlayer *player2){
	int i;

	for(i=0; i<NUMDEPECAS; i++){
		player1->pecas[i] == 1;
		player2->pecas[i] == 2;
	}

	player1->contaPecas = NUMDEPECAS;
	player2->contaPecas = NUMDEPECAS;
}

void inserePecaNoTab(tPosicao *T){

	tPosicao *aux;
	int linha = 1;
	int i;
	int casaDesocupada = 0;
	int p1Valor = 1;
	int p2Valor = 2;
	int casaBranca = -1;
	//insere as pecas player1
	for(i=1; i<=(NUMDEPECAS*2); i++){
		if(linha % 2 != 0 || linha == 1){
			if(i % 2 == 0){
				aux = buscaPosicao(T, i);
				aux->ocupante = p1Valor;
			}
			else{
				aux = buscaPosicao(T, i);
				aux->ocupante = casaBranca;
			}
		}
		else{
			if(i % 2 != 0){
				aux = buscaPosicao(T, i);
				aux->ocupante = p1Valor;
			}
			else{
				aux = buscaPosicao(T, i);
				aux->ocupante = casaBranca;
			}
		}
		if(i % TAMANHOLINHA == 0){linha++;}
	}

	for(i; i<=64; i++){
		//Insere Casas Desocupadas no meio
		if((i>=25) && (i<=40)){
			if(linha % 2 != 0 || linha == 1){
				if(i % 2 == 0){
					aux = buscaPosicao(T, i);
					aux->ocupante = casaDesocupada;
				}
			}
			else{
				if(i % 2 != 0){
					aux = buscaPosicao(T, i);
					aux->ocupante = casaDesocupada;
				}
			}
		}
		else{
			if(linha % 2 != 0 || linha == 1){
				if(i % 2 == 0){
					aux = buscaPosicao(T, i);
					aux->ocupante = p2Valor;
				}
				else{
				aux = buscaPosicao(T, i);
				aux->ocupante = casaBranca;
				}
			}
			else{
				if(i % 2 != 0){
					aux = buscaPosicao(T, i);
					aux->ocupante = p2Valor;
				}
				else{
				aux = buscaPosicao(T, i);
				aux->ocupante = casaBranca;
				}
			}
		}
		if(i % TAMANHOLINHA == 0){linha++;}
	}
}

// void inserePecaNoTab2(tTabuleiro T){
// 	if (T != NULL) {
// 		inserePecaNoTab(T->esq);
// 		T->ocupante = 1;
// 		inserePecaNoTab(T->dir);
// 		T->ocupante = 2;
// 	}
// }


void criaTabuleiro(tTabuleiro *T){
	*T = NULL;

	int i;
	int linha  = 1;
	int paridade;

	//
	for(i = 1; i<=TAMANHOTAB; i++){
		// if(linha % 2 != 0 || linha == 1){
		// 	if(i % 2 == 0){
		// 		insereTabuleiro(T, i);
		// 	}
		// }
		// else{
		// 	if(i % 2 != 0){
		// 		insereTabuleiro(T, i);
		// 	}
		// }
		// if(i % TAMANHOLINHA == 0){linha++;}
		insereTabuleiro(T, i);
	}
}

int insereTabuleiro(tTabuleiro *T, int valorPosicao){
	tPosicao *novaPosicao, *aux, *p;

	novaPosicao = malloc(sizeof(tPosicao));
	if (novaPosicao == NULL)
        return 0;

	novaPosicao->numero = valorPosicao;
	novaPosicao->ocupante = -1;
	novaPosicao->esq = NULL;
	novaPosicao->dir = NULL;

	if (*T == NULL){ 
 		*T = novaPosicao;
		return 1;
	}

    aux = *T;
    while (aux != NULL) {
        p = aux;
		if (valorPosicao < aux->numero)
			aux = aux->esq;
		else
			aux = aux->dir;
	}

	if (valorPosicao < p->numero){
		p->esq = novaPosicao;
	}else{
		p->dir = novaPosicao;
	}

	return 1;
}

tTabuleiro buscaPosicao(tTabuleiro T, int valor){

	//if (T == NULL)
	//	return NULL;  /* Arvore Vazia*/

	if(T->numero == valor){
		return T; /*Elem. encontrado na raiz*/
	}

	if (valor < T->numero){
		return buscaPosicao(T->esq, valor);
    }
    else{
		return buscaPosicao(T->dir, valor);
    }
}


int verificaPerdedor(tPlayer player){
	if(player.contaPecas == 0){
		return 1;
	}

	return 0;
}

void exibeTabuleiro(tTabuleiro T){
	if (T != NULL) {
		exibeTabuleiro(T->esq);
		printf("casa: %d , ocupante: %d  \n", T->numero, T->ocupante);
		exibeTabuleiro(T->dir);
	}
}

void preencheTabDraw(tabuleiroDraw draw){
	int i, 
	j, 
	contador;

	contador = 0;

	for(i = 0; i<TAMANHOLINHA; i++){
		for(j = 0; j<TAMANHOLINHA; j++){
			contador++;
			draw[i][j] = contador;
		}
	}
}

void imprimeInstrucoes(){

	printf("\n");
	printf("Instruções:\n");
	printf("Para selecionar uma peça:\n");
	printf("\tDigite primeiro a posição vertical;\n");
	printf("\tLogo depois digite a posição horizontal;\n");
	printf("\tPor último digite uma ação:\n");
	printf("\t\t4 - Move para a direita;\n");
	printf("\t\t5 - Move para a esquerda;\n");
	printf("\t\t6 - Captura a direita;\n");
	printf("\t\t7 - Captura a esquerda;\n");
	printf("\tDivirta-se!\n");
}

void desenhaTabDraw(tabuleiroDraw draw, tPosicao *T){
	int i, 
	j, 
	contador, 
	conteudoPosicao;

	tPosicao *aux;

	contador = 0;

	imprimeInstrucoes();

	printf("\n\n");

	printf("      1 2 3 4 5 6 7 8 \n");

	for(i = 0; i<TAMANHOLINHA; i++){
		
		printf("   %i |", i+1);

		for(j = 0; j < TAMANHOLINHA; j++){

			contador++;
			aux = buscaPosicao(T, contador);
			conteudoPosicao = aux->ocupante;

			switch(conteudoPosicao){
				case -1:
					printf(" |");
					break;

				case 0:
					printf("#|");
					break;

				case 1:
					printf("o|");				
					break;

				case 2:
					printf("O|");
					break;
			}
		}

		printf("\n");
	}
	printf("\n");
}