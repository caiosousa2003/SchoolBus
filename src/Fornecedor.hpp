#ifndef FORNECEDOR_HPP
#define FORNECEDOR_HPP

#include <vector>
#include "PessoaJuridica.hpp"
#include "Contrato.hpp" 

class Fornecedor : public PessoaJuridica
{
private:
    std::vector<Contrato *> contratos;

public:
    Fornecedor(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco,
               const std::string &telefone, const std::string &nomeFantasia, int numFuncionarios);

    void addContrato(Contrato *a);
    std::string apresentarDados() const override;
};

#endif 
