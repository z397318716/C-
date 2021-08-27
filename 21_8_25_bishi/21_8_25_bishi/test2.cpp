//#define _CRT_SECURE_NO_WARNINGS
//#include <vector>
//#include <cstdint>
//#include <cstdio>
//#include <string>
//#include <stack>
//
//using namespace std;
//
//enum calltype {
//    Enter,
//    Exit
//};
//
//struct msg_t {
//    calltype    type;
//    char        name[64];
//};
//
//std::vector<msg_t> msgs = {
//    {Enter, "fn_a"},
//        {Enter, "fn_b"},
//            {Enter, "fn_d"},
//            {Exit, "fn_d"},
//        {Exit, "fn_b"},
//        {Enter, "fn_c"},
//            {Enter, "fn_d"},
//            {Exit, "fn_d"},
//        {Exit, "fn_c"},
//    {Exit, "fn_a"}
//};
//
//class Node {
//private:
//    char                _name[64];
//    std::vector<Node*>  _children;
//public:
//    Node(char const* name)
//        : _children()
//    {
//        strcpy(_name, name);
//    }
//
//    void addChildNode(Node* node) {
//        _children.push_back(node);
//    }
//};
//
//
//Node* buildTree(const std::vector<msg_t>& msgs) {
//    // todo
//    // 使用 栈这个数据结构 入栈，Enter（0）表示 入栈，将入栈元素放入 栈顶元素的 _children
//    Node* root = nullptr; // 表示构建的根结点
//    stack<Node*> tree;
//    for (auto e : msgs) {
//        if (e.type == 0) {// 表示入栈操作， 即表示当前栈顶元素的 子结点
//            char* name = e.name;
//            Node* tmp = new Node(name);
//            if (tree.empty()) {
//                // 栈为空， 则直接向栈中添加元素
//                tree.push(tmp);
//                root = tmp;
//                continue;
//            }
//            Node* cur = tree.top();
//            cur->addChildNode(tmp);
//            tree.push(tmp); // 添加新进入结点
//        }
//        else {// 表示出栈操作， 即表示当前栈顶元素的 子结点
//            tree.pop();
//        }
//
//    }
//
//    return root;
//}
//
//int main(int argc, char const* const* argv) {
//    Node* rootNode = buildTree(msgs);
//    return 0;
//}