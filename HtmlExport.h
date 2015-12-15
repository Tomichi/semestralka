#ifndef SEMESTRALKA_HTMLEXPORT_H
#define SEMESTRALKA_HTMLEXPORT_H

#include <string>
#include <vector>
#include <fstream>

class HtmlExport
{
    private:
        std::string outputFile;
        void writeHtmlHeader(std::ofstream &);
        void writeHtmlFooter(std::ofstream &);
        void writeHtmlTableHead(std::ofstream &, const int);
        void writeHtmlTableFoot(std::ofstream &);
        void writeHtmlTableRow(std::ofstream &, std::string &);
        bool validateHtmlSufix();
    public:
        HtmlExport(std::string);
        ~HtmlExport();
        void export(std::vector<string> &, const int);

};



#endif //SEMESTRALKA_HTMLEXPORT_H
