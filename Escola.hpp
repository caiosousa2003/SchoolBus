#ifndef ESCOLA_HPP
#define ESCOLA_HPP

#include <vector>
#include <string>
#include "PessoaJuridica.hpp"
#include "Aluno.hpp" // Ensure that Aluno.hpp is defined properly.

class Escola : public PessoaJuridica
{
private:
    std::vector<Aluno *> alunos;

public:
    Escola(const std::string &nome_oficial, const std::string &cpf_cnpj, 
           const Endereco &endereco, const std::string &telefone,
           const std::string &nomeFantasia, int numFuncionarios
           );

    void matriculaAluno(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco,
                        const std::string &telefone, const std::string &nomeSocial, const std::string &mae,
                        const std::string &pai, const std::string &naturalidade, const std::tm &nascimento,
                        int matricula, const std::string &serie);
    std::string exibirAlunos() const;
    std::string apresentarDados() const override;
    const std::vector<Aluno *> &getAlunos() const;

    ~Escola(); // Destructor to handle dynamic memory
};

#endif // ESCOLA_HPP
