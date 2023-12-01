//
// Created by manu on 18/12/21.
//

#ifndef TP_FINAL_TRABALHADORES_H
#define TP_FINAL_TRABALHADORES_H

#include <vector>
#include <string>
#include <string.h>

using namespace std;

class trabalhadores {
    public:
        trabalhadores();
        ~trabalhadores() = default;

    virtual trabalhadores * duplica()const = 0;

        char gettipoTrabalhador();

        void setid(int num, int dia);
        string getid();

        void setdespedimento(int num);
        int getdespedimento();

        void setmoveu(bool num);
        int getmoveu();


    protected:
        string id;
        char tipoTrabalhador;
        int despedimento;
        bool moveu;
};

class mineiro: public trabalhadores{
    public:
        mineiro(int num, int dia);

    trabalhadores * duplica()const override;

};

class operario: public trabalhadores{
    public:
        operario(int num, int dia);

    trabalhadores * duplica()const override;

};

class lenhador: public trabalhadores{
    public:
        lenhador(int num, int dia);

    trabalhadores * duplica()const override;

};


#endif //TP_FINAL_TRABALHADORES_H
