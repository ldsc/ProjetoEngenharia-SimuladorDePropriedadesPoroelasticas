# Table of Contents

1.  [Nome do Desafio Tecnológico](#orgf60404e)
    1.  [ProjetoEngenharia-SimuladorDePropriedadesPoroelasticas](#orgb48a795)
    2.  [https://github.com/ldsc/ProjetoEngenharia-SimuladorDePropriedadesPoroelasticas](#orgef8def1)
2.  [Nome do Software:](#org306e29a)
3.  [Resumo e/ou informação extra:](#org78f2222)
4.  [Versão:](#org9dd9a48)
5.  [Data:](#org8301597)
6.  [Autores de Contato:](#org260c077)
7.  [Lista dos Autores:](#orgbcb907a)
8.  [Áreas de pesquisa vinculadas:](#orgcc39e80)
9.  [Vínculo com:](#org22bff78)
10. [Paradigmas:](#org66b23db)
11. [Tipo de Interface:](#org7d2cb4b)
12. [Plataformas Suportadas:](#org61b30a7)
13. [Linguagens Utilizadas:](#org82236e9)
14. [Bibliotecas/Softwares Utilizados (Dependências):](#orgb2d77a6)
15. [Funcionalidades Principais:](#org833cf44)
16. [Estrutura do Projeto:](#org_struct)
17. [Manual do Usuário e Desenvolvedor:](#org233f597)
18. [Instalação e Compilação:](#orgf8155fe)
19. [Guia de Uso Rápido:](#org_usage)
20. [Trabalhos Futuros e Sugestões de Melhoria:](#org6648983)
21. [Licença:](#org863bfd9)



<a id="orgf60404e"></a>

# Nome do Desafio Tecnológico


<a id="orgb48a795"></a>

## ProjetoEngenharia-SimuladorDePropriedadesPoroelasticas


<a id="orgef8def1"></a>

## [https://github.com/ldsc/ProjetoEngenharia-SimuladorDePropriedadesPoroelasticas](https://github.com/ldsc/ProjetoEngenharia-SimuladorDePropriedadesPoroelasticas)


<a id="org306e29a"></a>

# Nome do Software:

-   **PEC - Pore Elastic Calculator**


<a id="org78f2222"></a>

# Resumo e/ou informação extra:

-   O **PEC (Pore Elastic Calculator)** é uma ferramenta computacional robusta desenvolvida em C++ voltada para a área de Física de Rochas e Geomecânica.
-   O software calcula as propriedades elásticas efetivas (**Módulo de Compressibilidade - K** e **Módulo de Cisalhamento - G**) de rochas porosas com base em sua composição mineralógica e porosidade.
-   Utiliza as teorias clássicas de meio efetivo (EMT) de **Voigt** (limite superior), **Reuss** (limite inferior) e **Hill** (média aritmética) para fornecer estimativas confiáveis.
-   O sistema inclui geração automática de gráficos de alta qualidade (perfis de profundidade, crossplots K x Porosidade e análises de sensibilidade mineralógica) utilizando o **Gnuplot** como motor de renderização backend.
-   Projeto desenvolvido com foco em performance, modularidade e facilidade de extensão para novos modelos físicos.


<a id="org9dd9a48"></a>

# Versão:

-   **3.0** (Versão final com banco de dados de minerais, plotagem automatizada e suporte multiplataforma via CMake).


<a id="org8301597"></a>

# Data:

-   2025/2 - Segundo semestre.


<a id="org260c077"></a>

# Autores de Contato:

-   Matheus Sousa Bastos <matheus.bastos@lenep.uenf.br>
-   Nicolau Azevedo Prates <nicolauprates@lenep.uenf.br>


<a id="orgbcb907a"></a>

# Lista dos Autores:

-   Matheus Sousa Bastos
-   Nicolau Azevedo Prates
-   **Orientador:** Prof. André Duarte Bueno <bueno@lenep.uenf.br>


<a id="orgcc39e80"></a>

# Áreas de pesquisa vinculadas:

-   Engenharia de Petróleo e Exploração
-   Física de Rochas (Rock Physics)
-   Petrofísica
-   Modelagem Matemática Computacional
-   Engenharia de Software Aplicada


<a id="org22bff78"></a>

# Vínculo com:

-   Trabalho da disciplina **Projeto de Software Aplicado a Engenharia**.
    [https://sites.google.com/view/professorandreduartebueno/ensino/projeto-de-software-aplicado?authuser=0](https://sites.google.com/view/professorandreduartebueno/ensino/projeto-de-software-aplicado?authuser=0)
-   Laboratório de Engenharia e Exploração de Petróleo (**LENEP/UENF**).
-   Curso de Engenharia de Petróleo
    [https://sites.google.com/view/engenhariadepetroleo/in%C3%ADcio](https://sites.google.com/view/engenhariadepetroleo/in%C3%ADcio)


<a id="org66b23db"></a>

# Paradigmas:

-   **Orientação a Objetos (POO):** Utilização de classes para encapsulamento de entidades (Amostra, Mineral) e controladores.
-   **Design Patterns:**
    -   *Facade:* Na classe `CSimulador` para orquestrar o sistema.
    -   *Strategy:* Na classe `CElasticCalculator` para implementar diferentes algoritmos de física.


<a id="org7d2cb4b"></a>

# Tipo de Interface:

-   Texto (CLI/Terminal) interativo com menus numerados.
-   Saída gráfica automática via janelas externas (Gnuplot) e salvamento de arquivos PNG.


<a id="org61b30a7"></a>

# Plataformas Suportadas:

-   Windows (10/11)
-   Linux (Ubuntu/Debian/Fedora)
-   macOS (Intel e Apple Silicon)


<a id="org82236e9"></a>

# Linguagens Utilizadas:

-   **C++** (Standard 17 recomendado para compatibilidade de filesystem e containers modernos).
-   **CMake** (Linguagem de script para configuração de build).
-   **Gnuplot Scripting** (Geração dinâmica de arquivos .gp).


<a id="orgb2d77a6"></a>

# Bibliotecas/Softwares Utilizados (Dependências):

-   **CMake (>= 3.15):** Sistema de build essencial para compilar o projeto em diferentes sistemas operacionais.
-   **Gnuplot:** Essencial para a geração dos gráficos. O executável do Gnuplot deve estar acessível no PATH do sistema.
    -   *Windows:* Instalar e adicionar ao PATH.
    -   *Linux:* `sudo apt install gnuplot`
    -   *macOS:* `brew install gnuplot`
-   **Biblioteca Padrão do C++ (STL):** Uso extensivo de `<vector>`, `<map>`, `<iostream>`, `<fstream>`.


<a id="org833cf44"></a>

# Funcionalidades Principais:

1.  **Banco de Dados de Minerais:**
    -   Leitura e gerenciamento de propriedades (K, G) de minerais a partir de arquivos CSV (`database/minerais.csv`). Permite edição fácil sem recompilar o código.
2.  **Entrada de Dados Flexível:**
    -   Suporte a entrada manual interativa via terminal.
    -   Leitura em lote ("Batch Processing") via arquivos de texto estruturados (`.txt` ou `.csv`) contendo múltiplas amostras.
3.  **Cálculo Elástico Avançado:**
    -   Determinação de K e G usando as médias de Voigt (limite superior de rigidez), Reuss (limite inferior) e Hill (média aritmética).
    -   Tratamento físico da porosidade como uma fase de rigidez nula.
4.  **Visualização (Plotting):**
    -   Geração automática de gráficos salvos em `test/plots/`.
    -   Perfil de Propriedades Elásticas vs. Profundidade.
    -   Crossplot Propriedades Elásticas vs. Porosidade.
    -   Análise de sensibilidade: Variação das propriedades em função da fração de um mineral específico.


<a id="org_struct"></a>

# Estrutura do Projeto:

```text
PEC_v3/
├── build/              # Diretório de compilação (binários)
├── database/           # Arquivos de dados (minerais.csv)
├── include/            # Arquivos de cabeçalho (.h)
├── src/                # Código fonte (.cpp)
├── test/               # Arquivos de entrada para teste
│   └── Plots/          # Gráficos gerados (output)
├── CMakeLists.txt      # Configuração do CMake
├── main.cpp            # Ponto de entrada
└── README.md           # Este arquivo
```


<a id="org233f597"></a>

# Manual do Usuário e Desenvolvedor:

-   Os manuais completos em PDF (convertidos para o padrão LyX/LaTeX) encontram-se na pasta `docs/` deste repositório, contendo diagramas UML, equações físicas detalhadas e guias passo-a-passo.


<a id="orgf8155fe"></a>

# Instalação e Compilação:

O projeto utiliza **CMake** para facilitar a compilação. Siga os passos abaixo:

### Pré-requisitos
Certifique-se de ter instalado:
-   Compilador C++ (g++, clang ou MSVC)
-   CMake
-   Gnuplot

### Compilando (Linux/macOS)
```bash
# 1. Navegue até a pasta do projeto
cd PEC_v3

# 2. Crie a pasta de build
mkdir build && cd build

# 3. Configure o projeto com CMake
cmake ..

# 4. Compile
make

# 5. Execute
./PoreElasticCalculator
```

### Compilando (Windows)
1.  Abra o terminal na pasta do projeto.
2.  `mkdir build` e `cd build`.
3.  `cmake ..`
4.  `cmake --build .`
5.  Execute `.\Debug\PoreElasticCalculator.exe` (ou onde o executável foi gerado).

> **Nota:** O diretório `database/` contendo `minerais.csv` deve estar acessível relativamente ao executável (o programa busca em `../database/`).


<a id="org_usage"></a>

# Guia de Uso Rápido:

Ao iniciar o programa, o seguinte menu será exibido:

```text
--- MENU ---
1. Inserir nova amostra manualmente
2. Carregar amostra de arquivo (Lote)
3. Ver resumo das amostras
4. Gerar gráficos: profundidade e porosidade
5. Gerar gráfico de variação mineralógica
6. Configuracao: Exibir graficos na tela (Sim/Nao)
7. Sair
```

-   Para testes rápidos, utilize o arquivo `test/multiplasAmostras.txt` na opção **2**.
-   Os gráficos gerados serão salvos automaticamente na pasta `test/plots/` com carimbos de data/hora para evitar sobrescrita.


<a id="org6648983"></a>

# Trabalhos Futuros e Sugestões de Melhoria:

Para a continuidade deste projeto, sugerem-se as seguintes implementações:

1.  **Interface Gráfica (GUI):**
    -   Substituir a interação via terminal por uma interface gráfica utilizando **Qt**, facilitando a entrada de dados mineralógicos e visualização imediata dos resultados.
2.  **Modelos de Física de Rochas Avançados:**
    -   Implementar o modelo de **Hashin-Shtrikman** (limites mais estreitos e precisos que Voigt-Reuss).
    -   Implementar a equação de **Gassmann** para realizar substituição de fluidos (ex: trocar água por óleo/gás e recalcular os módulos).
3.  **Persistência de Dados:**
    -   Migrar o banco de dados de CSV para **SQLite**, permitindo consultas mais complexas sobre as propriedades dos minerais.
4.  **Visualização Integrada:**
    -   Substituir a chamada de sistema ao Gnuplot por uma biblioteca de plotagem integrada ao C++ (como QCustomPlot ou Matplot++), eliminando a dependência externa.


<a id="org863bfd9"></a>

# Licença:

-   GPL / Acadêmica (Software Livre para fins educacionais).
