// Title  :  Assignment 3
// Purpose:  Simple Solitaire
// Author :  anonymous
// Date   :  25/11/2015

// Using the standard IO library.
#include <iostream>
#include <time.h>

// Using the standard namespace as it is a single programmer project.
using namespace std;

void setup (int board[][5], // *In-Out*
            int solitaireBoard[][5], // *In-Out*
            int MAX,		 // *In*
	    int specialPeg1, // *In*
	    int specialPeg2, // *In*
            int &specialPegCount) // *Out*
{ // The 'setup' subprogram will be used when the player has indicated
  // they wish to start a new round of the game. It'll then copy the
  // default board setup into the 'solitaireBoard' array through the
  // ‘board’ array specified in the 'main' body of the program.

for (int i = 0; i < MAX; i++)
{
 for (int x = 0; x < MAX; x++)
 {
 solitaireBoard[i][x] = board[i][x] ;
 }
}

solitaireBoard[specialPeg1][specialPeg2] = 2;
specialPegCount = 0 ;

} // setup



void gameOver (int solitaireBoard[][5], // *In*
               int MAX, // *In*
               int &gameRunning, // *In*
               int board[][5],  // *In*
	       int &highScore,  // *In-Out*
	       int specialPeg1, // *In-Out*
	       int specialPeg2, // *In-Out*
	       int &specialPegCount) // *In-Out*
{ // The 'gameOver' subprogram is called when the user has typed
  // "0,0" on the peg selection stage, indicating they have ended
  // the current round. This subprogram is used to show the player
  // their score for the round, but also to determine whether a new
  // game is started or if the program should quit.

// Initialise our variables.
int counter = 0 ; // Counts the amount of pegs remaining.
int points = 0 ; // Stores the users points.
char newRound ; // Will indicate whether a new round begins.

cout << endl ;
cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl ;
cout << "You've decided to end the round!" << endl ;
cout << "You scored [" ;

// The following code will count the remaining pegs in the
// array so that a tally of points can be worked out.
for (int i = MAX-1; i >= 0; i--)
{
 for (int x = 0; x < MAX; x++)
 {
  if (solitaireBoard[i][x] == 1)
  {
  counter++ ;
  }
 }
}

// Once we've determined the remaining pegs in the array, we
// can calculate the amount of points that should be given to
// the player. Points will only be allocated when there are 8
// or fewer pegs remaining on the board when the player has
// entered "0,0".
if (counter == 8)
{
points += 10 ;
}
else if (counter == 7)
{
points += 20 ;
}
else if (counter == 6)
{
points += 30 ;
}
else if (counter == 5)
{
points += 40 ;
}
else if (counter == 4)
{
points += 50 ;
}
else if (counter == 3)
{
points += 60 ;
}
else if (counter == 2)
{
points += 70 ;
}
else if (counter == 1)
{
points += 80 ;
}
else
{
points = 0 ;
}

// If there is a peg remaining in the centre of the board when
// the player enters "0,0" then the player will be awarded
// 20 bonus points.
if (solitaireBoard[2][2] == 1)
{
points += 20 ;
}

// Once the point amount has been calculated it'll be
// printed out for the player to see.
cout << points ;
cout << "] points." << endl ;
cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl ;

// If the player has earned more points than the current High
// Score (which is defaulted at 0 when the game has first been run),
// then announce that the player has beaten the High Score and update
// the High Score with the new value.
if (points > highScore)
{
cout << "Congratulations!" << endl ;
cout << "Your score of [" ;
cout << points ;
cout << "] is a new high score!" << endl ;
cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl ;
highScore = points ;
}

// Display the current High Score. This number will not change
// unless the player has beaten the High Score. In which case, the
// previous string of code will handle the updated amount.
cout << "The current High Score is: [" ;
cout << highScore ;
cout << "]." << endl ;
cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl ;
cout << endl ;

do
{
// Ask the player whether they wish to start a new round or not. If
// the player has indicated they wish to start a new round, the board
// will be set up again via the 'setup' subprogram. If the user wishes
// to end the game, the program will simply end.
cout << "Would you like to play another round? (y/n): " ;
cin >> newRound ;

if (!cin || newRound != 'n' && newRound != 'N' &&
            newRound != 'y' && newRound != 'Y')
{
cout << "Please try again. Enter 'y' or 'n'." << endl ;
cin.clear();             // Clear whatever was entered into the input.
cin.ignore(999, '\n');   // Ignore anything in the stream.
}
else
{
 if (newRound == 'n' || newRound == 'N')
 {
 // If the player has decided to end the game, then report that the game
 // has ended through the 'gameRunning' variable. Setting this variable
 // to '1' indicates that the game has ended.
 gameRunning = 1 ;
 }
 else if (newRound == 'y' || newRound == 'Y')
 { // If the user wants to start a new game, then set up a new
   // board for them to play with.
 setup(board, solitaireBoard, MAX, specialPeg1, specialPeg2, specialPegCount) ;
 }
}
}
while (newRound != 'n' && newRound != 'N' && newRound != 'y' &&
       newRound != 'Y') ;
} // gameOver

