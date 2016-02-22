//building.cpp

#include <iostream>  //Library file so uses <>
#include <algorithm>
#include "building.h"

using namespace std;


building::building()
: names(0, vector<string>(0)),
  ids(0, vector<string>(0))
{
}

building::building(const int f, const int r)
: names(f, vector<string>(r)),
  ids(f, vector<string>(r))
{
}

building::building(const int f, const int r, const char theName[], const char theID[])
: names(f, vector<string>(r)),
  ids(f, vector<string>(r))
{
	//... put person with name theName[ ] and ID theID[]
	//... into room 0 on floor 0
  names.at(0).at(0) = theName;
  ids.at(0).at(0) = theID;


}

void building::Put(const char theName[], const char theID[], int f, int r)
{
  //... check if f and r are valid
  //... if valid, put person with name theName[] and ID theID
  //... into room r on floor f
  if(IsValidRoom(f, r)) {
    names.at(f).at(r) = theName;
    ids.at(f).at(r) = theID;
  }

}

void building::Empty(int f, int r)
{
    if (IsValidRoom(f,r))
		names[f][r] = "";
}

void building::Display(int f, int r)
{
  if (IsValidRoom(f, r)) {
    if (IsEmpty(f,r))
    {
      cout << "Room " << r << " on floor " << f << " is empty" << endl;
    }
    else
    {
      cout << "Occupant of Room " << r << " on floor " << f;
      cout << " is " << names[f][r];
      cout << ", Identity number "  << ids[f][r] << endl;
    }
  }
}

void building::Display(int f)
{
  if (IsValidFloor(f)) {
    int nonEmptyRoom = 0;

	for(int r = 0; r < names[f].size(); r++) {
      if (!IsEmpty(f,r))
      {
        nonEmptyRoom++;
        cout << "Occupant of Room " << r << " on floor " << f;
        cout << " is " << names[f][r];
        cout << ", Identity number "  << ids[f][r] << endl;
      }
    }

    if (nonEmptyRoom == 0)
      cout << "Floor " << f << " is empty" << endl;
  }
}

void building::Display()
{
  int nonEmptyRoom = 0;
  for (int f = 0; f < names.size(); f++) {
    for(int r = 0; r < names[f].size(); r++) {
      if (!IsEmpty(f,r))
      {
        nonEmptyRoom++;
        cout << "Occupant of Room " << r << " on floor " << f;
        cout << " is " << names[f][r];
        cout << ", Identity number "  << ids[f][r] << endl;
      }
    }
  }
  if (nonEmptyRoom == 0)
    cout << "The building is empty" << endl;
}

int building::Vacancies(int f) const
{
  //... check f is valid
  //... if f is valid, count the number of empty rooms at floor f
  //... if f is invalid, output error message and return -1
  if(IsValidFloor(f)) {
    int r = 0;
    for(int i = 0; i < names.at(f).size() ;i++) {
      if(IsEmpty(f, i)) {
        r++;
      }
    }
    return r;
  }
	cout << "Floor " << f << " is invalid, cannot cound vacancies" << endl;
	return -1;
}

int building::Vacancies() const
{
  //... count the number of empty rooms in the whole building
  int r = 0;
  for(int i = 0; i < names.size(); i++) {
    r += Vacancies(i);
  }
  return r;
	return -1;
}

bool building::IsEmpty(int f, int r) const
{
	return (names[f][r] == "");
}

void building::AddFloor(int r)
{
  //... add a floor with r number of rooms to the building
  //... all newly added rooms should be empty
  //... the new floor should be the highest level floor
  //... hints:
  //... use member function push_back() or insert() of std::vector
  names.push_back(vector<string>(r));
  ids.push_back(vector<string>(r));

}

void building::AddRoom(int f)
{
  //... check if f is valid
  //... if valid, add an empty room on floor f to the building
  //... hints:
  //... use member function push_back() or insert() of std::vector
  if(IsValidFloor(f)) {
    names.at(f).push_back("");
    ids.at(f).push_back("");
  }

}

void building::RemoveFloor()
{
  //... remove the last (highest level) floor
  //... hints:
  //... use member function pop_back() or erase() of std::vector
  names.pop_back();
  ids.pop_back();
}

void building::RemoveRoom(int f)
{
  //... check if f is valid
  //... remove the last room (biggest room number) on floor f
  //... hints:
  //... use member function pop_back() or erase() of std::vector
  if(IsValidFloor(f)) {
    names.at(f).pop_back();
    ids.at(f).pop_back();
  }
}

ostream& operator<<(ostream& os, const building& b)
{
  //... print out the names separated with a space (i.e. ' ')
  //... in alphabetical order
  //... hints:
  //... store all names in a string vector and apply STL algorithm sort()
  vector<string> namess;
  for(int f = 0; f < b.names.size(); f++) {
    for(int r = 0; r < b.names.at(f).size(); r++) {
      namess.push_back(b.names.at(f).at(r));
    }
  }
  sort(namess.begin(), namess.end());

  for(int i = 0; i < namess.size(); i++) {
    os << namess.at(i) << " ";
  }
  os << endl;
  return os;
}

bool operator==(const building& b1, const building& b2)
{
  return b1.Vacancies() == b2.Vacancies();
}

bool building::IsValidFloor(int f) const {
  bool valid = ((0 <= f) && (f < names.size()));
  if (! valid) {
    cerr << "Floor " << f << " is out of range!\n";
  }
  return valid;
};

bool building::IsValidRoom(int f, int r) const {
  bool valid = (IsValidFloor(f) && (0 <= r) && (r < names[f].size()));
  if (! valid) {
    cerr << "Room " << r << " on floor " << f << " is out of range!\n";
  }
  return valid;
};
