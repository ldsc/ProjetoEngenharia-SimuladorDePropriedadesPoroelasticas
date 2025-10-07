#ifndef CPLOTMANAGER_H
#define CPLOTMANAGER_H

#include "CReservoirData.h"
#include "CMineralDatabase.h"
#include <string>
#include <vector>

/**
 * @class CPlotManager
 * @brief Gerencia a criação e exibição/salvamento de gráficos usando Gnuplot.
 */
class CPlotManager {
public:
    CPlotManager();

    /**
     * @brief Gera os gráficos de K e G versus Porosidade.
     * @param data Objeto contendo os dados das amostras.
     * @param displayOnScreen Se verdadeiro, exibe o gráfico em uma janela interativa.
     */
    void PlotPorosityProfile(const CReservoirData& data, bool displayOnScreen);

    /**
     * @brief Gera os gráficos de K e G versus Profundidade.
     * @param data Objeto contendo os dados das amostras.
     * @param displayOnScreen Se verdadeiro, exibe o gráfico em uma janela interativa.
     */
    void PlotDepthProfile(const CReservoirData& data, bool displayOnScreen);

    /**
     * @brief Gera os gráficos de variação mineralógica entre dois minerais.
     * @param db A base de dados de minerais.
     * @param principal O nome do mineral principal (fixo).
     * @param secundario O nome do mineral cuja proporção irá variar.
     * @param displayOnScreen Se verdadeiro, exibe o gráfico em uma janela interativa.
     */
    void PlotVariationByMineral(const CMineralDatabase& db,
                                const std::string& principal,
                                const std::string& secundario,
                                bool displayOnScreen);

private:
    std::string m_outputPath;

    /**
     * @brief Gera arquivos .dat com dados (x, y) no diretório de saída.
     */
    void ExportCurve(const std::string& filename, const std::vector<double>& x, const std::vector<double>& y) const;

    /**
     * @brief Gera script Gnuplot, salva o gráfico em PNG no diretório de saída e opcionalmente exibe na tela.
     */
    void GeneratePlotScript(const std::string& filenameGp,
                            const std::string& outputPng,
                            const std::string& title,
                            const std::string& xlabel,
                            const std::string& ylabel,
                            const std::vector<std::string>& datFiles,
                            const std::vector<std::string>& legends,
                            bool displayOnScreen) const;
};

#endif