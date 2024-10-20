#include "PokemonLeauge.h"
BEGIN_GAME
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
      NAME: "Drought",
       ACTION: START  
        POKEBALL ATTACKER ---α
        DAMAGE DEFENDER 20
        SHOW GET_HP(ATTACKER)
        SHOW "Name: " << GET_NAME(DEFENDER)<< "Type: " << GET_TYPE(DEFENDER)
         END 
}
END_GAME

