//
// Autores do Trabalho:
// Tânia Guedes    - 2020139445
// Emanuel Saraiva - 2019130219
//

#ifndef TP_FINAL_INTERFACE_H
#define TP_FINAL_INTERFACE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include "ilhas.h"
#include "saves.h"
using namespace std;

class interface {
    public:
        interface();
        ~interface();
        void inicializaMain();

    vector<saves> Saves;

    void guardaSaves(string nome, ilhas &ilha);
    void loadEstadoJogo(string nome, ilhas &ilha);


    private:
        int menu();

        void processaComandosTeclado(int l, int c, ilhas &ilha, int &flagNext);

        void leFicheiroConfig(int l, int c, const string &nomeFicheiro, ilhas &ilha);
        void extraiInfoFicheiroConfig(int l, int c, istringstream &iss, ilhas &ilha);

        void leFicheiro(int l, int c, const string &nomeFicheiro, ilhas &ilha);
        void processaComandosFicheiro(int &k,int l, int c, istringstream &iss, ilhas &ilha);
};


#endif //TP_FINAL_INTERFACE_H
