//
// Autores do Trabalho:
// Tânia Guedes    - 2020139445
// Emanuel Saraiva - 2019130219
//

#ifndef TP_FINAL_ZONAS_H
#define TP_FINAL_ZONAS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "trabalhadores.h"
#include "edificios.h"
using namespace std;

//Só assim é que a funcao consegue aceder a este array de zonas. (nem no public dava)
const string tipoZonas[6] = { "mnt ",
                              "dsr ", "pas ", "flr ", "pnt ", "Cid "};

class zonas {
    public:
        //string getAsString() const;
        //void fazIlha(int linhas, int colunas);

       /* string gettipozona(); // Função Declarada [é feita assim nos .h]
        string gettipoedificio();*/
      /* vector<char> gettipoTrabalhadores();
        vector<char> settipoTrabalhadores(char caracter, int pos);*/

        zonas(); //Construtor
        ~zonas(); //Destrutor

    virtual zonas * duplica()const = 0;

        void setTipo(string tipoZona);                      //Tipo de ZONA
        string getTipo();

       /* void setEdificio(string tipoEdificio);              //Tipo de EDIFICIO
        string getEdificio();*/
        edificios *edificio = nullptr; // C: struct edificio edi = malloc(sizeof(edificio));

        void copiaVector(vector<trabalhadores *> trabalhador);
        void copiaEdi(edificios* edificio);

        //vector<char> tipoTrabalhadores={' ', ' ', ' ', ' '}; // Tipo de TRABALHADOR
        vector<trabalhadores *> trabalhador;

        int gettotalTrabalhadores();
        void settotalTrabalhadores(int num);                 // Numero total de TRABALHADORES
       /* char tipoTrabalhadoresM;
        char tipoTrabalhadoresL;
        char tipoTrabalhadoresO;
        char tipoTrabalhadores[4];*/

        virtual void setarvores(int num){return;}
        virtual int getarvores() { return 0;}

        virtual void setmadeira(float num){return;}
        virtual float getmadeira() { return 0;}

        virtual void setferro(float num) {return;}
        virtual float getferro() { return 0;}

        virtual void setguardaDiaEdiConstruido(int diaIlha) {return;}
        virtual int getguardaDiaEdiConstruido() {return 0;}

    protected:
        string tipo;

        //string edificio;
        int totalTrabalhadores;
    /*const string tipoprivate[6] = { "mnt ",
                             "wsr ", "pas ", "flr ", "pnt ", "znZ "};
        const string edificioprivate[6] = { "mnF ",
                               "mnC ", "elec", "bat ", "fun ", "    "};*/

       // int totalTrabalhadoresprivate;
};

class deserto : public zonas {
    public:
        deserto();

    zonas* duplica()const override;
};

class pastagem : public zonas {
    public:
        pastagem();

    zonas* duplica()const override;

};

class floresta : public zonas {
    public:
        floresta();

    zonas* duplica()const override;

        void setarvores(int num) override;
        int getarvores() override;

        void setmadeira(float num) override;
        float getmadeira() override;

    private:
        float madeira;
        int arvores;
};

class montanha : public zonas {
    public:
        montanha();

    zonas* duplica()const override;

        void setferro(float num) override;
        float getferro() override;

    private:
        float ferro;
};

class pantano : public zonas {
    public:
        pantano();

    zonas* duplica()const override;

        void setguardaDiaEdiConstruido(int diaIlha) override;
        int getguardaDiaEdiConstruido() override;

    private:
        int guardaDiaEdiConstruido;
};

class zonaX : public zonas {
public:
    zonaX();

    zonas* duplica()const override;
    //~ZonaX();
};


#endif //TP_FINAL_ZONAS_H
