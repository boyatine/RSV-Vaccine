/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Subject declaration                              **
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

class Subject
{
  friend istream& operator>>( istream &in, Subject &ps );
  friend ostream& operator<<( ostream & out, Subject s);
  
private:
  unsigned int subject_id; // mom's id
  char group;      // e or c 
  Subject *next;   // points to next in list in Trial
  Baby baby;       // points to embedded Baby object

public:
  Subject();

  void set_subject_id( unsigned int i ) { subject_id = i; }
  void set_group( char c ) { group = c; }
  void set_next( Subject *ps ) { next = ps; }
  unsigned int get_subject_id() { return subject_id; } 
  Subject *get_next() { return next; }
  void set_baby( Baby pb ) { baby = pb; }
  Baby get_baby() { return baby; }

  void report();

  char get_group() { return group; }

};   // END Subject class declaration
