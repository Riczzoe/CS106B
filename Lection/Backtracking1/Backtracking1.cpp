#include <iostream>
#include "console.h"
#include "vector.h"
using namespace std;

void listSubsets(string input, string soFar)
{
    if (input.empty()) {
        cout << "{" << soFar << "}" << endl;
    } else {
        char consider = input[0];
        string rest = input.substr(1);
        listSubsets(rest, soFar + consider);  // explore with
        listSubsets(rest, soFar);             // explore without
    }
}


bool partitionable(Vector<int>& rest, int sum1, int sum2) {
    if (rest.size() == 0) {
        return sum1 == sum2;
    } else {
        int n = rest[0];
        rest.remove(0);
        bool answer = partitionable(rest, sum1 + n, sum2)
                   || partitionable(rest, sum1, sum2 + n);
        rest.insert(0, n);
        return answer;
    }
}

bool partitionable(Vector<int> &rest, Vector<int>& v1, Vector<int>& v2) {
    if (rest.size() == 0) {
        int sum1 = 0;
        int sum2 = 0;
        for (int val : v1) {
            sum1 += val;
        }

        for (int val : v2) {
            sum2 += val;
        }

        return sum1 == sum2;
    } else {
        int n = rest[0];
        rest.remove(0);

        v1.add(n);

        bool answer1 = partitionable(rest, v1, v2);
        if (answer1) {
            rest.insert(0, n);
            return true;
        }

        v1.remove(v1.size() - 1);

        v2.add(n);

        bool answer2 = partitionable(rest, v1, v2);
        rest.insert(0, n);

        if (answer2) {
            return true;
        }

        v2.remove(v2.size() - 1);

        return false;
    }

}

struct VectorPair {
    Vector<int> v1;
    Vector<int> v2;
};

void partitionable(Vector<int> &rest, Vector<int>& v1, Vector<int>& v2, Vector<VectorPair>& allSolutions) {
    if (rest.size() == 0) {
        int sum1 = 0;
        int sum2 = 0;
        for (int val : v1) {
            sum1 += val;
        }

        for (int val : v2) {
            sum2 += val;
        }
        if (sum1 == sum2) {
            VectorPair vp;
            vp.v1 = v1;
            vp.v2 = v2;
            allSolutions.add(vp);
        }
    } else {
        int n = rest[0];
        rest.remove(0);

        v1.add(n);

        partitionable(rest, v1, v2, allSolutions);

        v1.remove(v1.size() - 1);

        v2.add(n);

        partitionable(rest, v1, v2, allSolutions);
        rest.insert(0, n);

        v2.remove(v2.size() - 1);
    }

}


bool partitionable(Vector<int>& nums) {
    return partitionable(nums, 0, 0);
}

int main() {
    listSubsets("ABC", "");

    Vector<int> v1 = {1, 1, 2, 3, 5};
    bool result = partitionable(v1);
    cout << "The Vector " << v1 << " is"
         << (result ? "" : "not ") << "partitionable." << endl;

    Vector<int> v2 = {1, 4, 5, 6};
    result = partitionable(v2);
    cout << "The Vector " << v2 << " is "
         << (result ? "" : "not ") << "partitionable." << endl;

    Vector<int> leftSolution;
    Vector<int> rightSolution;
    result = partitionable(v1, leftSolution, rightSolution);
    if (result) {
        cout << v1 << " is partitionable into " << leftSolution << " and " << rightSolution << endl;
    }

    leftSolution.clear();
    rightSolution.clear();
    Vector<int> largeVec = {1, 2, 3, 4, 5, 6, 7, 8};
    result = partitionable(largeVec, leftSolution, rightSolution);
    if (result) {
        cout << largeVec << " is partitionable into " << leftSolution << " and " << rightSolution << endl;
    }


    leftSolution.clear();
    rightSolution.clear();

    Vector<VectorPair> allSolutions;
    partitionable(largeVec, leftSolution, rightSolution, allSolutions);

    for (VectorPair vp : allSolutions) {
       cout << vp.v1 << ", " << vp.v2 << endl;
    }
    return 0;
}
