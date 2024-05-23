#ifndef ROTA_HPP
#define ROTA_HPP

// Inclusão de bibliotecas necessárias
#include <vector>

// Inclusão de arquivos hpp do projeto necessários
#include 'PontoDeParada.hpp'

class Rota
{
private:
    // Atributos Privados
    int id;
    std::vector<PontoDeParada> pontosDeParada;
    static int rotas;

public:
    // Construtor
    Rota();

    // Getters e Setters
    int getId();
    static int getRotas();
    std::vector<PontoDeParada> getPontosDeParada();

    // Funções específicas do obejto
    int demanda();
    void addPontoDeParada(PontoDeParada);
};

#endif