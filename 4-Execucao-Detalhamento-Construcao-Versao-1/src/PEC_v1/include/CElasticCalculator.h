#ifndef CELASTICCALCULATOR_H
#define CELASTICCALCULATOR_H

#include "CInput.h"
#include "CMineralDatabase.h"

/**
 * @class CElasticCalculator
 * @brief Realiza os cálculos dos módulos elásticos da amostra com base na composição mineralógica.
 */
class CElasticCalculator {
public:
    /**
     * @brief Construtor.
     * @param db Referência para o banco de dados de minerais.
     */
    explicit CElasticCalculator(const CMineralDatabase& db);

    /**
     * @brief Resultado contendo os módulos calculados.
     */
    struct Result {
        float bulkVoigt;
        float bulkReuss;
        float bulkHill;

        float shearVoigt;
        float shearReuss;
        float shearHill;
    };

    /**
     * @brief Calcula os módulos elásticos para uma amostra.
     * @param input Estrutura da amostra contendo composição e porosidade.
     * @return Estrutura com os resultados calculados.
     */
    Result Calculate(const CInput::SampleInput& input) const;

private:
    const CMineralDatabase& m_database;

    float CalcVoigt(const std::map<std::string, float>& minerals, bool bulk) const;
    float CalcReuss(const std::map<std::string, float>& minerals, bool bulk) const;
};

#endif
