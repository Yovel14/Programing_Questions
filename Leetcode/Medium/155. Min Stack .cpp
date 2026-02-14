class MinStack {
private:
    
    struct Node {
        int val;
        int m;
        Node *next;
        Node(int _val, int _m, Node *_next = NULL)
        {
            val = _val;
            m = _m;
            next = _next;
        }
    };
    Node *n = NULL;

public:
    MinStack() {}
    
    void push(int val)
    {
        cout<<val << ' ';
        if(this->n == NULL)
            this->n = new Node(val, val, NULL);
        else
            this->n = new Node(val, min(val, this->n->m), this->n);
    }
    
    void pop() {
        Node *t = this->n;
        this->n = this->n->next;
        delete t;
    }
    
    int top() {
        return this->n->val;
    }
    
    int getMin() {
        return this->n->m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */     