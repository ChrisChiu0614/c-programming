#include "cards.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void test_card_from_letters(char,char);

int main(void) {

  
  test_card_from_letters('0','c');
  test_card_from_letters('A','h');
  test_card_from_letters('K','c');
  test_card_from_letters('Q','d');
  test_card_from_letters('6','c');
  test_card_from_letters('J','c');
  //test_card_from_letters('?','0');
  
  return 0;
}

void test_card_from_letters(char value, char suit){
  //card_t temp;
  printf("value = %c, suit= %c \n",value, suit);
  //temp.value = convert_value_letter(value);
  //temp.suit = convert_suit_letter(suit);
  card_t temp = card_from_letters(value,suit);
  print_card(temp);
}

