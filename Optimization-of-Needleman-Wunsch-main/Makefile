# indicate how the object files are to be created
CC         := g++
CFLAGS     := -g -O3 -fopenmp
# CFLAGS     := -g -O3 
OBJECT_FILES := driver.o helper.o needleman.o needlemanoptv1.o needlemanoptv2.o needlemanoptv3.o needlemanoptv4.o needlemanoptv5.o needlemanoptv6.o needlemanoptv7.o

driver: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o driver

helper: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o helper

needleman: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o needleman

needlemanoptv1: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o needlemanoptv1

needlemanoptv2: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o needlemanoptv2

needlemanoptv3: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o needlemanoptv3

needlemanoptv4: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o needlemanoptv4

needlemanoptv5: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o needlemanoptv5

needlemanoptv6: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o needlemanoptv6

needlemanoptv7: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o needlemanoptv7

driver.o : driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp

helper.o : helper.cpp
	$(CC) $(CFLAGS) -c helper.cpp

needleman.o : needleman.cpp
	$(CC) $(CFLAGS) -c needleman.cpp

needlemanoptv1.o : needlemanoptv1.cpp
	$(CC) $(CFLAGS) -c needlemanoptv1.cpp

needlemanoptv2.o : needlemanoptv2.cpp
	$(CC) $(CFLAGS) -c needlemanoptv2.cpp

needlemanoptv3.o : needlemanoptv3.cpp
	$(CC) $(CFLAGS) -c needlemanoptv3.cpp

needlemanoptv4.o : needlemanoptv4.cpp
	$(CC) $(CFLAGS) -c needlemanoptv4.cpp	

needlemanoptv5.o : needlemanoptv5.cpp
	$(CC) $(CFLAGS) -c needlemanoptv5.cpp

needlemanoptv6.o : needlemanoptv6.cpp
	$(CC) $(CFLAGS) -c needlemanoptv6.cpp

needlemanoptv7.o : needlemanoptv7.cpp
	$(CC) $(CFLAGS) -c needlemanoptv7.cpp

clean:
	rm *.o 
