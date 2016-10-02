//determin the string is numeric
#include <iostream>
using namespace std;

void scanDigit(const char** str)
{
    while(**str >= '0' && **str <= '9' && **str != '\0')
        (*str)++;
}
bool isExponent(const char** str)
{
    if(**str != 'e' && **str != 'E')
        return false;
    (*str)++;
    if(**str == '+' || **str == '-')
        (*str)++;
    if(**str == '\0')
        return false;
    scanDigit(str);
    return (**str == '\0') ? true : false;
}
bool isNumeric(const char* str)
{
    if(str == NULL)
        return false;
    if(*str == '+' || *str == '-')
        str++;
    if(*str == '\0')
        return false;
    bool numeric = true;
    scanDigit(&str);  //需要在scanDigit里去移动str这个指针，所以需要传指针的指针进去。
    if(*str != '\0')
    {
        if(*str == '.')
        {
            str++;
            scanDigit(&str);
            if(*str == 'e' || *str == 'E')
                numeric = isExponent(&str);
        }
        else if(*str == 'e' || *str == 'E')
            numeric = isExponent(&str);
        else
            numeric = false;
    }
    return numeric && *str == '\0';
}

int main(int argc, char const *argv[])
{
    const char* p0 = "3e2";
    const char* p1 = "+3e-2";
    const char* p2 = "+3k";
    cout << isNumeric(p0) << endl;
    cout << isNumeric(p1) << endl;
    cout << isNumeric(p2) << endl;
    return 0;
}

