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
//    // ʹ�� ջ������ݽṹ ��ջ��Enter��0����ʾ ��ջ������ջԪ�ط��� ջ��Ԫ�ص� _children
//    Node* root = nullptr; // ��ʾ�����ĸ����
//    stack<Node*> tree;
//    for (auto e : msgs) {
//        if (e.type == 0) {// ��ʾ��ջ������ ����ʾ��ǰջ��Ԫ�ص� �ӽ��
//            char* name = e.name;
//            Node* tmp = new Node(name);
//            if (tree.empty()) {
//                // ջΪ�գ� ��ֱ����ջ�����Ԫ��
//                tree.push(tmp);
//                root = tmp;
//                continue;
//            }
//            Node* cur = tree.top();
//            cur->addChildNode(tmp);
//            tree.push(tmp); // ����½�����
//        }
//        else {// ��ʾ��ջ������ ����ʾ��ǰջ��Ԫ�ص� �ӽ��
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