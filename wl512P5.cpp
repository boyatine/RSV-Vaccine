/**
*   wl512P5.cpp 
*
*   COSC 051 Fall 2017
*   Project #5 
*
*   Due on: 6 DEC 2017
*   Author: Boya Lee 
*
*
*   In accordance with the class policies and Georgetown's
*   Honor Code, I certify that, with the exception of the
*   class resources and those items noted below, I have neither
*   given nor received any assistance on this project. 
*
*   References not otherwise commented within the program source code.
*   Note that you should not mention any help from the TAs, the professor, 
*   or any code taken from the class textbooks.
**/

#include <iostream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

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

class Baby {
    friend istream& operator>>(istream &in, Baby &b); // all data members on one line
    friend ostream& operator<<(ostream &out, Baby b); // all data members on one line
  
    public:
        Baby();

        double get_cough() { return cough; }
        void set_cough(double c) { cough = c; }

        int get_wheezing() { return wheezing; }
        void set_wheezing(int w) { wheezing = w; }

        int get_pneumonia() { return pneumonia; }
        void set_pneumonia(int p) { pneumonia = p; }

        void report();

        unsigned int get_mom_id() { return mom_id; }
        void set_mom_id(unsigned int id) { mom_id = id; }
  
    private:
        unsigned int mom_id; // must match one of the Subjects
        double cough; 
        int wheezing; 
        int pneumonia;
};   // END Baby class declaration

/**************************************************************************************************
*                                        Baby Constructor                                         *
**************************************************************************************************/

Baby::Baby() {

    mom_id = cough = wheezing = pneumonia = 0;
}

/**************************************************************************************************
*                                          Baby::report                                           *
**************************************************************************************************/

void Baby::report() {

    cout << *this << endl; // invokes overloaded operator    
}

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

class Subject {
    friend istream& operator>>(istream &in, Subject &ps);
    friend ostream& operator<<(ostream & out, Subject s); // id, group, baby data
  
    private:
        unsigned int subject_id; // mom's id
        char group;      // e or c 
        Subject *next;   // points to next in list in Trial
        Baby baby;       // points to embedded Baby object

    public:
        Subject();

        void set_subject_id(unsigned int i) { subject_id = i; }
        void set_group(char c) { group = c; }
        void set_next(Subject *ps) { next = ps; }
        unsigned int get_subject_id() { return subject_id; } 
        Subject *get_next() { return next; }
        void set_baby(Baby pb) { baby = pb; }
        Baby get_baby() { return baby; }

        void report();

        char get_group() { return group; }
};   // END Subject class declaration

/**************************************************************************************************
*                                       Subject Constructor                                       *
**************************************************************************************************/

Subject::Subject() {

    subject_id = 0;
    group = '?';
    next = nullptr;

    baby = Baby();
}

/**************************************************************************************************
*                                        Subject::report                                          *
**************************************************************************************************/

void Subject::report() {

    cout << subject_id << " " << group << " " << baby;
}

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

class Trial {
    private:
        Subject *head_subject;     // points to start of linked list of Subjects
        string subject_filename;   // record which data is used for this trial
        string baby_filename;      // ... same (these are not used here but ...)
    
    public:
        Trial();     // constructor
        ~Trial();    // destructor

        int load_subject_file(string);    // prompt for name and read it
        int load_baby_file(string);       // prompt for name and read it

        void add_subject(Subject*);    // add Subject object to the 'linked-list'

        Subject* find_subject_by_id(unsigned int); // for matching baby to mom

        void print_list(); // see the data

        void display_statistics(); // show avg + dev, e vs. c, for 3 symptoms
        
    private:
        double average(char, char);              // args: group (e or c), symptom code (c, w, or p)
        double deviation(char, char, double);  // same args, plus average
        void display_factor(char);             // shows both e and c for given symptom code
};   // END Trial class declaration

/**************************************************************************************************
*                                        Trial Constructor                                        *
**************************************************************************************************/

Trial::Trial() {
    head_subject = NULL;
    subject_filename = "";
    baby_filename = "";
}

/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 Trial::~Trial implementataion code                     **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 051 Fall 2017 to use exactly                   **
 **                 as is for Project #5.                                  **
 **                                                                        **
 **                 Students are allowed to use this code as their         **
 **                 as their own, without any attribution.                 **
 **                                                                        **
 **                 This is the complete implementation code               **
 **                 for the destructor of the Trial class.                 **
 **                 It may be used completely as is, or also               **
 **                 modified in any way, or not used at all.               **
 **                 No modifications are required for the                  **
 **                 method to work correctly.                              **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

Trial::~Trial() {

    Subject * current = head_subject;
    
    unsigned long deleteCount = 0;
    
    while (current != NULL) {
        current = current->get_next();
        delete head_subject;
        deleteCount++;
        head_subject = current;
    }
} // END destructor for class Trial

/**************************************************************************************************
*                                    Trial::load_subject_file                                     *
**************************************************************************************************/

int Trial::load_subject_file(string fileName) {
    
    int counter = 0;

    ifstream inputFile;
    inputFile.open(fileName.c_str());

    if (!inputFile) {
        cout << "Error: subject file not opened" << endl;
    } else {

        Subject s1;
        Baby b1;
        Subject *addThis = nullptr;

        while (inputFile >> s1) {
            s1.set_next(nullptr);
            s1.set_baby(b1);

            addThis = new Subject(s1);

            add_subject(addThis);

            counter++;
        } // end while
    } // end if-else

    inputFile.close();

    return counter;
}

/**************************************************************************************************
*                                     Trial::load_baby_file                                       *
**************************************************************************************************/

int Trial::load_baby_file(string fileName) {
    
    int counter = 0;

    ifstream inputFile;
    inputFile.open(fileName.c_str());

    if (!inputFile) {
        cout << "Error: Baby file not opened." << endl;
    } else {
        Baby b1;
        Subject *sPtr = nullptr;

        while (inputFile >> b1) {
            sPtr = find_subject_by_id(b1.get_mom_id());

            if (sPtr) {
                sPtr->set_baby(b1); 
            } // end if

            counter++;
        } // end while

    } // end if-else

    inputFile.close();

    return counter;
}

/**************************************************************************************************
*                                         Trial::add_subject                                      *
**************************************************************************************************/

void Trial::add_subject(Subject *sPtr) {

    if (head_subject == nullptr) {
        head_subject = sPtr;
        sPtr->set_next(nullptr);
    } else {
        Subject *current = head_subject;

        while (current->get_next() != nullptr) {
            current = current->get_next();
        } // end while

        current->set_next(sPtr);

        sPtr->set_next(nullptr);
    } // end if-else
}

/**************************************************************************************************
*                                    Trial::find_subject_by_id                                    *
**************************************************************************************************/

Subject* Trial::find_subject_by_id(unsigned int bID) {

    Subject *current = head_subject;
    bool complete = false;

    while (current != nullptr && !complete) {
        if (current->get_subject_id() == bID) {
            complete = true;
        } else {
            current = current->get_next();
        } // end if-else
    } // end while

    return current;
}

/**************************************************************************************************
*                                        Trial::print_list                                        *
**************************************************************************************************/

void Trial::print_list() {

    Subject *current = head_subject;

    while (current != nullptr) {
        cout << *current << endl;
        current = current->get_next();
    }
}

/**************************************************************************************************
*                                    Trial::display_statistics                                    *
**************************************************************************************************/

void Trial::display_statistics() {

    display_factor('c');
    cout << endl;
    display_factor('w');
    cout << endl;
    display_factor('p');
    cout << endl;
}

/**************************************************************************************************
*                                         Trial::average                                          *
**************************************************************************************************/

double Trial::average(char group_code, char symptom_code) {
    double avg = 0, total = 0;
    int count = 0;
    
    Subject *current = head_subject;

    while (current != nullptr) {
        if (tolower(group_code) == tolower(current->get_group())) {
            switch (tolower(symptom_code)) {
                case 'c':
                    total += (current->get_baby()).get_cough();
                    break;
                
                case 'w':
                    total += (current->get_baby()).get_wheezing();
                    break;

                case 'p':
                    total += (current->get_baby()).get_pneumonia();
                    break;                    
            } // end switch
            
            count++;    
        } // end if

        current = current->get_next();
    } // end while
    
    // prevent NaN
    if (count > 0)
        avg = total / static_cast<double>(count);
    else
        avg = 0.0;
    
    return avg;
}

double Trial::deviation(char group_code, char symptom_code, double avg) {
    double stdDev = 0, total = 0;
    int count = 0;
    double xIminusMu = 0;
    
    Subject *current = head_subject;
    
    while (current != nullptr) {
        switch (tolower(symptom_code)) {
            case 'c':
                if (tolower(group_code) == tolower(current->get_group())) {
                    xIminusMu = (((current->get_baby()).get_cough()) - avg);
                    total += pow(xIminusMu, 2);
                    count++;
                }
                break;
                
            case 'w':
                if (tolower(group_code) == tolower(current->get_group())) {
                    xIminusMu = (((current->get_baby()).get_wheezing()) - avg);
                    total += pow(xIminusMu, 2);
                    count++;
                }
                break;
                
            case 'p':
                if (tolower(group_code) == tolower(current->get_group())) {
                    xIminusMu = (((current->get_baby()).get_pneumonia()) - avg);
                    total += pow(xIminusMu, 2);
                    count++;
                }
                break;
        } // end switch

        current = current->get_next();
    } // end while


    // prevent NaN
    if (count > 0)
        stdDev = sqrt(total / count);
    else
        stdDev = 0.0;
    
    return stdDev;  
}

