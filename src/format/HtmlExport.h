#pragma once

#include <string>
#include <vector>
#include <fstream>

class HtmlExport {
private:
    std::string outputFile;

    void writeHtmlHeader(std::ofstream &);

    void writeHtmlFooter(std::ofstream &);

    void writeHtmlTableHead(std::ofstream &, const int);

    void writeHtmlTableFoot(std::ofstream &);

    void writeHtmlTableRow(std::ofstream &, std::string &);

public:

    HtmlExport(std::string);

    ~HtmlExport();

    void flush(std::vector<std::string> &, const int);
};
