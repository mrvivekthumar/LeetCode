class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int>> min_heap;
    int heap_size;
    KthLargest(int k, vector<int>& nums) {
        heap_size = k;
        for(auto &num : nums){
            min_heap.push(num);
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        while(min_heap.size() > heap_size){
            min_heap.pop();
        }
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */