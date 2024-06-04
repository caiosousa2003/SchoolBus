// Contrato.hpp

#ifndef CONTRATO_HPP
#define CONTRATO_HPP

#include <string>
#include <vector>
#include <ctime> // Para std::tm
#include "Motorista.hpp"
#include "Veiculo.hpp"
#include "PessoaJuridica.hpp"
#include "Fornecedor.hpp"

class Contrato
{
private:
    int numcontrato;
    std::tm dateinicio;
    std::tm datefim;
    double valor;
    std::vector<Motorista> motoristas;
    std::vector<Veiculo> veiculos;
    std::vector<PessoaJuridica> fornecedores;

public:
    Contrato(int numcontrato, const std::tm &datainicio, const std::tm &datafim, double valor);

    bool addMotorista(Motorista motorista);
    bool addVeiculo(Veiculo veiculo);
    bool addFornecedor(PessoaJuridica *a);

    bool removeMotorista(Motorista motorista);
    bool removeMotorista(const std::string &cpfcnpj);
    bool removeVeiculo(Veiculo veiculo);
    bool removeVeiculo(const std::string &placa);

    int getNumcontrato() const;
    std::tm getDateinicio() const;
    std::tm getDatefim() const;
    double getValor() const;

    std::vector<Motorista> getMotoristas() const;
    std::vector<Veiculo> getVeiculos() const;
    std::vector<PessoaJuridica> getFornecedores() const;
};

#endif // CONTRATO_HPP