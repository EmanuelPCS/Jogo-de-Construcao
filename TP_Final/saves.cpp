//
// Autores do Trabalho:
// Tânia Guedes    - 2020139445
// Emanuel Saraiva - 2019130219
//

#include "saves.h"
using namespace std;

string saves::getNomeSave(){
    return this->nomeSave;
}

saves::saves(string nome, ilhas &ilha) : nomeSave(nome), gIlhas(ilha) {

}

ilhas& saves::retorna(){
    return gIlhas;

}