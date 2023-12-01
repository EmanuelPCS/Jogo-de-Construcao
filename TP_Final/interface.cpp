//
// Autores do Trabalho:
// Tânia Guedes    - 2020139445
// Emanuel Saraiva - 2019130219
//

#include <limits>
#include <ios>
#include "interface.h"

interface::interface() {}
interface::~interface() {}

void interface::inicializaMain(){
    int op;
    do{
        int l=3,c=3, flagNext = 0;
        op = menu();
        switch(op){
            case 1: {
                do {
                    cout << endl;
                    cout << "Defina as dimensões da Ilha: "<< endl;
                    cout << "Linhas (Mínimo: 3): ";
                    cin >> l;
                    cout << "Colunas (Mínimo: 3): ";
                    cin >> c;

                    if(l < 3 || l > 8 || c < 3 || c > 16){
                        cout << "Por favor introduza valores entre [3,8] para as linhas e [3,16] para as colunas!\n";
                    }
                } while (l < 3 || l > 8 || c < 3 || c > 16);

                ilhas ilha(l, c); //criacao do objeto ilha para o construtor
                //ilha.desenhar_ilhas(l,c);

               /* comandosTeclado comando;
                comando.processaComandosTeclado(l, c, ilha);*/
               do {
                   cout << endl;
                   cout << ilha.dia <<" Dia" << endl;
                   cout << "AMANHECER" << endl;
                   //amanhecer()
                   ilha.amanhecer(l,c,ilha);
                   if(ilha.fimDoJogo(l,c) == 0)
                       flagNext = 1;
                   cout << ilha.getAsString(l,c);
                   //sleep(3);

                   cout << "MEIO DIA" << endl;
                   processaComandosTeclado(l, c, ilha, flagNext); // meioDia()

                   if(flagNext!=1){
                        cout << "ANOITECER" << endl;
                        ilha.produzir(l,c,ilha);
                        ilha.anoitecer(l,c,ilha);
                       if(ilha.fimDoJogo(l,c) == 0)
                           flagNext = 1;
                   }
                   ilha.dia++;
                   ilha.aux++;
               }while (flagNext==0);
                 ilha.contaNumTra = 0;
                for(int i = 0; i < l; i++)
                {
                    for(int j =0; j < c; j++)
                        delete ilha.zona[i][j];
                    delete[] ilha.zona[i];
                }
                delete[] ilha.zona;

                break;
            }
            case 2:
                ilhas ilha(l, c);
                /*ficheiros ficheiro;
                ficheiro.leFicheiro(l,c,"teste.txt",ilha);*/
                leFicheiro(l,c,"teste.txt",ilha);

                for(int i = 0; i < l; i++)
                {
                    for(int j =0; j < c; j++)
                        delete ilha.zona[i][j];
                    delete[] ilha.zona[i];
                }
                delete[] ilha.zona;

                break;
        }
    }while(op != 3);
}

int interface::menu(){
    int opcao;

    do{
        cout << ("\n|-------------------------------|") << endl;
        cout << ("|                               |") << endl;
        cout << ("|   *** Menu principal ***      |") << endl;
        cout << ("| 1 - Jogar                     |") << endl;
        cout << ("| 2 - Ler comandos do Ficheiro  |") << endl;
        cout << ("| 3 - Terminar                  |") << endl;
        cout << ("|                               |") << endl;
        cout << ("|-------------------------------|") << endl;
        cout << "\nOpcao: ";
        cin >> opcao;

        if(opcao < 1 || opcao > 3){
            cout << "Por favor introduza um valor entre [1,3]!\n";
        }
    }while( opcao < 1 || opcao > 3);

    return opcao;
}

