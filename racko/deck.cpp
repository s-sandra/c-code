/*
@author Sandra Shtabnaya

assignment: racko
purpose: defines functions for racko discard and draw decks.
*/

#ifndef DECK_CPP
#define DECK_CPP
#include "deck.h"
#include <iostream>
#include <cstdlib>
using namespace std;

/*
This function loads the deck you initialized with  
cards 1 through 60. 
*/
Deck::Deck() {
    for (int i = 0; i < MAX_CARDS; i++) {
        drawPile[i] = i + 1;
    }
    drawPileIndex = 59; // sets to top of deck.
    discardPileIndex = -1; // discard pile is empty.
}

/*
This function shuffles the deck or the discard pile.  
To decide which one it needs to shuffle, it checks the  
length of the deck. It shuffles the deck to start the  
game. Also is used to shuffle the discard pile if we ever  
run out of cards in the deck (length of deck being 0) 
*/
void Deck::shuffle() {
    
    // if no one has drawn from the deck yet
    if (drawPileIndex == 59) {
        shuffle(drawPile, 60);
    }
    
    // if the deck has run out of cards
    else if (drawPileIndex == -1) {
        // cout << "Deck has run out. Shuffling discard pile." << endl;
        shuffle(discardPile, discardPileIndex + 1);
        refillDeck();
        discardPileIndex = -1;
        addCardToDiscard(dealCard());
    }
    
    // tests that deck is shuffled
    /*cout << "Your shuffled deck is:\n"; 
    for (int i = 0; i < MAX_CARDS; i++) {
        cout << drawPile[i] << endl;
    }*/
}

/* 
this helper function transfers shuffled discard pile to
deck if the deck is empty. 
*/
void Deck::refillDeck() {
    for (int i = 0; i <= discardPileIndex; i++) {
        addCardToDeck(discardPile[i]);
    }
}

// This helper function shuffles the given list of cards.
void Deck::shuffle(int deck[], int size) {
     srand(time(0));
    
    // swaps randomly selected indices MAX_CARDS number of times
    for (int i = 0; i < size; i++) {
        int swap1 = rand() % size; // generates random index from 0 - size.
        int swap2 = rand() % size;
        int temp = deck[swap1];
        deck[swap1] = deck[swap2];
        deck[swap2] = temp;
    }
}

// prints out the top card in the discard pile.
void Deck::display() {
    cout << discardPile[discardPileIndex];
}

// returns the top card in the discard pile, without
// removing the card.
int Deck::displayDiscard() {
    return discardPile[discardPileIndex];
}

/*
This functions gets the discard card from the  
discard pile.  It is used after the first turn when 
the user wants to take the discard instead of a dealCard. 
*/
int Deck::getDisCard() {
    int card = discardPile[discardPileIndex];
    discardPileIndex--;
    return card;
}

/*
This function gets the top card from the deck.  
It is used at the start of gameplay and again  
during each player's turn if they decide to not  
take the top card from the discard pile.
*/
int Deck::dealCard() {
    // shuffles discard pile if deck is empty
    if (drawPileIndex == -1) {
        shuffle();
    }
    int card = drawPile[drawPileIndex];
    drawPileIndex--;
    return card;
}      

// places the given card in the discard pile
void Deck::addCardToDiscard(int currentCard) {
    discardPileIndex++;
    discardPile[discardPileIndex] = currentCard;
    // cout << "added " << currentCard << " to discarded pile at index " << discardPileIndex << endl;
}

void Deck::addCardToDeck(int card) {
    drawPileIndex++;
    drawPile[drawPileIndex] = card;
}
#endif /* DECK_CPP */
