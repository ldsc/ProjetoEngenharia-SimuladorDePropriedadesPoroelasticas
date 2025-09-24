#include "CMineralDatabase.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

CMineralDatabase::CMineralDatabase(const std::string& filePath) {
    LoadFromFile(filePath);
}

void CMineralDatabase::LoadFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "[ERRO] Não foi possível abrir o arquivo de minerais: " << filePath << std::endl;
        return;
    }

    std::string line;
    bool headerSkipped = false;
    while (std::getline(file, line)) {
        if (!headerSkipped) {
            headerSkipped = true; // pula o cabeçalho
            continue;
        }

        std::istringstream ss(line);
        std::string name, kStr, gStr;

        if (std::getline(ss, name, ',') &&
            std::getline(ss, kStr, ',') &&
            std::getline(ss, gStr)) {
            try {
                float k = std::stof(kStr);
                float g = std::stof(gStr);
                m_minerals[name] = {k, g};
            } catch (...) {
                std::cerr << "[WARN] Erro ao ler linha: " << line << std::endl;
            }
        }
    }

    file.close();
}

void CMineralDatabase::AddMineral(const std::string& name, float k, float g) {
    m_minerals[name] = {k, g};
}

bool CMineralDatabase::SaveToFile(const std::string& filePath) const {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "[ERRO] Falha ao salvar a base em " << filePath << std::endl;
        return false;
    }

    file << "nome,k,g\n";

    // Copia e ordena os elementos do mapa
    std::vector<std::pair<std::string, std::pair<float, float>>> sortedMinerals(
        m_minerals.begin(), m_minerals.end()
    );

    std::sort(sortedMinerals.begin(), sortedMinerals.end(),
        [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

    for (const auto& [name, values] : sortedMinerals) {
        file << name << "," << values.first << "," << values.second << "\n";
    }

    file.close();
    return true;
}

void CMineralDatabase::PrintAllMineralsSorted() const {
    std::vector<std::string> nomes;
    for (const auto& pair : m_minerals) {
        nomes.push_back(pair.first);
    }

    std::sort(nomes.begin(), nomes.end());

    for (const auto& name : nomes) {
        auto [k, g] = m_minerals.at(name);
        std::cout << name << " => K: " << k << " G: " << g << std::endl;
    }
}


bool CMineralDatabase::HasMineral(const std::string& name) const {
    return m_minerals.find(name) != m_minerals.end();
}

float CMineralDatabase::GetBulkModulus(const std::string& name) const {
    auto it = m_minerals.find(name);
    return (it != m_minerals.end()) ? it->second.first : -1.0f;
}

float CMineralDatabase::GetShearModulus(const std::string& name) const {
    auto it = m_minerals.find(name);
    return (it != m_minerals.end()) ? it->second.second : -1.0f;
}
