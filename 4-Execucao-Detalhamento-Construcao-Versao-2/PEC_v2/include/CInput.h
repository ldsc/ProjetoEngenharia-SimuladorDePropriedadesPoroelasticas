#ifndef CINPUTMANAGER_H
#define CINPUTMANAGER_H

#include "CAmostra.h"
#include <string>
#include <vector>
#include <map>

/**
 * @class CInputManager
 * @brief Gerencia a entrada de dados do usuário, seja via terminal ou arquivo.
 */
class CInput {
public:
    CInput();
    ~CInput();

    /**
     * @brief Solicita entrada manual do usuário via terminal.
     * @return CAmostra preenchida.
     */
    CAmostra PromptManualInput();

    /**
     * @brief Lê os dados de entrada a partir de um arquivo CSV.
     * @param filePath Caminho para o arquivo CSV.
     * @return CAmostra preenchida.
     */
    CAmostra ReadFromCSV(const std::string& filePath);

    /**
     * @brief Lê os dados de entrada a partir de um arquivo de texto (CSV ou TXT).
     * @param filePath Caminho para o arquivo.
     * @return CAmostra preenchida.
     */
    CAmostra ReadFromFile(const std::string& filePath);

    /**
     * @brief Imprime no terminal os dados lidos de uma amostra.
     * @param amostra A amostra a ser impressa.
     */
    void PrintSampleInput(const CAmostra& amostra);

    /**
     * @brief Lê múltiplas amostras de um único arquivo de entrada.
     * @param filePath Caminho para o arquivo.
     * @return Vetor de amostras lidas.
     */
    std::vector<CAmostra> ReadMultipleFromFile(const std::string& filePath);

private:
    /**
     * @brief Função auxiliar para fazer parsing de uma linha CSV.
     */
    void ParseCSVLine(const std::string& line, std::map<std::string, float>& mineralsOut);
};

#endif
