#include "CPlotManager.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>

/**
 * @brief Gera arquivos .dat com dados (x, y).
 */
static void ExportCurve(const std::string& filename, const std::vector<double>& x, const std::vector<double>& y) {
    std::ofstream file(filename);
    for (size_t i = 0; i < x.size(); ++i)
        file << std::fixed << std::setprecision(6) << x[i] << " " << y[i] << "\n";
}

/**
 * @brief Gera script Gnuplot e executa. Pode exibir na tela ou salvar PNG.
 */
static void GeneratePlotScript(const std::string& filenameGp,
                               const std::string& outputPng,
                               const std::string& title,
                               const std::string& xlabel,
                               const std::string& ylabel,
                               const std::vector<std::string>& datFiles,
                               const std::vector<std::string>& legends,
                               bool showOnScreen = false) {
    std::vector<std::string> estilos = {
        "with lines lt 1 lw 2 dashtype 2",  // Voigt
        "with lines lt 2 lw 2 dashtype 3",  // Reuss
        "with lines lt 3 lw 2 dashtype 1"   // Hill
    };

    std::ofstream gp(filenameGp);
    if (showOnScreen) {
        gp << "set terminal wxt size 800,600\n"; // sem persist aqui
    } else {
        gp << "set terminal pngcairo size 800,600 enhanced font 'Arial,10'\n";
        gp << "set output '" << outputPng << "'\n";
    }

    gp << "set xlabel '" << xlabel << "'\n";
    gp << "set ylabel '" << ylabel << "'\n";
    gp << "set title '" << title << "'\n";
    gp << "set grid\n";
    gp << "plot \\\n";
    for (size_t i = 0; i < datFiles.size(); ++i) {
        gp << "'" << datFiles[i] << "' using 1:2 title '" << legends[i] << "' " << estilos[i];
        if (i != datFiles.size() - 1) gp << ", \\\n";
        else gp << "\n";
    }
    gp.close();

    std::cin.get();

    std::string cmd = showOnScreen
        ? "gnuplot -persist \"" + filenameGp + "\""
        : "gnuplot \"" + filenameGp + "\"";

    system(cmd.c_str());

    // Limpa arquivos temporários
    std::remove(filenameGp.c_str());
    for (const auto& f : datFiles) std::remove(f.c_str());
}

CPlotManager::CPlotManager() {}

void CPlotManager::PlotPorosityProfile(const CReservoirData& data) {
    std::vector<float> phi, kV, kR, kH, gV, gR, gH;
    data.GetKGVsPorosityFull(phi, kV, kR, kH, gV, gR, gH);
    std::vector<double> x(phi.begin(), phi.end());

    ExportCurve("k_voigt_phi.dat", x, {kV.begin(), kV.end()});
    ExportCurve("k_reuss_phi.dat", x, {kR.begin(), kR.end()});
    ExportCurve("k_hill_phi.dat",  x, {kH.begin(), kH.end()});
    ExportCurve("g_voigt_phi.dat", x, {gV.begin(), gV.end()});
    ExportCurve("g_reuss_phi.dat", x, {gR.begin(), gR.end()});
    ExportCurve("g_hill_phi.dat",  x, {gH.begin(), gH.end()});

    GeneratePlotScript("K_vs_porosidade.gp", "K_vs_porosidade.png",
                       "Compressibilidade vs Porosidade",
                       "Porosidade (%)", "K (GPa)",
                       {"k_voigt_phi.dat", "k_reuss_phi.dat", "k_hill_phi.dat"},
                       {"Voigt", "Reuss", "Hill"}, true);

    GeneratePlotScript("G_vs_porosidade.gp", "G_vs_porosidade.png",
                       "Cisalhamento vs Porosidade",
                       "Porosidade (%)", "G (GPa)",
                       {"g_voigt_phi.dat", "g_reuss_phi.dat", "g_hill_phi.dat"},
                       {"Voigt", "Reuss", "Hill"}, true);
}

