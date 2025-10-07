====================================================
PEC - Poro Elastic Calculator
Versão 3.0
====================================================

Descrição:
-----------
O software PEC é um simulador numérico desenvolvido em C++ para calcular as propriedades elásticas de amostras de rocha com variações mineralógicas distintas.
Autores:
--------
Desenvolvido por: Matheus Souza Bastos 
Curso: Engenharia de Petróleo
Universidade: Universidade Estadual do Norte Fluminense Darcy Ribeiro
Contato: matheusbastos@lenep.uenf.br

Desenvolvido por: Nicolau Azevedo Prates
Curso: Engenharia de Petróleo
Universidade: Universidade Estadual do Norte Fluminense Darcy Ribeiro
Contato: nicolauprares@lenep.uenf.br

Requisitos:
-----------
- Sistema Operacional: Windows 10, Linux Ubuntu 22.04 ou macOS 
- Compilador: g++ (MinGW ou GCC) versão 12.2 ou superior
- Bibliotecas adicionais: gnuplot 

Estrutura do diretório:
-----------------------
\PEC
├── build\           (arquivos .cpp)
├── database\        (arquivos .cpp)
├── include\         (arquivos .h)
├── imput\           (arquivos de entrada)
├── src\             (arquivos .cpp)
├── test\            (arquivos de teste)
└── main.cpp         (programa principal)

Compilação:
-----------
Windows:
    g++ main.cpp src\*.cpp -Iinclude -o build\pec.exe

Linux:
    g++ main.cpp -o PEC -I include -std=c++17

Com CMake:
    mkdir build
    cd build
    cmake ..
    make

Execução:
---------
Para executar o programa:
    ./pec data/entrada.txt

Saídas:
-------
Os resultados serão salvos automaticamente na pasta "plots".
Exemplo:
    plots/resultados.txt
    plots/grafico.png

Licença:
--------
Uso acadêmico e educacional apenas. 
É proibida a redistribuição comercial sem autorização dos autores.

Histórico de Versões:
---------------------
v1.0 — Versão inicial (Março de 2025) 
v2.0 — Versão inicial (Julho de 2025)
v3.0 — Versão inicial (Outubro de 2025)