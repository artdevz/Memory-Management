#pragma once
#include <string>
#include <vector>

class GnuplotWrapper {

public:
    void Plot(
        const std::vector<int>& x,
        const std::vector<float>& y1,
        const std::string& label1,
        const std::vector<float>& y2,
        const std::string& label2,
        const std::string& title,
        const std::string& fileName
    );

private:
    void GenerateDataFile(const std::vector<int>& x, const std::vector<float>& y1, const std::vector<float>& y2, const std::string& filePath);
    void GenerateGnuplotScript(const std::string& dataFile, const std::string& label1, const std::string& label2, const std::string& title, const std::string& plotFile, const std::string& scriptFile);
    void RunGnuplot(const std::string& scriptFile);
    void OpenPlot(const std::string& plotFile);

};