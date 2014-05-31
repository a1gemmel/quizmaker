// main

#include <iostream>


#include "queue.h"
using namespace std;


int main () {
  queue my_queue;
  my_queue.get_questions("input.txt");
  my_queue.shuffle_questions();
  my_queue.print_test("output.txt", "key.txt");


  return 0;
}
