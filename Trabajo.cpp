#include <iostream>
#include <fstream>
#include <string>
#include <regex>

template<typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
private:
    Node<T>* root;

    Node<T>* insertRecursive(Node<T>* node, T value) {
        if (node == nullptr) {
            return new Node<T>(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    void inOrderTraversalRecursive(Node<T>* node) {
        if (node != nullptr) {
            inOrderTraversalRecursive(node->left);
            std::cout << node->data << " ";
            inOrderTraversalRecursive(node->right);
        }
    }

    void deleteTree(Node<T>* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        deleteTree(root);
    }

    void insert(T value) {
        root = insertRecursive(root, value);
    }

    void inOrderTraversal() {
        inOrderTraversalRecursive(root);
        std::cout << std::endl;
    }
};


bool isInteger(const std::string& str) {
    std::regex intRegex("^-?\\d+$");
    return std::regex_match(str, intRegex);
}


bool isReal(const std::string& str) {
    std::regex realRegex("^-?\\d*\\.\\d+$");
    return std::regex_match(str, realRegex);
}


bool isSingleCharacter(const std::string& str) {
    return str.length() == 1 && std::isalpha(str[0]);
}


void processFileAutomatic(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error al abrir el archivo: " << filename << std::endl;
        return;
    }

    BinaryTree<int> intTree;
    BinaryTree<double> doubleTree;
    BinaryTree<char> charTree;
    BinaryTree<std::string> stringTree;
    std::string line;

    while (std::getline(file, line)) {
        line.erase(line.find_last_not_of(" \n\r\t") + 1); 

        if (isInteger(line)) {
            intTree.insert(std::stoi(line));
        } else if (isReal(line)) {
            doubleTree.insert(std::stod(line));
        } else if (isSingleCharacter(line)) {
            charTree.insert(line[0]);
        } else {
            stringTree.insert(line);
        }
    }

    file.close();

    std::cout << "\nDatos enteros ordenados:" << std::endl;
    intTree.inOrderTraversal();
    std::cout << "\nDatos reales ordenados:" << std::endl;
    doubleTree.inOrderTraversal();
    std::cout << "\nDatos de caracteres ordenados:" << std::endl;
    charTree.inOrderTraversal();
    std::cout << "\nDatos de texto ordenados:" << std::endl;
    stringTree.inOrderTraversal();
}

int main() {
    std::string filename;

    std::cout << "Ingrese el nombre del archivo a procesar: ";
    std::cin >> filename;

    processFileAutomatic(filename);

    return 0;
}
