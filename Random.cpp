#include "Random.h"
namespace quizomat{
Random::Random()
{
    //ctor
}

Random::Random(unsigned short Size)
{
    using param_t = std::uniform_int_distribution<unsigned short>::param_type;
    param_t p{1, Size};
    _dist.param(p);
}

Random::Random(const Random& other)
{
    *this = other;
}

unsigned short Random::getRandomNumber()
{
    _engine.seed(_rdev());
    return _dist(_engine);
}

Random& Random::operator=(const Random& other)
{
    _engine = other._engine;
    _dist = other._dist;
    return *this;
}

const unsigned int Random::size()const
{
    return _dist.max();
}
}
