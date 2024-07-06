#include "Contrato.hpp"
#include <algorithm> 

Contrato::Contrato(int numcontrato, const std::tm &datainicio, const std::tm &datafim, double valor)
    : numcontrato(numcontrato), dateinicio(datainicio), datefim(datafim), valor(valor) {}

bool Contrato::addMotorista(Motorista motorista)
{
    if (motorista.getTipo() == 0)
    {
        return false;
    }
    else
    {
        motoristas.push_back(motorista);
        motorista.setNumcontrato(this->numcontrato);
        motorista.addContrato(this);
        return true;
    }
}

bool Contrato::addVeiculo(Veiculo veiculo)
{
    if (veiculo.getTipo() == 0)
    {
        return false;
    }
    else
    {
        veiculos.push_back(veiculo);
        veiculo.setNumcontrato(this->numcontrato);
        veiculo.setContrato(this);
        return true;
    }
}

bool Contrato::addFornecedor(PessoaJuridica *a)
{
    if (Fornecedor *f = dynamic_cast<Fornecedor *>(a)) 
    {
        fornecedores.push_back(*a);
        f->addContrato(this);
        return true;
    }
    else
    {
        return false;
    }
}

bool Contrato::removeMotorista(Motorista motorista)
{
    auto it = std::find(motoristas.begin(), motoristas.end(), motorista);
    if (it != motoristas.end())
    {
        motoristas.erase(it);
        return true;
    }
    else
    {
        return false;
    }
}

bool Contrato::removeMotorista(const std::string &cpfcnpj)
{
    auto it = std::find_if(motoristas.begin(), motoristas.end(), [&cpfcnpj](const Motorista &m)
                           { return m.getCPF() == cpfcnpj; });
    if (it != motoristas.end())
    {
        motoristas.erase(it);
        return true;
    }
    else
    {
        return false;
    }
}

bool Contrato::removeVeiculo(Veiculo veiculo)
{
    auto it = std::find(veiculos.begin(), veiculos.end(), veiculo);
    if (it != veiculos.end())
    {
        veiculos.erase(it);
        return true;
    }
    else
    {
        return false;
    }
}

bool Contrato::removeVeiculo(const std::string &placa)
{
    auto it = std::find_if(veiculos.begin(), veiculos.end(), [&placa](const Veiculo &v)
                           { return v.getPlaca() == placa; });
    if (it != veiculos.end())
    {
        veiculos.erase(it);
        return true;
    }
    else
    {
        return false;
    }
}

int Contrato::getNumcontrato() const
{
    return numcontrato;
}

std::tm Contrato::getDateinicio() const
{
    return dateinicio;
}

std::tm Contrato::getDatefim() const
{
    return datefim;
}

double Contrato::getValor() const
{
    return valor;
}

std::vector<Motorista> Contrato::getMotoristas() const
{
    return motoristas;
}

std::vector<Veiculo> Contrato::getVeiculos() const
{
    return veiculos;
}

std::vector<PessoaJuridica> Contrato::getFornecedores() const
{
    return fornecedores;
}
