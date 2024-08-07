#ifndef PONTO_DE_PARADA_HPP
#define PONTO_DE_PARADA_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Aluno.hpp" 

class Aluno;

class PontoDeParada
{
private:
    std::string nome;
    double latitude;
    double longitude;
    int id;
    std::vector<Aluno> alunos;
    static int pontos;

public:
    PontoDeParada(const std::string &nome, double latitude, double longitude, int id, const std::vector<Aluno> &alunos);

    std::string getNome() const;
    double getLatitude() const;
    double getLongitude() const;
    int getId() const;
    std::vector<Aluno> getAlunos() const;
    static int getPontos();
};
std::ostream& operator<<(std::ostream& os, const PontoDeParada& pontoDeParada);

#endif 
