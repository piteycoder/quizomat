#include "TestHandler.h"
namespace quizomat{
TestHandler::TestHandler()
{
    //ctor
}

TestHandler::TestHandler(std::pair<Map, Map> question_answer):
                        _questions(std::get<0>(question_answer)),
                        _answers(std::get<1>(question_answer))
                        {
                            _id = Random(_questions.size());
                            _posAnswers.resize(_questions.size() + 1);
                            for(unsigned int i = 1; i <= _questions.size(); i++){
                                _posAnswers[i] = getPossibleAnswers(i);
                            }

                        }

TestHandler::TestHandler(std::pair<Map, Map> question_answer, bool subtractPts):
                        _questions(std::get<0>(question_answer)),
                        _answers(std::get<1>(question_answer)),
                        _subtract(subtractPts)
                        {
                            _id = Random(_questions.size());
                            _posAnswers.resize(_questions.size() + 1);
                            for(unsigned int i = 1; i <= _questions.size(); i++){
                                _posAnswers[i] = getPossibleAnswers(i);
                            }
                        }

TestHandler::TestHandler(std::pair<Map, Map> question_answer, bool subtractPts, Random&& random):
                        _questions(std::get<0>(question_answer)),
                        _answers(std::get<1>(question_answer)),
                        _subtract(subtractPts),
                        _id(random)
                        {
                            _posAnswers.resize(_questions.size() + 1);
                            for(unsigned int i = 1; i <= _questions.size(); i++){
                                _posAnswers[i] = getPossibleAnswers(i);
                            }
                        }

bool TestHandler::init()
{
    std::cout << "Wlaczyc opcje ujemnych punktow?" << std::endl;
    std::cout << "1 - Tak\n0 - Nie" << std::endl;
    (std::cin >> _subtract).get();
    system("cls");
    std::cout << "Test rozpoczety!\n" << std::endl;

    unsigned short id = 0;
    std::set<unsigned short> used;
    std::set<unsigned short> send;
    Map _wronglyAnswered;

    if(!_id.size()){
        _id = Random(_questions.size());
    }

    while(used.size() < _questions.size()){
        id = _id.getRandomNumber();

        if(used.count(id))
            continue;

        std::cout << _questions[id] << std::endl;     ////// SHOWS QUESTION AND POSSIBLE ANSWERS

        unsigned int j = 0;
        for(char ch = 'A'; j < _posAnswers[id].size(); ++ch, ++j){
            std::cout << ch << ". ";
            std::cout << (_posAnswers[id])[ch] << std::endl;
        }
        char answer = getAnswer();

        if(_answers[id] == (_posAnswers[id])[answer]){
            std::cout << "TAK" << std::endl;
            send.insert(id);
            _result++;
        }
        else{
            std::cout << "NIE - poprawna odpowiedz to " << _answers[id] << std::endl;
            _wronglyAnswered[id] = _questions[id];
            if(_subtract)
                _result--;
        }
        used.insert(id);
        std::cout << std::endl;
    }

    if(_wronglyAnswered.size() > 0)
        rerun(_wronglyAnswered, send);
    return true;
}

std::map<char, std::string> TestHandler::getPossibleAnswers(unsigned short id)
{
    std::map<char, std::string> answers;
    std::string& temp = _questions[id];
    int i = temp.length();
    int last = 0;
    char ch = 'A';

    while(temp[--i]){
        last++;

        if(isspace(temp[i])){
           answers[ch] = temp.substr(i+1,last-1);
           ch++;
           last = 0;
        }

        if(temp[i] == '\n')
            break;
    }

    temp.erase(i);

    return answers;
}

char TestHandler::getAnswer(char answer)
{
    std::cout << "Twoja odpowiedz: ";
    std::cin >> answer;
    return toupper(answer);
}

void TestHandler::showResult()
{
    std::cout << "Uzyskano " << _result << "/" << _questions.size() << " pkt." << std::endl;
    std::cout << "ENTER aby wrocic do menu";

    std::cin.get();
    std::cin.get();
}

void TestHandler::rerun(Map& _wronglyAnswered, std::set<unsigned short>& used)
{
        std::set<unsigned short> send;
        unsigned int id = 0;
        while(_wronglyAnswered.size() > 0){
        id = _id.getRandomNumber();

        if(used.count(id))
            continue;

        std::cout << _wronglyAnswered[id] << std::endl;     ////// SHOWS QUESTION AND POSSIBLE ANSWERS

        unsigned int j = 0;
        for(char ch = 'A'; j < _posAnswers[id].size(); ++ch, ++j){
            std::cout << ch << ". ";
            std::cout << (_posAnswers[id])[ch] << std::endl;
        }
        char answer = getAnswer();

        if(_answers[id] == (_posAnswers[id])[answer]){
            _wronglyAnswered.erase(id);
            send.insert(id);
            std::cout << "TAK" << std::endl;
        }
        else{
            std::cout << "NIE - poprawna odpowiedz to " << _answers[id] << std::endl;
        }
        used.insert(id);
        std::cout << std::endl;
    }
    if(_wronglyAnswered.size())
        rerun(_wronglyAnswered, send);
}
}
