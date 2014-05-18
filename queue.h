// queue.h


// used for storing list of incorrect answers
struct string_list{
       char *s;
       struct string_list *next;
}
typedef StringList *string_list;

struct question {
       char * q;
       char * correct; 
       StringList incorrect; // pointer to list of incorrect answer strings
       struct question * next;
};
typedef Question *question;

class queue {
      private:
             Question first;
      public:
      
      // If a question exists, returns true and sets str_ptr to point at a copy of the current question.
      // NOTE: The pointer set by this function must be freed by the user.
      // POST: if true, str_ptr points at a question string
      //       if false, no questions remain.    
      bool *get_question(char **str_ptr);
      
      // If a question exists, returns true and sets str_ptr to point at a copy of the current correct answer.
      // NOTE: The pointer set by this function must be freed by the user.  
      // POST: if true, str_ptr points at an answer string
      //       if false, no questions remain.          
      bool get_correct_answer(char **str_ptr);
      
      // If a question exists, returns true and sets ll_ptr to point at the linked list of incorrect answers
      // NOTE: User should not mutate this list.
      // POST: if true, str_ptr points at a linked list of the incorrect answers
      //       if false, no questions remain.       
      bool get_incorrect_answers(StringList incorrect_list);
      
      // Deletes the current question, and if another question exists, advances to it and returns true
      // POST: If false, no questions remain
      bool next_question();
      
      /* NOTE: typical use of these functions should be as follows:
               if (get_question(my_question)) {
                  do something with my_question;
               }
         The return values do not need to be used, but are useful for error-catching
      */
      
      queue(Question t_first);
      ~queue();
};
typedef Queue *queue;



// Takes a filename and returns a pointer to a Queue of questions
Queue build_question_queue(char * filename);


