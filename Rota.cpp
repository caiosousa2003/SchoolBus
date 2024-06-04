// Rota.cpp

#include "Rota.hpp"

int Rota::rotas = 0;

Rota::Rota() : id(++rotas) {}

int Rota::getId() const
{
    return id;
}

void Rota::addPontoDeParada(const PontoDeParada &a)
{
    pontosDeParada.push_back(a);
}

std::vector<PontoDeParada> Rota::getPontosDeParada() const
{
    return pontosDeParada;
}

int Rota::getRotas()
{
    return rotas;
}

int Rota::demanda() const
{
    int total = 0;
    for (const auto &elem : pontosDeParada)
    {
        total += elem.getAlunos().size();
    }
    return total;
}
