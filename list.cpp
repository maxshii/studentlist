#include <iostream>

#include <vector>

#include <iterator>

#include <cstring>

#include <iomanip>

#include <algorithm>

using namespace std;

struct Student {
  char first[80];
  char last[80];
  int id;
  float gpa;
};

void
del(vector < Student * > * v, int i);

void add(vector < Student * > * v);

void print(vector < Student * > * v);

int
main() {
  vector < Student * > studentList;
  vector < Student * > * vectorPointer = new vector < Student * > ();
  vectorPointer = & studentList;

  while(true) {
      char input[80];
      cin.getline(input, 80, '\n');
      if (strcmp(input, "ADD")==0)
      {
          add(vectorPointer);
      }
      else if (strcmp(input, "PRINT")==0)
      {
          print(vectorPointer);
      }
      else if (strcmp(input, "DELETE")==0)
      {
          int id = 0;
          cout << "Enter ID: ";
          cin >> id;
          del(vectorPointer, id);
      }
      else if (strcmp(input, "QUIT")==0)
      {
          break;   
      }
  }
 
  return 0;
}

void
add(vector < Student * > * v) {
  char first[80];
  char last[80];
  int id;
  float gpa;
  cout << "Enter first name: ";
  cin >> first;
  cout << "Enter last name: ";
  cin >> last;
  cout << "Enter id: ";
  cin >> id;
  cout << "Enter gpa: ";
  cin >> gpa;
  

  Student * a = new Student();
  strcpy(a -> first, first);
  strcpy(a -> last, last);
  a -> id = id;
  a -> gpa = gpa;
  (v) -> push_back(a);
}

void
print(vector < Student * > * v) {
  vector < Student * > ::iterator ptr;

  for (ptr = v -> begin(); ptr < v -> end(); ++ptr) {

    cout << ( * ptr) -> first << " " << ( * ptr) -> last << ", " << ( * ptr) ->
      id << ", " << fixed << setprecision(2) << ( * ptr) -> gpa << endl;
  }

}

void del(vector < Student * > * v, int i) {
  vector < Student * > ::iterator ptr;
  int count = 0;
  for (ptr = v -> begin(); ptr < v -> end(); ++ptr) {
    if (( * ptr) -> id == i) {
      
      delete *ptr;
    
      v -> erase(ptr);
    }

    count++;
  }

}