void interface::processaComandosTeclado(int l, int c, ilhas &ilha, int &flagNext) {
    string comando;
    int flagVectorEmpty;
    //--ilha.dia;
    //int k = 0;

    do {

        cout << ilha.getAsString(l, c);
        flagVectorEmpty = 0;
        cout << "-----------------//-------------//-----------------";
        cout << endl;
        cout << "[Dia]" << endl;
        cout << "Você esta no " << ilha.dia << "º dia" << endl;
        cout << endl;
        cout << "[Dinheiro]";
        cout << "\nVocê tem: " << ilha.getdinheiro() << " euros" << endl;
        cout << endl;
        cout << "[Vigas de Madeira]";
        cout << "\nVocê tem: " << ilha.getvigasMadeira() << " vigas de Madeira" << endl;
        cout << endl;
        cout << "[Edificios]" << endl;
        cout << "[ minaf | minac | central | bat | fund | banc ]" << endl;
        cout << endl;
        cout << "[Recursos]" << endl;
        cout << "[ ferro | aco | carvao | mad | viga | eletr ]" << endl;
        cout << endl;
        cout << "[Trabalhadores]" << endl;
        cout << "[ M | O | L ]" << endl;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                if (ilha.zona[i][j]->trabalhador.empty() == false) { //if(!ilha.zona[i][j]->trabalhador.empty())
                    for (int h = 0; h < ilha.zona[i][j]->trabalhador.size(); h++) {
                        cout << "Trabalhador '" << ilha.zona[i][j]->trabalhador[h]->gettipoTrabalhador()
                             << "' tem " << "ID: " << ilha.zona[i][j]->trabalhador[h]->getid() << endl;
                    }
                    flagVectorEmpty = 1;
                }
            }
        }
        if (flagVectorEmpty == 0)
            cout << "Não há trabalhadores na Ilha" << endl;
        cout << "-----------------//-------------//-----------------" << endl;

        cout << endl;


        cout << "Introduza o Comando: ";
        //cin.ignore();
        //cin.clear();
        //fflush(stdin);
        getline(cin >> ws, comando);
        //cin.clear();
        //cout << "Comando: "<< comando << endl;
        stringstream ss(comando);
        ss >> comando;

        if (comando == "exec") {
            string nomeFicheiro;
            ss >> nomeFicheiro;
            /*cout << "Introduza o nome do Ficheiro: ";
            cin >> nomeFicheiro;*/

            leFicheiro(l, c, nomeFicheiro, ilha);

            //cout << nomeFicheiro;
            // mundo.criaTerritorio(tipo, n);
        } else if (comando == "cons") {
            string tipo;
            int li = 0, co = 0, comoPagar;
/*
            cout << "Introduza o tipo de Edifio: ";
            cin >> tipo;
            // do {
            cout << "Introduza a linha: ";
            cin >> li;
            cout << "Introduza a coluna: ";
            cin >> co;*/
            if (ss.good()) {
                ss >> tipo;
                ss >> li;
                ss >> co;
            }

            /*    if((li < 1 || co < 1) && (li >= l || co >= c)){
                    cout << "Por favor introduza um valor entre [1" <<","<< c <<"] para ambos\n";
                }
            }while((li < 1 && co < 1) || (li > l || co > c));*/

            if (li > 0 && co > 0 && li <= l && co <= c) {
                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                    if (tipo == "minaf" && ilha.zona[li - 1][co - 1]->getTipo() != "mnt ") {
                        if (ilha.getdinheiro() >= ilha.getcustoMinaF() && ilha.getvigasMadeira() >= 10) {
                            cout << "Como quer pagar a construcao do edificio " << tipo << "?" << endl;
                            cout << "Introduza: " << endl;
                            cout << "1 -> Para pagar com Dinheiro" << endl;
                            cout << "2 -> Para pagar com Vigas de Madeira" << endl;
                            cout << "Resposta: ";
                            cin >> comoPagar;

                            if (comoPagar == 1) {
                                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                    ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                                    ilha.setdinheiro(-ilha.getcustoMinaF());
                                    cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                                } else
                                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                            } else if (comoPagar == 2) {
                                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                    ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                                    ilha.setvigasMadeira(-10);
                                    cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                                } else
                                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                            } else
                                cout << "Introduziu uma resposta inválida" << endl;
                        } else if (ilha.getdinheiro() >= ilha.getcustoMinaF()) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                                ilha.setdinheiro(-ilha.getcustoMinaF());
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else if (ilha.getvigasMadeira() >= 10) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                                ilha.setvigasMadeira(-10);
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout
                                    << "[ERRO]: Verifique se tem dinheiro ou vigas de madeira suficientes para construir o edificio "
                                    << tipo << endl;


                        /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                            ilha.zona[li - 1][co - 1]->edificio = new minaFerro();
                        else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                    } else if (tipo == "minac" && ilha.zona[li - 1][co - 1]->getTipo() != "mnt ") {
                        if (ilha.getdinheiro() >= ilha.getcustoMinaC() && ilha.getvigasMadeira() >= 10) {
                            cout << "Como quer pagar a construcao do edificio " << tipo << "?" << endl;
                            cout << "Introduza: " << endl;
                            cout << "1 -> Para pagar com Dinheiro" << endl;
                            cout << "2 -> Para pagar com Vigas de Madeira" << endl;
                            cout << "Resposta: ";
                            cin >> comoPagar;

                            if (comoPagar == 1) {
                                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                    ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(),
                                                                                         ilha.dia);
                                    ilha.setdinheiro(-ilha.getcustoMinaC());
                                    cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                                } else
                                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                            } else if (comoPagar == 2) {
                                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                    ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(),
                                                                                         ilha.dia);
                                    ilha.setvigasMadeira(-10);
                                    cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                                } else
                                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                            } else
                                cout << "Introduziu uma resposta inválida" << endl;
                        } else if (ilha.getdinheiro() >= ilha.getcustoMinaC()) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(), ilha.dia);
                                ilha.setdinheiro(-ilha.getcustoMinaC());
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else if (ilha.getvigasMadeira() >= 10) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(), ilha.dia);
                                ilha.setvigasMadeira(-10);
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout
                                    << "[ERRO]: Verifique se tem dinheiro ou vigas de madeira suficientes para construir o edificio "
                                    << tipo << endl;

                        /* if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                             ilha.zona[li - 1][co - 1]->edificio = new minaCarvao();
                         else
                             cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                    } else if (tipo == "central" && ilha.zona[li - 1][co - 1]->getTipo() != "mnt ") {
                        if (ilha.getdinheiro() >= ilha.getcustoCentralEletrica()) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new centralEletrica(
                                        ilha.getcustoCentralEletrica(), ilha.dia);
                                ilha.setdinheiro(-ilha.getcustoCentralEletrica());
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout << "[ERRO]: Não tem dinheiro suficiente para construir o edificio " << tipo << endl;

                        /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                            ilha.zona[li - 1][co - 1]->edificio = new centralEletrica();
                        else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                    } else if (tipo == "bat" && ilha.zona[li - 1][co - 1]->getTipo() != "mnt ") {
                        if (ilha.getdinheiro() >= ilha.getcustoBateria() && ilha.getvigasMadeira() >= 10) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new bateria(ilha.getcustoBateria(), ilha.dia);
                                ilha.setdinheiro(-ilha.getcustoBateria());
                                ilha.setvigasMadeira(-10);
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout
                                    << "[ERRO]: Verifique se tem dinheiro e vigas de madeira suficientes para construir o edificio "
                                    << tipo << endl;

                        /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                            ilha.zona[li - 1][co - 1]->edificio = new bateria();
                        else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                    } else if (tipo == "fund" && ilha.zona[li - 1][co - 1]->getTipo() != "mnt ") {
                        if (ilha.getdinheiro() >= ilha.getcustoFundicao()) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new fundicao(ilha.getcustoFundicao(), ilha.dia);
                                ilha.setdinheiro(-ilha.getcustoFundicao());
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout << "[ERRO]: Não tem dinheiro suficiente para construir o edificio " << tipo << endl;

                        /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                            ilha.zona[li - 1][co - 1]->edificio = new fundicao();
                        else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                    } else if (tipo == "serr" && ilha.zona[li - 1][co - 1]->getTipo() != "mnt ") {
                        if (ilha.getdinheiro() >= ilha.getcustoSerracao()) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new serracao(ilha.getcustoSerracao(), ilha.dia);
                                ilha.setdinheiro(-ilha.getcustoSerracao());
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout << "[ERRO]: Não tem dinheiro suficiente para construir o edificio " << tipo << endl;
                    } else if (tipo == "banc" ) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            ilha.zona[li - 1][co - 1]->edificio = new edificioX(ilha.getcustoEdificioX(), ilha.dia);
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else if (tipo == "minaf" && ilha.zona[li - 1][co - 1]->getTipo() == "mnt ") {
                        if (ilha.getdinheiro() >= (ilha.getcustoMinaF() * 2) && ilha.getvigasMadeira() >= 20) {
                            cout << "Como quer pagar a construcao do edificio " << tipo << "?" << endl;
                            cout << "Introduza: " << endl;
                            cout << "1 -> Para pagar com Dinheiro" << endl;
                            cout << "2 -> Para pagar com Vigas de Madeira" << endl;
                            cout << "Resposta: ";
                            cin >> comoPagar;

                            if (comoPagar == 1) {
                                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                    ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                                    ilha.setdinheiro(-(ilha.getcustoMinaF() * 2));
                                    cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                                } else
                                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                            } else if (comoPagar == 2) {
                                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                    ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                                    ilha.setvigasMadeira(-20);
                                    cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                                } else
                                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                            } else
                                cout << "Introduziu uma resposta inválida" << endl;
                        } else if (ilha.getdinheiro() >= (ilha.getcustoMinaF() * 2)) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                                ilha.setdinheiro(-(ilha.getcustoMinaF() * 2));
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else if (ilha.getvigasMadeira() >= 20) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                                ilha.setvigasMadeira(-20);
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout
                                    << "[ERRO]: Verifique se tem dinheiro ou vigas de madeira suficientes para construir o edificio "
                                    << tipo << endl;


                        /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                            ilha.zona[li - 1][co - 1]->edificio = new minaFerro();
                        else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                    } else if (tipo == "minac" && ilha.zona[li - 1][co - 1]->getTipo() == "mnt ") {
                        if (ilha.getdinheiro() >= (ilha.getcustoMinaC() * 2) && ilha.getvigasMadeira() >= 20) {
                            cout << "Como quer pagar a construcao do edificio " << tipo << "?" << endl;
                            cout << "Introduza: " << endl;
                            cout << "1 -> Para pagar com Dinheiro" << endl;
                            cout << "2 -> Para pagar com Vigas de Madeira" << endl;
                            cout << "Resposta: ";
                            cin >> comoPagar;

                            if (comoPagar == 1) {
                                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                    ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(),
                                                                                         ilha.dia);
                                    ilha.setdinheiro(-(ilha.getcustoMinaC() * 2));
                                    cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                                } else
                                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                            } else if (comoPagar == 2) {
                                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                    ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(),
                                                                                         ilha.dia);
                                    ilha.setvigasMadeira(-20);
                                    cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                                } else
                                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                            } else
                                cout << "Introduziu uma resposta inválida" << endl;
                        } else if (ilha.getdinheiro() >= (ilha.getcustoMinaC() * 2)) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(), ilha.dia);
                                ilha.setdinheiro(-(ilha.getcustoMinaC() * 2));
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else if (ilha.getvigasMadeira() >= 20) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(), ilha.dia);
                                ilha.setvigasMadeira(-20);
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout
                                    << "[ERRO]: Verifique se tem dinheiro ou vigas de madeira suficientes para construir o edificio "
                                    << tipo << endl;

                        /* if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                             ilha.zona[li - 1][co - 1]->edificio = new minaCarvao();
                         else
                             cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                    } else if (tipo == "central" && ilha.zona[li - 1][co - 1]->getTipo() == "mnt ") {
                        if (ilha.getdinheiro() >= (ilha.getcustoCentralEletrica() * 2)) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new centralEletrica(
                                        ilha.getcustoCentralEletrica(), ilha.dia);
                                ilha.setdinheiro(-(ilha.getcustoCentralEletrica() * 2));
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout << "[ERRO]: Não tem dinheiro suficiente para construir o edificio " << tipo << endl;

                        /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                            ilha.zona[li - 1][co - 1]->edificio = new centralEletrica();
                        else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                    } else if (tipo == "bat" && ilha.zona[li - 1][co - 1]->getTipo() == "mnt ") {
                        if (ilha.getdinheiro() >= (ilha.getcustoBateria() * 2) && ilha.getvigasMadeira() >= 20) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new bateria(ilha.getcustoBateria(), ilha.dia);
                                ilha.setdinheiro(-(ilha.getcustoBateria() * 2));
                                ilha.setvigasMadeira(-20);
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout
                                    << "[ERRO]: Verifique se tem dinheiro e vigas de madeira suficientes para construir o edificio "
                                    << tipo << endl;

                        /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                            ilha.zona[li - 1][co - 1]->edificio = new bateria();
                        else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                    } else if (tipo == "fund" && ilha.zona[li - 1][co - 1]->getTipo() == "mnt ") {
                        if (ilha.getdinheiro() >= (ilha.getcustoFundicao() * 2)) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new fundicao(ilha.getcustoFundicao(), ilha.dia);
                                ilha.setdinheiro(-(ilha.getcustoFundicao() * 2));
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout << "[ERRO]: Não tem dinheiro suficiente para construir o edificio " << tipo << endl;

                        /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                            ilha.zona[li - 1][co - 1]->edificio = new fundicao();
                        else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                    } else if (tipo == "serr" && ilha.zona[li - 1][co - 1]->getTipo() == "mnt ") {
                        if (ilha.getdinheiro() >= (ilha.getcustoSerracao() * 2)) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new serracao(ilha.getcustoSerracao(), ilha.dia);
                                ilha.setdinheiro(-(ilha.getcustoSerracao() * 2));
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout << "[ERRO]: Não tem dinheiro suficiente para construir o edificio " << tipo << endl;
                    } else if (tipo == "banc") {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            ilha.zona[li - 1][co - 1]->edificio = new edificioX(ilha.getcustoEdificioX(), ilha.dia);
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else
                        cout << "[ERRO]: O tipo de edificio '" << tipo << "' não existe." << endl;
                }else
                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
            } else
            cout << "[ERRO]: Verifique o comando" << endl;
            /*cout << tipo << endl;
            cout << l << endl;
            cout << c << endl;*/

        } else if (comando == "cont") {
            string tipo;
            int li, co, flag = 0;

            /*cout << "Introduza o tipo de Trabalhador que quer contratar: ";
            cin >> tipo;*/
            ss >> tipo;
            /* cout << "Linha: ";
             cin >> li;
             cout << "Coluna: ";
             cin >> co;*/

            /*if (tipo == "miner") {
                for(int i = 0; i < l; i++){
                    for(int j = 0; j < c; j++){
                        if(ilha.zona[i][j]->getTipo() == "pas " && flag == 0) {
                            flag = 1;
                            //for(int z = 0; z <= k; z++)
                            if (k <= 4) {
                                //guarda[k] = 'M';
                                ilha.zona[i][j]->tipoTrabalhadores[k] = 'M';
                                //       ilha.zona[i][j]->tipoTrabalhadoresM = 'M';
                                //strcpy(ilha.zona[i][j].tipoTrabalhadores,guarda);
                            }
                            // if(k>4)
                            // ilha.zona[i][j]->totalTrabalhadores = ++k;
                            ilha.zona[i][j]->settotalTrabalhadores(++k);
                        }
                    }
                }
            }

             if (tipo == "oper") {
                for(int i = 0; i < l; i++){
                    for(int j = 0; j < c; j++){
                        if(ilha.zona[i][j]->getTipo() == "pas " && flag == 0) {
                            flag = 1;
                            //for(int z = 0; z <= k; z++)
                            if (k <= 4) {
                                //guarda[k] = 'M';
                                ilha.zona[i][j]->tipoTrabalhadores[k] = 'O';
                                //       ilha.zona[i][j]->tipoTrabalhadoresO = 'O';
                                //strcpy(ilha.zona[i][j].tipoTrabalhadores,guarda);
                            }
                            // if(k>4)
                            // ilha.zona[i][j]->totalTrabalhadores = ++k;
                            ilha.zona[i][j]->settotalTrabalhadores(++k);
                        }
                    }
                }
            }

            if (tipo == "len") {
                for(int i = 0; i < l; i++){
                    for(int j = 0; j < c; j++){
                        if(ilha.zona[i][j]->getTipo() == "pas " && flag == 0) {
                            flag = 1;
                            //for(int z = 0; z <= k; z++)
                            if (k <= 4) {
                                //guarda[k] = 'M';
                                ilha.zona[i][j]->tipoTrabalhadores[k] = 'L';
                                //        ilha.zona[i][j]->tipoTrabalhadoresL = 'L';
                                //strcpy(ilha.zona[i][j].tipoTrabalhadores,guarda);
                            }
                            // if(k>4)
                            //    ilha.zona[i][j]->totalTrabalhadores = ++k;
                            ilha.zona[i][j]->settotalTrabalhadores(++k);
                        }
                    }
                }
            }*/
            /*
            if (tipo == "miner") {
                if(k == 0){
                    do{
                        li = ilha.randomEntreDoisNumeros(0, l - 1);
                        co = ilha.randomEntreDoisNumeros(0, l - 1);

                        if(ilha.zona[li][co]->getTipo() == "pas ") {
                            ilha.zona[li][co]->trabalhador.push_back(new mineiro());
                            for(int h = 0; h < ilha.zona[li][co]->trabalhador.size(); h++){
                                ilha.zona[li][co]->trabalhador[h]->setid(,ilha.dia);
                            }
                            ilha.zona[li][co]->settotalTrabalhadores(++k);
                            flag = 1;
                            break;
                        }
                    }while (!flag); // while(aux) -> (aux != 0) | while(!aux) -> (aux == 0)
                } else{
                    for(int i = 0; i < l; i++){
                        for(int j = 0; j < c; j++){
                            if(ilha.zona[i][j]->getTipo() == "pas " && ilha.zona[i][j]->gettotalTrabalhadores() != 0){
                               // if(k <= 4)
                                    ilha.zona[i][j]->trabalhador.push_back(new mineiro());
                                ilha.zona[i][j]->settotalTrabalhadores(++k);
                                break;
                            }
                        }
                    }
                }
            }

            else if (tipo == "oper") {
                if(k == 0){
                    do{
                        li = ilha.randomEntreDoisNumeros(0, l - 1);
                        co = ilha.randomEntreDoisNumeros(0, l - 1);

                        if(ilha.zona[li][co]->getTipo() == "pas "){
                            ilha.zona[li][co]->trabalhador.push_back(new operario());
                            ilha.zona[li][co]->settotalTrabalhadores(++k);
                            flag = 1;
                            break;
                        }
                    }while (!flag); // while(aux) -> (aux != 0) | while(!aux) -> (aux == 0)
                } else{
                    for(int i = 0; i < l; i++){
                        for(int j = 0; j < c; j++){
                            if(ilha.zona[i][j]->getTipo() == "pas " && ilha.zona[i][j]->gettotalTrabalhadores() != 0){
                                //if(k <= 4)
                                    ilha.zona[i][j]->trabalhador.push_back(new operario());
                                ilha.zona[i][j]->settotalTrabalhadores(++k);
                                break;
                            }
                        }
                    }
                }
            }

            else if (tipo == "len") {
                if(k == 0){
                    do{
                        li = ilha.randomEntreDoisNumeros(0, l - 1);
                        co = ilha.randomEntreDoisNumeros(0, l - 1);

                        if(ilha.zona[li][co]->getTipo() == "pas "){
                            ilha.zona[li][co]->trabalhador.push_back(new lenhador());
                            ilha.zona[li][co]->settotalTrabalhadores(++k);
                            flag = 1;
                            break;
                        }
                    }while (!flag); // while(aux) -> (aux != 0) | while(!aux) -> (aux == 0)
                } else{
                    for(int i = 0; i < l; i++){
                        for(int j = 0; j < c; j++){
                            if(ilha.zona[i][j]->getTipo() == "pas " && ilha.zona[i][j]->gettotalTrabalhadores() != 0){
                                //if (k <= 4)
                                    ilha.zona[i][j]->trabalhador.push_back(new lenhador());
                                ilha.zona[i][j]->settotalTrabalhadores(++k);
                                break;
                            }
                        }
                    }
                }
            }else
                cout << "[ERRO]: O tipo de trabalhador '" << tipo <<"' não existe." << endl;
                */

            if (tipo == "miner") {
                if (ilha.getdinheiro() >= ilha.getcustoTrabM()) {
                    for (int i = 0; i < l; i++) {
                        for (int j = 0; j < c; j++) {
                            if (ilha.zona[i][j]->getTipo() == "pas " && ilha.zona[i][j]->gettotalTrabalhadores() != 0) {
                                ilha.zona[i][j]->trabalhador.push_back(new mineiro(++ilha.contaNumTra, ilha.dia));
                                ilha.zona[i][j]->settotalTrabalhadores(ilha.zona[i][j]->gettotalTrabalhadores() + 1);
                                flag = 1;
                                ilha.setdinheiro(-ilha.getcustoTrabM());
                                break;
                            }
                        }
                        if (flag == 1) break;
                    }

                    if (flag == 0) {
                        do {
                            li = ilha.randomEntreDoisNumeros(0, l - 1);
                            co = ilha.randomEntreDoisNumeros(0, l - 1);

                            if (ilha.zona[li][co]->getTipo() == "pas ") {
                                ilha.zona[li][co]->trabalhador.push_back(new mineiro(++ilha.contaNumTra, ilha.dia));
                                ilha.zona[li][co]->settotalTrabalhadores(
                                        ilha.zona[li][co]->gettotalTrabalhadores() + 1);
                                flag = 1;
                                ilha.setdinheiro(-ilha.getcustoTrabM());
                                break;
                            }
                        } while (flag != 1); // !flag
                    }
                } else
                    cout << "Não tem dinheiro suficiente para contratar um Mineiro" << endl;
            } else if (tipo == "oper") {
                if (ilha.getdinheiro() >= ilha.getcustoTrabO()) {
                    for (int i = 0; i < l; i++) {
                        for (int j = 0; j < c; j++) {
                            if (ilha.zona[i][j]->getTipo() == "pas " && ilha.zona[i][j]->gettotalTrabalhadores() != 0) {
                                ilha.zona[i][j]->trabalhador.push_back(new operario(++ilha.contaNumTra, ilha.dia));
                                ilha.zona[i][j]->settotalTrabalhadores(ilha.zona[i][j]->gettotalTrabalhadores() + 1);
                                flag = 1;
                                ilha.setdinheiro(-ilha.getcustoTrabO());
                                break;
                            }
                        }
                        if (flag == 1) break;
                    }

                    if (flag == 0) {
                        do {
                            li = ilha.randomEntreDoisNumeros(0, l - 1);
                            co = ilha.randomEntreDoisNumeros(0, l - 1);

                            if (ilha.zona[li][co]->getTipo() == "pas ") {
                                ilha.zona[li][co]->trabalhador.push_back(new operario(++ilha.contaNumTra, ilha.dia));
                                ilha.zona[li][co]->settotalTrabalhadores(
                                        ilha.zona[li][co]->gettotalTrabalhadores() + 1);
                                flag = 1;
                                ilha.setdinheiro(-ilha.getcustoTrabO());
                                break;
                            }
                        } while (flag != 1); // !flag
                    }
                } else
                    cout << "Não tem dinheiro suficiente para contratar um Operario" << endl;
            } else if (tipo == "len") {
                if (ilha.getdinheiro() >= ilha.getcustoTrabL()) {
                    for (int i = 0; i < l; i++) {
                        for (int j = 0; j < c; j++) {
                            if (ilha.zona[i][j]->getTipo() == "pas " && ilha.zona[i][j]->gettotalTrabalhadores() != 0) {
                                ilha.zona[i][j]->trabalhador.push_back(new lenhador(++ilha.contaNumTra, ilha.dia));
                                ilha.zona[i][j]->settotalTrabalhadores(ilha.zona[i][j]->gettotalTrabalhadores() + 1);
                                flag = 1;
                                ilha.setdinheiro(-ilha.getcustoTrabL());
                                break;
                            }
                        }
                        if (flag == 1) break;
                    }

                    if (flag == 0) {
                        do {
                            li = ilha.randomEntreDoisNumeros(0, l - 1);
                            co = ilha.randomEntreDoisNumeros(0, l - 1);

                            if (ilha.zona[li][co]->getTipo() == "pas ") {
                                ilha.zona[li][co]->trabalhador.push_back(new lenhador(++ilha.contaNumTra, ilha.dia));
                                ilha.zona[li][co]->settotalTrabalhadores(
                                        ilha.zona[li][co]->gettotalTrabalhadores() + 1);
                                flag = 1;
                                ilha.setdinheiro(-ilha.getcustoTrabL());
                                break;
                            }
                        } while (flag != 1); // !flag
                    }
                } else
                    cout << "Não tem dinheiro suficiente para contratar um Lenhador" << endl;
            } else
                cout << "[ERRO]: O tipo de trabalhador '" << tipo << "' não existe." << endl;

        } else if (comando == "list") {
            int li = 324534, co = 324534;
            //char var;
            /*cout << "Pretende inserir linha e coluna? " << endl;
            cout << "Sim -> s" << endl;
            cout << "Não -> n" << endl;
            cout << "Resposta: ";
            cin >> var;
            if(var == 's' || var == 'S'){
                cout << "\nIntroduza a linha: ";
                cin >> li;
                cout << "Introduza a coluna: ";
                cin >> co;

                cout << "\nTipo da Zona: " << ilha.zona[li-1][co-1]->getTipo() << endl;
                cout << "Tipo de Edificio na zona ' "<< ilha.zona[li-1][co-1]->getTipo() <<"': " << ilha.zona[li-1][co-1]->edificio->nomeEdificio << endl;
                cout << "Numero de trabalhadores na zona ' "<< ilha.zona[li-1][co-1]->getTipo() <<"': " << ilha.zona[li-1][co-1]->gettotalTrabalhadores() << endl;
            }else{
                int numEdf = 0, numTrab = 0;
                for (int i = 0; i < l; i++) {
                    for (int j = 0; j < c; j++) {
                        if(ilha.zona[i][j]->edificio->nomeEdificio != "    ")
                            numEdf++;
                        numTrab += ilha.zona[i][j]->gettotalTrabalhadores();
                    }
                }
                cout << endl;
                cout << "Numero de zonas na ilha " << l*c << endl;
                cout << "Numero de edificios na ilha " << numEdf << endl;
                cout << "Numero de trabalhadores na ilha " << numTrab << endl;
            }*/
            /*cout << l << endl;
            cout << c << endl;*/

            ss >> li;
            ss >> co;
            //if(li && co){ // li != 0 && co != 0
            if (li > 0 && co > 0 && li <= l && co <= c) {
                cout << "\nTipo da Zona: " << ilha.zona[li - 1][co - 1]->getTipo() << endl;

                if(ilha.zona[li-1][co-1]->edificio != nullptr)
                    cout << "Tipo de Edificio na zona ' " << ilha.zona[li - 1][co - 1]->getTipo() << "': " << ilha.zona[li - 1][co - 1]->edificio->nomeEdificio << endl;
                else
                    cout << "[INFO]: Não há edificios nessa zona " << endl;

                cout << "Numero de trabalhadores na zona ' " << ilha.zona[li - 1][co - 1]->getTipo() << "': "
                     << ilha.zona[li - 1][co - 1]->gettotalTrabalhadores() << endl;
                //else
                //cout << "[ERRO]: Verifique as linhas e/ou colunas" << endl;
                //}
                // else {
            } else if (li == 324534 && co == 324534) {
                int numEdf = 0, numTrab = 0;
                for (int i = 0; i < l; i++) {
                    for (int j = 0; j < c; j++) {
                        if (ilha.zona[i][j]->edificio != nullptr)
                            numEdf++;
                        numTrab += ilha.zona[i][j]->gettotalTrabalhadores();
                    }
                }
                cout << endl;
                cout << "Numero de zonas na ilha " << l * c << endl;
                cout << "Numero de edificios na ilha " << numEdf << endl;
                cout << "Numero de trabalhadores na ilha " << numTrab << endl;
            } else {
                cout << "[ERRO]: Verifique se os valores das linhas/colunas são válidos" << endl;
                cout << "[NOTA]: Para ver as informações globais da Ilha utilize apenas a palavra list " << endl;
            }

        } else if (comando == "liga") {
            int li = 0, co = 0;

            ss >> li;
            ss >> co;

            if (li > 0 && co > 0 && li <= l && co <= c) {
                if (ilha.zona[li - 1][co - 1]->edificio != nullptr) {
                    if (ilha.zona[li - 1][co - 1]->edificio->getestado()) //(ilha.zona[li - 1][co - 1]->edificio->getestado() == true)
                        cout << "O Edificio '" << ilha.zona[li - 1][co - 1]->edificio->nomeEdificio
                             << "' já se encontra ligado" << endl;
                    else {
                        ilha.zona[li - 1][co - 1]->edificio->setestado(true);
                        cout << "O edificio '" << ilha.zona[li - 1][co - 1]->edificio->nomeEdificio << "' foi ligado"
                             << endl;
                    }
                } else
                    cout << "[ERRO]: Não há edificios nessa zona" << endl;
            } else
                cout << "[ERRO]: Verifique o comando" << endl;

        } else if (comando == "des") {
            int li = 0, co = 0;

            ss >> li;
            ss >> co;

            if (li > 0 && co > 0 && li <= l && co <= c) {
                if (ilha.zona[li - 1][co - 1]->edificio != nullptr) {
                    if (ilha.zona[li - 1][co - 1]->edificio->getestado() == false)
                        cout << "O Edificio '" << ilha.zona[li - 1][co - 1]->edificio->nomeEdificio
                             << "' já se encontra desligado" << endl;
                    else {
                        ilha.zona[li - 1][co - 1]->edificio->setestado(false);
                        cout << "O edificio '" << ilha.zona[li - 1][co - 1]->edificio->nomeEdificio << "' foi desligado"
                             << endl;
                    }
                } else
                    cout << "[ERRO]: Não há edificios nessa zona" << endl;
            } else
                cout << "[ERRO]: Verifique o comando" << endl;

        } else if (comando == "move") {
            //string nova;
            string id, guardaLetra, guardaId, guardaDia, NumTra;
            int li = 0, co = 0, guardaTotalTrab = 0, flag = 0, flagDoId = 0, NOVODIA;
            // string arr[2];
            //int cont = 0;

            if (ss.good()) {
                ss >> id;
                ss >> li;
                ss >> co;
            }
            /*for (int i = 0; i < l; i++) {
                for (int j = 0; j < c; j++) {
                    for (int h = 0; h < ilha.zona[i][j]->trabalhador.size(); h++) {
                        cout << "Trabalhador '" << ilha.zona[i][j]->trabalhador[h]->gettipoTrabalhador()
                             << "' tem " << "ID: " << ilha.zona[i][j]->trabalhador[h]->getid() << endl;
                    }
                }
            }*/

            if (li > 0 && co > 0 && li <= l && co <= c) {
                for (int i = 0; i < l; i++) {
                    for (int j = 0; j < c; j++) {

                        for (int h = 0; h < ilha.zona[i][j]->trabalhador.size(); h++) {

                            if (ilha.zona[i][j]->trabalhador[h]->getid() == id ) {
                                if (ilha.zona[i][j]->trabalhador[h]->getmoveu() == false) {
                                    flagDoId = 1;
                                    guardaLetra = ilha.zona[i][j]->trabalhador[h]->gettipoTrabalhador();
                                    guardaId = ilha.zona[i][j]->trabalhador[h]->getid();
                                    //ilha.zona[i][j]->trabalhador.erase(ilha.zona[i][j]->trabalhador.begin() + h);

                                    /*istringstream ss(guardaId);
                                    while(getline(ss, nova, '.')) {
                                        arr[cont++] = nova;
                                    }
                                    ilha.contaNumTra = stoi(arr[0]);
                                    ilha.dia = stoi(arr[1]);*/
                                    istringstream ss(guardaId);
                                    getline(ss, NumTra, '.');
                                    ilha.contaNumTra = stoi(NumTra);
                                    getline(ss, guardaDia);
                                    NOVODIA = stoi(guardaDia);
                                    if (guardaLetra == "M" && ((li - 1 != i) || (co - 1 != j))) {
                                        ilha.zona[i][j]->trabalhador.erase(ilha.zona[i][j]->trabalhador.begin() + h);
                                        ilha.zona[li - 1][co - 1]->trabalhador.push_back(
                                                new mineiro(ilha.contaNumTra, NOVODIA));

                                        for (int z = 0; z < ilha.zona[li - 1][co - 1]->trabalhador.size(); z++) {
                                            if (ilha.zona[li - 1][co - 1]->trabalhador[z]->getid() == id)
                                                ilha.zona[li - 1][co - 1]->trabalhador[z]->setmoveu(true);
                                        }

                                        ilha.zona[li - 1][co - 1]->settotalTrabalhadores(
                                                ilha.zona[li - 1][co - 1]->gettotalTrabalhadores() + 1);
                                        ilha.zona[i][j]->settotalTrabalhadores(
                                                ilha.zona[i][j]->gettotalTrabalhadores() - 1);
                                        cout << "Trabalhador '" << guardaLetra << "' foi movido com sucesso" << endl;
                                        flag = 1;
                                        break;
                                    } else if (guardaLetra == "O" && ((li - 1 != i) || (co - 1 != j))) {
                                        ilha.zona[i][j]->trabalhador.erase(ilha.zona[i][j]->trabalhador.begin() + h);
                                        ilha.zona[li - 1][co - 1]->trabalhador.push_back(
                                                new operario(ilha.contaNumTra, NOVODIA));

                                        for (int z = 0; z < ilha.zona[li - 1][co - 1]->trabalhador.size(); z++) {
                                            if (ilha.zona[li - 1][co - 1]->trabalhador[z]->getid() == id)
                                                ilha.zona[li - 1][co - 1]->trabalhador[z]->setmoveu(true);
                                        }

                                        ilha.zona[li - 1][co - 1]->settotalTrabalhadores(
                                                ilha.zona[li - 1][co - 1]->gettotalTrabalhadores() + 1);
                                        ilha.zona[i][j]->settotalTrabalhadores(
                                                ilha.zona[i][j]->gettotalTrabalhadores() - 1);
                                        cout << "Trabalhador '" << guardaLetra << "' foi movido com sucesso" << endl;
                                        flag = 1;
                                        break;
                                    } else if (guardaLetra == "L" && ((li - 1 != i) || (co - 1 != j))) {
                                        ilha.zona[i][j]->trabalhador.erase(ilha.zona[i][j]->trabalhador.begin() + h);
                                        ilha.zona[li - 1][co - 1]->trabalhador.push_back(
                                                new lenhador(ilha.contaNumTra, NOVODIA));

                                        for (int z = 0; z < ilha.zona[li - 1][co - 1]->trabalhador.size(); z++) {
                                            if (ilha.zona[li - 1][co - 1]->trabalhador[z]->getid() == id)
                                                ilha.zona[li - 1][co - 1]->trabalhador[z]->setmoveu(true);
                                        }

                                        ilha.zona[li - 1][co - 1]->settotalTrabalhadores(
                                                ilha.zona[li - 1][co - 1]->gettotalTrabalhadores() + 1);
                                        ilha.zona[i][j]->settotalTrabalhadores(
                                                ilha.zona[i][j]->gettotalTrabalhadores() - 1);
                                        cout << "Trabalhador '" << guardaLetra << "' foi movido com sucesso" << endl;
                                        flag = 1;
                                        break;
                                    } else {
                                        flag = 1;
                                        cout << "O trabalhador '" << guardaLetra << "' já se encontra nessa posicao"
                                             << endl;
                                         }
                                    break;
                                } else {
                                    flag = 1;
                                cout << "O trabalhador já foi movido" << endl;
                                }
                            }
                            /* if(ilha.zona[i][j]->trabalhador[h]->getmoveu() == true) {
                                 flagDoId = 1;
                                 cout << "O trabalhador já foi movido" << endl;
                             }*/

                        }
                        if (flag == 1) break;

                    }
                    if (flag == 1) break;
                }
                if (flag == 0)
                    cout << "[ERRO]: O Trabalhador com id '" << id << "' não existe" << endl;
                //if(flagDoId == 0)
                //  cout << "Verifique o ID do Trabalhador que quer mudar" << endl;
            } else
                cout << "[ERRO]: Verifique o comando" << endl;

        } else if (comando == "vende") {
            string parametro1, parametro2, tipo;
            int li = 0, co = 0, contParametro1 = 0, contParametro2 = 0;
            float quantidade, quant;

            bool varAux = true, varAux2 = true;

            if (ss.good()) {
                ss >> parametro1;
                ss >> parametro2;
            }

            if (parametro1 != "" && parametro2 != "") {

                for (int i = 0; parametro1[i] != '\0'; i++) {
                    if (!isdigit(parametro1[i]))
                        varAux = false;
                }
                for (int i = 0; parametro2[i] != '\0'; i++) {
                    if (!isdigit(parametro2[i]))
                        varAux2 = false;
                }/*
                for (int z = 0; z < parametro1.size(); z++) {
                    if (isdigit(parametro1[z]))
                        contParametro1++;
                }

                for (int l = 0; l < parametro2.size(); l++) {
                    if (isdigit(parametro2[l]))
                        contParametro2++;
                }*/

                if (varAux2 == true) {

                    if (varAux != true) {

                        tipo = parametro1;
                        quant = stoi(parametro2);
                        quantidade = quant;

                        if (quant > 0) {

                            if (tipo == "ferro") {

                                if (ilha.gettotalFerro() >= quantidade) {
                                    for (int i = 0; i < l && quantidade != 0; i++) {
                                        for (int j = 0; j < c && quantidade != 0; j++) {

                                            if(ilha.zona[i][j]->edificio != nullptr) {
                                                if (ilha.zona[i][j]->edificio->getferro() > 0) {

                                                    if (ilha.zona[i][j]->edificio->getferro() >= quantidade) {
                                                        ilha.zona[i][j]->edificio->setferroSemNivel(-quantidade);
                                                        quantidade = 0;
                                                    } else {
                                                        quantidade -= ilha.zona[i][j]->edificio->getferro();
                                                        ilha.zona[i][j]->edificio->setferroSemNivel(
                                                                -ilha.zona[i][j]->edificio->getferro());
                                                    }

                                                    if (ilha.zona[i][j]->getferro() > 0 && quantidade != 0) {

                                                        if (ilha.zona[i][j]->getferro() >= quantidade) {
                                                            ilha.zona[i][j]->setferro(-quantidade);
                                                            quantidade = 0;
                                                        } else {
                                                            quantidade -= ilha.zona[i][j]->edificio->getferro();
                                                            ilha.zona[i][j]->setferro(-ilha.zona[i][j]->getferro());
                                                        }

                                                    }

                                                }
                                            }
                                        }
                                    }
                                    ilha.setdinheiro(quant * 1);

                                    cout << "O Ferro foi vendido com sucesso" << endl;
                                    cout << "Ganhou " << quant * 1 << " euros" << endl;

                                } else
                                    cout << "[ERRO]: Não tem a quantidade suficiente para vender Ferro" << endl;

                            } else if (tipo == "aco") {
                                if (ilha.gettotalBarraAco() >= quantidade) {
                                    for (int i = 0; i < l && quantidade != 0; i++) {
                                        for (int j = 0; j < c && quantidade != 0; j++) {
                                            if (ilha.zona[i][j]->edificio != nullptr) {
                                                if (ilha.zona[i][j]->edificio->getbarraAco() > 0) {

                                                    if (ilha.zona[i][j]->edificio->getbarraAco() >= quantidade) {
                                                        ilha.zona[i][j]->edificio->setbarraAco(-quantidade);
                                                        quantidade = 0;
                                                    } else {
                                                        quantidade -= ilha.zona[i][j]->edificio->getbarraAco();
                                                        ilha.zona[i][j]->edificio->setferroSemNivel(
                                                                -ilha.zona[i][j]->edificio->getbarraAco());
                                                    }

                                                }
                                            }
                                        }
                                    }
                                    ilha.setdinheiro(quant * 2);

                                    cout << "As Barras de Aço foram vendidas com sucesso" << endl;
                                    cout << "Ganhou " << quant * 2 << " euros" << endl;

                                } else
                                    cout << "[ERRO]: Não tem a quantidade suficiente para vender Barras de Aço" << endl;

                            } else if (tipo == "carvao") {
                                if (ilha.gettotalCarvao() >= quantidade) {
                                    for (int i = 0; i < l && quantidade != 0; i++) {
                                        for (int j = 0; j < c && quantidade != 0; j++) {
                                            if (ilha.zona[i][j]->edificio != nullptr) {
                                                if (ilha.zona[i][j]->edificio->nomeEdificio == "mnC ") {
                                                    if (ilha.zona[i][j]->edificio->getcarvao() > 0) {

                                                        if (ilha.zona[i][j]->edificio->getcarvao() >= quantidade) {
                                                            ilha.zona[i][j]->edificio->setcarvaoSemNivel(-quantidade);
                                                            quantidade = 0;
                                                        } else {
                                                            quantidade -= ilha.zona[i][j]->edificio->getcarvao();
                                                            ilha.zona[i][j]->edificio->setcarvaoSemNivel(
                                                                    -ilha.zona[i][j]->edificio->getcarvao());
                                                        }

                                                    }
                                                } else if (ilha.zona[i][j]->edificio->nomeEdificio == "elec") {
                                                    if (ilha.zona[i][j]->edificio->getcarvaoCE() > 0) {

                                                        if (ilha.zona[i][j]->edificio->getcarvaoCE() >= quantidade) {
                                                            ilha.zona[i][j]->edificio->setcarvaoCESemNivel(-quantidade);
                                                            quantidade = 0;
                                                        } else {
                                                            quantidade -= ilha.zona[i][j]->edificio->getcarvaoCE();
                                                            ilha.zona[i][j]->edificio->setcarvaoCESemNivel(
                                                                    -ilha.zona[i][j]->edificio->getcarvaoCE());
                                                        }

                                                    }
                                                }
                                            }
                                        }
                                    }
                                    ilha.setdinheiro(quant * 1);

                                    cout << "O Carvão foi vendido com sucesso" << endl;
                                    cout << "Ganhou " << quant * 1 << " euros" << endl;

                                } else
                                    cout << "[ERRO]: Não tem a quantidade suficiente para vender Carvão" << endl;

                            } else if (tipo == "mad") {
                                cout << ilha.gettotalMadeira() << endl;
                                if (ilha.gettotalMadeira() >= quantidade) {
                                    for (int i = 0; i < l && quantidade != 0; i++) {
                                        for (int j = 0; j < c && quantidade != 0; j++) {

                                            if (ilha.zona[i][j]->getmadeira() > 0) {

                                                if (ilha.zona[i][j]->getmadeira() >= quantidade) {
                                                    ilha.zona[i][j]->setmadeira(-quantidade);
                                                    quantidade = 0;
                                                } else {
                                                    quantidade -= ilha.zona[i][j]->getmadeira();
                                                    ilha.zona[i][j]->setmadeira(-ilha.zona[i][j]->getmadeira());
                                                }

                                            }

                                        }
                                    }
                                    ilha.setdinheiro(quant * 1);

                                    cout << "A Madeira foi vendida com sucesso" << endl;
                                    cout << "Ganhou " << quant * 1 << " euros" << endl;

                                } else
                                    cout << "[ERRO]: Não tem a quantidade suficiente para vender Madeira" << endl;

                            } else if (tipo == "viga") {
                                if (ilha.getvigasMadeira() >= quantidade) {

                                    ilha.setvigasMadeira(-quant);
                                    ilha.setdinheiro(quant * 2);

                                    cout << "As Vigas de Madeira foram vendidas com sucesso" << endl;
                                    cout << "Ganhou " << quant * 2 << " euros" << endl;

                                } else
                                    cout << "[ERRO]: Não tem a quantidade suficiente para vender Vigas de Madeira" << endl;

                            } else if (tipo == "eletr") {
                                if (ilha.gettotalEletricidade() >= quantidade) {
                                    for (int i = 0; i < l && quantidade != 0; i++) {
                                        for (int j = 0; j < c && quantidade != 0; j++) {
                                            if(ilha.zona[i][j]->edificio != nullptr) {
                                                if (ilha.zona[i][j]->edificio->geteletricidadeB() > 0) {

                                                    if (ilha.zona[i][j]->edificio->geteletricidadeB() >= quantidade) {
                                                        ilha.zona[i][j]->edificio->seteletricidadeB(-quantidade);
                                                        quantidade = 0;
                                                    } else {
                                                        quantidade -= ilha.zona[i][j]->edificio->geteletricidadeB();
                                                        ilha.zona[i][j]->edificio->seteletricidadeB(
                                                                -ilha.zona[i][j]->edificio->geteletricidadeB());
                                                    }

                                                }
                                            }
                                        }
                                    }
                                    ilha.setdinheiro(quant * 1.5);

                                    cout << "A Eletricidade foi vendida com sucesso" << endl;
                                    cout << "Ganhou " << quant * 1.5 << " euros" << endl;
                                } else
                                    cout << "[ERRO]: Não tem a quantidade suficiente para vender Eletricidade" << endl;

                            } else
                                cout << "[ERRO]: O Recurso " << tipo << " não existe" << endl;
                        } else
                            cout << "[ERRO]: Introduza uma quantidade válida" << endl;

                    } else {                                     //VENDE 2

                        li = stoi(parametro1);
                        co = stoi(parametro2);

                        if (li > 0 && co > 0 && li <= l && co <= c) {

                            if (ilha.zona[li-1][co-1]->edificio != nullptr) {
                                ilha.setdinheiro(ilha.zona[li-1][co-1]->edificio->getcustoEdi());
                                cout << "O edificio " << ilha.zona[li-1][co-1]->edificio->nomeEdificio << " foi vendido por " << ilha.zona[li - 1][co - 1]->edificio->getcustoEdi() << endl;

                                delete ilha.zona[li-1][co-1]->edificio;
                                ilha.zona[li-1][co-1]->edificio = nullptr;

                            } else
                                cout << "[ERRO]: Esta zona nao possui nenhum edificio" << endl;

                        } else
                            cout << "[ERRO]: Verifique se introduziu uma linha/coluna válida" << endl;

                    }

                } else
                    cout << "[ERRO]: Verifique o comando" << endl;
            }else
                cout << "[ERRO]: Verifique o comando" << endl;

        }else if (comando == "aumentanivel") {
            int li = 0, co = 0;
            if (ss.good()) {
                ss >> li;
                ss >> co;
            }

            if(li > 0 && co > 0) {
                if(li <= l && co <= c) {

                    if(ilha.zona[li-1][co-1]->edificio != nullptr) {

                        if (ilha.zona[li-1][co-1]->edificio->getnivel() > 0 && ilha.zona[li - 1][co - 1]->edificio->getnivel() < 5) {

                            if (ilha.zona[li-1][co-1]->edificio->nomeEdificio == "mnF ") {

                                if (ilha.getdinheiro() >= 15 && ilha.getvigasMadeira() >= 1) {
                                    ilha.zona[li-1][co-1]->edificio->setnivel(ilha.zona[li-1][co-1]->edificio->getnivel() + 1);
                                    ilha.setvigasMadeira(-1);
                                    ilha.setdinheiro(-15);
                                    cout << "O edificio mnF foi melhorado para o nivel " << ilha.zona[li-1][co-1]->edificio->getnivel() << endl;

                                } else {
                                        cout << "[ERRO]: O jogador nao possui recursos suficientes para aumentar de nivel o edificio mnF" << endl;
                                        cout << "[ERRO]: Precisa de 15 euros e 1 viga de madeira" << endl;
                                }
                            } else if (ilha.zona[li-1][co-1]->edificio->nomeEdificio == "mnC ") {

                                if (ilha.getdinheiro() >= 10 && ilha.getvigasMadeira() >= 1) {
                                    ilha.zona[li- 1][co- 1]->edificio->setnivel(ilha.zona[li-1][co-1]->edificio->getnivel() + 1);
                                    ilha.setdinheiro(-10);
                                    ilha.setvigasMadeira(-1);
                                    cout << "O edificio mnC foi melhorado para o nivel " << ilha.zona[li-1][co-1]->edificio->getnivel() << endl;

                                } else{
                                    cout << "[ERRO]: O jogador nao possui recursos suficientes para aumentar de nivel o edificio mnC" << endl;
                                    cout << "[ERRO]: Precisa de 15 euros e 1 viga de madeira" << endl;
                                }
                            } else if (ilha.zona[li-1][co-1]->edificio->nomeEdificio == "bat ") {

                                if (ilha.getdinheiro() >= 5) {
                                    ilha.zona[li-1][co-1]->edificio->setnivel(ilha.zona[li-1][co-1]->edificio->getnivel() + 1);
                                    ilha.setdinheiro(-5);
                                    cout << "O edificio bat foi melhorado para o nivel "<< ilha.zona[li-1][co-1]->edificio->getnivel() << endl;

                                } else{
                                    cout << "[ERRO]: O jogador nao possui recursos suficientes para aumentar de nivel o edificio mnC" << endl;
                                    cout << "[ERRO]: Precisa de 15 euros e 1 viga de madeira" << endl;
                                }

                            }
                        } else
                            cout << "[ERRO]: Este edificio não pode ser melhorado" << endl;
                    } else
                        cout << "[ERRO]: Não há edificios nessa zona" << endl;
                } else
                    cout << "[ERRO]: Introduziu uma linha/coluna errada" << endl;
            } else
                cout << "[ERRO]: Verifique o comando" << endl;

        }else if (comando == "next") {

        } else if (comando == "save") {
            string nome;
            ss >> nome;

            if(nome != "") {
                guardaSaves(nome, ilha);
                cout << "O estado do jogo foi salvo com sucesso" << endl;
            }
            else
                cout << "[ERRO]: Introduza um nome para salvar o estado do jogo" << endl;

        } else if (comando == "load") {
            string nome;
            int flag = -1;

            ss >> nome;

            if(nome != ""){

                for(int i = 0; i < Saves.size(); i++) {
                    if(Saves[i].getNomeSave() == nome)
                        flag = i;
                }

                if(flag != -1)//Encontrou um estado do jogo com aquele nome
                    loadEstadoJogo(nome, ilha);
                else
                    cout << "[ERRO]: Nenhum estado do jogo foi guardado com esse nome" << endl;

            } else
                cout << "[ERRO]: Introduza um nome valido para recuperar o estado do jogo" << endl;

        } else if (comando == "apaga") {
            string nome;
            int flag = -1;

            ss >> nome;

            if(nome != ""){
                for(int i = 0; i < Saves.size(); i++) {
                    if(Saves[i].getNomeSave() == nome)
                        flag = i;
                }

                if(flag != -1) //Encontrou um estado do jogo com aquele nome
                    Saves.erase(Saves.begin() + flag);
                else
                    cout << "[ERRO]: Nenhum estado do jogo foi guardado com esse nome" << endl;

            } else
                cout << "[ERRO]: Introduza um nome valido para recuperar o estado do jogo" << endl;

        } else if (comando == "config") {
            string nomeFicheiro;
            ss >> nomeFicheiro;

            leFicheiroConfig(l,c,nomeFicheiro,ilha);
        } else if (comando == "debcash") {
            int dinheiro = 0;

            if(ss.good())
                ss >> dinheiro;

            if(dinheiro != 0) {
                if (dinheiro > 0) {
                    //cout << "\nVocê tem: " << ilha.getdinheiro() << " euros" << endl;
                    ilha.setdinheiro(dinheiro);
                    cout << "Foi depositado a quantia de " << dinheiro << " euros na sua conta" << endl;
                    cout << "Ficou com: " << ilha.getdinheiro() << " euros" << endl;
                }else{
                    if (ilha.getdinheiro() + dinheiro >= 0) {
                        ilha.setdinheiro(dinheiro);
                        cout << "Foi retirado a quantia de: " << -dinheiro << " euros da sua conta" << endl;
                        cout << "Ficou com: " << ilha.getdinheiro() << " euros" << endl;
                    } else
                        cout << "Não tem o montante necessario para retirar essa quantia de dinheiro" << endl;
                }
            }else
                cout << "[ERRO]: Verifique o comando" << endl;
        }else if (comando == "debvigas") {
            int vigasM = 0;

            if(ss.good())
                ss >> vigasM;

            if(vigasM != 0) {
                if (vigasM > 0) {
                    //cout << "\nVocê tem: " << ilha.getdinheiro() << " euros" << endl;
                    ilha.setvigasMadeira(vigasM);
                    cout << "Foram adicionadas " << vigasM << " vigas" << endl;
                    cout << "Ficou com: " << ilha.getvigasMadeira() << " vigas" << endl;
                }else{
                    if (ilha.getvigasMadeira() + vigasM >= 0) {
                        ilha.setvigasMadeira(vigasM);
                        cout << "Foram adicionadas " << -vigasM << " vigas" << endl;
                        cout << "Ficou com: " << ilha.getvigasMadeira() << " vigas" << endl;
                    } else
                        cout << "Não tem a quantidade necessaria para retirar essa porção de vigas" << endl;
                }
            }else
                cout << "[ERRO]: Verifique o comando" << endl;
        } else if (comando == "debed") {
            string tipo;
            int li = 0, co = 0;

            if (ss.good()){
                ss >> tipo;
                ss >> li;
                ss >> co;
            }

            if(li > 0 && co > 0 && li <= l && co <= c) {
                if (tipo == "minaf") {
                    if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                        ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);

                        if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                            ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                    }else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                } else if (tipo == "minac") {
                    if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                        ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(), ilha.dia);

                        if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                            ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                    }else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                } else if (tipo == "central") {
                    if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                        ilha.zona[li - 1][co - 1]->edificio = new centralEletrica(ilha.getcustoCentralEletrica(),
                                                                                  ilha.dia);
                        if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                            ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                    }else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                } else if (tipo == "bat") {
                    if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                        ilha.zona[li - 1][co - 1]->edificio = new bateria(ilha.getcustoBateria(), ilha.dia);

                        if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                            ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                    }else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                } else if (tipo == "fund") {
                    if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                        ilha.zona[li - 1][co - 1]->edificio = new fundicao(ilha.getcustoFundicao(), ilha.dia);

                        if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                            ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                    }else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                } else if (tipo == "banc") {
                    if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                        ilha.zona[li - 1][co - 1]->edificio = new edificioX(ilha.getcustoEdificioX(), ilha.dia);

                    }else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                } else
                    cout << "[ERRO]: O tipo de edificio '" << tipo << "' não existe." << endl;
            }else
                cout << "[ERRO]: Verifique o comando" << endl;

        } else if (comando == "debkill") {
            string id="0.0", guardaLetra;
            int flag = 0;

            if(ss.good())
                ss >> id;

           /* for (int i = 0; i < l; i++) {
                for (int j = 0; j < c; j++) {
                    for (int h = 0; h < ilha.zona[i][j]->trabalhador.size(); h++) {
                        cout << "Trabalhador '" << ilha.zona[i][j]->trabalhador[h]->gettipoTrabalhador()
                             << "' tem " << "ID: " << ilha.zona[i][j]->trabalhador[h]->getid() << endl;
                    }
                }
            }*/

            if(id != "0.0") {
                for (int i = 0; i < l; i++) {
                    for (int j = 0; j < c; j++) {

                        for (int h = 0; h < ilha.zona[i][j]->trabalhador.size(); h++) {

                            if (ilha.zona[i][j]->trabalhador[h]->getid() == id) {
                                guardaLetra = ilha.zona[i][j]->trabalhador[h]->gettipoTrabalhador();
                                ilha.zona[i][j]->trabalhador.erase(ilha.zona[i][j]->trabalhador.begin() + h);
                                ilha.zona[i][j]->settotalTrabalhadores(ilha.zona[i][j]->gettotalTrabalhadores() - 1);

                                cout << "Trabalhador '" << guardaLetra << "' foi removido com sucesso" << endl;
                                flag = 1;
                            }

                        }

                    }
                }

                if(flag == 0)
                    cout << "[ERRO]: Verifique o id" << endl;

            }else
                cout << "[ERRO]: Verifique o comando" << endl;

        }else if (comando == "fim") {
            cout << "Obrigado por ter jogado!" << endl;
            if(flagNext == 0)
                flagNext = 1;

        }else {
            cout << endl;
            cout << "Comando " << comando << " invalido!" << endl;
        }

        if(ilha.fimDoJogo(l,c) == 0) {
            flagNext = 1;
            comando = "fim";
        }


    }while(comando != "next" && comando != "fim");
}

