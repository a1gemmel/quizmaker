//queue.c
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "queue.h"
using namespace std;

void queue::get_questions(const char * filename) {
      ifstream file(filename);
      cout << filename << " opened successfully..." << endl;
      char s[256];
      
      // question retrieval loop 
      while (file.getline(s, 256)) {
            cout << "Getting question..." << endl;
            question new_q;
            new_q.correct_location = 0;
            new_q.q = s;
            cout << "Getting answer..." << endl;
            file.getline(s, 256);
            new_q.correct = s;
            file.getline(s, 256);
            int i = 0;
            while (strlen(s) > 0) {
                  i++;
                  cout << "Getting answer..." << endl;
                  new_q.incorrect.push_back(s);
                  file.getline(s, 256);
            }
            cout << "Done question!" << endl;
            questions.push_back(new_q);
      }
}

void queue::shuffle_questions() {
     int random;
     int size = questions.size();
     srand(time(NULL));
     for (int i = 0; i < size; i++) {
         random = rand() % (size - i) + i;
         question temp = questions[i];
         questions[i] = questions[random];
         questions[random] = temp;
     }   
}        
      

void queue::shuffle_answers() {
     // do something    
}


void queue::print_test(char * testname, char * answerkeyname) {
     ofstream test(testname);
     test << "*******************************************" << endl
          << "*         QUIZ TIME MOTHAFUCKAS           *" << endl
          << "*******************************************" << endl << endl;
          
          
     for (int i = 0; i < questions.size(); i++) {
         test << i + 1 << ".  " << questions[i].q << endl;
         for (int j = 0; j < questions[i].incorrect.size(); j++) {
             if (j == questions[i].correct_location) test << "  " << questions[i].correct << endl;
             test << "  " << questions[i].incorrect[j] << endl;
         }
     test << endl;    
     }
     
}



