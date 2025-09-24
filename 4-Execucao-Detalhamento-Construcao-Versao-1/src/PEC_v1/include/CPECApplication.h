#ifndef CPECAPPLICATION_H
#define CPECAPPLICATION_H

#include "CInput.h"
#include "CMineralDatabase.h"
#include "CElasticCalculator.h"
#include "CReservoirData.h"
#include "CPlotManager.h"

/**
 * @class CPECApplication
 * @brief Classe principal da aplicação PEC que orquestra a leitura, cálculo e visualização.
 *
 * Responsável por:
 * - Inicializar módulos.
 * - Controlar o menu interativo.
 * - Gerenciar entrada manual ou por arquivo.
 * - Calcular módulos elásticos.
 * - Armazenar amostras e gerar gráficos.
 */
class CPECApplication {
public:
    /**
     * @brief Construtor padrão da aplicação.
     */
    CPECApplication();

    /**
     * @brief Destrutor da aplicação.
     */
    ~CPECApplication();

    /**
     * @brief Executa o ciclo principal da aplicação.
     */
    void Run();

private:
    /**
     * @brief Inicializa banco de dados e subsistemas.
     */
    void Initialize();

    /**
     * @brief Executa entrada manual, cálculo e armazenamento da amostra.
     */
    void ProcessSamples();

    /**
     * @brief Exibe menu principal e gerencia fluxo de opções.
     */
    void Menu();

    /**
     * @brief Finaliza aplicação, libera memória e recursos.
     */
    void Finalize();

private:
    CInput m_inputManager;           ///< Gerencia input do usuário.
    CMineralDatabase m_database;            ///< Banco de dados de minerais.
    CElasticCalculator* m_calculator;       ///< Cálculo dos módulos.
    CReservoirData m_reservoirData;         ///< Armazena todas as amostras.
    CPlotManager m_plotManager;             ///< Responsável por gerar gráficos.
    bool m_running;                         ///< Controle de loop principal.
};

#endif
