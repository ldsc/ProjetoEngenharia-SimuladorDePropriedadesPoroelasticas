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
    if (m_amostras.empty()) {
        std::cout << "\n[INFO] Nenhuma amostra para exibir.\n";
        return;
    }

   
    const int LARGURA_NOME = 12;
    const int LARGURA_PROF = 18;
    const int LARGURA_PORO = 16;
    const int LARGURA_K = 29;
    const int LARGURA_G = 24;

    
    std::cout << "\n" << std::left
              << std::setw(LARGURA_NOME) << "Nome" << "| "
              << std::setw(LARGURA_PROF) << "Profundidade (m)" << "| "
              << std::setw(LARGURA_PORO) << "Porosidade (%)" << "| "
              << std::setw(LARGURA_K) << "Compressibilidade K (GPa)" << "| "
              << std::setw(LARGURA_G) << "Cisalhamento G (GPa)" << std::endl;

   
    std::cout << std::string(LARGURA_NOME, '-') << "|-"
              << std::string(LARGURA_PROF, '-') << "|-"
              << std::string(LARGURA_PORO, '-') << "|-"
              << std::string(LARGURA_K, '-') << "|-"
              << std::string(LARGURA_G, '-') << std::endl;

    std::cout << std::fixed << std::setprecision(2);

    for (const auto& s : m_amostras) {
        std::cout << std::left
                  << std::setw(LARGURA_NOME) << s.amostra.NomeAmostra() << "| "
                  << std::setw(LARGURA_PROF) << s.amostra.Profundidade() << "| "
                  << std::setw(LARGURA_PORO) << s.amostra.Porosidade() << "| "
                  << std::setw(LARGURA_K) << s.resultado.bulkHill << "| "
                  << std::setw(LARGURA_G) << s.resultado.shearHill << std::endl;
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
std::set<std::string> CReservoirData::ObterNomesDeMineraisUnicos() const {
    std::set<std::string> nomesUnicos;
    for (const auto& s : m_amostras) {
        // Para cada amostra, pega o mapa de minerais
        auto minerais = s.amostra.Minerais(); // Supondo que o método se chame 'Minerais'
        // Itera sobre o mapa e insere o nome de cada mineral no nosso set
        for (const auto& parMineral : minerais) {
            nomesUnicos.insert(parMineral.first);
        }
    }
    return nomesUnicos;
}