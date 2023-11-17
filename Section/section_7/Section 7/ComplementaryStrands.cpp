#include "ComplementaryStrands.h"
using namespace std;

void addComplementaryStrand(Nucleotide* dna) {
    (void) dna;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works on an empty list.") {
    /* Should do nothing. */
    addComplementaryStrand(nullptr);
}

PROVIDED_TEST("Works on single-element lists.") {
    auto* dna = new Nucleotide {
        'A', nullptr, nullptr, nullptr
    };
    addComplementaryStrand(dna);

    EXPECT_NOT_EQUAL(dna->across, nullptr);
    EXPECT_EQUAL(dna->across->across, dna);

    EXPECT_EQUAL(dna->across->prev, nullptr);
    EXPECT_EQUAL(dna->across->next, nullptr);
    EXPECT_EQUAL(dna->across->value, 'T');

    delete dna->across;
    delete dna;
}

PROVIDED_TEST("Works on two-element lists.") {
    auto* a = new Nucleotide {
        'A', nullptr, nullptr, nullptr
    };
    auto* c = new Nucleotide {
        'C', nullptr, a, nullptr
    };
    a->next = c;

    addComplementaryStrand(a);

    EXPECT_NOT_EQUAL(a->across, nullptr);
    EXPECT_EQUAL(a->across->across, a);

    EXPECT_NOT_EQUAL(c->across, nullptr);
    EXPECT_EQUAL(c->across->across, c);

    EXPECT_EQUAL(a->across->prev, nullptr);
    EXPECT_EQUAL(a->across->next, c->across);
    EXPECT_EQUAL(a->across->value, 'T');

    EXPECT_EQUAL(c->across->prev, a->across);
    EXPECT_EQUAL(c->across->next, nullptr);
    EXPECT_EQUAL(c->across->value, 'G');

    delete a->across;
    delete a;
    delete c->across;
    delete c;
}

PROVIDED_TEST("Works on three-element lists.") {
    auto* a = new Nucleotide {
        'A', nullptr, nullptr, nullptr
    };
    auto* c = new Nucleotide {
        'C', nullptr, a, nullptr
    };
    a->next = c;
    auto* t = new Nucleotide {
        'T', nullptr, c, nullptr
    };
    c->next = t;

    addComplementaryStrand(a);

    EXPECT_NOT_EQUAL(a->across, nullptr);
    EXPECT_EQUAL(a->across->across, a);

    EXPECT_NOT_EQUAL(c->across, nullptr);
    EXPECT_EQUAL(c->across->across, c);

    EXPECT_NOT_EQUAL(t->across, nullptr);
    EXPECT_EQUAL(t->across->across, t);

    EXPECT_EQUAL(a->across->prev, nullptr);
    EXPECT_EQUAL(a->across->next, c->across);
    EXPECT_EQUAL(a->across->value, 'T');

    EXPECT_EQUAL(c->across->prev, a->across);
    EXPECT_EQUAL(c->across->next, t->across);
    EXPECT_EQUAL(c->across->value, 'G');

    EXPECT_EQUAL(t->across->prev, c->across);
    EXPECT_EQUAL(t->across->next, nullptr);
    EXPECT_EQUAL(t->across->value, 'A');

    delete a->across;
    delete a;
    delete c->across;
    delete c;
    delete t->across;
    delete t;
}
