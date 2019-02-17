#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
struct state {
				int num;
				string type1;
				string type2;
};
struct transition {
				int startState;
				char transition;
				int endState;
};
int main(int argc, char *argv[]) {
				int currentState;
				//stores accept and start states
				vector<state> states;
				//stores transitions
				vector<transition> transitions;
				//stores current states;
				vector<int> currentStates;
				string line;
				string input = argv[2];
				//turn string of 0's and 1's into array
				vector<char> nextInput;
				for(int i = 0; i < input.length(); i++) {
								nextInput.push_back(input.at(i));
				}
				//parse textfiles to create states and transistions
				ifstream myfile(argv[1]);
				if(myfile.is_open()) {
								while(getline(myfile, line)) {
												cout<< line << endl;
												istringstream iss(line);
												string type;
												string firstInput;
												string secondInput;
												string thirdInput;
												iss >> type >> firstInput >> secondInput >> thirdInput;
												if(type == "state") {
																//create state
																state newState =
																{
																				stoi(firstInput),
																				secondInput,
																				thirdInput
																};
																//add state to list of states
																states.push_back(newState);
												}
												if(type == "transition") {
																//create transition
																transition newTrans =
																{
																				stoi(firstInput),
																				secondInput[0],
																				stoi(thirdInput)
																};
																transitions.push_back(newTrans);
												}

								}
								myfile.close();
				}
				else {
								cout << "Unable to open file";
				}
				for(state s: states) {
								if(s.type1 == "start" || s.type2 == "start") {
									currentStates.push_back(s.num);
								}
				}
				while(!nextInput.empty()) {
					vector<int> addState;
					for(transition t: transitions) {
						for(int i: currentStates) {
							if(t.startState == i && *(nextInput.begin()) == t.transition) {
								if(find(addState.begin(), addState.end(),t.endState) == addState.end()) {
									addState.push_back(t.endState);
								}
							}
						}
					}
					currentStates = addState;
					nextInput.erase(nextInput.begin());
				}
				vector<int> acceptStates;
				bool accepted = false;
				for(int i : currentStates) {
					for(state s : states) {
						if(i == s.num && (s.type1 == "accept" || s.type2 == "accept")) {
							accepted = true;
							acceptStates.push_back(i);
						}
					}
				}
				if(accepted) {
					cout << "accept ";
					for(auto i = acceptStates.begin(); i !=acceptStates.end(); i++) {
						cout << *i << " ";
					}
				}
				else {
					cout << "reject ";
					for(auto i = currentStates.begin(); i !=currentStates.end(); i++) {
						cout << *i << " ";
					}
				}

}
