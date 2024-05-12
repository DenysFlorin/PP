//
// Created by denys on 5/11/2024.
//

#include "Masa.h"

Masa::Masa() {
    m_capacitate = 0;
}

Masa::Masa(int capacitate, std::vector<Rezervare>& rezervari) {
    m_capacitate = capacitate;
    m_rezervari = rezervari;
}

Masa::Masa(const Masa &masa) {
    m_capacitate = masa.m_capacitate;
    m_rezervari = masa.m_rezervari;
}

int Masa::getCapacitate() const {
    return m_capacitate;
}

std::vector<Rezervare> Masa::getRezervari() {
    return m_rezervari;
}

void Masa::setCapacitate(int capacitate) {
    m_capacitate = capacitate;
}

void Masa::setRezervari(std::vector<Rezervare>& rezervari) {
    m_rezervari = rezervari;
}

void Masa::input(std::istream &in) {
    if(in.fail() == std::cin.fail()){
        if(in.peek() == '\n')
            in.ignore();
        std::cout<<"\n"<<"Capacitate:";
        in >> m_capacitate;
    }
    else{
        if(in.peek() == '\n')
            in.ignore();
        in >> m_capacitate;
    }
}

void Masa::output(std::ostream &out) {
    if(out.fail() == std::cout.fail()){
        out << "| Masa cu" << " | "<< "Capacitate: "<< m_capacitate<<" |";
    }
    else{
        out << m_capacitate;
        for(auto & i : m_rezervari){
            out << "," << i.getData();
        }
        std::cout << "\n";
    }
}

std::istream &operator>>(std::istream &in, Masa &masa) {
    masa.input(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, Masa &masa) {
    masa.output(out);
    return out;
}









