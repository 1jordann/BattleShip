#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void yourboard(int board[10][10], char carrier, char cruiser, char battleship, char sub, char destroyer,int place_X1,
  int place_Y1,
  int place_X2,
  int place_Y2,

  int startx,
  int stopx,
  int starty,
  int stopy , int xcoordinate, char ycoordinate, int line, char column);
//Print the enemy board
void board1(int board[10][10], int line, char column, int xcoordinate, int ycoordinate, int win);
//places enemy ships
void shipss(int ships[2][2], int ship, int last);



int main(void) {
  int board[10][10];
  int line;
  char column;
  int ship;
  int last;
  int ships[2][2];
  int xcoordinate;
  char ycoordinate;
  int attempt;
  int attempts=0;
  int hits=0;
  int row;
  char carrier = 67;
  char cruiser = 82;
  char battleship = 66;
  char sub = 83;
  char destroyer = 68;
  char play;
  char miss = 42;
  int win=0;
int place_X1;
  int place_Y1;
  int place_X2;
  int place_Y2;

  int startx;
  int stopx;
  int starty;
  int stopy;
  board1(board,line,column,xcoordinate,ycoordinate,win);
  shipss(ships,ship,last);
  yourboard(board,carrier,cruiser, battleship,sub,destroyer,place_X1,place_Y1,
  place_X2,
  place_Y2,
  startx,
  stopx,
  starty,
  stopy ,xcoordinate,ycoordinate,line,column);
    //Entering coordinates
  printf("Enter coordinates (dont hit enter after x) starting with your x coordinate then your y coodinate.\n");
  printf("EX: 1A\n");
  scanf("%d%c", &xcoordinate, &ycoordinate);



//HIT OR MISS (that joke died)
       for(ship=0 ; ship < 5 ; ship++){


           if(xcoordinate==ships[ship][0] && ycoordinate==ships[ship][1]){
                printf("You hit a ship with the coordinate (%d,%c)\n",xcoordinate,ycoordinate);

                return 1;
            }
          else if(xcoordinate!=ships[ship][0] && ycoordinate!=ships[ship][1]){


            printf("You did not hit a ship with (%d,%c), better luck next time... ", xcoordinate,ycoordinate);
            board[xcoordinate][ycoordinate]= miss;
            break;
          }

  }




  return 0;
}
//Doesnt even work :/
void yourboard(int board[10][10], char carrier, char cruiser, char battleship, char sub, char destroyer,int place_X1,
  int place_Y1,
  int place_X2,
  int place_Y2,
  int startx,
  int stopx,
  int starty,
  int stopy, int xcoordinate, char ycoordinate, int line, char column ){
    printf("Your board\n");
    for(line=0 ; line < 10 ; line++ )
    for(column=0 ; column < 10 ; column++ )
   board[line][column]=-1;

    printf("\tA \tB \tC \tD \tE \tF \tG \tH \tI \tJ");

  printf("\n");

  for(line=0 ; line < 10 ; line++ ){
  printf("%d",line+1);
  for(column=0 ; column < 10 ; column++ ){
if(board[line][column]==-1){
 printf("\t0");
 }

 }
printf("\n");
}
    stopy = 0;
            stopx = 0;
            starty = 0;
            startx = 0;
            printf("\nPlease enter first coordinate to shoot  (capital letter followed by number, e.g. A8)  for the Carrier.");
            scanf(" %c%d", &ycoordinate, &place_Y1);
            place_X1 = ycoordinate - 65;
            printf("\nPlease enter second coordinate for  the Carrier.");
            scanf(" %c%d", &ycoordinate, &place_Y2);
            place_X2 = ycoordinate - 65;

  }

  void board1(int board[10][10],int line, char column, int xcoordinate, int ycoordinate, int win){

    printf("enemy board\n");
    for(line=0 ; line < 10 ; line++ )
    for(column=0 ; column < 10 ; column++ )
   board[line][column]=-1;

    printf("\tA \tB \tC \tD \tE \tF \tG \tH \tI \tJ");

  printf("\n");

  for(line=0 ; line < 10 ; line++ ){
  printf("%d",line+1);
  for(column=0 ; column < 10 ; column++ ){
if(board[line][column]==-1){
 printf("\t0");
 }

 }
printf("\n");
}

  }



void shipss(int ships[2][2], int ship, int last){
        for(ship=0 ; ship < 5 ; ship++){
            ships[ship][0]= rand()%10;
            ships[ship][1]= rand()%10;


            for(last=0 ; last < ship ; last++){
                if( (ships[ship][0] == ships[last][0])&&(ships[ship][1] == ships[last][1]) )
                    do{
                        ships[ship][0]= rand()%10;
                        ships[ship][1]= rand()%10;
                    }while( (ships[ship][0] == ships[last][0])&&(ships[ship][1] == ships[last][1]) );
            }

        }
}