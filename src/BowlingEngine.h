#ifndef BowlingEngine_H
#define BowlingEngine_H

class BowlingEngine {
  int rolls [21] = {};
  int rollIndex = 0;
  bool isSpare(int []);
  bool isStrike(int []);
  int scoreStrike(int []);
  int scoreSpare(int []);
  int scoreNormal(int []);

  public:
    void roll (int pins);
    int score ();
};

#endif