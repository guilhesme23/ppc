# Variáveis
CXX=g++
CXXFLAGS=-W -Wall -Werror -Wextra -std=c++17 -O2 -I/utils
UTILS=utils/shellParser.cpp

# Regra padrão
all: build

# Regra de compilação
build: #$(filter-out $@,$(MAKECMDGOALS))
	$(CXX) $(CXXFLAGS) $(target).cpp $(UTILS) -o out

.PHONY: all build %	