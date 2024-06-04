// Pessoa.cpp

#include "Pessoa.hpp"
#include "Aluno.hpp" // Supondo que as classes Aluno, Motorista, Escola, Fornecedor estão prontas
#include "Motorista.hpp"
#include "Escola.hpp"
#include "Fornecedor.hpp"

Pessoa::Pessoa(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco, const std::string &telefone)
    : nome_oficial(nome_oficial), cpf_cnpj(cpf_cnpj), endereco(endereco), telefone(telefone) {}

std::string Pessoa::getNomeOficial() const
{
    return nome_oficial;
}

std::string Pessoa::getCpfCnpj() const
{
    return cpf_cnpj;
}

Endereco Pessoa::getEndereco() const
{
    return endereco;
}

std::string Pessoa::getTelefone() const
{
    return telefone;
}

std::string Pessoa::apresentarDados() const
{
    return "Nome: " + getNomeOficial() + "\nCPF/CNPJ: " + cpf_cnpj + "\nEndereço: " + endereco.getEndereco() + "\nTelefone: " + telefone;
}

std::string Pessoa::verificarTipo() const
{
    if (dynamic_cast<const Aluno *>(this))
    {
        return "Tipo: Aluno";
    }
    else if (dynamic_cast<const Motorista *>(this))
    {
        return "Tipo: Motorista";
    }
    else if (dynamic_cast<const Escola *>(this))
    {
        return "Tipo: Escola";
    }
    else if (dynamic_cast<const Fornecedor *>(this))
    {
        return "Tipo: Fornecedor";
    }
    else
    {
        return "Não é possível identificar";
    }
}
