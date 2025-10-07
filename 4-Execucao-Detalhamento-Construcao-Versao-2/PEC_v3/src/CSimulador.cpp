#include "CSimulador.h"
#include <iostream>
#include <limits>
#include <cctype>
#include <vector>


CSimulador::CSimulador()
    : m_database("../database/minerais.csv"),
      m_calculator(m_database),
      m_running(true),
      m_displayGraphsOnScreen(true)
{}

void CSimulador::Run() {
    Initialize();
    while (m_running)
        Menu();
    Finalize();
}

void CSimulador::Initialize() {
    std::cout << "[INFO] Inicializando...\n";
}

void CSimulador::Finalize() {
    std::cout << "[INFO] Finalizando aplicação...\n";
}

void CSimulador::ConfigureGraphDisplay() {
    char choice;
    std::cout << "Deseja que os graficos sejam exibidos na tela (alem de salvos)? (S/N): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (toupper(choice) == 'S') {
        m_displayGraphsOnScreen = true;
        std::cout << "[OK] Exibicao de graficos na tela ATIVADA.\n";
    } else if (toupper(choice) == 'N') {
        m_displayGraphsOnScreen = false;
        std::cout << "[OK] Exibicao de graficos na tela DESATIVADA.\n";
    } else {
        std::cout << "[ERRO] Opcao invalida! A configuracao nao foi alterada.\n";
    }
}

void CSimulador::Menu() {
    std::cout << "\n--- MENU ---\n";
    std::cout << "1. Inserir nova amostra manualmente\n";
    std::cout << "2. Carregar amostra de arquivo\n";
    std::cout << "3. Ver resumo das amostras\n";
    std::cout << "4. Gerar gráficos: profundidade e porosidade\n";
    std::cout << "5. Gerar gráfico de variação mineralógica\n";
    std::cout << "6. Configuracao: Exibir graficos na tela (Atual: " << (m_displayGraphsOnScreen ? "Sim" : "Nao") << ")\n";
    std::cout << "7. Sair\n";
    std::cout << "Escolha: ";

    int opcao;
    std::cin >> opcao;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Opcao invalida.\n";
        return;
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (opcao) {
        case 1: {
            CAmostra amostra = m_inputManager.PromptManualInput();
            auto resultado = m_calculator.Calculate(amostra);
            m_reservoirData.AddSample(amostra, resultado);
            break;
        }
        case 2: {
            std::string caminho;
            std::cout << "Caminho do arquivo (.txt ou .csv): ";
            std::getline(std::cin, caminho);

            
            std::vector<CAmostra> amostras = m_inputManager.ReadMultipleFromFile(caminho);
            for (const auto& amostra : amostras) {
                auto resultado = m_calculator.Calculate(amostra);
                m_reservoirData.AddSample(amostra, resultado);
                m_inputManager.PrintSampleInput(amostra);
            }

            std::cout << "[OK] " << amostras.size() << " amostra(s) carregada(s).\n";
            break;
        }
        case 3:
            m_reservoirData.PrintSummary();
            break;
        case 4:
            m_plotManager.PlotDepthProfile(m_reservoirData, m_displayGraphsOnScreen);
            m_plotManager.PlotPorosityProfile(m_reservoirData, m_displayGraphsOnScreen);
            std::cout << "\n[OK] Graficos salvos em .png. Exibicao na tela: " << (m_displayGraphsOnScreen ? "Ativada" : "Desativada") << ".\n";
            break;
        case 5: {

    // Obtém e exibe a lista de minerais únicos disponíveis nas amostras
    auto nomesDosMinerais = m_reservoirData.ObterNomesDeMineraisUnicos();

    if (nomesDosMinerais.empty()) {
        std::cout << "\n[INFO] Nao ha minerais nas amostras para analisar.\n";
        break; 
    }
    
    std::cout << "\n--- Minerais Disponiveis nas Amostras ---\n";
    for (const auto& nome : nomesDosMinerais) {
        std::cout << "  - " << nome << std::endl;
    }
    std::cout << "-----------------------------------------\n";

    std::string principal, secundario;
    std::cout << "Mineral predominante: ";
    std::getline(std::cin, principal);
    std::cout << "Mineral secundario: ";
    std::getline(std::cin, secundario);

    m_plotManager.PlotVariationByMineral(m_database, principal, secundario, m_displayGraphsOnScreen);
    std::cout << "\n[OK] Graficos salvos em .png. Exibicao na tela: " << (m_displayGraphsOnScreen ? "Ativada" : "Desativada") << ".\n";
    break;
}
        case 6:
            ConfigureGraphDisplay();
            break;
        case 7:
            m_running = false;
            break;
        default:
            std::cout << "Opção inválida.\n";
    }
}