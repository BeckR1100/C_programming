#include<stdio.h>
#define TRUE 1
#define FALSE 0

void read_menu(FILE *fPtr_menu, int *c1, double *p1, int *c2, double *p2, int *c3, double *p3);
void read_discount(FILE *fPtr_discount, int *d1, int *d2, int *d3);
int get_menu_choice(int c1, int c2, int c3, double p1, double p2, double p3);
int order_meal(double price_of_food, int c_of_food, int d_percentage, double *money, int *cal);
void print_state(int report, int food, double money, int cal);

int main(){

  int c1,c2,c3;
  double p1,p2,p3;
  int d1,d2,d3;
  double discount, money;
  int d_type, menu, status;
  int cal;
  int key;

  printf("enter a number for key: \n");
  scanf("%d",key);
  if(key == 12345){

  FILE *fPtr_menu, *fPtr_discount;
  fPtr_menu = fopen("menu.txt", "r");
  fPtr_discount = fopen("discount.txt", "r");

}else{
  printf("key is not a valid\n");
}

  if(fPtr_menu == NULL || fPtr_discount == NULL){
    printf("Coldn't open file \n");
    return 1;
  }

 read_menu(fPtr_menu, &c1, &p1,&c2,&p2,&c3,&p3);

 printf("1.Calorie is %d - Price is %2.lf \n", c1,p1 );

 read_discount(fPtr_discount, &d1,&d2,&d3);

 printf("Our discount variables %d, %d, %d \n", d1,d2,d3);


 printf("enter your discount type (1-2-3): \n");
 scanf("%d", &d_type);

 printf("Enter your balance: \n");
 scanf("%lf", &money);


switch (d_type) {
  case 1: discount = d1; break;
  case 2: discount = d2; break;
  case 3: discount = d3; break;
  default:
  printf("return value \n");
}
menu =   get_menu_choice(c1,c2,c3,p1,p2,p3);
printf(" Enter select by user %d\n", menu);

while(menu != 0){
  switch (menu) {
    case 1: status = order_meal(p1,c1, discount , &money, &cal); break;
    case 2: status = order_meal(p2,c2, discount, &money, &cal); break;
    case 3: status = order_meal(p3,c3, discount, &money, &cal); break;
    default: printf("return value \n");
  }
     // printf("Status is: %d \n", status);
     print_state(status, menu, money, cal);
     menu =   get_menu_choice(c1,c2,c3,p1,p2,p3);

     return 0;

}
switch (menu) {
  case 1: status = order_meal(p1,c1, discount , &money, &cal); break;
  case 2: status = order_meal(p2,c2, discount, &money, &cal); break;
  case 3: status = order_meal(p3,c3, discount, &money, &cal); break;
  default: printf("return value \n");
}
   // printf("Status is: %d \n", status);
   print_state(status, menu, money, cal);
   return 0;
}
void read_menu(FILE *fPtr_menu, int *c1, double *p1, int *c2, double *p2, int *c3, double *p3){

  fscanf(fPtr_menu, "%d", c1);
  fscanf(fPtr_menu, "%d", c2);
  fscanf(fPtr_menu, "%d", c3);
  fscanf(fPtr_menu, "%lf", p1);
  fscanf(fPtr_menu, "%lf", p2);
  fscanf(fPtr_menu, "%lf", p3);
  return;
}

void read_discount(FILE *fPtr_discount, int *d1, int *d2, int *d3){
  fscanf(fPtr_discount, "%d", d1);
  fscanf(fPtr_discount, "%d", d2);
  fscanf(fPtr_discount, "%d", d3);
  return;
}

int get_menu_choice(int c1, int c2, int c3, double p1, double p2, double p3){
  int choice;
  printf("\n Enter meal: \n 1-Soup(%d cal) = %lf TL  \n 2-Becff(%d cal) = %lf TL \n 3- Kannd(%d cal) = %lf TL \n 0 - To exit \n \n Enter your choice: ", c1,p1,c2,p2,c3,p3 );
  scanf("%d", &choice);
  return choice;
}

int order_meal(double price_of_food, int c_of_food, int d_percentage, double *money, int *cal){
    price_of_food = price_of_food * (100 - d_percentage)/100;

    if(*money >= price_of_food){
        *money -= price_of_food;
        *cal += c_of_food;

        return TRUE;
    }
      return FALSE;
}

void print_state(int report, int food, double money, int cal){

  if(report == 0){

    printf("Your money is not enought to order thet food! \n");
    printf("Cal : %d \n Money: %.lf \n",cal, money);
    return;
  }

  switch (food) {
    case 1: printf("You ordered soup. \n Cal: %d Money %lf \n", cal, money); break;
    case 2: printf("You ordered beef. \n Cal: %d Money %lf \n", cal, money); break;
    case 3: printf("You ordered cake. \n Cal: %d Money %lf \n", cal, money); break;
    default: printf("return value \n");
  }
}
