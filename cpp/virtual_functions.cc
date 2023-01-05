#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Person
{
 protected:
  int age;
  string name;

 public:
  virtual void putdata() = 0;
  virtual void getdata() = 0;
};

class Professor : public Person
{
  static int cur_id;
  int publications;
  int id;

 public:
  Professor()
  {
    id = Professor::cur_id;
    Professor::cur_id++;
  }
  virtual ~Professor() {}

  virtual void getdata()
  {
    cin >> name >> age >> publications;
  }

  virtual void putdata()
  {
    cout << name << " " << age << " " << publications
         << " " << id;
    cout << endl;
  }
};

class Student : public Person
{
  static int cur_id;
  vector<int> marks;
  int id;

 public:
  Student() : marks(6)
  {
    id = Student::cur_id;
    Student::cur_id++;
  }
  virtual ~Student() {}

  virtual void getdata()
  {
    cin >> name >> age;
    for (int& mark : marks)
      cin >> mark;
  }

  virtual void putdata()
  {
    cout << name << " " << age << " ";
    cout << accumulate(marks.begin(), marks.end(), 0) << " ";
    cout << id;
    cout << endl;
  }
};

int Professor::cur_id = 1;
int Student::cur_id = 1;

int main()
{
  int n, val;
  cin >> n;  //The number of objects that is going to be created.
  Person* per[n];

  for (int i = 0; i < n; i++)
  {
    cin >> val;
    if (val == 1)
    {
      // If val is 1 current object is of type Professor
      per[i] = new Professor;
    }
    else
      per[i] = new Student;  // Else the current object is of type Student

    per[i]->getdata();  // Get the data from the user.
  }

  for (int i = 0; i < n; i++)
    per[i]->putdata();  // Print the required output for each object.

  return 0;
}
