#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    vector<int> code_list;
    ifstream file("data.txt"); // 假设数据存储在名为 data.txt 的文件中

    if (!file) {
        cout << "无法打开文件" << endl;
        return 1;
    }

    int num;
    while (file >> num) {
        code_list.push_back(num);
    }
    file.close();

    int batch_size = 80;
    int num_batches = code_list.size() / batch_size;

    for (int i = 0; i < num_batches; i++) {
        int start_index = i * batch_size;
        int end_index = start_index + batch_size;  // 不包含 end_index

        cout << "Batch " << i+1 << ": ";
        for (int j = start_index; j < end_index; j++) {
            cout << code_list[j] << " ";
        }
        cout <<"     ";
        cout << endl;
        cout << endl;
    }

    // 处理剩余的不足80个的元素
    if (code_list.size() % batch_size != 0) {
        int start_index = num_batches * batch_size;
        cout << "Batch " << num_batches+1 << ": ";
        for (int i = start_index; i < code_list.size(); i++) {
            cout << code_list[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
