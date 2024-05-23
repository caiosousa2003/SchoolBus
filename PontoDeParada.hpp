#ifndef PONTODEPARADA_HPP
#define PONTODEPARADA_HPP

// Inclusão de bibliotecas necessárias
#include <string>
#include <vector>

// Inclusão de arquivos hpp do projeto necessários
#include 'Aluno.hpp'

class PontoDeParada
{
private:
    // Atributos Privados
    std::string nome;
    double latitude;
    double longitude;
    int id;
    std::vector<Aluno> alunos;
    static int pontos;

public:
    // Construtor
    PontoDeParada(std::string, double, double, int, std::vector<Aluno>);

    // Getters e Setters
    std::string getNome();
    double getLatitude();
    double getLongitude();
    int getId();
    std::vector<Aluno> getAlunos();
    static int getPontos();
};

#endif