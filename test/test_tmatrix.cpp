#include "TTrBMatrix.h"
#include "TTrTMatrix.h"
#include "TSqMatrix.h"

#include <gtest.h>

using testing::Types;

template <class T>
class TMatrixTest : public testing::Test {};
typedef Types<int, double> Implementations;

TYPED_TEST_CASE(TMatrixTest, Implementations);


TYPED_TEST(TMatrixTest, can_create_trbmatrix_with_positive_length)
{
  ASSERT_NO_THROW(TTrBMatrix<TypeParam> mat(3));
}
TYPED_TEST(TMatrixTest, can_create_trtmatrix_with_positive_length)
{
  ASSERT_NO_THROW(TTrTMatrix<TypeParam> mat(3));
}
TYPED_TEST(TMatrixTest, can_create_sqmatrix_with_positive_length)
{
    ASSERT_NO_THROW(TSqMatrix<TypeParam> mat(3));
}


TYPED_TEST(TMatrixTest, can_not_create_trbmatrix_with_negative_length)
{
  ASSERT_ANY_THROW(TTrBMatrix<TypeParam> mat(-1));
}
TYPED_TEST(TMatrixTest, can_not_create_trtmatrix_with_negative_length)
{
  ASSERT_ANY_THROW(TTrTMatrix<TypeParam> mat(-1));
}
TYPED_TEST(TMatrixTest, can_not_create_sqmatrix_with_negative_length)
{
    ASSERT_ANY_THROW(TSqMatrix<TypeParam> mat(-1));
}


TYPED_TEST(TMatrixTest, can_get_trbmatrix_size)
{
  TTrBMatrix<TypeParam> mat(3);

  EXPECT_EQ(3, mat.GetLength());
}
TYPED_TEST(TMatrixTest, can_get_trtmatrix_size)
{
  TTrTMatrix<TypeParam> mat(3);

  EXPECT_EQ(3, mat.GetLength());
}
TYPED_TEST(TMatrixTest, can_get_sqmatrix_size)
{
    TSqMatrix<TypeParam> mat(3);

    EXPECT_EQ(3, mat.GetLength());
}

TYPED_TEST(TMatrixTest, can_compare_trbmatrix_equivalence)
{
  TTrBMatrix<TypeParam> mat1(2);
  TTrBMatrix<TypeParam> mat2(2);
  mat1[0][0] = 0;
  mat1[1][0] = 1;
  mat1[1][1] = 2;
  mat2[0][0] = 0;
  mat2[1][0] = 1;
  mat2[1][1] = 2;
  EXPECT_EQ(mat1 == mat2, true);
}
TYPED_TEST(TMatrixTest, can_compare_trtmatrix_equivalence)
{
  TTrTMatrix<TypeParam> mat1(2);
  TTrTMatrix<TypeParam> mat2(2);
  mat1[0][0] = 0;
  mat1[1][0] = 1;
  mat1[1][1] = 2;
  mat2[0][0] = 0;
  mat2[1][0] = 1;
  mat2[1][1] = 2;
  EXPECT_EQ(mat1 == mat2, true);
}
TYPED_TEST(TMatrixTest, can_compare_sqmatrix_equivalence)
{
    TSqMatrix<TypeParam> mat1(2);
    TSqMatrix<TypeParam> mat2(2);
    mat1[0][0] = 0;
    mat1[1][0] = 1;
    mat1[1][1] = 2;
    mat2[0][0] = 0;
    mat2[1][0] = 1;
    mat2[1][1] = 2;
    EXPECT_EQ(mat1 == mat2, true);
}

