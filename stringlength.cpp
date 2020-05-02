#include "stringlength.h"

using namespace std;

string StringLength::Run(vector<string> _data)
{
    if (_data.empty())
        return "-1";
    else
        return to_string(_data.front().size());
}
