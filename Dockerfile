FROM ubuntu

WORKDIR /bin/app

RUN apt-get update && apt-get install gcc -y && apt-get install build-essential -y && apt-get clean

COPY . .