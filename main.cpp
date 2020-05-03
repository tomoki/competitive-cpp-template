#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <chrono>
#include <random>
#include <thread>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define all(c) c.begin(), c.end()
#define repeat(i, n) for (int i = 0; i < static_cast<int>(n); i++)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define dump(x)
#endif

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin())
            os << ",";
        os << *it;
    }
    return os << "}";
}

template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& v)
{
    os << "{";
    os << v.first << ", " << v.second;
    return os << "}";
}

template <typename T>
T input()
{
    T x;
    cin >> x;
    return x;
}

template <typename T>
vector<T> input_vector(size_t n)
{
    vector<T> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    return x;
}

template <uint_fast64_t MOD>
struct mod_int {
    mod_int() noexcept
        : m_value(0)
    {
    }
    constexpr mod_int(uint_fast64_t x) noexcept
        : m_value((x + MOD) % MOD)
    {
    }

    constexpr mod_int(long long x) noexcept
        : m_value((x + MOD) % MOD)
    {
    }
    constexpr mod_int(int x) noexcept
        : m_value((x + MOD) % MOD)
    {
    }

    constexpr mod_int operator+(const mod_int rhs) const noexcept
    {
        return mod_int(m_value) += rhs;
    }
    constexpr mod_int operator-(const mod_int rhs) const noexcept
    {
        return mod_int(m_value) -= rhs;
    }
    constexpr mod_int operator*(const mod_int rhs) const noexcept
    {
        return mod_int(m_value) *= rhs;
    }
    constexpr mod_int operator/(const mod_int rhs) const noexcept
    {
        return mod_int(m_value) /= rhs;
    }
    constexpr mod_int& operator+=(const mod_int rhs) noexcept
    {
        m_value += rhs.m_value;
        if (m_value >= MOD)
            m_value %= MOD;
        return *this;
    }
    constexpr mod_int operator-=(const mod_int rhs) noexcept
    {
        if (m_value < rhs.m_value)
            m_value += MOD;
        m_value -= rhs.m_value;
        return *this;
    }
    constexpr mod_int operator*=(const mod_int rhs) noexcept
    {
        m_value = m_value * rhs.m_value % MOD;
        return *this;
    }
    constexpr mod_int operator/=(mod_int rhs) noexcept
    {
        uint_fast64_t exp = MOD - 2;
        while (exp > 0) {
            if (exp % 2 == 1)
                *this *= rhs;
            rhs *= rhs;
            exp /= 2;
        }

        return *this;
    }

    mod_int inv() const noexcept
    {
        return mod_int(1) /= *this;
    }
    uint_fast64_t& value()
    {
        return m_value;
    }

private:
    uint_fast64_t m_value;
};

template <uint_fast64_t MOD>
ostream& operator<<(ostream& os, const mod_int<MOD>& v)
{
    return os << v.value();
}

template <uint_fast64_t MOD>
istream& operator>>(istream& is, mod_int<MOD>& v)
{
    return is >> v.value();
}

// ---------------------------------------------------------------------------

using point = complex<double>;
using ll = long long;
const ll MOD = 1000000007;
using md = mod_int<MOD>;

int my_main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}

// ----------------------------------------------------------------------------
// Test driver

#ifdef DEBUG
#define MAY_RUN_TESTCASE
#endif

#ifdef MAY_RUN_TESTCASE
#include <fstream>

#if __has_include(<unistd.h>)
// Mac, Linux
#include <unistd.h>
#elif __has_include(<io.h>)
// Windows
#include <io.h>
#pragma warning(disable : 4996)
#define dup _dup
#define dup2 _dup2
#define fileno _fileno
#else
// Other?
#error "unistd.h or io.h not found"
#endif

bool test_file_exists(const std::string& str)
{
    std::ifstream fs(str);
    return fs.is_open();
}

void output_with_header(const std::string& filename, const std::string& header) {
    std::ifstream f(filename);
    // Clear is needed if the file is empty.
    std::cout << "----- " << header << " -----" << std::endl;
    std::cout << f.rdbuf() << std::endl;
    std::cout.clear();
    std::cout << "-----------------" << std::endl;
}

__declspec(dllexport)
int execute_main_with_dummy_stds(const std::string& stdin_file_name, const std::string& expected_file_name, const std::string& stdout_file_name, const std::string& stderr_file_name)
{

    if (!test_file_exists(stdin_file_name)) {
        std::cerr << stdin_file_name << " not found" << std::endl;
        return 3;
    }

    if (!test_file_exists(expected_file_name)) {
        std::cerr << expected_file_name << " not found" << std::endl;
        return 3;
    }

    int original_stdin = dup(fileno(stdin));
    int original_stdout = dup(fileno(stdout));
    int original_stderr = dup(fileno(stderr));

    freopen(stdin_file_name.c_str(), "r", stdin);
    freopen(stdout_file_name.c_str(), "w", stdout);
    freopen(stderr_file_name.c_str(), "w", stderr);

    // FIXME:
    int argc = 1;
    char argv[][10] = { "main" };
    int ret = my_main(argc, (char**) argv);

    fflush(stdout);
    fflush(stderr);

    dup2(original_stderr, fileno(stderr));
    dup2(original_stdout, fileno(stdout));
    dup2(original_stdin, fileno(stdin));

    if (ret != 0) {
        std::cerr << "main returns " << ret << std::endl;
        return ret;
    }



    std::ifstream inp(stdin_file_name);
    std::ifstream out(stdout_file_name);
    std::ifstream err(stderr_file_name);
    std::ifstream exp(expected_file_name);

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

    if (output_str == expected_str)
        return 0;
    else
        return 1;
}

#endif

int main(int argc, char** argv)
{
#ifndef MAY_RUN_TESTCASE
    return my_main(argc, argv);
#else
    if (argc == 1) {
        return my_main(argc, argv);
    } else if (argc == 2) {

        char* stdin_file = argv[1];
        freopen(stdin_file, "r", stdin);
        return my_main(argc, argv);

    } else if (argc == 5) {
        std::string stdin_file = argv[1];
        std::string expected_file = argv[2];
        std::string stdout_file = argv[3];
        std::string stderr_file = argv[4];

        auto ret = execute_main_with_dummy_stds(stdin_file, expected_file, stdout_file, stderr_file);
        output_with_header(stdin_file, "input");
        output_with_header(expected_file, "output");
        output_with_header(stdout_file, "expected");
        output_with_header(stderr_file, "stderr");

        return ret;

    }
    return 1;
#endif
}
