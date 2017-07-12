#include <stdio.h>
#include <stdlib.h>
#include "Tabuleiro.h"


int main(){

    //variaveis para iniciar o jogo
    tTabuleiro tabuleiro;
    tPlayer player1, player2;
    tabuleiroDraw draw;
    int i, j, acao;

    //inicializa o jogo
    preencheTabDraw(draw);
    criaTabuleiro(&tabuleiro);
    inserePecaNoTab(tabuleiro);
    criaPlayers(&player1, &player2);
    desenhaTabDraw(draw, tabuleiro);

    //variavel para alternar as rodadas
    int rodada = 1;
    int n = 0;
    int vencedor;

    /*
        Continua as rodadas, ate encontrar o perdedor.
        O perdedor eh encontrado quando suas pecas acabarem.
        Ao perder o player passa o status vencedor ao adversario.
    */

    while(1){
        if(rodada == 1){
            printf("P1 Escolha a peca, por suas coordenadas e uma acao:\n");
            scanf("%d%d%d", &i, &j, &acao);
            p1Choices(acao, i, j, draw, tabuleiro, player1, player2);

            rodada = 2;
        }
        else{
            printf("P2 Escolha a peca, por suas coordenadas e uma acao:\n");
            scanf("%d%d%d", &i, &j, &acao);
            p2Choices(acao, i, j, draw, tabuleiro, player1, player2);

            rodada = 1;
        }

        if(verificaPerdedor(player1)){
            vencedor = 2;
            break;
        }

        if(verificaPerdedor(player2)){
            vencedor = 1;
            break;
        }
    }    

    //imprime o vencedor e encerra o programa :)
    if(vencedor == 1){
        printf(" ____  _        _ __   _______ ____  _ \n");
        printf("|  _ \\| |      / \\\\ \\ / / ____|  _ \\/ |\n");
        printf("| |_) | |     / _ \\\\ V /|  _| | |_) | |\n");
        printf("|  __/| |___ / ___ \\| | | |___|  _ <| |\n");
        printf("|_|   |_____/_/   \\_\\_| |_____|_| \\_\\_|\n");
        printf("                                       \n");
        printf("__        ___       \n");
        printf("\\ \\      / (_)_ __  \n");
        printf(" \\ \\ /\\ / /| | '_ \\ \n");
        printf("  \\ V  V / | | | | |\n");
        printf("   \\_/\\_/  |_|_| |_|\n");
        printf("                    \n");
    }

    if(vencedor = 2){
        printf(" ____  _        _ __   _______ ____  ____  \n");
        printf("|  _ \\| |      / \\\\ \\ / / ____|  _ \\|___ \\ \n");
        printf("| |_) | |     / _ \\\\ V /|  _| | |_) | __) |\n");
        printf("|  __/| |___ / ___ \\| | | |___|  _ < / __/ \n");
        printf("|_|   |_____/_/   \\_\\_| |_____|_| \\_\\_____|\n");
        printf("                                           \n");
        printf("__        ___       \n");
        printf("\\ \\      / (_)_ __  \n");
        printf(" \\ \\ /\\ / /| | '_ \\ \n");
        printf("  \\ V  V / | | | | |\n");
        printf("   \\_/\\_/  |_|_| |_|\n");
        printf("                    \n");
    }  

    return 0;
}
