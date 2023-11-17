#pragma once

#include "Cells.h"
#include "GUI/MemoryDiagnostics.h"

struct Nucleotide {
    char value;         // 'A', 'C', 'G', or 'T'
    Nucleotide* next;   // To the right
    Nucleotide* prev;   // To the left
    Nucleotide* across; // Vertically, to the other strand.

    TRACK_ALLOCATIONS_OF(Nucleotide);
};

void addComplementaryStrand(Nucleotide* dna);
