cc 				= gcc
CFLAGS 			= -std=gnu99 -Wall -pedantic 
DBGFLAGS    	= -std=gnu99 -Wall -pedantic -ggdb3 -DDEBUG

SORT_SRCS 		= basic_sort.c heap_sort_pq.c heap_sort.c quick_sort.c radix_sort.c sort_test.c

ALL_SORT_SRCS 	= $(SORT_SRCS) all_sort_test.c
ALL_SORT_OBJS 	= $(ALL_SORT_SRCS:.c=.o)
ALL_DBG_OBJS 	= $(ALL_SORT_SRCS:.c=.dbg.o)

.PHONY: all debug clean

all: all_sort_test

all_sort_test: $(ALL_SORT_OBJS)
	$(cc) $(CFLAGS) -o $@ $^

debug: all_sort_test_dbg

all_sort_test_dbg: $(ALL_DBG_OBJS)
	$(cc) $(DBGFLAGS) -o $@ $^

%.dbg.o: %.c
	$(cc) $(DBGFLAGS) -c $< -o $@

clean:
	rm -f *.o *.dbg.o all_sort_test all_sort_test_dbg 

valgrind: all_sort_test
	valgrind --leak-check=full --show-leak-kinds=all ./all_sort_test
