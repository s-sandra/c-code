/*
@author Sandra Shtabnaya

assignment: racko
purpose: declares racko AI and functions for player moves.
*/

#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H
#include "deck.h"
#include <string>
using namespace std;

class gameController { 
   public:  
      
      void displayMenu(); 
      //Display the rules of the game 
       
      void playGame(); 
      //This will be the main loop until either the AI 
      //or the player wins 
       
      void AITurn(); 
      //Program a strategy that the AI will pick cards from 
      //discard pile when it benefits its rack.  Otherwise, 
      //pick from the draw pile and the AI will determine if 
      //the draw pile card will be used. 
       
      bool check_racko(int Rack[], const int SIZE);  
      //Given a rack, either the user's or the computer's,  
      //determine if Racko has been achieved. Achieving Racko  
      //means that the cards are in ascending order. 
 
      void deal_initial_hands(); 
	  //Start the game off by dealing two hands of 10 cards  
	  //each. The cards are to be inserted into the array at 
	  //the end. Make sure that you follow normal card game
	  //conventions of dealing. You have to deal one card to
	  //the user, one to the computer, one to the user, one to 
	  //the computer and so on. 

       
      void print_top_to_bottom(int Rack[],const int SIZE); 
      //Given a rack print it out from top to bottom in  
      //a manner that looks more akin to the game  
      //(more stack like than list like). For example,  
      //given the rack: [2, 57, 53, 23, 45, 60, 12, 35, 7, 1],  
      //the rack will look like: 
      //1 
      //7 
      //35 
      //12 
      //60 
      //45 
      //23 
      //53 
      //57 
      //2 
     
      bool findAndReplace(int newCard,int cardToBeReplaced, int Rack[],const int SIZE); 
      //This function finds the card that needs to be  
      //replaced in the hand, which is represented by  
      //the card's number, and then replaces it  
      //with the new card. The replaced card then gets  
      //put on top of the discard. Also, you want to  
      //check to make sure that the cardToBeReplaced is  
      //truly a card in the hand. If the user accidentally  
      //typed a card number incorrectly, leave the hand unchanged  
      //and have the user try again.
      
      void printGameState();
      // prints out the contents of player's and AI's rack, as well
      // as the top card in the discard pile.
      
      // converts given string to lowercase.
      void toLower(string& input);
             
   private: 
      static const int RACK_SIZE = 10;
      int humanRack[RACK_SIZE]; 
      int AIRack[RACK_SIZE]; 
      bool playing; 
      Deck gameDeck;
      
      // prompts player for next draw.
      string promptDraw();
      
      // prompts player for card to replace in rack.
      void promptCard(int newCard, int Rack[], const int SIZE);
      
      // prompts player for next move.
      void promptMove();
      
      int findOutOfOrderCard(int startingIndex);
      
      bool findPlaceFor(int card);
      
      bool defaultTurn(int card);
}; 
#endif /* GAME_CONTROL_H */