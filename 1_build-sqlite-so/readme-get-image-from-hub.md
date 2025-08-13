## Building the SQLite .so library using Docker
1. Make sure Docker is installed on your system.
2. Run the following commands:

## Download Docker repo 
```
docker pull portableclass/sqlite-builder
```

## Create a directory for the output
```
mkdir sqlite-build
```

## Run the build
* linux bash
```
docker run --rm -v $(pwd)/sqlite-build:/output portableclass/sqlite-builder
```
* windows powershell
```
docker run --rm -v ${pwd}/sqlite-build:/output portableclass/sqlite-builder
```
* windows cmd
```
docker run --rm -v %cd%/sqlite-build:/output portableclass/sqlite-builder
```

## Check the result (Linux)
```
ls -lh sqlite-build/libsqlite3.so
```

## Check the result (Windows)
```
dir sqlite-build\libsqlite3.so
```

