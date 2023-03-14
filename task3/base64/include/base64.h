#import <string>
using namespace std;

const string b64encode(const void* data, const size_t &len);

const string b64decode(const void* data, const size_t &len);

string b64encode(const string& str);

string b64decode(const string& str64);