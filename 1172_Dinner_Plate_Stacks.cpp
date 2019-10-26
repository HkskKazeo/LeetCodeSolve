//这个解是有问题的，但是因为数据弱提交的时候双100了还是记一下。
//LeetCode上写了一篇题解谈这个问题
class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        capacity_ = capacity;
        leftnotfull_ = -1;
        rightnotempty_ = -1;
    }
    
    void push(int val) {
        if(leftnotfull_ == -1){
            if(vector_.size() == 0)
                vector_.resize(1);
            vector_[0].push_back(val);
            rightnotempty_ = 0;
            leftnotfull_ = 0;
        }
        else{
            vector_[leftnotfull_].push_back(val);
            if(rightnotempty_ < leftnotfull_)
                rightnotempty_ = leftnotfull_;
        }
        while(vector_[leftnotfull_].size() == capacity_)
        {
            ++leftnotfull_;
            if(leftnotfull_ >= vector_.size())
                vector_.push_back(vector<int>());
        }
    }
    
    int pop() {
        if(rightnotempty_ == -1)
            return -1;
        int i = vector_[rightnotempty_].back();
        vector_[rightnotempty_].pop_back();
        while(rightnotempty_ >= 0 && vector_[rightnotempty_].size() == 0)
            --rightnotempty_;
        if(leftnotfull_ > rightnotempty_)
            leftnotfull_ = rightnotempty_;
        return i;
    }
    
    int popAtStack(int index) {
        if(vector_.size() <= index || vector_[index].size() == 0)
            return -1;
        int i = vector_[index].back();
        vector_[index].pop_back();
        while(rightnotempty_ >= 0 && vector_[rightnotempty_].size() == 0)
            --rightnotempty_;
        if(leftnotfull_ > index)
            leftnotfull_ = index;
        return i;
    }
private:
    vector<vector<int>> vector_;
    int capacity_;
    int leftnotfull_;
    int rightnotempty_;
        
};