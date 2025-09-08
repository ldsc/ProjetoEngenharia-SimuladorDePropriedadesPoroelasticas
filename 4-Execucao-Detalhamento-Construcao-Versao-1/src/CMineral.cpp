#include "CMineral.h"

CMineral::CMineral() : m_nome(""), m_bulk(0.0f), m_shear(0.0f) {}

CMineral::CMineral(const std::string& nome, float bulk, float shear)
    : m_nome(nome), m_bulk(bulk), m_shear(shear) {}

const std::string& CMineral::Nome() const {
    return m_nome;
}

float CMineral::Bulk() const {
    return m_bulk;
}

float CMineral::Shear() const {
    return m_shear;
}