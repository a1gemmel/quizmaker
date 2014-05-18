//queue.c

#include <stdlib.h>

bool queue::*get_question(char **str_ptr) {
    if (first != NULL) { 
       char *copy = malloc(sizeof(char) * (strlen(first->q) + 1);
       strcpy(copy, first->q);
       str_ptr = &copy;
       return true;
    }
    else return false;
}
      
bool queue::get_correct_answer(char **str_ptr) {
    if (first != NULL) { 
       char *copy = malloc(sizeof(char) * (strlen(first->correct) + 1);
       strcpy(copy, first->correct);
       str_ptr = &copy;
       return true;
    }
    else return false;
}
      
bool queue::get_incorrect_answers(StringList incorrect_list) {
     if (first != NULL && first->incorrect != NULL) {
        incorrect_list = first->incorrect;
     }
     else return false;
}     

void delete_list(StringList lst) {
     if (lst != NULL) {
             free (lst->s);
             delete_list(lst->next);
     }
}

      // Deletes the current question, and if another question exists, advances to it and returns true
      // POST: If false, no questions remain
bool queue::next_question() {
   if (first != NULL) {
      Question temp = first;
      first = first->next;
      free(temp->q);
      free(temp->correct);
      delete_list(temp->incorrect);
      free(temp);
      return true;
   }
   else return false;
}
      
/* NOTE: typical use of these functions should be as follows:
       if (get_question(my_question)) {
          do something with my_question;
       }
 The return values do not need to be used, but are useful for error-catching
*/
      
queue::queue(Question t_first) {
     first = t_first;
}

queue::~queue() {
     while (next_question()) { } //just iterate through until all questions are deleted
}

// NON-CLASS definitions

char *safe_get_line(FILE *file) {
     char *input = malloc(16 * sizeof(char));
     int used = 0;
     int max = 16;
     int next_char;
     while (next_char = get(file) != '\n') {
           input[used] = next_char;
           used++;
           if (used == max) {
              max *= 2;
              realloc(input, sizeof(char) * max);
           }
     }
     realloc(input, sizeof(char) * (used + 1));
     input[used] = 0; //null terminator
     return input;
}
                    



Queue build_question_queue(const char * filename) {
      file = fopen (filename, "w");
      int test;
      while (test = getc(file) != EOF) {
            ungetc(test, file);
            new_q = malloc(sizeof(struct question));
            new_q->q = safe_get_line(file);
            new_q->correct = safe_get_line(file);
      
