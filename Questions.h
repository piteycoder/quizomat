#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <string>
#include <map>
namespace quizomat{
class Questions
{
private:
    std::map<unsigned int, std::string> _quest;

public:
    Questions();
};
}
#endif // QUESTIONS_H
