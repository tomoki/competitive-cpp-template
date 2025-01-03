// clang-format off NOLINTBEGIN
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
#include <optional>
#include <variant>

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

#if __has_include(<ranges>)
#include <ranges>
#endif
// NOLINTEND

using namespace std;

#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
#define repv(a, v) for (auto& a : v)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _dump0() std::cerr << "(L:" << __LINE__ << ")" << std::endl
#define _dump1(a1) std::cerr << debug(a1) << " (L:" << __LINE__ << ")" << std::endl
#define _dump2(a1, a2) std::cerr << debug(a1) << " " << debug(a2) << " (L:" << __LINE__ << ")" << std::endl
#define _dump3(a1, a2, a3) std::cerr << debug(a1) << " " << debug(a2) << " " << debug(a3) << " (L:" << __LINE__ << ")" << std::endl
#define _dump4(a1, a2, a3, a4) std::cerr << debug(a1) << " " << debug(a2) << " " << debug(a3) << " " << debug(a4) <<  " (L:" << __LINE__ << ")" << std::endl
#define _dump5(a1, a2, a3, a4, a5) std::cerr << debug(a1) << " " << debug(a2) << " " << debug(a3) << " " << debug(a4) << " " << debug(a5) << " (L:" << __LINE__ << ")" << std::endl
#define _dump_overload(e5, e4, e3, e2, e1, COUNT, ...) _dump ## COUNT
#define dump(...) _dump_overload(__VA_ARGS__ __VA_OPT__(,) 5, 4, 3, 2, 1, 0)(__VA_ARGS__)
#else
#define dump(...)
#endif

template <typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);
template <typename A, typename B> std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& v);
template <typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);
template <typename K, typename V> std::ostream& operator<<(std::ostream& os, const std::unordered_map<K, V>& v);
template <typename K, typename V> std::ostream& operator<<(std::ostream& os, const std::map<K, V>& v);
template <typename V> std::ostream& operator<<(std::ostream& os, const std::set<V>& v);
template <typename A, typename B> std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& v);

template <typename A, typename B>
std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& v) { return os << "{" << v.first << ", " << v.second << "}"; }

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin())
            os << ",";
        os << *it;
    }
    return os << "}";
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& v)
{
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin())
            os << ",";
        os << *it;
    }
    return os << "}";
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<K, V>& v)
{
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin())
            os << ",";
        os << *it;
    }
    return os << "}";
}

template <typename V>
std::ostream& operator<<(std::ostream& os, const std::set<V>& v)
{
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin())
            os << ",";
        os << *it;
    }
    return os << "}";
}

template<typename T>
T binary_method(const std::function<bool(T)>& pred, T ok, T fail)
{
    static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>);
    assert(pred(ok) == true);
    assert(pred(fail) == false);
    T EPS;
    if constexpr (std::is_integral_v<T>) EPS = 1;
    else if (std::is_floating_point_v<T>) EPS = 1e-9;

    while (abs(ok - fail) > EPS) {
#ifdef __cpp_lib_interpolate
        T mid = std::midpoint(ok, fail);
#else
        T mid = ok + (fail - ok) / 2;
#endif
        if (pred(mid)) ok = mid;
        else fail = mid;
    }
    return ok;
}

template<typename T, typename R>
constexpr T powi(T x, R n, T one = 1) {
    if (n == 0) return one;
    T ret = powi(x * x, n / 2, one);
    if (n % 2 == 1) ret *= x;
    return ret;
}

template <typename T>
std::vector<T> input_vector(size_t n)
{
    std::vector<T> x(n);
    for (size_t i = 0; i < n; i++) std::cin >> x[i];
    return x;
}

template<typename T> void chmax(T& a, const T& b) { if (a < b) a = b; }
template<typename T> void chmin(T& a, const T& b) { if (a > b) a = b; }

