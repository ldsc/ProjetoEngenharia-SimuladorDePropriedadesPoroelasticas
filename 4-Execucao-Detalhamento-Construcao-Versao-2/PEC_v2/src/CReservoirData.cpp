#include "CReservoirData.h"
#include <iostream>
#include <iomanip>

void CReservoirData::AddSample(const CAmostra& amostra, const CElasticCalculator::Result& resultado) {
    m_amostras.push_back({amostra, resultado});
}

const std::vector<CReservoirData::EnrichedSample>& CReservoirData::GetSamples() const {
    return m_amostras;
}

void CReservoirData::PrintSummary() const {
    std::cout << "\n=== Resumo das Amostras ===\n";
    for (const auto& s : m_amostras) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "- " << s.amostra.NomeAmostra()
                  << " | Prof: " << s.amostra.Profundidade() << " m"
                  << " | Porosidade: " << s.amostra.Porosidade() << " %"
                  << " | K: " << s.resultado.bulkHill << " GPa"
                  << " | G: " << s.resultado.shearHill << " GPa"
                  << std::endl;
    }
}

void CReservoirData::GetKGVsDepth(std::vector<float>& depth,
                                  std::vector<float>& bulkHill,
                                  std::vector<float>& shearHill) const {
    depth.clear(); bulkHill.clear(); shearHill.clear();
    for (const auto& s : m_amostras) {
        depth.push_back(s.amostra.Profundidade());
        bulkHill.push_back(s.resultado.bulkHill);
        shearHill.push_back(s.resultado.shearHill);
    }
}

void CReservoirData::GetKGVsPorosity(std::vector<float>& phi,
                                     std::vector<float>& bulkHill,
                                     std::vector<float>& shearHill) const {
    phi.clear(); bulkHill.clear(); shearHill.clear();
    for (const auto& s : m_amostras) {
        phi.push_back(s.amostra.Porosidade());
        bulkHill.push_back(s.resultado.bulkHill);
        shearHill.push_back(s.resultado.shearHill);
    }
}

void CReservoirData::GetKGVsDepthFull(std::vector<float>& depth,
                                      std::vector<float>& kV, std::vector<float>& kR, std::vector<float>& kH,
                                      std::vector<float>& gV, std::vector<float>& gR, std::vector<float>& gH) const {
    depth.clear(); kV.clear(); kR.clear(); kH.clear(); gV.clear(); gR.clear(); gH.clear();
    for (const auto& s : m_amostras) {
        depth.push_back(s.amostra.Profundidade());
        kV.push_back(s.resultado.bulkVoigt);
        kR.push_back(s.resultado.bulkReuss);
        kH.push_back(s.resultado.bulkHill);
        gV.push_back(s.resultado.shearVoigt);
        gR.push_back(s.resultado.shearReuss);
        gH.push_back(s.resultado.shearHill);
    }
}

void CReservoirData::GetKGVsPorosityFull(std::vector<float>& phi,
                                         std::vector<float>& kV, std::vector<float>& kR, std::vector<float>& kH,
                                         std::vector<float>& gV, std::vector<float>& gR, std::vector<float>& gH) const {
    phi.clear(); kV.clear(); kR.clear(); kH.clear(); gV.clear(); gR.clear(); gH.clear();
    for (const auto& s : m_amostras) {
        phi.push_back(s.amostra.Porosidade());
        kV.push_back(s.resultado.bulkVoigt);
        kR.push_back(s.resultado.bulkReuss);
        kH.push_back(s.resultado.bulkHill);
        gV.push_back(s.resultado.shearVoigt);
        gR.push_back(s.resultado.shearReuss);
        gH.push_back(s.resultado.shearHill);
    }
}
