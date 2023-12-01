//
// Autores do Trabalho:
// Tânia Guedes    - 2020139445
// Emanuel Saraiva - 2019130219
//

#include "zonas.h"
#include "trabalhador.h"
#include <cstdlib>
#include <ctime>
#include <vector>
//string zonas::getAsString() const {}

//Construtor
zonas::zonas() {
    tipo = " ";
    //edificio = "    ";
    //tipoTrabalhadores;
    /*tipoTrabalhadoresM = ' ';
    tipoTrabalhadoresO = ' ';
    tipoTrabalhadoresL = ' ';*/
    totalTrabalhadores = 0;
}


void zonas::copiaVector(vector<trabalhadores *> trabalhador){

    trabalhador.clear(); // <- VER

    for(auto &op : trabalhador)
        trabalhador.push_back(op->duplica());
}

void zonas::copiaEdi(edificios* edificio){

    edificio->duplica();
}


zonas::~zonas() {
    delete edificio;
    //trabalhador.clear();

    /*for(auto trab : trabalhador)
        delete trab;*/
    for(trabalhadores * p: trabalhador)
        delete p;

}

/*
vector<char> zonas::settipoTrabalhadores(char caracter, int pos) {

    tipoTrabalhadores[pos] = caracter;
    cout << caracter;
}

vector<char> zonas::gettipoTrabalhadores(){
    return tipoTrabalhadores;
}*/

void zonas::setTipo(string tipoZona){
    this->tipo = tipoZona;
}

string zonas::getTipo(){
    return this->tipo;
}
/*
void zonas::setEdificio(string tipoEdificio){
    this->edificio = tipoEdificio;
}

string zonas::getEdificio(){
    return this->edificio;
}*/

void zonas::settotalTrabalhadores(int num){
    this->totalTrabalhadores = num;
}

int zonas::gettotalTrabalhadores(){

    return this->totalTrabalhadores;
}

deserto::deserto(){
    tipo = "dsr ";
    //edificio = "    ";
    //tipoTrabalhadores;
    totalTrabalhadores = 0;
}

zonas* deserto::duplica()const {
    //cout << "oi";
    return new deserto(*this);
}

pastagem::pastagem(){
    tipo = "pas ";
    //edificio = "    ";
    //tipoTrabalhadores;
    totalTrabalhadores = 0;
}

zonas* pastagem::duplica()const {
    //cout << "oi";
    return new pastagem(*this);
}

floresta::floresta(){
    tipo = "flr ";
    //edificio = "    ";
    //tipoTrabalhadores;
    totalTrabalhadores = 0;
    madeira = 0;
    arvores = rand()%(40-20 + 1) + 20;
}

zonas* floresta::duplica()const {
    //cout << "oi";
    return new floresta(*this);
}

void floresta::setarvores(int num) {
    arvores = arvores + num;
}

int floresta::getarvores() {
    return arvores;
}

void floresta::setmadeira(float num) {
    madeira = madeira + num;
}

float floresta::getmadeira() {
    return madeira;
}


montanha::montanha(){
    tipo = "mnt ";
    //edificio = "    ";
    //tipoTrabalhadores;
    totalTrabalhadores = 0;
    ferro = 0;
}

zonas* montanha::duplica()const {
    //cout << "oi";
    return new montanha(*this);
}

void montanha::setferro(float num) {
    ferro += num;
}

float montanha::getferro() {
    return ferro;
}

pantano::pantano(){
    tipo = "pnt ";
    //edificio = "    ";
    //tipoTrabalhadores;
    totalTrabalhadores = 0;
}

zonas* pantano::duplica()const {
    //cout << "oi";
    return new pantano(*this);
}

void pantano::setguardaDiaEdiConstruido(int diaIlha) {
    guardaDiaEdiConstruido = diaIlha;
}

int pantano::getguardaDiaEdiConstruido() {
    return guardaDiaEdiConstruido;
}

zonaX::zonaX(){
    tipo = "Cid ";
    //edificio = "    ";
    //tipoTrabalhadores;
    totalTrabalhadores = 0;
}

zonas* zonaX::duplica()const {
    //cout << "oi";
    return new zonaX(*this);
}

/*
//Função Criada [é feita assim nos .cpp]
string zonas::gettipozona(){
    return tipoprivate[rand() % 6];
}

string zonas::gettipoedificio(){
    return edificioprivate[rand() % 6];
}
*//*
char zonas::gettipotrabalhadores(){
    return trabalhadoresprivate[rand() % 3];
}*/
/*
int zonas::gettipototalTrabalhadores(){
    return totalTrabalhadores = rand() % 9 +1;
}*/
/*
void zonas::fazIlha(int linhas, int colunas){
    int var = 0, var1 = 1, cont = 0;
    int mais_cont = 0;

   /* zonas*** pZonas = new zonas**[linhas*4];
    for(int i = 0; i < linhas * 4; i++)
    {
        pZonas[i] = new zonas*[colunas*4];
        for(int j = 0; j < colunas *4; j++){
            pZonas[i][j] = nullptr;
        }
    }

    cout << "ZONA [" <<var1<<"]" << "-> " ;
    for (int g = 0; g < linhas * 4; g++) {
        for (int h = 0; h < colunas * 4; h++) {
            cout << pZonas[g][h];
            var++, cont++, mais_cont++;

            if (var == 4) {
                cout << ',';
                if(mais_cont==16 && var1 < linhas*colunas) {
                    cout << "\n" << "ZONA [" <<++var1<<"]" << "-> " ;
                    mais_cont = 0;
                }
                var = 0;
            }

            //cont = cont + 4;
            if (cont == 16) {
                // cout << cont << "\n";
                // cout <<"entrou "<< "\n";
                //cout << "\n";
                cont = 0;
            }//cout << cont;
        }

        /*if(var1 == 3){
            //cout  << "-------------------------" << "\n";
            for(int z=0; z<(5*colunas); z++)
                cout << '-';
            cout << "\n";
            var1 = -1;
        } var1++;*/
    //}

    //cout << linhas << endl;
    //cout << colunas;

    //delete
   /* for(int i = 0; i < linhas; i++)
    {
        for(int j =0; j < colunas; j++)
            delete pZonas[i][j];
        delete[] pZonas[i];
    }
    delete[] pZonas;*/
//}*/