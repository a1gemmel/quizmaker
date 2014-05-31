// main

#include <iostream>


#include "queue.h"
using namespace std;

void auto_mode(int argc, char *argv[]);

void manual_mode(int argc, char *argv[]);

int main (int argc, char *argv[]) {
    if (argc == 1) return 1; // no arguments given
    string mode(argv[1]);
    if (mode == "-a") {
       auto_mode(argc, argv);
    } else if (mode == "-m") {
      manual_mode(argc, argv);
    }
    
   
   return 0;
}


void manual_mode(int argc, char *argv[]) {
      for (int j = 2; j < argc; j+=3) { // output file name selection mode
        string i(argv[j]);
        string o = "out-" + i; // default output file names
        string k = "key-" + i;
        if (j + 1 < argc) { // makes sure the output names are given
           string o_temp(argv[j + 1]);
           o = o_temp;
        }
        if (j + 2 < argc) {
           string k_temp(argv[j + 2]);
           k = k_temp;
        }
        queue my_queue;
        my_queue.get_questions(i);
        my_queue.shuffle_questions();
        my_queue.shuffle_answers();
        my_queue.print_test(o, k);
    }
}

void auto_mode(int argc, char *argv[]) {
      for (int j = 2; j < argc; j++) { // output file name selection mode
        string i(argv[j]);
        string o = "out-" + i; // default output file names
        string k = "key-" + i;
        
        queue my_queue;
        my_queue.get_questions(i);
        my_queue.shuffle_questions();
        my_queue.shuffle_answers();
        my_queue.print_test(o, k);
    }
}
