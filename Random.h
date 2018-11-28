#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <iostream>

namespace quizomat{
class Random
{
public:
    Random();
    Random(unsigned short);
    Random(const Random&);

    unsigned short getRandomNumber();
    Random& operator=(const Random&);
    const unsigned int size()const;

private:
    std::random_device _rdev{};
    std::default_random_engine _engine{_rdev()};
    std::uniform_int_distribution<unsigned short> _dist;
};
}
#endif // RANDOM_H
