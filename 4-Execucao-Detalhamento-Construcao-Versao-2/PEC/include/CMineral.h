#ifndef CMINERAL_H
#define CMINERAL_H

#include <string>

/**
 * @class CMineral
 * @brief Representa um mineral com módulo de bulk e cisalhamento.
 */
class CMineral {
public:
    /**
     * @brief Construtor padrão necessário para uso com std::unordered_map.
     */
    CMineral();

    /**
     * @brief Construtor com nome, bulk e shear.
     */
    CMineral(const std::string& nome, float bulk, float shear);

    const std::string& Nome() const;
    float Bulk() const;
    float Shear() const;

private:
    std::string m_nome;
    float m_bulk;
    float m_shear;
};

#endif
