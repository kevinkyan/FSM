#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
struct state {
				int num;
				string type;
				string secondType;
};
struct transition {
				int startState;
				string transition;
				int endState;
};
int main(int argc, char *argv[]) {
				int currentState;
				//stores accept and start states
				vector<state> states;
				//stores transitions
				vector<transition> transitions;
				//stores current states;
				vector<state> *currentStates = new vector<state>;
				string line;
				string input = argv[2];
				//turn string of 0's and 1's into array
				int nextInput[input.length()];
				for(int i = 0; i < line.length(); i++) {
								nextInput[i] = line.at(i);
				}
				//parse textfiles to create states and transistions
				ifstream myfile(argv[1]);
				if(myfile.is_open()) {
								cout<<"file open";
								while(getline(myfile, line)) {
												cout<< line << endl;
												istringstream iss(line);
												string type;
												string firstInput;
												string secondInput;
												string thirdInput;
												iss >> type >> firstInput >> secondInput >> thirdInput;
												cout<< type<< endl;
												cout<< firstInput << endl;
												cout<< secondInput<< endl;
												cout<< thirdInput<< endl;
												if(type == "state") {
																cout<< "yes";
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
																				secondInput,
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
				//check that states were inputed
				for(int i = 0; i < states.size(); i++) {
								cout << "State" << states[i].num << endl << "Type1: " << states[i].type << endl;
				}
				for(int i = 0; i < transitions.size(); i++) {
						cout << "Start state: " << transitions[i].startState << endl << "Transition: " << transitions[i].transition << endl;
				}
}
int *makeIntArray(int length)
{
				int *p = NULL;
				if( length > 0 )
				{
								p = (int *) malloc(length*sizeof(int));
				}
				return p;
}
void deleteIntArray(int *p)
{
				if( p != NULL )
				{
								free(p);
				}
}
int **makeIntMatrix(int width, int height)
{
				int **p = (int **) NULL;
				int *pData = (int *) NULL;
				if( (width > 0) && (height > 0) )
				{
								p = (int **) malloc(width*sizeof(int*));
								pData = (int *) malloc(width*height*sizeof(int));
								int i = 0;
								while( i < width )
								{
												p[i] = pData+(i*height);
												i = i+1;
								}
				}
				return p;
}
void deleteIntMatrix(int **p)
{
				if( p != NULL )
				{
								if( p[0] != NULL )
								{
												free(p[0]);
								}
								free(p);
				}
}
