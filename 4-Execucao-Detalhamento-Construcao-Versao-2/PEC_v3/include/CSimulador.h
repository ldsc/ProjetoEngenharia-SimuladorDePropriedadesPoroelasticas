#ifndef CPECAPPLICATION_H
#define CPECAPPLICATION_H

#include "CInput.h"
#include "CElasticCalculator.h"
#include "CMineralDatabase.h"
#include "CReservoirData.h"
#include "CPlotManager.h"

/**
 * @class CSimulador
 * @brief Orquestra a execução do sistema de cálculo poroelástico.
 */
class CSimulador {
public:
    CSimulador();
    void Run();

private:
    CInput m_inputManager;
    CMineralDatabase m_database;
    CElasticCalculator m_calculator;
    CReservoirData m_reservoirData;
    CPlotManager m_plotManager;
    bool m_running;
    bool m_displayGraphsOnScreen; 

    void Menu();
    void Initialize();
    void Finalize();
    void ConfigureGraphDisplay(); 
};

#endif