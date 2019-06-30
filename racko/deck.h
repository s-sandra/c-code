/*
@author Sandra Shtabnaya

assignment: racko
purpose: declares functions for racko discard and draw decks.
*/

#ifndef DECK_H
#define DECK_H
using namespace std;

class Deck 
{ 
   public: 
      Deck(); 
      //This function loads the deck you initialized with  
      //cards 1 through 60. 
       
      void shuffle(); 
      //This function shuffles the deck or the discard pile.  
      //To decide which one it needs to shuffle, it checks the  
      //length of the deck. It shuffles the deck to start the  
      //game. Also used to shuffle the discard pile if we ever  
      //run out of cards in the deck (length of deck being 0)
      
      void shuffle(int deck[], int size);
 
      void display(); 
      //Prints out the discarded card.
      
      int displayDiscard();
      // returns the top of the discarded pile,
      // without removing the card from the pile.
 
      int getDisCard(); 
      //This functions gets the discard card from the  
      //discard pile.  It is used after the first turn when 
      //the user wants to take the discard instead of a dealCard 
       
      int dealCard();       
      //This function gets the top card from the deck.  
      //It is used at the start of gameplay and again  
      //during each player's turn if they decide to not  
      //take the top card from the discard pile.  
       
      void addCardToDiscard(int currentCard); 
      //Put the card in the discard pile
      
      void addCardToDeck(int card);
      
   private:
      static const int MAX_CARDS = 60;
      int drawPile[MAX_CARDS]; 
      int drawPileIndex;
      int discardPile[MAX_CARDS]; 
      int discardPileIndex;
      
      void refillDeck();
      // transfers discard pile to deck, if deck is empty.
      
}; //End class 
#endif /* DECK_H */
