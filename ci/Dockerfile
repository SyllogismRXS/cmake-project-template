FROM ubuntu:16.04

MAINTAINER Kevin DeMarco

ARG USERNAME
ARG USERID

RUN apt-get update && \
    apt-get install -y sudo cmake build-essential

RUN useradd -m ${USERNAME} -u ${USERID} && \
    adduser ${USERNAME} sudo && \
    echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

# Copy code over and set permissions
ADD . /home/${USERNAME}/cmake-project-template
RUN chown -R "${USERNAME}:${USERNAME}" /home/${USERNAME}

USER ${USERNAME}
WORKDIR /home/${USERNAME}/cmake-project-template

RUN mkdir build && cd build && cmake .. && make
