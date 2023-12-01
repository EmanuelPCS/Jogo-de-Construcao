//
// Autores do Trabalho:
// Tânia Guedes    - 2020139445
// Emanuel Saraiva - 2019130219
//

#ifndef TP_FINAL_SAVES_H
#define TP_FINAL_SAVES_H
#include "ilhas.h"
#include <string>

class saves {
public:
    string getNomeSave();
    ilhas gIlhas;
    saves(string nome, ilhas &ilha);
    ilhas& retorna();

private:
    string nomeSave;
};


#endif //TP_FINAL_SAVES_H
