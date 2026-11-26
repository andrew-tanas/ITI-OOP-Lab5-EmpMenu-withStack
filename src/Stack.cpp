#include "../include/Stack.hpp"

#include "../include/appConfig.hpp"

// Static member definition (required outside the class)
int Stack::activeStacksCount = 0;

int Stack ::getactiveStacksCount() {
  // LOG(this->top);//Compiler Error Unabialable for Static memberFunction
  return activeStacksCount;
}
Stack::Stack() {
  activeStacksCount++;
  LOG("No Parameter Constructor Stack()");
  this->sizeArray = 10;
  this->top = -1;
  this->items = new Employee[sizeArray];
  // ctor
}
Stack::Stack(Stack& s) {
  activeStacksCount++;
  LOG("Copy Constructor :: ");
  this->items = new Employee[s.sizeArray];
  this->sizeArray = s.sizeArray;
  this->top = s.top;
  for (int i = 0; i <= top; i++) {
    char department[DEPARTMET_LENGTH];
    char name[NAME_LENGTH];
    this->items[i].setAge(s.items[i].getAge());
    this->items[i].setSalary(s.items[i].getSalary());
    s.items[i].getDepartment(department);
    this->items[i].setDepartment(department);
    s.items[i].getName(name);
    this->items[i].setName(name);
  }
}
Stack::Stack(int sizeArray) {
  activeStacksCount++;
  LOG("Parameter Constructor Stack()");
  this->sizeArray = sizeArray;
  this->top = -1;
  this->items = new Employee[sizeArray];
  // ctor
}
void Stack::push(Employee data) {
  // 5 items push() push()   push() push() push()
  if (top >= sizeArray - 1) {  // 5
    LOG("Stack is FUll");
    return;  // Early Exit
  }
  top++;  // 0        1        2      3      4
  LOG("We Write index :" << top);
  items[top] = data;
}
int Stack::pop(Employee* data) {
  if (top == -1) {
    // LOG("Stack Empty");
    return 0;
    // return ??
  }
  *data = items[top];
  //   items[top] = 0;
  // LOG("Before POP"<<top);
  top--;
  // LOG("After POP"<<top);
  return 1;
}
void Stack::display(void) {
  for (int i = top; i >= 0; i--) {
    char name[20], department[20];
    fill(name, name + 20, '\0');
    fill(department, department + 20, '\0');
    items[i].getName(name);
    items[i].getDepartment(department);
    cout << "Employee" << i + 1 << ":\n";
    cout << "Name: " << name << ", Age: " << items[i].getAge()
         << ", Salary:" << items[i].getSalary()
         << " ,Department: " << department << endl;
  }
}
Stack& Stack::operator=(const Stack s) {
  LOG("Assgiment Operator :: ");
  delete[] this->items;
  items = new Employee[s.sizeArray];
  this->sizeArray = s.sizeArray;
  this->top = s.top;
  for (int i = 0; i <= top; i++) {
    this->items[i] = s.items[i];
  }
  return *this;
}

Stack::~Stack() {
  LOG("Destructor");
  activeStacksCount--;
  delete[] items;
  // dtor
}
