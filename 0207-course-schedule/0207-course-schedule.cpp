#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        // Build the adjacency list and calculate indegree of each vertex
        for (const auto& pair : prerequisites) {
            adj[pair[1]].push_back(pair[0]);
            indeg[pair[0]]++;
        }

        queue<int> q;
        // Add all vertices with indegree 0 to the queue
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; // Number of courses that can be completed
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int neighbor : adj[node]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If we can complete all courses, the count should be equal to numCourses
        return count == numCourses;
    }
};
