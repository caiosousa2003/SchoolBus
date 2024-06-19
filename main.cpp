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

using namespace std;

void menuCriacao()
{
    int n;

    do
    {
        cout << "Menu Interativo\n"
             << endl;
        cout << "1 - Criar Aluno\n2 - Criar Motorista\n3 - Criar Contrato\n4 - Criar Escola\n";
        cout << "5 - Criar Veiculo\n6 - Criar Ponto de Parada\n7 - Criar Nova Rota\n";
        cout << "8 - Criar Fornecedor\n0 - Voltar\n"
             << endl;

        cout << "Escolha o número correspondente: ";
        cin >> n;
        cin.ignore();

        switch (n)
        {
        case 1:
            criarAluno();
            break;
        case 2:
            // Placeholder para a função criarMotorista()
            cout << "Criar Motorista" << endl;
            break;
        case 3:
            // Placeholder para a função criarContrato()
            cout << "Criar Contrato" << endl;
            break;
        case 4:
            // Placeholder para a função criarEscola()
            cout << "Criar Escola" << endl;
            break;
        case 5:
            // Placeholder para a função criarVeiculo()
            cout << "Criar Veiculo" << endl;
            break;
        case 6:
            // Placeholder para a função criarPontoParada()
            cout << "Criar Ponto de Parada" << endl;
            break;
        case 7:
            // Placeholder para a função criarRota()
            cout << "Criar Nova Rota" << endl;
            break;
        case 8:
            criarFornecedor();
            break;
        }
    } while (n != 0);
}

Endereco criarEndereco()
{
    string rua, complemento, bairro;
    int numero;

    cout << "Rua: ";
    getline(cin, rua);
    cout << "Número: ";
    cin >> numero;
    cin.ignore();
    cout << "Complemento: ";
    getline(cin, complemento);
    cout << "Bairro: ";
    getline(cin, bairro);

    return Endereco(rua, numero, complemento, bairro);
}

void criarAluno()
{
    if (escolas.empty())
    {
        cout << "\nNenhuma escola cadastrada ainda!\nVoltando...\n"
             << endl;
    }
    else
    {
        int i;
        cout << "\nSelecione a Escola: " << endl;
        for (size_t idx = 0; idx < escolas.size(); ++idx)
        {
            cout << idx << " - " << escolas[idx].getNome() << endl;
        }
        cout << "\nInsira o número correspondente: ";
        cin >> i;
        cin.ignore();

        string nomeCivil, nome, mae, pai, naturalidade, cpf, telefone, serie;
        cout << "\nPreencha as seguintes informações:" << endl;
        cout << "Nome Civil: ";
        getline(cin, nomeCivil);
        cout << "Nome Social: ";
        getline(cin, nome);
        cout << "Nome da Mãe: ";
        getline(cin, mae);
        cout << "Nome do Pai: ";
        getline(cin, pai);
        cout << "Naturalidade: ";
        getline(cin, naturalidade);
        cout << "CPF: ";
        getline(cin, cpf);

        tm dataNascimento = {};
        cout << "Data de Nascimento (dd/MM/yyyy): ";
        string dataNascimentoStr;
        getline(cin, dataNascimentoStr);
        istringstream ss(dataNascimentoStr);
        ss >> get_time(&dataNascimento, "%d/%m/%Y");
        if (ss.fail())
        {
            cout << "Formato de data inválido." << endl;
            return;
        }

        cout << "Telefone: ";
        getline(cin, telefone);

        int matricula;
        cout << "Matrícula: ";
        cin >> matricula;
        cin.ignore();

        cout << "Série: ";
        getline(cin, serie);

        string endereco; // Placeholder para a função criarEndereco()
        cout << "Aluno criado com sucesso! Voltando para menu" << endl;
        escolas[i].matriculaAluno(nomeCivil, cpf, endereco, telefone, nome, mae, pai, naturalidade, dataNascimento, matricula, serie);
    }
}

