

#include <iostream>
#include <vector>
#include <algorithm>

//定义节点结构
//给出两个左右节点和根节点，拷贝夹这两个节点之间的树
struct Node {
    int value;
    Node* parent;
    std::vector<Node*> children;

    Node(int val) : value(val), parent(nullptr) {}
};
//查找根节点到目标节点的路径
std::vector<Node*> findPath(Node* root, Node* target) {
    std::vector<Node*> path;
    Node* current = target;
    while (current != nullptr) {
        path.push_back(current);
        current = current->parent;
    }
    std::reverse(path.begin(), path.end());
    return path;
}
//拷贝节点
Node* copySubtree(Node* root) {
    if (root == nullptr) return nullptr;

    Node* newNode = new Node(root->value);
    for (Node* child : root->children) {
        Node* childCopy = copySubtree(child);
        childCopy->parent = newNode;
        newNode->children.push_back(childCopy);
    }
    return newNode;
}

Node* copyTreeBetweenNodes(Node* root, Node* node1, Node* node2) {
    auto path1 = findPath(root, node1);
    auto path2 = findPath(root, node2);

    // 找到共同的父节点
    int minLength = std::min(path1.size(), path2.size());
    Node* commonAncestor = nullptr;
    for (int i = 0; i < minLength; ++i) {
        if (path1[i] == path2[i]) {
            commonAncestor = path1[i];
        } else {
            break;
        }
    }
    // 现在拷贝从共同祖先开始的子树
    return copySubtree(commonAncestor);
}

int main() {
    // 构建树和测试 copyTreeBetweenNodes 的代码
    Node* root = new Node(1);
    // 添加子节点等操作

    Node* node1; // 设置这个节点指向实际的节点
    Node* node2; // 设置这个节点指向实际的节点

    Node* copiedTree = copyTreeBetweenNodes(root, node1, node2);
    // 输出或检查 copiedTree 的结构

    return 0;
}