void CPlotManager::PlotDepthProfile(const CReservoirData& data) {
    std::vector<float> depth, kV, kR, kH, gV, gR, gH;
    data.GetKGVsDepthFull(depth, kV, kR, kH, gV, gR, gH);
    std::vector<double> x(depth.begin(), depth.end());

    ExportCurve("k_voigt_depth.dat", x, {kV.begin(), kV.end()});
    ExportCurve("k_reuss_depth.dat", x, {kR.begin(), kR.end()});
    ExportCurve("k_hill_depth.dat",  x, {kH.begin(), kH.end()});
    ExportCurve("g_voigt_depth.dat", x, {gV.begin(), gV.end()});
    ExportCurve("g_reuss_depth.dat", x, {gR.begin(), gR.end()});
    ExportCurve("g_hill_depth.dat",  x, {gH.begin(), gH.end()});

    GeneratePlotScript("perfil_K_vs_profundidade.gp", "perfil_K_vs_profundidade.png",
                       "Perfil de Compressibilidade",
                       "Profundidade (m)", "K (GPa)",
                       {"k_voigt_depth.dat", "k_reuss_depth.dat", "k_hill_depth.dat"},
                       {"Voigt", "Reuss", "Hill"}, true);

    GeneratePlotScript("perfil_G_vs_profundidade.gp", "perfil_G_vs_profundidade.png",
                       "Perfil de Cisalhamento",
                       "Profundidade (m)", "G (GPa)",
                       {"g_voigt_depth.dat", "g_reuss_depth.dat", "g_hill_depth.dat"},
                       {"Voigt", "Reuss", "Hill"}, true);
}

void CPlotManager::PlotVariationByMineral(const CMineralDatabase& db, const std::string& principal, const std::string& secundario) {
    if (!db.HasMineral(principal) || !db.HasMineral(secundario)) {
        std::cerr << "[ERRO] Um ou ambos os minerais não estão na base de dados.\n";
        return;
    }

    std::vector<double> perc, kV, kR, kH, gV, gR, gH;

    for (int p = 0; p <= 100; p += 5) {
        float fPri = 100.0f - p;
        float fSec = p;
        float kp = db.GetBulkModulus(principal), gp = db.GetShearModulus(principal);
        float ks = db.GetBulkModulus(secundario), gs = db.GetShearModulus(secundario);

        float kv = (fPri * kp + fSec * ks) / 100.0f;
        float gv = (fPri * gp + fSec * gs) / 100.0f;
        float kr = 1.0f / ((fPri / 100.0f) / kp + (fSec / 100.0f) / ks);
        float gr = 1.0f / ((fPri / 100.0f) / gp + (fSec / 100.0f) / gs);
        float kh = (kv + kr) / 2.0f;
        float gh = (gv + gr) / 2.0f;

        perc.push_back(fSec);
        kV.push_back(kv); kR.push_back(kr); kH.push_back(kh);
        gV.push_back(gv); gR.push_back(gr); gH.push_back(gh);
    }

    std::string base = "var_" + principal + "_vs_" + secundario;

    ExportCurve(base + "_k_voigt.dat", perc, kV);
    ExportCurve(base + "_k_reuss.dat", perc, kR);
    ExportCurve(base + "_k_hill.dat",  perc, kH);
    ExportCurve(base + "_g_voigt.dat", perc, gV);
    ExportCurve(base + "_g_reuss.dat", perc, gR);
    ExportCurve(base + "_g_hill.dat",  perc, gH);

    GeneratePlotScript(base + "_K.gp", base + "_K.png",
                       "Variação de K - fixando " + principal,
                       "% " + secundario, "K (GPa)",
                       {base + "_k_voigt.dat", base + "_k_reuss.dat", base + "_k_hill.dat"},
                       {"Voigt", "Reuss", "Hill"}, true);

    GeneratePlotScript(base + "_G.gp", base + "_G.png",
                       "Variação de G - fixando " + principal,
                       "% " + secundario, "G (GPa)",
                       {base + "_g_voigt.dat", base + "_g_reuss.dat", base + "_g_hill.dat"},
                       {"Voigt", "Reuss", "Hill"}, true);
}
