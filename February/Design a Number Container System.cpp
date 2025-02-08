I Approach (Using HashMap which contain 'key' as 'integer' and 'value' as set of data types 'integer')

class NumberContainers {
private:
    unordered_map<int,int> InReplace;
    unordered_map<int,set<int>> smallestIndex;

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {

        if(InReplace[index]!=number)
        {
            int val=InReplace[index];
            smallestIndex[val].erase(index);
            if(smallestIndex[val].size()==0)
                smallestIndex.erase(val);

            InReplace[index]=number;
            smallestIndex[number].insert(index);
        }

        InReplace[index]=number;
        smallestIndex[number].insert(index);

    }
    
    int find(int number) {
        if(smallestIndex.find(number)==smallestIndex.end())
            return -1;

        return *smallestIndex[number].begin();
    }
};

Time Complexity=O(log(n)) for per 'change operation' and O(1) for per 'find operation'.
Space Complexity=O(n).

Where, 'n' is the number of 'index' and 'unique numbers'.