void Trial::display_factor(char symptom_code) {

    double coughCtrlAvg = 0.0, coughExpAvg = 0.0, coughCtrlSD = 0.0, coughExpSD = 0.0;
    double wheezingCtrlAvg = 0.0, wheezingExpAvg = 0.0, wheezingCtrlSD = 0.0, wheezingExpSD = 0.0;
    double pneumoniaCtrlAvg = 0.0, pneumoniaExpAvg = 0.0, pneumoniaCtrlSD = 0.0, pneumoniaExpSD = 0.0;

    string symptomName;

    switch (symptom_code) {
        case 'c':
            symptomName = "coughing";

            coughCtrlAvg = average('c', 'c');
            coughCtrlSD = deviation('c', 'c', coughCtrlAvg);
            coughExpAvg = average('e', 'c');
            coughExpSD = deviation('e', 'c', coughExpAvg);
            
            cout << fixed << showpoint << setprecision(2) << endl << "For the symptoms of " << symptomName << endl;
            cout << setw(25) << "Control average = " << setw(6) << coughCtrlAvg;
            cout << setw(15) << " deviation = " << setw(6) << coughCtrlSD << endl;
            cout << setw(25) << "Experimental average = " << setw(6) << coughExpAvg;
            cout << setw(15) << " deviation = " << setw(6) << coughExpSD << endl;
            break;

        case 'w':
            symptomName = "wheezing";

            wheezingCtrlAvg = average('c', 'w');
            wheezingCtrlSD = deviation('c', 'w', wheezingCtrlAvg);
            wheezingExpAvg = average('e', 'w');
            wheezingExpSD = deviation('e', 'w', wheezingExpAvg);

            cout << "For the symptoms of " << symptomName << endl;
            cout << setw(25) << "Control average = " << setw(6) << wheezingCtrlAvg;
            cout << setw(15) << " deviation = " << setw(6) << wheezingCtrlSD << endl;
            cout << setw(25) << "Experimental average = " << setw(6) << wheezingExpAvg;
            cout << setw(15) << " deviation = " << setw(6) << wheezingExpSD << endl;
            break;

        case 'p':
            symptomName = "pneumonia";

            pneumoniaCtrlAvg = average('c', 'p');
            pneumoniaCtrlSD = deviation('c', 'p', pneumoniaCtrlAvg);
            pneumoniaExpAvg = average('e', 'p');
            pneumoniaExpSD = deviation('e', 'p', pneumoniaExpAvg);

            cout << "For the symptoms of " << symptomName << endl;
            cout << setw(25) << "Control average = " << setw(6) << pneumoniaCtrlAvg;
            cout << setw(15) << " deviation = " << setw(6) << pneumoniaCtrlSD << endl;
            cout << setw(25) << "Experimental average = " << setw(6) << pneumoniaExpAvg;
            cout << setw(15) << " deviation = " << setw(6) << pneumoniaExpSD << endl;
            break;
    }

}

/**************************************************************************************************
*                                                                                                 *
*                                                                                                 *
*                                              MAIN                                               *
*                                                                                                 *
*                                                                                                 *
**************************************************************************************************/

int main() {

    string subject_file, baby_file;
    Trial trial;

    cout << "Project 5 - RSV Vaccine Effectiveness Analysis\n";
    
    cout << "Enter name of subject file: ";
    cin >> subject_file;
    cin.ignore(500, '\n');


    cout << "Enter name of baby file: ";
    cin >> baby_file;
    cin.ignore(500, '\n');

    trial.load_subject_file(subject_file);
    trial.load_baby_file(baby_file);

    trial.display_statistics();

    return 0;
}

/**************************************************************************************************
*                                 Overloaded Assignment Operators                                 *
**************************************************************************************************/

// Baby friend operators

istream& operator>>(istream &in, Baby &b) {

    in >> b.mom_id >> b.cough >> b.wheezing >> b.pneumonia;

    return in;
}

ostream& operator<<(ostream &out, Baby b) {

    out << fixed << showpoint << setprecision(2);

    out << setw(12) << b.mom_id << " ";
    out << setw(4) << b.cough << " ";
    out << setw(4) << b.wheezing << " ";
    out << setw(4) << b.pneumonia;

    return out;
}

// Subject friend operators

istream& operator>>(istream &in, Subject &ps) {

    in >> ps.subject_id >> ps.group;

    return in;
}

ostream& operator<<(ostream &out, Subject s) {

    out << setw(12) << s.subject_id << " ";
    out << setw(2) << s.group;

    return out;
}