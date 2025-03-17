class TaskManager {
public:

    priority_queue<vector<int>>pq;
    unordered_map<int,int>taskToUser;
    unordered_map<int,int>taskToPriority;

    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0;i < tasks.size();i++) {
            pq.push({tasks[i][2],tasks[i][1],tasks[i][0]});
            taskToUser[tasks[i][1]] = tasks[i][0];
            taskToPriority[tasks[i][1]] = tasks[i][2];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskToUser[taskId] = userId;
        taskToPriority[taskId] = priority;
        pq.push({priority,taskId,userId});
    }
    
    void edit(int taskId, int newPriority) {
        taskToPriority[taskId] = newPriority;
        int userId = taskToUser[taskId];
        pq.push({newPriority,taskId,userId});
    }
    
    void rmv(int taskId) {
        taskToUser.erase(taskId);
        taskToPriority.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()) {
            int priority = pq.top()[0];
            int taskId = pq.top()[1];
            int userId = pq.top()[2];
            pq.pop();

            if(taskToUser.count(taskId) == 0 || taskToPriority.count(taskId) == 0) continue;
            if(taskToUser[taskId] != userId || taskToPriority[taskId] != priority) continue;
            taskToUser.erase(taskId);
            taskToPriority.erase(taskId);
            return userId;
        }
        return -1;
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
