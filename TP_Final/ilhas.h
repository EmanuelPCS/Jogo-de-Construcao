//
// Autores do Trabalho:
// Tânia Guedes    - 2020139445
// Emanuel Saraiva - 2019130219
//

#ifndef TP_FINAL_ILHAS_H
#define TP_FINAL_ILHAS_H

#include <iostream>
#include <wchar.h>
#include <cstdint>
#include <vector>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <array>
#include <random>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include "zonas.h"
using namespace std;

class ilhas {
    public:
        ilhas(int l, int c); //Construtor
        ~ilhas();
        ilhas(const ilhas &il);
        ilhas & operator=(const ilhas & il);


        int randomEntreDoisNumeros(int x, int y);
        string getAsString(int l, int c); //desenhar_ilhas

        void amanhecer(int l, int c, ilhas &ilha);

        void despedimento(int dia, int chanceDespedimentoLenhador, ilhas &ilha, int i, int j);

        void produzir(int l, int c, ilhas &ilha);

        void anoitecer(int l, int c, ilhas &ilha);

        int fimDoJogo(int l, int c);
        //void mostra_trabalhadores(int l, int c);
        //void desenhar_ilhas_atual(ilhas &ilha);

        void setdinheiro(float num);
        float getdinheiro();

        void setvigasMadeira(int num);
        int getvigasMadeira();

        float gettotalMadeira(){
            return totalMadeira;
        }
        float gettotalBarraAco(){
            return totalBarraAco;
        }
        float gettotalEletricidade(){
            return totalEletricidade;
        }
        float gettotalFerro(){
            return totalFerro;
        }
        float gettotalCarvao(){
            return totalCarvao;
        }


        float getcustoMinaF(){
            return custoMinaF;
        }
        float getcustoMinaC(){
            return custoMinaC;
        }
        float getcustoCentralEletrica(){
            return custoCentralEletrica;
        }
        float getcustoBateria(){
            return custoBateria;
        }
        float getcustoFundicao(){
            return custoFundicao;
        }
        float getcustoSerracao(){
            return custoSerracao;
        }
        float getcustoEdificioX(){
            return custoEdificioX;
        }

        void setcustoMinaF(float custo){
            custoMinaF = custo;
        }
        void setcustoMinaC(float custo){
            custoMinaC = custo;
        }
        void setcustoCentralEletrica(float custo){
            custoCentralEletrica = custo;
        }
        void setcustoBateria(float custo){
            custoBateria = custo;
        }
        void setcustoFundicao(float custo){
            custoFundicao = custo;
        }
        void setcustoSerracao(float custo){
            custoSerracao = custo;
        }
        void setcustoEdificioX(float custo){
            custoEdificioX = custo;
        }


        float getcustoTrabM(){
            return custoTrabM;
        }

        float getcustoTrabO(){
            return custoTrabO;
        }

        float getcustoTrabL(){
            return custoTrabL;
        }

        void setcustoTrabM(float custo){
            custoTrabM = custo;
        }

        void setcustoTrabO(float custo){
            custoTrabO = custo;
        }

        void setcustoTrabL(float custo){
            custoTrabL = custo;
        }

    //private:
        //zonas zona[8][16]; // em vez de ser uma matrix de carateres ou inteiros, é uma matriz de zonas.
                           // em que cada zona tem 4 coisas.
        zonas ***zona;
        int dia;
        int aux;
        int contaNumTra = 0;
        int linha;
        int coluna;
private:
    float dinheiro;
    int vigasMadeira;

    float totalMadeira;
    float totalBarraAco;
    float totalEletricidade;

    float totalFerro;
    float totalCarvao;

    float custoMinaF;
    float custoMinaC;
    float custoCentralEletrica;
    float custoBateria;
    float custoFundicao;
    float custoSerracao;
    float custoEdificioX;

    float custoTrabM;
    float custoTrabO;
    float custoTrabL;

};


#endif //TP_FINAL_ILHAS_H
