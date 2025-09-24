#include "CMineralDatabase.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

CMineralDatabase::CMineralDatabase(const std::string& filePath) {
    LoadFromFile(filePath);
}

void CMineralDatabase::LoadFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "[ERRO] Não foi possível abrir o arquivo de minerais: " << filePath << "\n";
        return;
    }

    std::string linha;
    bool headerPulado = false;
    while (std::getline(file, linha)) {
        if (!headerPulado) {
            headerPulado = true;
            continue;
        }

        std::stringstream ss(linha);
        std::string nome, kStr, gStr;

        if (std::getline(ss, nome, ',') &&
            std::getline(ss, kStr, ',') &&
            std::getline(ss, gStr)) {
            try {
                float k = std::stof(kStr);
                float g = std::stof(gStr);
                AddMineral(nome, k, g);
            } catch (...) {
                std::cerr << "[WARN] Erro ao interpretar linha: " << linha << "\n";
            }
        }
    }

    file.close();
}

bool CMineralDatabase::HasMineral(const std::string& nome) const {
    return m_minerals.count(nome) > 0;
}

float CMineralDatabase::GetBulkModulus(const std::string& nome) const {
    return m_minerals.at(nome).Bulk();
}

float CMineralDatabase::GetShearModulus(const std::string& nome) const {
    return m_minerals.at(nome).Shear();
}

void CMineralDatabase::AddMineral(const std::string& nome, float k, float g) {
    m_minerals[nome] = CMineral(nome, k, g);
}

void CMineralDatabase::PrintAllMineralsSorted() const {
    std::vector<std::string> nomes;
    for (const auto& [nome, _] : m_minerals)
        nomes.push_back(nome);

    std::sort(nomes.begin(), nomes.end());

    for (const auto& nome : nomes) {
        const auto& m = m_minerals.at(nome);
        std::cout << nome << " => K: " << m.Bulk() << ", G: " << m.Shear() << "\n";
    }
}
