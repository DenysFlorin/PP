//
// Created by denys on 02.06.2023.
//

#include "Rezervare.h"

Rezervare ::Rezervare() {
    m_cod = "0";
    m_data = "0";
}

Rezervare::Rezervare(std::string data, std::string cod) {
    m_data = data;
    m_cod = cod;
}

std::string Rezervare::getData() {
    return m_data;
}

std::string Rezervare::getCod(){
    return m_cod;
}

void Rezervare::setData(std::string &data) {
    m_data = data;
}

void Rezervare::setCod(std::string &cod) {
    m_cod = cod;
}
