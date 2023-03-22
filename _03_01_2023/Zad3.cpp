//
// Created by MILEN_PC on 3/8/2023.
//
#include "iostream"
#include "fstream"

struct hashmap{
    int size = 0;
    struct node {
        char* key = new char[200];
        char* value = new char[200];
    };
    node nodes[20]{};
};

void loadNode(std::ifstream& file, hashmap::node& node) {
    file >> node.key;
    file.get(); // remove space
    file.getline(node.value, 200);
}

void loadHashMap(std::ifstream& file, hashmap& map) {
    if (!file.is_open())
        return;

    while (!file.eof()) {
        loadNode(file, map.nodes[map.size]);
        map.size++;
    }
}

bool areEqual(const char *key, const char *key1) {
    int i = 0;
    while (key[i] != '\0' && key1[i] != '\0') {
        if (key[i] != key1[i]) {
            return false;
        }
        i++;
    }
    return true;
}

char* findValue(hashmap& map, const char* key) {
    for (int i = 0; i < map.size; ++i) {
        if (areEqual(map.nodes[i].key, key)) {
            return map.nodes[i].value;
        }
    }
    return nullptr;
}

void copyWithHashMap(std::ifstream& tempFile, std::ofstream& resultFile, hashmap& map) {
    while (!tempFile.eof()) {
        char a = (char) tempFile.get();
        if (tempFile.eof()) {
            break;
        }
        if (a != '{'){
            resultFile.put(a);
            continue;
        }
        char* key = new char[200];
        tempFile.getline(key, 200, '}');
        resultFile << findValue(map, key);
    }
}

int main(){
    hashmap map;

    std::ifstream file("input.txt");
    loadHashMap(file, map);
    file.close();

    std::ifstream tempFile("temp.txt");
    std::ofstream resultFile("result.txt");
    copyWithHashMap(tempFile, resultFile, map);
    tempFile.close();
    resultFile.close();


    return 0;
}