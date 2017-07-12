#ifndef ABP_H_INCLUDED
#define ABP_H_INCLUDED

//Aqui pode-se alterar para qualquer tamanho de tabuleiro
#define TAMANHOTAB 64
#define TAMANHOLINHA 8	
#define NUMDEPECAS 12


//Tabuleiro eh uma arvore de posicoes
typedef struct posicao{
	int 	numero;
	int 	ocupante;// 0 - vazio, 1 - player1, 2 - player2
	struct  posicao *esq;
	struct  posicao *dir; 
}tPosicao;       

typedef tPosicao *tTabuleiro; 

//Desenho do Tabuleiro
typedef int tabuleiroDraw[TAMANHOLINHA][TAMANHOLINHA];

//Os players sao listas encadeadas
typedef struct player{
	int 	pecas[NUMDEPECAS];
	int 	contaPecas;
}tPlayer;

void criaTabuleiro(tTabuleiro *Tabuleiro);
int insereTabuleiro(tTabuleiro *Tabuleiro, int numero);//linka arvore(tabuleiro) com matriz(desenho)
void exibeTabuleiro(tTabuleiro T);//funcao para debbugar

tTabuleiro buscaPosicao(tTabuleiro T, int valor);

void inserePecaNoTab(tPosicao *T);

int verifAndarDirP1(tPosicao *T, int posAtual);
int verifAndarEsqP1(tPosicao *T, int posAtual);
int verifAndarDirP2(tPosicao *T, int posAtual);
int verifAndarEsqP2(tPosicao *T, int posAtual);

int verifCaptuDirP1(tPosicao *T, int posAtual);
int verifCaptuEsqP1(tPosicao *T, int posAtual);
int verifCaptuDirP2(tPosicao *T, int posAtual);
int verifCaptuEsqP2(tPosicao *T, int posAtual);

void p1Choices(int acao, int i, int j, tabuleiroDraw draw, tPosicao *T, tPlayer player1, tPlayer player2);
void p2Choices(int acao, int i, int j, tabuleiroDraw draw, tPosicao *T, tPlayer player1, tPlayer player2);

void movePecaDirP1(tPosicao *T, int posAtual);
void movePecaEsqP1(tPosicao *T, int posAtual);
void movePecaDirP2(tPosicao *T, int posAtual);
void movePecaEsqP2(tPosicao *T, int posAtual);


void captuDirP1(tPosicao *T, int posAtual, tPlayer player1);
void captuEsqP1(tPosicao *T, int posAtual, tPlayer player1);
void captuDirP2(tPosicao *T, int posAtual, tPlayer player1);
void captuEsqP2(tPosicao *T, int posAtual, tPlayer player1);

void preencheTabDraw(tabuleiroDraw draw);
void imprimeInstrucoes();
void desenhaTabDraw(tabuleiroDraw draw, tPosicao *T);

void criaPlayers(tPlayer *player1, tPlayer *player2);
int verificaPerdedor(tPlayer player);

#endif
