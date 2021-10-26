ifndef GTEST_DIR
GTEST_DIR = ../googletest/googletest
endif

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

FLAGS += -isystem $(GTEST_DIR)/include
FLAGS += --std=c++17

all:
	g++ src/*.cpp -o bin/main.o  $(CPPFLAGS) -Wc++2a-extensions -Wno-write-strings
run:
	./bin/main.o
clean:
	rm ./bin/main.o