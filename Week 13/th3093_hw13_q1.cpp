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

class Organism {
protected:
    int possible_moves[4] = {1, 2, 3, 4};
    char shape;
    int space;
public:
    //pass optional parameter to move it in direction of ant to eat?
    void move() {
        vector <int> possible_moves;
        //1 = north, 2 = east, 3 = south, 4 = west
        for (int i = 0; i < 4; i++)
            possible_moves.push_back(i);
        random_shuffle(possible_moves.begin(), possible_moves.end());
        int move = possible_moves[0];
        //north (1)
        if (move == 1 && space > 19) {
            if (checkGrid(space - 20))
                space -= 20;
        }
        //east (2)
        if (move == 2 && space % 10 != 0) {
            if (checkGrid(space + 1))
                space += 1;
        }
        //south (3)
        if (move == 3 && space < 379) {
            if (checkGrid(space + 20))
                space += 20;
        }
        //west (4)
        if (move == 4 && space % 10 != 1) {
            if (checkGrid(space - 1))
                space -= 1;
        }
    }
    
    //

};

class Doodlebug: public Organism {
private:

public:

};

class Ant: public Organism {
private:

public:
        
};

bool checkGrid(int index) {
    if (grid[index] == '-')
        return true;
    else
        return false;
}

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
        grid[random_nums[i]] = 'X';
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


int main() {
    startSim();
    return 0;
}