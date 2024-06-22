#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>

#include "Aluno.hpp"
#include "Contrato.hpp"
#include "Endereco.hpp"
#include "Escola.hpp"
#include "Fornecedor.hpp"
#include "Motorista.hpp"
#include "PontoDeParada.hpp"
#include "Rota.hpp"
#include "Veiculo.hpp"



vector<Escola> escolas;
vector<Motorista> motoristas; // Placeholder para a classe Motorista
vector<Veiculo> veiculos;     // Placeholder para a classe Veiculo
vector<Contrato> contratos;   // Placeholder para a classe Contrato
vector<PontoDeParada> pontos; // Placeholder para a classe PontoDeParada
vector<Rota> rotas;           // Placeholder para a classe Rota
vector<Pessoa> pessoas;       // Placeholder para a classe Pessoa

// using namespace std;

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
        std::cin.ignore();

        switch (n)
        {
        case 1:
            criarAluno();
            break;
        case 2:
            // Placeholder para a função criarMotorista()
            std::cout << "Criar Motorista" << std::endl;
            break;
        case 3:
            // Placeholder para a função criarContrato()
            std::cout << "Criar Contrato" << std::endl;
            break;
        case 4:
            // Placeholder para a função criarEscola()
            std::cout << "Criar Escola" << std::endl;
            break;
        case 5:
            // Placeholder para a função criarVeiculo()
            std::cout << "Criar Veiculo" << std::endl;
            break;
        case 6:
            // Placeholder para a função criarPontoParada()
            std::cout << "Criar Ponto de Parada" << std::endl;
            break;
        case 7:
            // Placeholder para a função criarRota()
            std::cout << "Criar Nova Rota" << std::endl;
            break;
        case 8:
            criarFornecedor();
            break;
        }
    } while (n != 0);
}

Endereco criarEndereco()
{
    std::string rua, complemento, bairro;
    int numero;

    std::cout << "Rua: ";
    std::getline(cin, rua);
    std::cout << "Número: ";
    std::cin >> numero;
    std::cin.ignore();
    std::cout << "Complemento: ";
    std::getline(cin, complemento);
    std::cout << "Bairro: ";
    std::getline(cin, bairro);

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
            std::cout << idx << " - " << escolas[idx].getNome() << std::endl;
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> i;
        std::cin.ignore();

        std::string nomeCivil, nome, mae, pai, naturalidade, cpf, telefone, serie;
        std::cout << "\nPreencha as seguintes informações:" << std::endl;
        std::cout << "Nome Civil: ";
        std::getline(cin, nomeCivil);
        std::cout << "Nome Social: ";
        std::getline(cin, nome);
        std::cout << "Nome da Mãe: ";
        std::getline(cin, mae);
        std::cout << "Nome do Pai: ";
        std::getline(cin, pai);
        std::cout << "Naturalidade: ";
        std::getline(cin, naturalidade);
        std::cout << "CPF: ";
        std::getline(cin, cpf);

        tm dataNascimento = {};
        std::cout << "Data de Nascimento (dd/MM/yyyy): ";
        std::string dataNascimentoStr;
        std::getline(cin, dataNascimentoStr);
        std::istringstream ss(dataNascimentoStr);
        ss >> get_time(&dataNascimento, "%d/%m/%Y");
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

        std::string endereco; // Placeholder para a função criarEndereco()
        std::cout << "Aluno criado com sucesso! Voltando para menu" << std::endl;
        escolas[i].matriculaAluno(nomeCivil, cpf, endereco, telefone, nome, mae, pai, naturalidade, dataNascimento, matricula, serie);
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
    pessoas.push_back("Fornecedor"); // Placeholder para adicionar objeto Fornecedor à lista de pessoas
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
    cout << "CPF: ";
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

    motoristas.push_back("Motorista"); // Placeholder para adicionar objeto Motorista à lista de motoristas
    std::cout << "Motorista criado com sucesso! Voltando para menu" << endl;
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
    veiculos.push_back("Veiculo"); // Placeholder para adicionar objeto Veiculo à lista de veiculos
    std::cout << "Veiculo criado com sucesso! Voltando para menu" << endl;
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
    std::getline(cin, dateinicioStr);
    std::istringstream ssInicio(dateinicioStr);
    ssInicio >> get_time(&dateinicio, "%d/%m/%Y");
    if (ssInicio.fail())
    {
        std::cout << "Formato de data inválido." << std::endl;
        return;
    }

    std::cout << "Data de Fim (dd/MM/yyyy): ";
    std::getline(std::cin, datefimStr);
    std::istringstream ssFim(datefimStr);
    ssFim >> get_time(&datefim, "%d/%m/%Y");
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
            std::cout << idx << " - " << "NomeOficial"; 
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> n;
        std::cin.ignore();

        contrato.addFornecedor(/* parâmetros apropriados */);
    }
    contratos.push_back("Contrato"); 
}
//////////modificar aqui em cima, lógica de adicionar fornecedor ao contrato


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
    escolas.push_back("Escola"); 
    std::cout << "Escola criada com sucesso! Voltando para menu" << std::endl;
}

