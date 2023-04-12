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
vector<char> grid;

bool checkGrid(int new_index) {

    if (grid[new_index] == '-')
        return true;
    else
        return false;
}

class Organism {
protected:
    //1 - north, 2 - south, 3 - east, 4 - west
    int Space;
    int Life;
public:
    int possible_moves[4] = {1, 2, 3, 4};
    //pass optional parameter to move it in direction of ant to eat?
    int move() {
        vector <int> possible_moves;
        for (int i = 0; i < 4; i++)
            possible_moves.push_back(i);
        random_shuffle(possible_moves.begin(), possible_moves.end());
        
        //north (1)
        int moveTries = 0;
        int move = possible_moves[moveTries];
        bool moved = false;
        int space = this->Space;
        while (moved == false && moveTries < 4) {
            if (move == 1 && space > 19) {
                if (checkGrid(space - 20))
                    grid[space] = '-';
                    space -= 20;
                    grid[space] = 'X';
                    moved = true;
            }
            //east (2)
            if (move == 2 && Space % 10 != 0) {
                if (checkGrid(Space + 1))
                    space += 1;
                    moved = true;
            }
            //south (3)
            if (move == 3 && Space < 379) {
                if (checkGrid(Space + 20))
                    space += 20;
                    moved = true;
            }
            //west (4)
            if (move == 4 && Space % 10 != 1) {
                if (checkGrid(Space - 1))
                    space -= 1;
                    moved = true;
            }
            else
                move = possible_moves[moveTries++];
        }
        return space;
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
    Organism(int space) {
        Space = space;
        Life = 0;
    };
    //

};

vector<Organism> doodle;

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

    void breed() {
        if(checkGrid) {
            //random space
            //duplicate, call constructor
        }
    }
};

class Ant: public Organism {
private:
    char Shape = 'o';
    //increment life every round, 
    int Life = 0;
public:

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



void printGrid(vector <char> vect) {
    int counter = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        if (counter == 20) {
            cout<<endl;
            counter = 0;
        }
        cout<<vect[i]<<' ';
        counter++;
    }
    cout<<"\n\n Hit ENTER to continue\n"<<endl;
}

void startSim() {
    vector<int> random_nums;
    for (int i = 0; i < GRID_SIZE; i++) {
        grid.push_back('-');
        random_nums.push_back(i);
    }
    
    srand(time(0));
    random_shuffle(random_nums.begin(), random_nums.end());
    for (int i = 0; i < 6; i++) {
        int doodleSpace = random_nums[i];
        grid[doodleSpace] = 'X';
        Organism doodlebug(doodleSpace);
        doodle.push_back(doodlebug);
    }

    for (int i = 5; i < 105; i++) {
        grid[random_nums[i]] = 'o';
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

void round() {
    for (int i = 0; i < 6; i++) {
        doodle[i].move();
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