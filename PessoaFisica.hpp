#ifndef PESSOA_FISICA_HPP
#define PESSOA_FISICA_HPP

#include <string>
#include <iostream>
#include "Pessoa.hpp"
#include "Endereco.hpp" 
#include <ctime>       
class PessoaFisica : public Pessoa
{
private:
    std::string nomeSocial;
    std::string mae;
    std::string pai;
    std::string naturalidade;
    std::tm nascimento;

public:
    PessoaFisica(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco, const std::string &telefone,
                 const std::string &nomeSocial, const std::string &mae, const std::string &pai, const std::string &naturalidade, const std::tm &nascimento);

    std::string getNomeCivil() const;
    std::string getNomeSocial() const;
    std::string getMae() const;
    std::string getPai() const;
    std::string getNaturalidade() const;
    std::tm getNascimento() const;
    std::string getCPF() const;

    std::string apresentarDados() const override;
};

#endif // PESSOA_FISICA_HPP
