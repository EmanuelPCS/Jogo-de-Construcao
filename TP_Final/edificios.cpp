//
// Created by manu on 15/12/21.
//

#include "edificios.h"

edificios::edificios(){
    nomeEdificio = "    ";
    estado = false;
}

void edificios::setestado(bool num) {
    estado = num;
}

bool edificios::getestado() {
    return estado;
}

minaFerro::minaFerro(float custo, int dia){
    nomeEdificio = "mnF ";
    estado = false;
    ferro = 0;
    nivel = 1;
    custoEdi = custo;
    diaCons = dia;
}

edificios * minaFerro::duplica()const {
    return new minaFerro(*this);
}

void minaFerro::setferro(){
    ferro = (ferro + 1 + nivel);
}

void minaFerro::setferroSemNivel(float num) {
    ferro = (ferro + num);
}

void minaFerro::setferroMontanha() {
    if(nivel == 1)
        ferro = ferro + 4;
    if(nivel == 2)
        ferro = ferro + 5;
    if(nivel == 3)
        ferro = ferro + 6;
    if(nivel == 4)
        ferro = ferro + 7;
    if(nivel == 5)
        ferro = ferro + 8;
}

void minaFerro::setferroDeserto() {
    if(nivel == 1)
        ferro = ferro + 1;
    if(nivel == 2)
        ferro = ferro + 2;
    if(nivel == 3)
        ferro = ferro + 3;
    if(nivel == 4)
        ferro = ferro + 4;
    if(nivel == 5)
        ferro = ferro + 5;
}

float minaFerro::getferro(){
    return ferro;
}

minaCarvao::minaCarvao(float custo, int dia){
    nomeEdificio = "mnC ";
    estado = false;
    nivel = 1;
    carvao = 0;
    custoEdi = custo;
    diaCons = dia;
}

edificios * minaCarvao::duplica()const {
    return new minaCarvao(*this);
}

centralEletrica::centralEletrica(float custo, int dia){
    nomeEdificio = "elec";
    estado = false;
    produziu = false;
    carvao = 0;
    custoEdi = custo;
    diaCons = dia;
}

edificios * centralEletrica::duplica()const {
    return new centralEletrica(*this);
}

bateria::bateria(float custo, int dia){
    nomeEdificio = "bat ";
    estado = false;
    nivel = 1;
    eletricidade = 0;
    custoEdi = custo;
    diaCons = dia;
}

edificios * bateria::duplica()const {
    return new bateria(*this);
}

fundicao::fundicao(float custo, int dia){
    nomeEdificio = "fun ";
    estado = false;
    barraAco = 0;
    custoEdi = custo;
    diaCons = dia;
}

edificios * fundicao::duplica()const {
    return new fundicao(*this);
}

serracao::serracao(float custo, int dia){
    nomeEdificio = "ser ";
    estado = false;
    custoEdi = custo;
    diaCons = dia;
}

edificios * serracao::duplica()const {
    return new serracao(*this);
}

edificioX::edificioX(float custo, int dia){
    nomeEdificio = "banc";
    estado = false;
    custoEdi = custo;
    diaCons = dia;
}

edificios * edificioX::duplica()const {
    return new edificioX(*this);
}