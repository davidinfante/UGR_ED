SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

all: $(BIN)/test_refranes $(BIN)/adivina $(BIN)/estudio_prefijo
#$(BIN)/test_refranes_hash

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/test_refranes: $(OBJ)/test_refranes.o $(OBJ)/refranes.o
	$(CXX) -o $(BIN)/test_refranes $(OBJ)/refranes.o $(OBJ)/test_refranes.o

$(OBJ)/refranes.o: $(SRC)/refranes.cpp $(INC)/refranes.h $(INC)/ArbolGeneral.h
	$(CXX) $(CPPFLAGS)  $(SRC)/refranes.cpp -o $(OBJ)/refranes.o
$(OBJ)/test_refranes.o: $(SRC)/test_refranes.cpp $(INC)/refranes.h
	$(CXX) $(CPPFLAGS)  $(SRC)/test_refranes.cpp -o $(OBJ)/test_refranes.o

# $(OBJ)/refranes_hash.o: $(SRC)/refranes_hash.cpp $(INC)/refranes_hash.h
#	$(CXX) $(CPPFLAGS)  $(SRC)/refranes_hash.cpp -o $(OBJ)/refranes_hash.o

# $(BIN)/test_refranes_hash: $(OBJ)/test_refranes.o $(OBJ)/refranes_hash.o
#	$(CXX) -o $(BIN)/test_refranes_hash $(OBJ)/refranes_hash.o $(OBJ)/test_refranes.o

$(BIN)/adivina: $(OBJ)/adivina.o $(OBJ)/refranes.o
	$(CXX) -o $(BIN)/adivina $(OBJ)/adivina.o $(OBJ)/refranes.o

$(OBJ)/adivina.o: $(SRC)/adivina.cpp $(INC)/refranes.h
	$(CXX) $(CPPFLAGS)  $(SRC)/adivina.cpp -o $(OBJ)/adivina.o

$(BIN)/estudio_prefijo: $(OBJ)/estudio_prefijo.o $(OBJ)/refranes.o
	$(CXX) -o $(BIN)/estudio_prefijo $(OBJ)/refranes.o $(OBJ)/estudio_prefijo.o

$(OBJ)/refranes.o: $(SRC)/refranes.cpp $(INC)/refranes.h $(INC)/ArbolGeneral.h
	$(CXX) $(CPPFLAGS)  $(SRC)/refranes.cpp -o $(OBJ)/refranes.o

$(OBJ)/estudio_prefijo.o: $(SRC)/estudio_prefijo.cpp $(INC)/refranes.h
	$(CXX) $(CPPFLAGS)  $(SRC)/estudio_prefijo.cpp -o $(OBJ)/estudio_prefijo.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
