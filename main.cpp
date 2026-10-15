// ------------- FILE HEADER -------------
// Author ✅: 
// Assignment ✅:
// Date ✅:
// Citations: 
// https://glen-sasek-pcc-instructor.github.io/PCC-CS-161A/Assignment-4.html


// ------------- CODE -------------
#include <iostream>

using namespace std;

const string MESSAGE_WELCOME = "HI";
const string MESSAGE_GOODBYE = "BYE";
const string NO_MATCH = "No Match :(";
const string PHRASES_EQUAL = "Phrases are the same";
const string LABEL_FOUND_IN = "FOUND IN";

const string PROMPT_PHRASE_1 = "Enter Phrase 1";
const string PROMPT_PHRASE_2 = "Enter Phrase 2";

const string LABEL_PHRASE_CONFIRM = "You entered";



// Function prototypes (if any)

// COMPILE and RUN TESTS and CLEANUP
// g++ main.cpp && for x in test*txt; do echo -e "\n\nTEST: $x"; ./a.out < $x; done; rm ./a.out


// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main() {
    string phrase_1 = "";
    string phrase_2 = "";

    cout << MESSAGE_WELCOME;
    cout << endl;

    cout << PROMPT_PHRASE_1 << ": ";
    getline(cin, phrase_1); // https://en.cppreference.com/cpp/string/basic_string/getline
    cout << LABEL_PHRASE_CONFIRM << ": " << phrase_1;
    cout << endl;

    cout << PROMPT_PHRASE_2 << ": ";
    getline(cin, phrase_2); 
    cout << LABEL_PHRASE_CONFIRM << ": " << phrase_2;
    cout << endl;

    // CALCULATIONS
    // Find the position of a phrase_2 in phrase_1
    // https://en.cppreference.com/w/cpp/string/basic_string/find.html
    size_t pos_2_in_1 = phrase_1.find(phrase_2);
    size_t pos_1_in_2 = phrase_2.find(phrase_1);
    
    bool phrases_equal = phrase_1 == phrase_2;
    bool phrase_2_in_phrase_1 = pos_2_in_1 != string::npos;
    bool phrase_1_in_phrase_2 = pos_1_in_2 != string::npos;
    bool no_match = not(phrases_equal or phrase_1_in_phrase_2 or phrase_2_in_phrase_1);

    string substring_from_first_match_to_end = "";
    if(phrases_equal) {
      substring_from_first_match_to_end = phrase_1;
    } else if(phrase_2_in_phrase_1) {
      substring_from_first_match_to_end = phrase_1.substr(pos_2_in_1);
    } else if(phrase_1_in_phrase_2) {
      substring_from_first_match_to_end = phrase_2.substr(pos_1_in_2);
    } 

    // DISPLAY RESULTS
    if(phrases_equal) {
      cout << PHRASES_EQUAL;
    } else if(phrase_2_in_phrase_1) {
      cout << phrase_2 << endl;
      cout << LABEL_FOUND_IN << endl;
      cout << phrase_1 << endl;
      cout << substring_from_first_match_to_end << endl;
    } else if(phrase_1_in_phrase_2) {
      cout << phrase_1 << endl;
      cout << LABEL_FOUND_IN << endl;
      cout << phrase_2 << endl;
      cout << substring_from_first_match_to_end << endl;
    } else {
      cout << NO_MATCH;
    }    

    return 0;
}

// Function implementations (if any)


// ------------- DESIGN -------------
/* 
Program Name:

Program Description:

Design:
A. INPUT
string phrase_1 = "";
string phrase_2 = "";

B. OUTPUT
phrase_1
phrase_2

C. CALCULATIONS
bool phrases_equal = phrase_1 == phrase_2;
bool phrase_1_in_phrase_2 = TEST phrase_1 in phrase_2
bool phrase_2_in_phrase_1 = TEST phrase_2 in phrase_1

string substring_from_first_match_to_end = IMPLEMENT;

D. LOGIC and ALGORITHMS
MESSAGE welcome

PROMPT PROMPT_PHRASE_1
INPUT phrase_1

LABEL LABEL_PHRASE_1_CONFIRM
DATA phrase_1

PROMPT PROMPT_PHRASE_2
INPUT phrase_2

LABEL LABEL_PHRASE_2_CONFIRM
DATA phrase_2

CALCULATIONS

DISPLAY RESULTS Specified in sample runs

MESSAGE Goodbye


SAMPLE RUNS
Welcome to the Phrases and Subphrases program!
Enter Phrase 1: truck
You entered: truck
Enter Phrase 2: firetruck is here
You entered: firetruck is here
truck is found in firetruck is here
truck is here
Thank you for using my program!


Welcome to the Phrases and Subphrases program!
Enter Phrase 1: the green grass grows
You entered: the green grass grows
Enter Phrase 2: green grass
You entered: green grass
green grass is found in the green grass grows
green grass grows
Thank you for using my program!


Welcome to the Phrases and Subphrases program!
Enter Phrase 1: He was between a rock and a hard place
You entered: He was between a rock and a hard place
Enter Phrase 2: rock
You entered: rock
rock is found in He was between a rock and a hard place
rock and a hard place
Thank you for using my program!

*/
