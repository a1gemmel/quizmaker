//queue.c
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "queue.h"
using namespace std;

void queue::get_questions(string filename) {
      ifstream file(filename.c_str());
      char s[256];
      
      // question retrieval loop 
      while (file.getline(s, 256)) {
            question new_q;
            new_q.correct_location = 0;
            new_q.q = s;
            file.getline(s, 256);
            new_q.correct = s;
            file.getline(s, 256);
            int i = 0;
            while (strlen(s) > 0) {
                  i++;
                  new_q.incorrect.push_back(s);
                  file.getline(s, 256);
            }
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
     int random;
     int size = questions.size();
     srand(time(NULL));
     for (int j = 0; j < size; j++) {
         for (int i = 0; i < questions[j].incorrect.size(); i++) {
             random = rand() % (questions[j].incorrect.size() - i) + i;
             string temp = questions[j].incorrect[i];
             questions[j].incorrect[i] = questions[j].incorrect[random];
             questions[j].incorrect[random] = temp;
         }
         questions[j].correct_location = rand() % questions[j].incorrect.size(); // put the correct answer in a random place      
     }
}


void queue::print_test(string testname, string answerkeyname) {
     ofstream test(testname.c_str());
     test << "*******************************************" << endl
          << "*         QUIZ TIME MOTHAFUCKAS           *" << endl
          << "*******************************************" << endl << endl;
          
          
     for (int i = 0; i < questions.size(); i++) {
         char prefix = 'A';
         test << i + 1 << ".  " << questions[i].q << endl;
         for (int j = 0; j < questions[i].incorrect.size(); j++) {
             if (j == questions[i].correct_location) {
                test << " " << prefix << ") " << questions[i].correct << endl;
                prefix++;
             }
             test << " " << prefix << ") " << questions[i].incorrect[j] << endl;
             prefix++;
         }
         test << endl;
     }
     ofstream key(answerkeyname.c_str());
     key <<  "*******************************************" << endl
          << "*         KEY TIME MOTHAFUCKAS            *" << endl
          << "*******************************************" << endl << endl;
     for (int i = 0; i < questions.size(); i ++) {
         key << i + 1 << ". " << (char)(questions[i].correct_location + 'A') << endl;
     }
}



