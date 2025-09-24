#include "CInput.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

/**
 * @brief Construtor.
 */
CInput::CInput() {}

/**
 * @brief Destrutor.
 */
CInput::~CInput() {}

/**
 * @brief Solicita entrada manual do usuário.
 */
CInput::SampleInput CInput::PromptManualInput() {
    SampleInput input;
    std::cout << "Nome do reservatório: ";
    std::getline(std::cin, input.reservoirName);

    std::cout << "Nome da amostra: ";
    std::getline(std::cin, input.sampleName);

    std::cout << "Profundidade (m): ";
    std::cin >> input.depthMeters;

    std::cout << "Porosidade efetiva (%): ";
    std::cin >> input.effectivePorosity;
    std::cin.ignore(); // limpa quebra de linha

    std::cout << "Digite a composição mineralógica no formato \"mineral porcentagem\", uma por linha. Digite 'fim' para encerrar:\n";
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        if (line == "fim") break;

        std::istringstream iss(line);
        std::string mineral;
        float percent;
        if (iss >> mineral >> percent) {
            input.minerals[mineral] = percent;
        } else {
            std::cout << "[ERRO] Entrada inválida. Use: nome porcentagem\n";
        }
    }

    return input;
}

/**
 * @brief Lê um arquivo CSV e retorna os dados de entrada.
 */
CInput::SampleInput CInput::ReadFromCSV(const std::string& filePath) {
    SampleInput input;
    input.reservoirName = "Desconhecido (via CSV)";
    input.sampleName = "Amostra CSV";
    input.depthMeters = 0;
    input.effectivePorosity = 0;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "[ERRO] Não foi possível abrir o arquivo: " << filePath << std::endl;
        return input;
    }

    std::string line;
    while (std::getline(file, line)) {
        ParseCSVLine(line, input.minerals);
    }

    file.close();
    return input;
}

CInput::SampleInput CInput::ReadFromFile(const std::string& filePath) {
    SampleInput input;
    input.depthMeters = 0;
    input.effectivePorosity = 0;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "[ERRO] Não foi possível abrir o arquivo: " << filePath << std::endl;
        return input;
    }

    std::string line;
    bool parsingMinerals = false;

    while (std::getline(file, line)) {
        if (line.empty()) {
            parsingMinerals = true;
            continue;
        }

        if (!parsingMinerals) {
            std::istringstream ss(line);
            std::string label;
            std::getline(ss, label, ':');

            std::string value;
            std::getline(ss, value);
            value.erase(0, value.find_first_not_of(" \t"));

            if (label == "reservatorio") {
                input.reservoirName = value;
            } else if (label == "amostra") {
                input.sampleName = value;
            } else if (label == "profundidade") {
                input.depthMeters = std::stof(value);
            } else if (label == "porosidade") {
                input.effectivePorosity = std::stof(value);
            }
        } else {
            ParseCSVLine(line, input.minerals);
        }
    }

    file.close();
    return input;
}

void CInput::PrintSampleInput(const SampleInput& input) {
    std::cout << "\n=== Dados da Amostra ===\n";
    std::cout << "Reservatório: " << input.reservoirName << std::endl;
    std::cout << "Amostra:      " << input.sampleName << std::endl;
    std::cout << "Profundidade: " << input.depthMeters << " m" << std::endl;
    std::cout << "Porosidade:   " << input.effectivePorosity << " %\n";

    std::cout << "\nComposição Mineralógica:\n";
    for (const auto& pair : input.minerals) {
        std::cout << " - " << pair.first << ": " << pair.second << "%" << std::endl;
    }
    std::cout << "==========================\n" << std::endl;
}


/**
 * @brief Faz parsing de uma linha CSV.
 */
void CInput::ParseCSVLine(const std::string& line, std::map<std::string, float>& mineralsOut) {
    std::istringstream ss(line);
    std::string token1, token2;

    // Tenta identificar separador (vírgula, tab ou espaço)
    if (line.find(',') != std::string::npos) {
        std::getline(ss, token1, ',');
        std::getline(ss, token2);
    } else if (line.find('\t') != std::string::npos) {
        std::getline(ss, token1, '\t');
        std::getline(ss, token2);
    } else {
        ss >> token1 >> token2;
    }

    if (!token1.empty() && !token2.empty()) {
        try {
            float percent = std::stof(token2);
            mineralsOut[token1] = percent;
        } catch (...) {
            std::cerr << "[WARN] Valor inválido para mineral: " << token1 << std::endl;
        }
    }
}

std::vector<CInput::SampleInput> CInput::ReadMultipleFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::vector<SampleInput> samples;

    if (!file.is_open()) {
        std::cerr << "[ERRO] Não foi possível abrir o arquivo: " << filePath << std::endl;
        return samples;
    }

    std::string line;
    SampleInput current;
    bool dentroDeAmostra = false;

    while (std::getline(file, line)) {
        if (line.empty()) {
            if (dentroDeAmostra && !current.sampleName.empty() && !current.minerals.empty()) {
                samples.push_back(current);
                current = SampleInput();
                dentroDeAmostra = false;
            }
            continue;
        }

        if (line.find(':') != std::string::npos) {
            std::istringstream ss(line);
            std::string label;
            std::getline(ss, label, ':');

            std::string value;
            std::getline(ss, value);
            value.erase(0, value.find_first_not_of(" \t"));

            if (label == "reservatorio") {
                current.reservoirName = value;
                dentroDeAmostra = true;
            } else if (label == "amostra") {
                current.sampleName = value;
            } else if (label == "profundidade") {
                current.depthMeters = std::stof(value);
            } else if (label == "porosidade") {
                current.effectivePorosity = std::stof(value);
            }
        } else {
            ParseCSVLine(line, current.minerals);
        }
    }

    if (!current.sampleName.empty() && !current.minerals.empty()) {
        samples.push_back(current);
    }

    file.close();
    return samples;
}
