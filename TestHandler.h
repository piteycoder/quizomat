#ifndef TESTHANDLER_H
#define TESTHANDLER_H

#include <ostream>
#include <map>
#include <string>
#include <vector>
#include <set>

#include "Random.h"
#include "FileManager.h"

namespace quizomat{

typedef std::map<unsigned short, std::string> Map;

class TestHandler
{
    public:
        TestHandler();
        TestHandler(std::pair< Map, Map>);
        TestHandler(std::pair<Map, Map>, bool);
        TestHandler(std::pair<Map, Map>, bool, Random&&);
        bool init();
        void showResult();

    private:
        std::map<char, std::string> getPossibleAnswers(unsigned short id);
        char getAnswer(char='A');
        void rerun(Map&, std::set<unsigned short>&);

    private:
        Map _questions;
        Map _answers;
        std::vector< std::map<char, std::string> > _posAnswers;
        bool _subtract = 0;
        Random _id;
        int _result = 0;
};
}
#endif // TESTHANDLER_H
