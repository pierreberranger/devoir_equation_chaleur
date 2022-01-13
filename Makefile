CXX=g++
CXXFLAGS=-Wall -ggdb -Iinclude
AR=/usr/bin/ar -r 

code := $(wildcard code/*.cpp)
obj := $(subst code, build, $(code:.cpp=.o))


.PHONY: directories

all: directories libeqchaleur.a solve 
	@echo $(obj)

solve: main.cpp libeqchaleur.a
	$(CXX) $(CXXFLAGS) $^ -o $@ 

libeqchaleur.a: ${obj}
	${AR} $@ $^

build/%.o: code/%.cpp includes/%.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

directories: build
build:
	mkdir -p $@


clean: 
	rm solve
	rm libeqchaleur.a
	rm -r build


