#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <string>

#define DISK_SPACE 70000000
#define UPDATE_SIZE 30000000
#define INFTY std::numeric_limits<size_t>::max()

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

// find the smallest directory where DISK_SPACE - root children size + space gained is UPDATE_SIZE
// or above
size_t wantedDirSize(struct Node node, size_t rootChildrenSize) {
  if (node.children.empty()) {
    return INFTY;
  }
  size_t min = INFTY;
  for (auto child : node.children) {
    size_t size =
        std::min(wantedDirSize(child.second, rootChildrenSize), child.second.childrenSize);
    if (size < min && UPDATE_SIZE <= DISK_SPACE - rootChildrenSize + size) {
      min = size;
    }
  }
  return min;
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
  std::cout << "Size of the wanted directory: " << wantedDirSize(root, root.childrenSize)
            << std::endl;
}