// Endereco.cpp

#include "Endereco.hpp"

Endereco::Endereco(const std::string &rua, int numero, const std::string &complemento, const std::string &bairro)
    : rua(rua), numero(numero), complemento(complemento), bairro(bairro) {}

std::string Endereco::getEndereco() const
{
    return rua + ", " + std::to_string(numero) + ". " + bairro + ". " + complemento + ".";
}
