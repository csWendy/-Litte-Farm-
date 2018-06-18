
/*
Author: <Xiaoning Wang>
Course: {235}
Instructor: <Pavel Shostak>
Assignment: <Home Project 1>
@file Game.h
*/

#ifndef GAME_
#define GAME_
#include <vector>
using namespace std;

enum Activity {SEEDING, HARVESTING, MOVING, IDLE};

class Tractor
{
private:
  int x,y;//coordinator of the tractor, x and y is the center.
  unsigned short size;//size of the tractor. 
  Activity activity;  //current activity.
public:
  Tractor();//the default constructor that sets all fields to some default values 
  Tractor(int x_val, int y_val, unsigned short size_val, Activity activity_val); //the constructor that sets all fields to the given values.
  int get_x() const;
  int get_y() const;
  unsigned short get_size() const;
  Activity get_activity() const;
  int set_x(int new_x);
  int set_y(int new_y);
  unsigned short set_size(unsigned short new_size);
  Activity set_activity (Activity new_activity);
};

class Game
{
private:
  unsigned int map_size;//size of the game map.
  std::vector<Tractor> all;//list of all tractors on the map
  std::vector <int> selected;//indexes of all units currently selected in all-vector.
public:
  Game(unsigned int new_size);
  int GetTractor(int x, int y) const;//returns the index in all-vector of the tractor that occupies location (x,y).
  void SelectTractor(int x, int y); //empty the selected-vector.Put the index of the selected tractor(located on (x,y)) in it.
  void SelectTractors(int ox1, int oy1, int ox2, int oy2);//selects all tractors located in the rectangular defined by (x1,y1) and (x2,y2).
  void AddTractor(const Tractor& new_unit);//adds the new tractor to all-vector. 
  bool MoveTractor(int i, int new_x, int new_y);//moves the tractor number i to the new coordinates if it is possible.
  void AssignTractorsActivity(Activity new_activity); //sets the new_activity for all selected tractors.
  void PrintTractor(int i);//prints the tractor number i from the all-vector. 
  void PrintSelectedTractors();//prints selected units. 
  void PrintAllTractors();// prints all units.   
};
  
#include "Game.cpp"
#endif
  


