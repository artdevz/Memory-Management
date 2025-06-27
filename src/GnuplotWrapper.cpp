#include "GnuplotWrapper.hpp"
#include <fstream>
#include <cstdlib>

void GnuplotWrapper::GenerateDataFile(const std::vector<int>& x, const std::vector<int>& y1, const std::vector<int>& y2, const std::string& filePath) {
    std::ofstream file(filePath);
    for (size_t i = 0; i < x.size(); ++i)
        file << x[i] << " " << y1[i] << " " << y2[i]
            << " \"" << y1[i] << "\" \"" << y2[i] << "\"\n";
}

void GnuplotWrapper::GenerateGnuplotScript(const std::string& dataFile, const std::string& label1, const std::string& label2, const std::string& title, const std::string& plotFile, const std::string& scriptFile) {
    std::ofstream gp(scriptFile);
    gp << "set terminal pngcairo size 1920,1080 enhanced font 'Arial,18'\n";
    gp << "set output '" << plotFile << "'\n";
    gp << "set title '" << title << "'\n";
    gp << "set xlabel 'Número de Molduras'\n";
    gp << "set xtics 1\n";
    gp << "set key outside\n";
    gp << "plot \\\n";
    gp << "    '" << dataFile << "' using 1:2 with linespoints lt rgb 'green' lw 2 title '" << label1 << "', \\\n";
    gp << "    '" << dataFile << "' using 1:3 with linespoints lt rgb 'red' lw 2 title '" << label2 << "', \\\n";
    gp << "    '" << dataFile << "' using 1:2:4 with labels offset char 0,1 notitle, \\\n";
    gp << "    '" << dataFile << "' using 1:3:5 with labels offset char 0,-1 notitle\n";
}

void GnuplotWrapper::RunGnuplot(const std::string& scriptFile) {
    std::string cmd = "gnuplot " + scriptFile;
    system(cmd.c_str());
}

void GnuplotWrapper::OpenPlot(const std::string& plotFile) {
    std::string cmd = "xdg-open " + plotFile + " &";
    system(cmd.c_str());
}

void GnuplotWrapper::Plot(
    const std::vector<int>& x,
    const std::vector<int>& y1,
    const std::string& label1,
    const std::vector<int>& y2,
    const std::string& label2,
    const std::string& title,
    const std::string& fileName
) {
    std::string dataFile = "data/output_data.txt";
    std::string scriptFile = "data/plot_script.gp";
    std::string plotFile = "plots/" + fileName;

    GenerateDataFile(x, y1, y2, dataFile);
    GenerateGnuplotScript(dataFile, label1, label2, title, plotFile, scriptFile);
    RunGnuplot(scriptFile);
    OpenPlot(plotFile);
}