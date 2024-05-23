#ifndef VEICULO_HPP
#define VEICULO_HPP

// Inclusão de bibliotecas necessárias
#include <string>

// Inclusão de arquivos hpp do projeto necessários
#include 'Contrato.hpp'

class Veiculo
{
private:
    // Atributos Privados
    std::string placa;
    int ano;
    std::string modelo;
    int capacidade;
    int tipo;
    int numcontrato;
    Contrato contrato;

public:
    // Construtores
    Veiculo(std::string, int, std::string, int, int);
    Veiculo(std::string, int, std::string, int);

    // Getters e Setters
    std::string getPlaca();
    int getAno();
    std::string getModelo();
    int getCapacidade();
    int getNumContrato();
    Contrato getContrato();
    void setPlaca(std::string);
    void setAno(int);
    void setModelo(std::string);
    void setCapacidade(int);

    // Funções específicas do obejto
    std::string verificarTipo();
};

#endif