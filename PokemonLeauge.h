/**
 * @authors Gkogkos Kontstantinos csd4861,Fergadakis Nikolaos csd5027
*/

#include <functional>
#include <iostream>
#include <initializer_list>
#include <vector>
#include <cstdarg>
using namespace std;
class Pokemon;
class Ability;
std::vector<Ability> AbilityList;
std::vector<Pokemon> PokemonList;
std::vector<Ability> AfterAbilityHolder;
class Ability_List;
class Pokemon_List;
string Variables;
/**
 * @class PokemonStatusCalls
 * @brief Used for Pokeball of in and out of it and made with overload to understand the --- operator
*/
class PokemonStatusCalls{
    private:
        string Name="InPok";
    public:
         PokemonStatusCalls(const string& s="InPok") : Name(s) {}
         PokemonStatusCalls operator-() const {
            return PokemonStatusCalls("OutOfPok");
          
          }
         PokemonStatusCalls operator--(int) {
            Name = "OutOfPok";
              return *this;
            }
       PokemonStatusCalls& operator--() {
           Name = "OutOfPok";
            return *this;
         }
         string get_Name()
         {
            return this->Name;
         }
};
PokemonStatusCalls _;
PokemonStatusCalls α;
/**
 * @class Ability 
 * @brief Used for the abilities of pokemon fields name ,and the a function holder used for the Action made 
*/
class Ability
{
    private:
         string name;
         std::vector<Pokemon *> PokemonListA;
         std::function<void()> AbilityAction;
      
    public:
         Ability(string N, std::function<void()> AA) : name(N) ,AbilityAction(AA)
         {
           Variables=N;
          AbilityList.emplace_back(*this);
         }
         void StartAbilityAction()
         {
               AbilityAction();
         }
         std::string get_Name()
         {
          return this->name;
         }
          std::function<void()> get_Abilityf()
          {
            return AbilityAction;
          }
         void set_Pokemon(Pokemon* pa)
         {
                this->PokemonListA.push_back(pa);
         }
};
/**
 * @class AbilityQeue
 * @brief Used for listing the abilities for the ABILITY_LEARN purpose of the DSL , and operation overload of + for unuary and binary for concating the list and retruning the same
*/
class AbilityQeue{
  private:
    vector<Ability> AbilityVector;
  public:
    AbilityQeue& operator+(const AbilityQeue& DiffAbillityVector) {//Binary
      for (auto& a : DiffAbillityVector.GetAb()) {
           AbilityVector.push_back(a);
        }
        return *this; 
    }
   AbilityQeue operator+()  { //Unuary
        AbilityQeue Q = *this;
        return Q;  
    }
    vector<Ability>& GetAb() {
        return AbilityVector;
    }
    const vector<Ability>& GetAb() const {
        return AbilityVector;
    }
     void PrintAbilities() {
        if (AbilityVector.empty()) {
            cout << "No abilities in the queue." << endl;
            return;
        }
        
        cout << "Abilities in the Queue:" << endl;
        for ( auto& ability : AbilityVector) {
            cout << ability.get_Name() << endl;
        }
    }
};
/**
 * @class Ability_List
 * @brief class made in purpose of the CREATE ABILITIES[] and ABILITY_LEARN,holding the abilities of a pokemon and overloaded [] to understand lists and initiliazer lists!
*/
class Ability_List
{
    private:
        std::vector<Ability> Abilities;
    public:
        void operator[]( Ability P)
        {
            (void)P;
        }
    void operator[](AbilityQeue& q) {
        for (auto& a : q.GetAb()) {
            Abilities.emplace_back(a);
        }
    }
    vector<Ability> GetAbiltyList()
    {
        return this->Abilities;
    }
}; 
/**
 * @class Pokemon
 * @brief main class of pokemon holding the name,hp,and the abilities of it and also a boolean value for the purpose of pokeball!
*/
class Pokemon
{
    private:
        string name;
        string Type;
        double health_points;
        std::vector<Ability> Abilities;
        bool IsActive=true;

