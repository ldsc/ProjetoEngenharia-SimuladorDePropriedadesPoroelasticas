#include "CElasticCalculator.h"

CElasticCalculator::CElasticCalculator(const CMineralDatabase& db)
    : m_bulkCalc(db), m_shearCalc(db) {}

CElasticCalculator::Result CElasticCalculator::Calculate(const CAmostra& amostra) const {
    Result r;
    const auto& composicao = amostra.Minerais();

    r.bulkVoigt  = m_bulkCalc.CalcVoigt(composicao);
    r.bulkReuss  = m_bulkCalc.CalcReuss(composicao);
    r.bulkHill   = (r.bulkVoigt + r.bulkReuss) / 2.0f;

    r.shearVoigt = m_shearCalc.CalcVoigt(composicao);
    r.shearReuss = m_shearCalc.CalcReuss(composicao);
    r.shearHill  = (r.shearVoigt + r.shearReuss) / 2.0f;

    return r;
}
