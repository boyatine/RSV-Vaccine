/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Trial declaration                                **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 051 Fall 2017 to use exactly                   **
 **                 as is for Project #5.                                  **
 **                                                                        **
 **                 Students are expected use this code as their           **
 **                 as their own, without any attribution.                 **
 **                                                                        **
 **                 The order and names of parameters may NOT              **
 **                 be changed.  The names of data members and             **
 **                 member functions may NOT be changed.                   **
 **                                                                        **
 **                 Methods (member functions) may be added                **
 **                 but only if they enhance the design.                   **
 **                 Added methods may NOT replace the functionality        **
 **                 of existing methods.                                   **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

class Trial
{
private:
  Subject *head_subject;     // points to start of linked list of Subjects
  string subject_filename;   // record which data is used for this trial
  string baby_filename;      // ... same (these are not used here but ...)
	
public:
  Trial();     // constructor
  ~Trial();    // destructor

  int load_subject_file(string);    // prompt for name and read it
  int load_baby_file(string);       // prompt for name and read it

  void add_subject( Subject * );    // add Subject object to the 'linked-list'

  Subject* find_subject_by_id( unsigned int ); // for matching baby to mom

  void print_list(); // see the data

  void display_statistics(); // show avg + dev, e vs. c, for 3 symptoms
	
private:
  double average(char, char);              // args: group (e or c), symptom code (c, w, or p)
  double deviation( char, char, double );  // same args, plus average
  void display_factor( char );             // shows both e and c for given symptom code

};   // END Trial class declaration
