LIB_SOURCE_FILES := $(filter-out Main.cpp, $(wildcard *.cpp))

build-static-lib: $(LIB_SOURCE_FILES)
	g++ -c $(LIB_SOURCE_FILES) 
	ar rvs menu.a *.o

build: Main.cpp menu.a
	g++ Main.cpp menu.a

clean:
	rm -f *.o *.h.gch
	
run:
	./a.exe

all: build-static-lib build clean run