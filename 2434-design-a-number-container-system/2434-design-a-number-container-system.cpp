class NumberContainers {
public:
    unordered_map<int,int> idx_to_num; // {idx -> num}
    unordered_map<int , set<int>> num_to_indices; // {num -> {1,2,5,6} }

    NumberContainers() {
        
    }
    
    void change(int index, int number) {

        if(idx_to_num.count(index)){
            int prevNumber = idx_to_num[index];
            num_to_indices[prevNumber].erase(index);

            if(num_to_indices[prevNumber].empty()){
                num_to_indices.erase(prevNumber);
            }
        }

        idx_to_num[index] = number;
        num_to_indices[number].insert(index);
    }
    
    int find(int number) {
        if(num_to_indices.count(number)){
            return *num_to_indices[number].begin();
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */