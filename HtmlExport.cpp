/**
 * @file    HtmlExport.cpp
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Implementation of class HtmlExport
 *
 * This file contains implementation of HtmlExport class
 */
#include "HtmlExport.h"

void HtmlExport::writeHtmlHeader(std::ofstream &htmlFile) {
    // Write Html header to file
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

void HtmlExport::writeHtmlFooter(std::ofstream &htmlFile) {
    // Write end of the Html body to file
    htmlFile << "    </body>\n"
            "</html>";
}

void HtmlExport::writeHtmlTableHead(std::ofstream &htmlFile, const int id) {
    // Write beign of table to Html file
    htmlFile << "<table border=\"1\" style=\"width:100%\">"
                        "<tr><th>Rezervace mistnosti " + std::to_string(id) + "</th></tr>";

}

void HtmlExport::writeHtmlTableFoot(std::ofstream &htmlFile) {
    // Write end of table to Html file
    htmlFile << "</table>";
}

void HtmlExport::writeHtmlTableRow(std::ofstream &htmlFile, std::string &date) {
    // Write one table row to Html file
    htmlFile << "<tr><td>" + date + "<td></tr>";
}


HtmlExport::HtmlExport(std::string filename) {
    // Setup parameter
    this->outputFile = filename;
}

HtmlExport::~HtmlExport() {
    this->outputFile = "";
}

void HtmlExport::flush(std::vector<std::string> &date, const int id) {
    // Create output stream
    std::ofstream ofs(this->outputFile);

    // Write Html header
    this->writeHtmlHeader(ofs);

    // Start wrtiting table
    this->writeHtmlTableHead(ofs, id);

    // Write all dates to table
    int size = (int) date.size();
    for (int i = 0; i < size; i++) {
        this->writeHtmlTableRow(ofs, date.at(i));
    }

    this->writeHtmlTableFoot(ofs);

    //Write end of Html file
    this->writeHtmlFooter(ofs);
    ofs.close();
}