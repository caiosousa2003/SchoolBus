#ifndef PESSOA_HPP
#define PESSOA_HPP

// Inclusão de bibliotecas necessárias
#include <string>

// Inclusão de arquivos hpp do projeto necessários
#include 'Endereco.hpp'

class Pessoa
{
private:
    // Atributos Privados
    std::string nome_oficial;
    std::string cpf_cnpj;
    Endereco endereco;
    std::string telefone;

public:
    // Construtor
    Pessoa(std::string, std::string, Endereco, std::string);

    // Getters e Setters - protected
    std::string getNomeOficial();
    std::string getCpfCnpj();
    std::string getEndereco();
    std::string getTelefone();

    // Funções específicas do obejto
    std::string imprimirDados();
    std::string verificarTipo();
};

#endif