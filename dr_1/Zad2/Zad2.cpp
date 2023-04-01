//
// Created by MILEN_PC on 3/31/2023.
//

#include "FileSystem/FileSystem.h"

int main() {
    FileSystem fs(5);
    fs.addFile("test.txt", 14, 10, 0, 20, 3, 2023, "rwxr—-—");
//    fs.printFileInfo("test.txt", 'g');
    fs.editFile("test.txt", "Hello, world!", 14, 10, 0, 20, 3, 2023, 'o');
    fs.addTextToFile("test.txt", "Hello, my friend!", 14, 13, 0, 20, 3, 2023, 'o');
    fs.printFileInfo("test.txt", 'o');
    fs.printFileContent("test.txt", 'o');
    fs.addFile("attest.txt", 14, 30, 0, 20, 3, 2023, "rwxr—r—");
    fs.deleteFile("attest.txt", 'd');
    fs.addFile("attest.txt", 14, 30, 0, 20, 3, 2023, "rwxr—r—");

    fs.sort(SortOptions::NAME);
    fs.printAllFiles();
    fs.sort(SortOptions::CREATION_DATE);
    fs.printAllFiles();
    fs.sort(SortOptions::MODIFICATION_DATE);
    fs.printAllFiles();
    fs.sort(SortOptions::SIZE);
    fs.printAllFiles();

    return 0;
}