void criarFornecedor()
{
    string nome, nomeFantasia, cnpj, telefone;
    int num;

    cout << "Nome Oficial: ";
    getline(cin, nome);
    cout << "Nome Fantasia: ";
    getline(cin, nomeFantasia);
    cout << "CNPJ: ";
    getline(cin, cnpj);
    cout << "Telefone: ";
    getline(cin, telefone);
    cout << "Número de Funcionários: ";
    cin >> num;
    cin.ignore();

    Endereco endereco = criarEndereco();
    pessoas.push_back("Fornecedor"); // Placeholder para adicionar objeto Fornecedor à lista de pessoas
}

void criarMotorista()
{
    int i, numcontrato = -1;
    string nomeCivil, nome, mae, pai, naturalidade, cpfcnpj, telefone, numhabilitacao, cathabilitacao;
    tm dataNascimento = {};

    cout << "\nMotorista é terceirizado (1) ou servidor (0)? ";
    cin >> i;
    cin.ignore();

    if (i == 1)
    {
        cout << "Número de Contrato: ";
        cin >> numcontrato;
        cin.ignore();
    }

    cout << "Nome Civil: ";
    getline(cin, nomeCivil);
    cout << "Nome Social: ";
    getline(cin, nome);
    cout << "Nome da Mãe: ";
    getline(cin, mae);
    cout << "Nome do Pai: ";
    getline(cin, pai);
    cout << "Naturalidade: ";
    getline(cin, naturalidade);
    cout << "CPF: ";
    getline(cin, cpfcnpj);

    cout << "Data de Nascimento (dd/MM/yyyy): ";
    string dataNascimentoStr;
    getline(cin, dataNascimentoStr);
    istringstream ss(dataNascimentoStr);
    ss >> get_time(&dataNascimento, "%d/%m/%Y");
    if (ss.fail())
    {
        cout << "Formato de data inválido." << endl;
        return;
    }

    cout << "Telefone: ";
    getline(cin, telefone);
    cout << "Número de Habilitação: ";
    getline(cin, numhabilitacao);
    cout << "Categoria de Habilitação: ";
    getline(cin, cathabilitacao);

    Endereco endereco = criarEndereco();
    Motorista motorista(nomeCivil, cpfcnpj, endereco, telefone, nome, mae, pai, naturalidade, dataNascimento, numhabilitacao, cathabilitacao, numcontrato);

    motoristas.push_back("Motorista"); // Placeholder para adicionar objeto Motorista à lista de motoristas
    cout << "Motorista criado com sucesso! Voltando para menu" << endl;
}

void criarVeiculo()
{
    string placa, modelo;
    int ano, capacidade, i, numcontrato = -1;

    cout << "Placa do Veículo: ";
    getline(cin, placa);
    cout << "Ano do Veículo: ";
    cin >> ano;
    cin.ignore();
    cout << "Modelo do Veículo: ";
    getline(cin, modelo);
    cout << "Capacidade do Veículo: ";
    cin >> capacidade;
    cin.ignore();

    cout << "\nVeiculo é alugado (1) ou próprio (0)? ";
    cin >> i;
    cin.ignore();

    if (i == 1)
    {
        cout << "Número de Contrato: ";
        cin >> numcontrato;
        cin.ignore();
    }

    Veiculo veiculo(placa, ano, modelo, capacidade, numcontrato);
    veiculos.push_back("Veiculo"); // Placeholder para adicionar objeto Veiculo à lista de veiculos
    cout << "Veiculo criado com sucesso! Voltando para menu" << endl;
}

