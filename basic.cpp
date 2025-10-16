#include<iostream>
#include<stack>
int main()
{
    //int array_numbers[] = {1,23,4,56,78};

    // size, empty, push, top pull
    std::stack<int> stack_numbers;

    stack_numbers.push(1);
    stack_numbers.push(23);
    stack_numbers.push(4);
    stack_numbers.push(56);
    stack_numbers.push(78);

    // Stack size
    std::cout<<"Stack size: "<<stack_numbers.size()<<std::endl;
    // Stack peek or top
    std::cout<<"Peek: "<<stack_numbers.top()<<std::endl;
    //Pop
    stack_numbers.pop();
        // Stack size after we pop from it one element
    std::cout<<"Stack size: "<<stack_numbers.size()<<std::endl;
    // Peek after pop
    std::cout<<"Peek: "<<stack_numbers.top()<<std::endl;
    // std::cout<<array_numbers[4]<<std::endl;
    return 0;
}