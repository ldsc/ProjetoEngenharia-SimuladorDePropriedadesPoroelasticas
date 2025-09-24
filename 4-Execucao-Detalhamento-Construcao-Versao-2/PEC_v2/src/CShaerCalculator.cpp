#include "CShearCalculator.h"

CShearCalculator::CShearCalculator(const CMineralDatabase& db)
    : m_db(db) {}

float CShearCalculator::CalcVoigt(const std::map<std::string, float>& composicao) const {
    float soma = 0.0f;
    for (const auto& [nome, frac] : composicao)
        soma += (frac / 100.0f) * m_db.GetShearModulus(nome);
    return soma;
}

float CShearCalculator::CalcReuss(const std::map<std::string, float>& composicao) const {
    float inv = 0.0f;
    for (const auto& [nome, frac] : composicao)
        inv += (frac / 100.0f) / m_db.GetShearModulus(nome);
    return (inv > 0.0f) ? 1.0f / inv : -1.0f;
}
