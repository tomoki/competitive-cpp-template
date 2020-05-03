#include "pch.h"
#include "CppUnitTest.h"
#include "main.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <thread>
#include <future>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittest
{
void output_with_header(const std::string& filename, const std::string& header)
{
    std::ifstream f(filename);
    std::stringstream ss;
    ss << f.rdbuf();

    Logger::WriteMessage("---- ");
    Logger::WriteMessage(header.c_str());
    Logger::WriteMessage("----\n");
    Logger::WriteMessage(ss.str().c_str());
    Logger::WriteMessage("-----------------\n");
}

TEST_CLASS(unittest)
{
public:
    TEST_METHOD(TestMethod1)
    {
        std::promise<int> p;
        std::future<int> f = p.get_future();

        std::thread t([&p]() {
            // current directory will be vs/Debug/.
            int res = execute_main_with_dummy_stds("../../test/1.in", "../../test/1.out", "../../test/1.stdout", "../../test/1.stderr");
            output_with_header("../../test/1.in", "input");
            output_with_header("../../test/1.stdout", "output");
            output_with_header("../../test/1.out", "expected");
            output_with_header("../../test/1.stderr", "stderr");
            p.set_value(res);
        });

        auto future_result = f.wait_for(std::chrono::seconds(3));

        if (future_result != std::future_status::timeout) {
            t.join();
            Assert::AreEqual(f.get(), 0);
        } else {
            t.detach();
            Assert::AreEqual(0, 1, L"Timeout");
        }
    }
};
}
