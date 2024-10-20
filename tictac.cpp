#include <iostream>
#include <ctime>
#include <random>

using namespace std;

char board[9] = {' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' '};

void show_board();

void get_x_player();

void get_y_player();

void get_computer_choice();

int countBoard (char symbol);

char checkWinner();

void computer_vs_player();

void player_vs_player();


int main(){
//    show_board();
//      computer_vs_player();

    int mode;
    cout << "1. Computer VS Player." << endl;
    cout << "2. Player VS Player." << endl;
    cout << "Select Game Mode." << endl;
    cin >> mode;

    switch(mode){
        case 1:
            computer_vs_player();
            break;
        case 2:
            player_vs_player();
            break;
        default:
            cout << "Please Select Valid Game Mode." << endl;
            break;
    }
    return 0;
}

void computer_vs_player(){
    string player_name;
    cout << "Enter your name: ";
    cin >> player_name;

    while(true){
        system("cls");
        show_board();
        if (countBoard('X') == countBoard('O')){
            cout << player_name << "'s Turn" << endl;
            get_x_player();
        }
        else{
            get_computer_choice();
        }
        char winner = checkWinner();
        if (winner == 'X'){
            system ("cls") ; // clears screen
            show_board();
            cout << player_name << " Won the Game." << endl;
            break;
        }

        else if(winner == 'O'){
            system("cls");
            show_board();
            cout << "Computer won the Game." << endl;
            break;
        }

        else if (winner == 'D'){
            cout << "Game is Draw." << endl;
            break;
        }
    }
}

void get_computer_choice(){

    srand (time(0));
    int choice;

    do{
        choice = rand()%10;
    }
        while (board[choice] != ' ');
    board [choice] = 'O';

}

void get_x_player() {

    while (true) {
        cout << "Select your position (1-9): ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8){
            cout << "Please select your choice from (1-9) " << endl;
        }
        else if (board[choice] != ' ') {
            cout << "Please select an Empty position." << endl;
        }
        else{
            board[choice] = 'X';
            break;
        }
    }
}

void get_y_player() {

    while (true) {
        cout << "Select your position (1-9): ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8){
            cout << "Please select your choice from (1-9) " << endl;
        }
        else if (board[choice] != ' ') {
            cout << "Please select an Empty position." << endl;
        }
        else{
            board[choice] = 'O';
            break;
        }
    }
}

void player_vs_player () {
    string x_player_name, y_player_name;
    cout << "Enter X Player name: ";
    cin >> x_player_name;
    cout << "Enter O Player name: ";
    cin >> y_player_name;

    while(true) {
        system ("cls");
        show_board();
        if (countBoard('X') == countBoard('O')){
            cout << x_player_name << "'s Turn." << endl;
            get_x_player();
        }
        else{
            cout << y_player_name << "'s Turn." << endl;
            get_y_player();
        }
        char winner = checkWinner();
        if (winner == 'X'){
            system("cls");
            show_board();
            cout << x_player_name << " Won the Game." << endl;
            break;
        }

        else if(winner == 'O'){
            system("cls");
            show_board();
            cout << y_player_name << " Won the Game." << endl;
            break;
        }

        else if(winner == 'D'){
            cout << "Game is draw." << endl;
            break;
        }

    }
}

int countBoard (char symbol){
    int total = 0;
    for (int i=0; i<9; i++){
        if (board[i] == symbol){
            total += 1;

        }
    }
    return total;
}

char checkWinner() {

    //checking winner in horizontal row
    if (board[0] == board[1] and board[1]==board[2] and board[0] != ' ')
        return board[0];
    if (board[3] == board[4] and board[4]==board[5] and board[3] != ' ')
        return board[0];
    if (board[6] == board[7] and board[7]==board[8] and board[6] != ' ')
        return board[0];


    //checking winner in vertical column
    if (board[0] == board[3] and board[3]==board[6] and board[0] != ' ')
        return board[0];
    if (board[1] == board[4] and board[4]==board[7] and board[1] != ' ')
        return board[0];
    if (board[2] == board[5] and board[5]==board[8] and board[2] != ' ')
        return board[0];

    //checking winner in diagonal
    if (board[0] == board[4] and board[4]==board[8] and board[0] != ' ')
        return board[0];
    if (board[2] == board[4] and board[4]==board[6] and board[2] != ' ')
        return board[0];

    if (countBoard('X') + countBoard('O') < 9)
        return 'C';
    else
        return 'D';
}

void show_board (){
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[0] << "  |   "<< board[1] << "  |   "<< board[2] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[3] << "  |   "<< board[4] << "  |   "<< board[5] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[6] << "  |   "<< board[7] << "  |   "<< board[8] << endl;
    cout << "   " << "   |   " << "   |   " << endl;

}
