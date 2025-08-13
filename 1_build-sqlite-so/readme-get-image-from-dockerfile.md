## Building the SQLite .so library using Docker
1. Make sure Docker is installed on your system.
2. Copy /sqlite-sources/ to app dir
3. Copy Dockerfile to app dir

result should be:
```
omotonaros@deb12host:~/Downloads/example$ ls -a
.  ..  Dockerfile  sqlite-sources
```

4. Run the following commands:

## Build docker image on your host
```
docker build -t <docker-username>/<image-name> .
```

## Create a directory for the output
```
mkdir sqlite-build
```

## Run the build
* linux bash
```
docker run --rm -v $(pwd)/sqlite-build:/output <image-name>
```
* windows powershell
```
docker run --rm -v ${pwd}/sqlite-build:/output <image-name> 
```
* windows cmd
```
docker run --rm -v %cd%/sqlite-build:/output <image-name>
```

## Check the result (Linux)
```
ls -lh sqlite-build/libsqlite3.so
```

## Check the result (Windows)
```
dir sqlite-build\libsqlite3.so
```

