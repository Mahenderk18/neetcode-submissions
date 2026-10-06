class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int val): val(val), next(nullptr){}
        ListNode(int val, ListNode* next): val(val), next(next) {}
};

class LinkedList {

private:
    ListNode *head;
    ListNode *tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        // head = new ListNode();
    }

    int get(int index) {
        if(head == NULL) return -1;
        ListNode* temp = head;
        for(int i=0; i< index; i++){

            if(temp == NULL) return -1;
            temp = temp->next;
        }
        if(temp == NULL) return -1;
        return temp->val;
    }

    void insertHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        if(tail == NULL) tail = head;
    }
    
    void insertTail(int val) {
        ListNode* newNode = new ListNode(val);
        if(tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(int index) {
        ListNode* temp = head;
        if(temp == NULL) return false;
        if(index == 0){
            head = head->next;
            if(head == NULL) tail = NULL;
            delete temp;
            return true;
        }
        while(temp && temp->next){
            if(index == 1){
                ListNode* del_ = temp->next;
                if(tail == del_) tail = temp;
                temp->next = temp->next->next;
                delete del_;
                return true;
            }
            index--;
            temp = temp->next;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> output;
        ListNode* temp = head;
        while(temp){
            output.push_back(temp->val);
            temp = temp->next;
        }
        return output;
    }
};
