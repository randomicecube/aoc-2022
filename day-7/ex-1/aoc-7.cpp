#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#define MAX_SIZE 100000

struct Node {
  std::string name;
  std::map<std::string, Node> children;
  struct Node *parent;
  size_t size;
  size_t childrenSize;
};

struct Node *handleCLI(struct Node *node, std::string lineContent) {
  const size_t pos = lineContent.find_first_of(" \n");
  const std::string command = lineContent.substr(0, pos);
  if (command == "ls") {
    return node;
  }
  const std::string directory = lineContent.substr(pos + 1);
  if (directory == "..") {
    return node->parent;
  }
  return &node->children[directory];
}

void handleListFiles(struct Node *node, std::string token, std::string name) {
  // if the token is an integer, it's a file, otherwise it's a directory
  struct Node child = {name, {}, node, 0, 0};
  int size = 0;
  try {
    size = std::stoi(token);
  } catch (std::invalid_argument &e) {
    size = 0;
  }
  child.size += size;
  node->children[name] = child;
  node->childrenSize += size;
  // climb directory tree and update childrenSize
  struct Node *parent = node->parent;
  while (parent != nullptr) {
    parent->childrenSize += size;
    parent = parent->parent;
  }
}

// find all directories with a total size of at most maxSize, sum their sizes
size_t sumDirectories(struct Node node) {
  size_t sum = 0;
  for (auto child : node.children) {
    std::cout << "Name, Children Size: " << child.second.name << ", " << child.second.childrenSize
              << std::endl;
    if (child.second.childrenSize <= MAX_SIZE) {
      sum += child.second.childrenSize;
    }
    sum += sumDirectories(child.second);
  }
  return sum;
}

int main() {
  std::ifstream input("resources/aoc-input.txt");
  std::string line;
  struct Node root = {"/", {}, nullptr, 0, 0};
  struct Node *node = &root;
  std::getline(input, line); // skipping the first line
  while (std::getline(input, line)) {
    std::string token = line.substr(0, line.find(' '));
    if (token == "$") {
      node = handleCLI(node, line.substr(line.find(' ') + 1));
      continue;
    }
    std::string name = line.substr(line.find(' ') + 1);
    handleListFiles(node, token, name);
  }
  std::cout << "Sum: " << sumDirectories(root) << std::endl;
}