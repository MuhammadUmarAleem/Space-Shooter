#include<iostream>
#include <windows.h>
#include <conio.h>
#include<fstream>
using namespace std ;
//...........................................Prototypes............................................................
void gotoxy(int x , int y) ;// function to display on console 
void displayboard () ;	// function to display board 
int moveLeft(int sidel);// function to move plane left
int moveRight(int sidel);// function to move plane right
void moveUP(int sidel);// function to move plane up
void moveDown(int sidel);// function to move plane down
void fire(int gamecount) ;// function to fire 
void movefires (int gamecount) ;//function to move fires 
void aliegns1() ; // function to display first alien waves
void aliegns1fire(int gamecount) ;// function to fire of aliens1 and 2
void aliegns1movefires() ;// function to move fire of aliens1 and 2
void check1 (int gamecount) ;// function to check alien destroy or not 
void aliegns2() ;// function to display second alien waves
int scorecalculator1(int score) ;// function to calculate score of 1st and 2nd wave 
void aliegn3fires() ;// function to fire of aliens3
void aliegns3movefires() ;// function to move fire of aliens3
int scorecalculator2(int score) ;// function to calculate score after destroying alien3
bool aliegns3(bool flag) ;// function to display aliens 3
void WelcomeMessage() ;// function to print logo 
void check3 () ;// function to check alien3 is live or not 
void livescheck () ;// function to check lives of plane 
void displayscore(int score , int gamecount) ;// function to display score
int increaselives (int additionalcount) ;// function to increase lives 
int livescount (int livescount1 ) ;// function to count lives of plane  
void readboard () ;// function to read board 
// initializing of 2D array ................................................................
char board[25][70]  ;
int sided = 23 ;
int aliegnsd = 1 ;
int count = 0 ;
int aliegn1[5] = {0,0,0,0,0} ;
int lives = 3 ;
HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE) ;
main(){
    int livescounts1 = 0 ;
    int additionalcount = 1 ;
    bool flag ;
    int sidel = 31 ;
    int localcount = 0 ;
    int score = 0 ; 
    int gamecount = 0 ;
    system("cls") ;
    readboard() ;
    SetConsoleTextAttribute(h,10) ;
    displayboard() ;
    while (gamecount < 3 || lives <= 0){
        WelcomeMessage() ;
        displayscore(score,gamecount) ;

        Sleep(100) ;
                         SetConsoleTextAttribute(h,6) ;
        // condition to move left of plane ..................................................
             if(GetAsyncKeyState(VK_LEFT)){             
                 sidel = moveLeft(sidel); 
             }
             // condition to move right of plane ...........................................
             if(GetAsyncKeyState(VK_RIGHT)){             
                 sidel = moveRight(sidel); 
             }
             // condition to move up of plane ...............................................
             if(GetAsyncKeyState(VK_UP)){             
                 moveUP(sidel); 
             }
             // condition to move down of plane ................................................
             if(GetAsyncKeyState(VK_DOWN)){                
                 moveDown(sidel); 
             }
             // condition to move fire of plane ...............................................
             if(GetAsyncKeyState(VK_SPACE)){              
                 fire(gamecount) ;
             }
             // condition to exit the game..................................................  
             if(GetAsyncKeyState(VK_ESCAPE)){             
                 gamecount = 3 ; 
             }
             SetConsoleTextAttribute(h,11) ;
             movefires(gamecount) ;
             // condition for 1st wave of aliens...............................................
         if (gamecount == 0){
             SetConsoleTextAttribute(h,4) ;
             aliegns1() ;
             check1 (gamecount) ;
             if (aliegn1[0] >= 3 && aliegn1[1] >= 3 && aliegn1[2] >= 3 && aliegn1[3] >= 3 && aliegn1[4] >= 3 ){
                 gamecount ++ ;
             }
             score = scorecalculator1(score) ;
             aliegns1fire(gamecount) ;
             aliegns1movefires() ;
         }
            // condition for 2nd wave of aliens...............................................
         if (gamecount == 1){
             if (localcount == 0){// condition for intializing variables.......................
                 for (int z = 0 ; z < 5 ; z++){
                     aliegn1[z] = 0 ;
                 }
                 count = 0 ;
                 aliegnsd = 3 ;
                 localcount ++ ;
             } 
             aliegns2() ;
             check1 (gamecount) ;
             additionalcount = increaselives (additionalcount) ;
             livescheck () ;
             livescounts1 = livescount (livescounts1) ;
             if (aliegn1[0] >= 20 && aliegn1[1] >= 20 && aliegn1[2] >= 20 ){
                 gamecount ++ ;
             }
             score = scorecalculator2(score) ;
             aliegns1fire(gamecount) ; 
             aliegns1movefires() ;  
         }
             // condition for 3rd wave of aliens...............................................
         if (gamecount == 2){
             aliegns1movefires() ;
             if (localcount == 1){
                 aliegnsd = 1 ;
                 count = 0 ;
                 localcount++ ;
             }
             if (aliegn1[4] >= 50 ){
                 score = score + 25 ;
                 gamecount ++ ;
             }
             flag = aliegns3(flag) ;
             check3 () ;
             additionalcount = increaselives (additionalcount) ;
             livescheck () ;
             livescounts1 = livescount (livescounts1) ;
             aliegn3fires() ;
             aliegns3movefires() ; 
         }
         livescounts1 = livescount (livescounts1) ;
         if (livescounts1 == 10 || livescounts1 == 20 || livescounts1 == 30){ 
             lives -- ;
             livescounts1 ++ ;
         }
         if (lives <= 0){
             break ;
         }
     }
     system ("cls") ;
     WelcomeMessage() ;
     displayscore(score,gamecount) ;
     if (gamecount == 3){
            gotoxy(20 , 10);cout << "             _____                             "  <<     endl ;
            gotoxy(20 , 11);cout << " ___      ____(_)__________________________    "  <<   endl ;
            gotoxy(20 , 12);cout << " __ | /| / /_  /__  __ \\_  __ \\  _ \\_  ___/    "  <<  endl ; 
            gotoxy(20 , 13);cout << " __ |/ |/ /_  / _  / / /  / / /  __/  /        "  <<   endl ;
            gotoxy(20 , 14);cout << " ____/|__/ /_/  /_/ /_//_/ /_/\\___//_/         "  <<   endl ;  
                            
     }
     if (lives <= 0){
           gotoxy(20 , 10); cout << " ______                                  " << endl ;
            gotoxy(20 , 11);cout << " ___  /_______________________________   " << endl ;
            gotoxy(20 , 12);cout << " __  /_  __ \\  __ \\_  ___/  _ \\_  ___/   " << endl ;
           gotoxy(20 , 13); cout << " _  / / /_/ / /_/ /(__  )/  __/  /       " << endl ;
            gotoxy(20 , 14);cout << " /_/  \\____/\\____//____/ \\___//_/        " << endl ;
    }                            
}  
// function for logo of game ......................................................
void WelcomeMessage()
{ 
    SetConsoleTextAttribute(h,10) ;
int x = 80;
int y = 1;
gotoxy(x, y  ); cout << " _____                    _____ _           _           " << endl ;
gotoxy(x, y+1); cout << "|   __|___ ___ ___ ___   |   __| |_ ___ ___| |_ ___ ___ " << endl ;
gotoxy(x, y+2); cout << "|__   | . | .'|  _| -_|  |__   |   | . | . |  _| -_|  _|" << endl ;
gotoxy(x, y+3); cout << "|_____|  _|__,|___|___|  |_____|_|_|___|___|_| |___|_|  " << endl ;
gotoxy(x, y+4); cout << "      |_|" << endl ;
gotoxy(x, y+5); cout << "--------------------------------------------------------" << endl ;
}
// function for display score .................................................
void displayscore(int score , int gamecount){
    SetConsoleTextAttribute(h,11) ;
    int x = 100;
    int y = 12;
gotoxy(x, y-5); cout << " ________________ " << endl ;
gotoxy(x, y-4); cout << "|    Wave : " << gamecount + 1 << "    |   " << endl ;
gotoxy(x, y-3); cout << "|________________| " << endl ;
gotoxy(x, y-2); cout << "|    Eat F to    |   " << endl ;
gotoxy(x, y-1); cout << "| increase lives |" << endl ;
gotoxy(x, y  ); cout << "|________________|" << endl ;
gotoxy(x, y+1); cout << "|  Press Escape  |   " << endl ;
gotoxy(x, y+2); cout << "|  to exit game  |" << endl ;
gotoxy(x, y+3); cout << "|________________|" << endl ;
gotoxy(x, y+4); cout << "| Press Space to |   " << endl ;
gotoxy(x, y+5); cout << "|fire the  aliens|" << endl ;
gotoxy(x, y+6); cout << "|________________|" << endl ;
gotoxy(x, y+7); cout << "|     Total      |" << endl ;
gotoxy(x, y+8); cout << "|   Lives : 3    |" << endl ;
gotoxy(x, y+9); cout << "|________________|" << endl ;
gotoxy(x, y+10); cout << "|   Remaining    |" << endl ;
gotoxy(x, y+11); cout << "|   Lives : " << lives << "    |" << endl ;
gotoxy(x, y+12); cout << "|________________|" << endl ;
gotoxy(x, y+13); cout << "|   Score : " << score << "   |" << endl ;
gotoxy(x, y+14); cout << "|________________|" << endl ;
}
// function for display board.........................................................
void displayboard(){
        for (int z = 0 ; z < 25 ; z++){
            for (int y = 0 ; y < 70; y++){
                gotoxy(y,z) ;
                cout << board [z][y] ;
            }
            cout << endl ;
        }
}
// function for display on specific area of console...................................
void gotoxy(int x, int y)
{  COORD coordinates;
  coordinates.X = x;
coordinates.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates); 
 }
