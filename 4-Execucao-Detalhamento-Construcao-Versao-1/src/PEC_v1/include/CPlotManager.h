#ifndef CPLOTMANAGER_H
#define CPLOTMANAGER_H

#include "CReservoirData.h"
#include <iostream>

/**
 * @class CPlotManager
 * @brief Responsável por gerar gráficos a partir dos dados do reservatório usando CGnuplot.
 */
class CPlotManager {
public:
    /**
     * @brief Construtor.
     */
    CPlotManager();

    /**
     * @brief Gera gráfico de K (Hill) e G (Hill) vs profundidade.
     * @param data Referência para dados do reservatório.
     */
    void PlotDepthProfile(const CReservoirData& data);

    /**
     * @brief Gera gráfico de K (Hill) e G (Hill) vs porosidade.
     * @param data Referência para dados do reservatório.
     */
    void PlotPorosityProfile(const CReservoirData& data);

    /**
     * @brief Gera gráfico de como os módulos elásticos variam com a concentração de um mineral secundário,
     * fixando o mineral predominante.
     * @param db Referência ao banco de dados de minerais.
     * @param principal Nome do mineral predominante.
     * @param secundario Nome do mineral em variação.
     */
    void PlotVariationByMineral(const CMineralDatabase& db, const std::string& principal, const std::string& secundario);
};

#endif
