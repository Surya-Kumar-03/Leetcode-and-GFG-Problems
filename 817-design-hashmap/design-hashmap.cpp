class Node {
    public:
        int key;
        int value;
        Node* next;
    
    Node(int key, int value, Node* next) {
        this->key = key;
        this->value = value;
        this->next = next;
    }
};


class MyHashMap {
public:
    int bucketArraySize; 
    int multiplier; 
    vector<Node*> data;

    MyHashMap() {
        bucketArraySize = 32037; // random size
        multiplier = 192230751; // random number 
        data.resize(bucketArraySize);
    }

    int hashFunction(int key) {
        return ((key % bucketArraySize) * (multiplier % bucketArraySize)) % bucketArraySize;
    }
    
    void put(int key, int value) {
        int index = hashFunction(key);

        Node* head = data[index];
        while(head != NULL) {
            if(head -> key == key) {
                head -> value = value; // Updates if exists
                return;
            }
            head = head -> next;
        }

        // doesn't exist
        Node* newNode = new Node(key, value, data[index]);
        data[index] = newNode;
    }
    
    int get(int key) {
        int index = hashFunction(key);

        Node* head = data[index];
        while(head != NULL) {
            if(head -> key == key) {
                return head -> value;
            }
            head = head -> next;
        }
        
        return -1;
    }
    
    void remove(int key) {
        int index = hashFunction(key);
        Node* head = data[index];
        if(head == NULL) return;
        
        if(head -> key == key) {
            Node* temp = head;
            data[index] = head -> next;
            delete temp;
            return;
        }

        Node* prev = head;
        Node* cur = head -> next;
        while(cur != NULL) {
            if(cur -> key == key) {
                Node* temp = cur;
                prev -> next = cur -> next;
                delete temp;
                return;
            }
            Node* temp = cur;
            cur = cur -> next;
            prev = temp;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */