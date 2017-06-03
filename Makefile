# Created on 2017-06-03
# Author: Binbin Zhang

CXX = g++
CC = cc
CXXFLAGS = -g -I . -D WEBRTC_POSIX

SRC = $(wildcard webrtc/*/*/*.c)
OBJ = $(patsubst %.c, build/%.o, $(SRC)) build/vad.o
TEST_BIN = test/apply-vad

all: $(OBJ)

lib: lib/vad.a

test: $(TEST_BIN)

lib/vad.a: $(OBJ)
	@mkdir -p $(@D)
	ar -rcu $@ $(OBJ)

build/webrtc/%.o: webrtc/%.c
	@mkdir -p $(@D)
	$(CC) $(CXXFLAGS) -MM -MT build/webrtc/$*.o $< > build/webrtc/$*.d
	$(CC) $(CXXFLAGS) -c $< -o $@

build/vad.o: vad.cc
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -MM -MT build/vad.o $< > build/vad.d
	$(CXX) $(CXXFLAGS) -c $< -o $@

test/apply-vad: test/apply-vad.cc lib/vad.a
	$(CXX) $(CXXFLAGS) $^ -o $@

-include build/*.d
-include build/*/*/*/*.d

.PHONY: all clean

clean:
	rm -rf build; rm -rf lib;

