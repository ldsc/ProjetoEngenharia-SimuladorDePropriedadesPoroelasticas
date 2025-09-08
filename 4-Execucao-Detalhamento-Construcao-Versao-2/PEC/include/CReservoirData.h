#ifndef CRESERVOIRDATA_H
#define CRESERVOIRDATA_H

#include "CAmostra.h"
#include "CElasticCalculator.h"
#include <vector>

/**
 * @class CReservoirData
 * @brief Armazena todas as amostras e seus resultados elásticos.
 */
class CReservoirData {
public:
    struct EnrichedSample {
        CAmostra amostra;
        CElasticCalculator::Result resultado;
    };

    void AddSample(const CAmostra& amostra, const CElasticCalculator::Result& resultado);
    const std::vector<EnrichedSample>& GetSamples() const;

    void PrintSummary() const;

    void GetKGVsDepth(std::vector<float>& depth,
                      std::vector<float>& bulkHill,
                      std::vector<float>& shearHill) const;

    void GetKGVsPorosity(std::vector<float>& phi,
                         std::vector<float>& bulkHill,
                         std::vector<float>& shearHill) const;

    void GetKGVsDepthFull(std::vector<float>& depth,
                          std::vector<float>& kV, std::vector<float>& kR, std::vector<float>& kH,
                          std::vector<float>& gV, std::vector<float>& gR, std::vector<float>& gH) const;

    void GetKGVsPorosityFull(std::vector<float>& phi,
                             std::vector<float>& kV, std::vector<float>& kR, std::vector<float>& kH,
                             std::vector<float>& gV, std::vector<float>& gR, std::vector<float>& gH) const;

private:
    std::vector<EnrichedSample> m_amostras;
};

#endif // CRESERVOIRDATA_H
