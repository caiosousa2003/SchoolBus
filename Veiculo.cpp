// Veiculo.cpp

#include "Veiculo.hpp"

Veiculo::Veiculo(const std::string &placa, int ano, const std::string &modelo, int capacidade, int numcontrato)
    : placa(placa), ano(ano), modelo(modelo), capacidade(capacidade), tipo(1), numcontrato(numcontrato), contrato(nullptr) {}

Veiculo::Veiculo(const std::string &placa, int ano, const std::string &modelo, int capacidade)
    : placa(placa), ano(ano), modelo(modelo), capacidade(capacidade), tipo(0), numcontrato(0), contrato(nullptr) {}

std::string Veiculo::getPlaca() const
{
    return placa;
}

void Veiculo::setPlaca(const std::string &placa)
{
    this->placa = placa;
}

int Veiculo::getAno() const
{
    return ano;
}

void Veiculo::setAno(int ano)
{
    this->ano = ano;
}

std::string Veiculo::getModelo() const
{
    return modelo;
}

void Veiculo::setModelo(const std::string &modelo)
{
    this->modelo = modelo;
}

int Veiculo::getCapacidade() const
{
    return capacidade;
}

void Veiculo::setCapacidade(int capacidade)
{
    this->capacidade = capacidade;
}

int Veiculo::getTipo() const
{
    return tipo;
}

void Veiculo::setTipo(int tipo)
{
    this->tipo = tipo;
}

int Veiculo::getNumcontrato() const
{
    return numcontrato;
}

void Veiculo::setNumcontrato(int numcontrato)
{
    if (this->getTipo() == 1)
    {
        this->numcontrato = numcontrato;
    }
    else
    {
        std::cout << "Método Inválido" << std::endl;
    }
}

std::string Veiculo::verificarTipo() const
{
    return this->getTipo() == 1 ? "Alugado" : "Próprio";
}

Contrato *Veiculo::getContrato() const
{
    return contrato;
}

void Veiculo::setContrato(Contrato *contrato)
{
    this->contrato = contrato;
}