void criarContrato()
{
    int numcontrato, i, n;
    string dateinicioStr, datefimStr;
    double valor;
    tm dateinicio = {}, datefim = {};

    cout << "Número de Contrato: ";
    cin >> numcontrato;
    cin.ignore();

    cout << "Data de Início (dd/MM/yyyy): ";
    getline(cin, dateinicioStr);
    istringstream ssInicio(dateinicioStr);
    ssInicio >> get_time(&dateinicio, "%d/%m/%Y");
    if (ssInicio.fail())
    {
        cout << "Formato de data inválido." << endl;
        return;
    }

    cout << "Data de Fim (dd/MM/yyyy): ";
    getline(cin, datefimStr);
    istringstream ssFim(datefimStr);
    ssFim >> get_time(&datefim, "%d/%m/%Y");
    if (ssFim.fail())
    {
        cout << "Formato de data inválido." << endl;
        return;
    }

    cout << "Valor: ";
    cin >> valor;
    cin.ignore();

    Contrato contrato(numcontrato, dateinicio, datefim, valor);

    cout << "Gostaria de adicionar fornecedor ao contrato? Sim (1) ou Não (0): ";
    cin >> i;
    cin.ignore();

    if (i == 1)
    {
        for (size_t idx = 0; idx < pessoas.size(); ++idx)
        {
            cout << idx << " - " << "NomeOficial"; 
        }
        cout << "\nInsira o número correspondente: ";
        cin >> n;
        cin.ignore();

        contrato.addFornecedor(/* parâmetros apropriados */);
    }
    contratos.push_back("Contrato"); 
}
//////////modificar aqui em cima, lógica de adicionar fornecedor ao contrato


void criarEscola()
{
    string nome, nomeFantasia, cnpj, telefone;
    int num;

    cout << "Nome Oficial: ";
    getline(cin, nome);
    cout << "Nome Fantasia: ";
    getline(cin, nomeFantasia);
    cout << "CNPJ: ";
    getline(cin, cnpj);
    cout << "Telefone: ";
    getline(cin, telefone);
    cout << "Número de Funcionários: ";
    cin >> num;
    cin.ignore();

    Endereco endereco = criarEndereco();
    escolas.push_back("Escola"); 
    cout << "Escola criada com sucesso! Voltando para menu" << endl;
}

void criarPontoParada()
{
    string nome;
    double latitude, longitude;
    int id, i = -1, n = -1;
    vector<string> alunos;

    cout << "Nome da Localização: ";
    getline(cin, nome);
    cout << "Latitude: ";
    cin >> latitude;
    cin.ignore();
    cout << "Longitude: ";
    cin >> longitude;
    cin.ignore();
    cout << "Identificação (Número): ";
    cin >> id;
    cin.ignore();

    do
    {
        cout << "\nSelecione a Escola do aluno para esse ponto de parada: ";
        for (size_t idx = 0; idx < escolas.size(); ++idx)
        {
            cout << (idx + 1) << " - " << "Nome"; 
        }
        cout << "\nInsira o número correspondente (Quando finalizar, insira 0): ";
        cin >> i;
        cin.ignore();
        if (i == 0)
            break;
        do
        {
            cout << "\nSelecione os Alunos para esse ponto de parada: ";
            vector<string> alunosEscola = escolas[i - 1].getAlunos();
            for (size_t j = 0; j < alunosEscola.size(); ++j)
            {
                cout << (j + 1) << " - " << "NomeCivil"; 
            }
            cout << "\nInsira o número correspondente (Quando finalizar, insira 0): ";
            cin >> n;
            cin.ignore();
            if (n == 0)
                break;
            alunos.push_back(alunosEscola[n - 1]);
        } while (n != 0);
    } while (i != 0);

    pontos.push_back("PontoDeParada"); 
    cout << "Ponto de Parada criado com sucesso! Voltando para menu" << endl;
}

void criarRota()
{
    Rota rota;
    int i = -1;

    do
    {
        cout << "Rota criada com sucesso! Adicionando pontos a ela:";
        for (size_t idx = 0; idx < pontos.size(); ++idx)
        {
            cout << (idx + 1) << " - " << "Nome"; 
        }
        cout << "\nInsira o número correspondente (Quando finalizar, insira 0): ";
        cin >> i;
        cin.ignore();
        if (i == 0)
            break;
        rota.addPontoDeParada(PontoDeParada("Nome", 0, 0, 0, vector<string>())); 
        // Adicionar o "nome" certo, consertar a lógica do PontoDeParada
    } while (i != 0);

    rotas.push_back("Rota"); 
    cout << "Pontos adicionados com sucesso! Voltando para menu" << endl;
}

