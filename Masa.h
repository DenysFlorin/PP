//
// Created by denys on 19.05.2023.
//

#ifndef PROIECTPP2_MASA_H
#define PROIECTPP2_MASA_H


#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Rezervare.h"

class Masa {
private:
    int m_capacitate;
    std::vector<Rezervare> m_rezervari;
public:
    Masa();
    Masa(int, std::vector<Rezervare>&);
    Masa(const Masa&);
    int getCapacitate() const;
    std::vector<Rezervare> getRezervari();
    void setCapacitate(int);
    void setRezervari(std::vector<Rezervare>&);
    void input(std::istream&);
    void output(std::ostream&);
    friend std::istream& operator >>(std::istream&, Masa&);
    friend std::ostream& operator <<(std::ostream&, Masa&);
};


#endif //PROIECTPP2_MASA_H
