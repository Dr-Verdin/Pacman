# Variáveis
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I/usr/local/include/opencv4
LDFLAGS = -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgcodecs
TARGET = batata
SRC = Interface.cpp

# Regra padrão
all: $(TARGET)

# Regra para construir o executável
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET)

test:
	make clean
	make
	clear
	./batata
