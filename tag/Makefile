CXX = g++
EXEC = bin/tag
DEBUG = yes

CXXFLAGS = -g -W -Wall `taglib-config --cflags`

all : $(EXEC)

$(EXEC) : obj/main.o obj/tags.o
	$(CXX) $^ -o $(EXEC) `taglib-config --libs`

obj/%.o : %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clear:
	rm obj/* -f
	rm bin/* -f

exe: all
	./$(EXEC)
