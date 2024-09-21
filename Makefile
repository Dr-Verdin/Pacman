# Nome do compilador
CXX = g++

# Opções de compilação
CXXFLAGS = -Wall -Wextra -O2

# Nome do executável
TARGET = matrix

# Lista de arquivos fonte
SRCS = Mapa.cpp

# Regras para construir o executável
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Limpar arquivos compilados
clean:
	rm -f $(TARGET)
