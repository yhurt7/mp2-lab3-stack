#include "TFormuls.h"
#include <gtest.h>

using testing::Types;

template <class>
class TFormulsTest : public testing::Test {};

TEST(TFormulstest, without_prohibited_symbols)
{
  TFormuls a("1+2");
  a.Process();
  EXPECT_EQ(a.GetPostfix(),"12+");
}
TEST(TFormulstest, without_prohibited_symbols1)
{
  TFormuls a("(a-b)*2");
  a.Process();
  EXPECT_EQ(a.GetPostfix(),"ab-2*");
}
TEST(TFormulstest, without_prohibited_symbols2)
{
  TFormuls a("1+a^2");
  a.Process();
  EXPECT_EQ(a.GetPostfix(),"1a2^+");
}

