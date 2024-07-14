#include "PontoDeParada.hpp"

int PontoDeParada::pontos = 0;

PontoDeParada::PontoDeParada(const std::string &nome, double latitude, double longitude, int id, const std::vector<Aluno> &alunos)
    : nome(nome), latitude(latitude), longitude(longitude), id(id), alunos(alunos)
{
    pontos++;
}

std::string PontoDeParada::getNome() const
{
    return nome;
}

double PontoDeParada::getLatitude() const
{
    return latitude;
}

double PontoDeParada::getLongitude() const
{
    return longitude;
}

int PontoDeParada::getId() const
{
    return id;
}

std::vector<Aluno> PontoDeParada::getAlunos() const
{
    return alunos;
}

int PontoDeParada::getPontos()
{
    return pontos;
}

std::ostream& operator<<(std::ostream& os, const PontoDeParada& pontoDeParada) {
    os << "Nome: " << pontoDeParada.getNome() << "\n"
       << "Latitude: " << pontoDeParada.getLatitude() << "\n"
       << "Longitude: " << pontoDeParada.getLongitude() << "\n"
       << "ID: " << pontoDeParada.getId() << "\n"
       << "Alunos: ";

    for (const auto& aluno : pontoDeParada.getAlunos()) {
        os << aluno.getNomeCivil() << " "; // Supondo que Aluno tem um método getNomeCivil()
    }
    os << "\n";
    
    return os;
}
