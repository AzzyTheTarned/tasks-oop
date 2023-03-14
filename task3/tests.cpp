#include <gtest/gtest.h>
#include <base64.h>
using namespace std;

TEST(Encode, EncodeStr)
{
	    string s ="DEV";
        string out;
	    out = b64encode(s);
	    
	    EXPECT_EQ(out, "REVW");
}
TEST(DEcode, DEcodeStr)
{
        string s ="SQ==";
        string out;
        out = b64decode(s);

        EXPECT_EQ(out, "I");
}
TEST(Encode2, EncodeStr2)
{
        string s ="MAN";
        string out;
        out = b64encode(s);

        EXPECT_EQ(out, "TUFO");
}
TEST(DEcode2, DEcodeStr2)
{
        string s ="TkFOTw==";
        string out;
        out = b64decode(s);

        EXPECT_EQ(out, "NANO");
}
TEST(Encode3, EncodeStr3)
{
        string s ="";
        string out;
        out = b64encode(s);

        EXPECT_EQ(out, "");
}
TEST(DEcode3, DEcodeStr3)
{
        string s ="";
        string out;
        out = b64decode(s);

        EXPECT_EQ(out, "");
}