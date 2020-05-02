// Header-only library for otus-algo homework testing
// Written by Sergey Tsynikin, 2020

#ifndef TESTER_H
#define TESTER_H

#include <string>
#include <iostream>
#include <fstream>
#include <experimental\filesystem>

#include "itask.h"

namespace fs = std::experimental::filesystem;

class Tester
{
protected:
    ITask &Task;
    std::string Path;
    bool ShowExpects = false;
    bool ShowActuals = false;

public:
    Tester() = delete;
    Tester(ITask &_task, std::string _path) : Task(_task), Path(_path) {}

    void SetShowExpects(bool _showExpects) {ShowExpects = _showExpects;}
    void SetShowActuals(bool _showActuals) {ShowActuals = _showActuals;}

    void RunTests()
    {
        for (size_t nr = 0;; ++nr)
        {
            std::string inFile  = Path + "\\test." + std::to_string(nr) + ".in";
            std::string outFile = Path + "\\test." + std::to_string(nr) + ".out";

            if ( !fs::exists(inFile) || !fs::exists(outFile) )
                break;

            std::cout << "Test #" << nr << " - " << std::boolalpha << RunTest(inFile, outFile) << std::endl;
        }
    }

    bool RunTest(std::string _inFile, std::string _outFile)
    {
        std::vector<std::string> data;
        std::string line;
        std::ifstream i_stream_in(_inFile);
        while (getline(i_stream_in, line))
            data.emplace_back(line);

        std::string expect;
        std::ifstream i_stream_out(_outFile);
        if (getline(i_stream_out, line))
            expect = line;

        if (ShowExpects)
            std::cout << "expect = " << expect << std::endl;

        std::string actual = Task.Run(data);

        if (ShowActuals)
            std::cout << "actual = " << actual << std::endl;

        return expect == actual;
    }
};

#endif // TESTER_H
