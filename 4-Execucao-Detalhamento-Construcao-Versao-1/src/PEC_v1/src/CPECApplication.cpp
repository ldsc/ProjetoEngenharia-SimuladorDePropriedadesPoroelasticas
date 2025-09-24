#include "CPECApplication.h"
#include <iostream>
#include <limits>

CPECApplication::CPECApplication()
    : m_database("../database/minerais.csv"),
      m_calculator(nullptr),
      m_running(true) {}

CPECApplication::~CPECApplication() {
    delete m_calculator;
}

void CPECApplication::Run() {
    std::cout << "=== PoreElasticCalculator ===\n";
    Initialize();
    Menu();
    Finalize();
}

void CPECApplication::Initialize() {
    std::cout << "[INFO] Inicializando...\n";
    m_calculator = new CElasticCalculator(m_database);
}

void CPECApplication::Menu() {
    while (m_running) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Inserir nova amostra manualmente\n";
        std::cout << "2. Carregar amostra de arquivo\n";
        std::cout << "3. Ver resumo das amostras\n";
        std::cout << "4. Gerar gráficos: profundidade e porosidade\n";
        std::cout << "5. Gerar gráfico de variação mineralógica\n";
        std::cout << "6. Sair\n";
        std::cout << "Escolha: ";

        int escolha;
        std::cin >> escolha;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (escolha) {
            case 1:
                ProcessSamples();
                break;
            case 2: {
                std::string path;
                std::cout << "Caminho do arquivo (.txt ou .csv): ";
                std::getline(std::cin, path);

                auto inputs = m_inputManager.ReadMultipleFromFile(path);
                for (auto& input : inputs) {
                    auto result = m_calculator->Calculate(input);
                    m_inputManager.PrintSampleInput(input);
                    m_reservoirData.AddSample(input, result);
                }

                if (inputs.empty()) {
                    std::cout << "[INFO] Nenhuma amostra carregada.\n";
                } else {
                    std::cout << "[OK] " << inputs.size() << " amostra(s) carregada(s).\n";
                }
                break;
            }
            case 3:
                m_reservoirData.PrintSummary();
                break;
            case 4:
                m_plotManager.PlotDepthProfile(m_reservoirData);
                m_plotManager.PlotPorosityProfile(m_reservoirData);
                std::cout << "[OK] Gráficos salvos em .png\nPressione Enter para continuar...";
                std::cin.get();

                break;
            case 5: {
                std::string principal, secundario;
                std::cout << "Mineral predominante: ";
                std::getline(std::cin, principal);
                std::cout << "Mineral secundário: ";
                std::getline(std::cin, secundario);
                m_plotManager.PlotVariationByMineral(m_database, principal, secundario);
                std::cout << "[OK] Gráficos salvos em .png\n";
                std::cin.get();

                break;
            }
            case 6:
                m_running = false;
                break;
            default:
                std::cout << "[ERRO] Opção inválida.\n";
        }
    }
}

void CPECApplication::ProcessSamples() {
    auto input = m_inputManager.PromptManualInput();
    auto result = m_calculator->Calculate(input);
    m_inputManager.PrintSampleInput(input);
    m_reservoirData.AddSample(input, result);
}

void CPECApplication::Finalize() {
    std::cout << "[INFO] Finalizando aplicação...\n";
}