    public:
        Ability_List PokemonAblities;
        void ShowStats()
        {
             
                cout << "##################"<<endl;
                cout << "NAME:" << this->name<<endl;
                cout << "HP:" << this->Type<<endl;
                cout << "HP:" << this->health_points<<endl;
                cout << "##################"<<endl;
                
        }
        Pokemon(string N,string T,double hp) : name(N), Type(T), health_points(hp) 
        {
                while(T!="Electric" && T!="Fire" && T!="Water" && T!="Grass")
                {
                    cout << "You need to add 1 of these :\nElectric Fire Water Grass";
                    cin >> T;
                }
                while(hp<0)
                {
                    cout << "HP should be greater than 0\n";
                    cin >> hp;
                }
                 PokemonList.emplace_back(*this);
        }
        double get_HP()
        {
            return this->health_points;
        }
        string get_TYPE()
        {
            return this->Type;
        }
        string get_NAME()
        {
            return this->name;
        }
        void set_Abilities(Ability A)
        {
                this->Abilities.push_back(A);
        }
        std::vector<Ability> get_Abilities()
        {
            return this->PokemonAblities.GetAbiltyList();
        }
        void Show_Abilities()
        {
            for(std::size_t i = 0; i<get_Abilities().size(); i++)
            {
                cout<<get_Abilities().at(i).get_Name()<<endl;
            }
            
        }
        void set_IsActive(int value)
        {   
            value ? IsActive=true : IsActive=false;
        }
        bool get_IsActive()
        {   
            return this->IsActive;
        }
        void SetHp(double Hp)
        {
            this->health_points+=Hp;
        }
        bool operator ==(const char * T)
        {
            if(this->Type==T)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool operator ==(const int H)
        {
            if(this->health_points==H)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool operator !=(const char * T)
        {
            if(this->Type!=T)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
         bool operator !=(const int H)
        {
            if(this->health_points!=H)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
         bool operator <=(const int H)
        {
            if(this->health_points<=H)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
         bool operator >=(const int H)
        {
            if(this->health_points>=H)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool operator >(const int H)
        {
            if(this->health_points>H)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool operator <(const int H)
        {
            if(this->health_points<(H))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};
/**
 * @class Player
 * @brief  player class used for the game , 2  instances are made with the fields representing the name of the player the status where if in this round its his turn or not,and 2 function holders
 * used for the for and after effects!
*/
class Player
{
    private:
        bool Status;
        std::string Name;
        std::vector<Pokemon> PlayerPokemon;
        std::function<void()> OLDAbilityAction=NULL;
        std::function<void()> AfterAbilityAction=NULL;
         int round_counter=-1;
         int after_counter=-1;
    public:
        Player(string N):Name(N){}
        void SelectPokemon(Pokemon p)
        {
            this->PlayerPokemon.push_back(p);
        }    
        void SetStatus(bool S) //FALSE=DEFENDER ,TRUE=ATTACKER
        {
            this->Status=S;
        }
         bool GetStatus() //FALSE=DEFENDER ,TRUE=ATTACKER
        {
            return this->Status;
        }
        std::string GET_Name()
        {
            return this->Name;
        }
        void set_Pokemon(Pokemon P)
        {
            this->PlayerPokemon.push_back(P);
        }
        Pokemon& get_Pokemon() {
             return this->PlayerPokemon.at(0);
        }
        void set_round_counter(int round)
         {
                this->round_counter=round;
         }
         int get_round_counter()
         {
                return this->round_counter;
         }
          void set_After_counter(int round)
         {
                this->after_counter=round;
         }
         int get_After_counter()
         {
                return this->after_counter;
         }
         void set_OldAction(std::function<void()> f)
         {
                OLDAbilityAction=f;
         }
        std::function<void()> get_OLDAbilityfF()
        {
            return OLDAbilityAction;
        }
         void set_AfterAction(std::function<void()> f)
         {
                AfterAbilityAction=f;
         }
        std::function<void()> get_AfterAction()
        {
            return AfterAbilityAction;
        }
         void StartOldAbilityAction()
         {
            cout<<"Your are in a loop of Ability for :"<< this->round_counter<<endl;
            round_counter--;
            if(round_counter==0)
            {
                round_counter=-1;
            }
            OLDAbilityAction();
         }
         void StartAfterAbilityAction()
         {
            //cout<<"Rounds:"<<after_counter<<"before you did this Ability"<<endl;
            AfterAbilityAction();
         }

};
/**
 * @class PokemonList
 * @brief Used for the CREATE POKEMONS purpose ,just to create with initiliazer lists pokemons and overlaoding the [] operator to understand it
*/
class Pokemon_List
{
    private:
        std::vector<Pokemon> pokemons;
    public:
        void operator[]( Pokemon P)
        {
            (void)P;
        }
};  
Pokemon PokemonTemp {"","Fire",1};
std::function<void()>A;
std::vector<Player> PlayerList;
Player p1{"Player1"};
Pokemon_List pl; Ability_List al;
Player p2{"Player2"};
int Round=0;
#define BEGIN_GAME int main(void){   
#define END_GAME ;  return 0; }

#define NAME   false ? " " //used for DSL purpose to contain somehow the : 
#define TYPE false ? " "//used for DSL purpose to contain somehow the : 
#define HP  false ? 1//used for DSL purpose to contain somehow the : 

#define CREATE ;
#define REMOVE(...)//used to remove extra comma when needed for single argument expressions
#define concat(var1,var2) var1 ## var2
#define CONCAT(var1,var2)  concat(var1,var2)
#define UNIQUE_CONCAT(p) CONCAT(p, __LINE__)

#define POKEMON Pokemon  //used for the initilizer list
#define POKEMONS pl

#define ABILITY Ability //used for the initilizer list
#define ABILITIES al
#define ACTION false ? A//used for DSL purpose to contain somehow the : 
int contextStack = 0; 
#define START  []() {(cout<<""  //used a techinique of GNU where you can implement in ({}); 
    

#define REPLACE(PokemonTemp,...) PokemonTemp  //used to replace the comma

#define ATTACKER  GetStatusAttacker()==0 ? p1.get_Pokemon() : p2.get_Pokemon()  , //used to find the attacker and return the pokemon of the attacker player with a comma and used either for the 2 argument functions or for the sinlge ones and removing after with the macro replace
#define DEFENDER   GetStatusDefender()==0 ? p1.get_Pokemon(): p2.get_Pokemon()   , //used to find the defender and return the pokemon of the defender player with a comma and used either for the 2 argument functions or for the sinlge ones and removing after with the macro replace


#define DAMAGE  );Damage(     //call of the damage function and some other macros will close this function call
#define HEAL    );Heal(       //call of the heal function and some other macros will close this function call
#define POKEBALL   );intoPokeball(     //call of the intoPokeball function and some other macros will close this function call

#define GET_HP(PokemonTemp, ...) GETHP(REPLACE(PokemonTemp) REMOVE(__VA_ARGS__)) //here is the single argument function when the comma needs to be removed so we use the macros REPLACE and REMOVE
#define GET_TYPE(PokemonTemp, ...) GETTYPE(REPLACE(PokemonTemp) REMOVE(__VA_ARGS__))//here is the single argument function when the comma needs to be removed so we use the macros REPLACE and REMOVE
#define GET_NAME(PokemonTemp, ...) GETNAME(REPLACE(PokemonTemp) REMOVE(__VA_ARGS__))//here is the single argument function when the comma needs to be removed so we use the macros REPLACE and REMOVE
#define IS_IN_POKEBALL(PokemonTemp, ...) getActive(REPLACE(PokemonTemp) REMOVE(__VA_ARGS__))//here is the single argument function when the comma needs to be removed so we use the macros REPLACE and REMOVE

#define SHOW );(std::cout<< //Used for the pseudo Output of the Dsl
#define AND AND_SIMPLE //call of recursive call of and functio to implement n arguments to be called
#define OR OR_SIMPLE //call of recursive call of or functio to implement n arguments to be called
#define NOT !

#define IF );if( // Statement macro:IF where always close the before one and start a new one so the next one can finish it!
#define DO )({(cout<<""  // Statement macro:DO where always close the before one and start a new one so the next one can finish it!
#define ELSE_IF );}else if((cout<<"" // Statement macro:ELSE_IF where always close the before one and start a new one so the next one can finish it!
#define ELSE );});else({(cout<<"" // Statement macro:ELSE where always close the before one and start a new one so the next one can finish it!
#define END );} // Statement macro:END where always close the before one and start a new one so the next one can finish it!
#define DEAR ;PokemonList.at(SearchPokemon(  //DEAR is macro calling the field of the PokemoList which holds all pokemons and SearchByName the pokemon to return it
#define LEARN )).PokemonAblities //the field of pokemons holding the list of abillities
#define ABILITY_NAME(Abil) +SearchAbility(#Abil) // making a list of abilitylists where the + operatro already overloaded ubuary and binary with AbilityQeue class
#define ROUNDS );if(true //used just for the purpose of the motivo of the GNU styled i refered before!
#define FOR   );SetLoopAbillity ( //Calls a function which sets the counter for the for loop action
#define AFTER );SetAfterAbillity(Round+//Calls a function which sets the counter for the after loop action
/**
 * @brief Retturns the defender
 * @returns defender
*/
int GetStatusDefender()
{
    if(p1.GetStatus()==false)
    {
        return 0; //PLAYER1
    }
    else
    {
        return 1;//PLAYER2
    }
}
/*
void SafeStatus()
{
        SafePokemon.SetHp( GetStatusDefender()==0 ? p1.get_Pokemon().get_HP() :p1.get_Pokemon().get_HP() );
        SafePokemon.set_IsActive( GetStatusDefender()==0 ? p1.get_Pokemon().get_IsActive() :p1.get_Pokemon().get_IsActive() );
}*/
/**
 * @brief Retturns the attacker
 * @returns attacker
*/
int GetStatusAttacker()
{
     if(p1.GetStatus()==true)
    {
        return 0; //PLAYER1
    }
    else
    {
        return 1;//PLAYER2
    }
}
/**
 * @brief Sets the counter for the for loop action
 * @param rounds the round numer
 * @returns null
*/
void SetLoopAbillity(int rounds)
{
    GetStatusAttacker()==0 ? p1.set_round_counter(rounds) : p2.set_round_counter(rounds) ;
}     
/**
 * @brief Sets the counter for the after loop action
 * @param rounds the round numer
 * @returns null
*/
void SetAfterAbillity(int rounds)
{
     //SafeStatus();
    GetStatusAttacker()==0 ? p1.set_After_counter(rounds) : p2.set_After_counter(rounds) ;

}         
/**
 * @brief Returns the ability with name s
 * @param s the name of abilty needed
 * @return of the Ability Instance
*/
AbilityQeue SearchAbility(string s)
{
    AbilityQeue q;
    for(std::size_t i = 0; i<AbilityList.size();i++)
    {
        if(s==AbilityList.at(i).get_Name())
        {
            q.GetAb().emplace_back(AbilityList.at(i));
            break;
        }
    }
    return q;
}
/**
 * @brief returns the hp
 * @param P the pokemon 
 * @returns the hp
*/
double GETHP(Pokemon P,...)
{
    return P.get_HP();
}
/**
 * @brief returns the type
 * @param P the pokemon
 * @returns the type
*/
string GETTYPE(Pokemon P,...)
{
    return  P.get_TYPE();
}
/**
 * @brief returns the activeness of the pokemon
 * @param P the pokemon
 * @returns the activeness
*/
bool getActive(Pokemon P,...)
{
    return P.get_IsActive();
}
/**
 * @brief returns the name of the pokemon
 * @param P the pokemon
 * @returns the name
*/
string GETNAME(Pokemon P,...)
{
    return P.get_NAME();
}
/**
 * @brief heals the pokemon
 * @param P the pokemon
 * @param hp the hp he is about to be heaeled
 * @returns 
*/
void Heal(Pokemon& P,double hp)
{
     Pokemon pAttacker= GetStatusAttacker()==0 ? p1.get_Pokemon() : p2.get_Pokemon();
     Player Attacker= GetStatusAttacker()==0 ? p1 : p2;
        if(pAttacker.get_IsActive()==true)
        {
            P.SetHp(hp);
            P.ShowStats();
        }
        else
        {
            cout<<"Next time choose an ability that sets you out of the pokeball"<<endl;
        }

}
int AfterCounter=0;
/**
 * @brief damages the pokemon
 * @param P the pokemon
 * @param hp the hp he is about to be damaged
 * @returns 
*/
void Damage(Pokemon& P,double hp)
{
    double AlteredHp=hp;
    Pokemon pAttacker= GetStatusAttacker()==0 ? p1.get_Pokemon() : p2.get_Pokemon();
     Player Attacker= GetStatusAttacker()==0 ? p1 : p2;
        if(pAttacker.get_IsActive()==true)
        {
            if(pAttacker.get_TYPE()=="Grass")
            {
                if(Round % 2!=0)
                {
                       cout<<"Old hp:"<<AlteredHp<<endl;
                       int temp=hp*(7/100);
                    AlteredHp=AlteredHp+AlteredHp * 0.07;
                    cout<<"New hp:"<<AlteredHp<<endl;
                }
            }
            if(pAttacker.get_TYPE()=="Water")
            {
                
                cout<<"Im water and im attacking"<<endl;
                cout<<"Old hp:"<<AlteredHp<<endl;
                int temp=hp*(7/100);
                AlteredHp=AlteredHp+AlteredHp * 0.07;
                cout<<"New hp:"<<AlteredHp<<endl;
            }
            if(pAttacker.get_TYPE()=="Fire")
            {
                    if(P.get_TYPE()=="Electric")
                    {
                        cout<<"Im fire and im attacking Electric"<<endl;
                        cout<<"Old hp:"<<AlteredHp<<endl;
                        int temp=hp*(20/100);
                        AlteredHp=AlteredHp+AlteredHp * 0.20;
                         cout<<"New hp:"<<AlteredHp<<endl;
                    }
                    else{
                        cout<<"Im fire just"<<endl;
                        cout<<"Old hp:"<<AlteredHp<<endl;
                        int temp=hp*(15/100);
                        AlteredHp=AlteredHp+AlteredHp * 0.15;
                        cout<<"New hp:"<<AlteredHp<<endl;
                    }
            }
            if(P.get_TYPE()=="Electric")
            {
                    if(pAttacker.get_TYPE()=="Fire")
                    {
                        cout<<"im electric and  im getting attacked by fire"<<endl;
                           cout<<"Old hp:"<<AlteredHp<<endl;
                           int temp=hp*(30/100);
                        AlteredHp=AlteredHp-AlteredHp * 0.30;
                        cout<<"New hp:"<<AlteredHp<<endl;
                    }
                    else{
                         
                        cout<<"Im electric just"<<endl;
                          cout<<"Old hp:"<<AlteredHp<<endl;
                          int temp=hp*(20/100);
                        AlteredHp=AlteredHp-AlteredHp * 0.20;
                        cout<<"New hp:"<<AlteredHp<<endl;
                    }
            }
            if(P.get_TYPE()=="Water")
            {
                 cout<<"Im water and im defending"<<endl;
                    cout<<"Old hp:"<<AlteredHp<<endl;
                int temp=hp*(7/100);
                AlteredHp=AlteredHp-AlteredHp * 0.07;
                cout<<"New hp:"<<AlteredHp<<endl;
            }
            if(Attacker.get_After_counter()==-1)
            {
                P.SetHp(-AlteredHp);
                P.ShowStats();     
            }
            else
            {
                    if(AfterCounter!=0)
                    {             
                        P.SetHp(-AlteredHp);
                        P.ShowStats();  
                    }
                     AfterCounter++;
            }
        }
        else
        {
            cout<<"Next time choose an ability that sets you out of the pokeball"<<endl;
        }
}
/**
 * @brief sets the pokemon out/in Pokeball
 * @param P the pokemon
 * @param S the status that is goind to happen 
 * @returns 
*/
void intoPokeball(Pokemon& P,PokemonStatusCalls S)
{
  Player Attacker= GetStatusAttacker()==0 ? p1 : p2;
        if(S.get_Name()=="InPok")
        {
            cout<<"Pokemon Into The Pokeball"<<endl;
            P.set_IsActive(false);
        }
        else if(S.get_Name()=="OutOfPok")
        {
            cout<<"Pokemon Out of The Pokeball"<<endl;
            P.set_IsActive(true);
        }
}



/**
 * @brief Prints the pokemons to the user
*/
void PrintAllPokemons()
{
    cout<<"--------------------"<<endl;
    for(std::size_t i = 0;i<PokemonList.size(); i++)
    {
        cout<<PokemonList.at(i).get_NAME()<<endl;
    }
    cout<<"--------------------"<<endl;
}
/**
 * @brief Selects the pokemon for the player
 * @param p the player
*/
void Select_A_Pokemon(Player& p)
{
    std::string NamePokemon;
    cout<<p.GET_Name()<<" select a pokemon: "<<endl;
    PrintAllPokemons();
    while(1)
    {
            std::getline(std::cin, NamePokemon);
            for(std::size_t i = 0; i<PokemonList.size(); i++)
            {
                if(NamePokemon==PokemonList.at(i).get_NAME())
                {
                        cout<<"You selected "<<PokemonList.at(i).get_NAME()<<endl;
                        p.set_Pokemon(PokemonList.at(i));
                       // cout<<PokemonList.at(i)->get_NAME()<<PokemonList.at(i)->PokemonAblities.GetAbiltyList().size()<<endl;
                        return ;
                }
            }
            cout << "There is no Pokemon named "<<NamePokemon<<endl;
    }
}
/**
 * @brief Searches the pokemon out of the global list
 * @param s the name of the pokemon
 * @returns the index of it
*/
int SearchPokemon(string s)
{
    int return_number=-1;
    for(std::size_t i = 0; i<PokemonList.size(); i++)
    {
        if(s==PokemonList.at(i).get_NAME())
        {
            return_number =i;
            break;
        }
    }
    if(return_number==-1)
    {
         while(1)
         {
          cout<<"There is no Pokemon Named:"<<s<<endl<<"Please choose 1 of these:"<<endl;
          PrintAllPokemons();
          std::getline(std::cin, s);
            for(std::size_t i = 0; i<PokemonList.size(); i++)
            {
                if(s==PokemonList.at(i).get_NAME())
                {
                    return return_number;

                }
            }
         }
    }
    return return_number;
}
int P1forloopcounter=-1;
int P2forloopcounter=-1;
/**
 * @brief Selects and abilit from the list of the abilities of each pokemons player
 * @param p the player who called it
*/
void Select_A_Ability(Player& p)
{
    std::string NameAbility;
    std::vector<Ability> Avec;
    Avec=p.get_Pokemon().get_Abilities();
    cout<<p.get_Pokemon().get_NAME()<<"("<<p.GET_Name()<<") select an ability:"<<endl<<"----------------------------------------------------------------"<<endl;
            p.get_Pokemon().Show_Abilities();
    cout<<"----------------------------------------------------------------"<<endl;
    while(1)
    {
         if(  ((p.get_round_counter()!=-1 && p.get_OLDAbilityfF()==NULL)|| p.get_round_counter()==-1) &&((p.get_After_counter()!=-1 && p.get_AfterAction()==NULL) || p.get_After_counter()==-1) )
            {
                std::getline(std::cin, NameAbility);
                for(std::size_t i = 0; i< Avec.size(); i++)
                {
                    if(NameAbility==Avec.at(i).get_Name())
                    {
                        if(p.get_After_counter()!=-1 && p.get_OLDAbilityfF()==NULL)
                        {
                                int temp=p.get_After_counter();
                                Avec.at(i).StartAbilityAction();
                                cout<<"I saved the ability :"<<AfterAbilityHolder[AfterAbilityHolder.size()-2].get_Name()<<endl;
                                GetStatusAttacker() == 0 ?  p1.set_After_counter(-1) : p2.set_After_counter(-1);
                                p.set_After_counter(-1);
                                p.set_AfterAction(AfterAbilityHolder[AfterAbilityHolder.size()-2].get_Abilityf());
                                GetStatusAttacker() == 0 ?  p1.set_After_counter(temp) : p2.set_After_counter(temp);
                                p.set_After_counter(temp);
                                return ;
                        }
                        if(p.get_round_counter()==-1)
                        {
                            Avec.at(i).StartAbilityAction();
                            AfterAbilityHolder.emplace_back( Avec.at(i));
                            if(p.get_round_counter()!=-1)
                            {
                                     p.set_OldAction(Avec.at(i).get_Abilityf());
                                     GetStatusAttacker() == 0 ?  P1forloopcounter=p.get_round_counter()-1 :  P2forloopcounter=p.get_round_counter()-1;
                                     p.set_round_counter(p.get_round_counter()-1);
                            }
                            return ;
                        }
    
                    }
                }
                cout << "There is no Ability named "<<NameAbility<<endl;
         } 
         else
         {
              if(p.get_After_counter()==Round)
                {
                         GetStatusAttacker() == 0 ?  p1.set_After_counter(-1) : p2.set_After_counter(-1);
                         p.set_After_counter(-1);
                         p.StartAfterAbilityAction();
                        GetStatusAttacker() == 0 ?  p1.set_After_counter(-1) : p2.set_After_counter(-1);
                          p.set_After_counter(-1);
                         AfterCounter=0;
                }  
                if(p.get_round_counter()!=-1)
                {
                    p.StartOldAbilityAction();
                    GetStatusAttacker() == 0 ? p.set_round_counter(--P1forloopcounter) : p.set_round_counter(--P2forloopcounter);
                }
                return;
         }  
    }
}
/**
 * @brief used for the recursive call of the function and
 * @param 
 * @return 1 becasue is the base of recursion
*/
bool AND_SIMPLE() {
    return 1;  
}
/**
 * @brief template used for the purpose of unknown number of arguments called in this function
*/
template <typename... Args>
bool AND_SIMPLE(bool ANDarg0, Args... PokemonArgs) {
    return ANDarg0 && AND_SIMPLE(PokemonArgs...); 
}
/**
 * @brief used for the recursive call of the function or
 * @param 
 * @return 1 becasue is the base of recursion
*/
bool OR_SIMPLE() {
    return 1;  
}
/**
 * @brief template used for the purpose of unknown number of arguments called in this function
*/
template <typename... Args>
bool OR_SIMPLE(bool ORarg0, Args... PokemonArgs) {
    return ORarg0 || OR_SIMPLE(PokemonArgs...); 
}
/**
 * @brief used foe the effect of grass get healed each round
 * @param round the round
 * @param P the pokemon about to be healed
*/
void ChangeHpGrass(int round,Pokemon P)
{   
    if(round % 2 ==0 && P.get_TYPE()=="Grass")
    {
        cout<<"Even Round and Im Grass"<<endl;
        P.SetHp(+P.get_HP()*0.05);
        cout<<"New HP of pokermon:"<<P.get_HP()<<endl;
    }
}
/**
 * @brief change the staus of the player in each half round
*/
void ChangeStatus()
{
    if(p1.GetStatus()==false)
    {
        p1.SetStatus(true);
    }
    else
    {
        p1.SetStatus(false);
    }
    if(p2.GetStatus()==false)
    {
        p2.SetStatus(true);
    }
    else
    {
        p2.SetStatus(false);
    }
}
/**
 * @brief checks who win after each ability casted
*/
int END_POKEMON_GAME()
{
    if(p1.get_Pokemon().get_HP()<=0)
    {
        return 0;//p2 won
    }
    if(p2.get_Pokemon().get_HP()<=0)
    {
        return 1;//p1 won
    }
    return -1;
}
#define DUEL ; p1.SetStatus(true); p2.SetStatus(false); GamePokemon();

/**
 * @brief the pokemon game which holds all the logic
*/
void GamePokemon()
{
    int Winner=-1;
    PlayerList.push_back(p1);
    PlayerList.push_back(p2);

    cout<<"-------------------------------POKEMON THE GAME ---------------------------------------------"<<endl; 
    //ATTACKER=1,DEFENDER=2
    Select_A_Pokemon(p1); 
    Select_A_Pokemon(p2);
    while(1)
    {
        cout<<"----------------------------------------------------------------"<<endl<<"Round "<<Round<<endl<<"----------------------------------------------------------------"<<endl;
        
        Select_A_Ability(p1);
        ChangeStatus();
        ChangeHpGrass(Round,p1.get_Pokemon());
        Winner=END_POKEMON_GAME();
        if(Winner==0 ) {cout<<p2.GET_Name()<<"won"<<endl; return;}
        if(Winner==1){ cout<<p1.GET_Name()<<"won"<<endl ;return;}

        Select_A_Ability(p2);
        
        ChangeStatus();
        ChangeHpGrass(Round,p2.get_Pokemon());
        Winner=END_POKEMON_GAME();
        if(Winner==0 ) {cout<<p2.GET_Name()<<"won"<<endl; return;}
        if(Winner==1){ cout<<p1.GET_Name()<<"won"<<endl ;return;}

        Round++;
    }
}


