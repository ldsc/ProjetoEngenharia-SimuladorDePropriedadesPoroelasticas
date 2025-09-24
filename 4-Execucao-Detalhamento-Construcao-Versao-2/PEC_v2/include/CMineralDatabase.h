#ifndef CMINERALDATABASE_H
#define CMINERALDATABASE_H

#include "CMineral.h"
#include <unordered_map>
#include <string>
#include <vector>

/**
 * @class CMineralDatabase
 * @brief Banco de dados de minerais com seus módulos elásticos.
 */
class CMineralDatabase {
public:
    explicit CMineralDatabase(const std::string& filePath);

    /**
     * @brief Verifica se o mineral existe no banco.
     */
    bool HasMineral(const std::string& nome) const;

    /**
     * @brief Retorna o módulo de bulk do mineral.
     */
    float GetBulkModulus(const std::string& nome) const;

    /**
     * @brief Retorna o módulo de cisalhamento do mineral.
     */
    float GetShearModulus(const std::string& nome) const;

    /**
     * @brief Adiciona um novo mineral ao banco.
     */
    void AddMineral(const std::string& nome, float k, float g);

    /**
     * @brief Imprime todos os minerais ordenados alfabeticamente.
     */
    void PrintAllMineralsSorted() const;

private:
    std::unordered_map<std::string, CMineral> m_minerals;

    void LoadFromFile(const std::string& filePath);
};

#endif
