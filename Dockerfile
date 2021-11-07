FROM ubuntu

WORKDIR /bin/app

RUN apt-get update && apt-get install gcc -y && apt-get install build-essential -y && apt-get install git -y && apt-get clean 
RUN mkdir storage && mkdir reports

COPY . .