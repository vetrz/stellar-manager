# Stellar Manager

Sistema de gerenciamento de dados de constelações desenvolvido em C++. O projeto foca na manipulação eficiente de dados astronômicos através de uma interface de terminal (TUI) interativa.

## Funcionalidades Implementadas

- **Gerenciamento CRUD**: Sistema completo para adicionar, listar, editar (via ID) e remover constelações.
- **Interface TUI**: Navegação visual construída com a biblioteca FTXUI, incluindo suporte a inputs e tabelas dinâmicas.
- **Paginação de Dados**: Exibição otimizada de registros com paginação de 15 em 15 itens.
- **Filtros Avançados**: Sistema de filtragem flexível utilizando lambdas e `std::function` para critérios como hemisfério e outras propriedades astronômicas.
- **Estrutura de Dados Customizada**: Utilização de uma implementação própria de vetor com alocação dinâmica de memória.
- **Persistência**: Carregamento e tratamento de dados através de arquivos CSV (DataLoader).

# Estrutura de Diretórios

O projeto segue uma organização modular, separando as responsabilidades em subdiretórios específicos para facilitar a manutenção e escalabilidade:
Plaintext

```
stellar-manager/
├── data/          # Arquivos de dados brutos (CSV)
├── include/       # Definições de cabeçalho (.hpp)
├── src/           # Implementações (.cpp)
│   ├── core/      # Estrutura base: Vetor customizado
│   ├── infra/     # Persistência de dados e carregamento de arquivos
│   ├── models/    # Definição das entidades de negócio (Constellation)
│   ├── services/  # Regras de negócio e processamento (filtros, buscas)
│   └── ui/        # Interface de usuário (FTXUI), menus e telas
├── build.sh       # Script de automação de compilação
├── CMakeLists.txt # Configuração principal do CMake
└── README.md      # Documentação do projeto
```

## Compilação e Execução

### 1. Requisitos

- Compilador C++ com suporte a C++17 ou superior.
- CMake (mínimo 3.10).
- Biblioteca FTXUI.

### 2. Script de Automação

O projeto inclui um script `build.sh` na raiz para automatizar o processo de criação do diretório de build e compilação.

```bash
chmod +x build.sh
./build.sh

```

### 3. Compilação via CMake

Caso prefira executar os comandos manualmente:

```bash
mkdir build
cd build
cmake ..
cmake --build .

```

### 4. Execução

Após a compilação, o binário será gerado dentro da pasta `build`.

```bash
./stellar

```

---

## Controles e Navegação

- **Setas**: Navegação entre menus e campos de entrada de dados.
- **Enter**: Confirmação de ações e salvamento de registros.
- **Esc**: Sair das demais opções e volta para o "Listar Tudo".
