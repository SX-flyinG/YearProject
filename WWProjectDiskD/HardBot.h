
// Fills the given 2D array representing the player's game board with default values.
void fillArray(char polePlayer[11][11]);

// Prints the current state of the given game board.
void PrintPole(char pole[11][11]);

// Places destroyer ships on the player's board.
void PlaceDestroyers(int& letterKey, int& numKey, int destroyer, char polePlayer[11][11]);

// Places a cruiser ship with advanced logic.
void CruiserHard(int letterKey, int numKey, int wayKey, int cruiser, char pole[11][11], int& countOfMatch, int& countOfWins);

// Places a cruiser ship for the bot with advanced logic.
void PlaceCruiserBot(int cruiser, char field[11][11], int oneTry);

// Places a submarine ship with advanced logic.
void SubmarineHard(int letterKey, int numKey, int wayKey, int submarine, char pole[11][11], int& countOfMatch, int& countOfWins);

// Places a submarine ship for the bot with advanced logic.
void PlaceSubmarineBot(int submarine, char field[11][11], int oneTry);

// Places a battleship with advanced logic.
void BattleShipHard(int letterKey, int numKey, int wayKey, int battleShip, char pole[11][11], int& countOfMatch, int& countOfWins);

// Places a battleship for the bot with advanced logic.
void PlaceBattleshipBot(int battleShip, char field[11][11], int oneTry);

// Marks the surrounding cells of a ship to prevent overlapping placements.
void MarkSurroundings(int letterKey, int numKey, char pole[11][11]);

// Reads and validates the row input for placing a ship.
void WriteRow(int& letterKey);

// Reads and validates the column input for placing a ship.
void WriteColumn(int& numKey);

// Handles the player's move, including attacking the opponent's ships.
void PlayerMove(char field[11][11], char field2[11][11], char viewField[11][11], int& countOfMoves, int& switchSides, int& countOfShips, int letterKey, int numKey);

// Places ships on the bot's game board.
void BotPlacing(char poleBot[11][11]);

// Executes the hard difficulty bot's logic for a single turn in the game.
bool HardGameBot(char mainField[11][11], char rivalField[11][11], char viewRivalField[11][11], char viewMainField[11][11], int& swichSides, int& countOfMoves, int& countOfShipsPL1, int& countOfShipsPL2, int letterKey, int numKey, int& countOfWins);

// Initializes and manages the hard bot game mode.
void HardBot(int& countOfGames, int& countOfWins);

// Executes the hard bot's move logic, including attacking the player's ships.
void HardBotMove(char field[11][11], char viewField[11][11], int& countOfMoves, int& swichSides, int& countOfShipsPL1);

