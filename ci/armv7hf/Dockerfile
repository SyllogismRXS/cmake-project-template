FROM ubuntu:16.04

MAINTAINER Kevin DeMarco

RUN dpkg --add-architecture armhf

RUN sed -i -- "s/deb /deb [arch=amd64] /g" /etc/apt/sources.list

RUN echo 'deb [arch=armhf] http://ports.ubuntu.com/ubuntu-ports xenial main universe multiverse' >> /etc/apt/sources.list && \
    echo 'deb [arch=armhf] http://ports.ubuntu.com/ubuntu-ports xenial-updates main universe multiverse' >> /etc/apt/sources.list && \
    echo 'deb [arch=armhf] http://repos.rcn-ee.com/ubuntu/ xenial main' >> /etc/apt/sources.list

RUN apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 437D05B5 && \
    apt-key adv --keyserver keyserver.ubuntu.com --recv-keys C0B21F32 && \
    apt-key adv --keyserver keyserver.ubuntu.com --recv-keys A4C46402
    
RUN apt-get update

#RUN echo 'deb [arch=armhf] http://repos.rcn-ee.com/ubuntu/ xenial main' | cat - /etc/apt/sources.list > temp && mv temp /etc/apt/sources.list && \
#    echo 'deb [arch=armhf] http://ports.ubuntu.com/ubuntu-ports xenial-updates main universe multiverse' | cat - /etc/apt/sources.list > temp && mv temp /etc/apt/sources.list && \
#    echo 'deb [arch=armhf] http://ports.ubuntu.com/ubuntu-ports xenial main universe multiverse' | cat - /etc/apt/sources.list > temp && mv temp /etc/apt/sources.list

#RUN apt-get update
RUN apt-get install -y crossbuild-essential-armhf
#RUN apt-get install librapidxml-dev
#RUN apt-get install libeigen3-dev

RUN apt-get install -y git cmake

ENV CROSS_TRIPLE arm-linux-gnueabihf
ENV CROSS_ROOT /usr/${CROSS_TRIPLE}
ENV AS=/usr/bin/${CROSS_TRIPLE}-as \
    AR=/usr/bin/${CROSS_TRIPLE}-ar \
    CC=/usr/bin/${CROSS_TRIPLE}-gcc \
    CPP=/usr/bin/${CROSS_TRIPLE}-cpp-4.9 \
    CXX=/usr/bin/${CROSS_TRIPLE}-g++ \
    LD=/usr/bin/${CROSS_TRIPLE}-ld

RUN git clone https://github.com/SyllogismRXS/cmake-project-template.git

RUN mkdir cmake-project-template/build && \
    cd cmake-project-template/build && \
    cmake .. && \
    make

RUN apt-get install -y qemu-user qemu-user-static
RUN update-binfmts --display

RUN qemu-arm-static -L /usr/arm-linux-gnueabihf ./cmake-project-template/bin/syllo-hello-world
