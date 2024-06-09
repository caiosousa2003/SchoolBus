# Projeto SchoolBus

Este é um projeto de exemplo que implementa um sistema de gerenciamento de transporte escolar para a Secretaria de Educação. O projeto é desenvolvido em Java e utiliza conceitos de programação orientada a objetos.

## Funcionalidades

O projeto SchoolBus possui as seguintes funcionalidades:

1. Cadastro e gerenciamento de Motoristas.
2. Cadastro e gerenciamento de Veículos.
3. Cadastro e gerenciamento de Contratos para motoristas, veículos e fornecedores.
4. Cadastro e gerenciamento de Alunos.
5. Cadastro e gerenciamento de Escolas.
6. Cadastro e gerenciamento de Fornecedores.
7. Definição de Pontos de Parada para rotas de transporte escolar.
8. Criação e gerenciamento de Rotas de transporte escolar.
9. Cálculo da demanda total de alunos em cada ponto de parada de uma rota.

## Estrutura do Projeto

O projeto SchoolBus está organizado em classes Python separadas, cada uma representando uma entidade ou funcionalidade do sistema, cada classe está implementada em um arquivo python individual, e possui um código teste para verificação da funcionalidade individual de cada classe. As principais classes incluem:

- `Motorista`: Representa informações sobre motoristas, incluindo dados pessoais e contratos associados.
- `Veiculo`: Representa informações sobre veículos, incluindo detalhes como placa, modelo e contratos associados.
- `Contrato`: Representa contratos associados a motoristas e veículos.
- `Aluno`: Representa informações sobre alunos, incluindo dados pessoais e associação a escolas e pontos de parada.
- `Escola`: Representa informações sobre escolas, incluindo detalhes de contato e endereço.
- `PontoDeParada`: Representa pontos de parada para rotas de transporte escolar, incluindo a associação de alunos.
- `Rota`: Representa rotas de transporte escolar, incluindo pontos de parada e cálculo de demanda.
- `Fornecedor`: Representa as informações sobre o fornecedor, incluindo dados empresarias e de contrato.
- Há a existência de outras classes auxiliares como `Endereço` e outras classes utilizadas para confecção das demais classes, que inclusive, poderiam ser implementadas como abstratas, como `Pessoa`, `PessoaJuridica` e `PessoaFisica`.

## Como Executar o Projeto

1. Clone ou faça o download deste repositório para o seu computador.
2. Certifique-se de ter o Pyhton instalado em sua máquina.
3. Compile os arquivos `.py` em um terminal ou IDE de sua escolha.
4. Execute a classe `AplicacaoSchoolBus` para iniciar o programa interativo.
5. Caso queira avaliar as vlasses individualmente, pode executar os arquivos individuais, já existe um código teste.

## Uso do Programa

O programa interativo permitirá que você crie e gerencie motoristas, veículos, contratos, alunos, escolas, pontos de parada e rotas. Você também poderá calcular a demanda total de alunos em uma rota específica.

Siga as instruções no programa para usar essas funcionalidades.
