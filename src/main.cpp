#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <memory>
#include <limits> 
#include <stdexcept>

#include "Aluno.hpp"
#include "Contrato.hpp"
#include "Endereco.hpp"
#include "Escola.hpp"
#include "Fornecedor.hpp"
#include "Motorista.hpp"
#include "PontoDeParada.hpp"
#include "Rota.hpp"
#include "Veiculo.hpp"

std::vector<Escola> escolas;
std::vector<Motorista> motoristas;
std::vector<Veiculo> veiculos;
std::vector<Contrato> contratos;
std::vector<std::unique_ptr<PontoDeParada>> pontos;
// std::vector<PontoDeParada> pontos;
std::vector<Rota> rotas;
std::vector<std::unique_ptr<Pessoa>> pessoas;
// std::vector<Pessoa> pessoas;

Endereco criarEndereco()
{
    std::string rua, complemento, bairro;
    int numero;

    std::cout << "Rua: ";
    std::getline(std::cin, rua);
    std::cout << "Número: ";
    std::cin >> numero;
    std::cin.ignore();
    std::cout << "Complemento: ";
    std::getline(std::cin, complemento);
    std::cout << "Bairro: ";
    std::getline(std::cin, bairro);

    return Endereco(rua, numero, complemento, bairro);
}

void criarAluno()
{
    if (escolas.empty())
    {
        std::cout << "\nNenhuma escola cadastrada ainda!\nVoltando...\n"
                  << std::endl;
    }
    else
    {
        int i;
        std::cout << "\nSelecione a Escola: " << std::endl;
        for (size_t idx = 0; idx < escolas.size(); ++idx)
        {
            std::cout << idx << " - " << escolas[idx].getNome() << std::endl; // Verificar esse erro de interação
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> i;
        std::cin.ignore();

        std::string nomeCivil, nome, mae, pai, naturalidade, cpf, telefone, serie;
        std::cout << "\nPreencha as seguintes informações:" << std::endl;
        std::cout << "Nome Civil: ";
        std::getline(std::cin, nomeCivil);
        std::cout << "Nome Social: ";
        std::getline(std::cin, nome);
        std::cout << "Nome da Mãe: ";
        std::getline(std::cin, mae);
        std::cout << "Nome do Pai: ";
        std::getline(std::cin, pai);
        std::cout << "Naturalidade: ";
        std::getline(std::cin, naturalidade);
        std::cout << "CPF: ";
        std::getline(std::cin, cpf);

        tm dataNascimento = {};
        std::cout << "Data de Nascimento (dd/MM/yyyy): ";
        std::string dataNascimentoStr;
        std::getline(std::cin, dataNascimentoStr);
        std::istringstream ss(dataNascimentoStr);
        ss >> std::get_time(&dataNascimento, "%d/%m/%Y");
        if (ss.fail())
        {
            std::cout << "Formato de data inválido." << std::endl;
            return;
        }

        std::cout << "Telefone: ";
        std::getline(std::cin, telefone);

        int matricula;
        std::cout << "Matrícula: ";
        std::cin >> matricula;
        std::cin.ignore();

        std::cout << "Série: ";
        std::getline(std::cin, serie);

        Endereco endereco = criarEndereco();
        escolas[i].matriculaAluno(nomeCivil, cpf, endereco, telefone, nome, mae, pai, naturalidade, dataNascimento, matricula, serie);
        std::cout << "Aluno criado com sucesso! Voltando para menu" << std::endl;
    }
}

void criarFornecedor()
{
    std::string nome, nomeFantasia, cnpj, telefone;
    int num;

    std::cout << "Nome Oficial: ";
    std::getline(std::cin, nome);
    std::cout << "Nome Fantasia: ";
    std::getline(std::cin, nomeFantasia);
    std::cout << "CNPJ: ";
    std::getline(std::cin, cnpj);
    std::cout << "Telefone: ";
    std::getline(std::cin, telefone);
    std::cout << "Número de Funcionários: ";
    std::cin >> num;
    std::cin.ignore();

    Endereco endereco = criarEndereco();
    // Fornecedor fornecedor(nome, cnpj, endereco, telefone, nomeFantasia, num);
    // pessoas.push_back(fornecedor);
    pessoas.push_back(std::make_unique<Fornecedor>(nome, cnpj, endereco, telefone, nomeFantasia, num));
}

void criarMotorista()
{
    int i, numcontrato = -1;
    std::string nomeCivil, nome, mae, pai, naturalidade, cpfcnpj, telefone, numhabilitacao, cathabilitacao;
    tm dataNascimento = {};

    std::cout << "\nMotorista é terceirizado (1) ou servidor (0)? ";
    std::cin >> i;
    std::cin.ignore();

    if (i == 1)
    {
        std::cout << "Número de Contrato: ";
        std::cin >> numcontrato;
        std::cin.ignore();
    }

    std::cout << "Nome Civil: ";
    std::getline(std::cin, nomeCivil);
    std::cout << "Nome Social: ";
    std::getline(std::cin, nome);
    std::cout << "Nome da Mãe: ";
    std::getline(std::cin, mae);
    std::cout << "Nome do Pai: ";
    std::getline(std::cin, pai);
    std::cout << "Naturalidade: ";
    std::getline(std::cin, naturalidade);
    std::cout << "CPF: ";
    std::getline(std::cin, cpfcnpj);

    std::cout << "Data de Nascimento (dd/MM/yyyy): ";
    std::string dataNascimentoStr;
    std::getline(std::cin, dataNascimentoStr);
    std::istringstream ss(dataNascimentoStr);
    ss >> std::get_time(&dataNascimento, "%d/%m/%Y");
    if (ss.fail())
    {
        std::cout << "Formato de data inválido." << std::endl;
        return;
    }

    std::cout << "Telefone: ";
    std::getline(std::cin, telefone);
    std::cout << "Número de Habilitação: ";
    std::getline(std::cin, numhabilitacao);
    std::cout << "Categoria de Habilitação: ";
    std::getline(std::cin, cathabilitacao);

    Endereco endereco = criarEndereco();
    Motorista motorista(nomeCivil, cpfcnpj, endereco, telefone, nome, mae, pai, naturalidade, dataNascimento, numhabilitacao, cathabilitacao, numcontrato);

    motoristas.push_back(motorista);
    std::cout << "Motorista criado com sucesso! Voltando para menu" << std::endl;
}

void criarVeiculo()
{
    std::string placa, modelo;
    int ano, capacidade, i, numcontrato = -1;

    std::cout << "Placa do Veículo: ";
    std::getline(std::cin, placa);
    std::cout << "Ano do Veículo: ";
    std::cin >> ano;
    std::cin.ignore();
    std::cout << "Modelo do Veículo: ";
    std::getline(std::cin, modelo);
    std::cout << "Capacidade do Veículo: ";
    std::cin >> capacidade;
    std::cin.ignore();

    std::cout << "\nVeiculo é alugado (1) ou próprio (0)? ";
    std::cin >> i;
    std::cin.ignore();

    if (i == 1)
    {
        std::cout << "Número de Contrato: ";
        std::cin >> numcontrato;
        std::cin.ignore();
    }

    Veiculo veiculo(placa, ano, modelo, capacidade, numcontrato);
    veiculos.push_back(veiculo);
    std::cout << "Veiculo criado com sucesso! Voltando para menu" << std::endl;
}

void criarContrato()
{
    int numcontrato, i, n;
    std::string dateinicioStr, datefimStr;
    double valor;
    tm dateinicio = {}, datefim = {};

    std::cout << "Número de Contrato: ";
    std::cin >> numcontrato;
    std::cin.ignore();

    std::cout << "Data de Início (dd/MM/yyyy): ";
    std::getline(std::cin, dateinicioStr);
    std::istringstream ssInicio(dateinicioStr);
    ssInicio >> std::get_time(&dateinicio, "%d/%m/%Y");
    if (ssInicio.fail())
    {
        std::cout << "Formato de data inválido." << std::endl;
        return;
    }

    std::cout << "Data de Fim (dd/MM/yyyy): ";
    std::getline(std::cin, datefimStr);
    std::istringstream ssFim(datefimStr);
    ssFim >> std::get_time(&datefim, "%d/%m/%Y");
    if (ssFim.fail())
    {
        std::cout << "Formato de data inválido." << std::endl;
        return;
    }

    std::cout << "Valor: ";
    std::cin >> valor;
    std::cin.ignore();

    Contrato contrato(numcontrato, dateinicio, datefim, valor);

    std::cout << "Gostaria de adicionar fornecedor ao contrato? Sim (1) ou Não (0): ";
    std::cin >> i;
    std::cin.ignore();

    if (i == 1)
    {
        for (size_t idx = 0; idx < pessoas.size(); ++idx)
        {
            Fornecedor *fornecedor = dynamic_cast<Fornecedor *>(pessoas[idx].get());
            if (fornecedor)
            {
                std::cout << idx << " - " << fornecedor->getNomeOficial() << std::endl;
            }
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> n;
        std::cin.ignore();

        Fornecedor* fornecedor = dynamic_cast<Fornecedor*>(pessoas[n].get());
        if (fornecedor) {
            contrato.addFornecedor(fornecedor);
        }
        
    }
    contratos.push_back(contrato);
}

void criarEscola()
{
    std::string nome, nomeFantasia, cnpj, telefone;
    int num;

    std::cout << "Nome Oficial: ";
    std::getline(std::cin, nome);
    std::cout << "Nome Fantasia: ";
    std::getline(std::cin, nomeFantasia);
    std::cout << "CNPJ: ";
    std::getline(std::cin, cnpj);
    std::cout << "Telefone: ";
    std::getline(std::cin, telefone);
    std::cout << "Número de Funcionários: ";
    std::cin >> num;
    std::cin.ignore();

    Endereco endereco = criarEndereco();
    Escola escola(nome, cnpj, endereco, telefone, nomeFantasia, num);
    escolas.push_back(escola);
    std::cout << "Escola criada com sucesso! Voltando para menu" << std::endl;
}

void criarPontoParada()
{
    std::string nome;
    double latitude, longitude;
    int id, i = -1, n = -1;
    std::vector<std::string> alunos;
    std::vector<Aluno*> alunosEscola;

    std::cout << "Nome da Localização: ";
    std::getline(std::cin, nome);
    std::cout << "Latitude: ";
    std::cin >> latitude;
    std::cin.ignore();
    std::cout << "Longitude: ";
    std::cin >> longitude;
    std::cin.ignore();
    std::cout << "Identificação (Número): ";
    std::cin >> id;
    std::cin.ignore();
    
    do
    {
        std::cout << "\nSelecione a Escola do aluno para esse ponto de parada: ";
        for (size_t idx = 0; idx < escolas.size(); ++idx)
        {
            std::cout << (idx + 1) << " - " << "Nome"; // Nome da escola
        }
        std::cout << "\nInsira o número correspondente (Quando finalizar, insira 0): ";
        std::cin >> i;
        std::cin.ignore();
        if (i == 0)
            break;

        std::vector<Aluno*> alunosEscola = escolas[i - 1].getAlunos();
        do
        {
            std::cout << "\nSelecione os Alunos para esse ponto de parada: ";
            for (size_t j = 0; j < alunosEscola.size(); ++j)
            {
                std::cout << (j + 1) << " - " << "NomeCivil"; // Pegar nome do aluno (Implementar)
            }
            std::cout << "\nInsira o número correspondente (Quando finalizar, insira 0): ";
            std::cin >> n;
            std::cin.ignore();
            if (n == 0)
                break;
            alunosEscola.push_back(escolas[i - 1].getAlunos()[n - 1]);
        } while (n != 0);
    } while (i != 0);

    // pontos.push_back(new PontoDeParada(nome, latitude, longitude, id, alunosEscola)); // Verificar bug
    std::vector<Aluno> alunosEscola_;
    for (const auto& ptr : alunosEscola) {
        if (ptr != nullptr) {
            alunosEscola_.push_back(*ptr);
        }
    }
    pontos.push_back(std::make_unique<PontoDeParada>(nome, latitude, longitude, id, alunosEscola_));
    std::cout << "Ponto de Parada criado com sucesso! Voltando para menu" << std::endl;
}


void criarRota()
{
    Rota rota;
    int i = -1;

    do
    {
        std::cout << "Rota criada com sucesso! Adicionando pontos a ela:";
        for (size_t idx = 0; idx < pontos.size(); ++idx)
        {
            std::cout << (idx + 1) << " - " << "Nome"; // Pegar nome dos pontos de parada
        }
        std::cout << "\nInsira o número correspondente (Quando finalizar, insira 0): ";
        std::cin >> i;
        std::cin.ignore();
        if (i == 0)
            break;
        rota.addPontoDeParada(*pontos[i - 1]);
    } while (i != 0);

    rotas.push_back(rota);
    std::cout << "Pontos adicionados com sucesso! Voltando para menu" << std::endl;
}


int validacao_numero(int n){
    if (n>=0 && n<=8){
        return n;
    }else{
        std::cout << "Número inválido. Selecione um número entre 0 e 8: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    
    }
}

void menuCriacao()
{
    int n;
    


    do
    {
        std::cout << "Menu Interativo\n"
                  << std::endl;
        std::cout << "1 - Criar Aluno\n2 - Criar Motorista\n3 - Criar Contrato\n4 - Criar Escola\n";
        std::cout << "5 - Criar Veiculo\n6 - Criar Ponto de Parada\n7 - Criar Nova Rota\n";
        std::cout << "8 - Criar Fornecedor\n0 - Voltar\n"
                  << std::endl;

        std::cout << "Escolha o número correspondente: ";
        std::cin >> n;
        validacao_numero(n);
        std::cin.ignore();

        switch (n)
        {
        case 1:
            criarAluno();
            break;
        case 2:
            criarMotorista();
            break;
        case 3:
            criarContrato();
            break;
        case 4:
            criarEscola();
            break;
        case 5:
            criarVeiculo();
            break;
        case 6:
            criarPontoParada();
            break;
        case 7:
            criarRota();
            break;
        case 8:
            criarFornecedor();
            break;
        }
    } while (n != 0);
}

Rota escolherRota()
{
    std::cout << "Escolha a rota (pelo ID) para calcular demanda:" << std::endl;
    for (Rota x : rotas)
    {
        std::cout << x.getId() << std::endl;
    }
    std::cout << "\nInsira o número correspondente: ";
    int i;
    std::cin >> i;
    std::cin.ignore();

    return rotas[i - 1];
}
    template<typename T>
    int indexOf(const std::vector<T>& vec, const T& item) {
        for (size_t i = 0; i < vec.size(); ++i) {
            if (vec[i] == item) {
                return i;
            }
        }
        return -1;
    }
void mostrarDados() {
    std::cout << "Escolha o objeto que quer ver\n1-Aluno\n2-Motorista\n3-Escola\n4-Fornecedor";
    int i;
    std::cin >> i;
    std::cin.ignore();

    int n;
    int a;

    switch (i) {
    case 1: {
        std::cout << "\nSelecione a Escola do aluno: " << std::endl;
        for (size_t j = 0; j < escolas.size(); ++j) {
            std::cout << (j + 1) << " - " << escolas[j].getNome() << std::endl;
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> n;
        std::cin.ignore();

        if (n <= 0 || n > escolas.size()) {
            std::cerr << "Número inválido" << std::endl;
            return;
        }

        std::cout << "\nSelecione os Alunos para esse ponto de parada: " << std::endl;
        const auto& alunos = escolas[n - 1].getAlunos();
        for (size_t j = 0; j < alunos.size(); ++j) {
            std::cout << (j + 1) << " - " << alunos[j]->getNomeCivil() << std::endl;
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> a;
        std::cin.ignore();

        if (a <= 0 || a > alunos.size()) {
            std::cerr << "Número inválido" << std::endl;
            return;
        }

        std::cout << alunos[a - 1]->apresentarDados() << std::endl;
        break;
        }


    case 2:{
        std::cout << "\nSelecione o Motorista: " << std::endl;
        for (size_t j = 0; j < motoristas.size(); ++j) {
            std::cout << (j + 1) << " - " << motoristas[j].getNomeCivil() << std::endl;
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> n;
        std::cin.ignore();

        if (n <= 0 || n > motoristas.size()) {
            std::cerr << "Número inválido" << std::endl;
            return;
        }

        std::cout << motoristas[n - 1].apresentarDados() << std::endl;
        break;
        }
    case 3:{
        std::cout << "\nSelecione a Escola: " << std::endl;
        for (size_t j = 0; j < escolas.size(); ++j) {
            std::cout << (j + 1) << " - " << escolas[j].getNome() << std::endl;
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> n;
        std::cin.ignore();

        if (n <= 0 || n > escolas.size()) {
            std::cerr << "Número inválido" << std::endl;
            return;
        }

        std::cout << escolas[n - 1].apresentarDados() << std::endl;
        break;
        }
    case 4:{
        std::cout << "\nSelecione o Fornecedor: " << std::endl;
        for (size_t j = 0; j < pessoas.size(); ++j) {
            std::cout << (j + 1) << " - " << pessoas[j]->getNomeOficial() << std::endl;
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> n;
        std::cin.ignore();

        if (n <= 0 || n > pessoas.size()) {
            std::cerr << "Número inválido" << std::endl;
            return;
        }

           std::cout << pessoas[n - 1]->apresentarDados() << std::endl;

        break;
        }
    default:{
        std::cerr << "Opção inválida" << std::endl;
        break;
        }
    }
}

void mostrarTipo() {
    std::cout << "Escolha objeto: " << std::endl;
    for (size_t j = 0; j < pessoas.size(); ++j) {
        std::cout << (j + 1) << " - " << pessoas[j]->getNomeOficial() << std::endl;
    }

    std::cout << "\nInsira o número correspondente: ";
    int n;
    std::cin >> n;
    std::cin.ignore();

    if (n <= 0 || n > pessoas.size()) {
        std::cerr << "Número inválido" << std::endl;
        return;
    }

    std::cout << "Tipo do Objeto: " << pessoas[n - 1]->verificarTipo() << std::endl;

}
int validacoa(int n){
    if (n>=0 && n<=6){
        return n;
    }else{
        std::cout << "Número inválido. Selecione um número entre 0 e 6: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    
    }
}


int main()
{
    int n;

    do
    {
        std::cout << "Menu Interativo\n"
                  << std::endl;
        std::cout << "1 - Criar Objeto\n2 - Calcular Demanda de uma Rota\n3 - Exibir Número de Rotas\n";
        std::cout << "4 - Exibir Número de Ponto de Parada\n5 - Exibir Informação de um Objeto\n6 - Exibir Tipo do Objeto\n";
        std::cout << "0 - Sair do Programa\n"
                  << std::endl;

        std::cout << "Escolha o número correspondente: ";
        std::cin >> n;
        validacoa(n);
        std::cin.ignore();

        switch (n)
        {
        case 1:
            menuCriacao();
            break;
        case 2:
        {
            Rota rota = escolherRota();
            std::cout << "\nDemanda da Rota " << rota.getId() << ": " << rota.demanda() << "\n"
                      << std::endl;
        }
        break;
        case 3:
            std::cout << "\nNúmero de Rotas Criadas: " << rotas.size() << "\n"
                      << std::endl;
            break;
        case 4:
            std::cout << "\nNúmero de Pontos Criados: " << pontos.size() << "\n"
                      << std::endl;
            break;
        case 5:
            mostrarDados();
            break;
        case 6:
            mostrarTipo();
            break;
        }

    } while (n != 0);

    return 0;
}
