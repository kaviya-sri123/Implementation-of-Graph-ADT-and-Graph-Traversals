a.exe:graph_app.o graph_imp.o
	c++ graph_app.o graph_imp.o -o a.exe
graph_app.o:graph_app.cpp
	c++ -c graph_app.cpp
graph_imp.o:graph_imp.cpp
	c++ -c graph_imp.cpp