void errorList (int errorNumber) // *In*
{ // The subprogram 'errorList' will notify the user of an illegal move
  // they've attempted to make by retrieving a variable with its
  // corresponding number from where the error has initially occurred.

if (errorNumber == 1)
{
cout << endl ;
cout << "ILLEGAL MOVE." << endl ;
cout << "You cannot move the peg off of the board. " ;
cout << "Please try again." << endl ;
cout << endl ;
}
else if (errorNumber == 2)
{
cout << endl ;
cout << "ILLEGAL MOVE." << endl ;
cout << "There is no peg to jump over. Please try again." << endl ;
cout << endl ;
}
else if (errorNumber == 3)
{
cout << endl ;
cout << "ILLEGAL MOVE." << endl ;
cout << "A peg already exists in that location. " ;
cout << "Please try again." << endl ;
cout << endl ;
}
else if (errorNumber == 4)
{
cout << endl ;
cout << "ILLEGAL MOVE." << endl ;
cout << "You cannot jump over the special peg. " ;
cout << "Please try again." << endl ;
cout << endl ;
}

}



void doPlayerMove (int convertAction[], // *In-Out*
                   char &direction, // *In*
                   int MAX, // *In*
                   int solitaireBoard[][5], // *In*
                   int errorNumber, // *In*
                   int &gameRunning, // *In*
				   int &specialPegCount) // *In*
{ // The'doPlayerMove' subprogram deals with the direction in
  // which the chosen peg moves on the solitaire board by the
  // user entering a single character from 'n,s,e,w.' The peg
  // will only move if the conditions are met. 

// This if statement will only operate if the user has indicated
// they wish to move East by entering 'E' or 'e' after the peg
// selection stage. The user will be prompted with an error
// message if moving East means the peg will move outside of
// the playing area. 

if (direction == 'E' && convertAction[1] < MAX-1 ||
    direction == 'e' && convertAction[1] < MAX-1)
{
 if (solitaireBoard[convertAction[0]][convertAction[1]+1] == 2)
 { // You cannot jump over the special peg.
 errorNumber = 4;
 errorList(errorNumber);
 }
 else if (solitaireBoard[convertAction[0]][convertAction[1]+1] == 0)
 { // If there is no peg adjacent to the direction specified
   // then show the appropriate error message. 
 errorNumber = 2 ;
 errorList(errorNumber) ;
 }
 else if (solitaireBoard[convertAction[0]][convertAction[1]+2] == 1)
 { // If there is a peg already in the location that the user has 
   // attempted to move to, then show the appropriate error message.
 errorNumber = 3 ;
 errorList(errorNumber) ;
 }
 else
 {
 // Move the peg to the desired location on the board.
 if (solitaireBoard[convertAction[0]][convertAction[1]] == 2)
 {
 specialPegCount++;
 solitaireBoard[convertAction[0]][convertAction[1]+2] = 2;
 // If the special peg has been moved 3 times, delete it
 // from the board.
  if (specialPegCount > 2)
  {
  solitaireBoard[convertAction[0]][convertAction[1]+2] = 0;
  }
 }
 else
 {
 solitaireBoard[convertAction[0]][convertAction[1]+2] = 1;
 }
 // Remove the peg that has been jumped over from the board.
 solitaireBoard[convertAction[0]][convertAction[1]+1] = 0;
 // Removes the peg from the players current position.
 solitaireBoard[convertAction[0]][convertAction[1]] = 0;
 }

}

// This if statement will only operate if the user has indicated
// they wish to move West by entering 'W' or 'w' after the peg
// selection stage. The user will be prompted with an error
// message if moving West means the peg will move outside of
// the playing area. 
else if (direction == 'W' && convertAction[1] > 0 ||
         direction == 'w' && convertAction[1] > 0)
{
 if (solitaireBoard[convertAction[0]][convertAction[1]-1] == 2)
 { // You cannot jump over the special peg.
 errorNumber = 4;
 errorList(errorNumber);
 }
 else if (solitaireBoard[convertAction[0]][convertAction[1]-1] == 0)
 { // If there is no peg adjacent to the direction specified
   // then show the appropriate error message. 
 errorNumber = 2 ;
 errorList(errorNumber) ;
 }
 else if (solitaireBoard[convertAction[0]][convertAction[1]-2] == 1)
 { // If there is a peg already in the location that the user has 
   // attempted to move to, then show the appropriate error message.
 errorNumber = 3 ;
 errorList(errorNumber) ;
 }
 else
 {
 // Move the peg to the desired location on the board.
 if (solitaireBoard[convertAction[0]][convertAction[1]] == 2)
 {
 specialPegCount++;
 solitaireBoard[convertAction[0]][convertAction[1]-2] = 2;
 // If the special peg has been moved 3 times, delete it
 // from the board.
  if (specialPegCount > 2)
  {
  solitaireBoard[convertAction[0]][convertAction[1]-2] = 0;
  }
 }
 else
 {
 solitaireBoard[convertAction[0]][convertAction[1]-2] = 1;
 }
 // Remove the peg that has been jumped over from the board.
 solitaireBoard[convertAction[0]][convertAction[1]-1] = 0;
 // Removes the peg from the players current position.
 solitaireBoard[convertAction[0]][convertAction[1]] = 0;
 }

}

// This if statement will only operate if the user has indicated
// they wish to move South by entering 'S' or 's' after the peg
// selection stage. The user will be prompted with an error
// message if moving South means the peg will move outside of
// the playing area. 
else if (direction == 'S' && convertAction[0] > 0 ||
         direction == 's' && convertAction[0] > 0)
{
 if (solitaireBoard[convertAction[0] - 1][convertAction[1]] == 2)
 { // You cannot jump over the special peg.
 errorNumber = 4;
 errorList(errorNumber);
 }
 else if (solitaireBoard[convertAction[0]-1][convertAction[1]] == 0)
 { // If there is no peg adjacent to the direction specified
   // then show the appropriate error message. 
 errorNumber = 2 ;
 errorList(errorNumber) ;
 }
 else if (solitaireBoard[convertAction[0]-2][convertAction[1]] == 1)
 { // If there is a peg already in the location that the user has 
   // attempted to move to, then show the appropriate error message.
 errorNumber = 3 ;
 errorList(errorNumber) ;
 }
 else
 {
 // Move the peg to the desired location on the board.
 if (solitaireBoard[convertAction[0]][convertAction[1]] == 2)
 {
 specialPegCount++;
 solitaireBoard[convertAction[0]-2][convertAction[1]] = 2;
 // If the special peg has been moved 3 times, delete it
 // from the board.
  if (specialPegCount > 2)
  {
  solitaireBoard[convertAction[0]-2][convertAction[1]] = 0;
  }
 }
 else
 {
 solitaireBoard[convertAction[0]-2][convertAction[1]] = 1;
 }
 // Remove the peg that has been jumped over from the board.
 solitaireBoard[convertAction[0]-1][convertAction[1]] = 0;
 // Removes the peg from the players current position.
 solitaireBoard[convertAction[0]][convertAction[1]] = 0;
 }
}

// This if statement will only operate if the user has indicated
// they wish to move North by entering 'N' or 'n' after the peg
// selection stage. The user will be prompted with an error
// message if moving North means the peg will move outside of
// the playing area. 
else if (direction == 'N' && convertAction[0] < MAX-1 ||
         direction == 'n' && convertAction[0] < MAX-1)
{
 if (solitaireBoard[convertAction[0]+1][convertAction[1]] == 2)
 { // You cannot jump over the special peg.
 errorNumber = 4;
 errorList(errorNumber);
 }
 else if (solitaireBoard[convertAction[0]+1][convertAction[1]] == 0)
 { // If there is no peg adjacent to the direction specified
   // then show the appropriate error message. 
 errorNumber = 2 ;
 errorList(errorNumber) ;
 }
 else if (solitaireBoard[convertAction[0]+2][convertAction[1]] == 1)
 { // If there is a peg already in the location that the user has 
   // attempted to move to, then show the appropriate error message.
 errorNumber = 3 ;
 errorList(errorNumber) ;
 }
 else
 {
  // Move the peg to the desired location on the board.
  if (solitaireBoard[convertAction[0]][convertAction[1]] == 2)
  {
  specialPegCount++ ;
  solitaireBoard[convertAction[0]+2][convertAction[1]] = 2 ;
   // If the special peg has been moved 3 times, delete it
   // from the board.
   if (specialPegCount > 2)
   {
   solitaireBoard[convertAction[0]+2][convertAction[1]] = 0 ;
   }
  }
  else
  {
  solitaireBoard[convertAction[0]+2][convertAction[1]] = 1 ;
  }
  // Remove the peg that has been jumped over from the board.
  solitaireBoard[convertAction[0]+1][convertAction[1]] = 0 ;
  // Removes the peg from the players current position.
  solitaireBoard[convertAction[0]][convertAction[1]] = 0;
  }
}
else
{
errorNumber = 1 ;
errorList(errorNumber) ;
}
} // doPlayerMove



