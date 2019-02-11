//
// Created by richard on 11.02.19.
//

#include "VernamCoder.h"

using namespace std;

std::string VernamCoder::apply(const std::string &message, const std::string &key) {
    string resultMessage;

    auto it = key.begin();
    for(const auto& letter : message) {
        resultMessage += letter ^ (*it);
        (it == key.end() - 1) ? (it = key.begin()) : it++;
    }

    return resultMessage;
}
