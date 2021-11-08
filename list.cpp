/******************************************************************************

Online C++ Compiler.
Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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

  Student * baka = new Student();
  strcpy(baka -> first, "Max");
  strcpy(baka -> last, "Shi");
  baka -> id = 42;
  baka -> gpa = 5.0;
  (vectorPointer) -> push_back(baka);

  print(vectorPointer);

  add(vectorPointer);
  //del(vectorPointer, 42);
  print(vectorPointer);

  cout <<(&vectorPointer[0]) << '\n' << &((*vectorPointer)[0]->first) << '\n';
  cout << &baka << '\n' << &(baka->first) << '\n';
  cout << &(baka->last) << '\n' << &(baka->id) ;
  delete baka;
  
  cout << baka->first;
  return 0;
}

void
add(vector < Student * > * v) {
  char first[80] = "fdas";
  char last[80] = "fff";
  int id = 1;
  float gpa = 2;
  /*cout << "Enter first name: ";
  cin >> first;
  cout << "Enter last name: ";
  cin >> last;
  cout << "Enter id: ";
  cin >> id;
  cout << "Enter gpa: ";
  cin >> gpa;
  */

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

      v -> erase(ptr);
      
    }

    count++;
  }

}
