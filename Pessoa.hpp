#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include "Endereco.hpp"

class Pessoa
{
private:
    std::string nome_oficial;
    std::string cpf_cnpj;
    Endereco endereco;
    std::string telefone;

protected:
    std::string getNomeOficial() const;
    std::string getCpfCnpj() const;
    Endereco getEndereco() const;
    std::string getTelefone() const;

public:
    Pessoa(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco, const std::string &telefone);

    virtual std::string apresentarDados() const;
    std::string verificarTipo() const;
};

#endif 
