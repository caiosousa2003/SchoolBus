// Classe aluno é responsavel por admistrar todas as informações fos alunos e as informações de paradas
#include "Aluno.hpp"
#include <sstream>
#include <iomanip>

Aluno::Aluno(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco, const std::string &telefone,
             const std::string &nomeSocial, const std::string &mae, const std::string &pai, const std::string &naturalidade,
             const std::tm &nascimento, int matricula, const std::string &serie)
    : PessoaFisica(nome_oficial, cpf_cnpj, endereco, telefone, nomeSocial, mae, pai, naturalidade, nascimento),
      matricula(matricula), serie(serie), escola(nullptr), pontoDeParada(nullptr) {}

Aluno::~Aluno(){}

std::string Aluno::getNomeCivil() const
{
    return PessoaFisica::getNomeCivil();
}

std::string Aluno::getCPF() const
{
    return PessoaFisica::getCPF();
}

int Aluno::getMatricula() const
{
    return matricula;
}

std::string Aluno::getSerie() const
{
    return serie;
}

Escola *Aluno::getEscola() const
{
    return escola;
}

void Aluno::setEscola(Escola *escola)
{
    this->escola = escola;
}

PontoDeParada *Aluno::getPontoDeParada() const
{
    return pontoDeParada;
}

void Aluno::setPontoDeParada(PontoDeParada *pontoDeParada)
{
    this->pontoDeParada = pontoDeParada;
}

std::string Aluno::apresentarDados(){
    std::string dados="\nMatricula" + std::to_string(getMatricula)+
                        "\nSérie "+getSerie()+"\n";
    if(getEscola()!=nullptr){
        dados+="\nEscola "+getEscola()->getNome();
    }
    if(getPontoDeParada()!= nullptr){
        dados+= "\nPonto de Parada "+ getPontoDeParada()->getNome();
    }
    return dados;
}
