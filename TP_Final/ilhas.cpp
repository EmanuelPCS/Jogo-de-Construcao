//
// Autores do Trabalho:
// Tânia Guedes    - 2020139445
// Emanuel Saraiva - 2019130219
//

#include "ilhas.h"

ilhas::~ilhas() {}

ilhas::ilhas(int l, int c) {//cout << "sd";
    /*zona = new zonas**[l];
    //cout << "dsdf";
    for(int i = 0; i < l; i++){
        zona[i] = new zonas*[c];
        for(int j = 0; j < c; j++){
            zona[i][j] = nullptr;
        }
    }

    for(int i=0; i<l; i++)
    {
        for(int j=0; j<c; j++)
            zona[i][j] = new zonas();
    }
    //Começa por preencher cada zona, de maneira a ter pelo menos uma de cada tipo
    for (int i = 0; i < 6; ++i) {
        int lRandom;
        int cRandom;
        int flag = 1;
        //Vai buscar um valor aleatorio tanto para as linhas como para as colunas
        while(flag){
            lRandom = randomEntreDoisNumeros(0, l - 1);
            cRandom = randomEntreDoisNumeros(0, c - 1);
            if (zona[lRandom][cRandom]->getTipo() == " ") {
                //zona[lRandom][cRandom]->setTipo(tipoZonas[i]);
                if(i == 0)
                    zona[lRandom][cRandom] = new montanha();
                else if(i == 1)
                    zona[lRandom][cRandom] = new deserto();
                else if(i == 2)
                    zona[lRandom][cRandom] = new pastagem();
                else if(i == 3)
                    zona[lRandom][cRandom] = new floresta();
                else if(i == 4)
                    zona[lRandom][cRandom] = new pantano();
                else
                    zona[lRandom][cRandom] = new zonaX();
                flag = 0; // quer dizer que na posicao random gerada não há lá nada, assim já pode sair
                // e ir buscar o proximo tipo de zona
            }
        };
    }

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            int varRandom;
            varRandom = randomEntreDoisNumeros(0,5); // O array começa em 0 -> assim faz 6
            if (zona[i][j]->getTipo() == " "){
                //zona[i][j]->setTipo(tipoZonas[varRandom]);
                if(varRandom == 0)
                    zona[i][j] = new montanha();
                else if(varRandom == 1)
                    zona[i][j] = new deserto();
                else if(varRandom == 2)
                    zona[i][j] = new pastagem();
                else if(varRandom == 3)
                    zona[i][j] = new floresta();
                else if(varRandom == 4)
                    zona[i][j] = new pantano();
                else
                    zona[i][j] = new zonaX();
            }
        }
    }*/


        //srand(time(nullptr));

        linha = l;
        coluna = c;

        int z=0;

        zona = new zonas**[l];
        for(int i=0; i<l; i++)
        {
            zona[i] = new zonas*[c];

        }

        array<int,6> foo { 1, 2, 3, 4, 5, 6};

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));

        for(int h = 0; h < l; h++){
            for(int j = 0; j < c; j++){
                switch(foo[z]){
                    case 1:
                        zona[h][j] = new montanha();
                        break;
                    case 2:
                        zona[h][j] = new deserto();
                        break;
                    case 3:
                        zona[h][j] = new pastagem();
                        break;
                    case 4:
                        zona[h][j] = new floresta();
                        break;
                    case 5:
                        zona[h][j] = new pantano();
                        break;
                    case 6:
                        zona[h][j] = new zonaX();
                        break;
                }

                if(z == 5)
                {
                    z = 0;
                    shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));
                }

                z++;
            }
        }

    /*for(int i = 0; i < l; i++)
    {
        for(int j =0; j < c; j++)
            delete zona[i][j];
        delete[] zona[i];
    }
    delete[] zona;*/

    dia = 1;
    aux = 0;

    dinheiro = 500;
    vigasMadeira = 0;

    totalMadeira = 0;
    totalBarraAco = 0;
    totalEletricidade = 0;

    totalFerro = 0;
    totalCarvao = 0;

    custoMinaF = 100;
    custoMinaC = 100;
    custoCentralEletrica = 15;
    custoBateria = 10;
    custoFundicao = 10;
    custoSerracao = 10;
    custoEdificioX = 0;

    custoTrabM = 10;
    custoTrabO = 15;
    custoTrabL = 20;

}

int ilhas::randomEntreDoisNumeros(int x, int y) {
    int numRandom = (rand()%(y-x + 1)) + x;
    return numRandom;
}

//desenhar vai ser tudo aqui
string ilhas::getAsString(int l, int c) {
    ostringstream oss;
    oss << endl;
    int cont = 0;
    for (int i=0; i<l; i++){
        for(int j=0; j< c; j++){
            if(cont >= 10 && cont <=99)
                oss << "__" << ++cont << "_";
            else if(cont < 10)
                oss << "__" << ++cont << "__";
            else if(cont >= 100)
                oss << "_" << ++cont << "_";
            else
            oss << "__" << ++cont << "__";
            if (j == c-1) oss << "_";
        }
        oss << endl;
        for (int z = 0; z <= 3; z++) {//conteudo das zonas
            for (int k = 0; k < c; k++) {
                switch (z) {
                    case 0:
                        oss << "|" << zona[i][k]->getTipo() << "" ;
                        break;

                    case 1:
                        if(zona[i][k]->edificio != nullptr)
                        oss << "|" << zona[i][k]->edificio->nomeEdificio << "" ;
                        else
                            oss << "|" << setw(5);
                        break;

                    case 2: //{
                        /*cout << "|" << zona[i][k]->tipoTrabalhadoresM
                             << setw(1) << zona[i][k]->tipoTrabalhadoresO
                             << setw(1) << zona[i][k]->tipoTrabalhadoresL;*/
                        oss << "|";
                        //zona[i][0]->settipoTrabalhadores('M',0);
                        int b;
                        for(b = 0; b < 4 && zona[i][k]->trabalhador.size() > b; b++){
                            oss << zona[i][k]->trabalhador[b]->gettipoTrabalhador();
                            //cout << zona[i][k]->gettipoTrabalhadores()[b];
                        }
                        if(b<4)
                            oss << setw(4-b) << " ";
                       /* int u;
                        int tam = zona[i][k]->trabalhador.size();
                        for (u = 0; u < tam && u < 4; u++)
                            oss << zona[i][k]->trabalhador[u]->gettipoTrabalhador();

                        if (u < 4)
                            oss << setw(4 - u) << " ";*/
                        break;
                    //}
                    case 3:
                        if (zona[i][k]->gettotalTrabalhadores() != 0){
                            oss << "|" << zona[i][k]->gettotalTrabalhadores() << "   " ;
                        }else
                            oss << "|    " ;
                        break;
                }
                if (k == c-1) oss << "|" ;
            }
            oss << endl;
        }
    }
    oss << endl;

    return oss.str();
}

ilhas::ilhas(const ilhas &il)
{
    if(zona != nullptr)
        *this = il;
}

ilhas & ilhas::operator=(const ilhas & il) {
    if (this == &il) {// prevencao da auto-atribuição
        return *this;
    }

    // se os dois membros da atribuicao forem objetos diferentes
    dinheiro = il.dinheiro;
    vigasMadeira = il.vigasMadeira;
    linha = il.linha;
    coluna = il.coluna;
    dia = il.dia;
    contaNumTra = il.contaNumTra;
    totalBarraAco = il.totalBarraAco;
    totalEletricidade = il.totalEletricidade;
    totalCarvao = il.totalCarvao;
    totalFerro = il.totalFerro;
    totalMadeira = il.totalMadeira;
    custoMinaF = il.custoMinaF;
    custoMinaC = il.custoMinaC;
    custoCentralEletrica = il.custoCentralEletrica;
    custoBateria = il.custoBateria;
    custoFundicao = il.custoFundicao;
    custoEdificioX = il.custoEdificioX;
    custoTrabM = il.custoTrabM;
    custoTrabO = il.custoTrabO;
    custoTrabL = il.custoTrabL;


    zona = new zonas**[linha];
    for(int i=0; i<linha; i++)
    {
        zona[i] = new zonas*[coluna];

    }

    // libertar a memoria dinamica usada exclusivamente pelo primeiro membro
    for (int i = 0; i < il.linha; i++) {
        for (int j = 0; j < il.coluna; j++) {

            zona[i][j]->duplica();

            zona[i][j]->copiaVector(zona[i][j]->trabalhador);

            zona[i][j]->copiaEdi(zona[i][j]->edificio);

        }
    }

    return *this;

}





/*
//desenhar vai ser tudo aqui
void ilhas::desenhar_ilhas_atual(ilhas &ilha) {
    for(int i = 0; i < 4; i++){cout << "|";
        for(int j = 0; j < 4; j++){
                cout << ilha[i][j];
        }
        cout << endl;
    }
}*/

