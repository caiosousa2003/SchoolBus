// Motorista.hpp

#ifndef MOTORISTA_HPP
#define MOTORISTA_HPP

#include <string>
#include <vector>
#include "PessoaFisica.hpp"
#include "Contrato.hpp"

class Motorista : public PessoaFisica
{
private:
    std::string numhabilitacao;
    std::string cathabilitacao;
    int tipo;
    int numcontrato;
    std::vector<Contrato *> contratos;

public:
    // Construtor terceirizado
    Motorista(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco, const std::string &telefone,
              const std::string &nomeSocial, const std::string &mae, const std::string &pai, const std::string &naturalidade,
              const std::tm &nascimento, const std::string &numH, const std::string &catH, int numcontrato);

    // Construtor servidor
    Motorista(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco, const std::string &telefone,
              const std::string &nomeSocial, const std::string &mae, const std::string &pai, const std::string &naturalidade,
              const std::tm &nascimento, const std::string &numH, const std::string &catH);

    std::string getNomeCivil() const;
    std::string getCPF() const;
    std::string getNumhabilitacao() const;
    std::string getCathabilitacao() const;
    int getTipo() const;
    int getNumcontrato() const;
    void setNumcontrato(int numcontrato);
    void addContrato(Contrato *contrato);
    std::string verificarTipo() const;
    std::string apresentarDados() const override;
};

#endif // MOTORISTA_HPP
