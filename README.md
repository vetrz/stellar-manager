# Stellar Manager

Sistema de gerenciamento de dados de constelações desenvolvido em C++. O projeto foca na manipulação eficiente de dados astronômicos através de uma interface de terminal (TUI) interativa.

## Funcionalidades

* **Gerenciamento de Dados**: Leitura de arquivos CSV para carregamento de constelações.
* **Operações CRUD**: Inclusão de novas constelações, edição de registros existentes por ID e remoção.
* **Interface TUI**: Navegação visual construída com a biblioteca FTXUI.
* **Visualização**: Paginação de itens (15 por página) e tabelas com ajuste automático de redimensionamento.
* **Filtros**: Suporte a filtragem de constelações por critérios como hemisfério.

---

## Estrutura do Projeto

A arquitetura é modular, separando as responsabilidades em namespaces distintos:

* **core**: Lógica base e estruturas de dados customizadas (Vetor).
* **infra**: Persistência de dados e carregamento de arquivos (DataLoader).
* **models**: Definições das entidades de negócio.
* **services**: Regras de negócio e processamento de dados.
* **ui**: Gerenciamento da interface de usuário e estados de exibição.

---

## Requisitos

* Compilador C++ (suporte a C++17 ou superior).
* CMake (mínimo 3.10).
* Biblioteca FTXUI.

## Compilação e Execução

### 1. Compilação via CMake

O projeto utiliza um sistema de build automatizado para gerenciar as dependências e módulos.

```bash
mkdir build
cd build
cmake ..
cmake --build .

```

### 2. Execução

Após a compilação, o binário estará disponível no diretório `build`. Certifique-se de que o arquivo de dados CSV está no diretório esperado pelo sistema.

```bash
./stellar

```

---

## Controles e Navegação

* **Setas Direcionais**: Navegação entre menus, campos de input e itens da lista.
* **Enter**: Confirmação de seleções, submissão de formulários e salvamento de edições.
* **ID Navigation**: A edição e remoção de constelações são realizadas através da busca por ID único.
