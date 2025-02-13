CC = clang++
CFLAGS = -Wall -Werror -std=c++17 -Iinclude

# Google Test.
GTEST_LIB = /usr/local/lib/gtest
GTEST_INCLUDE = /usr/local/include/gtest
GTEST_FLAGS = -isystem $(GTEST_INCLUDE) -pthread

TARGET = build/bin/main
TEST_TARGET = build/bin/test

SRCS = $(wildcard src/BST/*.cpp)
OBJS = $(patsubst src/BST/%.cpp, build/obj/%.o, $(SRCS))

TEST_SRCS = $(wildcard src/unittest/test*.cpp)
TEST_OBJS = $(patsubst src/unittest/%.cpp, build/obj/%.o, $(TEST_SRCS))

build/obj/%.o: src/**/%.cpp
build/obj/main.o: src/main.cpp
	@mkdir -p build/obj
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS) build/obj/main.o
	@mkdir -p build/bin
	$(CC) $(CFLAGS) -o $@ $^

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	@mkdir -p build/bin
	$(CC) $(CFLAGS) $(GTEST_FLAGS) -o $@ $(OBJS) $(TEST_OBJS) $(GTEST_LIB)/libgtest.a $(GTEST_LIB)/libgtest_main.a

all:
run: $(TARGET)
	./$(TARGET)

clean:
	@rm -rf build/*

.PHONY: all run clean test
