#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
	int id;
	int duration;
	vector<int> dependencies;
};

int findEarliestCompletion(vector<Task>& tasks, int taskIndex) {
	if (tasks[taskIndex].dependencies.empty()) {
		return tasks[taskIndex].duration;
	}

	int maxCompletion = 0;
	for (int dep : tasks[taskIndex].dependencies) {
		maxCompletion = max(maxCompletion, findEarliestCompletion(tasks, dep));
	}

	return maxCompletion + tasks[taskIndex].duration;
}

int findCriticalPath(vector<Task>& tasks) {
	int maxPath = 0;
	for (int i = 0; i < tasks.size(); i++) {
		maxPath = max(maxPath, findEarliestCompletion(tasks, i));
	}

	return maxPath;
}

int main() {
	vector<Task> tasks = {
	{0, 5, {}},
	{1, 7, {0}},
	{2, 3, {0}},
	{3, 6, {1, 2}}
	};

	int criticalPath = findCriticalPath(tasks);
	cout << "Critical path duration: " << criticalPath << endl;

	return 0;
}