void playerMove (char action[], // *In*
                 int convertAction[], // *In-Out*
                 char &direction, // *In*
                 int MAX, // *In*
                 int solitaireBoard[][5], // *In*
                 int errorNumber, // *In*
                 int &gameRunning, // *In-Out*
                 int board[][5], // *In-Out*
                 int &highScore, // *In-Out*
				 int specialPeg1, // *In-Out*
				 int specialPeg2, // *In-Out*
				 int &specialPegCount) // *In-Out*
{ // The 'playerMove' subprogram deals mainly with the 'cin' instruction
  // and trying to ensure the player has entered the correct parameters.
  // The user will enter which peg they wish to move by writing in the
  // format "number,number" followed by N,S,E,W to move the peg in that
  // direction. This has to be marshalled to make sure they do not enter
  // an illegal command, such as a peg that does not exist or entering a
  // position that doesn’t belong to the board.

do
{
cout << "Enter the position of the peg you wish to move: " ;
cin >> action ;

// Converts the numbers entered as character into a number so we can
// run checks on entry validity.
convertAction[0] = action[0] - '1' ;
convertAction[1] = action[2] - '1' ;

 // If the user decides that they cannot make any more moves, or if they
 // wish to end the game early, then can enter "0,0" to signal the end of
 // the round.

 if(!cin || convertAction[0] < -1 || convertAction[1] < -1 || 
            convertAction[0] > MAX-1 || convertAction[1] > MAX-1 ||
            solitaireBoard[convertAction[0]][convertAction[1]] == 0)
 { // If the player somehow enters an input value that the game is not
   // expecting, then the game will let the player know they need to make
   // a different choice. 
 cout << "You've entered an invalid position on the board." << endl ;
 cin.clear();             // Clear whatever was entered into the input.
 cin.ignore(999, '\n');   // Ignore anything in the stream.
 }
 else
 {
  if (convertAction[0] == -1 && convertAction[1] == -1)
  {
	  gameOver(solitaireBoard, MAX, gameRunning, board, highScore, 
		       specialPeg1, specialPeg2, specialPegCount);
  }
 }
}
while (convertAction[0] < -1 || convertAction[1] < -1 ||
       convertAction[0] > MAX-1 || convertAction[1] > MAX-1 ||
       solitaireBoard[convertAction[0]][convertAction[1]] == 0);

if (convertAction[0] > -1 && convertAction[1] > -1)
{
do
{
cout << "In which direction would you like to move the peg " ;
cout << convertAction[0]+1 << "," << convertAction[1]+1 << "?: " ;
cin >> direction ;

 if(!cin || direction != 'N' && direction != 'n' && 
            direction != 'E' && direction != 'e' &&
            direction != 'S' && direction != 's' &&
            direction != 'W' && direction != 'w' &&
            direction != 'Q' && direction != 'q')
 { // If the player somehow enters an input value that the game is not
   // expecting, then the game will let the player know they need to make
   // a different choice. 
 cout << "You've entered an invalid direction." << endl ;
 cin.clear();             // Clear whatever was entered into the input.
 cin.ignore(999, '\n');   // Ignore anything in the stream.
 }
 else
 {
  // If the player has entered 'Q/q' then we'll recall the subprogram
  // so that they can remake their choice.
  if (direction == 'Q' || direction == 'q')
  {
  playerMove(action, convertAction, direction, MAX, solitaireBoard,
             errorNumber, gameRunning, board, highScore,
			 specialPeg1, specialPeg2, specialPegCount);
  }
  else
  {
  doPlayerMove(convertAction, direction, MAX, solitaireBoard, errorNumber,
			   gameRunning, specialPegCount);
  }
 }
}
while (direction != 'N' && direction != 'n' && 
       direction != 'E' && direction != 'e' &&
       direction != 'S' && direction != 's' &&
       direction != 'W' && direction != 'w');
}
} // playerMovePegSelection



