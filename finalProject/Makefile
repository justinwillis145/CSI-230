CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   := proj_lib.o 
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/main.cpp $(LIBRARIES)
	$(CXX) $(CXX_FLAGS) $^ -o $@ 

$(LIBRARIES): $(SRC)/proj_lib.cpp
	$(CXX) $(CXX_FLAGS) -c $(SRC)/proj_lib.cpp -o $(LIBRARIES)

clean:
	-rm $(BIN)/*