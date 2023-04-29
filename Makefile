# Variáveis
CXX=g++
CXXFLAGS=-W -Wall -Werror -Wextra -std=c++11 -O2 -I/utils -g
UTILS=#utils/shellParser.cpp utils/ast.cpp

# Regra padrão
all: build

# Regra de compilação
build: #$(filter-out $@,$(MAKECMDGOALS))
	$(CXX) $(CXXFLAGS) $(target).cpp $(UTILS) -o out

.PHONY: all build %	