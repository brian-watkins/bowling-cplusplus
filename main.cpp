#include <iostream>
#include "BowlingEngine.h"


int main(int argc, char const *argv[])
{
  BowlingEngine engine;

  engine.roll(1);
  engine.roll(7);
  
  engine.roll(10);
  
  engine.roll(10);
  
  engine.roll(6);
  engine.roll(4);

  engine.roll(10);

  engine.roll(8);
  engine.roll(0);

  engine.roll(2);
  engine.roll(8);

  engine.roll(7);
  engine.roll(1);

  engine.roll(10);

  engine.roll(6);
  engine.roll(4);
  engine.roll(10);

  std::cout << "your score is: " << engine.score() << "\n";

  return 0;
}
