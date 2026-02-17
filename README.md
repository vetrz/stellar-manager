# Stellar Manager

Sistema de gerenciamento de dados de constelações em C++.

## Como Rodar

### 1. Compilação

O projeto utiliza CMake para gerenciar a estrutura modular de pastas (core, infra, models, services e ui).

```bash
mkdir build
cd build
cmake ..
cmake --build .

```

### 2. Execução

Execute o binário gerado a partir da raiz do diretório build:

```bash
./stellar

```

---

## Estrutura de Pastas

- **data**: Arquivos de dados brutos (CSV).
- **include**: Arquivos de cabeçalho (.h).
- **src**: Arquivos de implementação (.cpp).

## Controles

- **Setas/Tab**: Navegação pela interface.
- **Enter**: Confirmar e salvar dados.

---
