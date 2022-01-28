//
// Created by ejeoh on 1/28/2022.
//

#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H
#include <stdexcept>

template <class T>
class Queue {
private:
    T* data;
    int sizeofQueue;
    int head;
    int tail;
    int numberofElements;
    bool needResize();
    void resizeQueue();

public:
    //This returns the number of elements stored in the queue
    int getSize();

    //This returns a boolean to check is the Queue is empty
    bool isEmpty();

    //This adds an element to the queue
    void add(T newElement);

    //This removes an element from the queue
    void pop();

    //This helps to peek at the head of a queue
    T getHead();


    //This is used to peek at the tail of the queue
    T getTail();

    //Constructor Definition
    Queue();

    //Destructor Definition
    ~Queue();


};

template <class T>
bool Queue<T>::needResize(){
    return (tail + 1) % sizeofQueue == head;
}

template <class T>
void Queue<T>::resizeQueue(){
    T* newData = new T[sizeofQueue * 2];
    int newHead = 0;
    int newTail = 0;
    int newNumberofElements = numberofElements;
    while(!isEmpty()){
        newData[newTail] = data[head];
        pop();
        newTail++;
    }
    head = newHead;
    tail = newTail;
    delete[] data;
    data = newData;
    sizeofQueue *= 2;
    numberofElements = newNumberofElements;
}

// This is the constructor
template <class T>
Queue<T>::Queue(){
    data = new T[10];
    sizeofQueue = 10;
    head = 0;
    tail = 0;
    numberofElements = 0;
}

// This is the destructor
template <class T>
Queue<T>::~Queue(){
    delete[] data;
}


//Returns the number of elements in the queue
template <class T>
int Queue<T>::getSize(){
    return numberofElements;
}


//Return a boolean if the queue is empty
template <class T>
bool Queue<T>::isEmpty() {
    return head == tail;
}


// Implementation for the add element method to the fucntion
template <class T>
void Queue<T>::add(T newElement){
    if(needResize()){
        resizeQueue();
    }
    if(tail ==  sizeofQueue){
        tail = 0;
    }
    data[tail] = newElement;
    tail++;
    numberofElements++;
}


//Implementation for the pop fdunction: Removes an element from teh queue and returns void
template <class T>
void Queue<T>::pop() {
    head = (head % sizeofQueue);
    if(isEmpty()){
        throw std::invalid_argument("You tried popping off an empty queue");
    }
    head++;
    numberofElements--;
}


//Implementation for the getHead funtion
template <class T>
T Queue<T>::getHead(){
    return data[head];
}

//Implementation for the get tail function
template <class T>
T Queue<T>::getTail(){
    if(tail == 0){
        return data[sizeofQueue - 1];
    }else{
        return data[tail- 1];
    }
}


//

#endif //STACK_QUEUE_H