# Trabalho - Estrutura de Dados

Este projeto é um trabalho proposto pelo professor Pedro Kilansky na disciplina de **Estrutura de Dados** do Centro Universitário Uniruy Wyden.

O proposito visa o aprendizado de algoritimos e estruturas complexas no cotidiano da programação.

### Membros do Trabalho:

<table>
  <thead>
    <tr>
      <th>Nome</th>
      <th>Matrícula</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Sinézio da Silva Ramos Junior</td>
      <td>202302375081</td>
    </tr>
    <tr>
      <td>Erick Mota Macedo da Silva</td>
      <td>202503032701</td>
    </tr>
    <tr>
      <td>Fulano de tal</td>
      <td>Matricula de fulano</td>
    </tr>
  </tbody>
</table>

## Estrutura do Projeto
Este projeto está organizado da seguinte forma:

* **build/:** Contém o arquivo executável main.exe que é gerado após a compilação do código-fonte.

* **include/:** Armazena os arquivos de cabeçalho (.h), que declaram funções e estruturas usadas no projeto.

* **source/:** Contém os arquivos de código-fonte (.cpp), onde a lógica principal do programa é implementada.

## Como Configurar o Ambiente de Desenvolvimento

Para rodar este projeto no VS Code, você precisa ter as seguintes ferramentas instaladas:

### Extensão C/C++ do VS Code: 

Essa extensão é essencial para a compilação e depuração de projetos C e C++ no editor. Para instalar, abra o VS Code, vá para a aba de Extensões (ou pressione Ctrl+Shift+X), procure por "C/C++" e clique em Instalar.

### MinGW (Minimalist GNU for Windows): 
É um conjunto de ferramentas de desenvolvimento que inclui o compilador GCC/G++. Você pode baixá-lo e seguir as instruções de instalação no site oficial do VS Code.

## Como Compilar e Executar o Código
Siga estes passos para gerar o executável e rodar o projeto:

* Abra o terminal integrado do VS Code.

* Execute o seguinte comando para compilar o código e gerar o arquivo main.exe na pasta build:

```
g++ (Get-ChildItem source\*.c) -Iinclude -o build\main.exe
```
Após o comando ser executado, o arquivo main.exe estará disponível na pasta build.

* Para executar o programa, navegue até a pasta build no terminal e digite o nome do executável:

```
./build/main.exe
```