TYPED_TEST(TMatrixTest, can_compare_trbmatrix_nonequivalence)
{
  TTrBMatrix<TypeParam> mat1(2);
  TTrBMatrix<TypeParam> mat2(2);
  mat1[0][0] = 0;
  mat1[1][0] = 1;
  mat1[1][1] = 2;
  mat2[0][0] = 1;
  mat2[1][0] = 1;
  mat2[1][1] = 2;
  EXPECT_EQ(mat1 != mat2, true);
}
TYPED_TEST(TMatrixTest, can_compare_trtmatrix_nonequivalence)
{
  TTrTMatrix<TypeParam> mat1(2);
  TTrTMatrix<TypeParam> mat2(2);
  mat1[0][0] = 0;
  mat1[1][0] = 1;
  mat1[1][1] = 2;
  mat2[0][0] = 1;
  mat2[1][0] = 1;
  mat2[1][1] = 2;
  EXPECT_EQ(mat1 != mat2, true);
}
TYPED_TEST(TMatrixTest, can_compare_sqmatrix_nonequivalence)
{
    TSqMatrix<TypeParam> mat1(2);
    TSqMatrix<TypeParam> mat2(2);
    mat1[0][0] = 0;
    mat1[1][0] = 1;
    mat1[1][1] = 2;
    mat2[0][0] = 1;
    mat2[1][0] = 1;
    mat2[1][1] = 2;
    EXPECT_EQ(mat1 != mat2, true);
}

TYPED_TEST(TMatrixTest, can_not_compare_empty_trbmatrix_equivalence)
{
  TTrBMatrix<TypeParam> mat1;
  TTrBMatrix<TypeParam> mat2;
  ASSERT_ANY_THROW(mat1 == mat2);
}
TYPED_TEST(TMatrixTest, can_not_compare_empty_trtmatrix_equivalence)
{
  TTrTMatrix<TypeParam> mat1;
  TTrTMatrix<TypeParam> mat2;
  ASSERT_ANY_THROW(mat1 == mat2);
}
TYPED_TEST(TMatrixTest, can_not_compare_empty_sqmatrix_equivalence)
{
    TSqMatrix<TypeParam> mat1;
    TSqMatrix<TypeParam> mat2;
    ASSERT_ANY_THROW(mat1 == mat2);
}

TYPED_TEST(TMatrixTest, can_not_compare_empty_trbmatrix_nonequivalence)
{
  TTrBMatrix<TypeParam> mat1;
  TTrBMatrix<TypeParam> mat2;
  ASSERT_ANY_THROW(mat1 != mat2);
}
TYPED_TEST(TMatrixTest, can_not_compare_empty_trtmatrix_nonequivalence)
{
  TTrTMatrix<TypeParam> mat1;
  TTrTMatrix<TypeParam> mat2;
  ASSERT_ANY_THROW(mat1 != mat2);
}
TYPED_TEST(TMatrixTest, can_not_compare_empty_sqmatrix_nonequivalence)
{
    TSqMatrix<TypeParam> mat1;
    TSqMatrix<TypeParam> mat2;
    ASSERT_ANY_THROW(mat1 != mat2);
}

TYPED_TEST(TMatrixTest, can_sum_trbmatrixes)
{
  TTrBMatrix<TypeParam> mat1(2);
  TTrBMatrix<TypeParam> mat2(2);
  mat1[0][0] = 0;
  mat1[1][0] = 1;
  mat1[1][1] = 2;
  mat2[0][0] = 1;
  mat2[1][0] = 1;
  mat2[1][1] = 2;
  TTrBMatrix<TypeParam> mat3 = mat1 + mat2;
  EXPECT_EQ(mat3[0][0], 1);
  EXPECT_EQ(mat3[1][0], 2);
  EXPECT_EQ(mat3[1][1], 4);
}
TYPED_TEST(TMatrixTest, can_sum_sqmatrixes)
{
    TSqMatrix<TypeParam> mat1(2);
    TSqMatrix<TypeParam> mat2(2);
    mat1[0][0] = 0;
    mat1[1][0] = 1;
    mat1[1][1] = 2;
    mat2[0][0] = 1;
    mat2[1][0] = 1;
    mat2[1][1] = 2;
    TSqMatrix<TypeParam> mat3 = mat1 + mat2;
    EXPECT_EQ(mat3[0][0], 1);
    EXPECT_EQ(mat3[1][0], 2);
    EXPECT_EQ(mat3[1][1], 4);
}

TYPED_TEST(TMatrixTest, can_substract_trbmatrixes)
{
  TTrBMatrix<TypeParam> mat1(2);
  TTrBMatrix<TypeParam> mat2(2);
  mat1[0][0] = 3;
  mat1[1][0] = 2;
  mat1[1][1] = 6;
  mat2[0][0] = 1;
  mat2[1][0] = 1;
  mat2[1][1] = 2;
  TTrBMatrix<TypeParam> mat3 = mat1 - mat2;
  EXPECT_EQ(mat3[0][0], 2);
  EXPECT_EQ(mat3[1][0], 1);
  EXPECT_EQ(mat3[1][1], 4);
}

