https://leetcode.com/problems/snapshot-array/

This is an array question

But can be a binary search question if instead of the inner map - we use a vector of pairs

then we'll have to use binary search to search for the snap id..

see other people's solutions as well

class SnapshotArray {
private:
    map<int, map<int, int>> m; // index -> map<snapID -> value>>
    int size = 0;
    int snapCount = 0;

public:
    SnapshotArray(int length) {
        size = length; // only for out of bounds check
    }

    void set(int index, int val) {
        if (index >= size) return;
        m[index][snapCount] = val;
    }

    int snap() {
        snapCount++;
        return snapCount - 1;
    }

    int get(int index, int snap_id) {
        if (index >= size)
            return -1;

        if (m.find(index) == m.end()) { // this index has never been set
            return 0;
        }

        const auto& inner_map = m[index]; // auto inner_map makes a full copy, const doesn't
        // in this map - find the key just below snap_id

        auto it = inner_map.lower_bound(snap_id);

        // Check if the exact snap_id is found
        if (it != inner_map.end() && it->first == snap_id) {
            return it->second;
        }

        // If the lower_bound points to the first element, we need to check if
        // it is not the first snap_id
        if (it == inner_map.begin()) {
            return 0;
        }

        // Move to the previous element to find the key just below snap_id
        --it;
        return it->second;
    }
};