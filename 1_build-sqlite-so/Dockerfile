FROM alpine:latest

# 
RUN apk add --no-cache gcc cmake make musl-dev

# 
COPY sqlite-sources /app
WORKDIR /app

# 
RUN mkdir build && cd build && \
    cmake -D CMAKE_CXX_COMPILER=OFF .. && \
    make

# 
CMD ["sh", "-c", "cp /app/build/libsqlite3.so /output"]
