#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

template <typename Container>
void display(const Container& container)
{
    for(const auto& e : container)
        std::cout<<e<<' ';
    std::cout<<"\n\n";
}

template <typename C>
void increase(C& c, int n)
{
    for(auto& e : c)
        e+=n;
}

template<typename Iter1, typename Iter2>
Iter2 m_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for(Iter1 i = f1; i!=e1; i++)
        *f2++ = *i;
    
    return f2;
}

int main ()
{
    const int size=10;



    int array[]= { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout<<"Array: "<<std::endl;
    display(array);



    std::vector<int> v(size);
    std::copy(array, array + size, v.begin());

    std::cout<<"Vector: "<<std::endl;
    display(v);

    

    std::list<int> l(size);
    std::copy(array, array + size, l.begin());

    std::cout<<"List: "<<std::endl;
    display(l);



    //second array, vector, list
    int ar2[10];
    for(int i=0; i<size;i++)
        ar2[i] = array[i];
    

    std::vector<int> v2=v;

    std::list<int> l2=l; 

    
    //increased containers
    increase(ar2, 2);
    std::cout<<"Increased second array's elements by 2: "<<std::endl;
    display(ar2);

    increase(v2, 3);
    std::cout<<"Increased second vector's elements by 3: "<<std::endl;
    display(v2);

    increase(l2, 5);
    std::cout<<"Increased second list's elements by 5: "<<std::endl;
    display(l2);



    m_copy(ar2, ar2 + size, v2.begin());
    std::cout<<"Second array copied to second vector:"<<std::endl;
    display(v2);

    m_copy(l2.begin(), l2.end(), ar2);
    std::cout<<"Second list copied to second array:"<<std::endl;
    display(ar2);



    std::vector<int> :: iterator serc;
    serc=find(v2.begin(), v2.end(), 3);
    if(serc != v2.end())
        std::cout<<"3 is in the "<<distance(v2.begin(), serc)<<". position"<<std::endl;
    else 
        std::cout<<"3 is not in it"<<std::endl;

    std::list<int> :: iterator serc2;
    serc2=find(l2.begin(), l2.end(), 27);
    if(serc2 != l2.end())
        std::cout<<"27 is in the "<<distance(l2.begin(), serc2)<<". position"<<std::endl;
    else
        std::cout<<"27 is not in it"<<std::endl;
}