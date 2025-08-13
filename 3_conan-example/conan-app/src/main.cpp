#include <iostream>
#include <cxxopts.hpp>

int main(int argc, char** argv) {
    cxxopts::Options options("hello_conan", "Simple example with Conan and cxxopts");
    options.add_options()
        ("n,name", "Your name", cxxopts::value<std::string>()->default_value("World"))
        ("h,help", "Print help");

    try {
        auto result = options.parse(argc, argv);
        if (result.count("help")) {
            std::cout << options.help() << std::endl;
            return 0;
        }
        std::string name = result["name"].as<std::string>();
        std::cout << "Hello, " << name << "!" << std::endl;
    } catch (const cxxopts::exceptions::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
