#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void print_balance(int age, double balance) {
    int years = age / 12;
    int months = age % 12;
    printf("Age %3d month %2d you have $%.2lf\n", years, months, balance);

}

double calculator_balance(int startAge, double initial, retire_info period){
  double balance = initial;
  
  for(int i = 0; i < period.months; i++){
    print_balance(startAge+i,balance);
    balance += balance*period.rate_of_return;
    balance += period.contribution;
  }
  return balance;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired){
 double balance =  calculator_balance(startAge, initial, working);
 calculator_balance(startAge+ working.months, balance, retired);

}

int main(){
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12;

  retirement(327, 21345, working, retired);

  return 0;
}
