#include <bits/stdc++.h>
using namespace std;

#define ROWS 9
#define COLS 10

typedef pair<int, int> Coord;

typedef pair<double, pair<int, int>> NodeInfo;

struct Node {
    int parentRow, parentCol; 
    double fCost, gCost, hCost; 
};

bool isInsideGrid(int row, int col) {
    return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS);
}

bool isWalkable(int grid[][COLS], int row, int col) {
    return (grid[row][col] == 1);
}

bool isGoal(int row, int col, Coord goal) {
    return (row == goal.first && col == goal.second);
}

double getHeuristic(int row, int col, Coord goal) {
    return sqrt(pow(row - goal.first, 2) + pow(col - goal.second, 2));
}

void printPath(Node nodeInfo[][COLS], Coord goal) {
    printf("\nShortest Path: ");
    int row = goal.first;
    int col = goal.second;

    stack<Coord> pathStack;

    while (!(nodeInfo[row][col].parentRow == row &&
             nodeInfo[row][col].parentCol == col)) {
        pathStack.push(make_pair(row, col));
        int tempRow = nodeInfo[row][col].parentRow;
        int tempCol = nodeInfo[row][col].parentCol;
        row = tempRow;
        col = tempCol;
    }
    pathStack.push(make_pair(row, col));

    while (!pathStack.empty()) {
        Coord p = pathStack.top();
        pathStack.pop();
        printf("-> (%d,%d) ", p.first, p.second);
    }
    printf("\n");
}

void aStarSearch(int grid[][COLS], Coord start, Coord goal) {
    if (!isInsideGrid(start.first, start.second)) {
        printf("Invalid start position\n");
        return;
    }
    if (!isInsideGrid(goal.first, goal.second)) {
        printf("Invalid goal position\n");
        return;
    }
    if (!isWalkable(grid, start.first, start.second) ||
        !isWalkable(grid, goal.first, goal.second)) {
        printf("Start or goal is blocked\n");
        return;
    }
    if (isGoal(start.first, start.second, goal)) {
        printf("Already at the goal\n");
        return;
    }

    bool visited[ROWS][COLS];
    memset(visited, false, sizeof(visited));

    Node nodeInfo[ROWS][COLS];

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            nodeInfo[r][c].fCost = FLT_MAX;
            nodeInfo[r][c].gCost = FLT_MAX;
            nodeInfo[r][c].hCost = FLT_MAX;
            nodeInfo[r][c].parentRow = -1;
            nodeInfo[r][c].parentCol = -1;
        }
    }

    int startRow = start.first;
    int startCol = start.second;
    nodeInfo[startRow][startCol].fCost = 0.0;
    nodeInfo[startRow][startCol].gCost = 0.0;
    nodeInfo[startRow][startCol].hCost = 0.0;
    nodeInfo[startRow][startCol].parentRow = startRow;
    nodeInfo[startRow][startCol].parentCol = startCol;

    set<NodeInfo> openSet;
    openSet.insert(make_pair(0.0, make_pair(startRow, startCol)));

    bool goalReached = false;

    int dRow[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dCol[] = {0, 0, 1, -1, 1, -1, 1, -1};
    double moveCost[] = {1.0, 1.0, 1.0, 1.0, 1.414, 1.414, 1.414, 1.414};

    while (!openSet.empty()) {
        NodeInfo current = *openSet.begin();
        openSet.erase(openSet.begin());

        int currRow = current.second.first;
        int currCol = current.second.second;
        visited[currRow][currCol] = true;

        for (int d = 0; d < 8; d++) {
            int nextRow = currRow + dRow[d];
            int nextCol = currCol + dCol[d];

            if (isInsideGrid(nextRow, nextCol)) {
                if (isGoal(nextRow, nextCol, goal)) {
                    nodeInfo[nextRow][nextCol].parentRow = currRow;
                    nodeInfo[nextRow][nextCol].parentCol = currCol;
                    printf("Goal reached!\n");
                    printPath(nodeInfo, goal);
                    goalReached = true;
                    return;
                }
                else if (!visited[nextRow][nextCol] &&
                         isWalkable(grid, nextRow, nextCol)) {
                    double newG = nodeInfo[currRow][currCol].gCost + moveCost[d];
                    double newH = getHeuristic(nextRow, nextCol, goal);
                    double newF = newG + newH;

                    if (nodeInfo[nextRow][nextCol].fCost == FLT_MAX ||
                        nodeInfo[nextRow][nextCol].fCost > newF) {
                        openSet.insert(make_pair(newF, make_pair(nextRow, nextCol)));
                        nodeInfo[nextRow][nextCol].fCost = newF;
                        nodeInfo[nextRow][nextCol].gCost = newG;
                        nodeInfo[nextRow][nextCol].hCost = newH;
                        nodeInfo[nextRow][nextCol].parentRow = currRow;
                        nodeInfo[nextRow][nextCol].parentCol = currCol;
                    }
                }
            }
        }
    }

    if (!goalReached)
        printf("No path found to the goal\n");
}

int main() {
    int grid[ROWS][COLS] = {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 0, 0, 1}
    };

    Coord start = make_pair(8, 0); 
    Coord goal = make_pair(0, 0);  

    aStarSearch(grid, start, goal);
    return 0;
}
