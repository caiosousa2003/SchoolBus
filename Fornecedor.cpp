#include "Fornecedor.hpp"

Fornecedor::Fornecedor(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco,
                       const std::string &telefone, const std::string &nomeFantasia, int numFuncionarios)
    : PessoaJuridica(nome_oficial, cpf_cnpj, endereco, telefone, nomeFantasia, numFuncionarios) {}

void Fornecedor::addContrato(Contrato *a)
{
    contratos.push_back(a);
}

std::string Fornecedor::apresentarDados() const
{
    return PessoaJuridica::apresentarDados(); // Plus any additional data formatting as needed
}
