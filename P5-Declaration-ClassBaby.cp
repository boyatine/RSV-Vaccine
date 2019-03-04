/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Baby declaration                                **
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

class Baby
{
  friend istream& operator>>( istream &in, Baby &b );
  friend ostream& operator<<( ostream &out, Baby b);
  
public:
  Baby( );

  double get_cough();
  void set_cough( double  );

  int get_wheezing();
  void set_wheezing( int  );

  int get_pneumonia();
  void set_pneumonia( int  );

  void report();

  unsigned int get_mom_id();
  void set_mom_id(unsigned int);
  
private:
  unsigned int mom_id; // must match one of the Subjects
  double cough; 
  int wheezing; 
  int pneumonia; 

};   // END Baby class declaration
