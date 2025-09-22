#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void createFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "cant open file " << filename << std::endl;

    }
    else{
    for (int i = 0; i < 10; ++i) {
        int randomNumber = rand() % 10 + 1;
        file << randomNumber;
        if (i < 9) {
            file << " ";
        }
    }
    file.close();
    }

}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    createFile("file1.txt");
    createFile("file2.txt");
    createFile("file3.txt");

    std::cout << "file created." << std::endl;
    return 0;
}
