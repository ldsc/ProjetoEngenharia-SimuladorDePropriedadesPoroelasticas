#ifndef CBULKCALCULATOR_H
#define CBULKCALCULATOR_H

#include "CMineralDatabase.h"
#include <map>
#include <string>

/**
 * @class CBulkCalculator
 * @brief Calcula os módulos de bulk usando os teoremas de Voigt e Reuss.
 */
class CBulkCalculator {
public:
    explicit CBulkCalculator(const CMineralDatabase& db);

    float CalcVoigt(const std::map<std::string, float>& composicao) const;
    float CalcReuss(const std::map<std::string, float>& composicao) const;

private:
    const CMineralDatabase& m_db;
};

#endif