// Rota.hpp

#ifndef ROTA_HPP
#define ROTA_HPP

#include <vector>
#include "PontoDeParada.hpp" // Supondo que o arquivo PontoDeParada.hpp existe e está pronto

class Rota
{
private:
    int id;
    std::vector<PontoDeParada> pontosDeParada;
    static int rotas;

public:
    Rota();

    int getId() const;
    void addPontoDeParada(const PontoDeParada &a);
    std::vector<PontoDeParada> getPontosDeParada() const;
    static int getRotas();
    int demanda() const;
};

#endif // ROTA_HPP
