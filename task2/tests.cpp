#include <gtest/gtest.h>
#include <hashtag.h>
using namespace std;

TEST(StackTest, StackPush)
{
    EXPECT_EQ("#ProveMeWrong", hashtag("prove    Me wrong"));
    EXPECT_EQ("#FridayNightFunkin", hashtag("  friday Night funkin"));
    EXPECT_EQ("#TwoPlusTwoIsFour", hashtag("Two plus two Is four         "));
    EXPECT_EQ("#TheEarthIsFlat", hashtag("  the Earth Is  flat   "));
    EXPECT_THROW(hashtag(""), invalid_argument);
    EXPECT_THROW(hashtag("qwesdfghjytresdfghjkliuytrewazx rtyuioplkjhgfazxcvbnmnb vcxsasdfghjkoiuytrewqqwertyuiolkjhgfdsazxcvbnm"), length_error);
}