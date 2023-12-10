// Queue implementation in C++

#include <iostream>
// We define a variable called " SIZE "
// Setting its value to 5
#define SIZE 5
using namespace std;

class Queue {
    // we then define an array with the size of 5
    // using the SIZE we defined.
   private: int items[SIZE], front, rear;

   // defining a basic Queue function with front and rear based on its definition.
   public: Queue() {
    front = -1;
    rear = -1;
  }

    // we define another function that would check a condition
    bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      return true;
    }
    return false;
  }

    // Another defined bool function that checks an empty condition
    bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }
}