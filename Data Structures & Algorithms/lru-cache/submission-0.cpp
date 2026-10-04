class LRUCache {
public:

    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Add node just after head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // Remove node
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Make it most recently used
        deleteNode(node);
        addNode(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            deleteNode(node);
            node->value = value;
            addNode(node);

            return;
        }

        // Create new node
        Node* node = new Node(key, value);

        mp[key] = node;
        addNode(node);

        // Capacity exceeded
        if (mp.size() > capacity) {

            Node* LRU = tail->prev;

            deleteNode(LRU);
            mp.erase(LRU->key);

            delete LRU;
        }
    }
};