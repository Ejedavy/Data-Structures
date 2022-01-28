#ifndef STACK_H
#define STACK_H
#include <stdexcept>

template <class T>
class Stack
{
    public:
        Stack(){
            data = new T[10];
            stackSize = 10;
            top = 0;
            numberOfElements = 0;
        }
        virtual ~Stack(){
            delete[] data;
        }

        Stack(const Stack<T>& source){
            data = new T[source.stackSize];
            for(int i = 0; i <  source.top; i++){
                data[i] = source.data[i];
            }

            stackSize = source.stackSize;
            top = source.top;
            numberOfElements = source = numberOfElements;
        }


        void add(T newElement);
        T peek();
        void pop();
        bool isEmpty();
        int getSize();


    private:
        T* data;
        int stackSize;
        int top;
        int numberOfElements;
        bool needResize();
        void resizeStack();
};


template <class T>
void Stack<T>::add(T newElement){
    if(needResize()){
        resizeStack();
    }
    data[top] = newElement;
    numberOfElements++;
    top++;
}

template <class T>
T Stack<T>::peek(){
    return data[top-1];
}

template <class T>
void Stack<T>::pop(){
    if(!isEmpty()){
        top --;
        numberOfElements --;
    }else{
        throw std::invalid_argument("You are trying to pop from an empty array");
    }
}

template <class T>
bool Stack<T>::isEmpty(){
    return top == 0;
}

template <class T>
bool Stack<T>::needResize(){
    return top == stackSize;
}

template <class T>
void Stack<T>::resizeStack(){
    T* newData = new T[stackSize *2 ];
    for(int i = 0; i < top; i++){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    stackSize *= 2;
}

template <class T>
int Stack<T>::getSize(){
    return numberOfElements;
}



#endif // STACK_H
