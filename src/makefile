CXX=g++

BUILD_DIR = ../build/lnx

CFLAGS  = -Wall -std=c++11

SRCS=main.cpp user_interface.cpp chess.cpp Tree.cpp TreeNode.cpp
OBJS=main.o user_interface.o chess.o Tree.o TreeNode.o

all: chess

chess: $(OBJS)
	$(CXX) $(CFLAGS) -o $(BUILD_DIR)/chess_console $(OBJS)

main.o: main.cpp

user_interface.o: user_interface.cpp user_interface.h

chess.o: chess.cpp chess.h

Tree.o: Tree.cpp Tree.h

TreeNode.o: TreeNode.cpp TreeNode.h

clean:
	rm -f $(OBJS)

distclean: clean
	rm -f $(BUILD_DIR)*