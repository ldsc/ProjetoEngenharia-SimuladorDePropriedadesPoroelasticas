#ifndef CRESERVOIRDATA_H
#define CRESERVOIRDATA_H

#include "CInput.h"
#include "CElasticCalculator.h"
#include <vector>

/**
 * @class CReservoirData
 * @brief Gerencia o armazenamento de múltiplas amostras de um reservatório.
 */
class CReservoirData {
public:
    /**
     * @brief Estrutura que encapsula uma amostra enriquecida com os resultados calculados.
     */
    struct EnrichedSample {
        CInput::SampleInput input;
        CElasticCalculator::Result result;
    };

    /**
     * @brief Construtor padrão.
     */
    CReservoirData();

    /**
     * @brief Adiciona uma nova amostra com seu resultado elástico.
     */
    void AddSample(const CInput::SampleInput& input,
                   const CElasticCalculator::Result& result);

    /**
     * @brief Retorna todas as amostras armazenadas.
     */
    const std::vector<EnrichedSample>& GetSamples() const;

    /**
     * @brief Imprime um resumo de todas as amostras armazenadas.
     */
    void PrintSummary() const;

    /**
     * @brief Coleta dados de profundidade e módulos Hill para gráficos.
     */
    void GetKGVsDepth(std::vector<float>& depths,
                      std::vector<float>& bulk,
                      std::vector<float>& shear) const;

    /**
     * @brief Coleta dados de porosidade e módulos Hill para gráficos.
     */
    void GetKGVsPorosity(std::vector<float>& porosities,
                         std::vector<float>& bulk,
                         std::vector<float>& shear) const;

    /**
     * @brief Coleta todos os valores de profundidade e os módulos K e G (Voigt, Reuss, Hill).
     */
    void GetKGVsDepthFull(std::vector<float>& depths,
                          std::vector<float>& kV, std::vector<float>& kR, std::vector<float>& kH,
                          std::vector<float>& gV, std::vector<float>& gR, std::vector<float>& gH) const;

    /**
     * @brief Coleta todos os valores de porosidade e os módulos K e G (Voigt, Reuss, Hill).
     */
    void GetKGVsPorosityFull(std::vector<float>& porosities,
                             std::vector<float>& kV, std::vector<float>& kR, std::vector<float>& kH,
                             std::vector<float>& gV, std::vector<float>& gR, std::vector<float>& gH) const;

private:
    std::vector<EnrichedSample> m_samples;
};

#endif
