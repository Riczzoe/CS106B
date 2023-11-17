#pragma once

#include "GUI/MemoryDiagnostics.h"
#include <algorithm>

/* Linked list cells that can be used in the different linked list problems. */
struct Cell {
    int value;
    Cell* next = nullptr;

    TRACK_ALLOCATIONS_OF(Cell);
};

/* Doubly-linked cell. */
struct DoublyLinkedCell {
    int value;
    DoublyLinkedCell* next = nullptr;
    DoublyLinkedCell* prev = nullptr;

    TRACK_ALLOCATIONS_OF(DoublyLinkedCell);
};

/* Cleans up all memory used by the linked list. */
template <typename CellType> void freeList(CellType* head) {
    while (head != nullptr) {
        auto* next = head->next;
        delete head;
        head = next;
    }
}

#include <initializer_list>
#include <iterator>

namespace CellDetail {
    /* Appends the given cell to a linked list. This indirection exists so that we
     * can handle both singly and doubly-linked lists.
     */
    inline void appendTo(Cell* tail, Cell* newCell) {
        tail->next = newCell;
    }

    inline void appendTo(DoublyLinkedCell* tail, DoublyLinkedCell* newCell) {
        tail->next = newCell;
        newCell->prev = tail;
    }

    template <typename CellType>
    CellType* build(std::initializer_list<int> elems) {
        CellType* head = nullptr;
        CellType* tail = nullptr;
        for (int value: elems) {
            CellType* cell = new CellType;
            cell->value = value;

            if (head == nullptr) {
                head = tail = cell;
            } else {
                CellDetail::appendTo(tail, cell);
                tail = cell;
            }
        }
        return head;
    }
}

template <typename... Args>
Cell* makeList(Args... args) {
    return CellDetail::build<Cell>({ args... });
}

template <typename... Args>
DoublyLinkedCell* makeDLList(Args... args) {
    return CellDetail::build<DoublyLinkedCell>({ args... });;
}

template <typename CellType> bool areEqual(CellType* list, std::initializer_list<int> values) {
    for (int elem: values) {
        if (list == nullptr) return false;
        if (list->value != elem) return false;

        list = list->next;
    }
    return list == nullptr;
}
