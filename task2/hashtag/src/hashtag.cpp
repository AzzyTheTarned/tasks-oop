#include <hashtag.h>
using namespace std;

string hashtag(string inputLine) {
    if (!inputLine.length()) throw invalid_argument("Input line is too short");
    string hashtag  = "#";
    bool upper = true;
    for (int i = 0; i < inputLine.length(); i++) {
        if (inputLine[i] != ' ') {
           if (upper) {
                if (islower(inputLine[i])) hashtag += toupper(inputLine[i]);
                else hashtag += inputLine[i];
                upper = false;
           }
           else hashtag += inputLine[i];
        }
        else upper = true;
    }
    if (hashtag.length() > 100) throw length_error("Output line is too long");
    else return hashtag;
}