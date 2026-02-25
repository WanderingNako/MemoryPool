all:
	g++ MemoryPool.cc CTest.cc -o CTest

clean:
	rm -f CTest

.PHONY: all clean