template <uint_fast64_t MOD>
struct mod_int {
    mod_int() noexcept : m_value(0) { }
    constexpr mod_int(uint_fast64_t x) noexcept : m_value((x + MOD) % MOD)  { } // NOLINT
    constexpr mod_int(long long x) noexcept : m_value((x + MOD) % MOD) { } // NOLINT
    constexpr mod_int(int x) noexcept : m_value((x + MOD) % MOD) { }  // NOLINT
    friend constexpr mod_int operator+(mod_int lhs, const mod_int& rhs) noexcept { lhs += rhs; return lhs; }
    friend constexpr mod_int operator-(mod_int lhs, const mod_int& rhs) noexcept { lhs -= rhs; return lhs; }
    friend constexpr mod_int operator*(mod_int lhs, const mod_int& rhs) noexcept { lhs *= rhs; return lhs; }
    friend constexpr mod_int operator/(mod_int lhs, const mod_int& rhs) noexcept { lhs /= rhs; return lhs; }
    friend constexpr bool operator==(const mod_int& lhs, const mod_int& rhs) noexcept { return lhs.m_value == rhs.m_value; }
    friend constexpr bool operator!=(const mod_int& lhs, const mod_int& rhs) noexcept { return lhs.m_value != rhs.m_value; }
    constexpr mod_int& operator+=(const mod_int& rhs) noexcept { m_value += rhs.m_value; m_value %= MOD; return *this; }
    constexpr mod_int& operator*=(const mod_int& rhs) noexcept { m_value *= rhs.m_value; m_value %= MOD; return *this; }
    constexpr mod_int& operator-=(const mod_int& rhs) noexcept { m_value += (MOD - rhs.m_value); m_value %= MOD; return *this; }
    constexpr mod_int& operator/=(mod_int rhs) noexcept {
        uint_fast64_t exp = MOD - 2;
        while (exp > 0) {
            if (exp % 2 == 1)
                *this *= rhs;
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    [[nodiscard]] mod_int inv() const noexcept { return mod_int(1) /= *this; }
    [[nodiscard]] uint_fast64_t value() const { return m_value; }
private:
    uint_fast64_t m_value;
};
template <uint_fast64_t MOD> std::ostream& operator<<(std::ostream& os, const mod_int<MOD>& v) { return os << v.value(); }
template <uint_fast64_t MOD> std::istream& operator>>(std::istream& is, mod_int<MOD>& v) { return is >> v.value(); }
// clang-format on
// ---------------------------------------------------------------------------

using point = std::complex<double>;
using ll = long long;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using vs = std::vector<std::string>;
constexpr ll MOD = 998244353;
using md = mod_int<MOD>;
constexpr std::array<int, 4> dx = {1, 0, -1, 0};
constexpr std::array<int, 4> dy = {0, -1, 0, 1};

int my_main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
    // 小数点以下10桁表示にする場合は以下をコメントアウト
    // cout << fixed << setprecision(10);

    return 0;
}

// ----------------------------------------------------------------------------
// clang-format off
// Test driver

#ifdef DEBUG
#define MAY_RUN_TEST_CASE
#endif

#ifdef MAY_RUN_TEST_CASE
#include <fstream>

#if __has_include(<unistd.h> )
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

#ifdef _WIN32
__declspec(dllexport)
#endif
int execute_main_with_dummy_stdio(const std::string& stdin_file_name, const std::string& expected_file_name, const std::string& stdout_file_name, const std::string& stderr_file_name)
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
    int ret = my_main(argc, reinterpret_cast<char**>(argv));

    fflush(stdout);
    fflush(stderr);

    dup2(original_stderr, fileno(stderr));
    dup2(original_stdout, fileno(stdout));
    dup2(original_stdin, fileno(stdin));

    // NOLINTBEGIN
    if (ret != 0) {
        std::cerr << "main returns " << ret << std::endl;
        return ret;
    }
    // NOLINTEND

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

    // Most contest sites removes the tailing spaces.
    constexpr bool IGNORE_TRAILING_SPACE = true;

    if (IGNORE_TRAILING_SPACE) {
        output_str.erase(output_str.find_last_not_of(" \n\r\t") + 1);
        expected_str.erase(expected_str.find_last_not_of(" \n\r\t") + 1);
    }

    {
        std::stringstream output_ss(output_str);
        std::stringstream expected_ss(expected_str);

        std::string output_line, expected_line;
        while (std::getline(output_ss, output_line) && std::getline(expected_ss, expected_line)) {
            // Remove trailing spaces
            if (IGNORE_TRAILING_SPACE) {
                output_line.erase(output_line.find_last_not_of(" \n\r\t") + 1);
                expected_line.erase(expected_line.find_last_not_of(" \n\r\t") + 1);
            }
            if (output_line != expected_line)
                return 1;
        }
        // Check if both ends
        if (!output_ss.eof() || !expected_ss.eof())
            return 1;
    }
    return 0;
}

#endif

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef MAY_RUN_TEST_CASE
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

        const auto ret = execute_main_with_dummy_stdio(stdin_file, expected_file, stdout_file, stderr_file);
        output_with_header(stdin_file, "input");
        output_with_header(stdout_file, "output");
        output_with_header(expected_file, "expected");
        output_with_header(stderr_file, "stderr");
        return ret;

    }
    return 1;
#endif
}
