#include <iostream>

template <typename T>
class Rational
{
public:
    Rational(const T& numberator = 0,
             const T& denominator = 1)
    : numberator_x(numberator), denominator_x(denominator)
    {}
    const T numberator() const
    {
        return numberator_x;
    }
    const T denominator() const
    {
        return denominator_x;
    }
    friend
    const Rational<T> operator*(const Rational<T> lhs, const Rational<T> rhs)
    {
        return Rational(lhs.numberator() * rhs.numberator(), lhs.denominator() * rhs.denominator());
    }
private:
    T numberator_x;
    T denominator_x;
};


int main(int argc, char const *argv[])
{
    Rational<int> oneHalf(1, 2);
    Rational<int> test = 2;
    Rational<int> result = oneHalf * 2;
    std::cout<< result.numberator() << "---" << result.denominator() << std::endl;
    return 0;
}