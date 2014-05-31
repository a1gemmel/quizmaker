// queue.h
#include <vector>
#include <string>

struct question {
       std::string q;
       std::string correct; 
       int correct_location;
       std::vector<std::string> incorrect; // vector of incorrect answer strings
};

class queue {
      private:
             std::vector<question> questions;
      public:
      // gets an arbitrary number of questions and answers in a given file
      void get_questions (const char * filename);       
             
      // shuffles the order of the questions
      void shuffle_questions();
      
      // randomizes the answer order
      void shuffle_answers();
      
      // writes the test and answer key to two given file names
      void print_test(char * testname, char * answerkeyname);

};




