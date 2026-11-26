#ifndef STACK_HPP_
#define STACK_HPP_
#include <iostream>

#include "employee.hpp"

using namespace employee;
#define LOG(str) std::cout << str << std::endl  // Macors
class Stack {
 public:
  Stack();
  Stack(int sizeArray);
  ~Stack();
  Stack(Stack &s);
  void push(Employee data);
  int pop(Employee *data);
  void display(void);
  Stack &operator=(const Stack s);
  static int getactiveStacksCount();

 protected:
 private:
  int top;
  int sizeArray;
  Employee *items;
  // 1. Declare a static variable to count active stacks
  static int activeStacksCount;
};

#endif  // STACK_H
