#include <gtest/gtest.h>
#include "BowlingEngine.h"

void rollMany (BowlingEngine * subject, int frames, int pins) {
  for (int i = 0; i < frames; i++) {
    subject->roll(pins);
  }
}

TEST(BowlingTests, AllGutterBalls) {
  BowlingEngine subject;
  rollMany(&subject, 20, 0);
  EXPECT_EQ(0, subject.score());
}

TEST(BowlingTests, AllOnes) {
  BowlingEngine subject;
  rollMany(&subject, 20, 1);
  EXPECT_EQ(20, subject.score());
}

TEST(BowlingTests, OnesWithSpare) {
  BowlingEngine subject;
  subject.roll(1);
  subject.roll(1);
  subject.roll(7);
  subject.roll(3);
  subject.roll(4);
  rollMany(&subject, 15, 1);
  EXPECT_EQ(35, subject.score());
}

TEST(BowlingTests, OnesWithStrike) {
  BowlingEngine subject;
  subject.roll(1);
  subject.roll(1);
  subject.roll(10);
  subject.roll(4);
  subject.roll(2);
  rollMany(&subject, 14, 1);
  EXPECT_EQ(38, subject.score());
}

TEST(BowlingTests, AllStrikes) {
  BowlingEngine subject;
  rollMany(&subject, 12, 10);
  EXPECT_EQ(300, subject.score());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}