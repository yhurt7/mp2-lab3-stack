#include "TVector.h"
#include <gtest.h>

using testing::Types;

template <class>
class TVectorTest : public testing::Test {};
typedef Types<int, double> Implementations;
TYPED_TEST_CASE(TVectorTest, Implementations);

TYPED_TEST(TVectorTest, can_create_vector_with_positive_size)
{
  ASSERT_NO_THROW(TVector<TypeParam> vec(3));
}

TYPED_TEST(TVectorTest, can_not_create_vector_with_negative_size)
{
  ASSERT_ANY_THROW(TVector<TypeParam> vec(-1));
}

TYPED_TEST(TVectorTest, can_create_vector_from_other_vector)
{
  TVector<TypeParam> vec1(2);
  vec1[0] = 0;
  vec1[1] = 1;
  TVector<TypeParam> vec2(vec1);
  EXPECT_EQ(vec1.GetLength(), vec2.GetLength());
  EXPECT_EQ(vec1[0], vec2[0]);
  EXPECT_EQ(vec1[1], vec2[1]);
}

TYPED_TEST(TVectorTest, can_not_create_vector_from_vector_with_zero_size_or_nullptr_pmem)
{
  TVector<TypeParam> vec1;
  ASSERT_ANY_THROW(TVector<TypeParam> vec2(vec1));
}

TYPED_TEST(TVectorTest, can_get_size)
{
  TVector<TypeParam> vec(3);
  EXPECT_EQ(3, vec.GetLength());
}

TYPED_TEST(TVectorTest, can_SetLength_vector)
{
  TVector<TypeParam> vec1(1);
  vec1[0] = 0;
  vec1.SetLength(2);
  vec1[1] = 1;
  EXPECT_EQ(vec1.GetLength(), 2);
  EXPECT_EQ(vec1[0], 0);
  EXPECT_EQ(vec1[1], 1);
}

TYPED_TEST(TVectorTest, can_not_SetLength_vector_to_negative_size)
{
  TVector<TypeParam> vec1(1);
  ASSERT_ANY_THROW(vec1.SetLength(-1));
}

TYPED_TEST(TVectorTest, can_copy_vector)
{
  TVector<TypeParam> vec1(2);
  vec1[0] = 0;
  vec1[1] = 1;
  TVector<TypeParam> vec2 = vec1;
  EXPECT_EQ(vec1.GetLength(), vec2.GetLength());
  EXPECT_EQ(vec1[0], vec2[0]);
  EXPECT_EQ(vec1[1], vec2[1]);
}

TYPED_TEST(TVectorTest, can_not_copy_vector_to_itself)
{
  TVector<TypeParam> vec1(2);
  vec1[0] = 0;
  vec1[1] = 1;
  ASSERT_ANY_THROW(vec1 = vec1);
}

TYPED_TEST(TVectorTest, can_check_vector_equivalence)
{
  TVector<TypeParam> vec1(2);
  vec1[0] = 0;
  vec1[1] = 1;
  TVector<TypeParam> vec2(2);
  vec2[0] = 0;
  vec2[1] = 1;
  EXPECT_EQ(vec1 == vec2, true);
}

TYPED_TEST(TVectorTest, can_check_vector_nonequivalence)
{
  TVector<TypeParam> vec1(2);
  vec1[0] = 0;
  vec1[1] = 1;
  TVector<TypeParam> vec2(2);
  vec2[0] = 0;
  vec2[1] = 1;
  EXPECT_EQ(vec1 != vec2, false);
}

TYPED_TEST(TVectorTest, can_not_check_vector_equivalence_with_nullptr)
{
  TVector<TypeParam> vec1;
  TVector<TypeParam> vec2;
  ASSERT_ANY_THROW(vec1 == vec2);
}

TYPED_TEST(TVectorTest, can_not_check_vector_nonequivalence_with_nullptr)
{
  TVector<TypeParam> vec1;
  TVector<TypeParam> vec2;
  ASSERT_ANY_THROW(vec1 != vec2);
}

TYPED_TEST(TVectorTest, can_sum_vectors)
{
  TVector<TypeParam> vec1(2);
  vec1[0] = 1;
  vec1[1] = 2;
  TVector<TypeParam> vec2(2);
  vec2[0] = 1;
  vec2[1] = 2;
  TVector<TypeParam> vec3 = vec1 + vec2;
  EXPECT_EQ(vec3.GetLength(), 2);
  EXPECT_EQ(vec3[0], 2);
  EXPECT_EQ(vec3[1], 4);
}

TYPED_TEST(TVectorTest, can_substract_vectors)
{
  TVector<TypeParam> vec1(2);
  vec1[0] = 5;
  vec1[1] = 7;
  TVector<TypeParam> vec2(2);
  vec2[0] = 1;
  vec2[1] = 2;
  TVector<TypeParam> vec3 = vec1 - vec2;
  EXPECT_EQ(vec3.GetLength(), 2);
  EXPECT_EQ(vec3[0], 4);
  EXPECT_EQ(vec3[1], 5);
}

TYPED_TEST(TVectorTest, can_scalar_multiply_vectors)
{
  TVector<TypeParam> vec1(2);
  vec1[0] = 5;
  vec1[1] = 7;
  TVector<TypeParam> vec2(2);
  vec2[0] = 1;
  vec2[1] = 2;
  TypeParam res = vec1 * vec2;
  EXPECT_EQ(res, 5 * 1 + 7 * 2);
}

TYPED_TEST(TVectorTest, can_sum_vector_with_scalar)
{
  TVector<TypeParam> vec1(2);
  vec1[0] = 1;
  vec1[1] = 2;
  TVector<TypeParam> vec2 = vec1 + 6;
  EXPECT_EQ(vec2.GetLength(), 2);
  EXPECT_EQ(vec2[0], 7);
  EXPECT_EQ(vec2[1], 8);
}

TYPED_TEST(TVectorTest, can_substract_scalar_from_vector)
{
  TVector<TypeParam> vec1(2);
  vec1[0] = 5;
  vec1[1] = 7;
  TVector<TypeParam> vec2 = vec1 - 2;
  EXPECT_EQ(vec2.GetLength(), 2);
  EXPECT_EQ(vec2[0], 3);
  EXPECT_EQ(vec2[1], 5);
}

TYPED_TEST(TVectorTest, can_multiply_vector_on_scalar)
{
  TVector<TypeParam> vec1(2);
  vec1[0] = 5;
  vec1[1] = 7;
  TVector<TypeParam> vec2 = vec1 * 2;
  EXPECT_EQ(vec2[0], 5 * 2);
  EXPECT_EQ(vec2[1], 7 * 2);
}
