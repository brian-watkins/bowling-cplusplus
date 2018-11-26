#include "BowlingEngine.h"

void BowlingEngine::roll (int pins) {
  rolls[rollIndex++] = pins;
}

int BowlingEngine::score () {
  int currentScore = 0;
  int i = 0;
  int frames = 0;
  while (i < rollIndex && frames < 10) {
    if (isStrike(&rolls[i])) {
      currentScore += scoreStrike(&rolls[i]);
      i++;
    }
    else if (isSpare(&rolls[i])) {
      currentScore += scoreSpare(&rolls[i]);
      i = i + 2;
    }
    else {
      currentScore += scoreNormal(&rolls[i]);
      i = i + 2;
    }
    frames++;
  }

  return currentScore;
}

int BowlingEngine::scoreStrike (int rolls []) {
  return 10 + rolls[1] + rolls[2];
}

int BowlingEngine::scoreSpare (int rolls []) {
  return 10 + rolls[2];
}

int BowlingEngine::scoreNormal (int rolls []) {
  return rolls[0] + rolls[1];
}

bool BowlingEngine::isStrike (int rolls []) {
  return rolls[0] == 10;
}

bool BowlingEngine::isSpare (int rolls []) {
  return rolls[0] + rolls[1] == 10;
}

