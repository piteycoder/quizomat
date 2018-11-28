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
                        }

TestHandler::TestHandler(std::pair<Map, Map> question_answer, bool subtractPts):
                        _questions(std::get<0>(question_answer)),
                        _answers(std::get<1>(question_answer)),
                        _subtract(subtractPts)
                        {
                            _id = Random(_questions.size());
                        }

TestHandler::TestHandler(std::pair<Map, Map> question_answer, bool subtractPts, Random&& random):
                        _questions(std::get<0>(question_answer)),
                        _answers(std::get<1>(question_answer)),
                        _subtract(subtractPts),
                        _id(random)
                        {

                        }

bool TestHandler::init()
{
    std::cout << "\nWlaczyc opcje ujemnych punktow?" << std::endl;
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
        used.insert(id);

        std::cout << _questions[id] << std::endl;     ////// SHOWS QUESTION AND POSSIBLE ANSWERS

        std::string answer = getAnswer();

        if(_answers[id] == answer){
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
        std::cout << std::endl;
    }

    if(_wronglyAnswered.size() > 0)
        rerun(_wronglyAnswered, send);
    return true;
}

std::string TestHandler::getAnswer(std::string answer)
{
    std::cout << "Twoja odpowiedz: ";
    std::cin >> answer;
    answer[0] = toupper(answer[0]);
    return answer;
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
        unsigned int id = 0;

        while(_wronglyAnswered.size() > 0){

        std::cout << "wrongly answered size: " << _wronglyAnswered.size() << std::endl;
        id = _id.getRandomNumber();

        if(used.count(id))
            continue;

        std::cout << _wronglyAnswered[id] << std::endl;     ////// SHOWS QUESTION AND POSSIBLE ANSWERS

        std::string answer = getAnswer();

        if(_answers[id] == answer){
            _wronglyAnswered.erase(id);
            used.insert(id);
            std::cout << "TAK" << std::endl;
        }
        else{
            std::cout << "NIE - poprawna odpowiedz to " << _answers[id] << std::endl;
        }

        std::cout << std::endl;
    }
}

void TestHandler::setAnswers(const std::array< std::map<char, std::string>, FileManager::QUESTIONS>& givenAnswers)
{
    for(int i = 0; i < FileManager::QUESTIONS; ++i){
        _posAnswers[i] = givenAnswers[i];
    }
}
}
