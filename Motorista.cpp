#include "Motorista.hpp"
#include <iostream>
#include <sstream>

Motorista::Motorista(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco, const std::string &telefone,
                     const std::string &nomeSocial, const std::string &mae, const std::string &pai, const std::string &naturalidade,
                     const std::tm &nascimento, const std::string &numH, const std::string &catH, int numcontrato)
    : PessoaFisica(nome_oficial, cpf_cnpj, endereco, telefone, nomeSocial, mae, pai, naturalidade, nascimento),
      numhabilitacao(numH), cathabilitacao(catH), tipo(1), numcontrato(numcontrato) {}

Motorista::Motorista(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco, const std::string &telefone,
                     const std::string &nomeSocial, const std::string &mae, const std::string &pai, const std::string &naturalidade,
                     const std::tm &nascimento, const std::string &numH, const std::string &catH)
    : PessoaFisica(nome_oficial, cpf_cnpj, endereco, telefone, nomeSocial, mae, pai, naturalidade, nascimento),
      numhabilitacao(numH), cathabilitacao(catH), tipo(0), numcontrato(-1) {}

std::string Motorista::getNomeCivil() const
{
    return PessoaFisica::getNomeCivil();
}

std::string Motorista::getCPF() const
{
    return PessoaFisica::getCPF();
}

std::string Motorista::getNumhabilitacao() const
{
    return numhabilitacao;
}

std::string Motorista::getCathabilitacao() const
{
    return cathabilitacao;
}

int Motorista::getTipo() const
{
    return tipo;
}

int Motorista::getNumcontrato() const
{
    return numcontrato;
}

void Motorista::setNumcontrato(int numcontrato)
{
    if (this->getTipo() == 1)
    {
        this->numcontrato = numcontrato;
    }
    else
    {
        std::cout << "Método Inválido" << std::endl;
    }
}

void Motorista::addContrato(Contrato *contrato)
{
    if (contrato == nullptr || this->getTipo() == 0)
    {
        return;
    }
    else
    {
        contratos.push_back(contrato);
    }
}

std::string Motorista::verificarTipo() const
{
    if (this->getTipo() == 1)
    {
        return "Terceirizado";
    }
    else
    {
        return "Servidor Público";
    }
}

std::string Motorista::apresentarDados() const
{
    std::ostringstream oss;
    oss << PessoaFisica::apresentarDados()
        << "\nNúmero da Habilitação: " << this->getNumhabilitacao()
        << "\nCategoria da Habilitação: " << this->getCathabilitacao()
        << "\nTipo: " << this->verificarTipo()
        << "\nNúmero de Contrato: " << this->getNumcontrato();
    return oss.str();
}
