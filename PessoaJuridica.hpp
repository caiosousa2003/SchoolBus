#ifndef PESSOAJURIDICA_HPP
#define PESSOAJURIDICA_HPP

#include <string>
#include "Pessoa.hpp"

class PessoaJuridica : public Pessoa
{
private:
    std::string nomeFantasia;
    int numFuncionarios;

public:
    PessoaJuridica(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco, const std::string &telefone,
                   const std::string &nomeFantasia, int numFuncionarios);

    std::string getNome() const;
    std::string getNomeFantasia() const;
    int getNumFuncionarios() const;
    std::string getCNPJ() const;

    std::string apresentarDados() const override;
};

#endif 
