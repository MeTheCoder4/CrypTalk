#include <iostream>
#include <string>
#include "VernamCoder.h"

using namespace std;

int main() {
    const string key = "/1cdgf";
    string coded = VernamCoder::apply("hello there, i come from cipherland", key);
    cout << coded << endl;
    string decoded = VernamCoder::apply(coded, key);
    cout << decoded << endl;
    return 0;
}