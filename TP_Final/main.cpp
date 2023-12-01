//
// Autores do Trabalho:
// Tânia Guedes    - 2020139445
// Emanuel Saraiva - 2019130219
//

#include <iostream>
#include <sstream>
#include <string>/*
#include "zonas.h"
#include "ilhas.h"
#include "ficheiros.h"
#include "comandosTeclado.h"
#include "menu.h"*/
#include "interface.h"

using namespace std;

int main() {

    srand(time(nullptr)); // Deu warning com: srand(time(NULL)); e pediu para pôr nullptr.

    interface ini;
    ini.inicializaMain();

   /* int l,c;
    cout << "Linha: ";
    cin >> l;
    cout << "Coluna: ";
    cin >> c;
    ilhas ilha(l,c); // criacao do objeto ilha para o construtor

    ilha.desenhar_ilhas(l,c);*/

    //ilha.zona[2][2].tipoTrabalhadores = 'M';
    //ilha.desenhar_ilhas(l,c);

    /*ficheiros ficheiro;
    ficheiro.leFicheiro(l,c,"teste.txt",ilha);*/
    //ilha.desenhar_ilhas(l,c);
    /*comandosTeclado comando;
    comando.processaComandosTeclado(l,c,ilha);*/

    //ilha.desenhar_ilhas_atual(ilha);
    //int linhas = 4;
    //int colunas = 5;
    //zonas mapa; //zonas *z1 = new zonas();
    //mapa.fazIlha(linhas,colunas);

    return 0;
}