void CruiserHard(int letterKey, int numKey, int wayKey, int cruiser, char pole[11][11], int& countOfMatch, int& countOfWins) {
    cout << "\nSecondly place your cruiser's ships: \n" << endl;

    while (cruiser > 0) {
        WriteRow(letterKey);
        WriteColumn(numKey);

        while (pole[letterKey][numKey] != '.') {
            cout << "\nThis position is already occupied, please choose another.\n";
            WriteRow(letterKey);
            WriteColumn(numKey);
        }

        bool validPlacement = false;
        while (!validPlacement) {
            cout << "\nWrite direction (W, w - up; A, a - left; S, s - down; D, d - right OR E , e - for replace): \n";
            wayKey = _getch();
            wayKey = toupper(wayKey);
            switch (wayKey) {
            case 'A':
                if (numKey - 1 >= 1 && pole[letterKey][numKey] == '.' && pole[letterKey][numKey - 1] == '.') {
                    pole[letterKey][numKey] = 'C';
                    pole[letterKey][numKey - 1] = 'C';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey, numKey - 1, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'S':
                if (letterKey + 1 <= 10 && pole[letterKey][numKey] == '.' && pole[letterKey + 1][numKey] == '.') {
                    pole[letterKey][numKey] = 'C';
                    pole[letterKey + 1][numKey] = 'C';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey + 1, numKey, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'D':
                if (numKey + 1 <= 10 && pole[letterKey][numKey] == '.' && pole[letterKey][numKey + 1] == '.') {
                    pole[letterKey][numKey] = 'C';
                    pole[letterKey][numKey + 1] = 'C';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey, numKey + 1, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'W':
                if (letterKey - 1 >= 1 && pole[letterKey][numKey] == '.' && pole[letterKey - 1][numKey] == '.') {
                    pole[letterKey][numKey] = 'C';
                    pole[letterKey - 1][numKey] = 'C';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey - 1, numKey, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'E':
                cout << "Sorry but u dont listen my advise.\n";
                HardBot(countOfMatch, countOfWins);

            default:
                cout << "Invalid direction. Please use W, A, S, or D. Or E for replace the position.\n";
                break;
            }
        }
        cruiser--;
        PrintPole(pole);

    }
}
    void SubmarineHard(int letterKey, int numKey, int wayKey, int submarine, char pole[11][11], int& countOfMatch, int& countOfWins) {
        cout << "\nSecondly place your submarine's ships: \n" << endl;

        while (submarine > 0) {  // Fixed loop condition
            WriteRow(letterKey);
            WriteColumn(numKey);

            while (pole[letterKey][numKey] != '.') {
                cout << "\nThis position is already occupied, please choose another.\n";
                WriteRow(letterKey);
                WriteColumn(numKey);
            }

            bool validPlacement = false;
            while (!validPlacement) {
                cout << "Write direction (W, w - up; A, a - left; S, s - down; D, d - right): \n";
                wayKey = _getch();
                wayKey = toupper(wayKey);

                switch (wayKey) {
                case 'A':
                    if (numKey - 2 >= 1 && pole[letterKey][numKey] == '.'
                        && pole[letterKey][numKey - 1] == '.'
                        && pole[letterKey][numKey - 2] == '.') {
                        pole[letterKey][numKey] = 'S';
                        pole[letterKey][numKey - 1] = 'S';
                        pole[letterKey][numKey - 2] = 'S';
                        MarkSurroundings(letterKey, numKey, pole);
                        MarkSurroundings(letterKey, numKey - 1, pole);
                        MarkSurroundings(letterKey, numKey - 2, pole);
                        validPlacement = true;
                    }
                    else {
                        cout << "Invalid placement! Try again.\n";
                    }
                    break;
                case 'S':
                    if (letterKey + 2 <= 10 && pole[letterKey][numKey] == '.'
                        && pole[letterKey + 1][numKey] == '.'
                        && pole[letterKey + 2][numKey] == '.') {
                        pole[letterKey][numKey] = 'S';
                        pole[letterKey + 1][numKey] = 'S';
                        pole[letterKey + 2][numKey] = 'S';
                        MarkSurroundings(letterKey, numKey, pole);
                        MarkSurroundings(letterKey + 1, numKey, pole);
                        MarkSurroundings(letterKey + 2, numKey, pole);
                        validPlacement = true;
                    }
                    else {
                        cout << "Invalid placement! Try again.\n";
                    }
                    break;
                case 'D':
                    if (numKey + 2 <= 10 && pole[letterKey][numKey] == '.'
                        && pole[letterKey][numKey + 1] == '.'
                        && pole[letterKey][numKey + 2] == '.') {
                        pole[letterKey][numKey] = 'S';
                        pole[letterKey][numKey + 1] = 'S';
                        pole[letterKey][numKey + 2] = 'S';
                        MarkSurroundings(letterKey, numKey, pole);
                        MarkSurroundings(letterKey, numKey + 1, pole);
                        MarkSurroundings(letterKey, numKey + 2, pole);
                        validPlacement = true;
                    }
                    else {
                        cout << "Invalid placement! Try again.\n";
                    }
                    break;
                case 'W':
                    if (letterKey - 2 >= 1 && pole[letterKey][numKey] == '.'
                        && pole[letterKey - 1][numKey] == '.'
                        && pole[letterKey - 2][numKey] == '.') {
                        pole[letterKey][numKey] = 'S';
                        pole[letterKey - 1][numKey] = 'S';
                        pole[letterKey - 2][numKey] = 'S';
                        MarkSurroundings(letterKey, numKey, pole);
                        MarkSurroundings(letterKey - 1, numKey, pole);
                        MarkSurroundings(letterKey - 2, numKey, pole);
                        validPlacement = true;
                    }
                    else {
                        cout << "Invalid placement! Try again.\n";
                    }
                    break;
                case 'E':
                    cout << "Sorry but u dont listen my advise.\n";
                    MediumBot(countOfMatch, countOfWins);
                default:
                    cout << "Invalid direction. Please use W, A, S, or D.\n";
                }
            }
            submarine--;
            PrintPole(pole);
        }
    }

    void BattleShipHard(int letterKey, int numKey, int wayKey, int battleShip, char pole[11][11], int& countOfMatch, int& countOfWins) {
        cout << "\nSecondly place your battleship's ships: \n" << endl;

        while (battleShip > 0) {
            // Fixed loop condition
            WriteRow(letterKey);
            WriteColumn(numKey);

            while (pole[letterKey][numKey] != '.') {
                cout << "\nThis position is already occupied, please choose another.\n";
                WriteRow(letterKey);
                WriteColumn(numKey);
            }

            bool validPlacement = false;
            while (!validPlacement) {
                cout << "Write direction (W, w - up; A, a - left; S, s - down; D, d - right): \n";
                wayKey = _getch();
                wayKey = toupper(wayKey);

                switch (wayKey) {
                case 'A':
                    if (numKey - 3 >= 1 && pole[letterKey][numKey] == '.'
                        && pole[letterKey][numKey - 1] == '.'
                        && pole[letterKey][numKey - 2] == '.'
                        && pole[letterKey][numKey - 3] == '.') {
                        pole[letterKey][numKey] = 'B';
                        pole[letterKey][numKey - 1] = 'B';
                        pole[letterKey][numKey - 2] = 'B';
                        pole[letterKey][numKey - 3] = 'B';
                        MarkSurroundings(letterKey, numKey, pole);
                        MarkSurroundings(letterKey, numKey - 1, pole);
                        MarkSurroundings(letterKey, numKey - 2, pole);
                        MarkSurroundings(letterKey, numKey - 3, pole);
                        validPlacement = true;
                    }
                    else {
                        cout << "Invalid placement! Try again.\n";
                    }
                    break;
                case 'S':
                    if (letterKey + 3 <= 10 && pole[letterKey][numKey] == '.'
                        && pole[letterKey + 1][numKey] == '.'
                        && pole[letterKey + 2][numKey] == '.'
                        && pole[letterKey + 3][numKey] == '.') {
                        pole[letterKey][numKey] = 'B';
                        pole[letterKey + 1][numKey] = 'B';
                        pole[letterKey + 2][numKey] = 'B';
                        pole[letterKey + 3][numKey] = 'B';
                        MarkSurroundings(letterKey, numKey, pole);
                        MarkSurroundings(letterKey + 1, numKey, pole);
                        MarkSurroundings(letterKey + 2, numKey, pole);
                        MarkSurroundings(letterKey + 3, numKey, pole);
                        validPlacement = true;
                    }
                    else {
                        cout << "Invalid placement! Try again.\n";
                    }
                    break;
                case 'D':
                    if (numKey + 3 <= 10 && pole[letterKey][numKey] == '.'
                        && pole[letterKey][numKey + 1] == '.'
                        && pole[letterKey][numKey + 2] == '.'
                        && pole[letterKey][numKey + 3] == '.') {
                        pole[letterKey][numKey] = 'B';
                        pole[letterKey][numKey + 1] = 'B';
                        pole[letterKey][numKey + 2] = 'B';
                        pole[letterKey][numKey + 3] = 'B';
                        MarkSurroundings(letterKey, numKey, pole);
                        MarkSurroundings(letterKey, numKey + 1, pole);
                        MarkSurroundings(letterKey, numKey + 2, pole);
                        MarkSurroundings(letterKey, numKey + 3, pole);
                        validPlacement = true;
                    }
                    else {
                        cout << "Invalid placement! Try again.\n";
                    }
                    break;
                case 'W':
                    if (letterKey - 3 >= 1 && pole[letterKey][numKey] == '.'
                        && pole[letterKey - 1][numKey] == '.'
                        && pole[letterKey - 2][numKey] == '.'
                        && pole[letterKey - 3][numKey] == '.') {
                        pole[letterKey][numKey] = 'B';
                        pole[letterKey - 1][numKey] = 'B';
                        pole[letterKey - 2][numKey] = 'B';
                        pole[letterKey - 3][numKey] = 'B';
                        MarkSurroundings(letterKey, numKey, pole);
                        MarkSurroundings(letterKey - 1, numKey, pole);
                        MarkSurroundings(letterKey - 2, numKey, pole);
                        MarkSurroundings(letterKey - 3, numKey, pole);
                        validPlacement = true;
                    }
                    else {
                        cout << "Invalid placement! Try again.\n";
                    }
                    break;
                case 'E':
                    cout << "Sorry but u dont listen my advise.\n";
                    HardBot(countOfMatch, countOfWins);
                default:
                    cout << "Invalid direction. Please use W, A, S, or D .\n";
                }
            }

            PrintPole(pole);
            battleShip--;
        }
    }

void HardBotMove(char field[11][11], char viewField[11][11], int& countOfMoves, int& swichSides, int& countOfShipsPL1) {
        int x, y;
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                if (field[i][j] == 'D' || field[i][j] == 'B' || field[i][j] == 'C' || field[i][j] == 'S') {
                    x = i;
                    y = j;
                }
            }
        }
        
        int h = rand() % 11 ;

        switch (h)
        { 
        case 0:
            viewField[x][y] = 'X';
            cout << "Bot hit your ship at (" << x << ", " << y << ")!" << endl;
            countOfShipsPL1--;
        case 4 :
            viewField[x][y] = 'X';
            cout << "Bot hit your ship at (" << x << ", " << y << ")!" << endl;
            countOfShipsPL1--;
        case 8 :
            viewField[x][y] = 'X';
            cout << "Bot hit your ship at (" << x << ", " << y << ")!" << endl;
            countOfShipsPL1--;
        case 10:
            viewField[x][y] = 'X';
            cout << "Bot hit your ship at (" << x << ", " << y << ")!" << endl;
            countOfShipsPL1--;
        default:
            do {
                x = rand() % 11 + 1;
                y = rand() % 11 + 1;
            } while (field[x][y] == 'X' || field[x][y] == '0' || x == 0 || y == 0);

            if (field[x][y] == 'D' || field[x][y] == 'C' || field[x][y] == 'S' || field[x][y] == 'B') {
                viewField[x][y] = 'X';
                cout << "Bot hit your ship at (" << x << ", " << y << ")!" << endl;
                countOfShipsPL1--;

            }
            else {
                viewField[x][y] = '0';
                cout << "Bot missed!" << endl;
                swichSides++;
            }
        }

        cout << "Your field after bot's move:" << endl;
        PrintPole(viewField);
    }



bool HardGameBot(char mainField[11][11], char rivalField[11][11], char viewRivalField[11][11], char viewMainField[11][11], int& swichSides, int& countOfMoves, int& countOfShipsPL1, int& countOfBotsShip, int letterKey, int numKey, int& countOfWins) {


        if (countOfShipsPL1 == 0) {
            cout << "Player2 wins the game!!!" << endl;
            ofstream inHistoryOfMatches("history.txt", ios::app);
            inHistoryOfMatches << "Game mod: Math with bot ; Level of bot : Hard ; Winner : Bot ; Count of moves : " << countOfMoves << "; " << endl;
            inHistoryOfMatches.close();
            return false;
        }
        if (countOfBotsShip == 0) {
            countOfWins++;
            cout << "Player win the game!!!" << endl;
            string username;
            ifstream outFileName("username.txt");
            getline(outFileName, username);
            outFileName.close();
            ofstream inHistoryOfMatches("history.txt", ios::app);
            inHistoryOfMatches << "Game mod: Math with bot; Level of bot : Hard ;Winner : " << username << "; Count of moves : " << countOfMoves << "; " << endl;
            inHistoryOfMatches.close();
            return false;
        }
        if (swichSides % 2 == 0) {
            cout << "Pole of rival before move : " << endl;
            PrintPole(viewRivalField);
            cout << "Player 1's move:" << endl;
            PlayerMove(mainField, rivalField, viewRivalField, countOfMoves, swichSides, countOfBotsShip, letterKey, numKey);
        }
        else {
            cout << "Bot's move:" << endl;
            HardBotMove(mainField, viewMainField, countOfMoves, swichSides, countOfShipsPL1);
        }

        return true;
    }


void HardBot(int& countOfGames, int& countOfWins) {
    int letterKey = 0;
    int numKey = 0;
    int wayKey = 0;
    int countOfDestroyShip = 4;
    int countOfCruiseShip = 3;
    int countOfSubmarines = 2;
    int countOfBattleShips = 1;
    char polePlayer[11][11];
    char poleBot[11][11];
    char player1Shots[11][11];
    char botShots[11][11];
    int countOfMoves = 0;
    int swichSides = 0;
    int countOfShips1 = 20;
    int countOfBotsShip = 20;
    fillArray(polePlayer);
    fillArray(player1Shots);
    fillArray(botShots);
    system("cls");
    cout << "Player num1 please place ur ship's : " << endl;
    PlaceDestroyers(letterKey, numKey, countOfDestroyShip, polePlayer);
    cout << "Please dont try to place ships there u cant choose way because u need to replace all ships" << endl;
    CruiserHard(letterKey, numKey, wayKey, countOfCruiseShip, polePlayer, countOfGames, countOfWins);
    SubmarineHard(letterKey, numKey, wayKey, countOfSubmarines, polePlayer, countOfGames, countOfWins);
    BattleShipHard(letterKey, numKey, wayKey, countOfBattleShips, polePlayer, countOfGames, countOfWins);
    system("cls");
    cout << "Bot is placing ships..." << endl;
    BotPlacing(poleBot);
    system("cls");
    while (HardGameBot(polePlayer, poleBot, player1Shots, botShots, swichSides, countOfMoves, countOfShips1, countOfBotsShip, letterKey, numKey, countOfWins));
    countOfGames++;
    lobby();
}