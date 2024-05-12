#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include "Masa.h"
#include "DataBase.h"

void red();
void green();
void reset();
void arrowHere(int, int);
void space();
void menuUser(Database);
void cautare(Database);
void anulare(Database);
void cautareMasa(Database);
void cautareR(Database);
void menuAdmin(Database);
void makeRezervare(Database);
void stergereMese(Database);
void afisareRezervari(Database);
bool validareData(std::string);

void red() {
    printf("\033[1;31m");
}
void reset() {
    printf("\033[0m");
}
void green() {
    printf("\033[0;32m");
}

int main(int argc, char* argv[]) {
    Database d, d2;
    Masa q;
    std::string filename = "rezervari.txt";
    std::ifstream fin(filename.c_str());
    d.load(fin);
    fin.close();
    std::vector<std::string> argument;
    std::string data;
    for(size_t i = 1; i < argc; i++)
    {
        argument.push_back(std::string(argv[i]));
    }
/*
    if (argument[1] == "-add") {
        int capacitate(std::stoi(argv[2]));
        std::string data(argv[3]);
        if(validareData(data) == true) {
            std::string codF(argv[4]);
            d.add(capacitate, data, codF);
            std::ofstream fout(filename.c_str());
            d.save(fout);
            fout.close();
            green();
            std::cout << "\nMasa a fost adaugata cu succes!\n";
            reset();
            std::ifstream fin(filename.c_str());
            d.load(fin);
            fin.close();
        }
        else{
            red();std::cout<<"Data introdusa nu este valida\n";
            reset();
        }
    } else if (argument[1] == "-delete") {
        d.sterge(std::stoi(argv[2]));
        std::ofstream fout(filename.c_str());
        d.save(fout);
        fout.close();
        std::ifstream fin(filename.c_str());
        d.load(fin);
        fin.close();
        green();
        std::cout << "\nMasa a fost stearsa cu succes!\n";
        reset();
    } else if (argument[1] == "-searchMasa") {
        if(d.search2(std::stoi(argv[2])) == 1){
            green();
            std::cout<<"Masa a fost gasita\n";
            reset();
        }
    } else if (argument[1] == "-print") {
        std::cout<<d;
    } else if (argument[1] == "-help") {
        std::cout << "Comenzile disponibile sunt: -add, -delete, -searchMasa, -print, -help si -menu\n\n";
        std::cout << "Comanda -add, trebuie urmata de numarul de persoane dorit, de data pe care se face rezervarea si de un cod utilizat in momentul anularii rezervarii. Un exemplu de utilizare: pp -add 2 27/07 1234\n";
        std::cout << "Comanda -delete, trebuie urmata de capacitatea mesei pe care doriti sa o stergeti. Un exemplu de utilizare: pp -delete 4\n";
        std::cout << "Comanda -anulare, trebuie urmata de codul rezervarii pe care doriti sa o stergeti. Un exemplu de utilizare: pp -anulare 12345\n";
        std::cout << "Comanda -searchMasa, trebuie urmata de capacitatea mesei pe care doriti sa o cautati. Un exemplu de utilizare: pp -searchMasa 5\n";
        std::cout << "Comanda -searchRezervare, trebuie urmata de codul rezervarii pe care doriti sa o cautati. Un exemplu de utilizare: pp -searchMasa %A#SQ\n\n";
        std::cout << "Comanda -print, afiseaza multimea de rezervari deja stocate in baza de date. Un exemplu de utilizare: pp -print\n\n";
        std::cout << "Coamanda -help afiseaza comenzile implementate si modul cum pot fi utilizate\n\n";
        std::cout << "Comanda -menu ofera interfata grafica in cazul in care nu se doreste utilizarea comenzilor din linia de comanda\n\n\n";
    } else if (argument[1] == "-menu") {
        menuUser(d);
    } else if (argument[1] == "-searchRezervare") {
        if(d.searchCod(argv[2]) == 1) {
            green();
            std::cout << "Rezervarea a fost gasita\n";
            reset();
        }
        else {
            red();
            std::cout << "Rezervarea cautata nu exista";
            reset();
        }
    }
    else if (argument[1] == "-anulare") {
        d.stergeCod(argv[2]);
        std::ofstream fout(filename.c_str());
        d.save(fout);
        fout.close();
        std::ifstream fin(filename.c_str());
        d.load(fin);
        fin.close();
        green();
        std::cout << "\nRezervarea a fost stearsa cu succes\n";
        reset();
    }
    else if (argument[1] == "-test") {
        std::cout<<argv[2];
    }
    */
menuUser(d);
    return 0;
}
void space() {
    std::cout<<"   ";
}
void arrowHere(int position, int arrowPosition) {
    if (position == arrowPosition) {
        std::cout<<"-->";
    }
    else {
        std::cout<<"   ";
    }
}
void menuUser(Database d){
    system("cls");
    int position = 1;
    int keyPressed = 0;
    int admin = 0;
    while(keyPressed != 13){
        system("cls");
        space();std::cout<<"+------------------------------------------+\n";
        space();std::cout<<"|              REZERVARE MESE              |\n";
        space();std::cout<<"+------------------------------------------+\n";
        arrowHere(1,position); std::cout<<"|1.Cautati o masa / o rezervare            |\n";
        space();std::cout<<"+------------------------------------------+\n";
        arrowHere(2, position); std::cout<<"|2.Rezervati o masa                        |\n";
        space();std::cout<<"+------------------------------------------+\n";
        arrowHere(3, position); std::cout<<"|3.Accesati meniu administrator            |\n";
        space();std::cout<<"+------------------------------------------+\n";
        arrowHere(4, position); std::cout<<"|4.Vizualizare rezervari                   |\n";
        space();std::cout<<"+------------------------------------------+\n";
        arrowHere(5, position); std::cout<<"|5.Anulati o rezervare                     |\n";
        space();std::cout<<"+------------------------------------------+\n";
        arrowHere(6, position); std::cout<<"|6.Inapoi                                  |\n";
        space();std::cout<<"+------------------------------------------+\n";
        keyPressed = getch();

        if (keyPressed == 80 && position != 6) position++;
        else if (keyPressed == 72 && position != 1) position--;
        else if (keyPressed == 64) { position = position; admin = 1; }
        else if (keyPressed == 72 && position == 1) position = 6;
        else if (keyPressed == 80 && position == 6) position = 1;
        else position = position;
    }
    switch (position) {
        case 1:
            cautare(d);
            break;
        case 2:
            makeRezervare(d);
            break;
        case 3: if (admin == 1) menuAdmin(d);
            else menuUser(d);
            break;
        case 4:
            afisareRezervari(d);
            break;
        case 5:
            anulare(d);
            break;
        case 6:
            exit(0);
    }
}
void cautare(Database d){
    system("cls");
    int position = 1;
    int keyPressed = 0;
    int admin = 0;
    while(keyPressed != 13){
        system("cls");
        space();std::cout<<"+------------------------------------------+\n";
        space();std::cout<<"|              REZERVARE MESE              |\n";
        space();std::cout<<"+------------------------------------------+\n";
        arrowHere(1, position);std::cout<<"|1.Cautati o masa                          |\n";
        space();std::cout<<"+------------------------------------------+\n";
        arrowHere(2,position);std::cout<<"|2.Cautati o rezervare                     |\n";
        space();std::cout<<"+------------------------------------------+\n";

        keyPressed = getch();
        if (keyPressed == 80 && position != 2) position++;
        else if (keyPressed == 72 && position != 1) position--;
        else if (keyPressed == 72 && position == 1) position = 2;
        else if (keyPressed == 80 && position == 2) position = 1;
        else position = position;
    }
    switch (position) {
        case 1:
            cautareMasa(d);
            break;
        case 2:
            cautareR(d);
            break;
    }
}
void cautareMasa(Database d){
    int cap;
    int i = 0;
    int keyPressed = 0;
    int position = 1;
    system("cls");
    space();std::cout<<"+------------------------------------------+\n";
    space();std::cout<<"|              REZERVARE MESE              |\n";
    space();std::cout<<"+------------------------------------------+\n";
    space();std::cout<<"|1.Introduceti capacitatea mesei cautate|"; arrowHere(1, position);std::cin>>cap;
    if(d.search2(cap) == true){
        system("cls");
        space();std::cout<<"+------------------------------------------+\n";
        space();std::cout<<"|              REZERVARE MESE              |\n";
        space();std::cout<<"+------------------------------------------+\n";
        green();
        space();std::cout<<"|Masa este disponibila                     |\n";
        reset();
        space();std::cout<<"+------------------------------------------+\n";
        arrowHere(1, position); std::cout<<"|1.Inapoi                                   |\n";
        space();std::cout<<"+------------------------------------------+\n";
        keyPressed = getch();
        if(keyPressed == 13) menuUser(d);
    }
    else{
        system("cls");
        space();std::cout<<"+------------------------------------------+\n";
        space();std::cout<<"|              REZERVARE MESE              |\n";
        space();std::cout<<"+------------------------------------------+\n";
        red();
        space();std::cout<<"|Masa nu este disponibila                  |\n";
        reset();
        space();std::cout<<"+------------------------------------------+\n";
        arrowHere(1, position); std::cout<<"|1.Inapoi                                   |\n";
        space();std::cout<<"+------------------------------------------+\n";
        keyPressed = getch();
        if(keyPressed == 13) menuUser(d);
    }
}
void cautareR(Database d){
    std::string cod;
    int i = 0;
    int keyPressed = 0;
    int position = 1;
    system("cls");
    space();std::cout<<"+------------------------------------------+\n";
    space();std::cout<<"|              REZERVARE MESE              |\n";
    space();std::cout<<"+------------------------------------------+\n";
    space();std::cout<<"|1.Introduceti codul rezervarii cautate|";arrowHere(1, position); std::cin>>cod;
    if(d.searchCod(cod) == 1){
        system("cls");
        space();std::cout<<"+------------------------------------------+\n";
        space();std::cout<<"|              REZERVARE MESE              |\n";
        space();std::cout<<"+------------------------------------------+\n";
        green();
        space();std::cout<<"|Rezervarea este valida                    |\n";
        reset();
        space();std::cout<<"+------------------------------------------+\n";
        arrowHere(1,position);std::cout<<"|1.Inapoi                                   |\n";
        space();std::cout<<"+------------------------------------------+\n";
        keyPressed = getch();
        if(keyPressed == 13) menuUser(d);
    }
    else{
        system("cls");
        space();std::cout<<"+------------------------------------------+\n";
        space();std::cout<<"|              REZERVARE MESE              |\n";
        space();std::cout<<"+------------------------------------------+\n";
        red();
        space();std::cout<<"|Rezervarea nu a fost gasita               |\n";
        reset();
        space();std::cout<<"+------------------------------------------+\n";
        arrowHere(1,position);std::cout<<"|1.Inapoi                                   |\n";
        space();std::cout<<"+------------------------------------------+\n";
        keyPressed = getch();
        if(keyPressed == 13) menuUser(d);
    }
}
void afisareRezervari(Database d){
    int position = 1;
    int keyPressed = 0;
    d.afisare2();
    keyPressed = getch();
    if(keyPressed == 13) menuUser(d);
}
void makeRezervare(Database d){
    std::string filename = "rezervari.txt";
    int position = 1, zi, luna;
    int keyPressed = 0;
    int admin = 0;
    int nr = 0;
    int capacitate;
    std::string data="";
    std::string cod;
    while(keyPressed != 13){
        system("cls");
        space();std::cout<<"+------------------------------------------+\n";
        space();std::cout<<"|              REZERVARE MESE              |\n";
        space();std::cout<<"+------------------------------------------+\n";
        space();std::cout<<"|1.Introduceti capacitatea dorita|"; arrowHere(1, position);std::cin>>capacitate;
        do{
            system("cls");
            space();std::cout<<"+------------------------------------------+\n";
            space();std::cout<<"|              REZERVARE MESE              |\n";
            space();std::cout<<"+------------------------------------------+\n";
            if(capacitate < 9) {
                space();std::cout << "|1.Introduceti capacitatea dorita| ";space();std::cout<<capacitate<<"    |\n";
                space();std::cout<<"+------------------------------------------+\n";
            }
            else{
                space();std::cout << "|1.Introduceti capacitatea dorita| ";space();std::cout<<capacitate<<"   |\n";
                space();std::cout<<"+------------------------------------------+\n";
            }
        }while(0);
        space();std::cout<<"Formatul datei de rezervare este ZZ LL         |\n";
        space();std::cout<<"+----------------------------------------------+\n";
        space();std::cout<<"|2.Introduceti intervalul orar|"; arrowHere(1, position);std::cin>>zi>>luna;
        if(zi<1 || zi>31 || luna<1 || luna>12){
            system("cls");
            space();std::cout<<"+------------------------------------------+\n";
            space();std::cout<<"|              REZERVARE MESE              |\n";
            space();std::cout<<"+------------------------------------------+\n";
            space();red();std::cout<<"|Data introdusa nu este valida             |\n";reset();
            space();std::cout<<"+------------------------------------------+\n";
            arrowHere(1, position); std::cout<<"|1.Inapoi                                  |\n";
            space();std::cout<<"+------------------------------------------+\n";
            keyPressed = getch();
            if(keyPressed == 13)menuUser(d);
        }
        if(zi<10){
            data = data + "0" + std::to_string(zi) + "/";
        }
        else
            data = data + std::to_string(zi) + "/";
        if(luna<10){
            data = data + "0" + std::to_string(luna);
        }
        else
            data = data + std::to_string(luna);
        do{
            system("cls");
            space();std::cout<<"+------------------------------------------+\n";
            space();std::cout<<"|              REZERVARE MESE              |\n";
            space();std::cout<<"+------------------------------------------+\n";
            space();std::cout <<"|1.Introduceti capacitatea dorita| ";space();std::cout<<capacitate<<"    |\n";
            space();std::cout<<"+------------------------------------------+\n";
            space();std::cout<<"|2.Introduceti intervalul orar|"; std::cout<<data<<"\n";
            space();std::cout<<"+------------------------------------------+\n";
        }while(0);
        space();std::cout<<"|Codul de verificare e format din 5 simboluri  \n";
        space();std::cout<<"+------------------------------------------+\n";
        space();std::cout<<"|3.Introduceti codul de verificare|";arrowHere(1, position);std::cin>>cod;
        if(cod.size()>5){
            system("cls");
            space();std::cout<<"+------------------------------------------+\n";
            space();std::cout<<"|              REZERVARE MESE              |\n";
            space();std::cout<<"+------------------------------------------+\n";
            space();red();std::cout<<"|Codul de verificare introdus nu este valid|\n";reset();
            space();std::cout<<"+------------------------------------------+\n";
            arrowHere(1, position); std::cout<<"|1.Inapoi                                  |\n";
            space();std::cout<<"+------------------------------------------+\n";
            keyPressed = getch();
            if(keyPressed == 13)menuUser(d);
        }
        do{
            system("cls");
            space();std::cout<<"+------------------------------------------+\n";
            space();std::cout<<"|              REZERVARE MESE              |\n";
            space();std::cout<<"+------------------------------------------+\n";
            space();std::cout <<"|1.Introduceti capacitatea dorita| ";space();std::cout<<capacitate<<"    |\n";
            space();std::cout<<"+------------------------------------------+\n";
            space();std::cout<<"|2.Introduceti intervalul orar|"; std::cout<<data<<"    \n";
            space();std::cout<<"+------------------------------------------+\n";
            space();std::cout<<"|3.Introduceti codul de verificare|"; std::cout<<data<<"    \n";
            space();std::cout<<"+------------------------------------------+\n"; position = position +3;
            arrowHere(4, position);std::cout<<"|4.Inapoi                                  |\n";
            space();std::cout<<"+------------------------------------------+\n";
            d.add(capacitate,data, cod);
            space(); green(); std::cout<<"Rezervare a fost realizata cu succes, va multumim";
            reset();
            std::ofstream fout(filename.c_str());
            d.save(fout);
            fout.close();
            std::ifstream fin(filename.c_str());
            d.load(fin);
            fin.close();
            keyPressed = getch();
            if(keyPressed == 13) menuUser(d);
        }while(0);
    }
}
void anulare(Database d){
    int i, j;
    std::string filename = "rezervari.txt";
    int keyPressed = 0;
    int position = 1;
    std::string cod;
    system("cls");
    space();std::cout<<"+------------------------------------------+\n";
    space();std::cout<<"|              REZERVARE MESE              |\n";
    space();std::cout<<"+------------------------------------------+\n";
    space();std::cout<<"|1.Introduceti codul rezervarii cautate|";arrowHere(1, position);std::cin>>cod;
    system("cls");
    if(d.searchCod(cod) == 0) {
        while (keyPressed != 13) {
            system("cls");
            space();
            std::cout << "+------------------------------------------+\n";
            space();
            std::cout << "|              REZERVARE MESE              |\n";
            space();
            std::cout << "+------------------------------------------+\n";
            space();
            red();
            std::cout << "|Rezervarea cu codul introdus nu exista    |\n";
            reset();
            space();
            std::cout << "+------------------------------------------+\n";
            arrowHere(1, position);
            std::cout << "|1.Inapoi                                  |\n";
            space();
            std::cout << "+------------------------------------------+\n";
            keyPressed = getch();
            std::ofstream fout(filename.c_str());
            d.save(fout);
            fout.close();
            std::ifstream fin(filename.c_str());
            d.load(fin);
            fin.close();
            if (keyPressed == 13) menuUser(d);
        }
    }
        else{
            d.stergeCod(cod);
            while(keyPressed !=13) {
                system("cls");
                space();
                std::cout << "+------------------------------------------+\n";
                space();
                std::cout << "|              REZERVARE MESE              |\n";
                space();
                std::cout << "+------------------------------------------+\n";
                space();
                green();
                std::cout << "|Rezervarea cu codul introdus a fost anulat|\n";
                reset();
                space();
                std::cout << "+------------------------------------------+\n";
                arrowHere(1, position);
                std::cout << "|1.Inapoi                                  |\n";
                space();
                std::cout << "+------------------------------------------+\n";
                keyPressed = getch();
                std::ofstream fout(filename.c_str());
                d.save(fout);
                fout.close();
                std::ifstream fin(filename.c_str());
                d.load(fin);
                fin.close();
                if (keyPressed == 13) menuUser(d);
            }
        }
    }
