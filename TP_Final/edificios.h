//
// Created by manu on 15/12/21.
//

#ifndef TP_FINAL_EDIFICIOS_H
#define TP_FINAL_EDIFICIOS_H

#include <string>
using namespace std;

class edificios {
    public:
        string nomeEdificio;
        edificios();
        virtual edificios * duplica()const = 0;
       // ~edificios() = default;

        void setestado(bool num);
        bool getestado();

        //minaFerro
        virtual void setferro() {return;}
        virtual void setferroSemNivel(float num) {return;} // 1 + nivel //2kg
        virtual void setferroMontanha() {return;} // 1 + nivel //2kg
        virtual void setferroDeserto() {return;} // 1 + nivel //2kg


    virtual float getferro() { return 0;}

        virtual void setnivel(int n) {return;}
        virtual int getnivel() { return 0;}

        virtual int getprobDesabarF() { return 0;}
        virtual float getarmazenamentoF() { return 0;}


        //minaCarvão
        virtual void setcarvao() {return;}
        virtual void setcarvaoSemNivel(int num) { return; }
        virtual float getcarvao() { return 0;}

        virtual int getprobDesabarC() { return 0;}
        virtual float getarmazenamentoC() { return 0;}

        virtual void setcarvaoMontanha() {return;}
        virtual void setcarvaoDeserto() {return;}

        //centralElétrica
        virtual void setcarvaoCE()  { return;} // 1 + nivel
        virtual float getcarvaoCE()  { return 0; }
        virtual void setcarvaoCESemNivel(int num) { return; }


        virtual int geteletricidadeCE()  { return 0; }
        virtual float getarmazenamentoCarvaoCE()  { return 0; }

        virtual void setproduziu(bool est) { return; }
        //void fazIlha(int linhas, int colunas);

        virtual bool getproduziu() { return false; }


        //bateria
        virtual void seteletricidadeB(float e) { return ; }
        virtual float geteletricidadeB()  { return 0; }

        virtual int getarmazenamentoB()  { return 0; }


        //fundição
        virtual void setbarraAco(float num) { return; }
        virtual float getbarraAco() { return 0; } //-1.5kg ferro e -0.5kg carvao
        virtual int getarmazenamentoFun() { return 0; }


        float getcustoEdi(){
            return custoEdi;
        }

protected:
        bool estado;
        float custoEdi;
        int diaCons;
};

class minaFerro: public edificios{
    public:
        minaFerro(float custo, int dia);

        edificios * duplica()const override;

        void setferro() override; // 1 + nivel //2kg
        void setferroSemNivel(float num) override; // 1 + nivel //2kg
        void setferroMontanha() override; // 1 + nivel //2kg
        void setferroDeserto() override; // 1 + nivel //2kg

        float getferro() override;

        void setnivel(int n) override { nivel = n; }
        int getnivel() override { return nivel;}

        int getprobDesabarF() override { return 15; }
        float getarmazenamentoF() override { return 90 + (10 * nivel); }

    private:
        float ferro;
        int nivel;
};

class minaCarvao: public edificios{
    public:
        minaCarvao(float custo, int dia);

    edificios * duplica()const override;

        void setcarvao() override{ carvao = (carvao + 1 + nivel); } // 1 + nivel
        void setcarvaoSemNivel(int num) override{ carvao += num; }
        void setcarvaoMontanha() override{
            if(nivel == 1)
                carvao = carvao + 4;
            if(nivel == 2)
                carvao = carvao + 5;
            if(nivel == 3)
                carvao = carvao + 6;
            if(nivel == 4)
                carvao = carvao + 7;
            if(nivel == 5)
                carvao = carvao + 8;
        }
        void setcarvaoDeserto() override{
            if(nivel == 1)
                carvao = carvao + 1;
            if(nivel == 2)
                carvao = carvao + 2;
            if(nivel == 3)
                carvao = carvao + 3;
            if(nivel == 4)
                carvao = carvao + 4;
            if(nivel == 5)
                carvao = carvao + 5;
        }

        float getcarvao() override { return carvao; }

        void setnivel(int n) override { nivel = n; }
        int getnivel() override { return nivel;}

        int getprobDesabarC() override { return 10; }
        float getarmazenamentoC() override { return 90 + (10 * nivel); }

    private:
        float carvao;
        int nivel;
};

class centralEletrica: public edificios{
    public:
        centralEletrica(float custo, int dia);

    edificios * duplica()const override;

    //-1kg de madeira
    void setcarvaoCE() override { carvao = carvao + 1; }
    void setcarvaoCESemNivel(int num) override { carvao += num; }

    float getcarvaoCE() override { return carvao; }

    int geteletricidadeCE() override { return 1; }

    float getarmazenamentoCarvaoCE() override { return 100; }

    void setproduziu(bool est) override { produziu = est; }
    bool getproduziu() override { return produziu; }

    private:
        float carvao;
        bool produziu;
};

class bateria: public edificios{
    public:
        bateria(float custo, int dia);

    edificios * duplica()const override;

    void seteletricidadeB(float e) override { eletricidade = eletricidade + e ; }
    float geteletricidadeB() override { return eletricidade; }

    void setnivel(int n) override { nivel = n; }
    int getnivel() override { return nivel;}

    int getarmazenamentoB() override { return 90 + (10 * nivel); }

    private:
        float eletricidade;
        int nivel;
};

class fundicao: public edificios{
    public:
        fundicao(float custo, int dia);

    edificios * duplica()const override;

    void setbarraAco(float num) override { barraAco += num; }
    float getbarraAco() override { return 1; } //-1.5kg ferro e -0.5kg carvao

    int getarmazenamentoFun() override { return 100; }

    private:
        float barraAco;
};

class serracao: public edificios{
public:
    serracao(float custo, int dia);

    edificios * duplica()const override;

    //int getvigasM() { return 1; } //-1.5kg ferro e -0.5kg carvao
};

class edificioX: public edificios{
    public:
        edificioX(float custo, int dia);

    edificios * duplica()const override;

};



#endif //TP_FINAL_EDIFICIOS_H
