CPPFLAGS = -Wall -Wextra -Wpedantic -pedantic-errors -Wno-unused-variable -Wno-unused-parameter -std=c++17 -g -fmax-errors=1 -Wfatal-errors -D_GLIBCXX_DEBUG -fsanitize=undefined -fsanitize=address

CPPCOMP = g++-10

CPPLIBS = wx-config --cxxflags

program: cApp.o cMain.o
	${CPPCOMP} ${CPPFLAGS} cApp.o cMain.o `${CPPLIBS} --libs std` -o program

cApp.o: cApp.cc cApp.h cMain.h
	${CPPCOMP} ${CPPFLAGS} cApp.cc -c `${CPPLIBS}`

cMain.o: cMain.cc cMain.h
	${CPPCOMP} ${CPPFLAGS} cMain.cc -c `${CPPLIBS}`
