#include "FileManager.h"
#include "Random.h"
namespace quizomat{

    bool FileManager::fileSearch() ///////// DZIALA //////////
    {
        _file.open(_filename + ".txt");
        if (!_file.is_open()){
            std::cout << "Nie znaleziono " << _filename + ".txt" << std::endl;
            std::cout << "Upewnij sie, ze " << _filename + ".txt" << " znajduje sie w folderze z plikiem .exe" << std::endl;
            std::cout << "ENTER aby wrocic do menu" << std::flush;
            std::cin.get();
            system("cls");
            return false;
        }
        _pFile = &_file;
        std::cout << _filename + ".txt" << " odnalezione i otworzone!" << std::endl;
        return true;
    }

    bool FileManager::getFilename() ////// DZIA£A ////////
    {
        std::cout << "Podaj nazwe szukanego quizu: " << std::flush;
        if(getline(std::cin, _filename))
            return true;
        std::cout << "Cos poszlo nie tak!" << std::flush;
        std::cin.clear();
        return false;
    }

    std::pair<Map, Map>  FileManager::readQuiz()//// NIE DZIALA /////
    {
        std::string text;
        std::vector<char> number;
        Map questions;
        Map answers;

        std::cout << "Odczytuje plik..." << std::endl;
        while(std::getline(*_pFile, text)) {
            if(text == "")
                continue;

            int i{0};
            while(isdigit(text[i])){
                number.push_back(text[i++]); /////// READS QUESTIONS' NUMBER //////////////
            }

            while(!isalnum(text[++i])){}  //////////////////// LEAVES BLANK SPACES UNTIL THE QUESTION STARTS

            unsigned short questionID = stringToInt(number);
            questions[questionID] = text.substr(i);


            char last = text[text.length() - 1];
            while(last != '?' && last != ':' && last != '.'){//// IF QUESTION HAS MORE LINES, READS THEM ///////
                std::getline(*_pFile, text);
                questions[questionID] += ' ';
                questions[questionID] += text;
                last = text[text.length() - 1];
            }

            /////////// READS ANSWERS //////////////

            std::getline(*_pFile, text);
            i = text.length() - 1;
            while(!isspace(text[--i])){}

            answers[questionID] = text.substr(i+1);
            questions[questionID] += '\n';
            questions[questionID] += text.substr(0, i);

            number.clear();
        }
        _pFile = nullptr;
        _file.close();
        return std::pair<Map, Map> (questions, answers);
    }

    unsigned short FileManager::stringToInt(const std::vector<char>& reverseNumbers)
    {
        unsigned int arSize{reverseNumbers.size()};
        unsigned short result{0};
        unsigned short multiplier{1};
        for(int i = arSize - 1; i >= 0; i--, multiplier *= 10){
            result += (reverseNumbers[i] - '0') * multiplier;
        }
        return result;
    }
}
