#include "PessoaJuridica.hpp"

PessoaJuridica::PessoaJuridica(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco, const std::string &telefone,
                               const std::string &nomeFantasia, int numFuncionarios)
    : Pessoa(nome_oficial, cpf_cnpj, endereco, telefone), nomeFantasia(nomeFantasia), numFuncionarios(numFuncionarios) {}

std::string PessoaJuridica::getNome() const
{
    return Pessoa::getNomeOficial();
}

std::string PessoaJuridica::getNomeFantasia() const
{
    return nomeFantasia;
}

int PessoaJuridica::getNumFuncionarios() const
{
    return numFuncionarios;
}

std::string PessoaJuridica::getCNPJ() const
{
    return Pessoa::getCpfCnpj();
}

std::string PessoaJuridica::apresentarDados() const
{
    return Pessoa::apresentarDados() + "\nNome Fantasia: " + getNomeFantasia() + "\nNúmero de Funcionários: " + std::to_string(getNumFuncionarios());
}
