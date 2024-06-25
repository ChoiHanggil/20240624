
#include <iostream>

class MyClass
{
public:
    int mValue;

    MyClass(int val) : mValue(val) {}

    bool operator > (MyClass& param)
    {
        return this->mValue > param.mValue;
    }
/*
    operator int() const
    {
        return mValue;
    }
    */
};

std::ostream& operator << (std::ostream& os, MyClass& t)
{
    os << t.mValue;
    return os;
}


template <typename T>
void Sort(T inputs[], int count)
{

    for (int i = 0; i < count; ++i)
    {
        for (int j = i; j < count; ++j)
        {
            if (inputs[i] > inputs[j])

            {
                T temp = inputs[i];
                inputs[i] = inputs[j];
                inputs[j] = temp;
            }
        }
    }
}

template <typename T>
void Print(T array, int count)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << array[i];
        if (i < count - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

//template function - Generalization(일반화)
template <typename T> 
void Function(T arg)
{
    std::cout << arg << std::endl;
}

//template class
//template <typename T>
template <class T>
class LinkedList
{
    T* pHead;
    T* pNext;
};

int main()

{
    int array1[5]{ 1, 2, 3, 5, 4 };
    Sort(array1, 5);

    double array2[5]{ 1.0, 2.0, 3.0, 5.0, 4.0 };
    Sort(array2, 5);

    MyClass array3[5]{
        MyClass(1),
        MyClass(2),
        MyClass(3),
        MyClass(5),
        MyClass(4)
    };

    Sort(array3, 5);

    Print(array3, 5);

    //-----------------------------------

    //특수화
    Function<int>(10);
    Function<float>(1.0f);

    //매개변수 추론(deduction)
    Function(314);
    Function(3.14f);
}