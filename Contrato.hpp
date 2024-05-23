#ifndef CONTRATO_HPP
#define CONTRATO_HPP

// Inclusão de bibliotecas necessárias
#include <string>
#include <vector>
#include <boost/date_time/gregorian/gregorian.hpp>

// Inclusão de arquivos hpp do projeto necessários
#include 'Motorista.hpp'
#include 'Veiculo.hpp'
#include 'PessoaJuridica.hpp'

class Contrato
{
private:
    // Atributos Privados
    int numContrato;
    boost::gregorian::date dataInicio;
    boost::gregorian::date dataFim;
    double valor;
    std::vector<Motorista> motoristas;
    std::vector<Veiculo> veiculos;
    std::vector<PessoaJuridica> fornecedores;

public:
    // Construtor
    Contrato(int, boost::gregorian::date, boost::gregorian::date, double);

    // Getters e Setters
    int getNumContrato();
    boost::gregorian::date getDataInicio();
    boost::gregorian::date getDataFim();
    double getValor();
    std::vector<Motorista> getMotoristas();
    std::vector<Veiculo> getVeiculos();
    std::vector<PessoaJuridica> getFornecedores();

    // Funções específicas do obejto
    bool addMotorista(Motorista);
    bool addVeiculo(Veiculo);
    bool addFornecedor(PessoaJuridica);
    bool removeMotorista(Motorista);
    bool removeMotorista(std::string);
    bool removeVeiculo(Veiculo);
    bool removeVeiculo(std::string);
    void imprimirDados();
};

#endif