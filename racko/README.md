# Rack-O
## Description
This program implements a variant of the card game Rack-O, where the user plays against an AI algorithm, with the goal of being the first to
order their “rack” of numbered cards through substitution. The implementation uses arrays to store and manipulate racks and decks. 

## Rules
The ``gameController`` module shuffles and deals the deck (which contains cards numbered 1 to 60), alters racks for players and 
determines winners. It begins by drawing a card for the player and the AI. Whoever has the highest numbered card goes first. 
The deck is then reshuffled and the controller deals each players’ rack, which consists of ten cards, arranged in the order in which 
they were given. During gameplay, cards can only be swapped with cards from the deck or discard pile one turn at a time.

### Discard Pile
The top of the deck is then used to start the discard pile. If the deck runs out, the discard pile is shuffled and used as the deck. 
Unlike the deck, the top of the discard pile is always known. During gameplay, cards are added to the top of the discard pile whenever 
the user substitutes a card in their rack.

### Turns
During a turn, the player can choose to either draw a card from the deck (which is unknown) or the discard pile (which is known). 
If the player draws from the discard pile, they must substitute the card with an existing one in their rack. However, if they draw 
an undesirable card from the deck, they can choose to add it to the discard pile and leave their rack unchanged.

### Win State
The first player to produce a rack in ascending order (from top to bottom) wins. In this program, the rack is depicted vertically, 
like a stack, with the beginning at the top and the end at the bottom.
