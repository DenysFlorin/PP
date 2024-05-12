//
// Created by denys on 02.06.2023.
//

#ifndef PROIECTPP2_REZERVARE_H
#define PROIECTPP2_REZERVARE_H

#include <string>


class Rezervare {

private:
    std::string m_data, m_cod;
public:
    Rezervare();
    Rezervare(std::string, std::string);
    std::string getData();
    std::string getCod();
    void setData(std::string&);
    void setCod(std::string&);
};



#endif //PROIECTPP2_REZERVARE_H
