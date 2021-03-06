#include <vector>
#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "CommonTests.h"

#include "boolinq.h"

using namespace boolinq;

//////////////////////////////////////////////////////////////////////////

TEST(SkipRange, ManyToMany)
{
    int src[] = {1,2,3,4,5,6};
    int ans[] = {1,2,3,4,5,6};

    auto rng = from(src);
    auto dst = rng.skip(0);

    CheckRangeEqArray(dst, ans);
}

TEST(SkipRange, ManyToLess)
{
    int src[] = {1,2,3,4,5,6};
    int ans[] = {4,5,6};

    auto rng = from(src);
    auto dst = rng.skip(3);

    CheckRangeEqArray(dst, ans);
}

TEST(SkipRange, ManyToOne)
{
    int src[] = {1,2,3,4,5,6};
    int ans[] = {6};

    auto rng = from(src);
    auto dst = rng.skip(5);

    CheckRangeEqArray(dst, ans);
}

TEST(SkipRange, ManyToZero)
{
    int src[] = {1,2,3,4,5,6};

    auto rng = from(src);
    auto dst = rng.skip(6);

    EXPECT_THROW(dst.nextObject(), EnumeratorEndException);
}

TEST(SkipRange, ManyToZeroLess)
{
    int src[] = {1,2,3,4,5,6};

    auto rng = from(src);
    auto dst = rng.skip(10);

    EXPECT_THROW(dst.nextObject(), EnumeratorEndException);
}

//////////////////////////////////////////////////////////////////////////

TEST(SkipRange, OneToOne)
{
    int src[] = {5};
    int ans[] = {5};

    auto rng = from(src);
    auto dst = rng.skip(0);

    CheckRangeEqArray(dst, ans);
}

TEST(SkipRange, OneToZero)
{
    int src[] = {5};

    auto rng = from(src);
    auto dst = rng.skip(1);

    EXPECT_THROW(dst.nextObject(), EnumeratorEndException);
}

TEST(SkipRange, OneToZeroLess)
{
    int src[] = {5};

    auto rng = from(src);
    auto dst = rng.skip(2);

    EXPECT_THROW(dst.nextObject(), EnumeratorEndException);
}

TEST(SkipRange, ZeroToZero)
{
    std::vector<int> src;

    auto rng = from(src);
    auto dst = rng.skip(0);

    EXPECT_THROW(rng.nextObject(), EnumeratorEndException);
}

TEST(SkipRange, ZeroToZeroLess)
{
    std::vector<int> src;

    auto rng = from(src);
    auto dst = rng.skip(2);

    EXPECT_THROW(rng.nextObject(), EnumeratorEndException);
}

//////////////////////////////////////////////////////////////////////////
