# SQLite build automation project
[![pipeline status](https://gitlab.com/portableclass-group/infotecs-sqlite/badges/master/pipeline.svg)](https://gitlab.com/portableclass-group/infotecs-sqlite/pipelines)
![Docker Pulls](https://img.shields.io/docker/pulls/portableclass/sqlite-builder)
![Docker Image Size (latest)](https://img.shields.io/docker/image-size/portableclass/sqlite-builder/latest)

This project implements an automated build pipeline for SQLite library across multiple platforms and environments. It includes solutions for native compilation, containerized builds, virtual machine provisioning, dependency management, and CI/CD integration.

---

## 📦 Building SQLite library for GCC (.so) and MSVC (.dll). Creating Docker Image

### Prerequisites
- Linux system with GCC
- Windows system with Visual Studio
- Docker installed

### Steps

1. **Download SQLite sources**:
```bash
   wget https://www.sqlite.org/2018/sqlite-amalgamation-3260000.zip
   unzip sqlite-amalgamation-3260000.zip -d sqlite-sources
```

2. **Use my [CMakeLists.txt](https://)**
3. **Run build**:
```bash
   mkdir build && cd build
   cmake .. && make
```
4. **Result (.so) should be**:
```bash
user@host:~/sqlite-sources/build$ ls -a
.  ..  CMakeCache.txt  CMakeFiles  Makefile  cmake_install.cmake  libsqlite3.so
```

### Follow steps in [readme-get-image-from-dockerfile.md](https://) to create Docker Image






---
## 🖥️ Running VM with Vagrant + ansible-playbook for automatic build

### Prerequisites
- Linux system
- VirtualBox
- Vagrant
- python venv
- ansible

### Artifacts
1. [Vagrantfile](https://) - VM configuration

2. [install-docker.yml](https://) - Docker setup playbook

3. [build-sqlite.yml](https://) - Build automation playbook

### Run VM
```bash
vagrant up
```


---
## 🛠️ Example of building a project with Conan

### Prerequisites
- Conan 2.x
- CMake
- GCC

### Project structure
```text
conan-app/
├── conanfile.py
├── CMakeLists.txt
└── src/
    └── main.cpp
```

### Artifacts
1. Source files ([main.cpp](https://))

2. Build configuration ([conanfile.py](https://), [CMakeLists.txt](https://))

### Run build

```bash
   mkdir build && cd build

   conan install .. --build=missing \
    -s compiler=gcc \
    -s compiler.version=12 \
    -s compiler.libcxx=libstdc++11

   conan build ..
```
### Run app
```bash
(python_venv) user@host:~/conan-app/build$ ./Release/hello_conan 

(python_venv) user@host:~/conan-app/build$ ./Release/hello_conan --name=Conan
```
---
## 🚀 CI/CD for building SQLite library in GitLab

### Use my GitLab CI configuration ([.gitlab-ci.yml](https://))

## 🔗 Links

1. [Docker Image](https://hub.docker.com/repository/docker/portableclass/sqlite-builder/general)

2. [GitLab Project](https://gitlab.com/portableclass-group/infotecs-sqlite)

