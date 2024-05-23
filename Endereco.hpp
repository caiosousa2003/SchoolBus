#ifndef ENDERECO_HPP
#define ENDERECO_HPP

// Inclusão de bibliotecas necessárias
#include <string>

class Endereco
{
private:
    // Atributos Privados
    std::string rua;
    int numero;
    std::string complemento;
    std::string bairro;

public:
    // Construtor
    Endereco(std::string, int, std::string, std::string);

    // Funções específicas do obejto
    std::string getEndereco();
};

#endif