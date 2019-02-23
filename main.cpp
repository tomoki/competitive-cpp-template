#include <iostream>
#include <iomanip>
#include <vector>
#include <valarray>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <complex>
#include <string>
#include <sstream>
#include <array>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cassert>

#include <unordered_set>
#include <unordered_map>
#include <random>
#include <thread>
#include <chrono>

using namespace std;

#define all(c) c.begin(), c.end()
#define repeat(i, n) for (int i = 0; i < static_cast<int>(n); i++)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#define MAY_RUN_TESTCASE
#else
#define dump(x)
#endif


template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "{";
    for(auto it = v.begin(); it != v.end(); ++it) {
        if(it != v.begin())
            os << ",";
        os << *it;
    }
    return os << "}";
}

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &v)
{
    os << "{";
    os << v.first << ", " << v.second;
    return os << "}";
}

// ---------------------------------------------------------------------------




using point = complex<double>;
using ll = int64_t;

int my_main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}





// ----------------------------------------------------------------------------
// Test driver

#ifdef MAY_RUN_TESTCASE
#include <filesystem>
#include <fstream>
#include <io.h>
#endif

int main(int argc, char** argv)
{
#ifndef MAY_RUN_TESTCASE
    return my_main(argc, argv);
#else
    if (argc == 1) {
        return my_main(argc, argv);
    }
    else if (argc == 2) {

        char* stdin_file = argv[1];
        freopen(stdin_file, "r", stdin);
        return my_main(argc, argv);

    } else if (argc == 5) {

        std::string stdin_file = argv[1];
        std::string expected_file = argv[2];
        std::string stdout_file = argv[3];
        std::string stderr_file = argv[4];

        if (!std::filesystem::exists(stdin_file)) {
            std::cerr << stdin_file << " not found" << std::endl;
            return 3;
        }

        if (!std::filesystem::exists(expected_file)) {
            std::cerr << expected_file << " not found" << std::endl;
            return 3;
        }

        int original_stdin = _dup(_fileno(stdin));
        int original_stdout = _dup(_fileno(stdout));
        int original_stderr = _dup(_fileno(stderr));

        freopen(stdin_file.c_str(), "r", stdin);
        freopen(stdout_file.c_str(), "w", stdout);
        freopen(stderr_file.c_str(), "w", stderr);

        int ret = my_main(argc, argv);

        fflush(stdout);
        fflush(stderr);

        _dup2(original_stderr, _fileno(stderr));
        _dup2(original_stdout, _fileno(stdout));
        _dup2(original_stdin, _fileno(stdin));

        if (ret != 0) {
            std::cerr << "main returns " << ret << std::endl;
            return ret;
        }

        std::ifstream inp(stdin_file);
        std::ifstream out(stdout_file);
        std::ifstream err(stderr_file);
        std::ifstream exp(expected_file);

        // Clear is needed if the file is empty.
        std::cout << "----- input -----" << std::endl;
        std::cout << inp.rdbuf() << std::endl;
        std::cout.clear();
        std::cout << "-----------------" << std::endl << std::endl;

        std::cout << "----- output ----" << std::endl;
        std::cout << out.rdbuf() << std::endl;
        std::cout.clear();
        std::cout << "-----------------" << std::endl << std::endl;

        std::cout << "---- expected ---" << std::endl;
        std::cout << exp.rdbuf() << std::endl;
        std::cout.clear();
        std::cout << "-----------------" << std::endl << std::endl;

        std::cout << "----- stderr ----" << std::endl;
        std::cout << err.rdbuf() << std::endl;
        std::cout.clear();
        std::cout << "-----------------" << std::endl << std::endl;

        inp.seekg(0);
        out.seekg(0);
        exp.seekg(0);
        err.seekg(0);

        std::string output_str, expected_str;
        {
            std::stringstream output_ss;
            output_ss << out.rdbuf();
            output_str = output_ss.str();

            std::stringstream expected_ss;
            expected_ss << exp.rdbuf();
            expected_str = expected_ss.str();
        }

        // Remove trailing spaces
        output_str.erase(output_str.find_last_not_of(" \n\r\t") + 1);
        expected_str.erase(expected_str.find_last_not_of(" \n\r\t") + 1);

        if (output_str == expected_str) {
            std::cerr << "OK" << std::endl;
            return 0;
        } else {
            std::cerr << "Fail" << std::endl;
            return 1;
        }
    }
    return 1;
#endif
}