void main () // *In*
{

// Initialise our variables.
srand((unsigned)time(NULL)); // Select a randomised number.
const int MAX = 5 ;
int board[MAX][MAX] = {{1,1,1,1,1},
                       {1,1,1,1,1},
                       {1,1,0,1,1},
                       {1,1,1,1,1},
                       {1,1,1,1,1}} ;
int specialPeg1 = rand() % 4 ;
int specialPeg2 = rand() % 4 ; 
int specialPegCount = 0 ; // Counts how many times the special peg has moved.
int solitaireBoard[MAX][MAX] ;
char action[10] ;
int convertAction[10] ;
char direction ;
int errorNumber = 0 ;
int gameRunning = 0 ;
int highScore = 0 ;

// Prints out the title card and the rules for the game. It's worth noting
// that these rules will only be shown once upon the games launch and will
// not be shown again afterwards, should the player play more than one
// game.

cout << R"(
      _____            __      ____     ___ __       _        
     / __(_)_ _  ___  / /__   / __/__  / (_) /____ _(_)______ 
    _\ \/ /  ' \/ _ \/ / -_) _\ \/ _ \/ / / __/ _ `/ / __/ -_)
   /___/_/_/_/_/ .__/_/\__/ /___/\___/_/_/\__/\_,_/_/_/  \__/ 
              /_/                                             )"
