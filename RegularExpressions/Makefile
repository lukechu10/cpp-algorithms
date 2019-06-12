SRC_DIR := ./
OBJ_DIR := ./Build
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS :=
CPPFLAGS := --std=c++17
CXXFLAGS := -Wall

main.out: $(OBJ_FILES)
	g++ $(LDFLAGS) -o $(OBJ_DIR)/$@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	rm Build/*.o | rm *.out

run:
	make main.out >&-
	./Build/main.out