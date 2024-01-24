#include <iostream>
#include <stdarg.h>

template <typename ValueType>
class MyPriorityQueue
{
    
private:
    ValueType* queue;
    size_t capacity ;
    void sort()
    {
        bool swapped;
        for (size_t index1 = 0; index1 < capacity - 1; index1++)
        {
            swapped = false;
            for (size_t index2 = 0; index2 < capacity - index1 - 1; index2++)
            {
                if (queue[index2] > queue[index2 + 1])
                {
                    ValueType temp = queue[index2];
                    queue[index2] = queue[index2 + 1];
                    queue[index2 + 1] = temp;
                    swapped = true;
                }
            }
            if (swapped == false)
                break;
        }
    }
    
public:
    // конструкторы/деструкторы
    MyPriorityQueue()
    :queue(nullptr), capacity(0)
    {}

    MyPriorityQueue(size_t size, ...)
    :queue(new ValueType[size]), capacity(size)
    {
        va_list factor;
        va_start(factor, size);
        for (size_t index = 0; index < size; ++index)
        {
            queue[index] = sizeof(ValueType) > 4 ? va_arg(factor, ValueType) : va_arg(factor, int);
        }
        va_end(factor);
        this->sort();
    }

    ~MyPriorityQueue()
    {
        delete[] queue;
        queue = nullptr;
        capacity = 0;
    }
    
    // методы
    void push(ValueType smth)
    {
        ValueType *new_queue = new ValueType [capacity + 1];
        for (size_t index = 0; index < capacity; ++index)
        {
            new_queue[index] = queue[index];
        }
        new_queue[capacity] = smth;
        capacity += 1;
        delete[] queue;
        queue = new_queue;
        this->sort();
    }
    
    ValueType pop()
    {
        ValueType *new_queue = new ValueType [capacity - 1];
        ValueType result = queue[capacity - 1];
        for (size_t index = 0; index < capacity - 1; ++index)
        {
            new_queue[index] = queue[index];
        }
        capacity -= 1;
        delete[] queue;
        queue = new_queue;
        return result;
    }

    ValueType peek()
    {
        return queue[capacity - 1];
    }

    size_t size()
    {
        return capacity;
    }

    // оператор
    friend std::ostream& operator << (std::ostream& out, MyPriorityQueue& obindex2ect)
    {
        for (size_t index = 0; index < obindex2ect.capacity; ++index)
        {
            out << obindex2ect.queue[index] << ' ';
        }
        out << '\n';
        return out;
    }
};

// /*
int main()
{
    // unsigned int var = -1;
    // std::cout << var << std::endl; почему так?¿

    //char
    
    MyPriorityQueue<char> char_queue(5, 'D', 'C', 'B', 'A', 'E');
    std::cout << "изначальная очередь:" << std::endl << char_queue << std::endl;

    char_queue.push('X'); char_queue.push('Y'); char_queue.push('A');
    std::cout << "после push('X'), push('Y'), push('A'):" << std::endl << char_queue << std::endl;

    std::cout << "pop(): " << char_queue.pop() << " pop(): " << char_queue.pop() << std::endl;
    std::cout << "после pop(), pop():" << std::endl << char_queue << std::endl;

    std::cout << "peek(): " << char_queue.peek() << std::endl;
    std::cout << "после peek():" << std::endl << char_queue << std::endl;

    //int
    MyPriorityQueue<int> int_queue(7, 1, 10, 2, -4, 0, 7, 2);
    std::cout << "изначальная очередь:" << std::endl << int_queue << std::endl;

    int_queue.push(101); int_queue.push(17); int_queue.push(14);
    std::cout << "после push(101), push(17), push(14):" << std::endl << int_queue << std::endl;

    std::cout << "pop(): " << int_queue.pop() << " pop(): " << int_queue.pop() << std::endl;
    std::cout << "после pop(), pop():" << std::endl << int_queue << std::endl;

    std::cout << "peek(): " << int_queue.peek() << std::endl;
    std::cout << "после peek():" << std::endl << int_queue << std::endl;
    

    
    return 0;
}
 //*/

/*
// template <typename T>
// void foo(size_t n, ...)
// {   
//     va_list list;
//     va_start(list, n);
//     T var; 

//     for(size_t i = 0; i < n; i++) {
//         var = va_arg(list, T);
//         std::cout << var << std::endl;
//     }

//     va_end(list);
// }

void foo(size_t n, ...)
{   
    va_list list;
    va_start(list, n);
    double var; 

    for(size_t i = 0; i < n; i++) {
        var = va_arg(list, double);
        std::cout << var << std::endl;
    }

    va_end(list);
}

int main(void)
{
  
  //foo<double>(2, 3.3, 4.4);  // подставить 2 вместо 3.3 или 4.4 (((
  //foo(2, 2.0, 4.4);
  //foo<float>(2, 3.3, 4.4); //output: 2.72008e+23 and -1.58819e-23

  //foo<double>(7, 1.01, 10, 1.2, -4, 0, 7.3, 2); !!!
  foo(7, 1.01, 10., 1.2, -4., .1, 7.3, 2.);         

  //foo<double>(2, 7, 4.4); //output: 3.45846e-323 and 4.4
  //foo(2, 7, 4.4);         //output: 3.45846e-323 and 4.4
  
  return 0;
}
 */