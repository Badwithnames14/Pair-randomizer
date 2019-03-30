//A program that creates pairs from a list of names. 2 modes are included, teams for exclusive pairs, and list for non-exclusive pairings (eg secret santa, order of succession, etc)
//Cord Corcese - March 2019

#include <iostream>
#include <string>
#include <time.h>
#include <pair>

std::vector<std::pair<std::string,std::string>> TeamBuilder(vector<std::string> names){
	//So we need to randomize each name in the name vector, take it out, and then reroll f
	std::string nameA;
	std::string nameB;
	std::vector<std::pair<std::string,std::string>> teams;
	std::unordered_multiset<std::string> NameSet;
	std::vector<std::string> RandomOrder;
	for(std::string name:names){
		NameSet.insert(name);
	}
	for(int i =0; i<names.size();i++){
		srand(time(NULL));
		Namepoint = rand()% names.size();
		NamesRemoved = NameSet.remove(names[Namepoint]);
		if(NamesRemoved > 1){
			for(int k =0; k < NamesRemoved; k++){
				NameSet.insert(names[Namepoint])
			}
		}
		else if (NamesRemoved == 0){
			while( NamesRemoved != 1 ){
				srand(time(NULL));
				Namepoint = rand()% names.size();
				NamesRemoved = NameSet.remove(names[Namepoint]);
				if(NamesRemoved > 1){
					for(int k =0; k < NamesRemoved; k++){
						NameSet.insert(names[Namepoint])
					}
				} 
			}
		}
		RandomOrder.push_back(names[Namepoint])
	}
	for(std::string RandName:RandomOrder){
		//Make pairs
	}
	
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
	
	std::vector<std::pair<std::string;std::string>> NamePairs;  //Team group builder
	for(int i; i<names.size()/2;i++){
		/*srand(tize();
		nameB = names[Namepoint];ime(NULL));
		Namepoint = rand() % names.size();
		nameA = names[Namepoint];
		srand(time(NULL));
		Namepoint = rand() % names.s*/
	}
	
}