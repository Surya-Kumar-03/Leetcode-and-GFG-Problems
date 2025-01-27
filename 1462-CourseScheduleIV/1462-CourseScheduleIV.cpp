class Solution
{
public:
    void indexBeforeHand(int numCourses, vector<vector<int>>& graph, 
        vector<vector<bool>>& coursePrerequisites) {
        
        for(int course = 0; course < numCourses; course++) {
            queue<int> pending;
            pending.push(course);

            while(!pending.empty()) {
                int curCourse = pending.front();
                pending.pop();

                for(auto curCoursePrerequisite : graph[curCourse]) {
                    if (coursePrerequisites[course][curCoursePrerequisite] == false) {
                        coursePrerequisites[course][curCoursePrerequisite] = true;
                        pending.push(curCoursePrerequisite);
                    }
                }
            }
        }

        return;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<int>> graph(numCourses);

        for (auto prerequisite : prerequisites)
        {
            graph[prerequisite[0]].push_back(prerequisite[1]);
        }

        vector<vector<bool>> coursePrerequisites(numCourses, vector<bool>(numCourses, false));

        indexBeforeHand(numCourses, graph, coursePrerequisites);

        int queryCount = queries.size();
        vector<bool> answer;

        for(auto query : queries) {
            if (coursePrerequisites[query[0]][query[1]] == true) {
                answer.push_back(true);
            } else {
                answer.push_back(false);
            }
        }

        return answer;
    }
};