
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
16. [Manual do Usuário e Desenvolvedor:](#org233f597)
17. [Instalação e Compilação:](#orgf8155fe)
18. [Trabalhos Futuros e Sugestões de Melhoria:](#org6648983)
19. [Licença:](#org863bfd9)



<a id="orgf60404e"></a>

# Nome do Desafio Tecnológico


<a id="orgb48a795"></a>

## ProjetoEngenharia-SimuladorDePropriedadesPoroelasticas


<a id="orgef8def1"></a>

## <https://github.com/ldsc/ProjetoEngenharia-SimuladorDePropriedadesPoroelasticas>


<a id="org306e29a"></a>

# Nome do Software:

-   PEC - Poro Elastic Calculator


<a id="org78f2222"></a>

# Resumo e/ou informação extra:

-   O PEC (Poro Elastic Calculator) é uma ferramenta computacional desenvolvida em C++ voltada para a área de Física de Rochas.
-   O software calcula as propriedades elásticas efetivas (Módulo de Compressibilidade - K e Módulo de Cisalhamento - G) de rochas porosas com base em sua composição mineralógica e porosidade.
-   Utiliza as teorias de meio efetivo de Voigt, Reuss e Hill para determinar os limites superior e inferior e a média das propriedades elásticas.
-   O sistema inclui geração automática de gráficos (perfis de profundidade, crossplots e análises de sensibilidade mineralógica) utilizando o Gnuplot como motor de renderização.


<a id="org9dd9a48"></a>

# Versão:

-   3.0 (Versão final com banco de dados de minerais e plotagem automatizada).


<a id="org8301597"></a>

# Data:

-   2025/2 - Segundo semestre.


<a id="org260c077"></a>

# Autores de Contato:

-   Matheus Sousa Bastos <matheus.bastos@lenep.uenf.br>
-   Nicolau Azevedo Prates <nicolau.prates@lenep.uenf.br>


<a id="orgbcb907a"></a>

# Lista dos Autores:

-   Matheus Sousa Bastos
-   Nicolau Azevedo Prates
-   Prof. André Duarte Bueno (Orientador) <bueno@lenep.uenf.br>


<a id="orgcc39e80"></a>

# Áreas de pesquisa vinculadas:

-   Engenharia de Petróleo e Exploração
-   Física de Rochas (Rock Physics)
-   Petrofísica
-   Modelagem Matemática Computacional


<a id="org22bff78"></a>

# Vínculo com:

-   Trabalho da disciplina Projeto de Software Aplicado a Engenharia.
    <https://sites.google.com/view/professorandreduartebueno/ensino/projeto-de-software-aplicado?authuser=0>
-   Laboratório de Engenharia e Exploração de Petróleo (LENEP/UENF).
-   Curso de Engenharia de Petróleo
    <https://sites.google.com/view/engenhariadepetroleo/in%C3%ADcio>


<a id="org66b23db"></a>

# Paradigmas:

-   Orientação a Objetos (C++).
-   Design Patterns (Facade, Strategy - conforme documentação técnica).


<a id="org7d2cb4b"></a>

# Tipo de Interface:

-   Texto (CLI/Terminal) com saída gráfica via janelas externas (Gnuplot).


<a id="org61b30a7"></a>

# Plataformas Suportadas:

-   Windows
-   Linux


<a id="org82236e9"></a>

# Linguagens Utilizadas:

-   C++ (Standard 17 recomendado).


<a id="orgb2d77a6"></a>

# Bibliotecas/Softwares Utilizados (Dependências):

-   ****Gnuplot:**** Essencial para a geração dos gráficos. O executável do Gnuplot deve estar acessível no PATH do sistema.
    Veja <https://github.com/ldsc/LDSC-Ajuda-DocumentosAuxiliares/tree/main/02-Softwares/03-Softwares/02-Gnuplot>
-   Biblioteca Padrão do C++ (STL).


<a id="org833cf44"></a>

# Funcionalidades Principais:

1.  ****Banco de Dados de Minerais:****
    -   Leitura e gerenciamento de propriedades (K, G) de minerais a partir de arquivos CSV.
2.  ****Entrada de Dados Flexível:****
    -   Suporte a entrada manual via terminal ou leitura em lote via arquivos CSV/TXT.
3.  ****Cálculo Elástico:****
    -   Determinação de K e G usando as médias de Voigt (limite superior de rigidez), Reuss (limite inferior) e Hill (média aritmética).
4.  ****Visualização (Plotting):****
    -   Perfil de Propriedades Elásticas vs. Profundidade.
    -   Crossplot Propriedades Elásticas vs. Porosidade.
    -   Análise de sensibilidade: Variação das propriedades em função da fração de um mineral específico.


<a id="org233f597"></a>

# Manual do Usuário e Desenvolvedor:

-   Os manuais completos em PDF (convertidos para o padrão LyX) encontram-se na pasta `docs/` deste repositório.


<a id="orgf8155fe"></a>

# Instalação e Compilação:

    # Exemplo de compilação via g++ (Linux/Unix)
    # Certifique-se de estar na raiz do projeto ou ajustar os caminhos
    g++ main.cpp src/*.cpp -o PEC_Simulador -std=c++17
    
    # Execução
    ./PEC_Simulador

-   O diretório \`database/\` contendo \`minerais.csv\` deve estar acessível ao executável.


<a id="org6648983"></a>

# Trabalhos Futuros e Sugestões de Melhoria:

Para a continuidade deste projeto, sugerem-se as seguintes implementações:

1.  ****Interface Gráfica (GUI):****
    -   Substituir a interação via terminal por uma interface gráfica utilizando ****Qt****, facilitando a entrada de dados mineralógicos e visualização imediata dos resultados.
2.  ****Modelos de Física de Rochas Avançados:****
    -   Implementar o modelo de ****Hashin-Shtrikman**** (limites mais estreitos e precisos que Voigt-Reuss).
    -   Implementar a equação de ****Gassmann**** para realizar substituição de fluidos (ex: trocar água por óleo/gás e recalcular os módulos).
3.  ****Persistência de Dados:****
    -   Migrar o banco de dados de CSV para ****SQLite****, permitindo consultas mais complexas sobre as propriedades dos minerais.
4.  ****Visualização Integrada:****
    -   Substituir a chamada de sistema ao Gnuplot por uma biblioteca de plotagem integrada ao C++ (como QCustomPlot ou Matplot++), eliminando a dependência externa.


<a id="org863bfd9"></a>

# Licença:

-   GPL / Acadêmica (Software Livre para fins educacionais).

