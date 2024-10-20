#include "PokemonLeauge.h"
BEGIN_GAME
CREATE POKEMON { NAME: "Squirtle", TYPE: "Water", HP: 100 }
CREATE POKEMON { NAME: "Pikachu", TYPE: "Electric", HP: 120 }

CREATE POKEMONS [ POKEMON{"Charizard",  "Fire",120 },
 POKEMON{"Ho Oh",  "Grass", 85 }
 ]
 
CREATE ABILITY { 
            NAME: "Electric_Shock", 
            ACTION: START 
                  IF GET_HP(ATTACKER) < 30   DO 
                        DAMAGE ATTACKER 25 
                  ELSE 
                        DAMAGE ATTACKER 15 
                  END
                  
            END 
}
 CREATE ABILITY {
      NAME: "Solar_Power",
      ACTION : START 
        DAMAGE DEFENDER 30 
        POKEBALL ATTACKER _
       END
 }
 CREATE ABILITY {
      NAME: "Or",
      ACTION : START 
        IF OR ( GET_TYPE(DEFENDER) == "Fire",
            NOT (GET_TYPE(ATTACKER) == "Electric"),
            GET_HP(DEFENDER) <= 20 )
             DO DAMAGE DEFENDER 20
       END
       END
 }
 CREATE ABILITY {
      NAME: "And",
      ACTION : START 
        IF AND (GET_HP(DEFENDER) > 30, GET_HP(DEFENDER) < 70) 
             DO DAMAGE DEFENDER 20
       END
       END
 }
 CREATE ABILITY { 
      NAME: "Drought",
       ACTION: START  
        POKEBALL ATTACKER ---α
        DAMAGE DEFENDER 20
        SHOW GET_HP(ATTACKER)
        SHOW "Name: " << GET_NAME(DEFENDER)<< "Type: " << GET_TYPE(DEFENDER)
         END 
}

 CREATE ABILITIES [
       ABILITY { 
            NAME: "Tough_Claws", 
            ACTION: START 
                  IF GET_HP (ATTACKER) < 30 DO 
                        HEAL ATTACKER 25 
                   ELSE 
                        HEAL ATTACKER 15
                   END 
                   
            END 
            }
            , ABILITY { 
                  NAME: "Blaze", 
                  ACTION: START 
                  DAMAGE DEFENDER 22 
                  END 
            }
 ]
CREATE ABILITY {
      NAME: "Solar_Power1",
      ACTION: START
            FOR 5 ROUNDS DO
                  DAMAGE DEFENDER 8
            END
      END
}
CREATE ABILITY {
      NAME: "Small",
      ACTION: START
                  DAMAGE DEFENDER 8     
      END
}
CREATE ABILITY {
      NAME: "After",
      ACTION   : START
            AFTER 2 ROUNDS DO
                  DAMAGE DEFENDER 20
            END 
      END
}
 DEAR "Pikachu" LEARN[
      ABILITY_NAME(Solar_Power)
      ABILITY_NAME(And)
      ABILITY_NAME(Or)
      ABILITY_NAME(After)
      ABILITY_NAME(Solar_Power1)
      ABILITY_NAME(Blaze) 
      ABILITY_NAME(Tough_Claws) 
      ABILITY_NAME(Small)
      ABILITY_NAME(Drought)
 ]
DEAR "Squirtle" LEARN[
      ABILITY_NAME(Solar_Power)
      ABILITY_NAME(Blaze) 
      ABILITY_NAME(And)
      ABILITY_NAME(Or)
       ABILITY_NAME(After)
       ABILITY_NAME(Solar_Power1)
      ABILITY_NAME(Tough_Claws) 
      ABILITY_NAME(Small)
      ABILITY_NAME(Drought)
 ]
 DEAR "Ho Oh" LEARN[
      ABILITY_NAME(Solar_Power)
       ABILITY_NAME(After)
ABILITY_NAME(And)
      ABILITY_NAME(Or)
      ABILITY_NAME(Blaze) 
       ABILITY_NAME(Solar_Power1)
      ABILITY_NAME(Tough_Claws) 
      ABILITY_NAME(Small)
      ABILITY_NAME(Drought)
 ]
  DEAR "Charizard" LEARN[
      ABILITY_NAME(Solar_Power)
       ABILITY_NAME(After)
ABILITY_NAME(And)
      ABILITY_NAME(Or)
      ABILITY_NAME(Blaze) 
      ABILITY_NAME(Solar_Power1)
      ABILITY_NAME(Small)
      ABILITY_NAME(Tough_Claws) 
      ABILITY_NAME(Drought)
 ]
DUEL

END_GAME
