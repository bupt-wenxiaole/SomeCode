#include <iostream>

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag{};
struct random_access_iterator_tag : public bidirectional_iterator_tag{};
namespace my_namespace  
{
    struct random_access_iterator_tag : public bidirectional_iterator_tag{};
}
class iterator1
{
public:
    typedef forward_iterator_tag iterator_category;
};

class iterator2
{
public: 
    typedef bidirectional_iterator_tag iterator_category;
};

template<typename iterT>
struct iterator_traits
{
    typedef typename iterT::iterator_category iterator_category;
};
template<typename iterT> //模板偏特化以支持指针类型
struct iterator_traits<iterT*>
{
    typedef typename my_namespace::random_access_iterator_tag iterator_category;
};
template<typename iterT, typename DistT>
void doAdvance(iterT& iter, DistT d, my_namespace::random_access_iterator_tag)
{
    std::cout << "random bahavior" <<" "<< "dist:" << d <<std::endl;
}
template<typename iterT, typename DistT>
void doAdvance(iterT& iter, DistT d, random_access_iterator_tag)
{
    std::cout << "random bahavior" <<" "<< "dist:" << d <<std::endl;
}

template<typename iterT, typename DistT>
void doAdvance(iterT& iter, DistT d, forward_iterator_tag)
{
    std::cout << "forward bahavior" <<" "<< "dist:" << d << std::endl;
}

template<typename iterT, typename DistT>
void doAdvance(iterT& iter, DistT d, bidirectional_iterator_tag)
{
    std::cout << "bidirectional_iterator_tag bahavior" << " " << "dist:" << d  << std::endl;
}

template<typename iterT, typename DistT>
void advance(iterT& iter, DistT d)
{
    doAdvance(iter, d, 
              typename iterator_traits<iterT>::iterator_category());
}
int main(int argc, char const *argv[])
{
    
    iterator1 iter1;
    advance<iterator1, int>(iter1, 3);
    iterator2 iter2;
    advance<iterator2, int>(iter2, 4);
    double* p;
    advance<double*, int>(p, 5);

}