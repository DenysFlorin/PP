//
// Created by denys on 19.05.2023.
//


#ifndef PROIECTPP2_DATABASE_H
#define PROIECTPP2_DATABASE_H

#include "Masa.h"
#include <iostream>
#include <vector>

class Database {
private:
    std::vector<Masa> m_date;
public:
    Database();
    Database(const Database&);
//  Database(const vector<Masa>, int);
    bool search(int);
    void add(int, const std::string&, const std::string&);
    void addload(Masa);
    void afisare();
    void sterge(int);
    void save(std::ostream&);
    void load(std::istream&);
    bool search2(int);
    bool searchCod(const std::string&);
    void stergeCod(const std::string&);
    std::vector<Masa> getDate();
    void afisare2();
    friend std::ostream& operator <<(std::ostream&, Database&);

};


#endif //PROIECTPP2_DATABASE_H
