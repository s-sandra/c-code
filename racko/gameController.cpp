/*
@author Sandra Shtabnaya

assignment: racko
purpose: defines racko AI and functions for player moves.
*/

#ifndef GAME_CONTROL_CPP
#define GAME_CONTROL_CPP
#include "gameController.h"
#include <iostream>
#include <cctype>
using namespace std;

// displays the rules of the game
void gameController::displayMenu() {
    cout << endl << "WELCOME TO RACKO!" << endl << endl;
    cout << "Racko Rules" << endl << endl;
    cout << "A Racko deck is composed of 60 cards, each numbered 1 to 60. Both the player and the " << endl << "computer are dealt ten cards, which form their rack." << endl; 
    cout << "The objective is to be the first player to arrange all of the cards in your rack from " << endl << 
            "lowest to highest." << endl << endl; 
    cout << "The top card of the deck is turned over to start the discard pile." << endl <<
            "A player takes a turn by taking the top card from either the deck or the discard pile, " << endl <<
            "then discarding one from his rack and inserting the new card in its place." << endl <<
            "If the player draws a card from the deck, he may immediately discard it; if he takes " << endl << 
            "the top discard, though, he must put it on his rack." << endl << endl;
}

void gameController::promptMove() {
    string choice = promptDraw();
    while (choice != "deck" && choice != "discard") {
        cout << "Invalid choice. Enter deck or discard: ";
        cin >> choice;
    }
    if (choice == "deck") {
        int card = gameDeck.dealCard();
        cout << "You drew " << card << " from the deck" << endl;
        cout << "Do you wish to discard this card? y or n? ";
        cin >> choice;
        toLower(choice);
        while (choice != "y" && choice != "n") {
            cout << "Invalid choice. Enter y or n: ";
            cin >> choice;
        }
        if (choice == "y") {
            cout << endl;
            gameDeck.addCardToDiscard(card);
        }
        else {
            cout << endl;
            promptCard(card, humanRack, RACK_SIZE);
        }
        
    }
    else {
        int card = gameDeck.getDisCard();
        cout << "You drew " << card << " from the discard pile" << endl;
        promptCard(card, humanRack, RACK_SIZE);
    }
}

/*
prints the contents of player's rack
as well as the top card in the discard pile.
*/
void gameController::printGameState() {
    
    // prints out players' racks.
    /*cout << "AI's Rack" << endl;
    print_top_to_bottom(AIRack, RACK_SIZE);
    cout << endl;*/
    
    cout << "Player's Rack" << endl;
    print_top_to_bottom(humanRack, RACK_SIZE);
    cout << endl;
    
    // top of deck becomes discard pile.
    cout << "Discard Pile" << endl;
    gameDeck.display();
    cout << endl << endl;
}

/*
This will be the main loop until either the AI 
or the player wins 
*/
void gameController::playGame() {
    
    // begin game by shuffling deck
    gameDeck.shuffle();
    
    // AI is dealt a card
    int AICard = gameDeck.dealCard();
    cout << "AI is dealt " << AICard << endl;
    
    // human is dealt a card
    int humanCard = gameDeck.dealCard();
    cout << "Player is dealt " << humanCard << endl << endl;
    
    bool humanFirst;
    
    // player with highest card goes first
    if (AICard > humanCard) {
        humanFirst = false;
        cout << "AI goes first!" << endl << endl;
    }
    else {
        humanFirst = true;
        cout << "Player goes first!" << endl << endl;
    }
    
    // deck is shuffled again
    gameDeck.addCardToDeck(humanCard);
    gameDeck.addCardToDeck(AICard);
    gameDeck.shuffle();
    
    // players given rack cards and discard pile is started
    deal_initial_hands();
    gameDeck.addCardToDiscard(gameDeck.dealCard());
    printGameState();
    
    if (humanFirst) {
        promptMove();
    }
    else {
        AITurn();
    }
    printGameState();
    
    // continue to play until one player gets Racko
    while (!check_racko(humanRack, RACK_SIZE) && !check_racko(AIRack, RACK_SIZE)) {
        
        // AI goes next only if human went last
        if (humanFirst) {
            AITurn();
            humanFirst = false;
        }
        else {
            promptMove();
            humanFirst = true;
        }
        printGameState();
    }
    
    if (check_racko(humanRack, RACK_SIZE)) {
        cout << "Player wins!" << endl;
    }
    else {
        cout << "AI wins. Game over." << endl;
    }
    
}

