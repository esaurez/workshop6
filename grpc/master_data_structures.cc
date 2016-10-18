//
// Created by Kevin Randrup on 10/12/16.
//

/// The master is the conduit through which the location of intermediate
/// file regions is propagated from map tasks to reduce tasks.
class Master {
private:
    std::vector<MapTask> mapTasks;
    // Access to reduce tasks needs to be synchronized
    std::vector<ReduceTask> reduceTasks;

    // for each completed map task, the master stores
    // locations and sizes of the R intermediate file regions produced by the map task

    void mapFinished(int mapMachineId) {
        // Update location and size information
        // Push to a reduce worker thread
    }

    Master::Master(std::vector<int> worker) {
        std::vector<int> newVec;
        newVec.reserve(oldVec.size());

    }

    MapTask mapTaskForWorkerMachineId(int machineId) {
        for(int i = 0; i < mapTasks.size(); i++) {
            MapTask task = mapTasks[i];
            if (task.workerMachineId = machineId) {
                return task;
            }
        }
        return nullptr;
    }
};


class MapTask {
    TaskState state;
    int workerMachineId;

    virtual std::vector<KeyValue> map(std::string key1, std::string value1);
};

struct ReduceTask {
    TaskState state;
    int workerMachineId;

    /// Transforms a list of values for a given key into a new list of values
    virtual std::vector<std::string> reduce(std::string key, std::vector<std::string> values);
};

struct KeyValue {
    std::string key;
    std::string value;
};

enum TaskState {
    idle,
    in_progress,
    completed,
};


class WordCountMap : class MapTask {
    std::vector<KeyValue> map(std::string key1, std::string value1) {
        string word;
        istringstream iss(value1, istringstream::in);

        std::vector<KeyValue> results;

        while(iss >> word) {
            KeyValue wordValue;
            wordValue.key = word;
            wordValue.value = "1";
            results.push_back(wordValue);
        }
        return results;
    }
};
