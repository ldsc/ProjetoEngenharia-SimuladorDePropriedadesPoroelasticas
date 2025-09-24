#ifndef CINPUT_H
#define CINPUT_H

#include <string>
#include <vector>
#include <map>

/**
 * @class CInput
 * @brief Gerencia a entrada de dados do usuário, seja via terminal ou arquivo.
 */
class CInput {
public:
    /**
     * @brief Construtor padrão.
     */
    CInput();

    /**
     * @brief Destrutor padrão.
     */
    ~CInput();

    /**
     * @brief Estrutura representando os dados de uma amostra.
     */
    struct SampleInput {
        std::string reservoirName;
        std::string sampleName;
        float depthMeters;
        float effectivePorosity;
        std::map<std::string, float> minerals; ///< Mapa: nome do mineral -> porcentagem
    };

    /**
     * @brief Solicita entrada manual do usuário via terminal.
     * @return SampleInput preenchido.
     */
    SampleInput PromptManualInput();

    /**
     * @brief Lê os dados de entrada a partir de um arquivo CSV.
     * @param filePath Caminho para o arquivo CSV.
     * @return SampleInput preenchido.
     */
    SampleInput ReadFromCSV(const std::string& filePath);

    /**
     * @brief Lê os dados de entrada a partir de um arquivo de texto (CSV ou TXT).
     * @param filePath Caminho para o arquivo.
     * @return SampleInput preenchido.
     */
    SampleInput ReadFromFile(const std::string& filePath);

    /**
     * @brief Imprime no terminal os dados lidos de uma amostra.
     * @param input Estrutura da amostra a ser impressa.
     */
    void PrintSampleInput(const SampleInput& input);

    /**
     * @brief Lê múltiplas amostras de um único arquivo de entrada.
     * @param filePath Caminho para o arquivo.
     * @return Vetor de amostras lidas.
     */
    std::vector<SampleInput> ReadMultipleFromFile(const std::string& filePath);


private:
    /**
     * @brief Função auxiliar para fazer parsing de uma linha CSV.
     */
    void ParseCSVLine(const std::string& line, std::map<std::string, float>& mineralsOut);
};

#endif
