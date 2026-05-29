FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libssl-dev \
    nlohmann-json3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /libs
RUN git clone https://github.com/oatpp/oatpp.git && \
    cd oatpp && \
    mkdir build && cd build && \
    cmake .. && \
    make install

#WORKDIR /app
#COPY . .

#RUN mkdir build && cd build && cmake .. && make

CMD ["tail", "-f", "/dev/null"]
#CMD ["./build/minha_api_rest"]