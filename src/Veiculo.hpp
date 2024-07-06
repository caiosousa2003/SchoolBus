#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <string>
#include <iostream>
#include "Contrato.hpp" 

class Contrato;

class Veiculo
{
private:
    std::string placa;
    int ano;
    std::string modelo;
    int capacidade;
    int tipo;
    int numcontrato;
    Contrato *contrato;

public:
    // Construtor com veiculo alugado
    Veiculo(const std::string &placa, int ano, const std::string &modelo, int capacidade, int numcontrato);

    // Construtor com veiculo próprio
    Veiculo(const std::string &placa, int ano, const std::string &modelo, int capacidade);

    std::string getPlaca() const;
    void setPlaca(const std::string &placa);

    int getAno() const;
    void setAno(int ano);

    std::string getModelo() const;
    void setModelo(const std::string &modelo);

    int getCapacidade() const;
    void setCapacidade(int capacidade);

    int getTipo() const;
    void setTipo(int tipo);

    int getNumcontrato() const;
    void setNumcontrato(int numcontrato);

    std::string verificarTipo() const;

    Contrato *getContrato() const;
    void setContrato(Contrato *contrato);

    friend bool operator==(const Veiculo& lhs, const Veiculo& rhs);
};

#endif 
