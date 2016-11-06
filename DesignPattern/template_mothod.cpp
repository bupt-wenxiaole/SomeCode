//template Method 模式
#include <iostream>

class GameCharacter
{
public:
    void healthyValue() const
    {
        std::cout << "before process" << std::endl; //wrapper
        doHealthValue();
        std::cout << "after process" << std::endl; //wrapper
    }
private:
    virtual void doHealthValue() const
    {
        std::cout << "do healthy" << std::endl;
    }

};

class AGameCharacter : public GameCharacter
{
private:
    virtual void doHealthValue() const
    {
        std::cout << "A do healthy" << std::endl;
    }
};

class BGameCharacter : public GameCharacter
{
private:
    virtual void doHealthValue() const
    {
        std::cout << "B do healthy" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    GameCharacter* aptr = new AGameCharacter;
    aptr -> healthyValue();
    GameCharacter* bptr = new BGameCharacter;
    bptr -> healthyValue();
    return 0;
}