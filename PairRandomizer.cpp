//A program that creates pairs from a list of names. 2 modes are included, teams for exclusive pairs, and list for non-exclusive pairings (eg secret santa, order of succession, etc)
//Cord Corcese - March 2019

#include <iostream>
#include <string>
#include <time.h>
#include <utility>  
#include <vector> 
#include <unordered_set>

std::vector<std::pair<std::string,std::string>> TeamBuilder(std::vector<std::string> names){
	//So we need to randomize each name in the name vector, take it out, and then reroll f
	std::string nameA;
	std::string nameB;
	std::vector<std::pair<std::string,std::string>> teams;
	std::unordered_multiset<std::string> NameSet;
	std::vector<std::string> RandomOrder;  //End variable init 
	int Namepoint = 0;
	for(std::string name:names){ //Creates multiset 
		NameSet.insert(name);
	}
	for(unsigned int i =0; i<names.size();i++){ //randomizes names 
		srand(time(NULL));
		Namepoint = rand()% names.size();
		int NamesRemoved = NameSet.erase(names[Namepoint]); 
		if(NamesRemoved > 1){  //If duplicate names are present, readd remaining to multiset 
			for(int k =0; k < NamesRemoved; k++){
				NameSet.insert(names[Namepoint]);
			}
		}
		else if (NamesRemoved == 0){ //If name is not in multiset, reroll until a valid name is drawn
			while( NamesRemoved != 1 ){ //Run until only one name is drawn from Multiset 
				srand(time(NULL));
				Namepoint = rand()% names.size();
				NamesRemoved = NameSet.erase(names[Namepoint]);
				if(NamesRemoved > 1){  //If duplicates exist, readd them and repeat
					for(int k =0; k < NamesRemoved; k++){
						NameSet.insert(names[Namepoint]);
					}
				} 
			}
		}
		RandomOrder.push_back(names[Namepoint]); //Push names into random order
	}
	for(unsigned int j=0;j<RandomOrder.size();j++){ //Creates pairs 
		//Make pairs. Need to take 2 things in a vector and combine them
		nameA = RandomOrder[j];
		j++;  //Counts 2 at a time 
		nameB = RandomOrder[j];
		teams.push_back(std::make_pair(nameA,nameB)); 
		//Need to add odd number check 
	}
	return teams;
}

int main(){
	std::string string1;
	std::vector<std::string> names; //List of names to randomize
	while(std::cin >> string1){  //User inputs names
		names.push_back(string1);
	}
	
	std::cout<<"names for pair randomizing:" << std::endl; //Shows user input 
	for(std::string h: names){
		std::cout << h << std::endl;
	}
	
	//Choose list or team 
	
	std::vector<std::pair<std::string,std::string>> NamePairs = TeamBuilder(names);  //Team group builder
	for(std::pair<std::string,std::string> pair : NamePairs){
		std::cout << pair.first << " is partners with " << pair.second << std::endl;
	}

	
}