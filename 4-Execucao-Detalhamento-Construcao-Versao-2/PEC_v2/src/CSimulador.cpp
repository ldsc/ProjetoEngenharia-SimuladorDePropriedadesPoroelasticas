#include "CSimulador.h"
#include <iostream>

CSimulador::CSimulador()
    : m_database("../database/minerais.csv"),
      m_calculator(m_database),
      m_running(true) {}

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

void CSimulador::Menu() {
    std::cout << "\n--- MENU ---\n";
    std::cout << "1. Inserir nova amostra manualmente\n";
    std::cout << "2. Carregar amostra de arquivo\n";
    std::cout << "3. Ver resumo das amostras\n";
    std::cout << "4. Gerar gráficos: profundidade e porosidade\n";
    std::cout << "5. Gerar gráfico de variação mineralógica\n";
    std::cout << "6. Sair\n";
    std::cout << "Escolha: ";

    int opcao;
    std::cin >> opcao;
    std::cin.ignore();

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
            m_plotManager.PlotDepthProfile(m_reservoirData);
            m_plotManager.PlotPorosityProfile(m_reservoirData);
            std::cout << "\n[OK] Gráficos salvos em .png\nPressione Enter para continuar...";
            std::cin.get();
            break;
        case 5: {
            std::string principal, secundario;
            std::cout << "Mineral predominante: ";
            std::getline(std::cin, principal);
            std::cout << "Mineral secundário: ";
            std::getline(std::cin, secundario);
            m_plotManager.PlotVariationByMineral(m_database, principal, secundario);
            std::cout << "\n[OK] Gráficos salvos em .png\n";
            break;
        }
        case 6:
            m_running = false;
            break;
        default:
            std::cout << "Opção inválida.\n";
    }
}
