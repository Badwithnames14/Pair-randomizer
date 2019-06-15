//A program that creates pairs from a list of names. 2 modes are included, teams for exclusive pairs, and list for non-exclusive pairings (eg secret santa, order of succession, etc)
//Cord Corcese - March 2019

#include <iostream>
#include <string>
#include <time.h>
#include <utility>  
#include <vector> 
#include <unordered_set>
#include <set>

std::vector<std::pair<std::string,std::string>> TeamBuilder(std::vector<std::string> names){
	//So we need to randomize each name in the name vector, take it out, and then reroll f
	std::string nameA;
	std::string nameB;
	std::vector<std::pair<std::string,std::string>> teams;
	//std::unordered_multiset<std::string> NameSet;
	std::multiset<std::string> NameSet;
	std::vector<std::string> RandomOrder;  //End variable init 
	int Namepoint = 0;
	for(std::string name:names){ //Creates multiset 
		NameSet.insert(name);
	}
	
	while(NameSet.size() != 0){//Add srand somewhere
		//Move iterator by a random value dependant on the size of the multiset 
		//Remove element at that point and insert it into the random order vector 
		Namepoint = rand()% NameSet.size(); //Picks point for name
		auto iter = NameSet.begin(); //Creates iterator 
		for(int k = 0; k<Namepoint; k++){ //Moves to element
			iter++; 
		}
		std::string thing = *iter; //Retrives value from iterator 
		RandomOrder.push_back(thing); //Adds to array
		NameSet.erase(iter); //Destorys 
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