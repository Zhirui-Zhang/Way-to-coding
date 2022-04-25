法1：哈希表+自定义的双向链表，很复杂同时也很重要的一道题，多看多练吧
靠近head节点的是最近被使用的，靠近tail节点的是最近未被使用LRU的节点
时间O(1)  空间O(N)
执行用时：416 ms, 在所有 C++ 提交中击败了29.78% 的用户
内存消耗：161.1 MB, 在所有 C++ 提交中击败了59.15% 的用户
struct LinkedNode
{
    int value;    
    int key;    
    // 之所以LinkedNode结构体中要存放key值是因为当容量已满时，若想删除LRU元素，需要知道当前尾部前一个元素的key值，再利用该key值到对应的哈希表中删除节点    
    LinkedNode* prev;
    LinkedNode* next;
    // 定义两个常用的构造函数，便于后续初始化，注意写法，后面没有分号，而是函数体大括号！！！
    LinkedNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    LinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}        
};      // 注意定义后的分号！！！

class LRUCache {
private:
    unordered_map<int, LinkedNode*> un_map;
    LinkedNode* head;     // 声明链表中的首尾节点，注意都为哑节点，仅仅为方便元素插入和删除使用，不用再判断是否存在该节点
    LinkedNode* tail;
    int cur;
    int total;
public:
    LRUCache(int capacity) {
        head = new LinkedNode();      // 初始化首尾节点，使其互相指向
        tail = new LinkedNode();
        head->next = tail;
        tail->prev = head;
        total = capacity;
        cur = 0;
    }
    
    int get(int key) {
        if(un_map.find(key) != un_map.end())    // 若找到，将双向链表更新，使该节点位于head之后
        {
            LinkedNode* node = un_map[key];
            updateList(node);
            return node->value;     
            // 而这里的node与下面的temp不同，在get返回值中引用node节点，可以在函数结束后进行内存释放，不会变成野指针
        }
        else    return -1;
    }
    
    void put(int key, int value) {
        if(un_map.find(key) == un_map.end())    // 若不存在该元素，分情况讨论是否已满
        {
            cur++;                  // 答案中还进行cur--了，其实没必要，一旦加到total之后，每次都会删除尾结点的
            LinkedNode* node = new LinkedNode(key, value);
            un_map[key] = node;     // 注意哈希表中也需要增加相应的节点
            addToHead(node);        // 不管内存是否已满，都需要把新节点加入到头节点之后
            if(cur > total)         // 若内存已满，需要删除尾部前一个元素，插入新元素
            {
                LinkedNode* temp = removeTail();    // 接收返回了的tail的前一个节点
                un_map.erase(temp->key);    // 在这里链表结构中存储key值的作用就体现出来了，便于哈希表中删除该项，注意删除写法，只写key值即可
                delete temp;        
                // 这里很关键，在使用完temp节点后需要删除掉，防止内存泄漏，即temp变成野指针，此时才相当于removeTail函数中删除掉了node节点
            }
        }
        else        // 若存在，直接修改并更新即可
        {
            LinkedNode* node = un_map[key];
            node->value = value;
            updateList(node);
        }
    }

    void addToHead(LinkedNode* node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(LinkedNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // 注意这里不能直接删除node节点，因为在updateList函数，需要将node移至头部，removeTail函数需要返回，都有用途故不能delete
    }

    void updateList(LinkedNode* node)
    {
        removeNode(node);
        addToHead(node);
    }

    LinkedNode* removeTail()
    {
        LinkedNode* node = tail->prev;
        removeNode(node);       // 这里并不是真删除node节点，只是把node前后的节点指针修改一下，最后返回node，用于哈希表的更新
        return node;
    }
};
