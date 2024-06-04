// Endereco.hpp

#ifndef ENDERECO_HPP
#define ENDERECO_HPP

#include <string>

class Endereco
{
private:
    std::string rua;
    int numero;
    std::string complemento;
    std::string bairro;

public:
    Endereco(const std::string &rua, int numero, const std::string &complemento, const std::string &bairro);

    std::string getEndereco() const;
};

#endif // ENDERECO_HPP
