/**
 * @file    HtmlExport.h
 * @author  Tomáš Michna
 * @date    December, 2015
 * @bug     No known bugs.
 * @brief   Prototype of class HtmlExport
 *
 * This file contains prototype of HtmlExport class
*/
#ifndef SEMESTRALKA_HTMLEXPORT_H
#define SEMESTRALKA_HTMLEXPORT_H

#include <string>
#include <vector>
#include <fstream>

/**
 * Html Export
 */
class HtmlExport {
private:
    std::string outputFile;

    /**
     * This function write header of Html
     * to the input file stream
     *
     * @parameter file ofstream
     */
    void writeHtmlHeader(std::ofstream &);

    /**
     * This function write footer of Html
     * to the input file stream
     *
     * @parameter file ofstream
     */
    void writeHtmlFooter(std::ofstream &);


    /**
    * This function write start table of Html
    * to the input file stream
    *
    * @parameter file ofstream
    * @parameter id of room
    */
    void writeHtmlTableHead(std::ofstream &, const int);

    /**
     * This function write end of table
     * to the input file stream
     *
     * @parameter file ofstream
     */
    void writeHtmlTableFoot(std::ofstream &);

    /**
     * This function write table row of Html
     * to the input file stream
     *
     * @parameter file ofstream
     * @parameter string date
     */
    void writeHtmlTableRow(std::ofstream &, std::string &);

public:
    /**
     * Default constructor
     *
     * @parameter name of output file
     */
    HtmlExport(std::string);

    /* Destructor */
    ~HtmlExport();

    /*
     * Proccess all strings contains date and write
     * html content to html file
     *
     * @parameter vector of string
     * @parameter id of room
     */
    void flush(std::vector<std::string> &, const int);
};


#endif //SEMESTRALKA_HTMLEXPORT_H
