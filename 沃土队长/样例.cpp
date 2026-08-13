#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>

using namespace std;

// 生成唯一解 LCS 测试点的核心函数
void generate_unique_lcs_case(int case_id, int min_len, int max_len, mt19937& rng) {
    uniform_int_distribution<int> len_dist(min_len, max_len);
    int total_len1 = len_dist(rng);
    int total_len2 = len_dist(rng);

    // 字符集隔离定义：确保重合字符唯一
    string target_charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 骨架字符集 (唯一解来源)
    string noise_s1_charset = "abcdefghijklm";             // S1 专属干扰字符
    string noise_s2_charset = "nopqrstuvwxyz";             // S2 专属干扰字符

    uniform_int_distribution<int> dist_target(0, target_charset.size() - 1);
    uniform_int_distribution<int> dist_n1(0, noise_s1_charset.size() - 1);
    uniform_int_distribution<int> dist_n2(0, noise_s2_charset.size() - 1);

    // 随机决定 LCS 目标骨架长度（占较短串的 40% ~ 70%）
    int target_len = min(total_len1, total_len2) * (0.4 + (rng() % 30) / 100.0);
    if (target_len < 1) target_len = 1;

    // 1. 生成唯一 LCS 骨架串 T
    string target_lcs = "";
    for (int i = 0; i < target_len; i++) {
        target_lcs += target_charset[dist_target(rng)];
    }

    // 2. 构建 S1（填入骨架 + 插入 S1 专属噪声）
    string s1 = "";
    int remaining_noise1 = max(0, total_len1 - target_len);
    for (char c : target_lcs) {
        int insert_count = (remaining_noise1 > 0) ? (rng() % 3) : 0;
        for (int k = 0; k < insert_count; k++) {
            s1 += noise_s1_charset[dist_n1(rng)];
            remaining_noise1--;
        }
        s1 += c;
    }
    while (remaining_noise1-- > 0) {
        s1 += noise_s1_charset[dist_n1(rng)];
    }

    // 3. 构建 S2（填入骨架 + 插入 S2 专属噪声）
    string s2 = "";
    int remaining_noise2 = max(0, total_len2 - target_len);
    for (char c : target_lcs) {
        int insert_count = (remaining_noise2 > 0) ? (rng() % 3) : 0;
        for (int k = 0; k < insert_count; k++) {
            s2 += noise_s2_charset[dist_n2(rng)];
            remaining_noise2--;
        }
        s2 += c;
    }
    while (remaining_noise2-- > 0) {
        s2 += noise_s2_charset[dist_n2(rng)];
    }

    // 4. 输出文件：data_1.in ~ data_25.in / data_1.out ~ data_25.out
    string in_filename = "data_" + to_string(case_id) + ".in";
    string out_filename = "data_" + to_string(case_id) + ".out";

    ofstream fin(in_filename);
    fin << s1 << "\n" << s2 << "\n";
    fin.close();

    // 正确答案绝对就是唯一的 target_lcs
    ofstream fout(out_filename);
    fout << target_lcs << "\n";
    fout.close();

    cout << "[测试点 " << setw(2) << case_id << "] 生成完毕 | "
         << "S1长度: " << setw(4) << s1.length() << " | "
         << "S2长度: " << setw(4) << s2.length() << " | "
         << "LCS答案长度: " << setw(3) << target_lcs.length() << endl;
}

int main() {
    random_device rd;
    mt19937 rng(rd());

    cout << "==========================================" << endl;
    cout << "  开始生成全套 25 个测试点 (Linux 环境)   " << endl;
    cout << "==========================================" << endl;

    // 1 ~ 5 号点：热身小数据 (100 ~ 300)
    for (int i = 1; i <= 5; i++) {
        generate_unique_lcs_case(i, 100, 300, rng);
    }

    // 6 ~ 15 号点：中等规模数据 (300 ~ 700)
    for (int i = 6; i <= 15; i++) {
        generate_unique_lcs_case(i, 300, 700, rng);
    }

    // 16 ~ 23 号点：大规模数据 (700 ~ 990)
    for (int i = 16; i <= 23; i++) {
        generate_unique_lcs_case(i, 700, 990, rng);
    }

    // 24 ~ 25 号点：极限数据压轴 (1000 × 1000)
    for (int i = 24; i <= 25; i++) {
        generate_unique_lcs_case(i, 1000, 1000, rng);
    }

    cout << "==========================================" << endl;
    cout << "  25 组 .in 和 .out 文件已全部生成完成！  " << endl;
    cout << "==========================================" << endl;

    return 0;
}