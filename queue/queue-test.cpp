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

  // Check if the queue is full
  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {  // If the front index 
    // is 0 and the rear index is equal to SIZE - 1, the queue is full
      return true;  // Return true to indicate that the queue is full
    }
    return false;  // Return false to indicate that the queue is not full
  }

  // Check if the queue is empty
  bool isEmpty() {
    if (front == -1)  // If the front index is -1, the queue is empty
      return true;  // Return true to indicate that the queue is empty
    else
      return false;  // Return false to indicate that the queue is not empty
  }


/*
  The enQueue function is used to insert an element into a queue. 
  It first checks if the queue is full. If the queue is not full, 
  it checks if the queue is empty. If the queue is empty, it sets the front index to 0. 
  Then, it increments the rear index to the next position and inserts the element at that position. 
  Finally, it prints a message indicating that the element has been inserted. 
  If the queue is full, it prints a message indicating that the queue is full.
*/
  void enQueue(int element) {
    if (isFull()) {  // Check if the queue is full
      cout << "Queue is full";  // Print a message indicating that the queue is full
    } else {
      if (front == -1) front = 0;  // If the queue is empty, set the front index to 0
      // Move the rear index to the next position
      rear++;
       // Insert the element at the rear position in the queue
      items[rear] = element;
      // Print a message indicating that the element has been inserted
      cout << endl << "Inserted " << element << endl;
    }
  }

  void display() {
    /* Function to display elements of Queue */
    int i;
    if (isEmpty()) {  // Check if the queue is empty
      cout << endl << "Empty Queue" << endl;  // Print a message indicating that the queue is empty
    } else {
      cout << endl << "Front index-> " << front;  // Print the front index of the queue
      cout << endl << "Items -> ";
      for (i = front; i <= rear; i++)  // Iterate over the elements in the queue
        cout << items[i] << "  ";  // Print each element
      cout << endl << "Rear index-> " << rear << endl;  // Print the rear index of the queue
    }
  }
}