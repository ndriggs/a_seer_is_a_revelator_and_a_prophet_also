all:
	
	g++ -o executable main.cpp
	
clean:

	rm -f executable
	
exp:

	g++ -o executable experimentalmain.cpp