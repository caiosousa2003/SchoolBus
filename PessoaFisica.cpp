// PessoaFisica.cpp

#include "PessoaFisica.hpp"

PessoaFisica::PessoaFisica(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco, const std::string &telefone,
                           const std::string &nomeSocial, const std::string &mae, const std::string &pai, const std::string &naturalidade, const std::tm &nascimento)
    : Pessoa(nome_oficial, cpf_cnpj, endereco, telefone), nomeSocial(nomeSocial), mae(mae), pai(pai), naturalidade(naturalidade), nascimento(nascimento) {}

std::string PessoaFisica::getNomeCivil() const
{
    return getNomeOficial();
}

std::string PessoaFisica::getNomeSocial() const
{
    return nomeSocial;
}

std::string PessoaFisica::getMae() const
{
    return mae;
}

std::string PessoaFisica::getPai() const
{
    return pai;
}

std::string PessoaFisica::getNaturalidade() const
{
    return naturalidade;
}

std::tm PessoaFisica::getNascimento() const
{
    return nascimento;
}

std::string PessoaFisica::getCPF() const
{
    return getCpfCnpj();
}

std::string PessoaFisica::apresentarDados() const
{
    std::ostringstream oss;
    oss << Pessoa::apresentarDados()
        << "\nNome Social: " << getNomeSocial()
        << "\nNome da Mãe: " << getMae()
        << "\nNome do pai: " << getPai()
        << "\nNaturalidade: " << getNaturalidade()
        << "\nData de Nascimento: " << std::put_time(&nascimento, "%Y-%m-%d");
    return oss.str();
}
