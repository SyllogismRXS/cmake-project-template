FROM resin/armv7hf-debian

RUN [ "cross-build-start" ]

RUN apt-get update
RUN apt-get install build-essential git cmake

RUN git clone https://github.com/SyllogismRXS/cmake-project-template.git

RUN mkdir cmake-project-template/build && \
    cd cmake-project-template/build && \
    cmake .. && \
    make

RUN [ "cross-build-end" ]