TYPED_TEST(TMatrixTest, can_not_sum_empty_trbmatrixes)
{
  TTrBMatrix<TypeParam> mat1;
  TTrBMatrix<TypeParam> mat2;
  ASSERT_ANY_THROW(TTrBMatrix<TypeParam> mat3 = mat1 + mat2);
}
TYPED_TEST(TMatrixTest, can_not_sum_empty_trtmatrixes)
{
  TTrTMatrix<TypeParam> mat1;
  TTrTMatrix<TypeParam> mat2;
  ASSERT_ANY_THROW(TTrTMatrix<TypeParam> mat3 = mat1 + mat2);
}
TYPED_TEST(TMatrixTest, can_not_sum_empty_sqmatrixes)
{
    TSqMatrix<TypeParam> mat1;
    TSqMatrix<TypeParam> mat2;
    ASSERT_ANY_THROW(TSqMatrix<TypeParam> mat3 = mat1 + mat2);
}

TYPED_TEST(TMatrixTest, can_not_substract_empty_trbmatrixes)
{
  TTrBMatrix<TypeParam> mat1;
  TTrBMatrix<TypeParam> mat2;
  ASSERT_ANY_THROW(TTrBMatrix<TypeParam> mat3 = mat1 - mat2);
}
TYPED_TEST(TMatrixTest, can_not_substract_empty_trtmatrixes)
{
  TTrTMatrix<TypeParam> mat1;
  TTrTMatrix<TypeParam> mat2;
  ASSERT_ANY_THROW(TTrTMatrix<TypeParam> mat3 = mat1 - mat2);
}
TYPED_TEST(TMatrixTest, can_not_substract_empty_sqmatrixes)
{
    TSqMatrix<TypeParam> mat1;
    TSqMatrix<TypeParam> mat2;
    ASSERT_ANY_THROW(TSqMatrix<TypeParam> mat3 = mat1 - mat2);
}

TYPED_TEST(TMatrixTest, can_not_sum_trbmatrixes_differrent_sizes)
{
  TTrBMatrix<TypeParam> mat1(1);
  TTrBMatrix<TypeParam> mat2(2);
  ASSERT_ANY_THROW(TTrBMatrix<TypeParam> mat3 = mat1 + mat2);
}
TYPED_TEST(TMatrixTest, can_not_sum_trtmatrixes_differrent_sizes)
{
  TTrTMatrix<TypeParam> mat1(1);
  TTrTMatrix<TypeParam> mat2(2);
  ASSERT_ANY_THROW(TTrTMatrix<TypeParam> mat3 = mat1 + mat2);
}
TYPED_TEST(TMatrixTest, can_not_sum_sqmatrixes_differrent_sizes)
{
    TSqMatrix<TypeParam> mat1(1);
    TSqMatrix<TypeParam> mat2(2);
    ASSERT_ANY_THROW(TSqMatrix<TypeParam> mat3 = mat1 + mat2);
}

TYPED_TEST(TMatrixTest, can_not_substract_trbmatrixes_differrent_sizes)
{
  TTrBMatrix<TypeParam> mat1(1);
  TTrBMatrix<TypeParam> mat2(2);
  ASSERT_ANY_THROW(TTrBMatrix<TypeParam> mat3 = mat1 - mat2);
}
TYPED_TEST(TMatrixTest, can_not_substract_trtmatrixes_differrent_sizes)
{
  TTrTMatrix<TypeParam> mat1(1);
  TTrTMatrix<TypeParam> mat2(2);
  ASSERT_ANY_THROW(TTrTMatrix<TypeParam> mat3 = mat1 - mat2);
}
TYPED_TEST(TMatrixTest, can_not_substract_sqmatrixes_differrent_sizes)
{
    TSqMatrix<TypeParam> mat1(1);
    TSqMatrix<TypeParam> mat2(2);
    ASSERT_ANY_THROW(TSqMatrix<TypeParam> mat3 = mat1 - mat2);
}

