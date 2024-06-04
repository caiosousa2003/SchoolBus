#include "Escola.hpp"
#include <sstream> // For std::stringstream

Escola::Escola(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco,
               const std::string &telefone, const std::string &nomeFantasia, int numFuncionarios)
    : PessoaJuridica(nome_oficial, cpf_cnpj, endereco, telefone, nomeFantasia, numFuncionarios) {}

void Escola::matriculaAluno(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco,
                            const std::string &telefone, const std::string &nomeSocial, const std::string &mae,
                            const std::string &pai, const std::string &naturalidade, const std::tm &nascimento,
                            int matricula, const std::string &serie)
{
    Aluno *aluno = new Aluno(nome_oficial, cpf_cnpj, endereco, telefone, nomeSocial, mae, pai, naturalidade,
                             nascimento, matricula, serie);
    aluno->setEscola(this);
    alunos.push_back(aluno);
}

std::string Escola::exibirAlunos() const
{
    std::stringstream text;
    for (const auto &aluno : alunos)
    {
        text << "Aluno: " << aluno->getNomeCivil() << "\n"
             << "Matrícula: " << aluno->getMatricula() << "\n"
             << "CPF: " << aluno->getCPF() << "\n"
             << "Série: " << aluno->getSerie() << "\n\n";
    }
    return text.str();
}

std::string Escola::apresentarDados() const
{
    return PessoaJuridica::apresentarDados(); // Plus any additional formatting as needed
}

const std::vector<Aluno *> &Escola::getAlunos() const
{
    return alunos;
}

Escola::~Escola()
{
    for (auto &aluno : alunos)
    {
        delete aluno;
    }
}
