#include <algorithm>
#include <random>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//20x20 grid, 5 dooglebugs, 100 ants
//all doodlebugs move before ants do
//after 3 moves, ants reproduce to available space
//after 8 moves, doodlebugs reproduce to available space

const char DOODLEBUG = 'X';
const char ANT = 'o';
const char SPACE = '-';
const int GRID_SIZE = 400;
char grid[20][20];
vector<int> possible_moves;

void updateGrid(int, int, char);
bool checkGridOpen(int, int, int);
bool checkGridOn(int, int, int);

class Organism {
protected:
    //1 - north, 2 - south, 3 - east, 4 - west
    int Space;
    int Life;
public:
    //pass optional parameter to move it in direction of ant to eat?

    int getLife() const {
        return Life;
    }
    int getSpace() const {
        return Space;
    }
    void setLife(int life) {
        Life = life;
    }

    //breed();
    //need to modify breed for bugs
    //constructor
    Organism() { Space = 0; Life = 0;}
    Organism(int space) {
        Space = space;
        Life = 0;
    };
    //

};

class Doodlebug: public Organism {
private:
    int XCord;
    int YCord;
    int Life;
public:
    void setXCord(int cord) {
        XCord = cord;
    }

    void setYCord(int cord) {
        YCord = cord;
    }

    void move() { 
        //north (1)
        bool moved = false;
        int direction = rand() % 4;
        //check for ant
        if (checkGridOn(XCord, YCord, direction) && checkGridOpen(XCord, YCord, direction)) {
            grid[XCord][YCord] = '-';
            switch(direction){
                //north
                case 0:  
                    YCord--;                
                break;
                //east
                case 1:
                    XCord++;
                    break;
                //south
                case 2:
                    YCord++;
                    break;
                //west
                case 3:
                    XCord--;
                    break;
                default:
                    break;
            }
            grid[XCord][YCord] = 'X';
        }
        else
            ;
    }

   /* void breed() {
        if(checkGrid) {
            //random space
            //duplicate, call constructor
        }
    }
    */

    Doodlebug(int x, int y) {XCord = x, YCord = y, Life = 0;}
    ~Doodlebug() {};
};

class Ant : public Organism {
private:
    int XCord;
    int YCord;
    //increment life every round, 
    int Life = 0;
public:
    void setXCord(int cord) {
        XCord = cord;
    }

    void setYCord(int cord) {
        YCord = cord;
    }

    int getLife(){
        return Life;
    }

    Ant(int x, int y) {XCord = x, YCord = y, Life = 0;}
    ~Ant() {};

    /*int move() {
        random_shuffle(possible_moves.begin(), possible_moves.end());
        for (int i = 0; i < 4; i++) {
            cout<<possible_moves[i]<<" ";
        cout<<endl;
        }
        //north (1)
        int moveTries = 0;
        int move = possible_moves[moveTries];
        cout<<move<<endl;
    }
    */
};

vector<Doodlebug> doodle;
vector<Ant> ants;

void printGrid(char arr[][20]) {
    cout<<"\nCalled"<<endl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cout<<grid[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<"\n\n Hit ENTER to continue\n"<<endl;
}

bool checkGridOpen(int x, int y, int direction) {
    switch (direction) {
        if (checkGridOn) {
            case 0:
                if (grid[x][y-1] == '-')
                    return true;
                else
                    return false;
                break;
        case 1:
            if (grid[x+1][y] == '-')
                    return true;
                else
                    return false;
            break;
        case 2:
            if (grid[x][y+1] == '-')
                    return true;
                else
                    return false;
            break;
        case 3:
            if (grid[x-1][y] == '-')
                    return true;
                else
                    return false;
            break;
        }
        else
            return false;
    }
}

bool checkGridOn(int x, int y, int direction) {
    switch (direction) {
        case 0:
            if (y != 0)
                return true;
            else
                return false;
            break;
        case 1:
            if (x != 19 == 0)
                return true;
            else
                return false;
            break;
        case 2:
            if (y != 19)
                return true;
            else
                return false;
            break;
        case 3:
            if (x != 0)
                return true;
            else
                return false;
            break;
    }
    return true;
}

void startSim() {
    int i;
    vector<int> random_nums_x;
    vector<int> random_nums_y;
    for (i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            grid[i][j] = '-';
        }
    }
    cout<<"finished";
    
    srand(time(NULL));
    cout<<"Shuff";
    i = 0;
    while (i < 5) {
        int doodleX = rand() % 20;
        int doodleY = rand() % 20;
        if (grid[doodleX][doodleY] == '-') {
            cout<<doodleX<<" "<<doodleY<<endl;
            cout<<"Success"<<endl;
            grid[doodleX][doodleY] = 'X';
            Doodlebug doodlebug(doodleX, doodleY);
            doodle.push_back(doodlebug);
            i++;
        }
        else {
            
        }
    }
    cout<<"ants";

    i = 0;
    while (i < 100) {
        int antX = rand() % 20;
        int antY = rand() % 20;
        if (grid[antX][antY] == '-') {
            grid[antX][antY] = 'o';
            Ant ant(antX, antY);
            ants.push_back(ant);
            i++;
        }
    }
    cout<<"bugs";
    printGrid(grid);
    
}

void updateGrid(int x, int y, char symbol){
    grid[x][y] = symbol;
}

void round() {
    for (int i = 0; i < doodle.size(); i++) {
        doodle[i].move();
    }
    /*
    for (int i = 0; i < ants.size(); i++) {
        ants[i].move();
    }
    printGrid(grid);
    */
}


int main() {

    cout<<"main"<<endl;
    
    startSim();
    char temp;
    while (temp != -1) {
        cin.get(temp);
        round();
    }
    
    return 0;
}