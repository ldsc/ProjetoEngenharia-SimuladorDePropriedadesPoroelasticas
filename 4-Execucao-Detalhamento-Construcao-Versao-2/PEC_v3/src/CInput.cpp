#include "CInput.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

CInput::CInput() {}
CInput::~CInput() {}

CAmostra CInput::PromptManualInput() {
    std::string reservatorio, nome;
    float profundidade, porosidade;
    std::map<std::string, float> minerais;

    std::cout << "Nome do reservatório: ";
    std::getline(std::cin, reservatorio);
    std::cout << "Nome da amostra: ";
    std::getline(std::cin, nome);
    std::cout << "Profundidade (m): ";
    std::cin >> profundidade;
    std::cout << "Porosidade (%): ";
    std::cin >> porosidade;
    std::cin.ignore();

    std::cout << "Digite os minerais e suas porcentagens (ex: quartzo 50 albita 50):\n";
    std::string linha;
    std::getline(std::cin, linha);
    std::istringstream iss(linha);
    std::string mineral;
    float frac;
    while (iss >> mineral >> frac)
        minerais[mineral] = frac;

    return CAmostra(reservatorio, nome, profundidade, porosidade, minerais);
}

CAmostra CInput::ReadFromCSV(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string linha;

    std::getline(file, linha); 
    std::getline(file, linha); 

    std::stringstream ss(linha);
    std::string reservatorio, nome;
    float profundidade, porosidade;
    std::map<std::string, float> minerais;

    std::getline(ss, reservatorio, ',');
    std::getline(ss, nome, ',');
    ss >> profundidade;
    ss.ignore(1); 
    ss >> porosidade;
    ss.ignore(1); 

    std::string mineraisStr;
    std::getline(ss, mineraisStr);
    ParseCSVLine(mineraisStr, minerais);

    return CAmostra(reservatorio, nome, profundidade, porosidade, minerais);
}

CAmostra CInput::ReadFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string linha;

    std::string reservatorio, nome;
    float profundidade = 0.0f, porosidade = 0.0f;
    std::map<std::string, float> minerais;

    while (std::getline(file, linha)) {
        if (linha.empty()) break;
        std::istringstream iss(linha);
        std::string token;
        iss >> token;

        if (token == "reservatorio:" || token == "reservatório:")
            iss >> reservatorio;
        else if (token == "amostra:")
            iss >> nome;
        else if (token == "profundidade:")
            iss >> profundidade;
        else if (token == "porosidade:")
            iss >> porosidade;
        else {
            std::string mineral = token;
            float perc;
            iss >> perc;
            minerais[mineral] = perc;
        }
    }

    return CAmostra(reservatorio, nome, profundidade, porosidade, minerais);
}

void CInput::PrintSampleInput(const CAmostra& amostra) {
    std::cout << "\n=== Dados da Amostra ===\n";
    std::cout << "Reservatório: " << amostra.NomeReservatorio() << "\n";
    std::cout << "Amostra:      " << amostra.NomeAmostra() << "\n";
    std::cout << "Profundidade: " << amostra.Profundidade() << " m\n";
    std::cout << "Porosidade:   " << amostra.Porosidade() << " %\n";
    std::cout << "\nComposição Mineralógica:\n";
    for (const auto& [nome, perc] : amostra.Minerais())
        std::cout << " - " << nome << ": " << perc << "%\n";
    std::cout << "==========================\n\n";
}

std::vector<CAmostra> CInput::ReadMultipleFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::vector<CAmostra> amostras;

    std::string linha;
    std::string nomeReservatorio, nomeAmostra;
    float profundidade = 0.0f, porosidade = 0.0f;
    std::map<std::string, float> minerais;

    auto salvarAmostraSeValida = [&]() {
        if (!nomeAmostra.empty() && profundidade > 0.0f && porosidade >= 0.0f && !minerais.empty()) {
            amostras.emplace_back(nomeReservatorio, nomeAmostra, profundidade, porosidade, minerais);
        }
        nomeAmostra.clear();
        profundidade = 0.0f;
        porosidade = 0.0f;
        minerais.clear();
    };

    while (std::getline(file, linha)) {
        if (linha.empty()) continue;

        std::istringstream iss(linha);
        std::string token;
        iss >> token;

        if (token == "reservatorio:" || token == "reservatório:") {
            salvarAmostraSeValida();
            iss >> nomeReservatorio;
        }
        else if (token == "amostra:") {
            iss >> nomeAmostra;
        }
        else if (token == "profundidade:") {
            iss >> profundidade;
        }
        else if (token == "porosidade:") {
            iss >> porosidade;
        }
        else {
            std::string mineral = token;
            float perc;
            iss >> perc;
            minerais[mineral] = perc;
        }
    }

    salvarAmostraSeValida();
    return amostras;
}


void CInput::ParseCSVLine(const std::string& line, std::map<std::string, float>& mineralsOut) {
    std::stringstream ss(line);
    std::string token;

    while (std::getline(ss, token, ',')) {
        std::string mineral = token;
        float perc = 0.0f;

        if (std::getline(ss, token, ','))
            perc = std::stof(token);

        mineralsOut[mineral] = perc;
    }
}
