#ifndef CELASTICCALCULATOR_H
#define CELASTICCALCULATOR_H

#include "CMineralDatabase.h"
#include "CAmostra.h"
#include "CBulkCalculator.h"
#include "CShearCalculator.h"

/**
 * @class CElasticCalculator
 * @brief Calcula os módulos elásticos da amostra usando as médias de Voigt, Reuss e Hill.
 */
class CElasticCalculator {
public:
    struct Result {
        float bulkVoigt, bulkReuss, bulkHill;
        float shearVoigt, shearReuss, shearHill;
    };

    explicit CElasticCalculator(const CMineralDatabase& db);

    /**
     * @brief Realiza o cálculo completo dos módulos para uma amostra.
     * @param amostra A amostra de entrada.
     * @return Resultado com todos os valores de K e G.
     */
    Result Calculate(const CAmostra& amostra) const;

private:
    CBulkCalculator m_bulkCalc;
    CShearCalculator m_shearCalc;
};

#endif // CELASTICCALCULATOR_H