void interface::leFicheiroConfig(int l, int c, const string &nomeFicheiro, ilhas &ilha) {
    string guardaInfoFicheiro;
    ifstream ficheiro;
    ficheiro.open(nomeFicheiro);
    int k = 0;
    cout << "A abrir o ficheiro " << nomeFicheiro << "..." << endl;

    if (ficheiro.is_open()) {
        //abriu com sucesso
        cout << "A processar o ficheiro..." << endl;

        while (getline(ficheiro, guardaInfoFicheiro)) {
            istringstream iss(guardaInfoFicheiro);
            extraiInfoFicheiroConfig(l, c, iss, ilha);
        }
        ficheiro.close();
    } else {
        //não foi possível abrir o ficheiro
        cout << "[ERRO]: Não foi possivel abrir o ficheiro " << nomeFicheiro << endl;
    }
}

void interface::extraiInfoFicheiroConfig(int l, int c, istringstream &iss, ilhas &ilha) {
    string comando;
    float custo = -1;

    getline(iss, comando);
    stringstream ss(comando);
    ss >> comando;

    if (comando == "miner") {
        ss >> custo;

        if(custo >= 0) {
            if(custo != ilha.getcustoTrabM()) {
                ilha.setcustoTrabM(custo);
                cout << "O custo de contratacao do Mineiro foi mudado para " << custo << " euros" << endl;
            } else
                cout << "[ERRO]: O Mineiro ja possui esse valor de contratacao" << endl;
        } else
            cout << "[ERRO]: Insira um valor maior do que zero" << endl;

    }else if (comando == "oper") {
        ss >> custo;

        if(custo >= 0) {
            if(custo != ilha.getcustoTrabO()) {
                ilha.setcustoTrabO(custo);
                cout << "O custo de contratacao do Operario foi mudado para " << custo << " euros" << endl;
            } else
                cout << "[ERRO]: O Operario ja possui esse valor de contratacao" << endl;
        } else
            cout << "[ERRO]: Insira um valor maior do que zero" << endl;

    }else if (comando == "len") {
        ss >> custo;

        if(custo >= 0) {
            if(custo != ilha.getcustoTrabL()) {
                ilha.setcustoTrabL(custo);
                cout << "O custo de contratacao do Lenhador foi mudado para " << custo << " euros" << endl;
            } else
                cout << "[ERRO]: O Lenhador ja possui esse valor de contratacao" << endl;
        } else
            cout << "[ERRO]: Insira um valor maior do que zero" << endl;

    }else if (comando == "minaf") {
        ss >> custo;

        if(custo >= 0) {
            if(custo != ilha.getcustoMinaF()) {

                ilha.setcustoMinaF(custo);
                cout << "O custo de construcao da Mina de Ferro foi mudado para " << custo << endl;
            } else
                cout << "[ERRO]: A Minha de Ferro ja possui esse valor de construcao!!!" << endl;
        } else
            cout << "[ERRO]: Insira um valor maior do que zero" << endl;

    }else if (comando == "minac") {
        if(custo >= 0) {
            if(custo != ilha.getcustoMinaC()) {

                ilha.setcustoMinaC(custo);
                cout << "O custo de construcao da Mina de Carvao foi mudado para " << custo << endl;
            } else
                cout << "[ERRO]: A Mina de Carvao ja possui esse valor de construcao!!!" << endl;
        } else
            cout << "[ERRO]: Insira um valor maior do que zero" << endl;

    }else if (comando == "central") {
        if(custo >= 0) {
            if(custo != ilha.getcustoCentralEletrica()) {

                ilha.setcustoCentralEletrica(custo);
                cout << "O custo de construcao da Central Eletrica foi mudado para " << custo << endl;
            } else
                cout << "[ERRO]: A Central Eletrica ja possui esse valor de construcao!!!" << endl;
        } else
            cout << "[ERRO]: Insira um valor maior do que zero" << endl;

    }else if (comando == "bat") {
        if(custo >= 0) {
            if(custo != ilha.getcustoBateria()) {

                ilha.setcustoBateria(custo);
                cout << "O custo de construcao da bateria foi mudado para " << custo << endl;
            } else
                cout << "[ERRO]: A Bateria ja possui esse valor de construcao!!!" << endl;
        } else
            cout << "[ERRO]: Insira um valor maior do que zero" << endl;

    }else if (comando == "fun") {
        if(custo >= 0) {
            if(custo != ilha.getcustoFundicao()) {

                ilha.setcustoFundicao(custo);
                cout << "O custo de construcao da Fundicao foi mudado para " << custo << endl;
            } else
                cout << "[ERRO]: A Fundicao ja possui esse valor de construcao!!!" << endl;
        } else
            cout << "[ERRO]: Insira um valor maior do que zero" << endl;

    }else if (comando == "serr") {
        if(custo >= 0) {
            if(custo != ilha.getcustoSerracao()) {

                ilha.setcustoSerracao(custo);
                cout << "O custo de construcao da Serracao foi mudado para " << custo << endl;
            } else
                cout << "[ERRO]: A Serracao ja possui esse valor de construcao!!!" << endl;
        } else
            cout << "[ERRO]: Insira um valor maior do que zero" << endl;

    }else if (comando == "banc") {
        if(custo >= 0) {
            if(custo != ilha.getcustoEdificioX()) {

                ilha.setcustoEdificioX(custo);
                cout << "O custo de construcao do Edificio X foi mudado para " << custo << endl;
            } else
                cout << "[ERRO]: O Edificio X ja possui esse valor de construcao!!!" << endl;
        } else
            cout << "[ERRO]: Insira um valor maior do que zero" << endl;

    }else {
        cout << "Comando " << comando << " invalido em ficheiro!" << endl;
    }
}

