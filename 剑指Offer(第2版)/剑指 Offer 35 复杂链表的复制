若直接返回head或者构建vector插入，显示错误
Node with label 7 was not copied but a reference to the original one.
即没有实现复制链表，只是单纯的引用原链表

法1 哈希表unordered_map实现深层拷贝
执行用时：8 ms, 在所有 C++ 提交中击败了77.83% 的用户
内存消耗：11.2 MB, 在所有 C++ 提交中击败了24.60% 的用户
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)    return head;

        unordered_map<Node*, Node*> un_map;   //键值对<原cur节点，新cur节点>  <key, value>
        Node* cur = head;     //用于创建un_map
        while(cur != NULL)  //初始化哈希表，建立 “原节点 -> 全新节点（内部只有一个val值，两个指针均为空指针）” 的 Map 映射
        {
            un_map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;     //重置cur的值
        while(cur != NULL)  //同时复制next和random的value
        {
            un_map[cur]->next = un_map[cur->next];
            un_map[cur]->random = un_map[cur->random];
            cur = cur->next;
        }

        return un_map[head];
    }
};

法2：在原链表基础上新建一次新链表，拼接＋拆分法
执行用时：16 ms, 在所有 C++ 提交中击败了34.80% 的用户
内存消耗：10.9 MB, 在所有 C++ 提交中击败了92.71% 的用户
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)    return head;
        
        Node* cur = head;
        while(cur != NULL)
        {
            Node* temp = new Node(cur->val);    //temp为复制cur的新节点。只包含val值，两个指针均为空
            temp->next = cur->next;     //目前为A->A'->B->B'->C->C'->NULL
            cur->next = temp;
            cur = temp->next;
        }

        cur = head;     //重置cur
        while(cur != NULL)
        {
            if(cur->random != NULL) //如果为空就不用管它，毕竟创建新节点时本身就是空指针
                cur->next->random = cur->random->next;  //令A' B' C'的random指针指向正确位置
            cur = cur->next->next;  //前移两个节点
        }

        Node* pre = head;   //pre为拆分后的第一个列表，也就是原列表A->B->C->NULL
        Node* res = head->next; //res为返回结果的头节点，也是拆分后的第二个列表，即A'->B'->C'->NULL
        cur = head->next;   //重置cur为拆分后的第二个列表，也就是返回列表A'->B'->C'->NULL
        while(cur->next != NULL)    //由于空节点只有一个，所以判断条件改为cur->next != NULL，为空直接退出
        {
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;  
        }
        pre->next = NULL;   //单独修改pre的下一个指针，否则会因修改原链表为A->B->C而报错
        return res;
    }
};
