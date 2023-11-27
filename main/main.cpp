// Copyright 2022 Marina Usova

#include <iostream>
#include "../lib_example/example.h"
#include "../lib_stack/stack.h"
#include "../lib_queue/queue.h"
#include "../lib_list/list.h"
#include "../lib_stack_on_list/stackOnList.h"

int main() {
    std::cout << "=================================EXAMPLE===============================" << std::endl;
  int a = 1, b = 4;
  float result;
  bool success = false;

  try {
      result = division(a, b);
      success = true;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }
  if (success) { printf("%d / %d = %.2f\n", a, b, result); success = false; }

  a = 1; b = 0;

  try {
      result = division(a, b);
      success = true;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }
  if (success) { printf("%d / %d = %.2f\n", a, b, result); success = false; }

  ExampleClass<int> obj(10);
  obj.setRandValues(-50, 30);
  std::cout << obj << std::endl;
  /////////////////////////////////////////////STACK
  std::cout << "==================================STACK APP============================" << std::endl;
 

  Stack<int> pt(3);

  pt.push(1);
  pt.push(2);
  pt.push(3);

  std::cout << "The top element is " << pt.top() << std::endl;
  pt.print();
  pt.pop();

  if (pt.isEmpty()) {
      std::cout << "The stack is empty\n";
  }
  else {
      std::cout << "The stack is not empty\n";
  }
  /////////////////////////////////////////////NODE
  std::cout << "==================================NODE APP============================" << std::endl;

  Node<int> node1;
  Node<int> node2(7);
  Node<int> node3(5, &node2);
  node1.print();
  std::cout << std::endl;
  node2.print();
  std::cout << std::endl;
  node3.print();
  std::cout << std::endl;
  int i = node1 < node2;
  int j = node1 > node2;
  std::cout << i << std::endl;
  std::cout << j << std::endl;
  /////////////////////////////////////////////LIST
  std::cout << "==================================LIST APP============================" << std::endl;
  List<int> list1;
  list1.print();
  list1.push_back(5);
  list1.push_back(6);
  list1.push_back(7);
  list1.push_front(1);
  list1.push_front(2);
  list1.push_back(8);
  list1.print();
  list1.pop_back();
  list1.pop_front();
  list1.print();


  /////////////////////////////////////////////STACK
  std::cout << "==================================STACKONLIST APP============================" << std::endl;

  StackOnList<int> stlist;

  stlist.push(1);
  stlist.push(2);
  stlist.push(3);

  std::cout << "The top element is " << stlist.top() << std::endl;
  stlist.print();
  stlist.pop();

  if (stlist.isEmpty()) {
      std::cout << "The stack is empty\n";
  }
  else {
      std::cout << "The stack is not empty\n";
  }

  /////////////////////////////////////////////QUEUE
  std::cout << "==================================QUEUE APP============================" << std::endl;


  Queue<int> qu(3);

  qu.push(1);
  qu.push(2);
  qu.push(3);

  std::cout << "The back element is " << qu.back() << std::endl;
  qu.print();
  qu.pop();
  qu.print();
  if (qu.isEmpty()) {
      std::cout << "The queue is empty\n";
  }
  else {
      std::cout << "The queue is not empty\n";
  }
  return 0;
}




