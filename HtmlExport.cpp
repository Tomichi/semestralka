#include "HtmlExport.h"


std::string outputFile;

void HtmlExport::writeHtmlHeader(std::ofstream & htmlFile) {
    htmlFile << "<!doctype html>\n"
                    "<html class=\"no-js\" lang=\"cs\">\n"
                    "    <head>\n"
                    "        <meta charset=\"utf-8\">\n"
                    "        <meta http-equiv=\"x-ua-compatible\" content=\"ie=edge\">\n"
                    "        <title></title>\n"
                    "        <meta name=\"description\" content=\"Vypis zamluvenych mistnosti\">\n"
                    "        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
                    "\n"
                    "\n"
                    "    </head>\n"
                    "    <body>";
}

void HtmlExport::writeHtmlFooter(std::ofstream & htmlFile) {
    htmlFile << "    </body>\n"
                        "</html>";
}

void HtmlExport::writeHtmlTableHead(std::ofstream & htmlFile, const int id) {
 htmlFile << "<table border=\"1\" style=\"width:100%\">"
                     "<tr><th>Rezervace mistnosti "+ std::to_string(id) +"</th></tr>";

}

void HtmlExport::writeHtmlTableFoot(std::ofstream & htmlFile) {
    htmlFile << "</table>";
}

void HtmlExport::writeHtmlTableRow(std::ofstream & htmlFile, std::string & date) {
    htmlFile << "<tr><td>" + date + "<td></tr>";
}

bool HtmlExport::validateHtmlSufix(std::string &fileName) {
    return  true;
}

HtmlExport::HtmlExport(std::string filename) {
    this->outputFile = filename;
}

HtmlExport::~HtmlExport() {
    this->outputFile = "";
}

void HtmlExport::export(std::vector<string> &date, const int id) {
    ofstream ofs(this->outputFile);
    this->writeHtmlHeader(ofs);
    this->writeHtmlTableHead(ofs);
    int size = (int) date.size();
    for (int i = 0; i < size; i++) {
        this->writeHtmlTableRow(ofs, date.at(i));
    }
    this->writeHtmlTableFoot(ofs);
    this->writeHtmlTableFoot(ofs);
    ofs.close();
}