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
bool checkGridOpen(int, int);
bool checkGridOffMap(int, int, int);

class Organism {
protected:
    //1 - north, 2 - south, 3 - east, 4 - west
    int Space;
    int Life;
public:
    //pass optional parameter to move it in direction of ant to eat?
    virtual int move() {
        return Space;
    }
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
    char Shape = 'X';
public:
    friend Doodlebug operator ++(Doodlebug& bug) {
        int life = bug.getLife();
        life += 1;
        if (life == 8) {
            //breed();
            life = 0;
        }
        bug.setLife(life);
        return bug;
    }

    void move() { 
        //north (1)
        bool moved = false;
        int direction = rand() % 4;
        //check for ant
        if (checkGridOn(XCord, YCord, direction) && checkGridOpen(XCord, YCord, direction)) {
            updateGrid(XCord, YCord, '-');
            switch(direction){
                //north
                case 0:
                    
                    YCord--;
                    grid[XCord][YCord] = 'X';                    
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
            }
        }
        else
            return;
        }

        switch(direction) {
            //north

            case 1:
                if (y > 0) {
                    y -= 20;
                }
            case 
        }


        if (checkGridOpen && checkGridOn)

    }
    void breed() {
        if(checkGrid) {
            //random space
            //duplicate, call constructor
        }
    }

    Doodlebug(int space) {Space = space; Life = 0;}
};

class Ant : public Organism {
private:
    char Shape = 'o';
    int Space;
    //increment life every round, 
    int Life = 0;
public:

    Ant(int space) {Space = space; Life = 0;}
    int move() {
        random_shuffle(possible_moves.begin(), possible_moves.end());
        for (int i = 0; i < 4; i++) {
            cout<<possible_moves[i]<<" ";
        cout<<endl;
        }
        //north (1)
        int moveTries = 0;
        int move = possible_moves[moveTries];
        cout<<move<<endl;
        

    //Ant breed() {
    //}
    friend Ant operator ++(Ant& bug) {
        int life = bug.getLife();
        life += 1;
        if (life == 3) {
            //breed();
            life = 0;
        }
        bug.setLife(life);
        return bug;
    }
};

vector<Doodlebug> doodle;
vector<Ant> ants;

void printGrid(char *grid[20]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            cout<<grid[i][j]<<' ';
        }
    }
    cout<<"\n\n Hit ENTER to continue\n"<<endl;
}

bool checkGridOpen(int x, int y) {
    if (grid[x][y] == '-')
        return true;
    else
        return false;
}

bool checkGridOn(int x, int y, int direction) {
    switch(direction) {
        
    }
}

void startSim() {
    vector<int> random_nums_x;
    vector<int> random_nums_y;
    for (int i = 0; i < GRID_SIZE; i++) {
        random_nums_x.push_back(i);
        random_nums_y.push_back(i);
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '-';
        }
    }
    
    srand(time(NULL));
    random_shuffle(random_nums_x.begin(), random_nums_x.end());
    random_shuffle(random_nums_y.begin(), random_nums_y.end());
    for (int i = 0; i < 6; i++) {
        int doodleSpace = random_nums_x[i];
        grid[doodleSpace] = 'X';
        Doodlebug doodlebug(doodleSpace);
        doodle.push_back(doodlebug);
    }

    for (int i = 5; i < 105; i++) {
        int antSpace = random_nums[i];
        cout<<"Ant space: "<<antSpace<<endl;
        grid[antSpace] = 'o';
        Ant ant(antSpace);
        ants.push_back(ant);
    }
    printGrid(grid);
    
}

//intialize grid
    //20x20 2-dimensional array
    //choose random spaces for 5 dbs
    //choose random spaces for 100 ants
    //intialize grid based on spaces for ants and dbs

    //5 doodlebugs
        //Organism class
            //doodlebug class
    //100 ants
        //Organism class
            //ant class

//Organism class
    //movement
    //

//time step
    //increment step #
    //move ants & dbs
    //check for eating
    //check for breeding
    //check for starvation
/*int doodleBug() {

    //initialize grid
        //
}*/

void updateGrid(int x, int y, char symbol){
    grid[x][y] = symbol;
}

void round() {
    for (int i = 0; i < doodle.size(); i++) {
        doodle[i].move();
    }
    for (int i = 0; i < ants.size(); i++) {
        ants[i].move();
    }
    printGrid(grid);
}


int main() {
    startSim();
    char temp;
    while (temp != -1) {
        cin.get(temp);
        round();
    }
    return 0;
}