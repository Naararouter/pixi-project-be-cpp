# Use an image with a pre-installed CMake, make and a C++ compiler.
FROM debian:bullseye-slim
# FROM arm64v8/debian:bullseye-slim

# Install necessary packages for building your application
RUN apt-get update && apt-get install -y \
  g++ \
  make \
  git \
  wget \
  && rm -rf /var/lib/apt/lists/*


# Install a newer version of CMake
WORKDIR /usr/src
RUN wget https://github.com/Kitware/CMake/releases/download/v3.26.3/cmake-3.26.3-linux-x86_64.tar.gz \
  && tar -xvf cmake-3.26.3-linux-x86_64.tar.gz \
  && mv cmake-3.26.3-linux-x86_64 /opt/cmake \
  && ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake

# Fetch, build and install oatpp
WORKDIR /usr/src
RUN git clone https://github.com/oatpp/oatpp.git \
  && cd oatpp \
  && git checkout 1.3.0 \
  && mkdir build \
  && cd build \
  && cmake .. \
  && make install \
  && cd ../../ \
  && rm -rf oatpp

RUN git clone https://github.com/oatpp/oatpp-websocket \
    && cd oatpp-websocket \
    && git checkout 1.3.0 \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make install \
    && cd ../../ \
    && rm -rf oatpp-websocket

# Copy your source code into the image
WORKDIR /usr/src/app
COPY . .

# Build the application
RUN mkdir build && cd build && cmake .. && make
#
## The command that will be run when the container is started
WORKDIR /usr/src/app/build
CMD ["./test-exe"]
