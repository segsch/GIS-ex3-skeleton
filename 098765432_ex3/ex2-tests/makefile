COMP = g++-10

GOOGLE_LIB = /usr/src/googletest/googletest/gcc-10-build/lib/
GOOGLE_TEST_INCLUDE = /usr/src/googletest/googletest/include/

GIS_PROJECT := ../GIS
NAVIGATION_PROJECT := ../Navigation
SIMULATOR_PROJECT := ../Simulator
SOURCE_FILES := $(notdir $(shell find $(GIS_PROJECT) -name '*.cpp')) $(notdir $(shell find $(NAVIGATION_PROJECT) -name '*.cpp')) NavigationValidator.o tests.cpp main.cpp
OBJS_FILES := $(SOURCE_FILES:%.cpp=%.o)
BIN_DIR := bin
OBJS := $(addprefix $(BIN_DIR)/, $(OBJS_FILES))
EXEC := ex2
CPP_COMP_FLAG := -std=c++20 -Werror -Wall -Wextra -pedantic-errors -DNDEBUG -I$(GOOGLE_TEST_INCLUDE) 
CPP_LINK_FLAG := -L$(GOOGLE_LIB) -lgtest -lgtest_main -pthread

all: $(BIN_DIR) $(EXEC)

$(BIN_DIR):
	mkdir -p $(BIN_DIR) && echo $(OBJS_FILES) 

$(EXEC): $(OBJS)
	$(COMP) $(OBJS) $(CPP_LINK_FLAG) -o $@

$(BIN_DIR)/GIS.o: $(GIS_PROJECT)/GIS.cpp $(GIS_PROJECT)/GIS.h
	$(COMP) $(CPP_COMP_FLAG) -D EX1_EX2 -c $< -o $@

$(BIN_DIR)/Way.o: $(GIS_PROJECT)/Way.cpp $(GIS_PROJECT)/Way.h
	$(COMP) $(CPP_COMP_FLAG) -c $< -o $@

$(BIN_DIR)/Navigation.o: $(NAVIGATION_PROJECT)/Navigation.cpp $(NAVIGATION_PROJECT)/Navigation.h
	$(COMP) $(CPP_COMP_FLAG) -D EX1_EX2 -c $< -o $@

$(BIN_DIR)/Routes.o: $(NAVIGATION_PROJECT)/Routes.cpp $(NAVIGATION_PROJECT)/Routes.h
	$(COMP) $(CPP_COMP_FLAG) -c $< -o $@

$(BIN_DIR)/Route.o: $(NAVIGATION_PROJECT)/Route.cpp $(NAVIGATION_PROJECT)/Route.h
	$(COMP) $(CPP_COMP_FLAG) -c $< -o $@

$(BIN_DIR)/NavigationValidator.o: $(SIMULATOR_PROJECT)/NavigationValidator.cpp $(SIMULATOR_PROJECT)/NavigationValidator.h
	$(COMP) $(CPP_COMP_FLAG) -c $< -o $@

$(BIN_DIR)/tests.o: tests.cpp mocks.h $(GIS_PROJECT)/GIS.h
	$(COMP) $(CPP_COMP_FLAG) -c $< -o $@

$(BIN_DIR)/main.o: main.cpp
	$(COMP) $(CPP_COMP_FLAG) -c $< -o $@

clean:
	rm -rf $(BIN_DIR) $(EXEC)
