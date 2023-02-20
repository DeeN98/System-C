#include<iostream>
#include "state_machine.h"
#include<regex>


void stateMachine::process()
{
	
	//char input_1 = input->read();
	//cout << input << endl;
	switch (current_state)
	{

		
		
	case Start:
		seq_count++;
		//cout << seq_count;
		//cout << input << endl;
		if (input == 'G') {
			current_state = G;	
			g_position++;
		}
		else{
			current_state = Start;
			g_position = 0;
		}
		break;
	case G:
		if (input == 'G') {
			current_state = G;
			g_position = 0; //i am in g then again g
			
		}
		//NEXT STATE
		else if (input == 'A') {
			current_state = GA; //this should increase
			g_position++;
		}
		else{
			current_state = Start;
			g_position = 0;
		}
		break;

	case GA:

		if (input == 'G') {
			current_state = G;
			g_position = 0;
		}
		
		//THE NEXT STATE
		else if (input == 'A') {
			current_state = GAA;
			g_position++;
		}
		else{
			current_state = Start;
			g_position = 0;
		}
		break;

	case GAA:

		if (input == 'A') {
			current_state = GAA;
			g_position++;
		}
		//THE NEXT STATE
		else if (input == 'G') {
			current_state = GAAG;
			std::cout << "done sistar" << endl;
			counter++;
			std::cout << counter << endl;
			g_position++;
			cout << "the position is: " << (seq_count - g_position) << endl;
			
		}
		else {
			current_state = Start;
			g_position = 0;
		}
		break;

	case GAAG:
		
		if (input == 'G') {
			current_state = G;
			

		}
		else {
			current_state = Start;
			g_position = 0;
			
		}
		break;

	default:
		std::cout << "tata bye bye";
		break;

	}
	
}



