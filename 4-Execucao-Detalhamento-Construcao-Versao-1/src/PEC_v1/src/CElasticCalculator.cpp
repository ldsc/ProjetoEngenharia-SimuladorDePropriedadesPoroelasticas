#include "CElasticCalculator.h"
#include <iostream>

CElasticCalculator::CElasticCalculator(const CMineralDatabase& db)
    : m_database(db) {}

CElasticCalculator::Result CElasticCalculator::Calculate(const CInput::SampleInput& input) const {
    Result res;
    res.bulkVoigt  = CalcVoigt(input.minerals, true);
    res.bulkReuss  = CalcReuss(input.minerals, true);
    res.bulkHill   = (res.bulkVoigt + res.bulkReuss) / 2.0f;

    res.shearVoigt = CalcVoigt(input.minerals, false);
    res.shearReuss = CalcReuss(input.minerals, false);
    res.shearHill  = (res.shearVoigt + res.shearReuss) / 2.0f;

    return res;
}

float CElasticCalculator::CalcVoigt(const std::map<std::string, float>& minerals, bool bulk) const {
    float sum = 0.0f;
    float totalPercent = 0.0f;

    for (const auto& [name, percent] : minerals) {
        if (!m_database.HasMineral(name)) continue;

        float mod = bulk ? m_database.GetBulkModulus(name) : m_database.GetShearModulus(name);
        sum += (percent / 100.0f) * mod;
        totalPercent += percent;
    }

    return (totalPercent > 0) ? sum : -1.0f;
}

float CElasticCalculator::CalcReuss(const std::map<std::string, float>& minerals, bool bulk) const {
    float sum = 0.0f;
    float totalPercent = 0.0f;

    for (const auto& [name, percent] : minerals) {
        if (!m_database.HasMineral(name)) continue;

        float mod = bulk ? m_database.GetBulkModulus(name) : m_database.GetShearModulus(name);
        if (mod > 0.0f)
            sum += (percent / 100.0f) / mod;
        totalPercent += percent;
    }

    return (sum > 0.0f && totalPercent > 0.0f) ? 1.0f / sum : -1.0f;
}
