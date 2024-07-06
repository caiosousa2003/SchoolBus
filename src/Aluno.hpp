// Aluno.hpp

#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <string>
#include "PessoaFisica.hpp"
#include "Escola.hpp"
#include "PontoDeParada.hpp"
class PontoDeParada;

class Aluno : public PessoaFisica
{
private:
    int matricula;
    std::string serie;
    Escola *escola;
    PontoDeParada *pontoDeParada;

public:
    Aluno(const std::string &nome_oficial, const std::string &cpf_cnpj, const Endereco &endereco, const std::string &telefone,
          const std::string &nomeSocial, const std::string &mae, const std::string &pai, const std::string &naturalidade,
          const std::tm &nascimento, int matricula, const std::string &serie);
    virtual ~Aluno();

    std::string getNomeCivil() const;
    std::string getCPF() const;
    int getMatricula() const;
    std::string getSerie() const;
    Escola *getEscola() const;
    void setEscola(Escola *escola);
    PontoDeParada *getPontoDeParada() const;
    void setPontoDeParada(PontoDeParada *pontoDeParada);

    std::string apresentarDados() const override;
};

#endif // ALUNO_HPP
