//Design Pattern : strategy pattern
#include <iostream>
#include <functional>
class GameCharacter;

int defaultHealthCalc(const GameCharacter& gc);

class GameCharacter
{
public:
    typedef std::function<int (const GameCharacter&)> HealthCalcFunc;
    explicit GameCharacter(int val, HealthCalcFunc hcf = defaultHealthCalc)
    :healthFunc(hcf), value(val)
    {}
    int healthValue() const
    {
        return healthFunc(*this);
    }
    
    int getValue() const
    {
        return value;
    }
private:
    HealthCalcFunc healthFunc;
    int value;
    /* data */
};

int defaultHealthCalc(const GameCharacter& gc)
{
    return gc.getValue() + 1;
}

int caculator1(const GameCharacter& gc)  //普通函数
{
    return gc.getValue() + 2;
}

struct caculator2                    //函数对象
{
    int operator() (const GameCharacter& gc) const
    {
        return gc.getValue() + 3;
    }
};

class GameLevel
{
public:
    int caculator3(const GameCharacter& gc) const
    {
        return gc.getValue() + 4;
    }
};

class EyeCandyCharacter : public GameCharacter
{
public:
    explicit EyeCandyCharacter(int val, HealthCalcFunc hcf)
    : GameCharacter(val, hcf)
    {}
};

class EvilBadGuy : public GameCharacter
{
public:
    explicit EvilBadGuy(int val, HealthCalcFunc hcf)
    : GameCharacter(val, hcf)
    {}
};

int main(int argc, char const *argv[])
{
    EvilBadGuy ebg1(1, caculator1);
    std::cout << ebg1.healthValue() << std::endl;
    EyeCandyCharacter ecc1(1, caculator2());
    std::cout << ecc1.healthValue() << std::endl;
    
    GameLevel currentLevel;
    EvilBadGuy ebg2(1, std::bind(&GameLevel::caculator3,
                              currentLevel,
                              std::placeholders::_1));
    std::cout << ebg2.healthValue() << std::endl;
    return 0;
}


