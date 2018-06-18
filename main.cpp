#include"Game.h"
#include<iostream>

using namespace std;

int main()
{
    Game g(100);
    Tractor trt1(10,10,4,IDLE);
    Tractor trt2(50,50,4,IDLE);
    Tractor trt3(90,90,4,IDLE);

    g.AddTractor(trt1);
    g.AddTractor(trt2);
    g.AddTractor(trt3);

    g.PrintAllTractors(); // all three tractors should be printed out

    cout<<"Clicking (9,9) found the tractor number "<<g.GetTractor(9,9)<<endl; // should be tractor number 0
    g.SelectTractor(89,90);
    g.PrintSelectedTractors(); // should print 2

    g.PrintSelectedTractors(); // should print 2

    g.SelectTractors(11,49,49,11);
    g.PrintSelectedTractors(); // should print 0 1

    g.AssignTractorsActivity(HARVESTING);
    g.PrintAllTractors(); // Tractors 0 and 1 should be HARVESTING. Tractor 2 should be IDLE.

    if(!g.MoveTractor(2,99,99)) cout<<"Cannot move tractor 2 to coordinates (99,99)"<<endl; // You should see this message
    if(!g.MoveTractor(2,13,13)) cout<<"Cannot move tractor 2 to coordinates (13,13)"<<endl; // You should see this message

    g.MoveTractor(2,80,50);
    g.PrintTractor(2); // should be the IDLE tractor of size 4 at coordinates (80,50)

    return 0;
}






/*#include "Game.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main ()
{

Game game(100);
Tractor t1;
Tractor t2(3,5,4,HARVESTING);
Tractor t3(7,9,2,SEEDING);
Tractor t4(101, 100, 8,SEEDING);
game.AddTractor(t1);
game.AddTractor(t2);
game.AddTractor(t3);
game.AddTractor(t4);

game.SelectTractor(7,9);
game.PrintSelectedTractors();


game.SelectTractors(0,0,100,100);
game.PrintSelectedTractors();
game.AssignTractorsActivity(HARVESTING);
game.PrintSelectedTractors();


game.PrintTractor(2);
game.MoveTractors(2, 20, 20);
game.PrintTractor(2);

game.PrintAllTractors();


}
*/