#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  //printf("value = %u, suit= %c \n",c.value, suit_letter(c));
  assert(c.value>=2 && c.value<=VALUE_ACE);
  assert(c.suit == SPADES || c.suit == HEARTS || c.suit == DIAMONDS || c.suit == CLUBS);
  
  
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH:
    return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND";
  case FULL_HOUSE:
    return "FULL_HOUSE";
  case FLUSH:
    return "FLUSH";
  case STRAIGHT:
    return "STRAIGHT";
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND";
  case TWO_PAIR:
    return "TWO_PAIR";
  case PAIR:
    return "PAIR";
  default:
    return "NOTHING";

  }
  return "";
}
unsigned convert_value_letter(char value) {
  if(value>='2' && value<='9'){
    return value-'0';
  }else{
    switch (value) {
    case '0':
      return 10;
    case 'J':
      return VALUE_JACK;
    case 'Q':
      return VALUE_QUEEN;
    case 'K':
      return VALUE_KING;
    case 'A':
      return VALUE_ACE;
    default:
      return 0;
    }
  }
  return 0;
}

char value_letter(card_t c) {
  if(c.value>=2 && c.value<=9){
    return '0'+c.value;
  }else{
    switch (c.value) {
    case 10:
      return '0';
    case VALUE_JACK:
      return 'J';
    case VALUE_QUEEN:
      return 'Q';
    case VALUE_KING:
      return 'K';
    case VALUE_ACE:
      return 'A';
    default:
      return 'x';
    }
  }
  return 'x';
}
suit_t convert_suit_letter(char suit) {
  switch(suit){
  case 's':
    return SPADES;
  case 'h':
    return HEARTS;
  case 'd':
    return DIAMONDS;
  case 'c':
    return CLUBS;
  default:
    return NUM_SUITS;
  }
  return NUM_SUITS;

 
}

char suit_letter(card_t c) {
  switch(c.suit){
  case SPADES:
    return 's';
  case HEARTS:
    return 'h';
  case DIAMONDS:
    return 'd';
  case CLUBS:
    return 'c';
  default:
    return 'x';
  }
  return 'x';
  
}

void print_card(card_t c) {
  assert_card_valid(c);
  char value = value_letter(c);
  char suit = suit_letter(c);
  printf("%c%c",value,suit);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  temp.value = convert_value_letter(value_let);
  temp.suit = convert_suit_letter(suit_let);
  //assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  assert(c>=0 && c <52);
  card_t temp;
  temp.value = c%13+2;
  temp.suit = c/13;
  return temp;
}
