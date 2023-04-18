#include <random>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//20x20 grid, 5 dooglebugs, 100 ants
//all doodlebugs move before ants do
//after 3 moves, ants reproduce to available space
//after 8 moves, doodlebugs reproduce to available space

//random num generator. Access using dis(gen)
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 3);

const char DOODLEBUG = 'X';
const char ANT = 'o';
const char SPACE = '-';
const int GRID_SIZE = 400;
char grid[20][20];
class Doodlebug;
class Ant;
vector<Doodlebug> doodle;
vector<Ant> ants;
vector<int> possible_moves;

void updateGrid(int, int, char);
bool checkGridOpen(int, int, int);
bool checkGridOn(int, int, int);
void increaseLives();

class Organism {
protected:
    //1 - north, 2 - south, 3 - east, 4 - west
    int Life;
public:
    //pass optional parameter to move it in direction of ant to eat?

    int getLife() const {
        return Life;
    }

    void increaseLife() {
        Life += 1;
    }
    void resetLife() {
        Life = 0;
    }

    //breed();
    //need to modify breed for bugs
    //constructor
    Organism() { Life = 0;}

};

class Ant : public Organism {
private:
    int XCord;
    int YCord;
    //increment life every round, 
    int Life = 0;
public:

    int getXCord(){
        return XCord;
    }
    int getYCord(){
        return YCord;
    }
    void setXCord(int cord) {
        XCord = cord;
    }

    void setYCord(int cord) {
        YCord = cord;
    }

    int getLife(){
        return Life;
    }

    void move() { 
        //north (1)
        bool moved = false;
        int direction = dis(gen);
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
            grid[XCord][YCord] = 'o';
        }
        else
            ;
    }

    Ant(int x, int y) {XCord = x, YCord = y, Life = 0;}
    ~Ant() {};

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

    bool eat() {
        vector<int> possible;
        for (int i = 0; i < 4; i++) {
            bool open = checkGridOn(XCord, YCord, i);
            if (!open) {
                possible.push_back(i);
            }
        }
        int size = possible.size();
        if (size != 0) {
            random_shuffle(possible.begin(), possible.end());
            int ant = possible[0];
            grid[XCord][YCord] = '-';
            switch(ant){
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
            for (int i = 0; i < ants.size(); i++) {
                int antX = ants[i].getXCord();
                int antY = ants[i].getYCord();
                if (antX == XCord && antY == YCord) {
                    ants.erase(ants.begin() + i);
                }
            }

            grid[XCord][YCord] = 'X';
            
        }
    }

    void move() { 
        //north (1)
        bool moved = false;
        int direction = dis(gen);
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


    Doodlebug(int x, int y) {XCord = x, YCord = y, Life = 0;}
    ~Doodlebug() {};
};




void printGrid(char arr[][20]) {
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

bool checkGridAnt(int x, int y, int direction) {
    switch (direction) {
        if (checkGridOn) {
            case 0:
                if (grid[x][y-1] == 'o')
                    return true;
                else
                    return false;
                break;
        case 1:
            if (grid[x+1][y] == 'o')
                    return true;
                else
                    return false;
            break;
        case 2:
            if (grid[x][y+1] == 'o')
                    return true;
                else
                    return false;
            break;
        case 3:
            if (grid[x-1][y] == 'o')
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

    
    srand(time(NULL));
    i = 0;
    while (i < 5) {
        int doodleX = rand() % 20;
        int doodleY = rand() % 20;
        if (grid[doodleX][doodleY] == '-') {
            grid[doodleX][doodleY] = 'X';
            Doodlebug doodlebug(doodleX, doodleY);
            doodle.push_back(doodlebug);
            i++;
        }
        else {
            
        }
    }

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
    printGrid(grid);
    
}

int roundNumber = 0;
void round() {
    for (int i = 0; i < doodle.size(); i++) {
        bool eat = doodle[i].eat();
        if (!eat) {
            doodle[i].move();
        }
    }
    for (int i = 0; i < ants.size(); i++) {
        ants[i].move();
    }
    roundNumber++;
    cout<<"round: "<<roundNumber<<endl;
    increaseLives();

    printGrid(grid);
}

void increaseLives() {
    for (int i = 0; i < doodle.size(); i++) {
        doodle[i].increaseLife();
        int life = doodle[i].getLife();
        if (life == 7) {
            //doodle[i].breed();
            //doodle[i].resetLife(0);
        }
    }
    for (int i = 0; i < ants.size(); i++) {
        ants[i].increaseLife();
        int life = doodle[i].getLife();
        if (life == 3) {
            //ants[i].breed();
            //ants[i].resetLife(0);
        }
    }
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