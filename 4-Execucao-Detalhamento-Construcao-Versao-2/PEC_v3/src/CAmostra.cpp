#include "CAmostra.h"

CAmostra::CAmostra()
    : m_profundidade(0.0f), m_porosidade(0.0f) {}

CAmostra::CAmostra(const std::string& reservatorio, const std::string& nome,
                   float profundidade, float porosidade,
                   const std::map<std::string, float>& minerais)
    : m_reservatorio(reservatorio), m_nome(nome),
      m_profundidade(profundidade), m_porosidade(porosidade),
      m_minerais(minerais) {}

const std::string& CAmostra::NomeReservatorio() const {
    return m_reservatorio;
}

const std::string& CAmostra::NomeAmostra() const {
    return m_nome;
}

float CAmostra::Profundidade() const {
    return m_profundidade;
}

float CAmostra::Porosidade() const {
    return m_porosidade;
}

const std::map<std::string, float>& CAmostra::Minerais() const {
    return m_minerais;
}