void ilhas::amanhecer(int l, int c, ilhas &ilha){
    int diaDoTrab, flag = 0;
    string guardaDia, NumTra;

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(zona[i][j]->getTipo() == "pas "){
                //Nenhum trabalhador se despede logo nao chamamos a funcao despedimento
            }
            else if(zona[i][j]->getTipo() == "flr "){
                despedimento(dia, 0, ilha, i, j);
                if(zona[i][j]->edificio != nullptr) {
                    if (zona[i][j]->edificio->nomeEdificio == "    " && zona[i][j]->edificio != nullptr) {
                        if (dia % 2 == 0 && zona[i][j]->getarvores() <= 100)
                            zona[i][j]->setarvores(1);
                    } else if(zona[i][j]->edificio->nomeEdificio != "    " && zona[i][j]->edificio != nullptr) {
                        if(zona[i][j]->getarvores() > 0)
                            zona[i][j]->setarvores(-1);
                    }
                }
                for(int h = 0; h < zona[i][j]->trabalhador.size(); h++) {
                    if(zona[i][j]->trabalhador[h]->gettipoTrabalhador() == 'L') {
                        istringstream ss(zona[i][j]->trabalhador[h]->getid());
                        getline(ss, NumTra, '.');
                        getline(ss, guardaDia);
                        diaDoTrab = stoi(guardaDia);
                        //+1 madeira

                        if(aux + diaDoTrab <= diaDoTrab + 4)
                            zona[i][j]->setmadeira(1);
                        else
                            aux=0;

                    }
                }
            }
            else if(zona[i][j]->getTipo() == "mnt ") {
                despedimento(dia, 1, ilha, i ,j);
                zona[i][j]->setferro(zona[i][j]->gettotalTrabalhadores() * 0.1);
            }
            else if(zona[i][j]->getTipo() == "pnt "){
                despedimento(dia, 0, ilha, i ,j);
                if(zona[i][j]->edificio != nullptr) {
                    if (dia == zona[i][j]->getguardaDiaEdiConstruido() + 10) {

                        delete zona[i][j]->edificio;
                        zona[i][j]->edificio = nullptr;

                        zona[i][j]->trabalhador.clear();
                        zona[i][j]->settotalTrabalhadores(0);

                        // flag = 1;
                        //break;
                    }
                }
                //if (dia = dia de construcao + 10)
                // -> edificio desaparece
            }
            else if(zona[i][j]->getTipo() == "dsr "){
                despedimento(dia, 0, ilha, i ,j);

            }
            else if(zona[i][j]->getTipo() == "Cid "){
                int numSorte = ilha.randomEntreDoisNumeros(1,10);
                int pede;
                if(zona[i][j]->edificio != nullptr) {
                    if(zona[i][j]->edificio->nomeEdificio == "banc"){
                        cout << "Diga um Numero [1,10]: " << endl;
                        cin >> pede;
                        if(numSorte == pede){
                            ilha.setdinheiro(10000);
                            cout << "Parabens! Acertou no Numero!" << endl;
                            cout << "Ganhou 10 000 euros!!" << endl;
                            delete zona[i][j]->edificio;
                            zona[i][j]->edificio = nullptr;

                            zona[i][j]->trabalhador.clear();
                            zona[i][j]->settotalTrabalhadores(0);
                        }
                    }
                }
            }
        }//if(flag == 1)break;
    }
}
// Recebe o vector da zona especificada quando é chamada a função
void ilhas::despedimento(int dia, int chanceDespedimentoLenhador, ilhas &ilha, int i, int j) {
    int diaDoTrab;
    string guardaDia, NumTra;
    //NOTA: SE a chanceDespedimentoLenhador = 0 ent quer dizer que o trabalhador nao esta na montanha
    //NOTA: SE a chanceDespedimentoLenhador = 5 ent quer dizer que o trabalhadro esta na montanha e
    //      assim a sua prob aumenta 5%

    for(int h = 0; h < zona[i][j]->trabalhador.size(); h++){
        istringstream ss(zona[i][j]->trabalhador[h]->getid());
        getline(ss, NumTra, '.');
        getline(ss, guardaDia);
        diaDoTrab = stoi(guardaDia);

        if(zona[i][j]->trabalhador[h]->gettipoTrabalhador() == 'M' && dia > diaDoTrab) {

            if(chanceDespedimentoLenhador == 0) {
                if ((rand() % 100) < 10) {
                    zona[i][j]->trabalhador.erase(zona[i][j]->trabalhador.begin() + h);
                    zona[i][j]->settotalTrabalhadores(zona[i][j]->gettotalTrabalhadores() - 1);
                    cout << "O Trabalhador \"" << zona[i][j]->trabalhador[h]->gettipoTrabalhador() << "\" despediu-se";
                }
            }else{
                if ((rand() % 100) < 15) {
                    zona[i][j]->trabalhador.erase(zona[i][j]->trabalhador.begin() + h);
                    zona[i][j]->settotalTrabalhadores(zona[i][j]->gettotalTrabalhadores() - 1);
                    cout << "O Trabalhador \"" << zona[i][j]->trabalhador[h]->gettipoTrabalhador() << "\" despediu-se";
                }
            }
        }
        else if(zona[i][j]->trabalhador[h]->gettipoTrabalhador() == 'O' && dia >= diaDoTrab + 10) {

            if(chanceDespedimentoLenhador == 0) {
                if ((rand() % 100) < 5) {
                    zona[i][j]->trabalhador.erase(zona[i][j]->trabalhador.begin() + h);
                    zona[i][j]->settotalTrabalhadores(zona[i][j]->gettotalTrabalhadores() - 1);
                    cout << "O Trabalhador \"" << zona[i][j]->trabalhador[h]->gettipoTrabalhador() << "\" despediu-se";
                }
            }else{
                if ((rand() % 100) < 10) {
                    zona[i][j]->trabalhador.erase(zona[i][j]->trabalhador.begin() + h);
                    zona[i][j]->settotalTrabalhadores(zona[i][j]->gettotalTrabalhadores() - 1);
                    cout << "O Trabalhador \"" << zona[i][j]->trabalhador[h]->gettipoTrabalhador() << "\" despediu-se";
                }
            }

        }
        else if(zona[i][j]->trabalhador[h]->gettipoTrabalhador() == 'L' && (chanceDespedimentoLenhador == 1)) {

            if((rand() % 100) < 5){
                zona[i][j]->trabalhador.erase(zona[i][j]->trabalhador.begin() + h);
                zona[i][j]->settotalTrabalhadores(zona[i][j]->gettotalTrabalhadores() - 1);
                cout << "O Trabalhador \"" << zona[i][j]->trabalhador[h]->gettipoTrabalhador() << "\" despediu-se";
            }

        }

    }
/*
    for (int h = 0; h < zona[i][j]->trabalhador.size(); h++) {

        istringstream ss(zona[i][j]->trabalhador[h]->getid());
        while(getline(ss, nova, '.')) {
            arr[cont++] = nova;
        }
        NumTra = stoi(arr[0]);
        diaDoTrab= stoi(arr[1]);

        cout << NumTra << endl;
        cout << diaDoTrab<< endl;
        cout << "dia: " << dia << endl;
        cout << i << endl;
        cout << j << endl;


        if (zona[i][j]->trabalhador[h]->gettipoTrabalhador() == 'M' && chanceDespedimentoLenhador == 0) {
cout << "1"<< endl;

            if (dia > diaDoTrab) {

                compara = randomEntreDoisNumeros(1, 10);
                //o compara deu por exemplo 5.
                // qual é a prob. de em 10 numeros eu tirar o 5 -> 10%
                if (compara == randomEntreDoisNumeros(1, 10)) {
                    zona[i][j]->trabalhador.erase(zona[i][j]->trabalhador.begin() + h);
                    zona[i][j]->settotalTrabalhadores(zona[i][j]->gettotalTrabalhadores()-1);
                }
            }
        } else if (zona[i][j]->trabalhador[h]->gettipoTrabalhador() == 'M' && chanceDespedimentoLenhador == 5) {

            cout << "2"<< endl;
            //if (dia > diaDoTrab) {
                /*compara = randomEntreDoisNumeros(1,20);
                //o compara deu por exemplo 5.
                // qual é a prob. de em 10 numeros eu tirar o 5 -> 15%
                if(compara == randomEntreDoisNumeros(1,10) || compara == randomEntreDoisNumeros(1,20))
                    trabalhador.erase(trabalhador.begin() + h);*/
            //}
       /* } else if (zona[i][j]->trabalhador[h]->gettipoTrabalhador() == 'O' && chanceDespedimentoLenhador == 0) {


            cout << "3"<< endl;
            if (dia > diaDoTrab + 9) {
                compara = randomEntreDoisNumeros(1, 20);
                //o compara deu por exemplo 5.
                // qual é a prob. de em 20 numeros eu tirar o 5 -> 5%
                if (compara == randomEntreDoisNumeros(1, 20)) {
                    zona[i][j]->trabalhador.erase(zona[i][j]->trabalhador.begin() + h);
                    zona[i][j]->settotalTrabalhadores(zona[i][j]->gettotalTrabalhadores()-1);
                }
            }

        } else if (zona[i][j]->trabalhador[h]->gettipoTrabalhador() == 'O' && chanceDespedimentoLenhador == 5) {

            cout << "4"<< endl;
            if (dia > diaDoTrab + 9) {
                compara = randomEntreDoisNumeros(1, 10);
                //o compara deu por exemplo 5.
                // qual é a prob. de em 10 numeros eu tirar o 5 -> 10%
                if (compara == randomEntreDoisNumeros(1, 10)) {
                    zona[i][j]->trabalhador.erase(zona[i][j]->trabalhador.begin() + h);
                    zona[i][j]->settotalTrabalhadores(zona[i][j]->gettotalTrabalhadores()-1);
                }
            }
        } else if (zona[i][j]->trabalhador[h]->gettipoTrabalhador() == 'L' && chanceDespedimentoLenhador == 5) {

            cout << "5"<< endl;
            compara = randomEntreDoisNumeros(1, 20);
            //o compara deu por exemplo 5.
            // qual é a prob. de em 20 numeros eu tirar o 5 -> 5%
            if (compara == randomEntreDoisNumeros(1, 20)) {
                //zona[i][j]->trabalhador.erase(zona[i][j]->trabalhador.begin() + h);

                //zona[i][j]->settotalTrabalhadores(zona[i][j]->gettotalTrabalhadores()-1);
            }
        }
    }*/
}

