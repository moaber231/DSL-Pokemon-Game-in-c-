
# Pokemon DSL Game in C++

## Overview
This project implements a **Domain-Specific Language (DSL)** using C++ for creating and managing 1v1 PokΓ©mon battles. The DSL allows users to define PokΓ©mon, set their abilities, and simulate battle scenarios by writing simple DSL code.

## Compilation & Execution
To compile the project and create the necessary executables, use the provided **Makefile**. The Makefile compiles the following files:
- `CreateAbilities.cpp`
- `CreatePokemonsAndAbilities.cpp`
- `CreatePokemons.cpp`
- `main.cpp`

### Build the Project
To compile the project, simply run the following command in the terminal:
```bash
make
```

### Run the Program
After compilation, you will have the following executables:

- `CreateAbilities.out`
- `CreatePokemonsAndAbilities.out`
- `CreatePokemons.out`
- `main.out`

To run any of these executables, use the following command:
```bash
./<executable_name>
```
For example:
```bash
./main.out
```

### Clean the Project
To clean up the compiled files, run:
```bash
make clean
```

## Language Elements

### PokΓ©mon Definitions
The DSL allows you to create individual PokΓ©mon or multiple PokΓ©mon using the following syntax.

#### Create a Single PokΓ©mon:
```dsl
CREATE POKEMON { 
  NAME: "name", 
  TYPE: "type", 
  HP: health_points 
}
```

#### Create Multiple PokΓ©mon:
```dsl
CREATE POKEMONS [  
  POKEMON { 
    NAME: "name", 
    TYPE: "type", 
    HP: health_points 
  }, 
  POKEMON { 
    NAME: "name", 
    TYPE: "type", 
    HP: health_points 
  } 
]
```

#### Example:
```dsl
CREATE POKEMON { 
   NAME: "Pikachu", 
   TYPE: "Electric", 
   HP: 120 
} 

CREATE POKEMON { 
   NAME: "Squirtle", 
   TYPE: "Water", 
   HP: 100 
}

CREATE POKEMONS [ 
   POKEMON { 
    NAME: "Ho Oh", 
    TYPE: "Fire", 
    HP: 120 
   }, 
   POKEMON { 
    NAME: "Bulbasaur", 
    TYPE: "Grass", 
    HP: 85 
   } 
]
```

### Ability Definition
You can define abilities that PokΓ©mon can use during battles. Abilities specify actions that may include conditional logic such as healing or damaging based on certain conditions.

#### Create a Single Ability:
```dsl
CREATE ABILITY { 
 NAME: "ability_name", 
 ACTION: START  
  ... 
 END 
}
```

#### Create Multiple Abilities:
```dsl
CREATE ABILITIES [  
 ABILITY { 
  NAME: "ability_name", 
  ACTION: START  
   ... 
  END 
 }, 
 ABILITY { 
  NAME: "ability_name", 
  ACTION: START  
   ... 
  END  
 } 
]
```

#### Example:
```dsl
CREATE ABILITY { 
 NAME: "Electric_Shock", 
 ACTION: START 
  IF GET_HP(ATTACKER) < 30 DO 
   HEAL ATTACKER 25 
  ELSE  
   DAMAGE DEFENDER 20 
  END 
 END 
}

CREATE ABILITY { 
 NAME: "Flame_Thrower", 
 ACTION: START 
  DAMAGE DEFENDER 35 
 END 
}

CREATE ABILITIES [ 
 ABILITY { 
  NAME: "Electric_Shock", 
  ACTION: START 
   IF GET_HP(ATTACKER) < 30 DO 
    HEAL ATTACKER 25 
   ELSE  
    HEAL ATTACKER 15 
   END 
  END 
 }, 
 ABILITY { 
  NAME: "Blaze", 
  ACTION: START 
   DAMAGE DEFENDER 22  
  END 
 } 
]
```

### Teaching Abilities to PokΓ©mon
You can assign abilities to PokΓ©mon using the following DSL construct:

```dsl
DEAR "pokemon name" LEARN [ 
 ABILITY_NAME(ability_name) 
 ABILITY_NAME(ability_name) 
]
```

#### Example:
```dsl
DEAR "Pikachu" LEARN [ 
 ABILITY_NAME(Electric_Shock) 
 ABILITY_NAME(Lightning_Rod) 
]

DEAR "Ho Oh" LEARN [ 
 ABILITY_NAME(Solar_Power) 
 ABILITY_NAME(Blaze) 
 ABILITY_NAME(Tough_Claws) 
 ABILITY_NAME(Drought) 
]
```

## Makefile
The project includes a Makefile for automating the compilation process. Below is the content of the Makefile:

```makefile
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
```

## Conclusion
This project demonstrates how a custom DSL can be built in C++ for a PokΓ©mon game. The DSL simplifies the process of creating PokΓ©mon, defining their abilities, and setting up battles by abstracting the underlying game logic. With the provided Makefile, compiling and running the game is straightforward.
