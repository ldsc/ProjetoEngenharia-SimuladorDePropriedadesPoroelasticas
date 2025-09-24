#include "CReservoirData.h"
#include <iostream>
#include <iomanip>

CReservoirData::CReservoirData() {}

void CReservoirData::AddSample(const CInput::SampleInput& input,
                                const CElasticCalculator::Result& result) {
    m_samples.push_back({input, result});
}

const std::vector<CReservoirData::EnrichedSample>& CReservoirData::GetSamples() const {
    return m_samples;
}

void CReservoirData::PrintSummary() const {
    std::cout << "\n=== Resumo das Amostras Armazenadas ===\n";
    for (const auto& sample : m_samples) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "- " << sample.input.sampleName
                  << " | Prof: " << sample.input.depthMeters << " m"
                  << " | Porosidade: " << sample.input.effectivePorosity << " %"
                  << " | K: " << sample.result.bulkHill << " GPa"
                  << " | G: " << sample.result.shearHill << " GPa"
                  << std::endl;
    }
    std::cout << "=========================================\n";
}

void CReservoirData::GetKGVsDepth(std::vector<float>& depths,
                                  std::vector<float>& bulk,
                                  std::vector<float>& shear) const {
    depths.clear(); bulk.clear(); shear.clear();
    for (const auto& s : m_samples) {
        depths.push_back(s.input.depthMeters);
        bulk.push_back(s.result.bulkHill);
        shear.push_back(s.result.shearHill);
    }
}

void CReservoirData::GetKGVsPorosity(std::vector<float>& porosities,
                                     std::vector<float>& bulk,
                                     std::vector<float>& shear) const {
    porosities.clear(); bulk.clear(); shear.clear();
    for (const auto& s : m_samples) {
        porosities.push_back(s.input.effectivePorosity);
        bulk.push_back(s.result.bulkHill);
        shear.push_back(s.result.shearHill);
    }
}

void CReservoirData::GetKGVsDepthFull(std::vector<float>& depths,
                                      std::vector<float>& kV, std::vector<float>& kR, std::vector<float>& kH,
                                      std::vector<float>& gV, std::vector<float>& gR, std::vector<float>& gH) const {
    depths.clear(); kV.clear(); kR.clear(); kH.clear(); gV.clear(); gR.clear(); gH.clear();
    for (const auto& s : m_samples) {
        depths.push_back(s.input.depthMeters);
        kV.push_back(s.result.bulkVoigt);
        kR.push_back(s.result.bulkReuss);
        kH.push_back(s.result.bulkHill);
        gV.push_back(s.result.shearVoigt);
        gR.push_back(s.result.shearReuss);
        gH.push_back(s.result.shearHill);
    }
}

void CReservoirData::GetKGVsPorosityFull(std::vector<float>& porosities,
                                         std::vector<float>& kV, std::vector<float>& kR, std::vector<float>& kH,
                                         std::vector<float>& gV, std::vector<float>& gR, std::vector<float>& gH) const {
    porosities.clear(); kV.clear(); kR.clear(); kH.clear(); gV.clear(); gR.clear(); gH.clear();
    for (const auto& s : m_samples) {
        porosities.push_back(s.input.effectivePorosity);
        kV.push_back(s.result.bulkVoigt);
        kR.push_back(s.result.bulkReuss);
        kH.push_back(s.result.bulkHill);
        gV.push_back(s.result.shearVoigt);
        gR.push_back(s.result.shearReuss);
        gH.push_back(s.result.shearHill);
    }
}