void gameController::toLower(string& input) {
    for(int i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
}

/*
Prompts player for next draw and returns their choice.
*/
string gameController::promptDraw() {
    string choice;
    cout << "Do you want to draw from the deck or the discard pile? ";
    cin >> choice;
    toLower(choice);
    cout << endl;
    
    return choice;
}

/*
Prompts player for the card they wish to swap in their rack.
*/
void gameController::promptCard(int newCard, 
                                int Rack[],
                                const int SIZE) {
    int choice;
    cout << "Which card do you want to replace with " << newCard << "? ";
    cin >> choice;
    cout << endl;
    
    // findAndReplace() returns false if card not found.
    while (!findAndReplace(newCard, choice, Rack, SIZE)) {
        cout << choice << " is not a card in your rack.\n";
        cout << "Which card do you want to replace with " << newCard << "? ";
        cin >> choice;
    }
}

/*
Finds the index of the first out of order card in AI's Rack, from the top to
bottom, starting at startingIndex. Otherwise, returns -1.
*/
int gameController::findOutOfOrderCard(int startingIndex) {
    
    // find first position (starting from top of rack) that's out of order
    for (int i = startingIndex; i >= 0; i--) {
        
        // if current card is at the top of the rack
        if (i == RACK_SIZE - 1) {
            // if the top card is greater than the one below it
            if (AIRack[i] > AIRack[i - 1]) {
                return i;
            }
        }
        else {
            // if current card is less than the one above it
            if (AIRack[i] < AIRack[i + 1]) {
                return i;
            }
        }
    }
    return -1;
}

/*
Finds a place for a card drawn from deck or discard
in AI's rack according to order. Returns false if no move made.
*/
bool gameController::findPlaceFor(int card) {
    int index = RACK_SIZE - 1;
    int candidate = -1;
    int ignore = -1;
    
    while (index > -1) {
        
        // searches for first out of order card.
        candidate = findOutOfOrderCard(index);
        
        // if out of order card is found
        if (candidate != -1) {
            int choice = AIRack[candidate]; // gets candidate card
            
            // if candidate is at the top, and it's greater than the 
            // discard or deck card
            if (candidate == RACK_SIZE - 1 && candidate > card) {
                findAndReplace(card, choice, AIRack, RACK_SIZE);
                return true;
            }
            
            // if the discard or deck card fits between the card above and
            // below candidate
            else if (AIRack[candidate + 1] < card && AIRack[candidate - 1] > card) {
                findAndReplace(card, choice, AIRack, RACK_SIZE);
                return true;
            }
            
            index = candidate - 1; // sets index to search for next candidate
        }
        else {
            index = -1;
        }
    }
    return false;
}

/*
Places passed card in the first position in AI rack, where the card
above is less than the passed card (if iterating from top) or
the card below is greater than passed card (if iterating from
bottom).
*/
bool gameController::defaultTurn(int card) {
    
    // if the card should be place near to the top of the rack
    if (card < 40) { 
        for (int i = RACK_SIZE - 1; i >= 0; i--) {
            // the card must be less than the current card
            if (AIRack[i] > card) {
                if (i == RACK_SIZE - 1) { // if current card is at top
                    findAndReplace(card, AIRack[i], AIRack, RACK_SIZE);
                    return true;
                }
                else if (i == 0 && AIRack[i] < card) { // if current card is at bottom
                    findAndReplace(card, AIRack[0], AIRack, RACK_SIZE);
                    return true;
                }
                // if the card above current card is less than card
                else if (AIRack[i + 1] < card) {
                    findAndReplace(card, AIRack[i], AIRack, RACK_SIZE);
                    return true;
                }
            }
        }
            
    }
    
    // if the card should be placed near the bottom of the rack
    else {
        for (int i = 0; i <= RACK_SIZE - 1; i++) {
             // card must be greater than current card
            if (AIRack[i] < card) {
                // if current card is at the top and greater than card
                if (i == RACK_SIZE - 1 && AIRack[i] > card) {
                    findAndReplace(card, AIRack[i], AIRack, RACK_SIZE);
                    return true;
                }
                else if (i == 0) { // if current card is at the bottom
                    findAndReplace(card, AIRack[0], AIRack, RACK_SIZE);
                    return true;
                }
                // if current card is not the bottom card and the
                // card below it is greater than passed card
                else if (i != 0 && AIRack[i - 1] > card) {
                    findAndReplace(card, AIRack[i], AIRack, RACK_SIZE);
                    return true;
                }
            }
        }
    }
    
    return false;
}

/*
Program a strategy that the AI will pick cards from 
discard pile when it benefits its rack.  Otherwise, 
pick from the draw pile and the AI will determine if 
the draw pile card will be used.
*/
void gameController::AITurn() {
    cout << "AI's Turn" << endl;
    int discard = gameDeck.displayDiscard();
    
    if (findPlaceFor(discard)) {
        cout << "AI has taken the discard\n\n";
        return;
    }

    // if there is no place for discard, choose default.
    if (defaultTurn(discard)) {
        cout << "AI has taken the discard\n\n";
        return;
    }
    
    // if there is no such position, draw from deck
    int card = gameDeck.dealCard();
    cout << "AI has drawn from the deck.\n\n";
    if (findPlaceFor(card)) {
        return;
    }
    
    // if there is no place for deck card, choose default.
    if (defaultTurn(card)) {
        return;
    }
    
    
    // if there is no such position, forfeit the card.
    gameDeck.addCardToDiscard(card);
    cout << "AI has forfeited its turn.\n\n";
    return;
}

/*
Determines whether Racko has been achieved. Achieving Racko  
means that the cards are in ascending order.
*/
bool gameController::check_racko(int Rack[], const int SIZE) {
    // top of rack is index 9.
    for (int i = SIZE - 1; i > 0; i--) {
        if (Rack[i] > Rack[i - 1]) {
            return false;
        }
    }
    return true;
} 
 
/*
Deals ten cards to each player following card
dealing conventions.
*/
void gameController::deal_initial_hands() {
    for (int i = 0; i < 10; i++) {
        humanRack[i] = gameDeck.dealCard();
        AIRack[i] = gameDeck.dealCard();
    }
}

/*
Prints a given rack from top to bottom.
*/
void gameController::print_top_to_bottom(int Rack[], const int SIZE) {
    for (int i = SIZE - 1; i >= 0; i--) {
        cout << Rack[i] << endl;
    }
}

/*
Finds the card that needs to be replaced in the rack by its
number and replaces it with new card. The replaced card then 
gets put on top of the discard. If the user accidentally  
typed a card number incorrectly, it leaves the hand unchanged  
and has the user try again. 
*/
bool gameController::findAndReplace(int newCard,
                                    int cardToBeReplaced, 
                                    int Rack[],
                                    const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        if (Rack[i] == cardToBeReplaced) {
            Rack[i] = newCard;
            gameDeck.addCardToDiscard(cardToBeReplaced);
            return true;
        }
    }
    return false;
}
#endif /* GAME_CONTROL_CPP */