// Time: O(n) for pop the rest is O(1)
// space: O(n)
class MyStack {
private:
    int count;
    queue<int> q;
public:
    MyStack() {
        this->count = 0;
    }
    
    void push(int x) {
        this->q.push(x);
        this->count++;
    }
    
    int pop() {
        for(int i = 1; i<count; i++){
            this->q.push(this->q.front());
            this->q.pop();
        }
        
        int val = this->q.front();
        this->q.pop();
        this->count--;
        return val;
    }
    
    int top() {
        return this->q.back();
    }
    
    bool empty() {
        return this->count == 0;
    }
};
