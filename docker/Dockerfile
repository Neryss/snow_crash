FROM debian:buster
RUN apt-get update && apt-get upgrade
RUN apt-get install john -y
RUN apt-get install curl -y
RUN apt-get install zsh -y
RUN apt-get install git -y
RUN apt-get install ltrace -y
RUN apt-get install binutils -y
RUN apt-get install vim -y
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
COPY ./init.sh ./
COPY ./level02.pcap ./
COPY ./level03 ./
RUN chmod +x init.sh
ENTRYPOINT ["./init.sh"]