TYPED_TEST(TMatrixTest, can_mult_trbmatrixes)
{
  TTrBMatrix<TypeParam> mat1(2);
  TTrBMatrix<TypeParam> mat2(2);
  mat1[0][0] = 4;
  mat1[1][0] = 5;
  mat1[1][1] = 6;
  mat2[0][0] = 1;
  mat2[1][0] = 2;
  mat2[1][1] = 3;
  TTrBMatrix<TypeParam> mat3 = mat1 * mat2;
  EXPECT_EQ(mat3[0][0], 4);
  EXPECT_EQ(mat3[1][0], 23);
  EXPECT_EQ(mat3[1][1], 18);
}
TYPED_TEST(TMatrixTest, can_mult_trtmatrixes)
{
  TTrTMatrix<TypeParam> mat1(2);
  TTrTMatrix<TypeParam> mat2(2);
  mat1[0][0] = 4;
  mat1[1][0] = 5;
  mat1[1][1] = 6;
  mat2[0][0] = 1;
  mat2[1][0] = 2;
  mat2[1][1] = 3;
  TTrTMatrix<TypeParam> mat3 = mat1 * mat2;
  EXPECT_EQ(mat3[0][0], 4);
  EXPECT_EQ(mat3[1][0], 10);
  EXPECT_EQ(mat3[1][1], 0);
}
TYPED_TEST(TMatrixTest, can_mult_sqmatrixes)
{
    TSqMatrix<TypeParam> mat1(2);
    TSqMatrix<TypeParam> mat2(2);
    mat1[0][0] = 4;
    mat1[1][0] = 5;
    mat1[1][1] = 6;
    mat2[0][0] = 1;
    mat2[1][0] = 2;
    mat2[1][1] = 3;
    TSqMatrix<TypeParam> mat3 = mat1 * mat2;
    EXPECT_EQ(mat3[0][0], 4);
    EXPECT_EQ(mat3[1][0], 23);
    EXPECT_EQ(mat3[1][1], 18);
}

TYPED_TEST(TMatrixTest, can_mult_trbmatrix_on_vector)
{
  TTrBMatrix<TypeParam> mat(2);
  TVector<TypeParam> vec1(2);
  mat[0][0] = 1;
  mat[1][0] = 2;
  mat[1][1] = 3;
  vec1[0] = 1;
  vec1[1] = 2;
  TVector<TypeParam> vec2 = mat * vec1;
  EXPECT_EQ(vec2[0], 5);
  EXPECT_EQ(vec2[1], 6);
}
TYPED_TEST(TMatrixTest, can_mult_trtmatrix_on_vector)
{
  TTrTMatrix<TypeParam> mat(2);
  TVector<TypeParam> vec1(2);
  mat[0][0] = 1;
  mat[1][0] = 2;
  mat[1][1] = 3;
  vec1[0] = 1;
  vec1[1] = 2;
  TVector<TypeParam> vec2 = mat * vec1;
  EXPECT_EQ(vec2[0], 5);
  EXPECT_EQ(vec2[1], 6);
}
TYPED_TEST(TMatrixTest, can_mult_sqmatrix_on_vector)
{
    TSqMatrix<TypeParam> mat(2);
    TVector<TypeParam> vec1(2);
    mat[0][0] = 1;
    mat[1][0] = 2;
    mat[1][1] = 3;
    vec1[0] = 1;
    vec1[1] = 2;
    TVector<TypeParam> vec2 = mat * vec1;
    EXPECT_EQ(vec2[0], 5);
    EXPECT_EQ(vec2[1], 6);
}

TYPED_TEST(TMatrixTest, can_mult_trbmatrix_on_scalar)
{
  TTrBMatrix<TypeParam> mat(2);
  mat[0][0] = 1;
  mat[1][0] = 2;
  mat[1][1] = 3;
  TTrBMatrix<TypeParam> res = mat * 2;
  EXPECT_EQ(res[0][0], 2);
  EXPECT_EQ(res[1][0], 4);
  EXPECT_EQ(res[1][1], 6);
}
TYPED_TEST(TMatrixTest, can_mult_sqmatrix_on_scalar)
{
    TSqMatrix<TypeParam> mat(2);
    mat[0][0] = 1;
    mat[1][0] = 2;
    mat[1][1] = 3;
    TSqMatrix<TypeParam> res = mat * 2;
    EXPECT_EQ(res[0][0], 2);
    EXPECT_EQ(res[1][0], 4);
    EXPECT_EQ(res[1][1], 6);
}
