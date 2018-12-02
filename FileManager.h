#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <array>
#include <vector>
#include <cctype>
#include <memory>

namespace quizomat{

    typedef std::map<unsigned short, std::string> Map;

class FileManager
{
public:
    static const unsigned int QUESTIONS = 1024;

private:
    std::ifstream _file;
    std::string _filename;
    std::istream* _pFile = nullptr;
    std::array< std::map<char, std::string>, QUESTIONS> _answers;

public:
    FileManager(std::string name): _filename(name){}
    FileManager(): _filename(""){}
    ~FileManager() {}

    bool getFilename();
    bool fileSearch();
    std::pair<Map, Map> readQuiz();
    const std::array< std::map<char, std::string>, QUESTIONS>& getAnswers();

private:
    unsigned short stringToInt(const std::vector<char>& reverseNumbers);
};


}
#endif // FILEMANAGER_H
