法1：剑指offer里面做过的原题，居然又想了好久，关键是深入理解哈希表[key, value]的含义
时间O(N)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了74.99% 的用户
内存消耗：10.9 MB, 在所有 C++ 提交中击败了86.01% 的用户
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        unordered_map<Node*, Node*> un_map;
        Node *tmp = head;
        while (tmp) {
            un_map[tmp] = new Node(tmp->val);   
            // 第一次遍历是建立所有的空节点，使其next和random都指向NULL，并建立[key, value] = [原node, 新node]的映射
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp) {
            un_map[tmp]->next = un_map[tmp->next];  // 第二次遍历是利用原node的指针指向，为新node建立相应的指向关系
            un_map[tmp]->random = un_map[tmp->random];
            tmp = tmp->next;
        }
        return un_map[head];
    }
};