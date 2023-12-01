//
// Created by manu on 18/12/21.
//

#include "trabalhadores.h"

trabalhadores::trabalhadores(){
    tipoTrabalhador = ' ';
}

char trabalhadores::gettipoTrabalhador(){
    return this->tipoTrabalhador;
}

void trabalhadores::setid(int num, int dia){
    this->id = to_string(num) + "." + to_string(dia);
}

string trabalhadores::getid(){
    return this->id;
}

void trabalhadores::setdespedimento(int num) {
    this->despedimento = num;
}

int trabalhadores::getdespedimento(){
    return this->despedimento;
}

void trabalhadores::setmoveu(bool num){
    this->moveu = num;
}

int trabalhadores::getmoveu(){
    return this->moveu;
}

mineiro::mineiro(int num, int dia){
    tipoTrabalhador = 'M';
    setid(num, dia);
    moveu = false;
}

trabalhadores * mineiro::duplica()const {
    return new mineiro(*this);
}

operario::operario(int num, int dia){
    tipoTrabalhador = 'O';
    setid(num, dia);
    moveu = false;
}

trabalhadores * operario::duplica()const {
    return new operario(*this);
}

lenhador::lenhador(int num, int dia){
    tipoTrabalhador = 'L';
    setid(num, dia);
    moveu = false;
}

trabalhadores * lenhador::duplica()const {
    return new lenhador(*this);
}

