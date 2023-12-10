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

   public: Queue() {
    front = -1;
    rear = -1;
  }

  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      return true;
    }
    return false;
  }

  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }

  void enQueue(int element) {
    if (isFull()) {
      cout << "Queue is full";
    } else {
      if (front == -1) front = 0;
      rear++;
      items[rear] = element;
      cout << endl << "Inserted " << element << endl;
    }
  }

  int deQueue() {
    int element;
    if (isEmpty()) {  // Check if the queue is empty
      cout << "Queue is empty" << endl;  // Print a message indicating that the queue is empty
      return (-1);  // Return a sentinel value (-1) to indicate an error or an empty queue
    } else {
      element = items[front];  // Store the element at the front of the queue
      if (front >= rear) {  // Check if there is only one element in the queue
        front = -1;  // Reset the front index to -1
        rear = -1;  // Reset the rear index to -1
      } 
      /* If there is more than one element in the queue, we simply move the front index forward. */
      else {
        front++;  // Move the front index forward
      }
      cout << endl << "Deleted -> " << element << endl;  // Print the deleted element
      return (element);  // Return the deleted element
    }
  }

  void display() {
    /* Function to display elements of Queue */
    int i;
    if (isEmpty()) {
      cout << endl << "Empty Queue" << endl;
    } else {
      cout << endl << "Front index-> " << front;
      cout << endl << "Items -> ";
      for (i = front; i <= rear; i++)
        cout << items[i] << "  ";
      cout << endl
         << "Rear index-> " << rear << endl;
    }
  }
};

int main() {
  Queue q;

  // we can run this deQueue with an
  // empty array first to see that it
  // is not possible on empty queue
  q.deQueue();

  // then run the enQueue again but with 5 elements
  // on insertion
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);

  // 6th element can't be added to because the queue is full
  q.enQueue(6);

  q.display();

  //deQueue removes element entered first i.e. 1
  q.deQueue();

  //Now we have just 4 elements
  q.display();

  return 0;
}