Rota escolherRota()
{
    cout << "Escolha a rota (pelo ID) para calcular demanda:" << endl;
    for (Rota x : rotas)
    {
        cout << x.getId() << endl;
    }
    cout << "\nInsira o número correspondente: ";
    int i;
    cin >> i;
    cin.ignore();

    return rotas[i - 1];
}

void mostrarDados()
{
    cout << "Escolha o objeto que quer ver\n1-Aluno\n2-Motorista\n3-Escola\n4-Fornecedor";
    int i;
    cin >> i;
    cin.ignore();

    int n;
    int a;

    switch (i)
    {
    case 1:
        cout << "\nSelecione a Escola do aluno: " << endl;
        for (Escola x : escolas)
        {
            cout << (escolas.indexOf(x) + 1) << " - " << x.getNome() << endl;
        }
        cout << "\nInsira o número correspondente: ";
        cin >> n;
        cin.ignore();

        cout << "\nSelecione os Alunos para esse ponto de parada: " << endl;
        for (Aluno y : escolas[n - 1].getAlunos())
        {
            cout << (escolas[n - 1].getAlunos().indexOf(y) + 1) << " - " << y.getNomeCivil() << endl;
        }
        cout << "\nInsira o número correspondente: ";
        cin >> a;
        cin.ignore();

        cout << escolas[n - 1].getAlunos()[a - 1].apresentarDados() << endl;
        break;
    case 3:
        cout << "\nSelecione a Escola: " << endl;
        for (Escola x : escolas)
        {
            cout << (escolas.indexOf(x) + 1) << " - " << x.getNome() << endl;
        }
        cout << "\nInsira o número correspondente: ";
        cin >> n;
        cin.ignore();

        cout << escolas[n - 1].apresentarDados() << endl;
        break;
    case 2:
        cout << "\nSelecione o Motorista: " << endl;
        for (Motorista x : motoristas)
        {
            cout << (motoristas.indexOf(x) + 1) << " - " << x.getNomeCivil() << endl;
        }
        cout << "\nInsira o número correspondente: ";
        cin >> n;
        cin.ignore();

        cout << motoristas[n - 1].apresentarDados() << endl;
        break;
    case 4:
        cout << "\nSelecione o Fornecedor: " << endl;
        for (Pessoa x : pessoas)
        {
            cout << (pessoas.indexOf(x) + 1) << " - " << x.getNomeOficial() << endl;
        }
        cout << "\nInsira o número correspondente: ";
        cin >> n;
        cin.ignore();

        cout << pessoas[n - 1].apresentarDados() << endl;
        break;
    }
}

void mostrarTipo()
{
    cout << "Escolha objeto: " << endl;
    for (Pessoa x : pessoas)
    {
        cout << (pessoas.indexOf(x) + 1) << " - " << x.getNomeOficial() << endl;
    }

    cout << "\nInsira o número correspondente: ";
    int n;
    cin >> n;
    cin.ignore();

    cout << "Tipo do Objeto: " << pessoas[n - 1].verificarTipo() << endl;
}

int main()
{
    int n;

    do
    {
        cout << "Menu Interativo\n"
             << endl;
        cout << "1 - Criar Objeto\n2 - Calcular Demanda de uma Rota\n3 - Exibir Número de Rotas\n";
        cout << "4 - Exibir Número de Ponto de Parada\n5 - Exibir Informação de um Objeto\n6 - Exibir Tipo do Objeto\n";
        cout << "0 - Sair do Programa\n"
             << endl;

        cout << "Escolha o número correspondente: ";
        cin >> n;
        cin.ignore();

        switch (n)
        {
        case 1:
            menuCriacao();
            break;
        case 2:
        {
            string rota = escolherRota();
            // ????? essa função não existe em lugar nenhum
            cout << "\nDemanda da Rota " << rota << ": [Demanda]" << "\n"
                 << endl;
        }
        break;
        case 3:
            cout << "\nNúmero de Rotas Criadas: " << rotas.size() << "\n"
                 << endl;
            break;
        case 4:
            cout << "\nNúmero de Pontos Criados: " << pontos.size() << "\n"
                 << endl;
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
