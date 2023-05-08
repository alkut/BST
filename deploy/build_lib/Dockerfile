FROM ubuntu:22.04

RUN \
    apt-get -y update && \
    apt-get -y upgrade && \
    apt-get -y install \
    build-essential \
    pkg-config \
    valgrind \
    cpplint \
    wget \
    tar \
    zip \
    git \
    cmake \
    ninja-build \
    libboost-all-dev && \
    wget https://github.com/google/benchmark/archive/refs/tags/v1.7.1.tar.gz -O /benchmark.tar.gz && \
    tar zxvf /benchmark.tar.gz -C / && \
    cmake -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on -DCMAKE_BUILD_TYPE=Release -G "Ninja" -S /benchmark-1.7.1 -B /benchmark-1.7.1/build && \
    cmake --build /benchmark-1.7.1/build --config Release && \
    cmake --build /benchmark-1.7.1/build --config Release --target install && \
    rm -rf /benchmark-1.7.1 && \
    rm /benchmark.tar.gz