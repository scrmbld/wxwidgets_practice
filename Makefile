program: cApp.o cMain.o
	g++ cApp.o cMain.o `wx-config --cxxflags --libs std` -o program

cApp.o: cApp.cc cApp.h cMain.h
	g++ cApp.cc -c `wx-config --cxxflags`

cMain.o: cMain.cc cMain.h
	g++ cMain.cc -c `wx-config --cxxflags`
