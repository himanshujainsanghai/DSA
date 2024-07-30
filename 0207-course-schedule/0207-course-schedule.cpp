#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pr) {
        vector<int> adj[numCourses];
        int n = pr.size();
        vector<int> in(numCourses, 0);

        // Build the adjacency list and in-degree array
        for (auto i : pr) {
            adj[i[1]].push_back(i[0]);
            in[i[0]]++;
        }

        int cnt = 0;
        queue<int> q;
        // Add all courses with indegree 0 to the queue
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) q.push(i);
        }

        // Process the courses
        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[fr]) {
                in[it]--;
                if (in[it] == 0) q.push(it);
            }
        }

        // If we can complete all courses, the count should be equal to numCourses
        return cnt == numCourses;
    }
};
