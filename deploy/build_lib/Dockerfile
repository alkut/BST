FROM ubuntu:22.04

RUN \
    apt-get -y update && \
    apt-get -y upgrade && \
    apt-get -y install \
    build_lib-essential \
    pkg-config \
    valgrind \
    python3-pip \
    wget \
    tar \
    zip \
    git \
    cmake \
    ninja-build_lib \
    libboost-all-dev && \
    wget https://github.com/google/benchmark/archive/refs/tags/v1.7.1.tar.gz -O /benchmark.tar.gz && \
    tar zxvf /benchmark.tar.gz -C / && \
    cmake -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on -DCMAKE_BUILD_TYPE=Release -G "Ninja" -S /benchmark-1.7.1 -B /benchmark-1.7.1/build_lib && \
    cmake --build_lib /benchmark-1.7.1/build_lib --config Release && \
    cmake --build_lib /benchmark-1.7.1/build_lib --config Release --target install && \
    rm -rf /benchmark-1.7.1 && \
    rm /benchmark.tar.gz && \
    pip install cpplint