// function to move left of plane ...................................................
int moveLeft(int sidel){
    if (sidel>3){
        sidel = sidel - 1 ;
        gotoxy(sidel ,sided) ;
        cout << "(" ;
        gotoxy(sidel+1,sided) ;
        cout << "(" ;
        gotoxy(sidel+2,sided) ;
        cout << "o" ;
        gotoxy(sidel+3,sided) ;
        cout << ")" ;
        gotoxy(sidel+4,sided) ;
        cout << ")" ;
        gotoxy(sidel+5,sided) ;
        cout << " " ;
        gotoxy(sidel+1,sided-1) ;
        cout << "/" ;
        gotoxy(sidel+2,sided-1) ;
        cout << "|" ;
        gotoxy(sidel+3,sided-1) ;
        cout << "\\" ;
        gotoxy(sidel+4,sided-1) ;
        cout << " " ;
        board  [sided] [sidel] = '(' ;
        board  [sided] [sidel+1]= '(' ;
        board  [sided] [sidel+2]= 'o' ;
        board  [sided] [sidel+3] = ')' ;
        board  [sided] [sidel+4]= ')' ;
        board  [sided] [sidel+5]= ' ' ;
        board  [sided-1] [sidel+1] = '/' ;
        board  [sided-1] [sidel+2]= '|' ;
        board  [sided-1] [sidel+3] = '\\' ;
        board  [sided-1] [sidel+4] = ' ' ;
    }
    return sidel ;
}
// function to move right of plane ...................................................
int moveRight(int sidel){
    if (sidel+4<=64){
        sidel = sidel + 1 ;
        gotoxy(sidel,sided) ;
        cout << "(" ;
        gotoxy(sidel+1,sided) ;
        cout << "(" ;
        gotoxy(sidel+2,sided) ;
        cout << "o" ;
        gotoxy(sidel+3,sided) ;
        cout << ")" ;
        gotoxy(sidel+4,sided) ;
        cout << ")" ;
        gotoxy(sidel-1,sided) ;
        cout << " " ;
        gotoxy(sidel+1,sided-1) ;
        cout << "/" ;
        gotoxy(sidel+2,sided-1) ;
        cout << "|" ;
        gotoxy(sidel+3,sided-1) ;
        cout << "\\" ;
        gotoxy(sidel,sided-1) ;
        cout << " " ;
        board  [sided] [sidel+4] = ')' ;
        board  [sided] [sidel+3]= ')' ;
        board  [sided] [sidel+2]= 'o' ;
        board  [sided] [sidel+1] = '(' ;
        board  [sided] [sidel]= '(' ;
        board  [sided] [sidel-1]= ' ' ;
        board  [sided-1] [sidel+3] = '\\' ;
        board  [sided-1] [sidel+2]= '|' ;
        board  [sided-1] [sidel+1] = '/' ;
        board  [sided-1] [sidel] = ' ' ;
    }
    return sidel ;
}
// function to move up of plane ...................................................
void moveUP(int sidel){
    
    if (sided>2){
            sided = sided-1 ;
        gotoxy(sidel,sided) ;
        cout << "(" ;
        gotoxy(sidel+1,sided) ;
        cout << "(" ;
        gotoxy(sidel+2,sided) ;
        cout << "o" ;
        gotoxy(sidel+3,sided) ;
        cout << ")" ;
        gotoxy(sidel+4,sided) ;
        cout << ")" ;
        gotoxy(sidel+1,sided-1) ;
        cout << "/" ;
        gotoxy(sidel+2,sided-1) ;
        cout << "|" ;
        gotoxy(sidel+3,sided-1) ;
        cout << "\\" ;
        gotoxy(sidel,sided+1) ;
        cout << " " ;
        gotoxy(sidel+1,sided+1) ;
        cout << " " ;
        gotoxy(sidel+2,sided+1) ;
        cout << " " ;
        gotoxy(sidel+3,sided+1) ;
        cout << " " ;
        gotoxy(sidel+4,sided+1) ;
        cout << " " ;
        board[sided-1][sidel+1] = '/';
        board[sided-1][sidel+2] = '|';
        board[sided-1][sidel+3] = '\\';
        board[sided][sidel] = '(';
        board[sided][sidel+1] = '(';
        board[sided][sidel+2] = 'o';
        board[sided][sidel+3] = ')';
        board[sided][sidel+4] = ')';
        board[sided+1][sidel] = ' ';
        board[sided+1][sidel+1] = ' ';
        board[sided+1][sidel+2] = ' ';
        board[sided+1][sidel+3] = ' ';
        board[sided+1][sidel+4] = ' '; 
    }
}
// function to move down of plane ...................................................
void moveDown(int sidel){
    
    if (sided<23){
            sided = sided+1 ;
            gotoxy(sidel,sided) ;
        cout << "(" ;
        gotoxy(sidel+1,sided) ;
        cout << "(" ;
        gotoxy(sidel+2,sided) ;
        cout << "o" ;
        gotoxy(sidel+3,sided) ;
        cout << ")" ;
        gotoxy(sidel+4,sided) ;
        cout << ")" ;
        gotoxy(sidel+1,sided-1) ;
        cout << "/" ;
        gotoxy(sidel+2,sided-1) ;
        cout << "|" ;
        gotoxy(sidel+3,sided-1) ;
        cout << "\\" ;
        gotoxy(sidel,sided-1) ;
        cout << " " ;
        gotoxy(sidel+4,sided-1) ;
        cout << " " ;
        gotoxy(sidel+1,sided-2) ;
        cout << " " ;
        gotoxy(sidel+2,sided-2) ;
        cout << " " ;
        gotoxy(sidel+3,sided-2) ;
        cout << " " ;
        board[sided][sidel] = '(';
        board[sided][sidel+1] = '(';
        board[sided][sidel+2] = 'o';
        board[sided][sidel+3] = ')';
        board[sided][sidel+4] = ')';
        board[sided-1][sidel+1] = '/';
        board[sided-1][sidel+2] = '|';
        board[sided-1][sidel+3] = '\\';
        board[sided-1][sidel] = ' ';
        board[sided-1][sidel+4] = ' ';
        board[sided-2][sidel] = ' ';
        board[sided-2][sidel+1] = ' ';
        board[sided-2][sidel+3] = ' ';
    }
}
// function for firing of plane ..............................................
void fire(int gamecount){
    SetConsoleTextAttribute(h,11) ;  
    for (int z = 0 ; z < 25 ; z++){
        for (int y = 3 ; y < 66 ; y++){
            if ( board [z][y] == '|' && board [z][y-1] == '/' && board [z][y+1] == '\\'){
                gotoxy(y,z-1) ;
                cout << "^" ;
                board [z-1][y] = '^' ;
                if (gamecount == 1){
                    gotoxy(y-1,z-1) ;
                    cout << "^" ;
                    board [z-1][y-1] = '^' ;
                } 
                if (gamecount == 2){
                    gotoxy(y-1,z-1) ;
                    cout << "^" ;
                    board [z-1][y-1] = '^' ;
                    gotoxy(y+1,z-1) ;
                    cout << "^" ;
                    board [z-1][y+1] = '^' ;
                } 
            }
        }
    }
    SetConsoleTextAttribute(h,10) ;  
}
// function for moving fire of plane ................................................
void movefires(int gamecount){
    for (int z = 1 ; z < 22 ; z++){
        for (int y = 3 ; y < 70 ; y++){
            if ( board [z][y] == '^'){
                if (z==1){
                    gotoxy(y,z) ;
                    cout << " " ;
                    board [z][y] = ' ' ;
                }
                if (z>1){
                    gotoxy(y,z-1) ;
                    cout << "^" ;
                    board [z-1][y] = '^' ;
                    gotoxy(y,z) ;
                    cout << " " ;
                    board [z][y] = ' ' ;
                }
            }
        }
    }
}
// function to display 1st wave of aleiens................................................
void aliegns1(){
    int localcount1 = 0 ;
    int aliegnsl = 9 ;
    if (count % 10 == 0){
        if (aliegnsd < 9){
            for (int z = aliegnsl ; z < 65 ; z = z + 12){
                if (aliegn1[localcount1] < 3){
                    if (aliegnsd > 1){
                        gotoxy(z-1,aliegnsd-2) ;
                        cout << " " ;
                    board [aliegnsd-2][z-1] = ' ' ;
                        gotoxy(z,aliegnsd-2) ;
                        cout << " " ;
                    board [aliegnsd-2][z] = ' ' ;
                        gotoxy(z+1,aliegnsd-2) ;
                        cout << " " ;
                    board [aliegnsd-2][z+1] = ' ' ;
                    }
                gotoxy(z,aliegnsd) ;
                cout << "*" ;
                board [aliegnsd][z] = '*' ;
                gotoxy(z-1,aliegnsd-1) ;
                cout << "*" ;
                board [aliegnsd-1][z-1] = '*' ;
                gotoxy(z,aliegnsd-1) ;
                cout << "*" ;
                board [aliegnsd-1][z] = '*' ;
                 gotoxy(z+1,aliegnsd-1) ;
                cout << "*" ;
                board [aliegnsd-1][z+1] = '*' ;
                }
                localcount1++ ;
            }
        aliegnsd = aliegnsd + 1 ;
        }
    }
    localcount1 = 0 ;
        if (aliegnsd <= 9){
            for (int y = aliegnsl ; y < 65 ; y = y + 12){
                if (aliegn1[localcount1] < 3){
                gotoxy(y,aliegnsd-1) ;
                cout << "*" ;
                board [aliegnsd-1][y] = '*' ;
                gotoxy(y-1,aliegnsd-2) ;
                cout << "*" ;
                board [aliegnsd-2][y-1] = '*' ;
                gotoxy(y,aliegnsd-2) ;
                cout << "*" ;
                board [aliegnsd-2][y] = '*' ;
                gotoxy(y+1,aliegnsd-2) ;
                cout << "*" ;
                board [aliegnsd-2][y+1] = '*' ;
                }
                localcount1 ++ ;
            }
        }
    count ++ ;
}
// function to firing 1st and 2nd wave of aleiens................................................
void aliegns1fire(int gamecount){
    int z ;
    if (gamecount == 0){
        z = 10 ;
    }
    if (gamecount == 0){
        z = 5 ;
    }
if (count % z == 0){
    for (int z = 0 ; z < 25 ; z++){
        for (int y = 3 ; y < 66 ; y++){
            if ( board [z][y] == '*'){
                if (board [z][y-1] != '*' && board [z][y+1] != '*' && board [z][y-2] != '*' && board [z][y+2] != '*'){
                    gotoxy(y,z+1) ;
                    cout << "." ;
                    board [z+1][y] = '.' ; 
                }
            }
        }
    }
}
}
// function to move firing 1st and 2nd  wave of aleiens................................................
void aliegns1movefires(){
    for (int z = 23 ; z > 1 ; z--){
        for (int y = 3 ; y < 70 ; y++){
            if ( board [z][y] == '.'){
                if (z==23){
                    gotoxy(y,z) ;
                    cout << " " ;
                    board [z][y] = ' ' ;
                }
                if (z>1 && z<23){
                    if (board [z+2][y] == ' ' ){
                            gotoxy(y,z+1) ;
                            cout << "." ;
                        board [z+1][y] = '.' ;
                            gotoxy(y,z) ;
                            cout << " " ;
                        board [z][y] = ' ' ;
                    }
                    if (board [z+2][y] != ' ' ){
                        gotoxy(y,z+1) ;
                        cout << " " ;
                        board [z+1][y] = ' ' ;
                        gotoxy(y,z) ;
                            cout << " " ;
                        board [z][y] = ' ' ;
                    }
                }
            }
        }
    }
}
// function to check 1st and 2nd  wave of aleiens are live or not..........................
void check1 (int gamecount){
    int num = 0 ;
    int localcount1 ;
    int localcount ;
    if (gamecount == 0){
        localcount = 3 ;
        localcount1 = 12 ;
    }
    if (gamecount == 1){
        localcount = 20 ;
        localcount1 = 24 ;
    }
    for (int a = 6 ; a < 65 ; a = a + localcount1){
        for (int z = a ; z <= a+5 ; z++){
            for (int y = 1 ; y < 24 ; y++){
                if (board [y][z] == '*'){
                    if (board [y+1][z] == '^'){
                        aliegn1[num]++ ;
                    }
                    if (aliegn1[num] >= localcount){
                        for (int x = (num * 8) + 5 ; x <= ((num * 8) + 12); x++ ){
                            for (int y = 1 ; y < 10 ; y++){
                                    gotoxy(z,y) ;
                                    cout << " " ;
                                    board [y][z] = ' ' ;
                            }
                        }
                    }
                }
            }
        }
        num ++ ;
    }
}
// function to display 2nd wave of aleiens................................................
void aliegns2(){
    int localcount1 = 0 ;
    int aliegnsl = 9 ;
    if (count % 10 == 0){
        if (aliegnsd < 9){
            for (int z = aliegnsl ; z < 65 ; z = z + 24){
                if (aliegn1[localcount1] < 20){
                    if (aliegnsd > 1){
                        gotoxy(z-1,aliegnsd-3) ;
                        cout << " " ;
                    board [aliegnsd-3][z-1] = ' ' ;
                        gotoxy(z,aliegnsd-3) ;
                        cout << " " ;
                    board [aliegnsd-3][z] = ' ' ;
                        gotoxy(z+1,aliegnsd-3) ;
                        cout << " " ;
                    board [aliegnsd-3][z+1] = ' ' ;
                        gotoxy(z+2,aliegnsd-3) ;
                        cout << " " ;
                    board [aliegnsd-3][z+2] = ' ' ;
                        gotoxy(z-2,aliegnsd-3) ;
                        cout << " " ;
                    board [aliegnsd-3][z-2] = ' ' ;
                    }
                gotoxy(z,aliegnsd) ;
                cout << "*" ;
                board [aliegnsd][z] = '*' ;
                gotoxy(z-1,aliegnsd-1) ;
                cout << "*" ;
                board [aliegnsd-1][z-1] = '*' ;
                gotoxy(z,aliegnsd-1) ;
                cout << "*" ;
                board [aliegnsd-1][z] = '*' ;
                 gotoxy(z+1,aliegnsd-1) ;
                cout << "*" ;
                board [aliegnsd-1][z+1] = '*' ;
                gotoxy(z-1,aliegnsd-2) ;
                cout << "*" ;
                board [aliegnsd-2][z-1] = '*' ;
                gotoxy(z,aliegnsd-2) ;
                cout << "*" ;
                board [aliegnsd-2][z] = '*' ;
                 gotoxy(z+1,aliegnsd-2) ;
                cout << "*" ;
                board [aliegnsd-2][z+1] = '*' ;
                gotoxy(z-2,aliegnsd-2) ;
                cout << "*" ;
                board [aliegnsd-2][z-2] = '*';
                 gotoxy(z+2,aliegnsd-2) ;
                cout << "*" ;
                board [aliegnsd-2][z+2] = '*' ;
                }
                localcount1++ ;
            }
        aliegnsd = aliegnsd + 1 ;
        }
    }
    localcount1 = 0 ;
        if (aliegnsd <= 9){
            for (int y = aliegnsl ; y < 65 ; y = y + 24){
                if (aliegn1[localcount1] < 20){
                gotoxy(y,aliegnsd-1) ;
                cout << "*" ;
                board [aliegnsd-1][y] = '*' ;
                gotoxy(y-1,aliegnsd-2) ;
                cout << "*" ;
                board [aliegnsd-2][y-1] = '*' ;
                gotoxy(y,aliegnsd-2) ;
                cout <<"*";
                board [aliegnsd-2][y] = '*' ;
                gotoxy(y+1,aliegnsd-2) ;
                cout << "*" ;
                board [aliegnsd-2][y+1] = '*' ;
                gotoxy(y-1,aliegnsd-3) ;
                cout << "*" ;
                board [aliegnsd-3][y-1] = '*' ;
                gotoxy(y,aliegnsd-3) ;
                cout << "*" ;
                board [aliegnsd-3][y] = '*' ;
                 gotoxy(y+1,aliegnsd-3) ;
                cout << "*" ;
                board [aliegnsd-3][y+1] = '*' ;
                gotoxy(y-2,aliegnsd-3) ;
                cout << "*" ;
                board [aliegnsd-3][y-2] = '*' ;
                 gotoxy(y+2,aliegnsd-3) ;
                cout << "*" ;
                board [aliegnsd-3][y+2] = '*' ;
                }
                localcount1 ++ ;
            }
        }
    count ++ ;
}
// function to calculate score after 1st wave of aliens......................................
int scorecalculator1(int score){
    score = 0 ;
    for (int z = 0 ; z < 5 ; z++){
       if (aliegn1[z] >= 3){
           score = score + 5 ;
       }
    }
    return score ; 
}
// function to calculate score after 2nd wave of aliens......................................
int scorecalculator2(int score){
    score = 25 ;
    for (int z = 0 ; z < 3 ; z++){
       if (aliegn1[z] >= 20){
           score = score + 10 ;
       }
    }
    return score ; 
}
// function to display aliens3 ...............................................................
bool aliegns3(bool flag){

    int z = 33 ;
     if (count % 10 == 0){
        if (aliegnsd <= 9){
            if (aliegn1[4] < 50){
            board[aliegnsd][z] = '#' ;
            gotoxy(z,aliegnsd) ;
            cout << "#" ;
            board[aliegnsd][z+1] = '#' ;
            gotoxy(z+1,aliegnsd) ;
            cout << "#" ;
            board[aliegnsd][z+2] = '#' ;
            gotoxy(z+2,aliegnsd) ;
            cout << "#" ;
            board[aliegnsd][z+3] = '#' ;
            gotoxy(z+3,aliegnsd) ;
            cout << "#" ;
            board[aliegnsd][z+4] = '#' ;
            gotoxy(z+4,aliegnsd) ;
            cout << "#" ;
            board[aliegnsd+1][z+1] = '#' ;
            gotoxy(z+1,aliegnsd+1) ;
            cout << "#" ;
            board[aliegnsd+1][z+2] = '#' ;
            gotoxy(z+2,aliegnsd+1) ;
            cout << "#" ;
            board[aliegnsd+1][z+3] = '#' ;
            gotoxy(z+3,aliegnsd+1) ;
            cout << "#" ;
            board[aliegnsd+2][z+2] = '#' ;
            gotoxy(z+2,aliegnsd+2) ;
            cout << "#" ;
        
        if (flag == 0 || aliegnsd == 9){
            board[aliegnsd-1][z] = ' ' ;
            gotoxy(z,aliegnsd-1) ;
            cout << " " ;
            board[aliegnsd-1][z+1] = ' ' ;
            gotoxy(z+1,aliegnsd-1) ;
            cout << " " ;
            board[aliegnsd-1][z+2] = ' ' ;
            gotoxy(z+2,aliegnsd-1) ;
            cout << " " ;
            board[aliegnsd-1][z+3] = ' ' ;
            gotoxy(z+3,aliegnsd-1) ;
            cout << " " ;
            board[aliegnsd-1][z+4] = ' ' ;
            gotoxy(z+4,aliegnsd-1) ;
            cout << " " ;
            if (aliegnsd != 9){
                aliegnsd ++ ;
            }  
        }
        if (flag == 1 || aliegnsd == 1){
            board[aliegnsd+1][z+4] = ' ' ;
            gotoxy(z+4,aliegnsd+1) ;
            cout << " " ;
            board[aliegnsd+1][z] = ' ' ;
            gotoxy(z,aliegnsd+1) ;
            cout << " " ;
            board[aliegnsd+2][z+3] = ' ' ;
            gotoxy(z+3,aliegnsd+2) ;
            cout << " " ;
            board[aliegnsd+2][z+1] = ' ' ;
            gotoxy(z+1,aliegnsd+2) ;
            cout << " " ;
            board[aliegnsd+3][z+2] = ' ' ;
            gotoxy(z+2,aliegnsd+3) ;
            cout << " " ;
            if (aliegnsd != 1){
                aliegnsd -- ;
            }
        }
       
        if (aliegnsd == 9){
            flag = 1 ;
        }
        if (aliegnsd == 1){
            flag = 0 ;
        }
    }
}
}
    count ++ ;
    return flag ;
}
// function for fire the alien3........................................................
void aliegn3fires(){
    if (count % 10 == 0){
    for (int z = 0 ; z < 25 ; z++){
        for (int y = 3 ; y < 66 ; y++){
            if ( board [z][y] == '#'){
                if (board [z][y+1] != '#' && board [z][y+2] != '#' && board [z][y-1] != '#' && board [z][y-2] != '#' ){
                    gotoxy(y,z+1) ;
                    cout << "!" ;
                    board [z+1][y] = '!' ;
                }
            }
        }
    }
    }
}
// function for move fire the alien3.........................................
void aliegns3movefires(){
    for (int z = 23 ; z > 1 ; z--){
        for (int y = 3 ; y < 70 ; y++){
            if ( board [z][y] == '!'){
                if (z==23){
                    gotoxy(y,z) ;
                    cout << " " ;
                    board [z][y] = ' ' ;
                }
                if (z>1 && z<23){
                    gotoxy(y,z+1) ;
                    cout << "!" ;
                board [z+1][y] = '!' ;
                    gotoxy(y,z) ;
                    cout << " " ;
                board [z][y] = ' ' ;
                }
            }
        }
    }
}
// function for check the alien3 is live or not.........................................
void check3 (){
    for (int z = 33 ; z <= 38 ; z++){
        for (int y = 1 ; y < 9 ; y++){
            if (board [y][z] == '#'){
                if (board [y+1][z] == '^'){
                    aliegn1[4]++ ;
                }
                if (aliegn1[4] >= 50){
                    for (int x = 33 ; x <= 38; x++ ){
                        for (int y = 1 ; y < 9 ; y++){
                            gotoxy(z,y) ;
                            cout << " " ;
                            board [y][z] = ' ' ;
                        }
                    }
                }
            }
        }
    }
}
// function to calculate lives of plane ...............................................
int livescount (int livescount1){
    for (int z = 3 ; z <= 68 ; z++){
        for (int y = 1 ; y < 24 ; y++){
            if (board [y][z] == '|' || board [y][z] == '/' || board [y][z] == '\\' ){
                if (board [y-1][z] == '.' || board [y-2][z] == '.' || board [y-3][z] == '.' ){
                    livescount1 ++ ;
                }
                if (board [y-1][z] == '!'){
                    board [y-1][z] == ' ' ;
                    lives -- ;
                }
            }
        }
    }   
    return livescount1 ;
}
// function to increase lives of plane ...............................................
int increaselives (int additionalcount){
    int leftside = 23 ;
    if (additionalcount < 25){
    if (count % 5 == 0){
        if (board [additionalcount][leftside] == ' ' || additionalcount < 23){ 
            board [additionalcount][leftside] = 'F' ;
            gotoxy(leftside,additionalcount) ;
            cout << "F" ;
            board [additionalcount-1][leftside] = ' ' ;
            gotoxy(leftside,additionalcount-1) ;
            cout << " " ;
            additionalcount ++ ;
        }
        if (board [additionalcount][leftside] != ' ' || additionalcount == 23){
            board [additionalcount-1][leftside] = ' ' ;
            gotoxy(leftside,additionalcount-1) ;
            cout << " " ;
            additionalcount = 25 ;
        }
    }
    }
    return additionalcount ;
}
// function to calculate lives of plane ...............................................
void livescheck (){
    for (int z = 3 ; z <= 68 ; z++){
        for (int y = 0 ; y < 24 ; y++){
            if (board [y][z] == '|' || board [y][z] == '/' || board [y][z] == '\\' ){
                if (board [y-1][z] == 'F'){
                    board [y-1][z] == ' ' ;
                    gotoxy(z,y-1) ;
                    cout << " " ;
                    board [y][z] == ' ' ;
                    gotoxy(z,y) ;
                    cout << " " ;
                    lives++ ;
                }
            }
        }
    }
}
// function to read board .............................................................
void readboard(){
    string line;
    fstream file;
    file.open("board.txt", ios::in);
    for (int i = 0; i < 25; i++)
    {
        getline(file, line);
        for (int j = 0; j < 70; j++)
        {
            board[i][j] = line[j];
        }
    }
    file.close();
}