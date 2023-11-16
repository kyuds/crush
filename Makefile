CC = g++

crush: src/example.cc src/test_node.cc src/crush/crush.cc src/crush/selector.cc
	$(CC) -o crush src/example.cc src/test_node.cc src/crush/crush.cc src/crush/selector.cc