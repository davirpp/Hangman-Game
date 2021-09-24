#include <iostream>
#include <cstdlib>
#include <ctime>

/* MACROS PARA DEFINIR O S.O. */
#ifdef  _linux_
    #include <unistd.h>
    #define LIMPAR "clear"
    void wait(unsigned milissegundos) {
        usleep(milissegundos * 1000);
    }
    
#elif  _WIN32
    #include <windows.h>
    #define LIMPAR "cls"
    void wait(unsigned milissegundos) {
        Sleep(milissegundos);
    }
#endif

using namespace std;

/* CORPO DAS FUNÇÕES */
/**************************************/

void LimpaConsole() {
    system(LIMPAR);
}

/**************************************/

int numeroAleatorio(int menor, int maior) {
    return rand()%(maior-menor+1) + menor;
}

/**************************************/

int tela_inicial() {

    int nivel;
    cout << "\n****************************" << endl;
    cout << " BEM VINDO AO JOGO DA FORCA" << endl;
    cout << "****************************\n" << endl;

    cout << "Escolha um nivel para jogar\n";
    cout << "1 - FACIL \n2 - MEDIO \n3 - DIFICIL";
    cout << "\nNumero do nivel escolhido: ";
    cin >> nivel;

    return nivel;
}

/**************************************/

void desenha_boneco(int tentativas) {

    //Boneco padrao
    string topo = " ______\n/     |";
    static string cabeca = "|";  //Usando tipo static para quando a variavel ser alterada no switch, ela permanece
    static string corpo = "|";
    string perna = "|";

    //De acordo com as tentativas desenha o boneco com ou sem braço/perna
    switch (tentativas) {
        case 4:
            cabeca = "|     O";
            break;
        case 3:
            corpo = "|    /|";
            break;
        case 2:
            corpo = "|    /|\\";
            break;
        case 1:
            perna = "|    /";
            break;
        case 0:
            perna = "|    /\\";
            break;
    }

    //Após determinar o boneco, imprime na tela
    cout << topo << endl;
    cout << cabeca << endl;
    cout << corpo << endl;
    cout << perna << endl;
    cout << "|\n" << endl;
}