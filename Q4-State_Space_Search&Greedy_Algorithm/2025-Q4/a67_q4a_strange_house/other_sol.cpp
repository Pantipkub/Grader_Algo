#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
vector<int> adj[MAXN]; // Adjacency list for the graph
int n, m;


// Calculate how many beds are in their correct positions
int correctPositions(const vector<int>& rooms) {
    int count = 0;
    
    // Check blue beds in rooms 1 to n
    for (int i = 1; i <= n; i++) {
        if (rooms[i] == 2) count++;
    }
    
    // Check red beds in rooms n+1 to 2n
    for (int i = n+1; i <= 2*n; i++) {
        if (rooms[i] == 1) count++;
    }
    
    return count;
}

// Represents the state of the house
struct State {
    vector<int> rooms;     // 0 = empty, 1 = red bed, 2 = blue bed
    int emptyRoom;         // Position of the empty room
    vector<int> moves;     // Sequence of moves performed
    
    // For comparison in priority queue
    bool operator<(const State& other) const {
        // We want higher values to have higher priority
        // So invert the comparison
        return correctPositions(rooms) < correctPositions(other.rooms);
    }
};



// Check if the state meets the target condition
bool isTargetState(const vector<int>& rooms) {
    // Check if rooms 1 to n have blue beds (value 2)
    for (int i = 1; i <= n; i++) {
        if (rooms[i] != 2) return false;
    }
    
    // Check if rooms n+1 to 2n have red beds (value 1)
    for (int i = n+1; i <= 2*n; i++) {
        if (rooms[i] != 1) return false;
    }
    
    return true;
}

// A* search to find the solution
vector<int> solveAStar() {
    // Initialize the starting state
    State start;
    start.rooms.resize(2*n+2, 0);
    
    // Initial setup: red beds in rooms 1 to n, blue beds in rooms n+1 to 2n
    for (int i = 1; i <= n; i++) {
        start.rooms[i] = 1; // Red beds
    }
    for (int i = n+1; i <= 2*n; i++) {
        start.rooms[i] = 2; // Blue beds
    }
    
    start.emptyRoom = 2*n+1; // Room 2n+1 is initially empty
    
    // Use priority queue for A* search
    priority_queue<State> pq;
    pq.push(start);
    
    // Use a set to keep track of visited states
    set<vector<int>> visited;
    visited.insert(start.rooms);
    
    // Add a counter to limit the number of iterations
    int statesExplored = 0;
    const int MAX_STATES = 100000;
    
    while (!pq.empty() && statesExplored < MAX_STATES) {
        State current = pq.top();
        pq.pop();
        statesExplored++;
        
        // Check if we've reached the target
        if (isTargetState(current.rooms)) {
            return current.moves;
        }
        
        // Try moving beds from adjacent rooms to the empty room
        for (int adj_room : adj[current.emptyRoom]) {
            // Don't go back to the room we just came from
            if (!current.moves.empty() && adj_room == current.moves.back()) {
                continue;
            }
            
            // Create a new state by moving a bed
            State next = current;
            
            // Move the bed from adj_room to the empty room
            next.rooms[current.emptyRoom] = current.rooms[adj_room];
            next.rooms[adj_room] = 0; // The adjacent room becomes empty
            next.emptyRoom = adj_room;
            
            // Record this move
            next.moves.push_back(adj_room);
            
            // Check if we haven't visited this state before
            if (visited.find(next.rooms) == visited.end()) {
                visited.insert(next.rooms);
                pq.push(next);
            }
        }
    }
    
    // If no solution was found or we've exceeded our exploration limit
    return {-1};
}

int main() {
    cin >> n >> m;
    
    // Read the connections between rooms
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // Find the solution
    vector<int> solution = solveAStar();
    
    if (solution.size() == 1 && solution[0] == -1) {
        cout << -1 << endl;
    } else {
        cout << solution.size() << endl;
        for (int move : solution) {
            cout << move << " ";
        }
        cout << endl;
    }
    
    return 0;
}
