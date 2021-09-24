/*****************************************
Etapa 1 do Projeto de POO - Jogo da Forca
******************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "forca.h"

using namespace std;

/* PRINCIPAL */ 
int main(void) {

    /* VARIAVEIS */
    char letra;
    string palavra_escolhida, escolhida_final;
    int tamanho = 0, tentativas = 5, acertos = 0, indice, nivel;
    bool acerto = false;

    //Para gerar números aleatórios
    srand((unsigned)time(0));  

    // Designando as palavras fáceis
    string palavra_facil[15] = {"BOLA", "BALA", "PYTHON", "AMOR", "DOCE",
                                "CAMA", "CASA", "NOITE", "BOLO", "DADOS",
                                "GATO", "AZUL", "PORTA", "OURO", "CAJU"};

    // Designando as palavras medias   
    string palavra_medio[15] = {"CIENCIA", "GUERRA", "FOGUETE", "MEDICO", "FOGUEIRA",
                                "ESCOPO", "CLIENTE", "FABRICA", "DUVIDA", "MEXICO",
                                "REMOTO", "CONTROLE", "IRONIA", "CHAPEU", "ESTADO"};

    // Designando as palavras dificeis 
    string palavra_dific[15] = {"ANSIEDADE", "CIENTISTA", "INTELIGENCIA", "ARTIFICIAL", "ZOOLOGICO",
                                "COMPRIMENTO", "MEDICINA", "BEXIGA", "GOIABA", "MACAXEIRA", 
                                "QUARENTENA", "PANDEMIA", "AMENDOIM", "GUARDANAPO", "GELADEIRA"};

    //Designando o espaço da palavra
    string descobre_palavra[15] = {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_",
                                   "_", "_", "_", "_", "_",};

    //Gerando um numero aleatorio para escolher palavra aleatoria de x ate y
    indice = numeroAleatorio(0, 14);

    //Colhendo o nivel e iniciando a pseudo tela do jogo
    LimpaConsole();
    nivel = tela_inicial();

    //De acordo com o nivel captado é determinado as tentativas e ocorre a escolha aleatoria da palavra
    switch(nivel) {
        case 1:
        cout << "\nVoce selecionou o nivel: FACIL\n";
        palavra_escolhida = palavra_facil[indice];
        break;

        case 2:
        cout << "\nVoce selecionou o nivel: MEDIO\n";
        palavra_escolhida = palavra_medio[indice];
        break;

        case 3:
        cout << "\nVoce selecionou o nivel: DIFICIL\n";
        tentativas = 4;
        palavra_escolhida = palavra_dific[indice];
        break;

        default:
        cout << "\nNivel nao reconhecido. Falha no sistema!\n" << endl;
        cout << "Finalizando programa...\n" << endl;
        wait(700);
        exit(0);
        break;
    };
    
    //Copiando a palavra escolhida em outra variavel
    escolhida_final = palavra_escolhida;

    //Pegando o tamanho da palavra sorteada
    tamanho = palavra_escolhida.size();

    //Pequeno 'stand-by' para iniciar o jogo e limpando o console
    wait(1050);
    LimpaConsole();

    /**********************************************
                    LOGICA DO JOGO
    ***********************************************/
    while (tentativas > 0 && acertos < tamanho) {
        /* Para testes descomentar linha abaixo: */
        //cout << "Palavra escolhida: " << escolhida_final << endl;
        cout << "Tentativas: " << tentativas << endl;

        //Sempre desenhando o boneco e toda tentativa determina como está o boneco
        desenha_boneco(tentativas);
        cout << "Sua palavra: ";

        //Desenha os espaços para a palavra
        for (int i = 0; i < tamanho; i++) {
            cout << descobre_palavra[i] << " ";
        }
        cout << endl;
        
        cout << "\nDigite uma letra: ";
        cin >> letra;

        //Colocando a letra recebida em UpperCase para evitar erros
        letra = toupper(letra);

        //Logica para determinar um acerto e eliminar a letra acertada da palavra evitando erros
        for (int i = 0; i < tamanho; i++) {
            if (palavra_escolhida[i] == letra) {
                acerto = true;
                descobre_palavra[i] = palavra_escolhida[i];
                palavra_escolhida[i] = '-';
                acertos++;
            }
        }

        if (acerto == false) {
            tentativas--;
        }

        //'Zerando' a variavel para novas avaliações
        acerto = false;
        LimpaConsole();
    }
    
    /* Após acabar as tentativas ou os acertos igualarem ao tamanho da palavra(condição do while), ocorre a avaliação de vitória */
    if (tamanho == acertos) {
        cout << "PARABENS, voce acertou a palavra " << escolhida_final << " e nao sera enforcado...\n";
        wait(750);
        cout << "Nao dessa vez...\n";
    }
    else {
        desenha_boneco(tentativas);
        cout << "Sua palavra era: " << escolhida_final <<endl;
        cout << "Voce foi enforcado e perdeu, que pena...\n";
    }

    cout << "\nObrigado por jogar!" << endl;

    return 0;
}