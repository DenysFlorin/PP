//
// Created by denys on 19.05.2023.
//


#include "DataBase.h"

Database::Database() = default;


Database::Database(const Database &database) {
    m_date = database.m_date;
}

bool Database::search(int capacitate) {
    bool found = false;
    for(auto &m : m_date){
        if(m.getCapacitate() == capacitate){
            std::cout << "Masa a fost gasita!\n";
            m.output(std::cout);
            found = true;
        }
    }
    if(found){
        return true;
    }
    else{
        return false;
    }
}

void Database::add(int capacitate, const std::string& data,  const std::string& cod) {
    bool ok = false;
    for(int i = 0; i < m_date.size() && !ok; i++){
        if(capacitate == m_date[i].getCapacitate()){
            ok = true;
            std::vector<Rezervare> R = m_date[i].getRezervari();
            R.emplace_back(data, cod);
            m_date[i].setRezervari(R);
        }
    }
    if(!ok){
        std::vector<Rezervare> R;
        R.emplace_back(data, cod);
        m_date.emplace_back(capacitate, R);
    }
}

void Database::addload(Masa m) {
    bool ok = false;
    for(int i = 0; i < m_date.size() && !ok; i++){
        if(m_date[i].getCapacitate() == m.getCapacitate()){
            ok = true;
            std::vector<Rezervare> R = m_date[i].getRezervari();
            R.push_back(m.getRezervari()[0]);
        }
    }
    if(!ok){
        m_date.push_back(m);
    }
}

void Database :: afisare(){
    system("cls");
    std::cout << "    "; std::cout << "+-------------------------------------------------------------------+\n";
    for(int i = 0; i < m_date.size(); i++){
        std::cout << "    "; std::cout<<"| Table "<<i<<" | Capacitate: "<< m_date[i].getCapacitate()<<" | Masa este rezervata pentru datele:";
        for(int j = 0; j < m_date[i].getRezervari().size();j++){
            std::cout << m_date[i].getRezervari()[j].getData()<< " | ";
        }
        std::cout << "\n";
    }
    std::cout << "    "; std::cout << "+-------------------------------------------------------------------+\n";
}

void Database::sterge(int capacitate) {
    for(int i = 0; i < m_date.size(); i++){
        if(m_date[i].getCapacitate() == capacitate){
            m_date.erase(m_date.begin() + i);
            std::cout << "Masa a fost stearsă cu succes\n";
            return;
        }
    }
}

void Database::stergeCod(const std::string& cod) {
    for(int i = 0; i < m_date.size(); i++){
        for(int j = 0; j < m_date[i].getRezervari().size(); j++){
            if(m_date[i].getRezervari()[j].getCod() == cod){
                std::vector<Rezervare> R = m_date[i].getRezervari();
                R.erase(R.begin() + j);
                if(R.empty()){
                    m_date.erase(m_date.begin() + i);
                }
                else
                    m_date[i].setRezervari(R);
                return;
            }
        }
    }
}

void Database::save(std::ostream &out) {
    for(int i = 0; i < m_date.size(); i++){
        out << m_date[i].getCapacitate() << ",";
        for(int j = 0; j < m_date[i].getRezervari().size(); j++){
            out << m_date[i].getRezervari()[j].getData() << "-" << m_date[i].getRezervari()[j].getCod()<<",";
        }
        out << "\n";
    }
}

void Database :: load(std::istream& in){
    std::string delim = ",";
    std::string line;
    std::string data;
    int pos = 0;
    int pos2 = 0;
    std::string r;
    std::string cod;
    Rezervare l;
    while (getline(in, line)) {
        int index = 0, capacitate = 0;
        std::vector<Rezervare> rezervari;
        int c = 0;
        while ((pos = line.find(delim)) != std::string::npos) {
            data = line.substr(0, pos);
            if(c == 0) {
                capacitate = stoi(data);
                c++;
            }
            else{
                //rezervari.push_back(data);
                pos2 = data.find("-");
                r = data.substr(0,pos2);
                data.erase(0,pos2+1);
                pos2 = data.find(",");
                cod = data.substr(0, pos2);
                data.erase(0,pos2+1);
                l.setCod(cod);
                l.setData(r);
                rezervari.push_back(l);
            }
            line.erase(0,pos + delim.length());  /* erase() function store the current positon and move to next token. */
        }
        Masa m(capacitate, rezervari);
        this->addload(m);
    }
}

bool Database::search2(int capacitate) {
    for (auto i: m_date)
        if (i.getCapacitate() == capacitate) {
            return true;
        }
    return false;
}

bool Database::searchCod(const std::string& cod) {
    for(auto i : m_date){
        for(auto j : i.getRezervari()){
            if(j.getCod() == cod){
                return true;
            }
        }
    }
    return false;
}

std::vector<Masa> Database::getDate() {
    return m_date;
}

void Database::afisare2(){
    system("cls");
    int max = 0;
    int l = 0;
    int ok = 0;
    int s = 0;
    for(int i = 0; i < m_date.size(); i++){
        if(max < m_date[i].getRezervari().size())
            max = m_date[i].getRezervari().size();
    }
    std::cout << "    "; std::cout << "+-----------------------------------------------------------------";
    for(int k = 0; k < max; k++)
        std::cout << "------";
    std::cout << "-+\n";
    for(int i = 0; i < m_date.size(); i++){
        l = 0; ok = 0, s = 0;
        std::cout<<"    "; std::cout << "| Table "<< i <<" | Capacitate: " << m_date[i].getCapacitate() << " | Masa este rezervata pentru datele:";
        for(int j = 0; j < m_date[i].getRezervari().size(); j++){
            std::cout << " " << m_date[i].getRezervari()[j].getData()<< " |";
            l++;
        }
        if(l!=max) {
            int s = max*8 - l*8 - 1;
            while (l != max) {
                std::cout << "       ";
                l++;
                s = s - 7;
            }
            if(s!=0){
                while(s!=0) {
                    std::cout << " ";
                    s--;
                }
            }
            std::cout << "|\n";
        }
        else
            std::cout << "\n";
    }
    std::cout<<"    "; std::cout<<"+-----------------------------------------------------------------";
    for(int k = 0; k < max; k++)
        std::cout<<"------";
    std::cout<<"-+\n";
}

std::ostream &operator<<(std::ostream &out, Database &D) {
    D.afisare2();
    return out;
}