void interface::leFicheiro(int l, int c, const string &nomeFicheiro, ilhas &ilha) {
    string guardaInfoFicheiro;
    ifstream ficheiro;
    ficheiro.open(nomeFicheiro);
    int k = 0;
    cout << "A abrir o ficheiro " << nomeFicheiro << "..." << endl;

    if (ficheiro.is_open()) {
        //abriu com sucesso
        cout << "A processar o ficheiro..." << endl;

        while (getline(ficheiro, guardaInfoFicheiro)) {
            istringstream iss(guardaInfoFicheiro);
            processaComandosFicheiro(k,l, c, iss, ilha);
        }
        ficheiro.close();
    } else {
        //não foi possível abrir o ficheiro
        cout << "[ERRO]: Não foi possivel abrir o ficheiro " << nomeFicheiro << endl;
    }
}

void interface::processaComandosFicheiro(int &k, int l, int c, istringstream &iss, ilhas &ilha) {
    string comando;
    getline(iss, comando);
    stringstream ss(comando);
    ss >> comando;

    if (comando == "exec") {
        string nomeFicheiro;
        ss >> nomeFicheiro;
        /*cout << "Introduza o nome do Ficheiro: ";
        cin >> nomeFicheiro;*/

        leFicheiro(l, c, nomeFicheiro, ilha);
    } else if (comando == "cons") {
        cout << "\nCOMANDO ENCONTRADO -> [cons]" << endl;
        string tipo;
        int li = 0, co = 0, comoPagar;
/*
            cout << "Introduza o tipo de Edifio: ";
            cin >> tipo;
            // do {
            cout << "Introduza a linha: ";
            cin >> li;
            cout << "Introduza a coluna: ";
            cin >> co;*/
        if (ss.good()) {
            ss >> tipo;
            ss >> li;
            ss >> co;
        }

        /*    if((li < 1 || co < 1) && (li >= l || co >= c)){
                cout << "Por favor introduza um valor entre [1" <<","<< c <<"] para ambos\n";
            }
        }while((li < 1 && co < 1) || (li > l || co > c));*/

        if (li > 0 && co > 0 && li <= l && co <= c) {
            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                if (tipo == "minaf" && ilha.zona[li - 1][co - 1]->getTipo() != "mnt ") {
                    if (ilha.getdinheiro() >= ilha.getcustoMinaF() && ilha.getvigasMadeira() >= 10) {
                        cout << "Como quer pagar a construcao do edificio " << tipo << "?" << endl;
                        cout << "Introduza: " << endl;
                        cout << "1 -> Para pagar com Dinheiro" << endl;
                        cout << "2 -> Para pagar com Vigas de Madeira" << endl;
                        cout << "Resposta: ";
                        cin >> comoPagar;

                        if (comoPagar == 1) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                                ilha.setdinheiro(-ilha.getcustoMinaF());
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else if (comoPagar == 2) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                                ilha.setvigasMadeira(-10);
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout << "Introduziu uma resposta inválida" << endl;
                    } else if (ilha.getdinheiro() >= ilha.getcustoMinaF()) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                            ilha.setdinheiro(-ilha.getcustoMinaF());
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else if (ilha.getvigasMadeira() >= 10) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                            ilha.setvigasMadeira(-10);
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else
                        cout
                                << "[ERRO]: Verifique se tem dinheiro ou vigas de madeira suficientes para construir o edificio "
                                << tipo << endl;


                    /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                        ilha.zona[li - 1][co - 1]->edificio = new minaFerro();
                    else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                } else if (tipo == "minac" && ilha.zona[li - 1][co - 1]->getTipo() != "mnt ") {
                    if (ilha.getdinheiro() >= ilha.getcustoMinaC() && ilha.getvigasMadeira() >= 10) {
                        cout << "Como quer pagar a construcao do edificio " << tipo << "?" << endl;
                        cout << "Introduza: " << endl;
                        cout << "1 -> Para pagar com Dinheiro" << endl;
                        cout << "2 -> Para pagar com Vigas de Madeira" << endl;
                        cout << "Resposta: ";
                        cin >> comoPagar;

                        if (comoPagar == 1) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(),
                                                                                     ilha.dia);
                                ilha.setdinheiro(-ilha.getcustoMinaC());
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else if (comoPagar == 2) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(),
                                                                                     ilha.dia);
                                ilha.setvigasMadeira(-10);
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout << "Introduziu uma resposta inválida" << endl;
                    } else if (ilha.getdinheiro() >= ilha.getcustoMinaC()) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(), ilha.dia);
                            ilha.setdinheiro(-ilha.getcustoMinaC());
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else if (ilha.getvigasMadeira() >= 10) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(), ilha.dia);
                            ilha.setvigasMadeira(-10);
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else
                        cout
                                << "[ERRO]: Verifique se tem dinheiro ou vigas de madeira suficientes para construir o edificio "
                                << tipo << endl;

                    /* if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                         ilha.zona[li - 1][co - 1]->edificio = new minaCarvao();
                     else
                         cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                } else if (tipo == "central" && ilha.zona[li - 1][co - 1]->getTipo() != "mnt ") {
                    if (ilha.getdinheiro() >= ilha.getcustoCentralEletrica()) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new centralEletrica(
                                    ilha.getcustoCentralEletrica(), ilha.dia);
                            ilha.setdinheiro(-ilha.getcustoCentralEletrica());
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else
                        cout << "[ERRO]: Não tem dinheiro suficiente para construir o edificio " << tipo << endl;

                    /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                        ilha.zona[li - 1][co - 1]->edificio = new centralEletrica();
                    else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                } else if (tipo == "bat" && ilha.zona[li - 1][co - 1]->getTipo() != "mnt ") {
                    if (ilha.getdinheiro() >= ilha.getcustoBateria() && ilha.getvigasMadeira() >= 10) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new bateria(ilha.getcustoBateria(), ilha.dia);
                            ilha.setdinheiro(-ilha.getcustoBateria());
                            ilha.setvigasMadeira(-10);
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else
                        cout
                                << "[ERRO]: Verifique se tem dinheiro e vigas de madeira suficientes para construir o edificio "
                                << tipo << endl;

                    /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                        ilha.zona[li - 1][co - 1]->edificio = new bateria();
                    else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                } else if (tipo == "fund" && ilha.zona[li - 1][co - 1]->getTipo() != "mnt ") {
                    if (ilha.getdinheiro() >= ilha.getcustoFundicao()) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new fundicao(ilha.getcustoFundicao(), ilha.dia);
                            ilha.setdinheiro(-ilha.getcustoFundicao());
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else
                        cout << "[ERRO]: Não tem dinheiro suficiente para construir o edificio " << tipo << endl;

                    /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                        ilha.zona[li - 1][co - 1]->edificio = new fundicao();
                    else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                } else if (tipo == "serr" && ilha.zona[li - 1][co - 1]->getTipo() != "mnt ") {
                    if (ilha.getdinheiro() >= ilha.getcustoSerracao()) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new serracao(ilha.getcustoSerracao(), ilha.dia);
                            ilha.setdinheiro(-ilha.getcustoSerracao());
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else
                        cout << "[ERRO]: Não tem dinheiro suficiente para construir o edificio " << tipo << endl;
                } else if (tipo == "banc") {
                    if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                        ilha.zona[li - 1][co - 1]->edificio = new edificioX(ilha.getcustoEdificioX(), ilha.dia);
                    } else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                } else if (tipo == "minaf" && ilha.zona[li - 1][co - 1]->getTipo() == "mnt ") {
                    if (ilha.getdinheiro() >= (ilha.getcustoMinaF() * 2) && ilha.getvigasMadeira() >= 20) {
                        cout << "Como quer pagar a construcao do edificio " << tipo << "?" << endl;
                        cout << "Introduza: " << endl;
                        cout << "1 -> Para pagar com Dinheiro" << endl;
                        cout << "2 -> Para pagar com Vigas de Madeira" << endl;
                        cout << "Resposta: ";
                        cin >> comoPagar;

                        if (comoPagar == 1) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                                ilha.setdinheiro(-(ilha.getcustoMinaF() * 2));
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else if (comoPagar == 2) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                                ilha.setvigasMadeira(-20);
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout << "Introduziu uma resposta inválida" << endl;
                    } else if (ilha.getdinheiro() >= (ilha.getcustoMinaF() * 2)) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                            ilha.setdinheiro(-(ilha.getcustoMinaF() * 2));
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else if (ilha.getvigasMadeira() >= 20) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);
                            ilha.setvigasMadeira(-20);
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else
                        cout
                                << "[ERRO]: Verifique se tem dinheiro ou vigas de madeira suficientes para construir o edificio "
                                << tipo << endl;


                    /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                        ilha.zona[li - 1][co - 1]->edificio = new minaFerro();
                    else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                } else if (tipo == "minac" && ilha.zona[li - 1][co - 1]->getTipo() == "mnt ") {
                    if (ilha.getdinheiro() >= (ilha.getcustoMinaC() * 2) && ilha.getvigasMadeira() >= 20) {
                        cout << "Como quer pagar a construcao do edificio " << tipo << "?" << endl;
                        cout << "Introduza: " << endl;
                        cout << "1 -> Para pagar com Dinheiro" << endl;
                        cout << "2 -> Para pagar com Vigas de Madeira" << endl;
                        cout << "Resposta: ";
                        cin >> comoPagar;

                        if (comoPagar == 1) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(),
                                                                                     ilha.dia);
                                ilha.setdinheiro(-(ilha.getcustoMinaC() * 2));
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else if (comoPagar == 2) {
                            if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                                if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                    ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                                ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(),
                                                                                     ilha.dia);
                                ilha.setvigasMadeira(-20);
                                cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                            } else
                                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                        } else
                            cout << "Introduziu uma resposta inválida" << endl;
                    } else if (ilha.getdinheiro() >= (ilha.getcustoMinaC() * 2)) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(), ilha.dia);
                            ilha.setdinheiro(-(ilha.getcustoMinaC() * 2));
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else if (ilha.getvigasMadeira() >= 20) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(), ilha.dia);
                            ilha.setvigasMadeira(-20);
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else
                        cout
                                << "[ERRO]: Verifique se tem dinheiro ou vigas de madeira suficientes para construir o edificio "
                                << tipo << endl;

                    /* if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                         ilha.zona[li - 1][co - 1]->edificio = new minaCarvao();
                     else
                         cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                } else if (tipo == "central" && ilha.zona[li - 1][co - 1]->getTipo() == "mnt ") {
                    if (ilha.getdinheiro() >= (ilha.getcustoCentralEletrica() * 2)) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new centralEletrica(
                                    ilha.getcustoCentralEletrica(), ilha.dia);
                            ilha.setdinheiro(-(ilha.getcustoCentralEletrica() * 2));
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else
                        cout << "[ERRO]: Não tem dinheiro suficiente para construir o edificio " << tipo << endl;

                    /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                        ilha.zona[li - 1][co - 1]->edificio = new centralEletrica();
                    else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                } else if (tipo == "bat" && ilha.zona[li - 1][co - 1]->getTipo() == "mnt ") {
                    if (ilha.getdinheiro() >= (ilha.getcustoBateria() * 2) && ilha.getvigasMadeira() >= 20) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new bateria(ilha.getcustoBateria(), ilha.dia);
                            ilha.setdinheiro(-(ilha.getcustoBateria() * 2));
                            ilha.setvigasMadeira(-20);
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else
                        cout
                                << "[ERRO]: Verifique se tem dinheiro e vigas de madeira suficientes para construir o edificio "
                                << tipo << endl;

                    /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                        ilha.zona[li - 1][co - 1]->edificio = new bateria();
                    else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                } else if (tipo == "fund" && ilha.zona[li - 1][co - 1]->getTipo() == "mnt ") {
                    if (ilha.getdinheiro() >= (ilha.getcustoFundicao() * 2)) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new fundicao(ilha.getcustoFundicao(), ilha.dia);
                            ilha.setdinheiro(-(ilha.getcustoFundicao() * 2));
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else
                        cout << "[ERRO]: Não tem dinheiro suficiente para construir o edificio " << tipo << endl;

                    /*if (ilha.zona[li - 1][co - 1]->edificio->nomeEdificio == "    ")
                        ilha.zona[li - 1][co - 1]->edificio = new fundicao();
                    else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;*/
                } else if (tipo == "serr" && ilha.zona[li - 1][co - 1]->getTipo() == "mnt ") {
                    if (ilha.getdinheiro() >= (ilha.getcustoSerracao() * 2)) {
                        if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                            if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                                ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                            ilha.zona[li - 1][co - 1]->edificio = new serracao(ilha.getcustoSerracao(), ilha.dia);
                            ilha.setdinheiro(-(ilha.getcustoSerracao() * 2));
                            cout << "O edificio " << tipo << " foi adicionado com sucesso" << endl;
                        } else
                            cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                    } else
                        cout << "[ERRO]: Não tem dinheiro suficiente para construir o edificio " << tipo << endl;
                } else if (tipo == "banc") {
                    if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {

                        ilha.zona[li - 1][co - 1]->edificio = new edificioX(ilha.getcustoEdificioX(), ilha.dia);
                    } else
                        cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
                } else
                    cout << "[ERRO]: O tipo de edificio '" << tipo << "' não existe." << endl;
            }else
                cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
        } else
            cout << "[ERRO]: Verifique o comando" << endl;
        /*cout << tipo << endl;
        cout << l << endl;
        cout << c << endl;*/

        cout << ilha.getAsString(l,c);
    } else if (comando == "cont") {
        cout << "\nCOMANDO ENCONTRADO -> [cont]" << endl;
        string tipo;
        int li, co, flag = 0;

        ss >> tipo;

        if (tipo == "miner") {
            if (ilha.getdinheiro() >= ilha.getcustoTrabM()) {
                for (int i = 0; i < l; i++) {
                    for (int j = 0; j < c; j++) {
                        if (ilha.zona[i][j]->getTipo() == "pas " && ilha.zona[i][j]->gettotalTrabalhadores() != 0) {
                            ilha.zona[i][j]->trabalhador.push_back(new mineiro(++ilha.contaNumTra, ilha.dia));
                            ilha.zona[i][j]->settotalTrabalhadores(ilha.zona[i][j]->gettotalTrabalhadores() + 1);
                            flag = 1;
                            ilha.setdinheiro(-ilha.getcustoTrabM());
                            break;
                        }
                    }
                    if (flag == 1) break;
                }

                if (flag == 0) {
                    do {
                        li = ilha.randomEntreDoisNumeros(0, l - 1);
                        co = ilha.randomEntreDoisNumeros(0, l - 1);

                        if (ilha.zona[li][co]->getTipo() == "pas ") {
                            ilha.zona[li][co]->trabalhador.push_back(new mineiro(++ilha.contaNumTra, ilha.dia));
                            ilha.zona[li][co]->settotalTrabalhadores(
                                    ilha.zona[li][co]->gettotalTrabalhadores() + 1);
                            flag = 1;
                            ilha.setdinheiro(-ilha.getcustoTrabM());
                            break;
                        }
                    } while (flag != 1); // !flag
                }
            } else
                cout << "Não tem dinheiro suficiente para contratar um Mineiro" << endl;
        } else if (tipo == "oper") {
            if (ilha.getdinheiro() >= ilha.getcustoTrabO()) {
                for (int i = 0; i < l; i++) {
                    for (int j = 0; j < c; j++) {
                        if (ilha.zona[i][j]->getTipo() == "pas " && ilha.zona[i][j]->gettotalTrabalhadores() != 0) {
                            ilha.zona[i][j]->trabalhador.push_back(new operario(++ilha.contaNumTra, ilha.dia));
                            ilha.zona[i][j]->settotalTrabalhadores(ilha.zona[i][j]->gettotalTrabalhadores() + 1);
                            flag = 1;
                            ilha.setdinheiro(-ilha.getcustoTrabO());
                            break;
                        }
                    }
                    if (flag == 1) break;
                }

                if (flag == 0) {
                    do {
                        li = ilha.randomEntreDoisNumeros(0, l - 1);
                        co = ilha.randomEntreDoisNumeros(0, l - 1);

                        if (ilha.zona[li][co]->getTipo() == "pas ") {
                            ilha.zona[li][co]->trabalhador.push_back(new operario(++ilha.contaNumTra, ilha.dia));
                            ilha.zona[li][co]->settotalTrabalhadores(
                                    ilha.zona[li][co]->gettotalTrabalhadores() + 1);
                            flag = 1;
                            ilha.setdinheiro(-ilha.getcustoTrabO());
                            break;
                        }
                    } while (flag != 1); // !flag
                }
            } else
                cout << "Não tem dinheiro suficiente para contratar um Operario" << endl;
        } else if (tipo == "len") {
            if (ilha.getdinheiro() >= ilha.getcustoTrabL()) {
                for (int i = 0; i < l; i++) {
                    for (int j = 0; j < c; j++) {
                        if (ilha.zona[i][j]->getTipo() == "pas " && ilha.zona[i][j]->gettotalTrabalhadores() != 0) {
                            ilha.zona[i][j]->trabalhador.push_back(new lenhador(++ilha.contaNumTra, ilha.dia));
                            ilha.zona[i][j]->settotalTrabalhadores(ilha.zona[i][j]->gettotalTrabalhadores() + 1);
                            flag = 1;
                            ilha.setdinheiro(-ilha.getcustoTrabL());
                            break;
                        }
                    }
                    if (flag == 1) break;
                }

                if (flag == 0) {
                    do {
                        li = ilha.randomEntreDoisNumeros(0, l - 1);
                        co = ilha.randomEntreDoisNumeros(0, l - 1);

                        if (ilha.zona[li][co]->getTipo() == "pas ") {
                            ilha.zona[li][co]->trabalhador.push_back(new lenhador(++ilha.contaNumTra, ilha.dia));
                            ilha.zona[li][co]->settotalTrabalhadores(
                                    ilha.zona[li][co]->gettotalTrabalhadores() + 1);
                            flag = 1;
                            ilha.setdinheiro(-ilha.getcustoTrabL());
                            break;
                        }
                    } while (flag != 1); // !flag
                }
            } else
                cout << "Não tem dinheiro suficiente para contratar um Lenhador" << endl;
        } else
            cout << "[ERRO]: O tipo de trabalhador '" << tipo << "' não existe." << endl;

        cout << ilha.getAsString(l,c);
    } else if (comando == "list") {
        cout << "\nCOMANDO ENCONTRADO -> [list]" << endl;
        int li = 324534, co = 324534;

        ss >> li;
        ss >> co;
        //if(li && co){ // li != 0 && co != 0
        if (li > 0 && co > 0 && li <= l && co <= c) {
            cout << "\nTipo da Zona: " << ilha.zona[li - 1][co - 1]->getTipo() << endl;

            if(ilha.zona[li-1][co-1]->edificio != nullptr)
                cout << "Tipo de Edificio na zona ' " << ilha.zona[li - 1][co - 1]->getTipo() << "': " << ilha.zona[li - 1][co - 1]->edificio->nomeEdificio << endl;
            else
                cout << "[INFO]: Não há edificios nessa zona " << endl;

            cout << "Numero de trabalhadores na zona ' " << ilha.zona[li - 1][co - 1]->getTipo() << "': "
                 << ilha.zona[li - 1][co - 1]->gettotalTrabalhadores() << endl;
            //else
            //cout << "[ERRO]: Verifique as linhas e/ou colunas" << endl;
            //}
            // else {
        } else if (li == 324534 && co == 324534) {
            int numEdf = 0, numTrab = 0;
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < c; j++) {
                    if (ilha.zona[i][j]->edificio != nullptr)
                        numEdf++;
                    numTrab += ilha.zona[i][j]->gettotalTrabalhadores();
                }
            }
            cout << endl;
            cout << "Numero de zonas na ilha " << l * c << endl;
            cout << "Numero de edificios na ilha " << numEdf << endl;
            cout << "Numero de trabalhadores na ilha " << numTrab << endl;
        } else {
            cout << "[ERRO]: Verifique se os valores das linhas/colunas são válidos" << endl;
            cout << "[NOTA]: Para ver as informações globais da Ilha utilize apenas a palavra list " << endl;
        }

        cout << ilha.getAsString(l,c);
    }else if (comando == "liga") {
        cout << "COMANDO ENCONTRADO -> [liga]" << endl;
        int li = 0, co = 0;

        ss >> li;
        ss >> co;

        if (li > 0 && co > 0 && li <= l && co <= c) {
            if (ilha.zona[li - 1][co - 1]->edificio != nullptr) {
                if (ilha.zona[li - 1][co - 1]->edificio->getestado()) //(ilha.zona[li - 1][co - 1]->edificio->getestado() == true)
                    cout << "O Edificio '" << ilha.zona[li - 1][co - 1]->edificio->nomeEdificio
                         << "' já se encontra ligado" << endl;
                else {
                    ilha.zona[li - 1][co - 1]->edificio->setestado(true);
                    cout << "O edificio '" << ilha.zona[li - 1][co - 1]->edificio->nomeEdificio << "' foi ligado"
                         << endl;
                }
            } else
                cout << "[ERRO]: Não há edificios nessa zona" << endl;
        } else
            cout << "[ERRO]: Verifique o comando" << endl;

        cout << ilha.getAsString(l,c);
    }else if (comando == "des") {
        cout << "COMANDO ENCONTRADO -> [des]" << endl;
        int li = 0, co = 0;

        ss >> li;
        ss >> co;

        if (li > 0 && co > 0 && li <= l && co <= c) {
            if (ilha.zona[li - 1][co - 1]->edificio != nullptr) {
                if (ilha.zona[li - 1][co - 1]->edificio->getestado() == false)
                    cout << "O Edificio '" << ilha.zona[li - 1][co - 1]->edificio->nomeEdificio
                         << "' já se encontra desligado" << endl;
                else {
                    ilha.zona[li - 1][co - 1]->edificio->setestado(false);
                    cout << "O edificio '" << ilha.zona[li - 1][co - 1]->edificio->nomeEdificio << "' foi desligado"
                         << endl;
                }
            } else
                cout << "[ERRO]: Não há edificios nessa zona" << endl;
        } else
            cout << "[ERRO]: Verifique o comando" << endl;

        cout << ilha.getAsString(l,c);
    }else if (comando == "move") {
        cout << "COMANDO ENCONTRADO -> [move]" << endl;

        string id, guardaLetra, guardaId, guardaDia, NumTra;
        int li = 0, co = 0, guardaTotalTrab = 0, flag = 0, flagDoId = 0, NOVODIA;

        if (ss.good()) {
            ss >> id;
            ss >> li;
            ss >> co;
        }

        if (li > 0 && co > 0 && li <= l && co <= c) {
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < c; j++) {

                    for (int h = 0; h < ilha.zona[i][j]->trabalhador.size(); h++) {

                        if (ilha.zona[i][j]->trabalhador[h]->getid() == id &&
                            ilha.zona[i][j]->trabalhador[h]->getmoveu() == false) {
                            flagDoId = 1;
                            guardaLetra = ilha.zona[i][j]->trabalhador[h]->gettipoTrabalhador();
                            guardaId = ilha.zona[i][j]->trabalhador[h]->getid();
                            //ilha.zona[i][j]->trabalhador.erase(ilha.zona[i][j]->trabalhador.begin() + h);

                            /*istringstream ss(guardaId);
                            while(getline(ss, nova, '.')) {
                                arr[cont++] = nova;
                            }
                            ilha.contaNumTra = stoi(arr[0]);
                            ilha.dia = stoi(arr[1]);*/
                            istringstream ss(guardaId);
                            getline(ss, NumTra, '.');
                            ilha.contaNumTra = stoi(NumTra);
                            getline(ss, guardaDia);
                            NOVODIA = stoi(guardaDia);
                            if (guardaLetra == "M" && ((li - 1 != i) || (co - 1 != j))) {
                                ilha.zona[i][j]->trabalhador.erase(ilha.zona[i][j]->trabalhador.begin() + h);
                                ilha.zona[li - 1][co - 1]->trabalhador.push_back(new mineiro(ilha.contaNumTra, NOVODIA));

                                for (int z = 0; z < ilha.zona[li - 1][co - 1]->trabalhador.size(); z++) {
                                    if (ilha.zona[li - 1][co - 1]->trabalhador[z]->getid() == id)
                                        ilha.zona[li - 1][co - 1]->trabalhador[z]->setmoveu(true);
                                }

                                ilha.zona[li - 1][co - 1]->settotalTrabalhadores(
                                        ilha.zona[li - 1][co - 1]->gettotalTrabalhadores() + 1);
                                ilha.zona[i][j]->settotalTrabalhadores(
                                        ilha.zona[i][j]->gettotalTrabalhadores() - 1);
                                cout << "Trabalhador '" << guardaLetra << "' foi movido com sucesso" << endl;
                                flag = 1;
                                break;
                            } else if (guardaLetra == "O" && ((li - 1 != i) || (co - 1 != j))) {
                                ilha.zona[i][j]->trabalhador.erase(ilha.zona[i][j]->trabalhador.begin() + h);
                                ilha.zona[li - 1][co - 1]->trabalhador.push_back(new operario(ilha.contaNumTra, NOVODIA));

                                for (int z = 0; z < ilha.zona[li - 1][co - 1]->trabalhador.size(); z++) {
                                    if (ilha.zona[li - 1][co - 1]->trabalhador[z]->getid() == id)
                                        ilha.zona[li - 1][co - 1]->trabalhador[z]->setmoveu(true);
                                }

                                ilha.zona[li - 1][co - 1]->settotalTrabalhadores(
                                        ilha.zona[li - 1][co - 1]->gettotalTrabalhadores() + 1);
                                ilha.zona[i][j]->settotalTrabalhadores(
                                        ilha.zona[i][j]->gettotalTrabalhadores() - 1);
                                cout << "Trabalhador '" << guardaLetra << "' foi movido com sucesso" << endl;
                                flag = 1;
                                break;
                            } else if (guardaLetra == "L" && ((li - 1 != i) || (co - 1 != j))) {
                                ilha.zona[i][j]->trabalhador.erase(ilha.zona[i][j]->trabalhador.begin() + h);
                                ilha.zona[li - 1][co - 1]->trabalhador.push_back(new lenhador(ilha.contaNumTra, NOVODIA));

                                for (int z = 0; z < ilha.zona[li - 1][co - 1]->trabalhador.size(); z++) {
                                    if (ilha.zona[li - 1][co - 1]->trabalhador[z]->getid() == id)
                                        ilha.zona[li - 1][co - 1]->trabalhador[z]->setmoveu(true);
                                }

                                ilha.zona[li - 1][co - 1]->settotalTrabalhadores(
                                        ilha.zona[li - 1][co - 1]->gettotalTrabalhadores() + 1);
                                ilha.zona[i][j]->settotalTrabalhadores(
                                        ilha.zona[i][j]->gettotalTrabalhadores() - 1);
                                cout << "Trabalhador '" << guardaLetra << "' foi movido com sucesso" << endl;
                                flag = 1;
                                break;
                            } else
                                cout << "O trabalhador '" << guardaLetra << "' já se encontra nessa posicao"
                                     << endl;

                            break;
                        } else if (ilha.zona[i][j]->trabalhador[h]->getid() != id)
                            cout << "Verifique o ID do Trabalhador que quer mudar" << endl;
                        else if (ilha.zona[i][j]->trabalhador[h]->getmoveu() == true)
                            cout << "O trabalhador já foi movido" << endl;
                        /* if(ilha.zona[i][j]->trabalhador[h]->getmoveu() == true) {
                             flagDoId = 1;
                             cout << "O trabalhador já foi movido" << endl;
                         }*/

                    }
                    if (flag == 1) break;

                }
                if (flag == 1) break;
            }
            //if(flagDoId == 0)
            //  cout << "Verifique o ID do Trabalhador que quer mudar" << endl;
        } else
            cout << "[ERRO]: Verifique o comando" << endl;

        cout << ilha.getAsString(l,c);
    }else if (comando == "vende") {
        cout << "COMANDO ENCONTRADO -> [vende]" << endl;
        string parametro1, parametro2, tipo;
        int li = 0, co = 0, contParametro1 = 0, contParametro2 = 0;
        float quantidade, quant;

        bool varAux = true, varAux2 = true;

        if (ss.good()) {
            ss >> parametro1;
            ss >> parametro2;
        }

        if (parametro1 != "" && parametro2 != "") {

            for (int i = 0; parametro1[i] != '\0'; i++) {
                if (!isdigit(parametro1[i]))
                    varAux = false;
            }
            for (int i = 0; parametro2[i] != '\0'; i++) {
                if (!isdigit(parametro2[i]))
                    varAux2 = false;
            }/*
                for (int z = 0; z < parametro1.size(); z++) {
                    if (isdigit(parametro1[z]))
                        contParametro1++;
                }

                for (int l = 0; l < parametro2.size(); l++) {
                    if (isdigit(parametro2[l]))
                        contParametro2++;
                }*/

            if (varAux2 == true) {

                if (varAux != true) {

                    tipo = parametro1;
                    quant = stoi(parametro2);
                    quantidade = quant;

                    if (quant > 0) {

                        if (tipo == "ferro") {

                            if (ilha.gettotalFerro() >= quantidade) {
                                for (int i = 0; i < l && quantidade != 0; i++) {
                                    for (int j = 0; j < c && quantidade != 0; j++) {

                                        if(ilha.zona[i][j]->edificio != nullptr) {
                                            if (ilha.zona[i][j]->edificio->getferro() > 0) {

                                                if (ilha.zona[i][j]->edificio->getferro() >= quantidade) {
                                                    ilha.zona[i][j]->edificio->setferroSemNivel(-quantidade);
                                                    quantidade = 0;
                                                } else {
                                                    quantidade -= ilha.zona[i][j]->edificio->getferro();
                                                    ilha.zona[i][j]->edificio->setferroSemNivel(
                                                            -ilha.zona[i][j]->edificio->getferro());
                                                }

                                                if (ilha.zona[i][j]->getferro() > 0 && quantidade != 0) {

                                                    if (ilha.zona[i][j]->getferro() >= quantidade) {
                                                        ilha.zona[i][j]->setferro(-quantidade);
                                                        quantidade = 0;
                                                    } else {
                                                        quantidade -= ilha.zona[i][j]->edificio->getferro();
                                                        ilha.zona[i][j]->setferro(-ilha.zona[i][j]->getferro());
                                                    }

                                                }

                                            }
                                        }
                                    }
                                }
                                ilha.setdinheiro(quant * 1);

                                cout << "O Ferro foi vendido com sucesso" << endl;
                                cout << "Ganhou " << quant * 1 << " euros" << endl;

                            } else
                                cout << "[ERRO]: Não tem a quantidade suficiente para vender Ferro" << endl;

                        } else if (tipo == "aco") {
                            if (ilha.gettotalBarraAco() >= quantidade) {
                                for (int i = 0; i < l && quantidade != 0; i++) {
                                    for (int j = 0; j < c && quantidade != 0; j++) {
                                        if (ilha.zona[i][j]->edificio != nullptr) {
                                            if (ilha.zona[i][j]->edificio->getbarraAco() > 0) {

                                                if (ilha.zona[i][j]->edificio->getbarraAco() >= quantidade) {
                                                    ilha.zona[i][j]->edificio->setbarraAco(-quantidade);
                                                    quantidade = 0;
                                                } else {
                                                    quantidade -= ilha.zona[i][j]->edificio->getbarraAco();
                                                    ilha.zona[i][j]->edificio->setferroSemNivel(
                                                            -ilha.zona[i][j]->edificio->getbarraAco());
                                                }

                                            }
                                        }
                                    }
                                }
                                ilha.setdinheiro(quant * 2);

                                cout << "As Barras de Aço foram vendidas com sucesso" << endl;
                                cout << "Ganhou " << quant * 2 << " euros" << endl;

                            } else
                                cout << "[ERRO]: Não tem a quantidade suficiente para vender Barras de Aço" << endl;

                        } else if (tipo == "carvao") {
                            if (ilha.gettotalCarvao() >= quantidade) {
                                for (int i = 0; i < l && quantidade != 0; i++) {
                                    for (int j = 0; j < c && quantidade != 0; j++) {
                                        if (ilha.zona[i][j]->edificio != nullptr) {
                                            if (ilha.zona[i][j]->edificio->nomeEdificio == "mnC ") {
                                                if (ilha.zona[i][j]->edificio->getcarvao() > 0) {

                                                    if (ilha.zona[i][j]->edificio->getcarvao() >= quantidade) {
                                                        ilha.zona[i][j]->edificio->setcarvaoSemNivel(-quantidade);
                                                        quantidade = 0;
                                                    } else {
                                                        quantidade -= ilha.zona[i][j]->edificio->getcarvao();
                                                        ilha.zona[i][j]->edificio->setcarvaoSemNivel(
                                                                -ilha.zona[i][j]->edificio->getcarvao());
                                                    }

                                                }
                                            } else if (ilha.zona[i][j]->edificio->nomeEdificio == "elec") {
                                                if (ilha.zona[i][j]->edificio->getcarvaoCE() > 0) {

                                                    if (ilha.zona[i][j]->edificio->getcarvaoCE() >= quantidade) {
                                                        ilha.zona[i][j]->edificio->setcarvaoCESemNivel(-quantidade);
                                                        quantidade = 0;
                                                    } else {
                                                        quantidade -= ilha.zona[i][j]->edificio->getcarvaoCE();
                                                        ilha.zona[i][j]->edificio->setcarvaoCESemNivel(
                                                                -ilha.zona[i][j]->edificio->getcarvaoCE());
                                                    }

                                                }
                                            }
                                        }
                                    }
                                }
                                ilha.setdinheiro(quant * 1);

                                cout << "O Carvão foi vendido com sucesso" << endl;
                                cout << "Ganhou " << quant * 1 << " euros" << endl;

                            } else
                                cout << "[ERRO]: Não tem a quantidade suficiente para vender Carvão" << endl;

                        } else if (tipo == "mad") {
                            cout << ilha.gettotalMadeira() << endl;
                            if (ilha.gettotalMadeira() >= quantidade) {
                                for (int i = 0; i < l && quantidade != 0; i++) {
                                    for (int j = 0; j < c && quantidade != 0; j++) {

                                        if (ilha.zona[i][j]->getmadeira() > 0) {

                                            if (ilha.zona[i][j]->getmadeira() >= quantidade) {
                                                ilha.zona[i][j]->setmadeira(-quantidade);
                                                quantidade = 0;
                                            } else {
                                                quantidade -= ilha.zona[i][j]->getmadeira();
                                                ilha.zona[i][j]->setmadeira(-ilha.zona[i][j]->getmadeira());
                                            }

                                        }

                                    }
                                }
                                ilha.setdinheiro(quant * 1);

                                cout << "A Madeira foi vendida com sucesso" << endl;
                                cout << "Ganhou " << quant * 1 << " euros" << endl;

                            } else
                                cout << "[ERRO]: Não tem a quantidade suficiente para vender Madeira" << endl;

                        } else if (tipo == "viga") {
                            if (ilha.getvigasMadeira() >= quantidade) {

                                ilha.setvigasMadeira(-quant);
                                ilha.setdinheiro(quant * 2);

                                cout << "As Vigas de Madeira foram vendidas com sucesso" << endl;
                                cout << "Ganhou " << quant * 2 << " euros" << endl;

                            } else
                                cout << "[ERRO]: Não tem a quantidade suficiente para vender Vigas de Madeira" << endl;

                        } else if (tipo == "eletr") {
                            if (ilha.gettotalEletricidade() >= quantidade) {
                                for (int i = 0; i < l && quantidade != 0; i++) {
                                    for (int j = 0; j < c && quantidade != 0; j++) {
                                        if(ilha.zona[i][j]->edificio != nullptr) {
                                            if (ilha.zona[i][j]->edificio->geteletricidadeB() > 0) {

                                                if (ilha.zona[i][j]->edificio->geteletricidadeB() >= quantidade) {
                                                    ilha.zona[i][j]->edificio->seteletricidadeB(-quantidade);
                                                    quantidade = 0;
                                                } else {
                                                    quantidade -= ilha.zona[i][j]->edificio->geteletricidadeB();
                                                    ilha.zona[i][j]->edificio->seteletricidadeB(
                                                            -ilha.zona[i][j]->edificio->geteletricidadeB());
                                                }

                                            }
                                        }
                                    }
                                }
                                ilha.setdinheiro(quant * 1.5);

                                cout << "A Eletricidade foi vendida com sucesso" << endl;
                                cout << "Ganhou " << quant * 1.5 << " euros" << endl;
                            } else
                                cout << "[ERRO]: Não tem a quantidade suficiente para vender Eletricidade" << endl;

                        } else
                            cout << "[ERRO]: O Recurso " << tipo << " não existe" << endl;
                    } else
                        cout << "[ERRO]: Introduza uma quantidade válida" << endl;

                } else {                                     //VENDE 2

                    li = stoi(parametro1);
                    co = stoi(parametro2);

                    if (li > 0 && co > 0 && li <= l && co <= c) {

                        if (ilha.zona[li-1][co-1]->edificio != nullptr) {
                            ilha.setdinheiro(ilha.zona[li-1][co-1]->edificio->getcustoEdi());
                            cout << "O edificio " << ilha.zona[li-1][co-1]->edificio->nomeEdificio << " foi vendido por " << ilha.zona[li - 1][co - 1]->edificio->getcustoEdi() << endl;

                            delete ilha.zona[li-1][co-1]->edificio;
                            ilha.zona[li-1][co-1]->edificio = nullptr;

                        } else
                            cout << "[ERRO]: Esta zona nao possui nenhum edificio" << endl;

                    } else
                        cout << "[ERRO]: Verifique se introduziu uma linha/coluna válida" << endl;

                }

            } else
                cout << "[ERRO]: Verifique o comando" << endl;
        }else
            cout << "[ERRO]: Verifique o comando" << endl;

        cout << ilha.getAsString(l,c);
    }else if (comando == "next") {
        cout << "COMANDO ENCONTRADO -> [next]" << endl;
    }else if (comando == "save") {
        cout << "COMANDO ENCONTRADO -> [save]" << endl;
        string nome;
        ss >> nome;

        if(nome != "") {
            guardaSaves(nome, ilha);
            cout << "O estado do jogo foi salvo com sucesso" << endl;
        }
        else
            cout << "[ERRO]: Introduza um nome para salvar o estado do jogo" << endl;

    } else if (comando == "load") {
        cout << "COMANDO ENCONTRADO -> [load]" << endl;
        string nome;
        int flag = -1;

        ss >> nome;

        if(nome != ""){

            for(int i = 0; i < Saves.size(); i++) {
                if(Saves[i].getNomeSave() == nome)
                    flag = i;
            }

            if(flag != -1)//Encontrou um estado do jogo com aquele nome
                loadEstadoJogo(nome, ilha);
            else
                cout << "[ERRO]: Nenhum estado do jogo foi guardado com esse nome" << endl;

        } else
            cout << "[ERRO]: Introduza um nome valido para recuperar o estado do jogo" << endl;

    } else if (comando == "apaga") {
        cout << "COMANDO ENCONTRADO -> [apaga]" << endl;
        string nome;
        int flag = -1;

        ss >> nome;

        if(nome != ""){
            for(int i = 0; i < Saves.size(); i++) {
                if(Saves[i].getNomeSave() == nome)
                    flag = i;
            }

            if(flag != -1) //Encontrou um estado do jogo com aquele nome
                Saves.erase(Saves.begin() + flag);
            else
                cout << "[ERRO]: Nenhum estado do jogo foi guardado com esse nome" << endl;

        } else
            cout << "[ERRO]: Introduza um nome valido para recuperar o estado do jogo" << endl;

    }else if (comando == "config") {
        string nomeFicheiro;
        ss >> nomeFicheiro;

        leFicheiroConfig(l,c,nomeFicheiro,ilha);
    }else if (comando == "debcash") {
        cout << "COMANDO ENCONTRADO -> [debcash]" << endl;
        int dinheiro = 0;

        if(ss.good())
            ss >> dinheiro;

        if(dinheiro != 0) {
            if (dinheiro > 0) {
                //cout << "\nVocê tem: " << ilha.getdinheiro() << " euros" << endl;
                ilha.setdinheiro(dinheiro);
                cout << "Foi depositado a quantia de " << dinheiro << " euros na sua conta" << endl;
                cout << "Ficou com: " << ilha.getdinheiro() << " euros" << endl;
            }else{
                if (ilha.getdinheiro() + dinheiro >= 0) {
                    ilha.setdinheiro(dinheiro);
                    cout << "Foi retirado a quantia de: " << -dinheiro << " euros da sua conta" << endl;
                    cout << "Ficou com: " << ilha.getdinheiro() << " euros" << endl;
                } else
                    cout << "Não tem o montante necessario para retirar essa quantia de dinheiro" << endl;
            }
        }else
            cout << "[ERRO]: Verifique o comando" << endl;

        cout << ilha.getAsString(l,c);
    }else if (comando == "debed") {
        cout << "COMANDO ENCONTRADO -> [debed]" << endl;
        string tipo;
        int li = 0, co = 0;

        if (ss.good()){
            ss >> tipo;
            ss >> li;
            ss >> co;
        }

        if(li > 0 && co > 0 && li <= l && co <= c) {
            if (tipo == "minaf") {
                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                    ilha.zona[li - 1][co - 1]->edificio = new minaFerro(ilha.getcustoMinaF(), ilha.dia);

                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                }else
                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
            } else if (tipo == "minac") {
                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                    ilha.zona[li - 1][co - 1]->edificio = new minaCarvao(ilha.getcustoMinaC(), ilha.dia);

                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                }else
                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
            } else if (tipo == "central") {
                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                    ilha.zona[li - 1][co - 1]->edificio = new centralEletrica(ilha.getcustoCentralEletrica(),
                                                                              ilha.dia);
                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                }else
                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
            } else if (tipo == "bat") {
                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                    ilha.zona[li - 1][co - 1]->edificio = new bateria(ilha.getcustoBateria(), ilha.dia);

                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                }else
                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
            } else if (tipo == "fund") {
                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                    ilha.zona[li - 1][co - 1]->edificio = new fundicao(ilha.getcustoFundicao(), ilha.dia);

                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                }else
                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
            } else if (tipo == "banc") {
                if (ilha.zona[li - 1][co - 1]->edificio == nullptr) {
                    ilha.zona[li - 1][co - 1]->edificio = new edificioX(ilha.getcustoEdificioX(), ilha.dia);

                    if (ilha.zona[li - 1][co - 1]->getTipo() == "pnt ")
                        ilha.zona[li - 1][co - 1]->setguardaDiaEdiConstruido(ilha.dia);

                }else
                    cout << "[ERRO]: Já existe um edificio nesse sitio." << endl;
            } else
                cout << "[ERRO]: O tipo de edificio '" << tipo << "' não existe." << endl;
        }else
            cout << "[ERRO]: Verifique o comando" << endl;

        cout << ilha.getAsString(l,c);
    }else if (comando == "debkill") {
        cout << "COMANDO ENCONTRADO -> [debkill]" << endl;
        string id="0.0", guardaLetra;
        int flag = 0;

        if(ss.good())
            ss >> id;

        /* for (int i = 0; i < l; i++) {
             for (int j = 0; j < c; j++) {
                 for (int h = 0; h < ilha.zona[i][j]->trabalhador.size(); h++) {
                     cout << "Trabalhador '" << ilha.zona[i][j]->trabalhador[h]->gettipoTrabalhador()
                          << "' tem " << "ID: " << ilha.zona[i][j]->trabalhador[h]->getid() << endl;
                 }
             }
         }*/

        if(id != "0.0") {
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < c; j++) {

                    for (int h = 0; h < ilha.zona[i][j]->trabalhador.size(); h++) {

                        if (ilha.zona[i][j]->trabalhador[h]->getid() == id) {
                            guardaLetra = ilha.zona[i][j]->trabalhador[h]->gettipoTrabalhador();
                            ilha.zona[i][j]->trabalhador.erase(ilha.zona[i][j]->trabalhador.begin() + h);
                            ilha.zona[i][j]->settotalTrabalhadores(ilha.zona[i][j]->gettotalTrabalhadores() - 1);

                            cout << "Trabalhador '" << guardaLetra << "' foi removido com sucesso" << endl;
                            flag = 1;
                        }

                    }

                }
            }

            if(flag == 0)
                cout << "[ERRO]: Verifique o id" << endl;

        }else
            cout << "[ERRO]: Verifique o comando" << endl;

        cout << ilha.getAsString(l,c);
    }
    else {
        cout << "Comando " << comando << " invalido em ficheiro!" << endl;
    }

}


void interface::guardaSaves(string nome, ilhas &ilha)
{
    Saves.emplace_back(nome, ilha); //Quando faz isto chama o Construtor
}

void interface::loadEstadoJogo(string nome, ilhas &ilha)
{
    //for(int i= 0; i< Saves.size(); i++)
    for(auto &lo : Saves) {
        if(lo.getNomeSave() == nome) {
            ilha = lo.retorna();
        }
    }

}