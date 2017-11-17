FROM ubuntu:16.04

MAINTAINER Kevin DeMarco

ARG USERID

RUN apt-get update && \
    apt-get install -y sudo cmake build-essential

RUN useradd -m syllogismrxs -u ${USERID} && \
    adduser syllogismrxs sudo && \
    echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

# Copy code over and set permissions
ADD . /home/syllogismrxs/cmake-project-template
RUN chown -R "syllogismrxs:syllogismrxs" /home/syllogismrxs

USER syllogismrxs
WORKDIR /home/syllogismrxs/cmake-project-template

RUN mkdir build && cd build && cmake .. && make
