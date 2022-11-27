#include "gtest.h"
#include "TStack.h"

TEST(TStack, positive_length)
{
  TStack<int> a;
  a.Push(2);
  a.Push(3);
  EXPECT_EQ(a.Top(),3);
}
TEST(TStack, positive_length1)
{
  TStack<int> a;
  a.Push(2);
  a.Push(3);
  a.Pop();
  EXPECT_EQ(a.Top(),2);
}
