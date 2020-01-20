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
		std::cout<<"added "<<name<<std::endl;
	}
	
	while(NameSet.size() != 0){//Add srand somewhere
		std::cout << "in while loop" << std::endl;
		//Move iterator by a random value dependant on the size of the multiset 
		//Remove element at that point and insert it into the random order vector 
		Namepoint = rand()% NameSet.size(); //Picks point for name
		std::cout << "Created Namepoint" << std::endl;
		auto iter = NameSet.begin(); //Creates iterator 
		std::cout << "created iter" << std::endl;
		for(int k = 0; k<Namepoint; k++){ //Moves to element
			iter++; 
		}
		std::string thing = *iter; //Retrives value from iterator 
		std::cout << "thing is "<< thing << std::endl;
		RandomOrder.push_back(thing); //Adds to array
		std::cout << "added " << thing << " to randomOrder" << std::endl; 
		NameSet.erase(iter); //Destorys 
	}
	std::cout << "randomOrder size = " << RandomOrder.size() << std::endl;
	for(unsigned int j=0;j<RandomOrder.size();j++){ //Creates pairs 
		//Make pairs. Need to take 2 things in a vector and combine them
		nameA = RandomOrder[j];
		std::cout << "nameA = " << nameA << std::endl;
		j++;  //Counts 2 at a time 
		if(j <= RandomOrder.size() ){
			nameB = RandomOrder[j];
			std::cout << "nameB = " << nameB << std::endl; 
			teams.push_back(std::make_pair(nameA,nameB)); 
		}else{
			nameB = "";
		}
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
	}
	else{
		std::cout << "Invalid input, please restart and try again" << std::endl;
	}
	

	
}