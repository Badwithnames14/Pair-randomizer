//A program that creates pairs from a list of names. 2 modes are included, teams for exclusive pairs, and list for non-exclusive pairings (eg secret santa, order of succession, etc)
//To do: 
//Finish list implimentation
//Add variable team sizes
//Rewrite to take advantage of classes
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
		if(j <= RandomOrder.size() ){
			nameB = RandomOrder[j];
			teams.push_back(std::make_pair(nameA,nameB)); 
		}else{
			nameB = "";
		}
		//Need to add odd number check 
	}
	return teams;
}

std::vector<std::pair<std::string,std::string>> Listbuilder(std::vector<std::string> names){ //Creates secret santa style sorting
	//To do
	std::vector<std::string> getters;
	for(std::string name : names){
		getters.push_back(name);
	}//copy vector to hold potential gift recivers
	std::vector<std::pair<std::string,std::string>> matches; //Maybe switch to using a list?
	for(std::string name: getters){
		std::cout << "getters: " << name << std::endl; 
	}
	
	for(std::string giver: names){
		int namepos = rand()%getters.size();
		matches.push_back(make_pair(giver,getters.at(namepos)));
		getters.erase(getters.begin() + namepos);
		//Randomly take name from getters and pair it with giver
		//Remove name pulled from getters
		//matches.append();
	}
	//std::cout << "GIVER" << "buys for" << "GETTER" //Add variables This goes in main or as a class function once implemented
	//Return as a pair with the santa matched with the giftee
	for(std::pair pairing: matches){
		std::cout << pairing.first << " buys for " << pairing.second << std::endl;
	}
	//Need to ensure all names are matched
	//Copy inital name list, one will be giver list, one will be getter list
	//Take a givers, randomly match with getter, remove both from each list
	//Then print out secret santa matches
	//Add way to anonomize it later? 
	return matches;
}

int main(){
	std::string string1;
	std::vector<std::string> names; //List of names to randomize
	while(std::cin >> string1){  //User inputs names
		names.push_back(string1);
	}
	std::cin.clear();
	std::cout<<"names for pair randomizing:" << std::endl; //Shows user input 
	for(std::string h: names){
		std::cout << h << std::endl;
	}
	
	std::string programMode;
	std::cout << "Please enter \"Team\" or \"List\" to choose team randomization or group list" << std::endl;	//Choose list or team 
	std::cin >> programMode;
	for (char &letter:programMode){ //Negates capitalization
		letter = toupper(letter);
	}
	
	if(programMode == "TEAM"){
		std::vector<std::pair<std::string,std::string>> NamePairs = TeamBuilder(names);  //Team group builder
		for(std::pair<std::string,std::string> pair : NamePairs){
			std::cout << pair.first << " is partners with " << pair.second << std::endl;
		}
	}
	else if(programMode == "LIST"){
		std::cout << "List mode has yet to be developed, sorry the inconvience" << std::endl;
		Listbuilder(names);
	}
	else{
		std::cout << "Invalid input, please restart and try again" << std::endl;
	}
	

	
}