#include <iostream>
#include <string>
#include <vector>

using namespace std;

void bfsmod(int x, int y);

long long n, m;
string* maze;

int dots = 0;

int main(int argc, char *argv[]) {
    cin >> n >> m;
    // find entrances a - w and save coords
    // loop through entrances
    // mark all dots found
    // if a found dot is encountered, go to the next iteration
    // if a new dot is found start subroutine,
    //      mark all dots reachable
    //      add 1 to count
    // end loop
    // check whole map for unfound dots and count them
    
    maze = new string[n];
    getline(cin, maze[0]);  // consume newline from first line
    for(int i = 0; i < n; i++) {
        getline(cin, maze[i]);
    }
    
    vector<pair<int,int>> entrances;
    // find a-w and count dots
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] >= 'A' && maze[i][j] <= 'W') {
                entrances.push_back({i,j});
            }
            if(maze[i][j] == '.') dots++;
        }
    }
    
    int entrancesNeeded = 0;
    
    // loop through entrances
    for(int i = 0; i < entrances.size(); i++) {
        int y = entrances[i].first;
        int x = entrances[i].second;
        
        if(x == 0)
            x++;
        else if(y == 0)
            y++;
        else if(x == m - 1)
            x--;
        else
            y--;
        
        if(x == 0 || y == 0 || x == m - 1 || y == n - 1) continue;   // literal corner case
        if(maze[y][x] == 'X') continue; // edge case :)
        if(maze[y][x] == ',') continue; // already been here
    
        int tempdots = dots;
        bfsmod(x,y);
        if(tempdots != dots) entrancesNeeded++;
    }
    
    cout << entrancesNeeded << " " << dots << endl;
    
    delete [] maze;
    return 0;
}

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}; // possible moves
// change all reachable periods and spaces to commas
void bfsmod(int x, int y) {
    if(maze[y][x] == ' ') {
        maze[y][x] = ',';
    } else if(maze[y][x] == '.') {
        maze[y][x] = ',';
        dots--;
    }
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i], newY = y + dy[i];
        if(maze[newY][newX] == '.' || maze[newY][newX] == ' ')
        {
            bfsmod(newX, newY);
        }
    }
}