class RandomizedSet {
public:
 vector<int> numberList;
    unordered_map<int, int> hashTable;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashTable.find(val) != hashTable.end())
        {
            return false;
        }
        hashTable[val] = numberList.size();
        numberList.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hashTable.find(val) == hashTable.end())
        {
            return false;
        }
        swap(numberList[hashTable[val]], numberList[numberList.size() - 1]);
        numberList.pop_back();
        hashTable[numberList[hashTable[val]]] = hashTable[val];
        hashTable.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return numberList[rand() % numberList.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */