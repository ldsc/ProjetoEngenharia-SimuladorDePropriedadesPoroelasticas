#ifndef CAMOSTRA_H
#define CAMOSTRA_H

#include <string>
#include <map>

/**
 * @class CAmostra
 * @brief Representa os dados de uma amostra.
 */
class CAmostra {
public:
    CAmostra();
    CAmostra(const std::string& reservatorio, const std::string& nome,
             float profundidade, float porosidade,
             const std::map<std::string, float>& minerais);

    const std::string& NomeReservatorio() const;
    const std::string& NomeAmostra() const;
    float Profundidade() const;
    float Porosidade() const;
    const std::map<std::string, float>& Minerais() const;

private:
    std::string m_reservatorio;
    std::string m_nome;
    float m_profundidade;
    float m_porosidade;
    std::map<std::string, float> m_minerais;
};

#endif
