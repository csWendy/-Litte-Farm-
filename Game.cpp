/*
Author: <Xiaoning Wang>
Course: {235}
Instructor: <Pavel Shostak>
Assignment: <Home Project 1>
@file Game.cpp
*/

#include "Game.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Tractor::Tractor()
{
  x = y = 2;
  size = 2;
  activity = IDLE;
}

Tractor::Tractor(int x_val, int y_val, unsigned short size_val, Activity activity_val)
{
	x = x_val;
	y = y_val;
	size = size_val;
	activity = activity_val;
}


int Tractor::get_x() const
{
	return x;
}

int Tractor::get_y() const
{
	return y;
}

unsigned short Tractor::get_size() const
{
	return size;
}

Activity Tractor::get_activity() const
{
	return activity;
}

int Tractor::set_x(int new_x) 
{
	x = new_x;
}

int Tractor::set_y(int new_y)
{
	y = new_y;
}

unsigned short Tractor::set_size(unsigned short new_size)
{
	size = new_size;
}

Activity Tractor::set_activity(Activity new_activity)
{
	activity = new_activity;
}

Game::Game(unsigned int new_size)
{
	map_size = new_size;
}

int Game::GetTractor(int x, int y) const // returns the index in all vector of the tractor that occupies location (x,y).
{
	for (int i = 0; i < all.size(); i++)
	{
		if ((x >= all[i].get_x() - all[i].get_size()/2.0) && 
			(x <= all[i].get_x() + all[i].get_size()/2.0) && 
			(y >= all[i].get_y() - all[i].get_size()/2.0) && 
			(y <= all[i].get_y() + all[i].get_size()/2.0)) 
		    // check if user click inside the square of a tractor. 
			return i;
		else 
			return -1;
	}
	
}

void Game::SelectTractor(int x, int y) //empty the selected-vector.Put the index of the selected tractor(located on (x,y)) in it.
{
	selected.resize(0);
	for (int i = 0; i < all.size(); i++)
	{
		if ((x >= all[i].get_x() - all[i].get_size()/2.0) && (x <= all[i].get_x() + all[i].get_size()/2.0) && (y >= all[i].get_y() - all[i].get_size()/2.0) && 
			(y <= all[i].get_y() + all[i].get_size()/2.0)) selected.push_back(i);
		else 
			selected.resize(0);
	}
		
}

void Game::SelectTractors(int ox1, int oy1, int ox2, int oy2) //selects all tractors located in the rectangular defined by (x1,y1) and (x2,y2).
{
	int x1,x2,y1,y2;
	if(ox1 < ox2) 
	{
		 x1=ox1; 
		 x2=ox2;
	}
	else
	{
		x1=ox2; x2=ox1;
	} 
	if(oy1 < oy2) 
	{
		 y1=oy1; 
		 y2=oy2;
	}
	else 
	{
		y1=oy2; 
		y2=oy1; 
	}


	selected.resize(0);
	if ((x1 >= 0) && (x2 <= map_size) && (y1 >= 0) && (y2 <= map_size))
	{
		for (int i = 0; i < all.size(); i++)
		{
			if ((all[i].get_x() >= x1 - all[i].get_size()/2.0 ) && ( all[i].get_y() >= y1 - all[i].get_size()/2.0))
			{
				if ((all[i].get_x() <= x2 + all[i].get_size()) && (all[i].get_y() <= y2 + all[i].get_size()/2.0)) selected.push_back(i);
			}
			else
				selected.resize(0);
		}
	}
	else 
		selected.resize(0);
}


 void Game::AddTractor(const Tractor &new_unit)//adds the new tractor to all vector. 
 {
 	if ((new_unit.get_size()/2.0 <= new_unit.get_x()) && (new_unit.get_size()/2.0 <= new_unit.get_y()) && 
 		(new_unit.get_x() <= map_size - new_unit.get_size()/2.0) && (new_unit.get_y() <= map_size - new_unit.get_size()/2.0))
		all.push_back(new_unit); 
	else 
		cout << "Invalid tractor coordinates!" << endl;
 }

 bool Game::MoveTractor(int i, int new_x, int new_y)//moves the tractor number i in all to the new coordinates if it is possible.
 {
 	if ((new_x <= map_size - all[i].get_size()/2.0) && (new_x >= all[i].get_size()/2.0) &&(new_y <= map_size - all[i].get_size()/2.0) && (new_y >= all[i].get_size()/2.0))
 	{
 		for (int k = 0 ; k < all.size(); k++)
 		if (((new_x >= all[k].get_x() + all[k].get_size()/2.0 + all[i].get_size()/2.0) && (new_y >= all[k].get_y() + all[k].get_size()/2.0 + all[i].get_size()/2.0)) || 
 			((new_x <= all[k].get_x() - all[k].get_size()/2.0 - all[i].get_size()/2.0) && (new_y <= all[i].get_y() - all[i].get_size()/2.0 - all[i].get_size()/2.0))) 
			//(all[i].GetTractor(new_x,new_y) == -1) didn't work. Can I use the method of GetTractor here?
 		{
			all[i].set_x(new_x);
			all[i].set_y(new_y);
			return true;
		}
		else 
		{
			all[i].set_x(all[i].get_x());
			all[i].set_y(all[i].get_y());
 			return false;
 		}
 	}
 	else
 	{
 		all[i].set_x(all[i].get_x());
		all[i].set_y(all[i].get_y());
 		return false;
 	}
}


void Game::AssignTractorsActivity(Activity new_activity) //sets the new_activity for all selected tractors.
{
	for (int i = 0; i < selected.size();i++ )
		all[selected[i]].set_activity(new_activity);
}

void Game::PrintTractor(int i)//prints the tractor number i from the all-vector. 
{
	if (i >=0  && i < all.size ())
	{
		cout << "The Tractor of index" <<" "<<  i  << " " << " located at " << " " << "(" << all[i].get_x() << "," << all[i].get_y() << " ) " << endl;
		cout << "Size: " << " " << all[i].get_size() << endl;
		cout << "Activity: " << " " << all[i].get_activity() << endl;// ?????????????? How to print enum activity?  
	} 

	else 
		cout << "Invalid index!" << endl;
}

void Game::PrintSelectedTractors()//prints selected units. 
{
	for (int i = 0; i < selected.size(); i++)
	{
		cout << selected[i] << endl;  
	} 
}

  void Game::PrintAllTractors()// prints all units. 
  {
	for (int i = 0; i < all.size(); i ++)
	{
		cout <<"Tractor" << " " << i << " " <<"located at" << " " << "(" << all[i].get_x() << "," << all[i].get_y() << " ) " << endl;
		cout << "Size: " << " " << all[i].get_size() << endl;
		cout << "Activity: " << " " << all[i].get_activity() << endl;   
	}
  }  






