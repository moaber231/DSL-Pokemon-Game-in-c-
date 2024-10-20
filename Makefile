CXX = g++
CXXFLAGS = -std=c++11  -g

all: CreateAbilities.out CreatePokemonsAndAbilities.out CreatePokemons.out main.out

CreateAbilities.out: CreateAbilities.cpp
	$(CXX) $(CXXFLAGS) CreateAbilities.cpp -o CreateAbilities.out

CreatePokemonsAndAbilities.out: CreatePokemonsAndAbilities.cpp
	$(CXX) $(CXXFLAGS) CreatePokemonsAndAbilities.cpp -o CreatePokemonsAndAbilities.out

CreatePokemons.out: CreatePokemons.cpp
	$(CXX) $(CXXFLAGS) CreatePokemons.cpp -o CreatePokemons.out

main.out: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main.out

clean:
	rm -f *.out

