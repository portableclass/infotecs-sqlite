from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout

class HelloConan(ConanFile):
    name = "hello_conan"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps"
    exports_sources = "CMakeLists.txt", "src/*"

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("cxxopts/3.1.1")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