void ilhas::produzir(int l, int c, ilhas &ilha) {

    int guardaI;
    int guardaJ;
    int guardaFI = 0, guardaFJ = 0, guardaFI2 = 0, guardaFJ2 = 0, flag = 0;
    int flagEdiLigado = 0;

    for(int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {

            if(zona[i][j]->edificio != nullptr) {
            if (zona[i][j]->edificio->getestado() == true) {
                    //Se o dia em que for contratado for igual ao dia em que estamos ent so produz metade
                    if (zona[i][j]->edificio->nomeEdificio == "mnF " &&
                        (zona[i][j]->edificio->getferro() < zona[i][j]->edificio->getarmazenamentoF())) {
                        for (int z = 0; z < zona[i][j]->trabalhador.size(); z++) {
                            if (zona[i][j]->trabalhador[z]->gettipoTrabalhador() == 'M') {
                                if (zona[i][j]->getTipo() == "mnt ")
                                    zona[i][j]->edificio->setferroMontanha();
                                else if (zona[i][j]->getTipo() == "dsr ")
                                    zona[i][j]->edificio->setferroDeserto();
                                else
                                    zona[i][j]->edificio->setferro(); // Só há um setferro
                            }
                        }

                        if ((rand() % 100) < zona[i][j]->edificio->getprobDesabarF()) {

                            delete zona[i][j]->edificio;
                            zona[i][j]->edificio = nullptr;

                            cout << "O Edificio " << zona[i][j]->edificio->nomeEdificio << " desabou";
                        }

                    } else if (zona[i][j]->edificio->nomeEdificio == "mnC " &&
                               (zona[i][j]->edificio->getcarvao() < zona[i][j]->edificio->getarmazenamentoC())) {
                        for (int z = 0; z < zona[i][j]->trabalhador.size(); z++) {
                            if (zona[i][j]->trabalhador[z]->gettipoTrabalhador() == 'M') {
                                if (zona[i][j]->getTipo() == "mnt ")
                                    zona[i][j]->edificio->setcarvaoMontanha();
                                else if (zona[i][j]->getTipo() == "dsr ")
                                    zona[i][j]->edificio->setcarvaoDeserto();
                                else
                                    zona[i][j]->edificio->setcarvao(); // Só há um setcarvao
                            }
                        }

                        if ((rand() % 100) < zona[i][j]->edificio->getprobDesabarC()) {

                            delete zona[i][j]->edificio;
                            zona[i][j]->edificio = nullptr;

                            cout << "O Edificio " << zona[i][j]->edificio->nomeEdificio << " desabou";
                        }
                    } else if (zona[i][j]->edificio->nomeEdificio == "elec") {
                        guardaI = 0;
                        guardaJ = 0;
                        for (int z = 0; z < zona[i][j]->trabalhador.size(); z++) {
                            if (zona[i][j]->trabalhador[z]->gettipoTrabalhador() == 'O') {
                                //FAZER UM break pq mal encontra um trabalhador sai. nao precisa de
                                // ver se tens varios trabalhadores, basta um
                                //Ver os 4 vertices (done); Ver a 1ª Linha -> i = 0; Ver a Ultima Linha -> l-1
                                //Ver a 1ª Coluna -> j = 0; Ver a Ultima Coluna -> c-1
                                if (i == 0 && j == 0) { // 1º Vertice
                                    if (zona[i][j + 1]->getTipo() == "flr " || zona[i + 1][j]->getTipo() == "flr ") {
                                        cout << "Encontrou - 1 Vertice" << endl;

                                        if (zona[i][j + 1]->getmadeira() >= 1 || zona[i + 1][j]->getmadeira() >= 1) {
                                            if (zona[i][j + 1]->getTipo() == "flr " &&
                                                zona[i][j + 1]->getmadeira() >= 1) {
                                                guardaI = i;
                                                guardaJ = j + 1;
                                            } else if (zona[i + 1][j]->getTipo() == "flr " &&
                                                       zona[i + 1][j]->getmadeira() >= 1) {
                                                guardaI = i + 1;
                                                guardaJ = j;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-1);
                                            if (zona[i][j]->edificio->getcarvaoCE() <
                                                zona[i][j]->edificio->getarmazenamentoCarvaoCE()) {
                                                zona[i][j]->edificio->setcarvaoCE();
                                            }
                                            zona[i][j]->edificio->setproduziu(
                                                    true); // dar reset ao final do dia -> passar a false
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (i == l - 1 && j == 0) { // 2º Vertice
                                    if (zona[i - 1][j]->getTipo() == "flr " || zona[i][j + 1]->getTipo() == "flr ") {
                                        cout << "Encontrou - 2 Vertice" << endl;
                                        if (zona[i - 1][j]->getmadeira() >= 1 || zona[i][j + 1]->getmadeira() >= 1) {
                                            if (zona[i - 1][j]->getTipo() == "flr " &&
                                                zona[i - 1][j]->getmadeira() >= 1) {
                                                guardaI = i - 1;
                                                guardaJ = j;
                                            } else if (zona[i][j + 1]->getTipo() == "flr " &&
                                                       zona[i][j + 1]->getmadeira() >= 1) {
                                                guardaI = i;
                                                guardaJ = j + 1;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-1);
                                            if (zona[i][j]->edificio->getcarvaoCE() <
                                                zona[i][j]->edificio->getarmazenamentoCarvaoCE()) {
                                                zona[i][j]->edificio->setcarvaoCE();
                                            }
                                            zona[i][j]->edificio->setproduziu(
                                                    true); // dar reset ao final do dia -> passar a false
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (j == c - 1 && i == 0) { // 3º Vertice
                                    if (zona[i][j - 1]->getTipo() == "flr " || zona[i + 1][j]->getTipo() == "flr ") {
                                        cout << "Encontrou - 3 Vertice" << endl;
                                        if (zona[i][j - 1]->getmadeira() >= 1 || zona[i + 1][j]->getmadeira() >= 1) {
                                            if (zona[i][j - 1]->getTipo() == "flr " &&
                                                zona[i][j - 1]->getmadeira() >= 1) {
                                                guardaI = i;
                                                guardaJ = j - 1;
                                            } else if (zona[i + 1][j]->getTipo() == "flr " &&
                                                       zona[i + 1][j]->getmadeira() >= 1) {
                                                guardaI = i + 1;
                                                guardaJ = j;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-1);
                                            if (zona[i][j]->edificio->getcarvaoCE() <
                                                zona[i][j]->edificio->getarmazenamentoCarvaoCE()) {
                                                zona[i][j]->edificio->setcarvaoCE();
                                            }
                                            zona[i][j]->edificio->setproduziu(
                                                    true); // dar reset ao final do dia -> passar a false
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (j == c - 1 && i == l - 1) { // 4º Vertice
                                    if (zona[i][j - 1]->getTipo() == "flr " || zona[i - 1][j]->getTipo() == "flr ") {
                                        cout << "Encontrou - 4 Vertice" << endl;
                                        if (zona[i][j - 1]->getmadeira() >= 1 || zona[i - 1][j]->getmadeira() >= 1) {
                                            if (zona[i][j - 1]->getTipo() == "flr " &&
                                                zona[i][j - 1]->getmadeira() >= 1) {
                                                guardaI = i;
                                                guardaJ = j - 1;
                                            } else if (zona[i - 1][j]->getTipo() == "flr " &&
                                                       zona[i - 1][j]->getmadeira() >= 1) {
                                                guardaI = i - 1;
                                                guardaJ = j;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-1);
                                            if (zona[i][j]->edificio->getcarvaoCE() <
                                                zona[i][j]->edificio->getarmazenamentoCarvaoCE()) {
                                                zona[i][j]->edificio->setcarvaoCE();
                                            }
                                            zona[i][j]->edificio->setproduziu(
                                                    true); // dar reset ao final do dia -> passar a false
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (i == 0 && j != 0 && j != c - 1) { // Ver a 1ª Linha -> i = 0
                                    if (zona[i + 1][j]->getTipo() == "flr " || zona[i][j - 1]->getTipo() == "flr " ||
                                        zona[i][j + 1]->getTipo() == "flr ") {
                                        cout << "Encontrou - 1ª Linha" << endl;
                                        if (zona[i + 1][j]->getmadeira() >= 1 || zona[i][j - 1]->getmadeira() >= 1 ||
                                            zona[i][j + 1]->getmadeira() >= 1) {

                                            if (zona[i + 1][j]->getTipo() == "flr " &&
                                                zona[i + 1][j]->getmadeira() >= 1) {
                                                guardaI = i + 1;
                                                guardaJ = j;
                                            } else if (zona[i][j - 1]->getTipo() == "flr " &&
                                                       zona[i][j - 1]->getmadeira() >= 1) {
                                                guardaI = i;
                                                guardaJ = j - 1;
                                            } else if (zona[i][j + 1]->getTipo() == "flr " &&
                                                       zona[i][j + 1]->getmadeira() >= 1) {
                                                guardaI = i;
                                                guardaJ = j + 1;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-1);
                                            if (zona[i][j]->edificio->getcarvaoCE() <
                                                zona[i][j]->edificio->getarmazenamentoCarvaoCE()) {
                                                zona[i][j]->edificio->setcarvaoCE();
                                            }
                                            zona[i][j]->edificio->setproduziu(
                                                    true); // dar reset ao final do dia -> passar a false
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (i == l - 1 && j != 0 && j != c - 1) { // Ver a Ultima Linha -> l - 1
                                    if (zona[i - 1][j]->getTipo() == "flr " || zona[i][j - 1]->getTipo() == "flr " ||
                                        zona[i][j + 1]->getTipo() == "flr ") {
                                        cout << "Encontrou - Ultima Linha" << endl;
                                        if (zona[i - 1][j]->getmadeira() >= 1 || zona[i][j - 1]->getmadeira() >= 1 ||
                                            zona[i][j + 1]->getmadeira() >= 1) {

                                            if (zona[i - 1][j]->getTipo() == "flr " &&
                                                zona[i - 1][j]->getmadeira() >= 1) {
                                                guardaI = i - 1;
                                                guardaJ = j;
                                            } else if (zona[i][j - 1]->getTipo() == "flr " &&
                                                       zona[i][j - 1]->getmadeira() >= 1) {
                                                guardaI = i;
                                                guardaJ = j - 1;
                                            } else if (zona[i][j + 1]->getTipo() == "flr " &&
                                                       zona[i][j + 1]->getmadeira() >= 1) {
                                                guardaI = i;
                                                guardaJ = j + 1;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-1);
                                            if (zona[i][j]->edificio->getcarvaoCE() <
                                                zona[i][j]->edificio->getarmazenamentoCarvaoCE()) {
                                                zona[i][j]->edificio->setcarvaoCE();
                                            }
                                            zona[i][j]->edificio->setproduziu(
                                                    true); // dar reset ao final do dia -> passar a false
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (j == 0 && i != 0 && i != l - 1) { // Ver a 1ª Coluna -> j = 0
                                    if (zona[i][j + 1]->getTipo() == "flr " || zona[i - 1][j]->getTipo() == "flr " ||
                                        zona[i + 1][j]->getTipo() == "flr ") {
                                        cout << "Encontrou - 1ª Coluna" << endl;
                                        if (zona[i][j + 1]->getmadeira() >= 1 || zona[i - 1][j]->getmadeira() >= 1 ||
                                            zona[i + 1][j]->getmadeira() >= 1) {

                                            if (zona[i][j + 1]->getTipo() == "flr " &&
                                                zona[i][j + 1]->getmadeira() >= 1) {
                                                guardaI = i;
                                                guardaJ = j + 1;
                                            } else if (zona[i - 1][j]->getTipo() == "flr " &&
                                                       zona[i - 1][j]->getmadeira() >= 1) {
                                                guardaI = i - 1;
                                                guardaJ = j;
                                            } else if (zona[i + 1][j]->getTipo() == "flr " &&
                                                       zona[i + 1][j]->getmadeira() >= 1) {
                                                guardaI = i + 1;
                                                guardaJ = j;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-1);
                                            if (zona[i][j]->edificio->getcarvaoCE() <
                                                zona[i][j]->edificio->getarmazenamentoCarvaoCE()) {
                                                zona[i][j]->edificio->setcarvaoCE();

                                            }
                                            zona[i][j]->edificio->setproduziu(
                                                    true); // dar reset ao final do dia -> passar a false
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (j == c - 1 && i != 0 && i != l - 1) { // Ver a Ultima Coluna -> c - 1
                                    if (zona[i][j - 1]->getTipo() == "flr " || zona[i - 1][j]->getTipo() == "flr " ||
                                        zona[i + 1][j]->getTipo() == "flr ") {
                                        cout << "Encontrou - ultima Coluna" << endl;
                                        if (zona[i][j - 1]->getmadeira() >= 1 || zona[i - 1][j]->getmadeira() >= 1 ||
                                            zona[i + 1][j]->getmadeira() >= 1) {

                                            if (zona[i][j - 1]->getTipo() == "flr " &&
                                                zona[i][j - 1]->getmadeira() >= 1) {
                                                guardaI = i;
                                                guardaJ = j - 1;
                                            } else if (zona[i - 1][j]->getTipo() == "flr " &&
                                                       zona[i - 1][j]->getmadeira() >= 1) {
                                                guardaI = i - 1;
                                                guardaJ = j;
                                            } else if (zona[i + 1][j]->getTipo() == "flr " &&
                                                       zona[i + 1][j]->getmadeira() >= 1) {
                                                guardaI = i + 1;
                                                guardaJ = j;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-1);
                                            if (zona[i][j]->edificio->getcarvaoCE() <
                                                zona[i][j]->edificio->getarmazenamentoCarvaoCE()) {
                                                zona[i][j]->edificio->setcarvaoCE();
                                            }
                                            zona[i][j]->edificio->setproduziu(
                                                    true); // dar reset ao final do dia -> passar a false
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else {// Se nao estou em nenhuma das anteriores, ent estou no meio da ilha
                                    if (zona[i - 1][j]->getTipo() == "flr " || zona[i + 1][j]->getTipo() == "flr " ||
                                        zona[i][j - 1]->getTipo() == "flr " || zona[i][j + 1]->getTipo() == "flr ") {
                                        cout << "Encontrou - no Meio" << endl;
                                        if (zona[i - 1][j]->getmadeira() >= 1 || zona[i + 1][j]->getmadeira() >= 1 ||
                                            zona[i][j - 1]->getmadeira() >= 1 || zona[i][j + 1]->getmadeira() >= 1) {

                                            if (zona[i - 1][j]->getTipo() == "flr " &&
                                                zona[i - 1][j]->getmadeira() >= 1) {
                                                guardaI = i - 1;
                                                guardaJ = j;
                                            } else if (zona[i + 1][j]->getTipo() == "flr " &&
                                                       zona[i + 1][j]->getmadeira() >= 1) {
                                                guardaI = i + 1;
                                                guardaJ = j;
                                            } else if (zona[i][j - 1]->getTipo() == "flr " &&
                                                       zona[i][j - 1]->getmadeira() >= 1) {
                                                guardaI = i;
                                                guardaJ = j - 1;
                                            } else if (zona[i][j + 1]->getTipo() == "flr " &&
                                                       zona[i][j + 1]->getmadeira() >= 1) {
                                                guardaI = i;
                                                guardaJ = j + 1;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-1);
                                            if (zona[i][j]->edificio->getcarvaoCE() <
                                                zona[i][j]->edificio->getarmazenamentoCarvaoCE()) {
                                                zona[i][j]->edificio->setcarvaoCE();
                                            }
                                            zona[i][j]->edificio->setproduziu(
                                                    true); // dar reset ao final do dia -> passar a false
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                }

                            }
                        }

                    } else if (zona[i][j]->edificio->nomeEdificio == "bat " &&
                               zona[i][j]->edificio->geteletricidadeB() < zona[i][j]->edificio->getarmazenamentoB()) {

                        //Ver os 4 vertices (done); Ver a 1ª Linha -> i = 0; Ver a Ultima Linha -> l-1
                        //Ver a 1ª Coluna -> j = 0; Ver a Ultima Coluna -> c-1
                        if (i == 0 && j == 0) { // 1º Vertice
                            if(zona[i][j + 1]->edificio != nullptr){
                                if (zona[i][j + 1]->edificio->nomeEdificio == "elec") {
                                    //cout << "Encontrou - 1 Vertice" << endl;
                                    if (zona[i][j + 1]->edificio->nomeEdificio == "elec" &&
                                        zona[i][j + 1]->edificio->getproduziu() != false) {
                                        zona[i][j]->edificio->seteletricidadeB(1);
                                        zona[i][j + 1]->edificio->setproduziu(false);
                                    }
                                }
                            }
                            if(zona[i + 1][j]->edificio != nullptr){
                                if (zona[i + 1][j]->edificio->nomeEdificio == "elec") {
                                    if (zona[i + 1][j]->edificio->nomeEdificio == "elec" &&
                                        zona[i + 1][j]->edificio->getproduziu() != false) {
                                        zona[i][j]->edificio->seteletricidadeB(1);
                                        zona[i + 1][j]->edificio->setproduziu(false);
                                    }
                                }
                            }

                        } else if (i == l - 1 && j == 0) { // 2º Vertice
                            if (zona[i - 1][j]->edificio->nomeEdificio == "elec" ||
                                zona[i][j + 1]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - 2 Vertice" << endl;

                                if (zona[i - 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i - 1][j]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i - 1][j]->edificio->setproduziu(false);
                                }
                                if (zona[i][j + 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j + 1]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i][j + 1]->edificio->setproduziu(false);
                                }
                            } else
                                cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                        } else if (j == c - 1 && i == 0) { // 3º Vertice
                            if (zona[i][j - 1]->edificio->nomeEdificio == "elec" ||
                                zona[i + 1][j]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - 3 Vertice" << endl;

                                if (zona[i][j - 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j - 1]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i][j - 1]->edificio->setproduziu(false);
                                }
                                if (zona[i + 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i + 1][j]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i + 1][j]->edificio->setproduziu(false);
                                }
                            } else
                                cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                        } else if (j == c - 1 && i == l - 1) { // 4º Vertice
                            if (zona[i][j - 1]->edificio->nomeEdificio == "elec" ||
                                zona[i - 1][j]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - 4 Vertice" << endl;

                                if (zona[i][j - 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j - 1]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i][j - 1]->edificio->setproduziu(false);
                                }
                                if (zona[i - 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i - 1][j]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i - 1][j]->edificio->setproduziu(false);
                                }
                            } else
                                cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                        } else if (i == 0 && j != 0 && j != c - 1) { // Ver a 1ª Linha -> i = 0
                            if (zona[i + 1][j]->edificio->nomeEdificio == "elec" ||
                                zona[i][j - 1]->edificio->nomeEdificio == "elec" ||
                                zona[i][j + 1]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - 1ª Linha" << endl;
                                if (zona[i + 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i + 1][j]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i + 1][j]->edificio->setproduziu(false);
                                }
                                if (zona[i][j - 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j - 1]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i][j - 1]->edificio->setproduziu(false);
                                }
                                if (zona[i][j + 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j + 1]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i][j + 1]->edificio->setproduziu(false);
                                }
                            } else
                                cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                        } else if (i == l - 1 && j != 0 && j != c - 1) { // Ver a Ultima Linha -> l - 1
                            if (zona[i - 1][j]->edificio->nomeEdificio == "elec" ||
                                zona[i][j - 1]->edificio->nomeEdificio == "elec" ||
                                zona[i][j + 1]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - Ultima Linha" << endl;
                                if (zona[i - 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i - 1][j]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i - 1][j]->edificio->setproduziu(false);
                                }
                                if (zona[i][j - 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j - 1]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i][j - 1]->edificio->setproduziu(false);
                                }
                                if (zona[i][j + 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j + 1]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i][j + 1]->edificio->setproduziu(false);
                                }
                            } else
                                cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                        } else if (j == 0 && i != 0 && i != l - 1) { // Ver a 1ª Coluna -> j = 0
                            if (zona[i][j + 1]->edificio->nomeEdificio == "elec" ||
                                zona[i - 1][j]->edificio->nomeEdificio == "elec" ||
                                zona[i + 1][j]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - 1ª Coluna" << endl;
                                if (zona[i][j + 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j + 1]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i][j + 1]->edificio->setproduziu(false);
                                }
                                if (zona[i - 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i - 1][j]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i - 1][j]->edificio->setproduziu(false);
                                }
                                if (zona[i + 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i + 1][j]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i + 1][j]->edificio->setproduziu(false);
                                }
                            } else
                                cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                        } else if (j == c - 1 && i != 0 && i != l - 1) { // Ver a Ultima Coluna -> c - 1
                            if (zona[i][j - 1]->edificio->nomeEdificio == "elec" ||
                                zona[i - 1][j]->edificio->nomeEdificio == "elec" ||
                                zona[i + 1][j]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - ultima Coluna" << endl;
                                if (zona[i][j - 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j - 1]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i][j - 1]->edificio->setproduziu(false);
                                }
                                if (zona[i - 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i - 1][j]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i - 1][j]->edificio->setproduziu(false);
                                }
                                if (zona[i + 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i + 1][j]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i + 1][j]->edificio->setproduziu(false);
                                }
                            } else
                                cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                        } else {// Se nao estou em nenhuma das anteriores, ent estou no meio da ilha
                            if (zona[i - 1][j]->edificio->nomeEdificio == "elec" ||
                                zona[i + 1][j]->edificio->nomeEdificio == "elec" ||
                                zona[i][j - 1]->edificio->nomeEdificio == "elec" ||
                                zona[i][j + 1]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - no Meio" << endl;
                                if (zona[i - 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i - 1][j]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i - 1][j]->edificio->setproduziu(false);
                                }
                                if (zona[i + 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i + 1][j]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i + 1][j]->edificio->setproduziu(false);
                                }
                                if (zona[i][j - 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j - 1]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i][j - 1]->edificio->setproduziu(false);
                                }
                                if (zona[i][j + 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j + 1]->edificio->getproduziu() != false) {
                                    zona[i][j]->edificio->seteletricidadeB(1);
                                    zona[i][j + 1]->edificio->setproduziu(false);
                                }
                            } else
                                cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                        }
                    } else if (zona[i][j]->edificio->nomeEdificio == "fun " &&
                               zona[i][j]->edificio->getbarraAco() < zona[i][j]->edificio->getarmazenamentoFun()) {
                        flag = 0;
                        guardaFI = 0;
                        guardaFJ = 0;
                        guardaFI2 = 0;
                        guardaFJ2 = 0;
                        //Ver os 4 vertices (done); Ver a 1ª Linha -> i = 0; Ver a Ultima Linha -> l-1
                        //Ver a 1ª Coluna -> j = 0; Ver a Ultima Coluna -> c-1
                        if (i == 0 && j == 0) { // 1º Vertice
                            if(zona[i][j + 1]->edificio != nullptr){
                                if (zona[i][j + 1]->edificio->nomeEdificio == "mnF " &&
                                    zona[i][j + 1]->edificio->getferro() >= 1.5) {
                                    guardaFI = i;
                                    guardaFJ = j + 1;
                                }
                                else if(zona[i + 1][j]->edificio != nullptr){
                                    if (zona[i + 1][j]->edificio->nomeEdificio == "mnF " &&
                                             zona[i + 1][j]->edificio->getferro() >= 1.5) {
                                        guardaFI = i + 1;
                                        guardaFJ = j;
                                    }
                                }
                            }
                            if(zona[i + 1][j]->edificio != nullptr){
                                if (zona[i + 1][j]->edificio->nomeEdificio == "mnF " &&
                                    zona[i + 1][j]->edificio->getferro() >= 1.5) {
                                    guardaFI = i + 1;
                                    guardaFJ = j;
                                }else if(zona[i][j + 1]->edificio != nullptr) {
                                    if (zona[i][j + 1]->edificio->nomeEdificio == "mnF " &&
                                        zona[i][j + 1]->edificio->getferro() >= 1.5) {
                                        guardaFI = i;
                                        guardaFJ = j + 1;
                                    }
                                }
                            }

                            if (zona[i][j + 1]->edificio->nomeEdificio == "mnC " ||
                                zona[i + 1][j]->edificio->nomeEdificio == "mnC ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j + 1]->edificio->nomeEdificio == "mnC " &&
                                    zona[i][j + 1]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j + 1;
                                    flag = 1;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "mnC " &&
                                           zona[i + 1][j]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i + 1;
                                    guardaFJ2 = j;
                                    flag = 1;
                                }
                            } else if (zona[i][j + 1]->edificio->nomeEdificio == "elec" ||
                                       zona[i + 1][j]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j + 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j + 1]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j + 1;
                                    flag = 2;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "elec" &&
                                           zona[i + 1][j]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i + 1;
                                    guardaFJ2 = j;
                                    flag = 2;
                                }
                            }

                        } else if (i == l - 1 && j == 0) { // 2º Vertice
                            if (zona[i - 1][j]->edificio->nomeEdificio == "mnF " ||
                                zona[i][j + 1]->edificio->nomeEdificio == "mnF ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i - 1][j]->edificio->nomeEdificio == "mnF " &&
                                    zona[i - 1][j]->edificio->getferro() >= 1.5) {
                                    guardaFI = i - 1;
                                    guardaFJ = j;
                                } else if (zona[i][j + 1]->edificio->nomeEdificio == "mnF " &&
                                           zona[i][j + 1]->edificio->getferro() >= 1.5) {
                                    guardaFI = i;
                                    guardaFJ = j + 1;
                                }
                            }
                            if (zona[i - 1][j]->edificio->nomeEdificio == "mnC " ||
                                zona[i][j + 1]->edificio->nomeEdificio == "mnC ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i - 1][j]->edificio->nomeEdificio == "mnC " &&
                                    zona[i - 1][j]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i - 1;
                                    guardaFJ2 = j;
                                    flag = 1;
                                } else if (zona[i][j + 1]->edificio->nomeEdificio == "mnC " &&
                                           zona[i][j + 1]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j + 1;
                                    flag = 1;
                                }
                            } else if (zona[i - 1][j]->edificio->nomeEdificio == "elec" ||
                                       zona[i][j + 1]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i - 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i - 1][j]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i - 1;
                                    guardaFJ2 = j;
                                    flag = 2;
                                } else if (zona[i][j + 1]->edificio->nomeEdificio == "elec" &&
                                           zona[i][j + 1]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j + 1;
                                    flag = 2;
                                }
                            }

                        } else if (j == c - 1 && i == 0) { // 3º Vertice
                            if (zona[i][j - 1]->edificio->nomeEdificio == "mnF " ||
                                zona[i + 1][j]->edificio->nomeEdificio == "mnF ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j - 1]->edificio->nomeEdificio == "mnF " &&
                                    zona[i][j - 1]->edificio->getferro() >= 1.5) {
                                    guardaFI = i;
                                    guardaFJ = j - 1;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "mnF " &&
                                           zona[i + 1][j]->edificio->getferro() >= 1.5) {
                                    guardaFI = i + 1;
                                    guardaFJ = j;
                                }
                            }
                            if (zona[i][j - 1]->edificio->nomeEdificio == "mnC " ||
                                zona[i + 1][j]->edificio->nomeEdificio == "mnC ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j - 1]->edificio->nomeEdificio == "mnC " &&
                                    zona[i][j - 1]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j - 1;
                                    flag = 1;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "mnC " &&
                                           zona[i + 1][j]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i + 1;
                                    guardaFJ2 = j;
                                    flag = 1;
                                }
                            } else if (zona[i][j - 1]->edificio->nomeEdificio == "elec" ||
                                       zona[i + 1][j]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j - 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j - 1]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j - 1;
                                    flag = 2;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "elec" &&
                                           zona[i + 1][j]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i + 1;
                                    guardaFJ2 = j;
                                    flag = 2;
                                }
                            }

                        } else if (j == c - 1 && i == l - 1) { // 4º Vertice
                            if (zona[i][j - 1]->edificio->nomeEdificio == "mnF " ||
                                zona[i - 1][j]->edificio->nomeEdificio == "mnF ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j - 1]->edificio->nomeEdificio == "mnF " &&
                                    zona[i][j - 1]->edificio->getferro() >= 1.5) {
                                    guardaFI = i;
                                    guardaFJ = j - 1;
                                } else if (zona[i - 1][j]->edificio->nomeEdificio == "mnF " &&
                                           zona[i - 1][j]->edificio->getferro() >= 1.5) {
                                    guardaFI = i - 1;
                                    guardaFJ = j;
                                }
                            }
                            if (zona[i][j - 1]->edificio->nomeEdificio == "mnC " ||
                                zona[i - 1][j]->edificio->nomeEdificio == "mnC ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j - 1]->edificio->nomeEdificio == "mnC " &&
                                    zona[i][j - 1]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j - 1;
                                    flag = 1;
                                } else if (zona[i - 1][j]->edificio->nomeEdificio == "mnC " &&
                                           zona[i - 1][j]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i - 1;
                                    guardaFJ2 = j;
                                    flag = 1;
                                }
                            } else if (zona[i][j - 1]->edificio->nomeEdificio == "elec" ||
                                       zona[i - 1][j]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j - 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j - 1]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j - 1;
                                    flag = 2;
                                } else if (zona[i - 1][j]->edificio->nomeEdificio == "elec" &&
                                           zona[i - 1][j]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i - 1;
                                    guardaFJ2 = j;
                                    flag = 2;
                                }
                            }

                        } else if (i == 0 && j != 0 && j != c - 1) { // Ver a 1ª Linha -> i = 0
                            if (zona[i + 1][j]->edificio->nomeEdificio == "mnF " ||
                                zona[i][j - 1]->edificio->nomeEdificio == "mnF " ||
                                zona[i][j + 1]->edificio->nomeEdificio == "mnF ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i + 1][j]->edificio->nomeEdificio == "mnF " &&
                                    zona[i + 1][j]->edificio->getferro() >= 1.5) {
                                    guardaFI = i + 1;
                                    guardaFJ = j;
                                } else if (zona[i][j - 1]->edificio->nomeEdificio == "mnF " &&
                                           zona[i][j - 1]->edificio->getferro() >= 1.5) {
                                    guardaFI = i;
                                    guardaFJ = j - 1;
                                } else if (zona[i][j + 1]->edificio->nomeEdificio == "mnF " &&
                                           zona[i][j + 1]->edificio->getferro() >= 1.5) {
                                    guardaFI = i;
                                    guardaFJ = j + 1;
                                }
                            }
                            if (zona[i + 1][j]->edificio->nomeEdificio == "mnC " ||
                                zona[i][j - 1]->edificio->nomeEdificio == "mnC " ||
                                zona[i][j + 1]->edificio->nomeEdificio == "mnC ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i + 1][j]->edificio->nomeEdificio == "mnC " &&
                                    zona[i + 1][j]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i + 1;
                                    guardaFJ2 = j;
                                    flag = 1;
                                } else if (zona[i][j - 1]->edificio->nomeEdificio == "mnC " &&
                                           zona[i][j - 1]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j - 1;
                                    flag = 1;
                                } else if (zona[i][j + 1]->edificio->nomeEdificio == "mnC " &&
                                           zona[i][j + 1]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j + 1;
                                    flag = 1;
                                }
                            } else if (zona[i + 1][j]->edificio->nomeEdificio == "elec" ||
                                       zona[i][j - 1]->edificio->nomeEdificio == "elec" ||
                                       zona[i][j + 1]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i + 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i + 1][j]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i + 1;
                                    guardaFJ2 = j;
                                    flag = 2;
                                } else if (zona[i][j - 1]->edificio->nomeEdificio == "elec" &&
                                           zona[i][j - 1]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j - 1;
                                    flag = 2;
                                } else if (zona[i][j + 1]->edificio->nomeEdificio == "elec" &&
                                           zona[i][j + 1]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j + 1;
                                    flag = 2;
                                }
                            }
                        } else if (i == l - 1 && j != 0 && j != c - 1) { // Ver a Ultima Linha -> l - 1
                            if (zona[i - 1][j]->edificio->nomeEdificio == "mnF " ||
                                zona[i][j - 1]->edificio->nomeEdificio == "mnF " ||
                                zona[i][j + 1]->edificio->nomeEdificio == "mnF ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i - 1][j]->edificio->nomeEdificio == "mnF " &&
                                    zona[i - 1][j]->edificio->getferro() >= 1.5) {
                                    guardaFI = i - 1;
                                    guardaFJ = j;
                                } else if (zona[i][j - 1]->edificio->nomeEdificio == "mnF " &&
                                           zona[i][j - 1]->edificio->getferro() >= 1.5) {
                                    guardaFI = i;
                                    guardaFJ = j - 1;
                                } else if (zona[i][j + 1]->edificio->nomeEdificio == "mnF " &&
                                           zona[i][j + 1]->edificio->getferro() >= 1.5) {
                                    guardaFI = i;
                                    guardaFJ = j + 1;
                                }
                            }
                            if (zona[i - 1][j]->edificio->nomeEdificio == "mnC " ||
                                zona[i][j - 1]->edificio->nomeEdificio == "mnC " ||
                                zona[i][j + 1]->edificio->nomeEdificio == "mnC ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i - 1][j]->edificio->nomeEdificio == "mnC " &&
                                    zona[i - 1][j]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i - 1;
                                    guardaFJ2 = j;
                                    flag = 1;
                                } else if (zona[i][j - 1]->edificio->nomeEdificio == "mnC " &&
                                           zona[i][j - 1]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j - 1;
                                    flag = 1;
                                } else if (zona[i][j + 1]->edificio->nomeEdificio == "mnC " &&
                                           zona[i][j + 1]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j + 1;
                                    flag = 1;
                                }
                            } else if (zona[i - 1][j]->edificio->nomeEdificio == "elec" ||
                                       zona[i][j - 1]->edificio->nomeEdificio == "elec" ||
                                       zona[i][j + 1]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i - 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i - 1][j]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i - 1;
                                    guardaFJ2 = j;
                                    flag = 2;
                                } else if (zona[i][j - 1]->edificio->nomeEdificio == "elec" &&
                                           zona[i][j - 1]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j - 1;
                                    flag = 2;
                                } else if (zona[i][j + 1]->edificio->nomeEdificio == "elec" &&
                                           zona[i][j + 1]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j + 1;
                                    flag = 2;
                                }
                            }

                        } else if (j == 0 && i != 0 && i != l - 1) { // Ver a 1ª Coluna -> j = 0
                            if (zona[i][j + 1]->edificio->nomeEdificio == "mnF " ||
                                zona[i - 1][j]->edificio->nomeEdificio == "mnF " ||
                                zona[i + 1][j]->edificio->nomeEdificio == "mnF ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j + 1]->edificio->nomeEdificio == "mnF " &&
                                    zona[i][j + 1]->edificio->getferro() >= 1.5) {
                                    guardaFI = i;
                                    guardaFJ = j + 1;
                                } else if (zona[i - 1][j]->edificio->nomeEdificio == "mnF " &&
                                           zona[i - 1][j]->edificio->getferro() >= 1.5) {
                                    guardaFI = i - 1;
                                    guardaFJ = j;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "mnF " &&
                                           zona[i + 1][j]->edificio->getferro() >= 1.5) {
                                    guardaFI = i + 1;
                                    guardaFJ = j;
                                }
                            }
                            if (zona[i][j + 1]->edificio->nomeEdificio == "mnC " ||
                                zona[i - 1][j]->edificio->nomeEdificio == "mnC " ||
                                zona[i + 1][j]->edificio->nomeEdificio == "mnC ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j + 1]->edificio->nomeEdificio == "mnC " &&
                                    zona[i][j + 1]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j + 1;
                                    flag = 1;
                                } else if (zona[i - 1][j]->edificio->nomeEdificio == "mnC " &&
                                           zona[i - 1][j]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i - 1;
                                    guardaFJ2 = j;
                                    flag = 1;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "mnC " &&
                                           zona[i + 1][j]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i + 1;
                                    guardaFJ2 = j;
                                    flag = 1;
                                }
                            } else if (zona[i][j + 1]->edificio->nomeEdificio == "elec" ||
                                       zona[i - 1][j]->edificio->nomeEdificio == "elec" ||
                                       zona[i + 1][j]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j + 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j + 1]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j + 1;
                                    flag = 2;
                                } else if (zona[i - 1][j]->edificio->nomeEdificio == "elec" &&
                                           zona[i - 1][j]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i - 1;
                                    guardaFJ2 = j;
                                    flag = 2;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "elec" &&
                                           zona[i + 1][j]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i + 1;
                                    guardaFJ2 = j;
                                    flag = 2;
                                }
                            }
                        } else if (j == c - 1 && i != 0 && i != l - 1) { // Ver a Ultima Coluna -> c - 1
                            if (zona[i][j - 1]->edificio->nomeEdificio == "mnF " ||
                                zona[i - 1][j]->edificio->nomeEdificio == "mnF " ||
                                zona[i + 1][j]->edificio->nomeEdificio == "mnF ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j - 1]->edificio->nomeEdificio == "mnF " &&
                                    zona[i][j - 1]->edificio->getferro() >= 1.5) {
                                    guardaFI = i;
                                    guardaFJ = j - 1;
                                } else if (zona[i - 1][j]->edificio->nomeEdificio == "mnF " &&
                                           zona[i - 1][j]->edificio->getferro() >= 1.5) {
                                    guardaFI = i - 1;
                                    guardaFJ = j;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "mnF " &&
                                           zona[i + 1][j]->edificio->getferro() >= 1.5) {
                                    guardaFI = i + 1;
                                    guardaFJ = j;
                                }
                            }
                            if (zona[i][j - 1]->edificio->nomeEdificio == "mnC " ||
                                zona[i - 1][j]->edificio->nomeEdificio == "mnC " ||
                                zona[i + 1][j]->edificio->nomeEdificio == "mnC ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j - 1]->edificio->nomeEdificio == "mnC " &&
                                    zona[i][j - 1]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j - 1;
                                    flag = 1;
                                } else if (zona[i - 1][j]->edificio->nomeEdificio == "mnC " &&
                                           zona[i - 1][j]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i - 1;
                                    guardaFJ2 = j;
                                    flag = 1;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "mnC " &&
                                           zona[i + 1][j]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i + 1;
                                    guardaFJ2 = j;
                                    flag = 1;
                                }
                            } else if (zona[i][j - 1]->edificio->nomeEdificio == "elec" ||
                                       zona[i - 1][j]->edificio->nomeEdificio == "elec" ||
                                       zona[i + 1][j]->edificio->nomeEdificio == "elec") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i][j - 1]->edificio->nomeEdificio == "elec" &&
                                    zona[i][j - 1]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j - 1;
                                    flag = 2;
                                } else if (zona[i - 1][j]->edificio->nomeEdificio == "elec" &&
                                           zona[i - 1][j]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i - 1;
                                    guardaFJ2 = j;
                                    flag = 2;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "elec" &&
                                           zona[i + 1][j]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i + 1;
                                    guardaFJ2 = j;
                                    flag = 2;
                                }
                            }
                        } else {// Se nao estou em nenhuma das anteriores, ent estou no meio da ilha
                            if (zona[i - 1][j]->edificio->nomeEdificio == "mnF " ||
                                zona[i + 1][j]->edificio->nomeEdificio == "mnF " ||
                                zona[i][j - 1]->edificio->nomeEdificio == "mnF " ||
                                zona[i][j + 1]->edificio->nomeEdificio == "mnF ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i - 1][j]->edificio->nomeEdificio == "mnF " &&
                                    zona[i - 1][j]->edificio->getferro() >= 1.5) {
                                    guardaFI = i - 1;
                                    guardaFJ = j;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "mnF " &&
                                           zona[i + 1][j]->edificio->getferro() >= 1.5) {
                                    guardaFI = i + 1;
                                    guardaFJ = j;
                                } else if (zona[i][j - 1]->edificio->nomeEdificio == "mnF " &&
                                           zona[i][j - 1]->edificio->getferro() >= 1.5) {
                                    guardaFI = i;
                                    guardaFJ = j - 1;
                                } else if (zona[i][j + 1]->edificio->nomeEdificio == "mnF " &&
                                           zona[i][j + 1]->edificio->getferro() >= 1.5) {
                                    guardaFI = i;
                                    guardaFJ = j + 1;
                                }
                            }
                            if (zona[i - 1][j]->edificio->nomeEdificio == "mnC " ||
                                zona[i + 1][j]->edificio->nomeEdificio == "mnC " ||
                                zona[i][j - 1]->edificio->nomeEdificio == "mnC " ||
                                zona[i][j + 1]->edificio->nomeEdificio == "mnC ") {
                                cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i - 1][j]->edificio->nomeEdificio == "mnC " &&
                                    zona[i - 1][j]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i - 1;
                                    guardaFJ2 = j;
                                    flag = 1;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "mnC " &&
                                           zona[i + 1][j]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i + 1;
                                    guardaFJ2 = j;
                                    flag = 1;
                                } else if (zona[i][j - 1]->edificio->nomeEdificio == "mnC " &&
                                           zona[i][j - 1]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j - 1;
                                    flag = 1;
                                } else if (zona[i][j + 1]->edificio->nomeEdificio == "mnC " &&
                                           zona[i][j + 1]->edificio->getcarvao() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j + 1;
                                    flag = 1;
                                }
                            } else if (zona[i - 1][j]->edificio->nomeEdificio == "elec" ||
                                       zona[i + 1][j]->edificio->nomeEdificio == "elec" ||
                                       zona[i][j - 1]->edificio->nomeEdificio == "elec" ||
                                       zona[i][j + 1]->edificio->nomeEdificio == "elec") {
                                //cout << "Encontrou - 1 Vertice" << endl;

                                if (zona[i - 1][j]->edificio->nomeEdificio == "elec" &&
                                    zona[i - 1][j]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i - 1;
                                    guardaFJ2 = j;
                                    flag = 2;
                                } else if (zona[i + 1][j]->edificio->nomeEdificio == "elec" &&
                                           zona[i + 1][j]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i + 1;
                                    guardaFJ2 = j;
                                    flag = 2;
                                } else if (zona[i][j - 1]->edificio->nomeEdificio == "elec" &&
                                           zona[i][j - 1]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j - 1;
                                    flag = 2;
                                } else if (zona[i][j + 1]->edificio->nomeEdificio == "elec" &&
                                           zona[i][j + 1]->edificio->getcarvaoCE() >= 0.5) {
                                    guardaFI2 = i;
                                    guardaFJ2 = j + 1;
                                    flag = 2;
                                }
                            }
                        }

                        if (guardaFI != 0 && guardaFJ != 0 && guardaFI2 != 0 && guardaFJ2 != 0) {
                            if (flag == 1)
                                zona[guardaFI2][guardaFJ2]->edificio->setcarvaoSemNivel(-0.5);
                            else if (flag == 2)
                                zona[guardaFI2][guardaFJ2]->edificio->setcarvaoCESemNivel(-0.5);

                            zona[guardaFI][guardaFJ]->edificio->setferroSemNivel(-1.5);

                            zona[guardaFI][guardaFJ]->edificio->setbarraAco(1);

                        }

                    } else if (zona[i][j]->edificio->nomeEdificio == "ser ") {
                        guardaI = 0;
                        guardaJ = 0;
                        for (int z = 0; z < zona[i][j]->trabalhador.size(); z++) {
                            if (zona[i][j]->trabalhador[z]->gettipoTrabalhador() == 'L') {
                                //FAZER UM break pq mal encontra um trabalhador sai. nao precisa de
                                // ver se tens varios trabalhadores, basta um
                                //Ver os 4 vertices (done); Ver a 1ª Linha -> i = 0; Ver a Ultima Linha -> l-1
                                //Ver a 1ª Coluna -> j = 0; Ver a Ultima Coluna -> c-1
                                if (i == 0 && j == 0) { // 1º Vertice
                                    if (zona[i][j + 1]->getTipo() == "flr " || zona[i + 1][j]->getTipo() == "flr ") {
                                        cout << "Encontrou - 1 Vertice" << endl;

                                        if (zona[i][j + 1]->getmadeira() >= 2 || zona[i + 1][j]->getmadeira() >= 2) {
                                            if (zona[i][j + 1]->getTipo() == "flr " &&
                                                zona[i][j + 1]->getmadeira() >= 2) {
                                                guardaI = i;
                                                guardaJ = j + 1;
                                            } else if (zona[i + 1][j]->getTipo() == "flr " &&
                                                       zona[i + 1][j]->getmadeira() >= 2) {
                                                guardaI = i + 1;
                                                guardaJ = j;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-2);
                                            setvigasMadeira(1);
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (i == l - 1 && j == 0) { // 2º Vertice
                                    if (zona[i - 1][j]->getTipo() == "flr " || zona[i][j + 1]->getTipo() == "flr ") {
                                        cout << "Encontrou - 2 Vertice" << endl;
                                        if (zona[i - 1][j]->getmadeira() >= 2 || zona[i][j + 1]->getmadeira() >= 2) {
                                            if (zona[i - 1][j]->getTipo() == "flr " &&
                                                zona[i - 1][j]->getmadeira() >= 2) {
                                                guardaI = i - 1;
                                                guardaJ = j;
                                            } else if (zona[i][j + 1]->getTipo() == "flr " &&
                                                       zona[i][j + 1]->getmadeira() >= 2) {
                                                guardaI = i;
                                                guardaJ = j + 1;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-2);
                                            setvigasMadeira(1);
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (j == c - 1 && i == 0) { // 3º Vertice
                                    if (zona[i][j - 1]->getTipo() == "flr " || zona[i + 1][j]->getTipo() == "flr ") {
                                        cout << "Encontrou - 3 Vertice" << endl;
                                        if (zona[i][j - 1]->getmadeira() >= 2 || zona[i + 1][j]->getmadeira() >= 2) {
                                            if (zona[i][j - 1]->getTipo() == "flr " &&
                                                zona[i][j - 1]->getmadeira() >= 2) {
                                                guardaI = i;
                                                guardaJ = j - 1;
                                            } else if (zona[i + 1][j]->getTipo() == "flr " &&
                                                       zona[i + 1][j]->getmadeira() >= 2) {
                                                guardaI = i + 1;
                                                guardaJ = j;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-2);
                                            setvigasMadeira(1);
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (j == c - 1 && i == l - 1) { // 4º Vertice
                                    if (zona[i][j - 1]->getTipo() == "flr " || zona[i - 1][j]->getTipo() == "flr ") {
                                        cout << "Encontrou - 4 Vertice" << endl;
                                        if (zona[i][j - 1]->getmadeira() >= 2 || zona[i - 1][j]->getmadeira() >= 2) {
                                            if (zona[i][j - 1]->getTipo() == "flr " &&
                                                zona[i][j - 1]->getmadeira() >= 2) {
                                                guardaI = i;
                                                guardaJ = j - 1;
                                            } else if (zona[i - 1][j]->getTipo() == "flr " &&
                                                       zona[i - 1][j]->getmadeira() >= 2) {
                                                guardaI = i - 1;
                                                guardaJ = j;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-2);
                                            setvigasMadeira(1);
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (i == 0 && j != 0 && j != c - 1) { // Ver a 1ª Linha -> i = 0
                                    if (zona[i + 1][j]->getTipo() == "flr " || zona[i][j - 1]->getTipo() == "flr " ||
                                        zona[i][j + 1]->getTipo() == "flr ") {
                                        cout << "Encontrou - 1ª Linha" << endl;
                                        if (zona[i + 1][j]->getmadeira() >= 2 || zona[i][j - 1]->getmadeira() >= 2 ||
                                            zona[i][j + 1]->getmadeira() >= 2) {

                                            if (zona[i + 1][j]->getTipo() == "flr " &&
                                                zona[i + 1][j]->getmadeira() >= 2) {
                                                guardaI = i + 1;
                                                guardaJ = j;
                                            } else if (zona[i][j - 1]->getTipo() == "flr " &&
                                                       zona[i][j - 1]->getmadeira() >= 2) {
                                                guardaI = i;
                                                guardaJ = j - 1;
                                            } else if (zona[i][j + 1]->getTipo() == "flr " &&
                                                       zona[i][j + 1]->getmadeira() >= 2) {
                                                guardaI = i;
                                                guardaJ = j + 1;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-2);
                                            setvigasMadeira(1);
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (i == l - 1 && j != 0 && j != c - 1) { // Ver a Ultima Linha -> l - 1
                                    if (zona[i - 1][j]->getTipo() == "flr " || zona[i][j - 1]->getTipo() == "flr " ||
                                        zona[i][j + 1]->getTipo() == "flr ") {
                                        cout << "Encontrou - Ultima Linha" << endl;
                                        if (zona[i - 1][j]->getmadeira() >= 2 || zona[i][j - 1]->getmadeira() >= 2 ||
                                            zona[i][j + 1]->getmadeira() >= 2) {

                                            if (zona[i - 1][j]->getTipo() == "flr " &&
                                                zona[i - 1][j]->getmadeira() >= 2) {
                                                guardaI = i - 1;
                                                guardaJ = j;
                                            } else if (zona[i][j - 1]->getTipo() == "flr " &&
                                                       zona[i][j - 1]->getmadeira() >= 2) {
                                                guardaI = i;
                                                guardaJ = j - 1;
                                            } else if (zona[i][j + 1]->getTipo() == "flr " &&
                                                       zona[i][j + 1]->getmadeira() >= 2) {
                                                guardaI = i;
                                                guardaJ = j + 1;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-2);
                                            setvigasMadeira(1);
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (j == 0 && i != 0 && i != l - 1) { // Ver a 1ª Coluna -> j = 0
                                    if (zona[i][j + 1]->getTipo() == "flr " || zona[i - 1][j]->getTipo() == "flr " ||
                                        zona[i + 1][j]->getTipo() == "flr ") {
                                        cout << "Encontrou - 1ª Coluna" << endl;
                                        if (zona[i][j + 1]->getmadeira() >= 2 || zona[i - 1][j]->getmadeira() >= 2 ||
                                            zona[i + 1][j]->getmadeira() >= 2) {

                                            if (zona[i][j + 1]->getTipo() == "flr " &&
                                                zona[i][j + 1]->getmadeira() >= 2) {
                                                guardaI = i;
                                                guardaJ = j + 1;
                                            } else if (zona[i - 1][j]->getTipo() == "flr " &&
                                                       zona[i - 1][j]->getmadeira() >= 2) {
                                                guardaI = i - 1;
                                                guardaJ = j;
                                            } else if (zona[i + 1][j]->getTipo() == "flr " &&
                                                       zona[i + 1][j]->getmadeira() >= 2) {
                                                guardaI = i + 1;
                                                guardaJ = j;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-2);
                                            setvigasMadeira(1);
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else if (j == c - 1 && i != 0 && i != l - 1) { // Ver a Ultima Coluna -> c - 1
                                    if (zona[i][j - 1]->getTipo() == "flr " || zona[i - 1][j]->getTipo() == "flr " ||
                                        zona[i + 1][j]->getTipo() == "flr ") {
                                        cout << "Encontrou - ultima Coluna" << endl;
                                        if (zona[i][j - 1]->getmadeira() >= 2 || zona[i - 1][j]->getmadeira() >= 2 ||
                                            zona[i + 1][j]->getmadeira() >= 2) {

                                            if (zona[i][j - 1]->getTipo() == "flr " &&
                                                zona[i][j - 1]->getmadeira() >= 2) {
                                                guardaI = i;
                                                guardaJ = j - 1;
                                            } else if (zona[i - 1][j]->getTipo() == "flr " &&
                                                       zona[i - 1][j]->getmadeira() >= 2) {
                                                guardaI = i - 1;
                                                guardaJ = j;
                                            } else if (zona[i + 1][j]->getTipo() == "flr " &&
                                                       zona[i + 1][j]->getmadeira() >= 2) {
                                                guardaI = i + 1;
                                                guardaJ = j;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-2);
                                            setvigasMadeira(1);
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                } else {// Se nao estou em nenhuma das anteriores, ent estou no meio da ilha
                                    if (zona[i - 1][j]->getTipo() == "flr " || zona[i + 1][j]->getTipo() == "flr " ||
                                        zona[i][j - 1]->getTipo() == "flr " || zona[i][j + 1]->getTipo() == "flr ") {
                                        cout << "Encontrou - no Meio" << endl;
                                        if (zona[i - 1][j]->getmadeira() >= 2 || zona[i + 1][j]->getmadeira() >= 2 ||
                                            zona[i][j - 1]->getmadeira() >= 2 || zona[i][j + 1]->getmadeira() >= 2) {

                                            if (zona[i - 1][j]->getTipo() == "flr " &&
                                                zona[i - 1][j]->getmadeira() >= 2) {
                                                guardaI = i - 1;
                                                guardaJ = j;
                                            } else if (zona[i + 1][j]->getTipo() == "flr " &&
                                                       zona[i + 1][j]->getmadeira() >= 2) {
                                                guardaI = i + 1;
                                                guardaJ = j;
                                            } else if (zona[i][j - 1]->getTipo() == "flr " &&
                                                       zona[i][j - 1]->getmadeira() >= 2) {
                                                guardaI = i;
                                                guardaJ = j - 1;
                                            } else if (zona[i][j + 1]->getTipo() == "flr " &&
                                                       zona[i][j + 1]->getmadeira() >= 2) {
                                                guardaI = i;
                                                guardaJ = j + 1;
                                            }
                                            zona[guardaI][guardaJ]->setmadeira(-2);
                                            setvigasMadeira(1);
                                        }
                                        break;
                                    } else
                                        cout << "Não há nenhuma zona \"Floresta\" adjacente à Central Eletrica" << endl;
                                }

                            }
                        }

                    }

                    /*zona[0][0]->edificio->setnivel(1); //minaf
                zona[1][1]->edificio->setnivel(2); //minac
                cout << "NIVEL MINAF: " << zona[0][0]->edificio->getnivel();
                cout << "NIVEL MINAC: " << zona[1][1]->edificio->getnivel();*/

            }else
                flagEdiLigado = 1;
            }
        }
    }

    if(flagEdiLigado == 1)
        cout << "\n[AVISO]: Verifique se os edificios estão ligados para poderem produzir recursos!\n" << endl;
}

void ilhas::anoitecer(int l, int c, ilhas &ilha) {

    totalMadeira = 0;
    totalBarraAco = 0;
    totalEletricidade = 0;
    totalFerro = 0;
    totalCarvao = 0;


    for(int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {

            //ZONA FLORESTA
            if (zona[i][j]->getTipo() == "flr ")
                    totalMadeira += zona[i][j]->getmadeira();

            //ZONA MONTANHA
            if (zona[i][j]->getTipo() == "mnt ")
                totalFerro += zona[i][j]->getferro();

            if(zona[i][j]->edificio != nullptr) {
                //EDIFICIO MINA DE FERRO
                if (zona[i][j]->edificio->nomeEdificio == "mnF ")
                    totalFerro += zona[i][j]->edificio->getferro();

                //EIFICIO MINA DE CARVAO
                if (zona[i][j]->edificio->nomeEdificio == "mnC ")
                    totalCarvao += zona[i][j]->edificio->getcarvao();

                //EDIFICIO CENTRAL ELETRICA
                if (zona[i][j]->edificio->nomeEdificio == "elec") {
                    totalCarvao += zona[i][j]->edificio->getcarvaoCE();
                    zona[i][j]->edificio->setproduziu(false);
                }

                //EDIFICIO BATERIA
                if (zona[i][j]->edificio->nomeEdificio == "bat ")
                    totalEletricidade += zona[i][j]->edificio->geteletricidadeB();

                //EDIFICIO FUNDICAO
                if (zona[i][j]->edificio->nomeEdificio == "fun ")
                    totalBarraAco += zona[i][j]->edificio->getbarraAco();

            }
            for (int z = 0; z < ilha.zona[i][j]->trabalhador.size(); z++) {
                ilha.zona[i][j]->trabalhador[z]->setmoveu(false);
            }

        }
        /*if (flag == 1) {
        varAux = totalMadeira;
        }*/
    }

    cout << "Qauntidade de Barras de Aco: " << totalBarraAco << " kg" << endl;
    cout << "Qauntidade de Eletricidade: " << totalEletricidade << " KWh" << endl;
    cout << "Qauntidade de Carvao: " << totalCarvao << " Kg" << endl;
    cout << "Qauntidade de Ferro: " << totalFerro  << " Kg" << endl;
    cout << "Qauntidade de Madeira: " << totalMadeira << " Kg" << endl;

    //NOTA: SO PRODUZ SE O EDIFICIO RESPETIVO ESTIVER LIGADO

}

int ilhas::fimDoJogo(int l, int c) {

    int total = 0;
    for(int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            total += zona[i][j]->gettotalTrabalhadores();
        }
    }

    if(total == 0 && totalMadeira == 0 && totalCarvao == 0 && totalFerro == 0 && totalBarraAco == 0 && totalEletricidade == 0 && vigasMadeira == 0 && dinheiro == 0){
        cout << "Você perdeu"<< endl;
        cout << "Acabou o Jogo com: "<< endl;
        cout << dinheiro << " euros" << endl;
        cout << totalBarraAco << " kg" << endl;
        cout << totalEletricidade << " KWh" << endl;
        cout << totalCarvao << " Kg" << endl;
        cout << totalFerro  << " Kg" << endl;
        cout << totalMadeira << " Kg" << endl;
        return 0;
    }
    return 1;
}

void ilhas::setdinheiro(float num) {
    dinheiro = dinheiro + num;
}

float ilhas::getdinheiro() {
    return dinheiro;
}

void ilhas::setvigasMadeira(int num) {
    vigasMadeira = vigasMadeira + num;
}

int ilhas::getvigasMadeira() {
    return vigasMadeira;
}