void menuAdmin(Database d){
    system("cls");
    int position = 1;
    int keyPressed = 0;
    int user = 1;
    while (keyPressed != 13) {
        system("cls");
        space(); printf("+------------------------------------------+\n");
        space(); printf("|            MENIU ADMINISTRATIE           |\n");
        space(); printf("+------------------------------------------+\n");
        arrowHere(1, position); printf("|1.Vizualizare rezervari                   |\n");
        space(); printf("+------------------------------------------+\n");
        arrowHere(2, position); printf("|2.Rezervati o masa                        |\n");
        space(); printf("+------------------------------------------+\n");
        arrowHere(3, position); printf("|3.Anularea unei rezervari                 |\n");
        space(); printf("+------------------------------------------+\n");
        arrowHere(5, position); printf("|4.Stergere masa                           |\n");
        space(); printf("+------------------------------------------+\n");
        arrowHere(6, position); printf("|5.Cautarea unei mese / unei rezervari     |\n");
        space(); printf("+------------------------------------------+\n");
        arrowHere(7, position); printf("|6.Inapoi                                  |\n");
        space(); printf("+------------------------------------------+\n");
        keyPressed = _getch();


        if (keyPressed == 80 && position != 7) position++;
        else if (keyPressed == 72 && position != 1) position--;
        else if (keyPressed == 80 && position == 7) position = 1;
        else if (keyPressed == 72 && position == 1) position = 7;
        else position = position;
    }
    printf("%d", position);
    switch (position) {
        case 1:
            afisareRezervari(d);
            break;
        case 2:
            makeRezervare(d);
            break;
        case 3:
            anulare(d);
            break;
            break;
        case 4:
            stergereMese(d);
            break;
        case 5:
            cautare(d);
            break;
        case 6:
            menuUser(d);
            break;
    }
}
void stergereMese(Database d){
    int i, j;
    std::string filename = "rezervari.txt";
    int keyPressed = 0;
    int position = 1;
    int capacitate;
    system("cls");
    space();std::cout<<"+------------------------------------------+\n";
    space();std::cout<<"|              REZERVARE MESE              |\n";
    space();std::cout<<"+------------------------------------------+\n";
    space();std::cout<<"|1.Introduceti capacitatea mesei eliminate |";arrowHere(1, position);std::cin>>capacitate;
    system("cls");
    if(d.search(capacitate) == 0){
        while(keyPressed !=13) {
            system("cls");
            space();
            std::cout << "+---------------------------------------------+\n";
            space();
            std::cout << "|               REZERVARE MESE                |\n";
            space();
            std::cout << "+---------------------------------------------+\n";
            space();
            red();
            std::cout << "|Rezervarea cu capacitatea introdusa nu exista|\n";
            reset();
            space();
            std::cout << "+---------------------------------------------+\n";
            arrowHere(1, position);
            std::cout << "|1.Inapoi                                     |\n";
            space();
            std::cout << "+---------------------------------------------+\n";
            keyPressed = getch();
            std::ofstream fout(filename.c_str());
            d.save(fout);
            fout.close();
            std::ifstream fin(filename.c_str());
            d.load(fin);
            fin.close();
            if (keyPressed == 13) menuUser(d);
        }
    }
    if(d.search(capacitate) == 1){
        while(keyPressed !=13) {
            system("cls");
            space();
            std::cout << "+--------------------------------------------------+\n";
            space();
            std::cout << "|                  REZERVARE MESE                  |\n";
            space();
            std::cout << "+--------------------------------------------------+\n";
            space();
            green();
            std::cout << "|Rezervarea cu capacitatea introdusa a fost stearsa|\n";
            reset();
            space();
            std::cout << "+--------------------------------------------------+\n";
            arrowHere(1, position);
            std::cout << "|1.Inapoi                                          |\n";
            space();
            std::cout << "+--------------------------------------------------+\n";
            keyPressed = getch();
            std::ofstream fout(filename.c_str());
            d.save(fout);
            fout.close();
            std::ifstream fin(filename.c_str());
            d.load(fin);
            fin.close();
            if (keyPressed == 13) menuUser(d);
        }
    }
}
bool validareData(std::string s){
    std::string zi, luna;
    int z, l;
    int ok = 1;
    zi = zi + *(s.begin());
    zi = zi + *(s.begin()+1);
    luna = luna + *(s.begin()+3);
    luna = luna + *(s.begin()+4);
    z = stoi(zi);
    l = stoi(luna);
    if(l<1 || l>12){
        ok = 0;
    }
    else if(l == 1 || l == 3 || l == 5 || l == 7 || l == 8 || l == 10 || l == 12){
        if(z < 0 || z > 31)
            ok = 0;
    }
    else if(l == 4 || l == 6 || l == 9 || l == 11) {
        if (z < 0 || z > 30)
            ok = 0;
    }
    else if(l == 2){
        if(z < 0 || z>29)
            ok = 0;
    }
    if(ok == 1)
        return true;
    else return false;
}
