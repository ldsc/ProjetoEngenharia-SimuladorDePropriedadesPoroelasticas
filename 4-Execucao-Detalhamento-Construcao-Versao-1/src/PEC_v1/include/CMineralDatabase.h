#ifndef CMINERALDATABASE_H
#define CMINERALDATABASE_H

#include <string>
#include <unordered_map>
#include <utility>

/**
 * @class CMineralDatabase
 * @brief Carrega e fornece acesso aos módulos K e G de minerais, lidos de arquivo.
 */
class CMineralDatabase {
public:
    /**
     * @brief Construtor que carrega o banco de dados a partir de um arquivo.
     * @param filePath Caminho do arquivo .csv com dados de minerais.
     */
    explicit CMineralDatabase(const std::string& filePath);

    /**
     * @brief Verifica se o mineral está presente no banco de dados.
     */
    bool HasMineral(const std::string& name) const;

    /**
     * @brief Retorna o módulo de compressibilidade (K) de um mineral.
     */
    float GetBulkModulus(const std::string& name) const;

    /**
     * @brief Retorna o módulo de cisalhamento (G) de um mineral.
     */
    float GetShearModulus(const std::string& name) const;

    /**
     * @brief Adiciona um novo mineral ao banco de dados.
     * @param name Nome do mineral.
     * @param k Valor de K (GPa).
     * @param g Valor de G (GPa).
     */
    void AddMineral(const std::string& name, float k, float g);

    /**
     * @brief Salva a base de dados atual de minerais em um arquivo CSV.
     * @param filePath Caminho de destino.
     * @return true se salvou com sucesso.
     */
    bool SaveToFile(const std::string& filePath) const;

    /**
     * @brief Imprime todos os minerais da base em ordem alfabética.
     *
     * Esta função é útil para debug ou visualização da base atual de dados.
     * Mostra o nome do mineral seguido de seus valores de K e G (em GPa).
     */
    void PrintAllMineralsSorted() const;

private:
    std::unordered_map<std::string, std::pair<float, float>> m_minerals;

    /**
     * @brief Carrega os dados de minerais do arquivo CSV.
     */
    void LoadFromFile(const std::string& filePath);
};

#endif
