#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <cctype>
#include <memory>

namespace quizomat{

    typedef std::map<unsigned short, std::string> Map;

class FileManager
{
private:
    std::ifstream _file;
    std::string _filename;
    std::istream* _pFile = nullptr;

public:
    FileManager(std::string name): _filename(name){}
    FileManager(): _filename(""){}
    ~FileManager() {}

    bool getFilename();
    bool fileSearch();
    std::pair<Map, Map> readQuiz();

private:
    unsigned short stringToInt(const std::vector<char>& reverseNumbers);
};


}
#endif // FILEMANAGER_H
