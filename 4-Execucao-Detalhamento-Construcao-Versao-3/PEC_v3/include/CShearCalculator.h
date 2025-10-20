#ifndef CSHEARCALCULATOR_H
#define CSHEARCALCULATOR_H

#include "CMineralDatabase.h"
#include <map>
#include <string>

/**
 * @class CShearCalculator
 * @brief Calcula os módulos de cisalhamento usando os teoremas de Voigt e Reuss.
 */
class CShearCalculator {
public:
    explicit CShearCalculator(const CMineralDatabase& db);

    float CalcVoigt(const std::map<std::string, float>& composicao) const;
    float CalcReuss(const std::map<std::string, float>& composicao) const;

private:
    const CMineralDatabase& m_db;
};

#endif // CSHEARCALCULATOR_H