<< endl ;
cout << endl ;

// Show the user the rules of the game.
cout << "The aim of the game is to remove as many pegs from the " ;
cout << "playing" << endl ;
cout << "surface as you can. To do this, you should type in which " ;
cout << "peg" << endl ;
cout << "you wish to move by entering the co-ordinates. " ;
cout << "The bottom left" << endl ;
cout << "peg is considered to be '1,1' whilst the top right is " ;
cout << "'5,5'." << endl ;
cout << endl ;
cout << "Next you will be prompted to enter a direction you " ;
cout << "wish the peg" << endl ;
cout << "to be moved in by entering one of 'N,S,E,W.' " ;
cout << "There are a few" << endl ;
cout << "instances when this can be invalid. For example, " ;
cout << "you cannot move" << endl ;
cout << "a peg from the confinements of the playing surface. " ;
cout << "You cannot" << endl ;
cout << "move a peg in a direction where there is no adjacent " ;
cout << "peg, and you" << endl ;
cout << "cannot move a peg in a direction where a peg is " ;
cout << "already present." << endl ;
cout << endl ;
cout << "If you feel there are no longer any possible moves, " ;
cout << "you can enter" << endl ;
cout << "'0,0' to end the round and caclulate your points. " ;
cout << "Alternatively," << endl ;
cout << "if you change your mind about a peg, you can " ;
cout << "enter 'Q' on the" << endl ;
cout << "movement stage to re-select your peg." << endl ;
cout << endl ;

// Setup the playing surface.
setup(board, solitaireBoard, MAX, specialPeg1, specialPeg2, specialPegCount);

while (gameRunning == 0)
{

// This'll print the solitaire board out. NOTE: For the players sake, we
// won't be printing 0 and 1. Who wants to look at that? Instead,
// we'll be using O for pegs and fullstops (.) for empty spaces.
// The board will also be reversed horizontally, so that it's easier to
// map the bottom left peg as 1,1 as opposed to 5,1.

for (int i = MAX-1; i >= 0; i--)
{
 for (int x = 0; x < MAX; x++)
 {
  if (solitaireBoard[i][x] == 0)
  { // This'll definte the pegs by characters rather than numbers.
  cout << "." << " " ;
  }
  else if (solitaireBoard[i][x] == 2)
  {
  cout << "*" << " " ;
  }
  else
  {
  cout << "O" << " " ;
  }
 }
 cout << endl ;
}
cout << endl ;

// The users action.
playerMove(action, convertAction, direction, MAX, solitaireBoard,
           errorNumber, gameRunning, board, highScore,
		   specialPeg1, specialPeg2, specialPegCount);

}

} // main