void criarPontoParada()
{
    std::string nome;
    double latitude, longitude;
    int id, i = -1, n = -1;
    std::vector<std::string> alunos;

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
            std::cout << (idx + 1) << " - " << "Nome"; 
        }
        std::cout << "\nInsira o número correspondente (Quando finalizar, insira 0): ";
        std::cin >> i;
        std::cin.ignore();
        if (i == 0)
            break;
        do
        {
            std::cout << "\nSelecione os Alunos para esse ponto de parada: ";
            vector<string> alunosEscola = escolas[i - 1].getAlunos();
            for (size_t j = 0; j < alunosEscola.size(); ++j)
            {
                std::cout << (j + 1) << " - " << "NomeCivil"; 
            }
            std::cout << "\nInsira o número correspondente (Quando finalizar, insira 0): ";
            std::cin >> n;
            std::cin.ignore();
            if (n == 0)
                break;
            alunos.push_back(alunosEscola[n - 1]);
        } while (n != 0);
    } while (i != 0);

    pontos.push_back("PontoDeParada"); 
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
            std::cout << (idx + 1) << " - " << "Nome"; 
        }
        std::cout << "\nInsira o número correspondente (Quando finalizar, insira 0): ";
        std::cin >> i;
        std::cin.ignore();
        if (i == 0)
            break;
        rota.addPontoDeParada(PontoDeParada("Nome", 0, 0, 0, vector<string>())); 
        // Adicionar o "nome" certo, consertar a lógica do PontoDeParada
    } while (i != 0);

    rotas.push_back("Rota"); 
    std::cout << "Pontos adicionados com sucesso! Voltando para menu" << std::endl;
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

void mostrarDados()
{
    std::cout << "Escolha o objeto que quer ver\n1-Aluno\n2-Motorista\n3-Escola\n4-Fornecedor";
    int i;
    std::cin >> i;
    std::cin.ignore();

    int n;
    int a;

    switch (i)
    {
    case 1:
        std::cout << "\nSelecione a Escola do aluno: " << std::endl;
        for (Escola x : escolas)
        {
            std::cout << (escolas.indexOf(x) + 1) << " - " << x.getNome() << std::endl;
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> n;
        std::cin.ignore();

        std::cout << "\nSelecione os Alunos para esse ponto de parada: " << std::endl;
        for (Aluno y : escolas[n - 1].getAlunos())
        {
            cout << (escolas[n - 1].getAlunos().indexOf(y) + 1) << " - " << y.getNomeCivil() << endl;
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> a;
        std::cin.ignore();

        std::cout << escolas[n - 1].getAlunos()[a - 1].apresentarDados() << std::endl;
        break;
    case 3:
        std::cout << "\nSelecione a Escola: " << std::endl;
        for (Escola x : escolas)
        {
            std::cout << (escolas.indexOf(x) + 1) << " - " << x.getNome() << std::endl;
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> n;
        std::cin.ignore();

        std::cout << escolas[n - 1].apresentarDados() << std::endl;
        break;
    case 2:
        std::cout << "\nSelecione o Motorista: " << std::endl;
        for (Motorista x : motoristas)
        {
            std::cout << (motoristas.indexOf(x) + 1) << " - " << x.getNomeCivil() << std::endl;
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> n;
        std::cin.ignore();

        std::cout << motoristas[n - 1].apresentarDados() << std::endl;
        break;
    case 4:
        std::cout << "\nSelecione o Fornecedor: " << std::endl;
        for (Pessoa x : pessoas)
        {
            std::cout << (pessoas.indexOf(x) + 1) << " - " << x.getNomeOficial() << std::endl;
        }
        std::cout << "\nInsira o número correspondente: ";
        std::cin >> n;
        std::cin.ignore();

        std::cout << pessoas[n - 1].apresentarDados() << std::endl;
        break;
    }
}

void mostrarTipo()
{
    std::cout << "Escolha objeto: " << std::endl;
    for (Pessoa x : pessoas)
    {
        std::cout << (pessoas.indexOf(x) + 1) << " - " << x.getNomeOficial() << std::endl;
    }

    std::cout << "\nInsira o número correspondente: ";
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::cout << "Tipo do Objeto: " << pessoas[n - 1].verificarTipo() << std::endl;
}

int main()
{
    int n;

    do
    {
        std::cout << "Menu Interativo\n"
             << endl;
        std::cout << "1 - Criar Objeto\n2 - Calcular Demanda de uma Rota\n3 - Exibir Número de Rotas\n";
        std::cout << "4 - Exibir Número de Ponto de Parada\n5 - Exibir Informação de um Objeto\n6 - Exibir Tipo do Objeto\n";
        std::cout << "0 - Sair do Programa\n"
             << std::endl;

        std::cout << "Escolha o número correspondente: ";
        std::cin >> n;
        std::cin.ignore();

        switch (n)
        {
        case 1:
            menuCriacao();
            break;
        case 2:
        {
            std::string rota = escolherRota();
            // ????? essa função não existe em lugar nenhum
            std::cout << "\nDemanda da Rota " << rota << ": [Demanda]" << "\n"
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
