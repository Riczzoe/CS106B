CC 		= g++
CFLAGS 	= -Wall
TARGET 	= fraction_test

all: $(TARGET)

$(TARGET): fraction.o test.o
	$(CC) $(CFLAGS) -o $(TARGET) fraction.o test.o

clean:
	rm -f *.o $(TARGET)
