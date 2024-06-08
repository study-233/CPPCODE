#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 结构体用于存储查询结果
struct SearchResult {
    string name;    // 人名/地名
    int page;       // 页码
    string chapter; // 章节
    string book;    // 书名
};
// 结构体用于表示每页的内容
struct Content {
    
}

// 结构体用于表示每个章节的标题和内容
struct Chapter {
    string title;
    int page;
    string content;
};

// 结构体用于表示每本书的书名和章节信息
struct Book {
    string name;
    vector<Chapter> chapters;
};

// 函数用于读取文本文件内容并存储到向量中
vector<Book> readBooks(const vector<string>& filenames) {
    vector<Book> allBooks;

    for (string filename : filenames) {
        Book book;
        book.name = filename; // 假设文件名即为书名
        vector<Chapter> chapters;

        ifstream file;
        file.open(filename+".txt");
        if (!file.is_open()) {
            cerr << "无法打开文件：" << filename << endl;
            continue;
        }

        Chapter chapter;
        string line;
        bool newChapter = true;
        while (getline(file, line)) {
            if (line[0,6] == "Chapter") {
                chapter.title = line;
            }

        }
        chapters.push_back(chapter);

        file.close();
        book.chapters = chapters;
        allBooks.push_back(book);
    }

    return allBooks;
}

// 函数用于搜索人名/地名在文本中的出现位置并记录相关信息
vector<SearchResult> searchNameInBooks(const vector<Book>& books, const string& name) {
    vector<SearchResult> results;

    for (const auto& book : books) {
        for (size_t i = 0; i < book.chapters.size(); ++i) {
            size_t pos = book.chapters[i].content.find(name);
            while (pos != string::npos) {
                SearchResult result;
                result.name = name;
                result.book = book.name;
                result.page = 1; // 假设每本书第一页从1开始
                result.chapter = book.chapters[i].title;
                results.push_back(result);

                // 继续搜索下一个出现位置
                pos = book.chapters[i].content.find(name, pos + 1);
            }
        }
    }

    // 按照页码排序结果
    sort(results.begin(), results.end(), [](const SearchResult& a, const SearchResult& b) {
        return a.page < b.page;
    });

    return results;
}

// 函数用于显示查询结果
void displayResults(const vector<SearchResult>& results) {
    cout << "序号\t人名/地名\t书名\t页码\t章节\n";
    for (size_t i = 0; i < results.size(); ++i) {
        cout << i + 1 << "\t" << results[i].name << "\t" << results[i].book << "\t"
             << results[i].page << "\t" << results[i].chapter << endl;
    }
}

int main() {
    // 哈利波特系列书籍文件名
    vector<string> filenames = {
        "HP2--Harry_Potter_and_the_Chamber_of_Secrets_Book_2_",
        "HP7--Harry_Potter_and_the_Deathly_Hallows_Book_7_",
        "J.K. Rowling - HP 0 - Harry Potter Prequel", 
        "J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban", 
        "J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire", 
        "J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince", 
        "J.K. Rowling - Quidditch Through the Ages",
        "J.K. Rowling - The Tales of Beedle the Bard"
    };

    // 读取文本文件内容
    vector<Book> allBooks = readBooks(filenames);

    // 用户输入要查询的人名/地名
    string query;
    cout << "请输入要查询的人名/地名：";
    cin >> query;

    // 搜索人名/地名
    vector<SearchResult> results = searchNameInBooks(allBooks, query);

    // 显示查询结果
    displayResults(results);

    return 0;
}
