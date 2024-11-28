#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

// Function to print a hand, with spaces between each card
void print_hand(deck_t *hand) {
    size_t i = 0;
    while (i < hand->n_cards) {
        if (i > 0) {
            printf(" ");
        }
        print_card(*hand->cards[i++]);  // Dereference pointer to pass card_t value to print_card
    }
}

// Function to check if a specific card is in the deck; returns 1 if found, 0 otherwise
int deck_contains(deck_t *d, card_t c) {
    size_t i = 0;
    while (i < d->n_cards) {
        // Fix: Avoid incrementing i twice when checking value and suit
        if (c.value == d->cards[i]->value && c.suit == d->cards[i]->suit) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Shuffle function using the Fisher-Yates algorithm
void shuffle(deck_t *d) {
    for (size_t i = d->n_cards - 1; i > 0; i--) {
        // Randomly select a card and swap it
        size_t random_index = rand() % (i + 1);
        card_t *temp = d->cards[i];
        d->cards[i] = d->cards[random_index];
        d->cards[random_index] = temp;
    }
}

// Function to check if the deck contains exactly 52 unique cards
void assert_full_deck(deck_t *d) {
    unsigned re[52] = {0};  // Initialize an array to track each card in the deck
    for (size_t i = 0; i < 52; i++) {
        // If the deck contains a specific card, set the corresponding index to 1
        if (deck_contains(d, card_from_num(i))) {
            re[i] = 1;
        }
    }

    // Verify that each card appears exactly once
    for (size_t i = 0; i < 52; i++) {
        // Fix: Check that re[i] is 1, meaning each card should only appear once
        assert(re[i] == 1);
    }
}

void add_card_to(deck_t * deck, card_t c){
    card_t *card = malloc(sizeof(*card));
    card->value = c.value;
    card->suit = c.suit;
    deck->cards = realloc(deck->cards,(deck->n_cards+1)*sizeof(*deck->cards));
    deck->cards[deck->n_cards] = card;
    deck->n_cards++;
}

deck_t * make_deck_exclude(deck_t * excluded_cards){
    deck_t * newDeck = malloc(sizeof(*newDeck));
    newDeck->cards = NULL;
    newDeck->n_cards=0;
    for(int i = 0; i < 52; i++){
        card_t c = card_from_num(i);
        if(deck_contains(excluded_cards,c)){
            continue;
        }
        add_card_to(newDeck, c);
    }
    return newDeck;
}

card_t * add_empty_card(deck_t * deck){
    card_t c = {.value=0,.suit=0};
    add_card_to(deck,c);
    return deck->cards[deck->n_cards-1];

}

void free_deck(deck_t * deck) {
    if(deck == NULL){
        return;
    }
    for(size_t i = 0; i < deck->n_cards; i++){
        free(deck->cards[i]);
    }

    free(deck->cards);
    free(deck);
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands){
    deck_t *exclu = malloc(sizeof(*exclu));
    exclu->cards= NULL;
    exclu->n_cards=0;
    for(size_t i =0; i <n_hands; i++){
        card_t** cards = hands[i]->cards;
        size_t len = hands[i]->n_cards;
        for(size_t j = 0; j < len; j++){
            add_card_to(exclu, *cards[j]);
        }
    }
    deck_t *ans = make_deck_exclude(exclu);
    free(exclu);
    return ans;
}
