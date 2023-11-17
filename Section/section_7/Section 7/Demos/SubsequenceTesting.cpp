#include "SubsequenceTesting.h"
#include "strlib.h"
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

namespace {
    /* Way to catch the contents of cout and read it back later. */
    class StreamCatcher {
    public:
        StreamCatcher() {
            oldBuf = std::cout.rdbuf(buffer.rdbuf());
        }

        ~StreamCatcher() {
            std::cout.rdbuf(oldBuf);
        }

        string output() const {
            return buffer.str();
        }
    private:
        ostringstream buffer;
        streambuf* oldBuf;
    };
}

bool outputMatchesImpl(function<void()> callback, const Vector<string>& expected) {
    /* Divert cout. */
    StreamCatcher catcher;

    /* Invoke the callback to see what it prints out. */
    callback();
    string output = catcher.output();

    /* Now check if everything matches. */
    size_t index = 0;
    for (string token: expected) {
        /* Find the match. */
        index = output.find(token, index);

        /* Should have been a match. */
        if (index == string::npos) {
            return false;
        }

        /* Match; skip over it. */
        index += token.length();
    }

    return true;
}
